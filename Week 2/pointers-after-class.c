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
	printf("Address of ptr: %p, value=%d\n", ptr, *ptr);
	printf("Address of s_ptr: %p, value=%d\n", s_ptr, *s_ptr);
	printf("Address of c_ptr: %p, value=%d\n", c_ptr, *c_ptr);
	printf("Address of f_ptr: %p, value=%f\n", f_ptr, *f_ptr);
	printf("Address of v_ptr: %p\n", v_ptr);
	ptr++;
	s_ptr++;
	c_ptr++;
	f_ptr++;
	v_ptr++;
	printf("Address of ptr: %p\n", ptr);
	printf("Address of s_ptr: %p\n", s_ptr);
	printf("Address of c_ptr: %p\n", c_ptr);
	printf("Address of f_ptr: %p\n", f_ptr);
	printf("Address of v_ptr: %p\n", v_ptr);
	return 0;
}
