//EJ Eppinger
//6.6.16
//Learning C++

using namespace std;

int** rank;
int n = 10;
int int main() {


  Queens chessBoard = new Queens(n);


  rank = ranking(rank);


  queensRunner(0, chessBoard);

  return 0;
}


void queensRunner(int a, Queens board){
  if (a == n){
    board.printBoard();
    return true;
  }
  for(int i = 0; i < n; ++i){
    board.placePiece(i, nThMinRow(rank[a], i));
    if(board.isValid()){
      queensRunner(a + 1, board);
    }
    board.placePiece(a,nThMinRow(rank[a], i));
  }
}

**int ranking(int **input){
  int output[sizeof(input)][sizeof(input[0])];

  for (int row = 0; row < sizeof(output); ++row){
    for (int col = 0; col < sizeof(output[0]); ++col){
      if (row <= col && row <= n - row && row <= n - col ){output[row][col] = 3 * n - 2 + 2 * row;}
      else if (col <= row && col <= n - row && col <= n - col) {output[row][col] = 3 * n - 2 + 2 * col;}
      else if (n - col <= row && n - col <= n - row && n - col <= col) {output[row][col] = 3 * n - 2 + 2 * (n - col);}
      else if (n - row <= row && n - row <= col && n - row <= n - col) {output[row][col] = 3 * n - 2 + 2 * (n - row);}
    }
  }
  return output;
}

int nThMinRow(int *array, int rank){
  if(rank % 2 == 0){ return rank / 2; }
  return sizeof(array) - 1 - rank / 2;
}
