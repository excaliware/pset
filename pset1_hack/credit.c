#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MASTERCARD	16
#define AMEX		15
#define VISA		13

int check_number(long long num);

int main(int argc, char *argv[])
{
	long long num;

	printf("Number: ");
	scanf("%lld", &num);

	while (num < 1) {
		printf("Retry: ");
		scanf("%lld", &num);
	}
	/*
	num = 378282246310005;
	*/
	
	if (!check_number(num))
		printf("VALID\n");
	else
		printf("INVALID\n");

	return 0;
}

/*
	Check if a valid credit card number was provided.
	Return 0 if the number is valid.
*/
int check_number(long long num)
{
	int iseven = 0;
	int d;
	int sum = 0;
	int num_copy = num;
	int ndigits = 0;

	while (num) {
		d = num % 10;
		printf("%d\n", d);
		if (!iseven) {
			iseven = 1;
			sum += d;
		} else {
			iseven = 0;
			d *= 2;
			if (d > 9)
				/* Sum up the two digits. */
				sum += d % 10 + d / 10;
			else
				sum += d;
		}
		ndigits++;
		num /= 10;

		printf("sum = %d; ndigits = %d\t", sum, ndigits);
	}

	/* Check start numbers. */
	num = num_copy;
	num = num / pow(10, ndigits-2);
	printf("start: %lld\n", num);

	switch (ndigits) {
	case 15:
		/* 34 or 37 */
		printf("AMEX\n");
		break;
	case 13:
		/* 4 */
		printf("VISA\n");
		break;
	case 16:
		/* visa 4; mastercard 51, 52, 53, 54, 55 */
		printf("MASTERCARD\n");
		printf("VISA\n");
		break;
	default:
		return 1;
	}

	return sum % 10 ? 1 : 0;
}
