#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

typedef struct {
	char name[10];
	int age;
	float salary;
} humanBeing;

int humans_equal(humanBeing, humanBeing);

void main(){
	humanBeing person1, person2;
	int rv;

	strcpy(person1.name, "James");
	person1.age = 10;
	person1.salary = 35000;

	strcpy(person2.name, "Jessy");
	person2.age = 11;
	person2.salary = 40000;

	if(humans_equal(person1, person2))
		printf("The two human beings are the same.\n");
	else
		printf("The two human beings are not the same.\n");
}

int humans_equal(humanBeing person1, humanBeing person2) {
	/* returns TRUE if person1 and person2 are the same human being.
	   otherwise return FALSE */
	if(strcmp(person1.name, person2.name)) return FALSE;
	if(person1.age != person2.age) return FALSE;
	if(person1.salary != person2.salary) return FALSE;
	return TRUE;
}
