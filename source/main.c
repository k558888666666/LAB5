#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int wdeck[][13])
{
	int row, column, card;
	for (card = 1; card <= 52; card++)
	{
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wdeck[row][column] != 0);
		wdeck[row][column] = card;
	}
}
void deal(const int wdeck[][13], const int *wface[], const int *wsuit[])
{
	int row, column, card;
	for ( card = 1; card <= 52; card++)
	{
		for (row = 0; row <= 3; row++)
		{
			for (column = 0; column <= 12; column++)
			{
				if (wdeck[row][column] == card)
				{
					printf("%5s of %-8s%c", wface[column], wsuit[row], card % 2 == 0 ? '\n' : '\t');
				}
			}
		}
	}
}

int main(void)
{
	const char *suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	const char *face[13] = { "ace","deuce" ,"three", "four", "five" ,"six", "seven", "eight", "nine","ten","jack","queen","king" };
	int deck[4][13] = { 0 };
	srand(time(0));
	shuffle(deck);
	deal(deck, face, suit);
	system("pause");
	return 0;
	
	
}