#include <stdlib.h>
#include <stdio.h>

int main (int argc, char **argv)
{
	int * ptr = (int *) malloc (sizeof(int) * 2);
	short * s_ptr = ptr;
	char * c_ptr = ptr;
	float * f_ptr = ptr;
	void * v_ptr = ptr;
	ptr[0] = 255;
	ptr[1] = 131071;
	return 0;
}
