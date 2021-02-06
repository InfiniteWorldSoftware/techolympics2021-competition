#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int userplay(int64_t *pebs) {
	int64_t play;
	fputs("Input number of pebbles to remove: ", stdout);
	scanf("%lu", &play);

	if(play < 1 || play > 5) {
		fputs("Invalid play.\n", stdout);
		return 1;
	}

	*pebs -= play;

	if(*pebs <= 0) {
		fputs("You win!\n", stdout);
		exit(0);
	}
	return 0;
}

void botplay(int64_t *pebs) {
	if(*pebs >= 12 || *pebs <= 5)
		*pebs -= 5;
	else
		*pebs -= (*pebs - 6);

	if(*pebs <= 0) {
		fputs("Bot wins!\n", stdout);
		exit(0);
	}
}

int main(void) {
	int64_t starting_pebbles;

	fputs("Number of pebbles to start with: ", stdout);
	scanf("%ld", &starting_pebbles);

	/* This code has the bot go first if the starting pebbles are less than 5. It's disabled, but if you want to have the bot win every time, enable it.
	if(starting_pebbles <= 5)
		botplay(&starting_pebbles);
	*/
	
	while(starting_pebbles) {
		fprintf(stdout, "Number of pebbles remaining: %ld\n", starting_pebbles);

INVAL: ;
		if(userplay(&starting_pebbles))
			goto INVAL;
		
		fprintf(stdout, "Number of pebbles remaining: %ld\n", starting_pebbles);
		botplay(&starting_pebbles);
	}
	return 0;
}
