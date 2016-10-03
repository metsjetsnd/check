#include <iostream>
using namespace std;

const int size = 8;

void p(char[][size], bool[], int, int, int, int);
void P(char[][size], bool[], int, int, int, int);
void n(char[][size], bool[], int, int, int, int);
void N(char[][size], bool[], int, int, int, int);
void b(char[][size], bool[], int, int, int, int);
void B(char[][size], bool[], int, int, int, int);
void r(char[][size], bool[], int, int, int, int);
void R(char[][size], bool[], int, int, int, int);
void q(char[][size], bool[], int, int, int, int);
void Q(char[][size], bool[], int, int, int, int);
void k(char[][size], bool[], int, int, int, int);
void K(char[][size], bool[], int, int, int, int);
void printResults(bool[], bool[], int);
void readBoard(char[][size]);
int checkNotEmpty(char[][size]);
void canPieceCheck(char[][size], bool[], bool[], int);
void initializeCheckArrays(bool[], bool[]);


int main(){
	char board[size][size];
	int notEmpty = 1, round = -1;
	bool checkW[1000], checkB[1000];
	initializeCheckArrays(checkB, checkW);
	while (notEmpty == 1){
		round++;
		readBoard(board);
		notEmpty = checkNotEmpty(board);
		if (notEmpty == 1){
			canPieceCheck(board, checkW, checkB, round);
		}//if notEmpty = 1
	}//while !empty
	printResults(checkW, checkB, round);
	return 0;
}//main

