#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long calcpennies(int p, int d);
char *format_number(long num);

int main(int argc, char *argv[])
{
	int d;
	int p;
	long total;

	do {
		printf("Days in month: ");
		scanf("%d", &d);
	} while (d < 28 || d > 31);

	do {
		printf("Pennies on first day: ");
		scanf("%d", &p);
	} while (p < 1);

	printf("\n%d days, %d pennies.\n", d, p);

	total = calcpennies(p, d);

	printf("Total cents: %ld\n", total);

	printf("$%s\n", format_number(total));

	return 0;
}

/* Format a given number as a string representing the number with thousands separators. */
char *format_number(long num)
{
	int ngroups = 0;
	int groups[6];
	int cents;
	char *str = malloc(18);
	char buffer[5];
	int i;

	/* Get cents. */
	cents = num % 100;
	num /= 100;

	while (num / 1000 != 0) {
		groups[ngroups] = num % 1000;
		ngroups++;
		num /= 1000;
	}

	sprintf(buffer, "%ld", num);
	strcpy(str, buffer);

	for (i = ngroups-1; i >= 0; i--) {
		sprintf(buffer, ",%d", groups[i]);
		strcat(str, buffer);
	}

	sprintf(buffer, ".%d", cents);
	strcat(str, buffer);
	
	return str;
}

/*
Calculate the amount that user will have received in total by the end of the month if that amount is doubled on every day but the first, expressed as dollars and cents.
*/
long calcpennies(int p, int d)
{
	long total = p;

	while (d > 0) {
		total *= 2;
		printf("%lu\t", total);
		d -= 1;
	}
	printf("\n");

	total -= p;	/* do not double the amount on the first day */

	/* Express the amount as dollars and cents.
	total /= 100.0;
	*/
	return total;
}
