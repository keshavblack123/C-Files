#include <stdio.h>

typedef struct lestudent
{
	char firstname[256];
	char lastname[256];
	char gradeLetter;
	float averageGrade;
}
student;

int main (int argc, char ** argv)
{
	student s;
	printf("The size of a student struct is: %lu bytes\n", sizeof(s));
	return 0;
}

