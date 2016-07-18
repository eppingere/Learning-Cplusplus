
#include <vector>



namespace EJ {

  class Queens{

  public:
    const int n;


    //Constructor
    Queens(int n);

    //unfinished board printer method
    void printBoard();

    //placePiece method
    void placePiece(int col, int row);
    //testing diagonals in the up-right direction
    bool right(int row, int col);

    //testing diagonals in the up-left direction
    bool left(int row, int col);

    //tests a board's validity
    bool isValid();

    int nThMin(int nth);

    void ranking(std::vector<std::vector<int>> &output) const;

  private:
    int valids;
    std::vector<std::vector<bool>> board;
    int boards;


  };


}
