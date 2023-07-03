#include <iostream>
#include <cmath>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int score = 0;

void add_cell(int a[][4]);
int gameover_check_lose(int a[][4]);
void game_init(int a[][4]);
void up(int a[][4]);
void down(int a[][4]);
void right(int a[][4]);
void left(int a[][4]);
void print(int a[][4]);
bool equal(int a[][4], int temp[][4]);
bool win_check(int a[][4]);
void revert_back_move(int a[][4], int prev[][4]);





void add_cell(int a[][4])
{
	/* Randomly selects a row and column and then checks if the generated cell is empty. if it is empty then it randomly assigns a value of either 1 or 2 to the cell.
	if the cell is not empty then it keeps generating new values of rows and columns until it gets a empty cell. */

	srand(time(0));
	int row;
	int column;

	while(1)
	{
		row = rand() % 4;
		column = rand() % 4;
		if (a[row][column] == 0)
		{
			a[row][column] = 1 + rand() % 2;
			break;
		}
	}

}

int gameover_check_lose(int a[][4])
{
	/* Simply checks if any equal or empty cell is left. if they are left then returns 0 else returns 1 */
	int empty_cell = 0, equal_cell = 0;

	for (int i = 0; i < 4; i++)

		for (int j = 0; j < 4; j++)

			if (a[i][j] == 0)
			{
				empty_cell = 1;
				break;
			}

	for (int i = 0; i < 3; i++)

		for (int j = 0; j < 3; j++)

			if (a[i + 1][j] == a[i][j] || a[i][j + 1] == a[i][j])
			{
				equal_cell = 1;
				break;
			}

	if (empty_cell || equal_cell)

		return 0;

	else

		return 1;


}

void game_init(int a[][4])
{
	/* Displays the main screen and initialises the grid  */
	cout << "\n\n\n\n\t\t\t1024 GAME\n\n\n\t\t";
	cout << "\n\n\t\t\tProgramming Fundamentals Project\n\n\n\t\t";
	cout << "\n\n\t\t\tGroup Memebers:\n\n\n\t\t";
	cout << "\t\t\tMuhammad Abdullah 21L-5288\n\n\n\t\t";
	cout << "\t\t\tSafi Ullah 21L-1851\n\n\n\t\t";
	cout << "\t\t\tMenal Naeem 21L-1872\n\n\n\t\t";
	system("pause");
	system("cls");

	int rn1, rn2, rn3, rn4;
	srand(time(0));

	rn1 = rand() % 4;
	rn2 = rand() % 4;

	while (1)
	{
		rn3 = rand() % 4;
		rn4 = rand() % 4;

		if (rn3 != rn1 && rn4 != rn2)
			break;


	}

	a[rn1][rn2] = 1 + rand() % 3;
	a[rn3][rn4] = 1 + rand() % 3;

	print(a);





}

void up(int a[][4])
{
	int row, column;
	for (int j = 0; j < 4; j++)
	{
		row = 0, column = j;
		for (int i = 1; i < 4; i++)
		{
			if (a[i][j] != 0)
			{
				if (a[i - 1][j] == 0 || a[i - 1][j] == a[i][j])
				{
					if (a[row][column] == a[i][j])
					{
						a[row][column] *= 2;
						a[i][j] = 0;
					}
					else
					{
						if (a[row][column] == 0)
						{
							a[row][column] = a[i][j];
							a[i][j] = 0;
						}
						else
						{
							a[++row][column] = a[i][j];
							a[i][j] = 0;
						}
					}
				}
				else row++;
			}
		}
	}
}



int main()
{

	int a[4][4] = { 0 };
	int temp[4][4] = { 0 };
	int prev[4][4] = { 0 };

	game_init(a);

	char in;
	bool revert = 0;

	while(1)
	{




		for (int i = 0; i < 4; i++)

			for (int j = 0; j < 4; j++)

				prev[i][j] = temp[i][j];








		for (int i = 0; i < 4; i++)

			for (int j = 0; j < 4; j++)

				temp[i][j] = a[i][j];



		cout << "press R for right, L for left, U for up, D for down, B to revert back one move, O to restart game and Esc to exit" << endl;

		in = _getch();

		system("cls");

		if (in == 117 || in == 'w')
        {
			up(a);
			revert = 0;

        }

		if (in == 100 || in == 's')
        {
			down(a);
			revert = 0;

        }

		if (in == 108 || in == 'a')
        {

			left(a);
			revert = 0;
        }

		if (in == 114 || in == 'd')
        {
			right(a);
			revert = 0;

        }

		if (in == 111 || in == 'o')
		{
			main();
			revert = 0;

		}

		if (in == 98 || in == 'b')
		{
			if (!revert)
			{
				revert_back_move(a, prev);

				revert = 1;

			}


		}

		if (in == 27 || in == 'e')
			break;

		if (!equal(a, temp) && !revert)
		{
			add_cell(a);
			score += 10;

		}


		print(a);

		if (win_check(a))
		{
			cout << "\n\n\t\t\tYou Won!!!\n\n\n";
			system("pause");
			break;
		}

		if (gameover_check_lose(a))
		{
			cout << "\n\n\t\t\tGAME OVER!!!\n\n\n";
			system("pause");
			break;
		}
	}
	return 0;
}




