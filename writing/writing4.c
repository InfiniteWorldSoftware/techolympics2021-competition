#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void userplay(int64_t *cnt, int64_t *ucnt) {
	while(*ucnt < 1 || *ucnt > 3)
		scanf("%ld", ucnt);

	*cnt -= *ucnt;
}

void botplay(int64_t *cnt, uint64_t *ucnt) {
	
}

int main(void) {
	int64_t cnt, ucnt = 0, bcnt = 0;

	while(!(cnt % 2))
		scanf("%ld", &cnt);

	while(cnt) {
		fprintf(stdout, "Sticks remaining: %ld\n", cnt);
		userplay(&cnt, &ucnt);
		fprintf(stdout, "Sticks remaining: %ld\n", cnt);
		botplay(&cnd, &bcnt);
	}

	return 0;
}
