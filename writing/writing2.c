#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

bool div_coconuts(uint64_t *pile) {
	uint32_t mod = *pile % 3;
	bool retval = mod == 1;

	*pile /= 3;
	*pile -= mod;
	return retval;
}

int main(void) {
	uint64_t pile, original_pile;

	fputs("Input: ", stdout);
	scanf("%lu", &pile);
	original_pile = pile;

	fputs("Output: ", stdout);
	if(div_coconuts(&pile) && div_coconuts(&pile) && div_coconuts(&pile)) {
		fprintf(stdout, "%lu could be the number of coconuts in the pile\n", original_pile);
		exit(0);
	}
	fprintf(stdout, "%lu could not be the number of coconuts in the pile\n", original_pile);
	exit(0);
}
