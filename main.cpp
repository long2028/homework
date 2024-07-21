#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint32_t my_ntohl(uint32_t n){
        return ((n >> 24) & 0x000000FF) |
               ((n << 24) & 0xFF000000) |
               ((n >> 8) & 0x0000FF00) |
               ((n << 8) & 0x00FF0000);
}

uint32_t read_nbo(const char* filename){
	FILE *file = fopen(filename, "rb");
	uint32_t number;

	fread(&number, sizeof(number), 1, file);
	fclose(file);
	
	return number;
}

int main(int argc, char* argv[])
{
	uint32_t num1 = my_ntohl(read_nbo(argv[1]));
	uint32_t num2 = my_ntohl(read_nbo(argv[2]));
	uint32_t sum = num1 + num2;

	printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n",
		       	num1, num1, num2, num2, sum, sum);

	return 0;
}
