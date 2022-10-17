/*
TicTacToe by Avighnash Kumar. 9/30/22.
Play a game of TicTacToe, made in C++!
*/

#include <iostream>

using namespace std;

// Variables
char board[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };

int x_wins = 0;
int o_wins = 0;
int ties = 0;

char X_TURN = 'X';
char O_TURN = 'O';

char current_turn = X_TURN;

bool playing = true;

// Draws the board
void drawBoard() {
	cout << "\n\n    1     2     3  " << endl;
	cout << "       |     |     " << endl;
    	cout << "A   " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    	cout << "  _____|_____|_____" << endl;
    	cout << "       |     |     " << endl;
    	cout << "B   " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    	cout << "  _____|_____|_____" << endl;
   	cout << "       |     |     " << endl;
    	cout << "C   " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
    	cout << "       |     |     \n\n" << endl;
}

// Sets new turn
void setTurn(char turn) {
	current_turn = turn;
}

// Iterates over every slot and sets to an empty char
void clearBoard() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}
}

// Performs a turn
void performTurn() {
	char choice[2];
	cin >> choice;

	int row, column;

	// Checks if row input is valid and sets to appropriate numeric value
	if (choice[0] == 'a') {
		row = 0;
	}
	else if (choice[0] == 'b') {
		row = 1;
	}
	else if (choice[0] == 'c') {
		row = 2;
	}
	else {
		cout << "Invalid row identifier! You should enter a, b, or c. Try again." << endl;
		performTurn();
	}

	// CHecks if column input is valid and sets to appropriate numeric value
	if (choice[1] == '1') {
		column = 0;
	}
	else if (choice[1] == '2') {
		column = 1;
	}
	else if (choice[1] == '3') {
		column = 2;
	}
	else {
		cout << "Invalid column identifier! You should enter 1, 2, or 3. Try again." << endl;
		performTurn();
	}	

	// Checks to see if spot is taken
	if (board[row][column] != ' ') {
		cout << "Spot is taken! Try again." << endl;
		performTurn();
	}

	board[row][column] = current_turn;
}

// Checks for win conditions for the turn
bool checkWin(char turn) {
	for (int i = 0; i < 3; i++) {
		// Row win condition
		if (board[i][0] == turn && board[i][1] == turn && board[i][2] == turn) {
			return true;
		}

		// Column win condition
		if (board[0][i] == turn && board[1][i] == turn && board[2][i] == turn) {
			return true;
		}
	}
	
	// Diagonal win conditions
	if ((board[0][0] == turn && board[1][1] == turn && board[2][2] == turn) || (board[0][2] == turn && board[1][1] == turn && board[2][0] == turn)) {
		return true;
	}	

	return false;
}

// Iterates over every slots to see if there are any empty slots and if tehre aren't, sets to true to indicate a tie
bool checkTie() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == ' ') {
				return false; // empty slot exists, board isn't filled yet
			}
		}
	}

	return true; // tie
}

// Switches turn
void switchTurn() {
	if (current_turn == X_TURN) {
		current_turn = O_TURN;
	}
	else if (current_turn == O_TURN) {
		current_turn = X_TURN;
	}
}

// Prints the number of wins/ties and prompts the user if they want to continue playing
void performRoundEndSequence() {
	cout << "\nX has " << x_wins << " wins, O has " << o_wins << " wins, and there are " << ties << " ties." << endl;
	cout << "Would you like to keep playing? (y/n)" << endl;
		
	char answer;
	cin >> answer;

	if (answer == 'y') {
		playing = true;
		clearBoard(); // reset board
		current_turn = X_TURN; // x starts first
	}
	else if (answer == 'n') {
		playing = false;
	}
}

int main() {
	cout << "Tic Tac Toe\n" << endl;
	cout << "When it's your turn, enter a letter followed by a number of the spot corresponding to your desired move.\n" << endl;

	while (playing) {
		drawBoard();
		cout << "It's " << current_turn << "'s turn! Enter a letter and number to choose your spot." << endl;
		performTurn();

		if (checkWin(X_TURN)) {
			drawBoard();
			x_wins++;
			cout << "\nX WON!!!" << endl;
			performRoundEndSequence();
		}
		else if (checkWin(O_TURN)) {
			drawBoard();
			o_wins++;
			cout << "\nO WON!!!" << endl;
			performRoundEndSequence();
		}
		else if (checkTie()) {
			drawBoard();
			ties++;
			cout << "\nTIE!!!" << endl;
			performRoundEndSequence();
		}
		else {
			switchTurn();
		}
	}

	return 0;
};
