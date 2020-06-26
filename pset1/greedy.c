#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define QUARTER 25
#define DIME 10
#define NICKEL 5
#define PENNY 1

int main(int argc, char *argv[])
{
	float input;
	int change;
	int ncoins;
	int n;

	do {
		printf("How much change is owed? ");
		scanf("%f", &input);
	} while (input < 0);

	/* Convert the money to cents. */
	change = lround(input * 100.0);
	printf("Change: %d cents\n", change);

	/* First calculate the number of quarters. */
	n = change / QUARTER;
	change -= n * QUARTER;
	ncoins = n;
	printf("# quarters: %d\n", n);

	n = change / DIME;
	change -= n * DIME;
	ncoins += n;
	printf("# dimes: %d\n", n);
	
	n = change / NICKEL;
	change -= n * NICKEL;
	ncoins += n;
	printf("# nickels: %d\n", n);

	/* Only pennies left. */
	ncoins += change;
	printf("# pennies: %d\n", change);

	printf("Total coins: %d\n", ncoins);

	return 0;
}
