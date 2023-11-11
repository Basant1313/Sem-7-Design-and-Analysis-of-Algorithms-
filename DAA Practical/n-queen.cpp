#include <iostream>
#include <vector>
using namespace std;

void printSolution(vector<vector<char>> board, int dimension) {
  for (int row = 0; row < dimension; row++) {
    for (int col = 0; col < dimension; col++) {
      cout << board[row][col] << " ";
    }
    cout << endl;
  }
  cout << endl << endl;
}

bool isSafe(int row, int col, vector<vector<char>> &board, int dimension) {
  int i = row, j = col;
  // check row;
  while (j >= 0) {
    if (board[i][j] == 'Q') {

      return false;
    }
    j--;
  }

  i = row;
  j = col;

  // check upper left diagonal
  while (i >= 0 && j >= 0) {
    if (board[i][j] == 'Q') {

      return false;
    }
    i--;
    j--;
  }
  i = row;
  j = col;
  // check bottom left diagonal
  while (i < dimension && j >= 0) {
    if (board[i][j] == 'Q') {

      return false;
    }
    i++;
    j--;
  }
  return true;
}

void solve(vector<vector<char>> &board, int col, int dimension) {
  // base case
  while (col >= dimension) {
    printSolution(board, dimension);
    return;
  }

  // solve one case rest recursion will handle
  for (int row = 0; row < dimension; row++) {
    if (isSafe(row, col, board, dimension)) {
      board[row][col] = 'Q';

      solve(board, col + 1, dimension);
      // backtracking
      board[row][col] = '-';
    }
  }
}

int main() {
  int dimension;
  cout << "Enter the dimension of board : ";
  cin >> dimension;

  vector<vector<char>> board(dimension, vector<char>(dimension, '-'));
  int col = 0;

  solve(board, col, dimension);

  return 0;
}