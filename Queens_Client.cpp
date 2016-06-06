//EJ Eppinger
//6.6.16
//Learning C++

using namespace std;

int** rank;
int n = 10;

class Queens {

  //public methods
public:
  int n;
  int valids;
  bool** board;

  //Constructor
  Queens(int n)
  : n(n)
  , valids(0)
  {
    board = new bool*[n];
    for (int i = 0; i < n; ++i) {
      board[i] = new bool[n];
    }

    for(int col = 0; col < n; ++col){
      for(int row = 0; row < n; ++row){
        board[col][row] = false;
      }
    }
  }

  //N getter method
  int getN(){ return n;}

  //unfinished board printer method
  /*void printBoard(){
  cout << "Board: " << isValid() << endl;

  for(int col = 0; col < n; ++col){
  for(int row = 0; row < n; ++row){
  if(board[row][col])

}
}
}
*/


//placePiece method
void placePiece(int col, int row){
  board[col][row] = !board[col][row];
}

//testing diagonals in the up-right direction
bool right(int row, int col){
  int count = 0;

  for(int i = 0; i < n; ++i){
    if( row- i < 0 || col + i > n + 1){
      return true;
    }

    else if(board[row - 1][col + 1]) {
      ++count;

      if(count > 1){
        return false;
      }
    }
  }

  return true;
}

//testing diagonals in the up-left direction
bool left(int row, int col){
  int count = 0;

  for(int i = 0; i < n; ++i){
    if (row - i < 0 || col - i < 0){
      return true;
    }

    if(board[row - i][col - i]){
      ++count;
      if(count > 1){
        return false;
      }
    }
  }
  return true;
}


//tests a board's validity
bool isValid(){
  ++valids;

  for(int row = 0; row < n; ++row){
    int count = 0;

    for (int col = 0; col < n; ++col){

      if(board[row][col]){
        ++count;
        if(count > 1){
          return false;
        }
      }
    }
  }

  for(int row = 0; row < n; ++row){
    int count = 0;

    for (int col = 0; col < n; ++col){

      if(board[col][row]){
        ++count;
        if(count > 1){
          return false;
        }
      }
    }
  }

  for(int i = 0; i < n; ++i){
    if(!(right(n - 1, i) && right(i, 0) && left(n - 1, i) && left(i, n - 1))){
      return false;
    }
  }
  return true;
}
};



int nThMinRow(int *array, int rank){
  if(rank % 2 == 0){ return rank / 2; }
  return sizeof(array) - 1 - rank / 2;
}

void queensRunner(int a, Queens board){
  if (a == n){
    board.printBoard();
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

int main() {
  Queens chessBoard = new Queens(n);
  rank = ranking(rank);
  queensRunner(0, chessBoard);
  return 0;
}
