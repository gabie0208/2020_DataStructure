/*ADT SPARSE MATRIX
	objects: a set of triples, <row, column, value>, where row and column are integers and form a unique combination, 
			 and value comes from the set item.
	fuctions: 
			1. Sparse_Matrix Create(max_row, max_col) ::=
					return a Sparse_Matrix that can hold up to
					max_items = max_row * max_col and whose
					maximum row size is max_row and whose maximum column size is max_col.
					
			2. Sparse_Matrix Transpose(a) ::=
					return the matrix produced by interchaning the row and column value of every triple.
					
			3. Sparse_Matrix Add(a, b) ::=
					if the dimension of a and b are the same
					return the matrix produced by adding corresponding items, namely those with identical row and column values.
					else return error.
					
			4. Sparse_Matrix Multiply(a, b) ::=
					if number of columns in a equals number of rows in b
					return the matrix d produced by multiplying a by
					b accroing to the formula : d(i, j) =  SUM a(i, k)¡¤b(k, j),
					where d(i, j) is the (i, j)th element
					else return error.
			
			5. end Sparse_Matrix*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101
#define MAX_COL 100

typedef struct {
	int col, row, value;
}term;

term a[MAX_TERMS];

void transpose(term a[], term b[])
{
	int n, i, j, currentb;
	n = a[0].value;
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = n;

	if (n > 0) {
		currentb = 1;
		for(i=0; i<a[0].col; i++)
			for(j=1; j<=n; j++)
				if (a[j].col == i) {
					b[currentb].row = a[j].col;
					b[currentb].col = a[j].row;
					b[currentb].value = a[j].value;
					currentb++;
				}
	}
}

void fast_transpose(term a[], term b[])
{
	int row_terms[MAX_COL], starting_pos[MAX_COL];
	int i, j;
	int num_cols = a[0].col; 
	int num_terms = a[0].value;
	b[0].row = num_cols; 
	b[0].col = a[0].value;
	b[0].value = num_terms;

	if (num_terms > 0) {
		for (i = 0; i < num_cols; i++)	
			row_terms[i] = 0;
		for (i = 1; i <= num_terms; i++)		
			row_terms[a[i].col]++;
		starting_pos[0] = 1;

		for (i = 1; i < num_cols; i++)	
			starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];
		for (i = 1; i <= num_terms; i++) {
			j = starting_pos[a[i].col]++;
			b[j].row = a[i].col;
			b[j].col = a[i].row;
			b[j].value = a[i].value;
		}
	}
}

void mmult(term a[], term b[], term d[])
{
	int i, j, column;
	int totalb = b[0].value;
	int totald = 0;
	int rows_a = a[0].row,
		cols_a = a[0].col,
		totala = a[0].value;
	int cols_b = b[0].col;
	int row_begin = 1,
		row = a[1].row,
		sum = 0;
	term new_b[MAX_TERMS];

	if (cols_a != b[0].row) {
		fprintf(stderr, "Incompatible matrices\n");
		exit(1);
	}
	fast_transpose(b, new_b);
	
	a[totala + 1].row = rows_a;
	new_b[totalb + 1].row = cols_b;
	new_b[totalb + 1].col = -1;

	for (i = 1; i <= totala;) {
		column = new_b[1].row;
		for (j = 1; j <= totalb + 1;) {
			if (a[i].row != row) {
				storeSum(d, &totald, row, column, &sum);
				i = row_begin;
				for (; new_b[j].row == column; j++)
					;
				column = new_b[j].row;
			}
			else if (new_b[j].row != column) {
				storeSum(d, &totald, row, column, &sum);
				i = row_begin;
				column = new_b[j].row;
			}
			else switch (COMPARE(a[i].col, new_b[j].col)) {
			case -1:
				i++; break;
			case 0:
				sum += (a[i++].value * new_b[j++].value); break;
			case 1:
				j++;
			}
		}
		for (; a[i].row == row; i++)
			;
		row_begin = i;
		row = a[i].row;
	}
	d[0].row = rows_a;
	d[0].col = cols_b;
	d[0].value = totald;
}

void storeSum(term d[], int* totald, int row, int column, int* sum)
{
	if(*sum)
		if (*totald < MAX_TERMS) {
			d[++ * totald].row = row;
			d[*totald].col = column;
			d[*totald].value = *sum;
			*sum = 0;
		}
		else {
			fprintf(stderr, "Numbers of terms in product exceeds %d\n", MAX_TERMS);
			exit(EXIT_FAILURE);
		}
}