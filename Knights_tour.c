/*=============================================================================
*                               KnightsTour
*=============================================================================*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define BOARD_SIZE  8
typedef int board_t[BOARD_SIZE][BOARD_SIZE];

#define MOVE_COUNT 8 /**< Number of moves that a knight can make */
const int MOVES_X[MOVE_COUNT] = {2, 1, -1, -2, -2, -1, 1, 2};
const int MOVES_Y[MOVE_COUNT] = {1, 2, 2, 1, -1, -2, -2, -1};


//________________________________________ check if done ________________________________________
bool move_is_possible(size_t moveId, size_t x, size_t y, board_t visited)
{
	int new_x = (int)x + MOVES_X[moveId]; //(int) "casts" x from unsigned size_t to signed int
	int new_y = (int)y + MOVES_Y[moveId];

	if (   new_x < 0 || new_x >= BOARD_SIZE
	    || new_y < 0 || new_y >= BOARD_SIZE)
	{
		return false;
	}
	if (visited[new_x][new_y] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//________________________________________ Shuffle ________________________________________//
// https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle with help from ChatGPT
void fisher_yates(int *moves) //shuffle the moves / make it random using the fisher-yates algorithm
{ 

    for (int i = MOVE_COUNT -1; i>0 ; i--) //reverse treverse the move list
    { 
        int j = rand() % (i+1);
        int tmp_move = moves[i];
        moves[i] = moves[j];
        moves[j] = tmp_move;
    }

}

//________________________________________ Tour_greedy a single square ________________________________________

unsigned int tour_greedy(size_t start_x, size_t start_y)
{
    board_t board;
    int numMoves = 0;

    // reset the board with zeros
    for (int x = 0; x < BOARD_SIZE; x++)
        for (int y = 0; y < BOARD_SIZE; y++)
            board[x][y] = 0;

    while (true)
    {
        board[start_x][start_y] = 1; //mark the visisted positions

        // make a list of moves and shuffle them
        int moves[MOVE_COUNT];
        for (int i = 0; i < MOVE_COUNT; i++)
            moves[i] = i;
        fisher_yates(moves);

        // find the first possible move among the shuffled ones
        int moveId = -1;
        for (int i = 0; i < MOVE_COUNT; i++) {
            if (move_is_possible(moves[i], start_x, start_y, board)) {
                moveId = moves[i];
                break;
            }
        }

        if (moveId == -1)
            break; // no moves left

        numMoves++;

        // update position
        start_x += MOVES_X[moveId];
        start_y += MOVES_Y[moveId];
    }

    return numMoves;
}


//________________________________________ Call helper ________________________________________
void greedy_tour_from_each_square(void) //call helper function for each square
{
	for (int y = 0; y < BOARD_SIZE; y++)
	{
		for (int x = 0; x < BOARD_SIZE; x++)
		{
			tour_greedy(x, y);
			printf(" %2d", tour_greedy(x, y)); 
		}
		printf("\n");
	}
}

//________________________________________ MAIN ________________________________________//

int main()
{
    srand(time(NULL));
    greedy_tour_from_each_square();
    return 0;
}



