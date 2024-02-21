#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct lestudent student;

struct lestudent
{
	char * firstname;
	char * lastname;
	char gradeLetter;
	float averageGrade;
	void (* print) (student *);
};

void print_student(student * this);


student * create_student (char *f, char *l, char letter, float avg)
{
	/* Step 1: create pointer to student */
	student * result = (student *) malloc (sizeof(student));
	/* Step 2: copy the first and last name */
	result->firstname = (char *) malloc(strlen(f) * sizeof(char) + 1);
	result->lastname = (char *) malloc(strlen(l) * sizeof(char) + 1);
	strcpy(result->firstname, f);
	strcpy((*result).lastname, l);
	/* Step 3: copy the values for the last two fields */
	(*result).gradeLetter = letter;
	result->averageGrade = avg;
	result->print = print_student;
	/* return the newly created student */
	return result;

}

void free_student(student * this)
{
	free(this->firstname);
	free(this->lastname);
	free(this);
}

void print_student(student * this)
{
	printf("First name: %s, Last name: %s\n Grade: %c, Score: %f\n",
		this->firstname, this->lastname, this->gradeLetter,
		this->averageGrade
		);
}

int main (int argc, char ** argv)
{
	student *s = create_student("Simon", "Perrault", 'C', 78.9);
	s->print(s);
	free_student(s);
	return 0;
}

