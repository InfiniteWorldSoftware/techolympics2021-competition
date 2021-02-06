/*Sticks program*/
/*
 *The algorithm for this program wasn't as straightforward as the last one, and I'm not sure if it works 100% of the time.
 *However, it's mostly the same idea: Force the user to a range of numbers that is advantageous to the bot.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void take(int64_t num, int64_t **cnt, int64_t **xcnt) {
	if(num > **cnt)
		num = **cnt;
	**cnt -= num;
	**xcnt += num;
}

void userplay(int64_t *cnt, int64_t *bcnt, int64_t *ucnt) {
	int64_t input = 0;
	
	if(cnt <= 0)
		return;
	while(input < 1 || input > 3) {
		fputs("Input: ", stdout);
		scanf("%ld", &input);
	}

	take(input, &cnt, &ucnt);
}

void botplay(int64_t *cnt, int64_t *bcnt, int64_t *ucnt) {
	/*Avoid negatives*/
	if(*cnt <= 0)
		return;
	/*Take 2 if we are odd already*/
	if(*bcnt % 2 && *cnt > 1)
		take(2, &cnt, &bcnt);
	/*If not, become odd.*/
	else if(!(*bcnt % 2) && *cnt >= 3)
		take(3, &cnt, &bcnt);
	else if(!(*bcnt % 2) && *cnt < 3)
		take(1, &cnt, &bcnt);
}

int main(void) {
	int64_t cnt, ucnt = 0, bcnt = 0;

	/*Function pointers to make selecting players easier*/
	void (*player1)(int64_t *, int64_t *, int64_t *);
	void (*player2)(int64_t *, int64_t *, int64_t *);

	while(!(cnt % 2)) {
		fputs("Input: ", stdout);
		scanf("%ld", &cnt);
	}

	//User goes first if even
	if(cnt % 2) {
		player1 = userplay;
		player2 = botplay;
	}
	else {
		player1 = botplay;
		player2 = userplay;
	}

	while(cnt > 0) {
		fprintf(stdout, "Sticks remaining: %ld   Bot sticks: %ld   User sticks: %ld\n", cnt, bcnt, ucnt);
		player1(&cnt, &bcnt, &ucnt);
		fprintf(stdout, "Sticks remaining: %ld   Bot sticks: %ld   User sticks: %ld\n", cnt, bcnt, ucnt);
		player2(&cnt, &bcnt, &ucnt);
	}

	fprintf(stdout, "Sticks remaining: %ld   Bot sticks: %ld   User sticks: %ld\n", cnt, bcnt, ucnt);

	fprintf(stdout, "You %s!\n", (ucnt % 2) ? "win" : "lose");
	fprintf(stdout, "Bot %s!\n", (bcnt % 2) ? "wins" : "loses");

	return 0;
}
