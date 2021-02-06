#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {
	int32_t ctl;

	fputs("Input: ", stdout);
	scanf("%d", &ctl);
	fputs("Output: ", stdout);
	if(!(ctl % 3))
		fputs("Tech", stdout);
	if(!(ctl % 7))
		fputs("Olympics", stdout);
	if((ctl % 3) && (ctl % 7))
		fprintf(stdout, "%i", ctl);
	fputs("\n", stdout);

	return 0;
}
