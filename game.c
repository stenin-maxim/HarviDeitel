/* Игра в крепс */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(void);

int main()
{
	int gameStatus, sum, myPoint;

	srand(time(NULL));
	sum = rollDice();  /* первый выброс костей */

	switch (sum) {
		case 7: case 11:	/* выйгрыш при первом броске */
			gameStatus = 1;
			break;
		case 2: case 3: case 12: /* пройгрыш при первом броске */
			gameStatus = 2;
			break;
		default:		/* запомнить очки */
			gameStatus = 0;
			myPoint = sum;
			printf("Point is %d\n", myPoint);
			break;
	}

	while (gameStatus == 0) { /* продолжать бросать */
		sum = rollDice();

		if (sum == myPoint)  /* выйгрышь повторным выбросов очков */
			gameStatus = 1;
		else 
			if (sum == 7)  /* пройгрыш при выборе 7 */
				gameStatus = 2;
	}

	if (gameStatus == 1) 
		printf("Player wins\n");
	else 
		printf("Player loses\n");
	

	return 0;
}

int rollDice(void)
{
	int die1, die2, workSum;

	die1 = 1 + (rand() % 6);
	die2 = 1 + (rand() % 6);
	workSum = die1 + die2;
	printf("Player rolled %d + %d = %d\n", die1, die2, workSum);

	return workSum;
}

