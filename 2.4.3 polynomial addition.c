#include <stdio.h>
#define MAX_TERMS 100
#define COMPARE(x, y) ((x < y ? -1 : (x == y) ? 0:1))

typedef struct {float coef; int expon;}polynomial;
polynomial terms[MAX_TERMS];
int avail = 0;

void padd(int startA, int finishA, int startB, int finishB, int* startD, int* finishD){
	float coefficient;
	*startD = avail;
	while (startA <= finishA && startB <= finishB)
		switch (COMPARE(terms[startA].expon, terms[startB].expon)) {
		case -1:
			attach(terms[startB].coef, terms[startB].expon);
			startB++;
			break;
		case 0:
			coefficient = terms[startA].coef + terms[startB].coef;
			if (coefficient)
				attach(coefficient, terms[startA].expon);
			startA++; startB++;
			break;
		case 1:
			attach(terms[startA].coef, terms[startA].expon);
			startA++;
		}
	for (; startA <= finishA; startA++)
		attach(terms[startA].coef, terms[startA].expon);
	*finishD = avail - 1;
}
void attach(float coefficient, int exponent)
{
	if (avail >= MAX_TERMS) {
		fprintf(stderr, "Too many terms in the polynomial.");
		exit(1);
	}
	terms[avail].coef = coefficient;
	terms[avail++].expon = exponent;
}