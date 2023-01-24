#include "model.hxx"
//#include <iostream>
//#include <vector>
//#include "controller.hxx"
//using namespace std;
using namespace ge211;

Model::Model() {
    board_ =
        {{' ', ' ', ' ', ' ', ' ', '5', ' ', ' ', '9'},
        {'6', '9', ' ', ' ', ' ', ' ', '2', ' ', '8'},
        {'3', ' ', '1', ' ', '2', ' ', '4', ' ', ' '},
        {'7', '8', '3', '9', '6', ' ', ' ', '4', '2'},
        {' ', ' ', ' ', ' ', ' ', '8', ' ', '6', '3'},
        {'9', '4', ' ', '2', '5', '3', ' ', '1', '7'},
        {' ', '1', ' ', ' ', ' ', ' ', '3', ' ', ' '},
        {' ', ' ', ' ', '1', '9', ' ', ' ', ' ', '4'},
        {'8', ' ', '9', '5', ' ', '4', ' ', ' ', ' '}};

    board_sol =
        {{'2','7','8','6','4','5','1','3','9'},
         {'6','9','4','3','1','7','2','5','8'},
         {'3','5','1','8','2','9','4','7','6'},
         {'7','8','3','9','6','1','5','4','2'},
         {'1','2','5','4','7','8','9','6','3'},
         {'9','4','6','2','5','3','8','1','7'},
         {'4','1','2','7','8','6','3','9','5'},
         {'5','3','7','1','9','2','6','8','4'},
         {'8','6','9','5','3','4','7','2','1'}
        };

    board_state_ =
    {{false, false, false, false, false, false, false, false, false},
     {false, false, false, false, false, false, false, false, false},
     {false, false, false, false, false, false, false, false, false},
     {false, false, false, false, false, false, false, false, false},
     {false, false, false, false, false, false, false, false, false},
     {false, false, false, false, false, false, false, false, false},
     {false, false, false, false, false, false, false, false, false},
     {false, false, false, false, false, false, false, false, false},
     {false, false, false, false, false, false, false, false, false}
    };

}

bool Model::is_empty(int r, int c) const
{
    if (r < 9 && c < 9) {
        return (board_[r][c] == ' ' || board_[r][c] == '~');
    }
    return false;
}

void Model::write(int r, int c, char key){
    if (r < 9 && c < 9 && c >= 0 && r >= 0
    && is_empty(r, c) && board_state_[r][c] == true){
        if (key == board_sol[r][c]){
            board_[r][c] = key;
        }
        else{
            board_[r][c] = '~';
        }
    }
}

void Model::activate_square(int r, int c) {
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
                board_state_[i][j] = false;
        }
    }
    if (r < 9 && c < 9){
        board_state_[r][c] = true;
    }
}

bool Model::check_win() const
{
    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            if (board_[i][j] == ' '
            && check_row(i, board_[i][j]
            && check_col(j, board_[i][j]
            && check_square(i, j, board_[i][j])))){
                return false;
            }
        }
    }
    return true;
}

bool Model::check_row(int r, char key) const
{
    for (int i = 0; i < grid_size; i++){
        if (key == board_[r][i] && board_[r][i] != ' '){
            return false;
        }
    }
    return true;
}

bool Model:: check_col(int c, char key) const
{
    for (int r = 0; r < grid_size; r++){
        if (key == board_[r][c] && board_[r][c] != ' '){
            return false;
        }
    }
    return true;
}

bool Model:: check_square(int w, int c, char key) const
{
    int row = w - w % 3;
    int column = c - c % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
                if (key == board_[row + i][column + j]) {
                    return false;
                }
        }
    }
    return true;
}
