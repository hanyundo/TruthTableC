#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

void i_truthtable(int n) {
	int** table;
	int cases = pow(2, n);
	int i, j;
	int acase;
	
	table = (int**)malloc(sizeof(int*)*cases);
	for(i=0; i<cases; i++)
		table[i] = (int*)malloc(sizeof(int)*n);
	
	for(i=0; i<cases; i++) {
		acase = i;
		for(j=0; j<n; j++) {
			table[i][j] = acase%2;
			acase /= 2;
		}
	}		

	for(i=0; i<cases; i++) {
		printf("<");
		for(j=n-1; j>=0; j--) {
			if(table[i][j])
				printf("true");
			else
				printf("false");
			if(j>0)
				printf(", ");
		}
		printf(">\n");
	}
	
	for(i=0; i<cases; i++)
		free(table[i]);
	free(table);
}

void r_truthtable(int* table, int pos, int finish) {
	int i;
	if(finish == pos) {
		printf("<");
		for(i=0; i<finish; i++) {
			if(table[i])
				printf("true");
			else
				printf("false");
			if(i<finish-1)
				printf(", ");
		}
		printf(">\n");
		return;
	}
	table[pos] = 0;
	r_truthtable(table, pos+1, finish);
	table[pos] = 1;
	r_truthtable(table, pos+1, finish);
}

int main(void) {
	int n;
	int* table;
	scanf("%d", &n);
	printf("<n = %d> Truth Table\n\n", n);
	
	table = (int*)malloc(n*sizeof(int));
	printf("<Recursive Function>\n");
	r_truthtable(table, 0, n);
	free(table);
	
	printf("\n<Iterable Function>\n");
	i_truthtable(n);
	
	return 0;
}