void p(char board[][size], bool checkW[1000], int checkSize, int m, int n, int round){
	if (((m + 1) <= (size - 1)) && ((n - 1) >= 0) && (board[m + 1][n - 1] == 'K'))
		checkW[round] = true;
	else if (((m + 1) <= (size - 1)) && ((n + 1) <= (size - 1)) && (board[m + 1][n + 1] == 'K'))
		checkW[round] = true;
}
void P(char board[][size], bool checkB[1000], int checkSize, int m, int n, int round){
	if (((m - 1) >= 0) && ((n - 1) >= 0) && (board[m - 1][n - 1] == 'k'))
		checkB[round] = true;
	else if (((m - 1) >= 0) && ((n + 1) <= (size - 1)) && (board[m - 1][n + 1] == 'k'))
		checkB[round] = true;
}
void n(char board[][size], bool checkW[1000], int checkSize, int m, int n, int round){
	if (((m - 1) >= 0) && ((n - 2) >= 0) && (board[m - 1][n - 2] == 'K'))
		checkW[round] = true;
	else if (((m - 2) >= 0) && ((n - 1) >= 0) && (board[m - 2][n - 1] == 'K'))
		checkW[round] = true;
	else if (((m - 2) >= 0) && ((n + 1) <= (size - 1)) && (board[m - 2][n + 1] == 'K'))
		checkW[round] = true;
	else if (((m - 1) >= 0) && ((n + 2) <= (size - 1)) && (board[m - 1][n + 2] == 'K'))
		checkW[round] = true;
	else if (((m + 1) <= (size - 1)) && ((n - 2) >= 0) && (board[m + 1][n - 2] == 'K'))
		checkW[round] = true;
	else if (((m + 2) <= (size - 1)) && ((n - 1) >= 0) && (board[m + 2][n - 1] == 'K'))
		checkW[round] = true;
	else if (((m + 2) <= (size - 1)) && ((n + 1) <= (size - 1)) && (board[m + 2][n + 1] == 'K'))
		checkW[round] = true;
	else if (((m + 1) <= (size - 1)) && ((n + 2) <= (size - 1)) && (board[m + 1][n + 2] == 'K'))
		checkW[round] = true;
}
void N(char board[][size], bool checkB[1000], int checkSize, int m, int n, int round){
	if (((m - 1) >= 0) && ((n - 2) >= 0) && (board[m - 1][n - 2] == 'k'))
		checkB[round] = true;
	else if (((m - 2) >= 0) && ((n - 1) >= 0) && (board[m - 2][n - 1] == 'k'))
		checkB[round] = true;
	else if (((m - 2) >= 0) && ((n + 1) <= (size - 1)) && (board[m - 2][n + 1] == 'k'))
		checkB[round] = true;
	else if (((m - 1) >= 0) && ((n + 2) <= (size - 1)) && (board[m - 1][n + 2] == 'k'))
		checkB[round] = true;
	else if (((m + 1) <= (size - 1)) && ((n - 2) >= 0) && (board[m + 1][n - 2] == 'k'))
		checkB[round] = true;
	else if (((m + 2) <= (size - 1)) && ((n - 1) >= 0) && (board[m + 2][n - 1] == 'k'))
		checkB[round] = true;
	else if (((m + 2) <= (size - 1)) && ((n + 1) <= (size - 1)) && (board[m + 2][n + 1] == 'k'))
		checkB[round] = true;
	else if (((m + 1) <= (size - 1)) && ((n + 2) <= (size - 1)) && (board[m + 1][n + 2] == 'k'))
		checkB[round] = true;
}
void b(char board[][size], bool checkW[1000], int checkSize, int x, int y, int round){
	int count = 1, i = x, j = y;
	while ((x + count) <= (size - 1) && (y + count) <= (size - 1)){
		if (board[x + count][y + count] == 'K'){
			checkW[round] = true;
			x = size;
		}
		else if (board[x + count][y + count] != '.'){
			x = size;
		}
		count++;
	}//while
	x = i;
	y = j;
	count = 1;
	while ((x + count) <= (size - 1) && (y - count) >= 0){
		if (board[x + count][y - count] == 'K'){
			checkW[round] = true;
			x = size;
		}
		else if (board[x + count][y - count] != '.'){
			x = size;
		}
		count++;
	}//while
	x = i;
	y = j;
	count = 1;
	while ((x - count) >= 0 && (y + count) <= (size - 1)){
		if (board[x - count][y + count] == 'K'){
			checkW[round] = true;
			x = 0;
		}
		else if (board[x - count][y + count] != '.'){
			x = 0;
		}
		count++;
	}//while
	x = i;
	y = j;
	count = 1;
	while ((x - count) >= 0 && (y - count) >= 0){
		if (board[x - count][y - count] == 'K'){
			checkW[round] = true;
			x = 0;
		}
		else if (board[x - count][y - count] != '.'){
			x = 0;
		}
		count++;
	}//while
}
void B(char board[][size], bool checkB[1000], int checkSize, int x, int y, int round){
	int count = 1, i = x, j = y;
	while ((x + count) <= (size - 1) && (y + count) <= (size - 1)){
		if (board[x + count][y + count] == 'k'){
			checkB[round] = true;
			x = size;
		}
		else if (board[x + count][y + count] != '.'){
			x = size;
		}
		count++;
	}//while
	x = i;
	y = j;
	count = 1;
	while ((x + count) <= (size - 1) && (y - count) >= 0){
		if (board[x + count][y - count] == 'k'){
			checkB[round] = true;
			x = size;
		}
		else if (board[x + count][y - count] != '.'){
			x = size;
		}
		count++;
	}//while
	x = i;
	y = j;
	count = 1;
	while ((x - count) >= 0 && (y + count) <= (size - 1)){
		if (board[x - count][y + count] == 'k'){
			checkB[round] = true;
			x = 0;
		}
		else if (board[x - count][y + count] != '.'){
			x = 0;
		}
		count++;
	}//while
	x = i;
	y = j;
	count = 1;
	while ((x - count) >= 0 && (y - count) >= 0){
		if (board[x - count][y - count] == 'k'){
			checkB[round] = true;
			x = 0;
		}
		else if (board[x - count][y - count] != '.'){
			x = 0;
		}
		count++;
	}//while
}
void r(char board[][size], bool checkW[1000], int checkSize, int x, int y, int round){
	int count = 1, i = x, j = y;
	while ((x + count) <= (size - 1)){
		if (board[x + count][y] == 'K'){
			checkW[round] = true;
			x = size;
		}
		else if (board[x + count][y] != '.'){
			x = size;
		}
		count++;
	}//while
	x = i;
	y = j;
	count = 1;
	while ((x - count) >= 0){
		if (board[x - count][y] == 'K'){
			checkW[round] = true;
			x = -1;
		}
		else if (board[x - count][y] != '.'){
			x = -1;
		}
		count++;
	}//while
	x = i;
	y = j;
	count = 1;
	while (((y + count) <= (size - 1))){
		if (board[x][y + count] == 'K'){
			checkW[round] = true;
			y = size;
		}
		else if (board[x][y + count] != '.'){
			y = size;
		}
		count++;
	}//while
	x = i;
	y = j;
	count = 1;
	while ((y - count) >= 0){
		if (board[x][y - count] == 'K'){
			checkW[round] = true;
			y = 0;
		}
		else if (board[x][y - count] != '.'){
			y = 0;
		}
		count++;
	}//while
}
void R(char board[][size], bool checkB[1000], int checkSize, int x, int y, int round){
	int count = 1, i = x, j = y;
	while ((x + count) <= (size - 1)){
		if (board[x + count][y] == 'k'){
			checkB[round] = true;
			x = size;
		}
		else if (board[x + count][y] != '.'){
			x = size;
		}
		count++;
	}//while
	x = i;
	y = j;
	count = 1;
	while ((x - count) >= 0){
		if (board[x - count][y] == 'k'){
			checkB[round] = true;
			x = 0;
		}
		else if (board[x - count][y] != '.'){
			x = 0;
		}
		count++;
	}//while
	x = i;
	y = j;
	count = 1;
	while (((y + count) <= (size - 1))){
		if (board[x][y + count] == 'k'){
			checkB[round] = true;
			y = size;
		}
		else if (board[x][y + count] != '.'){
			y = size;
		}
		count++;
	}//while
	x = i;
	y = j;
	count = 1;
	while ((y - count) >= 0){
		if (board[x][y - count] == 'k'){
			checkB[round] = true;
			y = 0;
		}
		else if (board[x][y - count] != '.'){
			y = 0;
		}
		count++;
	}//while
}
void q(char board[][size], bool checkW[1000], int checkSize, int x, int y, int round){
	int count = 1, i = x, j = y;
	while ((x + count) <= (size - 1)){
		if (board[x + count][y] == 'K'){
			checkW[round] = true;
			x = size;
		}
		else if (board[x + count][y] != '.'){
			x = size;
		}
		count++;
	}//while
	x = i;
	y = j;
	count = 1;
	while ((x - count) >= 0){
		if (board[x - count][y] == 'K'){
			checkW[round] = true;
			x = 0;
		}
		else if (board[x - count][y] != '.'){
			x = 0;
		}
		count++;
	}//while
	x = i;
	y = j;
	count = 1;
	while (((y + count) <= (size - 1))){
		if (board[x][y + count] == 'K'){
			checkW[round] = true;
			y = size;
		}
		else if (board[x][y + count] != '.'){
			y = size;
		}
		count++;
	}//while
	x = i;
	y = j;
	count = 1;
	while ((y - count) >= 0){
		if (board[x][y - count] == 'K'){
			checkW[round] = true;
			y = 0;
		}
		else if (board[x][y - count] != '.'){
			y = 0;
		}
		count++;
	}//while
	x = i;
	y = j;
	count = 1;
	while ((x + count) <= (size - 1) && (y + count) <= (size - 1)){
		if (board[x + count][y + count] == 'K'){
			checkW[round] = true;
			x = size;
		}
		else if (board[x + count][y + count] != '.'){
			x = size;
		}
		count++;
	}//while
	x = i;
	y = j;
	count = 1;
	while ((x + count) <= (size - 1) && (y - count) >= 0){
		if (board[x + count][y - count] == 'K'){
			checkW[round] = true;
			x = size;
		}
		else if (board[x + count][y - count] != '.'){
			x = size;
		}
		count++;
	}//while
	x = i;
	y = j;
	count = 1;
	while ((x - count) >= 0 && (y + count) <= (size - 1)){
		if (board[x - count][y + count] == 'K'){
			checkW[round] = true;
			x = 0;
		}
		else if (board[x - count][y + count] != '.'){
			x = 0;
		}
		count++;
	}//while
	x = i;
	y = j;
	count = 1;
	while ((x - count) >= 0 && (y - count) >= 0){
		if (board[x - count][y - count] == 'K'){
			checkW[round] = true;
			x = 0;
		}
		else if (board[x - count][y - count] != '.'){
			x = 0;
		}
		count++;
	}//while
}
void Q(char board[][size], bool checkB[1000], int checkSize, int x, int y, int round){
	int count = 1, i = x, j = y;
	while ((x + count) <= (size - 1)){
		if (board[x + count][y] == 'k'){
			checkB[round] = true;
			x = size;
		}
		else if (board[x + count][y] != '.'){
			x = size;
		}
		count++;
	}//while
	x = i;
	y = j;
	count = 1;
	while ((x - count) >= 0){
		if (board[x - count][y] == 'k'){
			checkB[round] = true;
			x = 0;
		}
		else if (board[x - count][y] != '.'){
			x = 0;
		}
		count++;
	}//while
	x = i;
	y = j;
	count = 1;
	while (((y + count) <= (size - 1))){
		if (board[x][y + count] == 'k'){
			checkB[round] = true;
			y = size;
		}
		else if (board[x][y + count] != '.'){
			y = size;
		}
		count++;
	}//while
	x = i;
	y = j;
	count = 1;
	while ((y - count) >= 0){
		if (board[x][y - count] == 'k'){
			checkB[round] = true;
			y = 0;
		}
		else if (board[x][y - count] != '.'){
			y = 0;
		}
		count++;
	}//while
	x = i;
	y = j;
	count = 1;
	while ((x + count) <= (size - 1) && (y + count) <= (size - 1)){
		if (board[x + count][y + count] == 'k'){
			checkB[round] = true;
			x = size;
		}
		else if (board[x + count][y + count] != '.'){
			x = size;
		}
		count++;
	}//while
	x = i;
	y = j;
	count = 1;
	while ((x + count) <= (size - 1) && (y - count) >= 0){
		if (board[x + count][y - count] == 'k'){
			checkB[round] = true;
			x = size;
		}
		else if (board[x + count][y - count] != '.'){
			x = size;
		}
		count++;
	}//while
	x = i;
	y = j;
	count = 1;
	while ((x - count) >= 0 && (y + count) <= (size - 1)){
		if (board[x - count][y + count] == 'k'){
			checkB[round] = true;
			x = 0;
		}
		else if (board[x - count][y + count] != '.'){
			x = 0;
		}
		count++;
	}//while
	x = i;
	y = j;
	count = 1;
	while ((x - count) >= 0 && (y - count) >= 0){
		if (board[x - count][y - count] == 'k'){
			checkB[round] = true;
			x = 0;
		}
		else if (board[x - count][y - count] != '.'){
			x = 0;
		}
		count++;
	}//while
}
void k(char board[][size], bool checkW[1000], int checkSize, int m, int n, int round){
	if (((m - 1) >= 0) && ((n - 1) >= 0) && (board[m - 1][n - 1] == 'K'))
		checkW[round] = true;
	else if (((m - 1) >= 0) && ((n + 1) <= (size - 1)) && (board[m - 1][n + 1] == 'K'))
		checkW[round] = true;
	else if (((m + 1) <= (size - 1)) && ((n + 1) <= (size - 1)) && (board[m + 1][n + 1] == 'K'))
		checkW[round] = true;
	else if (((m + 1) <= (size - 1)) && ((n - 1) >= 0) && (board[m + 1][n - 1] == 'K'))
		checkW[round] = true;
	else if (((n - 1) >= 0) && (board[m][n - 1] == 'K'))
		checkW[round] = true;
	else if (((n + 1) <= (size - 1)) && (board[m][n + 1] == 'K'))
		checkW[round] = true;
	else if (((m + 1) <= (size - 1)) && (board[m + 1][n] == 'K'))
		checkW[round] = true;
	else if (((m - 1) >= 0) && (board[m - 1][n] == 'K'))
		checkW[round] = true;
}
void K(char board[][size], bool checkB[1000], int checkSize, int m, int n, int round){
	if (((m - 1) >= 0) && ((n - 1) >= 0) && (board[m - 1][n - 1] == 'k'))
		checkB[round] = true;
	else if (((m - 1) >= 0) && ((n + 1) <= (size - 1)) && (board[m - 1][n + 1] == 'k'))
		checkB[round] = true;
	else if (((m + 1) <= (size - 1)) && ((n + 1) <= (size - 1)) && (board[m + 1][n + 1] == 'k'))
		checkB[round] = true;
	else if (((m + 1) <= (size - 1)) && ((n - 1) >= 0) && (board[m + 1][n - 1] == 'k'))
		checkB[round] = true;
	else if (((n - 1) >= 0) && (board[m][n - 1] == 'k'))
		checkB[round] = true;
	else if (((n + 1) <= (size - 1)) && (board[m][n + 1] == 'k'))
		checkB[round] = true;
	else if (((m + 1) <= (size - 1)) && (board[m + 1][n] == 'k'))
		checkB[round] = true;
	else if (((m - 1) >= 0) && (board[m - 1][n] == 'k'))
		checkB[round] = true;
}
void printResults(bool checkW[1000], bool checkB[1000], int round){
	for (int i = 0; i < round; i++){
		if (checkW[i] == 1)
			cout << "Game #" << i + 1 << ": white king is in check." << endl;
		if (checkB[i] == 1)
			cout << "Game #" << i + 1 << ": black king is in check." << endl;
		if (checkW[i] == 0 && checkB[i] == 0)
			cout << "Game #" << i + 1 << ": no king is in check." << endl;
	}//for i
}
void readBoard(char board[][size]){
	char num;
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			cin >> num;
			board[i][j] = num;
		}//for j
	}//for i
	cout << endl;
}//readBoard
int checkNotEmpty(char board[][size]){
	int notEmpty;
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if (board[i][j] != '.')
				notEmpty = 1;
		}//for j
	}//for i

	if (notEmpty == 1)
		return 1;
	else
		return 0;
}//checkNotEmpty
void canPieceCheck(char board[][size], bool checkW[1000], bool checkB[1000], int round){
	char piece;
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			piece = board[i][j];
			switch (piece){
				case '.':
					break;
				case 'p':
					p(board, checkW, 1000, i, j, round);
					break;
				case 'P':
					P(board, checkB, 1000, i, j, round);
					break;
				case 'n':
					n(board, checkW, 1000, i, j, round);
					break;
				case 'N':
					N(board, checkB, 1000, i, j, round);
					break;
				case 'b':
					b(board, checkW, 1000, i, j, round);
					break;
				case 'B':
					B(board, checkB, 1000, i, j, round);
					break;
				case 'r':
					r(board, checkW, 1000, i, j, round);
					break;
				case 'R':
					R(board, checkB, 1000, i, j, round);
					break;
				case 'q':
					q(board, checkW, 1000, i, j, round);
					break;
				case 'Q':
					Q(board, checkB, 1000, i, j, round);
					break;
				case 'k':
					k(board, checkW, 1000, i, j, round);
					break;
				case 'K':
					K(board, checkB, 1000, i, j, round);
					break;
				default:
					break;
			}//switch board[i][j]
		}//for j
	}//for i
}//canPieceCheck
void initializeCheckArrays(bool checkW[1000], bool checkB[1000]){
	for (int i = 0; i < 1000; i++){
		checkW[i] = false;
		checkB[i] = false;
	}//for i
}//initializeCheckArrays
