#include <stdlib.h>
#include <stdio.h>

#define SCREEN_WIDTH	80
#define MAX_BAR_HEIGHT	20
#define BAR_WIDTH	3
#define BAR		"###"
#define BAR_EMPTY	"   "

int main(int argc, char *argv[])
{
	int mf, fm, ff, mm;
	int sum;
	int i;

	printf("Enter M-F F-M F-F M-M: ");
	scanf("%d", &mf);
	scanf("%d", &fm);
	scanf("%d", &ff);
	scanf("%d", &mm);

	printf("\nWho is spotting whom\n");

	sum = mf + fm + ff + mm;
	if (sum == 0)
		return 0;

	printf("M-F: %d F-M: %d F-F: %d M-M: %d\n", mf, fm, ff, mm);

	mf = MAX_BAR_HEIGHT * ((float) mf / sum);
	fm = MAX_BAR_HEIGHT * ((float) fm / sum);
	ff = MAX_BAR_HEIGHT * ((float) ff / sum);
	mm = MAX_BAR_HEIGHT * ((float) mm / sum);

	printf("M-F: %d F-M: %d F-F: %d M-M: %d\n", mf, fm, ff, mm);

	for (i = 0; i < MAX_BAR_HEIGHT; i++) {
		if (mf >= MAX_BAR_HEIGHT-i) {
			printf("%s  ", BAR);
		} else {
			printf("%s  ", BAR_EMPTY);
		}

		if (fm >= MAX_BAR_HEIGHT-i) {
			printf("%s  ", BAR);
		} else {
			printf("%s  ", BAR_EMPTY);
		}

		if (ff >= MAX_BAR_HEIGHT-i) {
			printf("%s  ", BAR);
		} else {
			printf("%s  ", BAR_EMPTY);
		}

		if (mm >= MAX_BAR_HEIGHT-i) {
			printf("%s  ", BAR);
		} else {
			printf("%s  ", BAR_EMPTY);
		}
		printf("\n");
	}

	printf("M-F  F-M  F-F  M-M\n");

	return 0;
}
