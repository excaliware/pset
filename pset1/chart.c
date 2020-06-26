#include <stdlib.h>
#include <stdio.h>

#define SCREEN_WIDTH 80
#define BAR_CHAR '#'

int main(int argc, char *argv[])
{
	int mf, fm, ff, mm;
	int sum;
	int npounds;
	int i;

	printf("Enter M-F F-M F-F M-M: ");
	scanf("%d", &mf);
	scanf("%d", &fm);
	scanf("%d", &ff);
	scanf("%d", &mm);

	printf("\nWho is spotting whom\n");

	sum = mf + fm + ff + mm;

	if (mf == 0)
		npounds = 0;
	else
		npounds = SCREEN_WIDTH / ((float) sum / mf);
	printf("M-F %d\n", mf);
	for (i = 0; i < npounds; i++) {
		printf("%c", BAR_CHAR);
	}
	printf("\n");

	if (fm == 0)
		npounds = 0;
	else
		npounds = SCREEN_WIDTH / ((float) sum / fm);
	printf("F-M %d\n", fm);
	for (i = 0; i < npounds; i++) {
		printf("%c", BAR_CHAR);
	}
	printf("\n");

	if (ff == 0)
		npounds = 0;
	else
		npounds = SCREEN_WIDTH / ((float) sum / ff);
	printf("F-F %d\n", ff);
	for (i = 0; i < npounds; i++) {
		printf("%c", BAR_CHAR);
	}
	printf("\n");

	if (mm == 0)
		npounds = 0;
	else
		npounds = SCREEN_WIDTH / ((float) sum / mm);
	printf("M-M %d\n", mm);
	for (i = 0; i < npounds; i++) {
		printf("%c", BAR_CHAR);
	}
	printf("\n");

	return 0;
}
