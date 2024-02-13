#include <stdio.h>
#include <string.h>

typedef struct lestudent
{
	char firstname[256];
	char lastname[256];
	char gradeLetter;
	float averageGrade;
}
student;

student create_student (char f[], char l[], char g, float a)
{
	student me;
	int i;
	for (i=0; i <= strlen(f); i++)
	{
		me.firstname[i] = f[i];
	}
	for (i=0; i <= strlen(l); i++)
	{
		me.lastname[i] = l[i];
	}
	me.gradeLetter = g;
	me.averageGrade = a;
	return me;
}

void print_student(student s)
{
	printf("%s %s %c %f\n", s.firstname, s.lastname, s.gradeLetter, s.averageGrade);
}

void modify_student(student s, float a) 
{
	s.averageGrade = a;
	s.firstname[0] = 'H';
}
int main (int argc, char ** argv)
{
	student s = create_student("Simon", "Perrault", 'C', 78.9);
	print_student(s);
	modify_student(s, 90.0);
		print_student(s);
	return 0;
}

