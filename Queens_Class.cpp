//EJ Eppinger
//06.06.16
//Program to teach me how to use C++

using namespace std;

int main(){

  //intializes Queens class
  class Queens{

  //public methods
  public:

    int n;
    int valids = 0;


    //Constructor
    Queens(int n){
      this.n = n;
      board = bool[n][n]
      for(int col = 0; col < n; col++){
        for(int row = 0; row < n; row++){
          board[col][row] = false;
        }
      }
    }

    //N getter method
    static int getN(){ return n;}

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
}
