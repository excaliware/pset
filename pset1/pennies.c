#include <stdlib.h>
#include <stdio.h>

double calcpennies(int p, int d);

int main(int argc, char *argv[])
{
	int d;
	int p;
	double total;

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

	printf("Total:\n$%.2f\n", total);

	return 0;
}

/*
Calculate the amount that user will have received in total by the end of the month if that amount is doubled on every day but the first, expressed as dollars and cents.
*/
double calcpennies(int p, int d)
{
	double total = p;

	while (d > 0) {
		total *= 2;
		printf("%.0f\t", total);
		d -= 1;
	}
	printf("\n");

	total -= p;	/* do not double the amount on the first day */

	/* Express the amount as dollars and cents. */
	total /= 100.0;

	return total;
}