void right(int a[][4])
{
	int row, column;
	for (int i = 0; i < 4; i++)
	{
		row = i, column = 3;
		for (int j = 2; j >= 0; j--)
		{
			if (a[i][j] != 0)
			{
				if (a[i][j + 1] == 0 || a[i][j + 1] == a[i][j])
				{
					if (a[row][column] == a[i][j])
					{
						a[row][column] *= 2;
						a[i][j] = 0;
					}
					else
					{
						if (a[row][column] == 0)
						{
							a[row][column] = a[i][j];
							a[i][j] = 0;
						}
						else
						{
							a[row][--column] = a[i][j];
							a[i][j] = 0;
						}
					}
				}
				else column--;
			}
		}
	}
}



void print(int a[][4])
{
	/* Prints the grid on the screen */


	cout << "\n\n\n";
	cout << "\t---------------------------------------------------------------------------" << endl << endl;
	for (int row = 0; row < 4; row++)
	{
		cout << "\t |";
		for (int col = 0; col < 4; col++)
		{
			cout << "\t |";
			if (a[row][col] != 0)
            {
                cout << a[row][col];

            }
            else
            {
                cout << "  ";
            }
            cout << "| \t";

		}
		cout << "\t|  \n" << endl;

	}

	cout << "\t---------------------------------------------------------------------------" << endl;

	cout << "\t\t\t\tSCORE: " << score << "\n";
}

void down(int a[][4])
{
	int row, column;
	for (int j = 0; j < 4; j++)
	{
		row = 3, column = j;
		for (int i = 2; i >= 0; i--)
		{
			if (a[i][j] != 0)
			{
				if (a[i + 1][j] == 0 || a[i + 1][j] == a[i][j])
				{
					if (a[row][column] == a[i][j])
					{
						a[row][column] *= 2;
						a[i][j] = 0;
					}
					else
					{
						if (a[row][column] == 0)
						{
							a[row][column] = a[i][j];
							a[i][j] = 0;
						}
						else
						{
							a[--row][column] = a[i][j];
							a[i][j] = 0;
						}
					}
				}
				else row--;
			}
		}
	}
}

void left(int a[][4])
{
	int row, column;
	for (int i = 0; i < 4; i++)
	{
		row = i, column = 0;
		for (int j = 1; j < 4; j++)
		{
			if (a[i][j] != 0)
			{
				if (a[i][j - 1] == 0 || a[i][j - 1] == a[i][j])
				{
					if (a[row][column] == a[i][j])
					{
						a[row][column] *= 2;
						a[i][j] = 0;
					}
					else
					{
						if (a[row][column] == 0)
						{
							a[row][column] = a[i][j];
							a[i][j] = 0;
						}
						else
						{
							a[row][++column] = a[i][j];
							a[i][j] = 0;
						}
					}
				}
				else column++;
			}
		}
	}
}

bool equal(int a[][4], int temp[][4])
{
	/* checks if 2 arrays passed to it are equal. the game compares the the grid before and after input from user to check if any change was made to the grid by the users moves */

	bool f = 1;

	for (int i = 0; i < 4; i++)

		for (int j = 0; j < 4; j++)

			if (temp[i][j] != a[i][j])
			{
				f = 0;
				break;
			}


	return f;



}

bool win_check(int a[][4])
{
	/* Checks if any cell in the grid holds a value of 1024. if any cell does hold a value of 1024, the function returns 1 and the game goes into the win state,
	 else returns 0 and the game carries on */
	bool f = 0;

	for (int i = 0; i < 4; i++)

		for (int j = 0; j < 4; j++)

			if (a[i][j] == 1024)
			{
				f = 1;
				break;

			}

	return f;


}

void revert_back_move( int a[][4], int prev[][4])
{
	/* Copies the state of the grid before the last move to the current grid. Used to implement the revert back functionality of the game.
	The last state of the grid is saved in an array(prev) like a save state whose contents are then copied back to the array holding the current grid(a) */
	for (int i = 0; i < 4; i++)

		for (int j = 0; j < 4; j++)

			a[i][j] = prev[i][j];



}

