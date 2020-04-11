#include<iostream>
#include<conio.h>
using namespace std;


//two player game
class player
{
	char x;
public:
	player(char c)
		:x{ c } {};
	
};

//invludes game board, player list , 
class game {
	
	char a[3][3];
public:
	game();
	void game_board();
	void add_X();
	int win_X();
	int win_O();
	void add_O();

};

void game::add_X()
{
	char n;
	int b;
	cout << "player'X' turn, enter position: "<<endl;
	cin >> n;
	for(int i=0;i<3;i++)
		for (int j = 0; j < 3; j++)
		{
			if (a[i][j] == n)
				a[i][j] = 'X';
			
			
		}

	b = win_X();
	if (b == 1) {
		system("cls");
		game_board();
		cout << "Player 'X' wins" << endl;
		exit('0');
	}
}


void game::add_O()
{
	char n;
	int b;
	cout << "player'O' turn, enter position: " << endl;
	cin >> n;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (a[i][j] == n)
				a[i][j] = 'O';
			

		}
	b = win_O();
	if (b == 1)
	{
		system("cls");
		game_board();
		cout << "player 'O' wins" << endl;
		exit('0');
	}
}


int game::win_X()
{
	for (int i = 0; i < 3; i++)
	{
		return ((a[i][0] == 'X' && a[i][1] == 'X' && a[i][2] == 'X') || (a[0][i] == 'X' && a[1][i] == 'X' && a[2][i] == 'X') || (a[2][2] == 'X' && a[1][1] == 'X' && a[0][0] == 'X') || (a[0][2] == 'X' && a[1][1] == 'X' && a[2][0] == 'X'));
	}

}
int game::win_O()
{
	for (int i = 0; i < 3; i++)
	{
		return ((a[i][0] == 'O' && a[i][1] == 'O' && a[i][2] == 'O') || (a[0][i] == 'O' && a[1][i] == 'O' && a[2][i] == 'O') || (a[2][2] == 'O' && a[1][1] == 'O' && a[0][0] == 'O') || (a[0][2] == 'O' && a[1][1] == 'O' && a[2][0] == 'O'));
	}

}

game::game()
	: a{ {'1','2','3'},{'4','5','6'},{'7','8','9'} } {}


void game::game_board()
{
	for (int i = 0; i < 3; i++)
	{
		cout << a[i][0] << " | " << a[i][1] << " | " << a[i][2] << endl;
		cout << "---------" << endl;
	}
}

int main()
{
	game g;
	char ch;
	while (true) {
		g.game_board();
		g.add_X();
		system("cls");
		g.game_board();
		g.add_O();
		system("cls");

		


	}
}