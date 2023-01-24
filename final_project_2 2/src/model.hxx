#pragma once
//#include "controller.hxx"
#include <ge211.hxx>
#include <iostream>
#include <vector>
using namespace std;

class Model
{
public:
    Model();

    const int grid_size = 9;

    using Position = ge211::Posn<int>;


    bool is_empty(int i, int j) const;

    void activate_square(int r, int c);

    std::vector<vector<char>> board_sol;

    std::vector<vector<char>> board_; // 3 rows, 3 columns

    std::vector<vector<bool>> board_state_;

    bool check_win() const;

    bool check_row(int r, char key) const;

    bool check_col(int c, char key) const;

    bool check_square(int r, int c, char key) const;

    void write(int r, int c, char key);

private:
    //Controller controller_;

};
