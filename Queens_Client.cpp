//EJ Eppinger
//6.6.16
//Learning C++


#include "Queens_Client.hpp"


#include <iostream>

using EJ::Queens;


//Constructor
Queens::Queens(int n)
: n(n)
, valids(0)
, boards(0)
, board(n, std::vector<bool>(n, false))
{}

  //board printer method
  void Queens::printBoard(){
    std::cout << "Boards: " << boards++ << std::endl;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j]){
          std::cout <<" Q ";
        }
        else{
          std::cout <<" _ ";
        }
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }


  //placePiece method
  void Queens::placePiece(int col, int row){
    board[col][row] = !board[col][row];
  }

  //testing diagonals in the up-right direction
  bool Queens::right(int row, int col){
    int count = 0;

    for(int i = 0; i < n; ++i){
      if( row- i < 0 || col + i > n){
        return true;
      }

      else if(board[row - i][col + i]) {
        ++count;

        if(count > 1){
          return false;
        }
      }
    }

    return true;
  }

  //testing diagonals in the up-left direction
  bool Queens::left(int row, int col){
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
  bool Queens::isValid(){
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


  int Queens::nThMin(int nth){
    if(nth % 2 == 0){ return  nth / 2; }
    return n - 1 - nth / 2;
  }

  void Queens::ranking(std::vector<std::vector<int>> &output) const {

    output.resize(n);
    for(auto& v : output){
      v.resize(n);
    }

    for (int row = 0; row < n; ++row){
      for (int col = 0; col < n; ++col){
        if (row <= col && row <= n - row && row <= n - col ){
          output[row][col] = 3 * n - 2 + 2 * row;
        }
        else if (col <= row && col <= n - row && col <= n - col) {
          output[row][col] = 3 * n - 2 + 2 * col;
        }
        else if (n - col <= row && n - col <= n - row && n - col <= col) {
          output[row][col] = 3 * n - 2 + 2 * (n - col);
        }
        else if (n - row <= row && n - row <= col && n - row <= n - col) {
          output[row][col] = 3 * n - 2 + 2 * (n - row);
        }
      }
    }
  }

  void queensRunner(int a, int n, Queens &board){
    if (a == n){
      board.printBoard();
    }
    else{
      for(int i = 0; i < n; ++i){
        board.placePiece(a, board.nThMin(i));
        if(board.isValid()){
          queensRunner(a + 1, n, board);
        }
        board.placePiece(a, board.nThMin(i));
      }
    }
  }



  int main() {


    int n = 15;
    std::vector<std::vector<int> rank(10, std::vector<int>(10, 0));

    Queens chessBoard(n);
    chessBoard.printBoard();
    chessBoard.ranking(rank);
    chessBoard.printBoard();
    queensRunner(0, n, chessBoard);
    return 0;
  }
