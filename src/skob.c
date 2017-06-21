#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>


int trade (char skobki) {
	switch (skobki) {
		case '(' :
			return 1;
		case '[' :
			return 2;
		case '{' :
			return 3;
		case ')' :
			return -1;
		case ']' :
			return -2;
		case '}' :
			return -3;
		default     :
			return 0;
	}
}

FILE *open_file (char *file_name) {
	FILE *f = fopen(file_name, "r");
	return f;
}

int check (FILE *f) {
	int *s = (int *) malloc(sizeof(int));
	char c;
	int ctr, i = 0, found = 0;
	
	do {
		c = getc(f);
		ctr = trade(c);
		if (ctr > 0) {
			s[ i ] = ctr;
			i++;
		} else if (ctr < 0) {
			if (i > 0 && (s[ i - 1 ] + ctr) == 0)
				i--;
			else {
				found = 1;
				break;
			}
		}
	} while (c != EOF);
	
	if (!i && !found)
		return 1;
	else
		return 0;
}
