#include "model.hxx"
#include <catch.hxx>

//Checks if game is won when all squares are filled in correctly
TEST_CASE("Check win")
{
    Model model;
    model.board_ =
                {{'2', '7', '8', '6', '4', '5', '1', '3', '9'},
                 {'6', '9', '4', '3', '1', '7', '2', '5', '8'},
                 {'3', '5', '1', '8', '2', '9', '4', '7', '6'},
                 {'7', '8', '3', '9', '6', '1', '5', '4', '2'},
                 {'1', '2', '5', '4', '7', '8', '9', '6', '3'},
                 {'9', '4', '6', '2', '5', '3', '8', '1', '7'},
                 {'4', '1', '2', '7', '8', '6', '3', '9', '5'},
                 {'5', '3', '7', '1', '9', '2', '6', '8', '4'},
                 {'8', '6', '9', '5', '3', '4', '7', '2', '1'}
                };
        CHECK(model.check_win() == true);
}

// Checks that cell cannot be modified only after it has been clicked on
TEST_CASE("Check activation")
{
    Model model;
    model.write(0, 0, 2);
    CHECK(model.board_[0][0] == ' ');
    model.activate_square(0, 0);
    model.write(0, 0, '2');
    CHECK(model.board_[0][0] == '2');
}

//Checks that if an incorrect number is inputted the board will indicate it's
// wrong
TEST_CASE("Incorrect number inserted")
{
    Model model;
    model.activate_square(0, 0);
    model.write(0, 0, '3');
    CHECK(model.board_[0][0] == '~'); // ~ indicates when square turns red
    CHECK(model.is_empty(0, 0));
}

//Checks that if you click two squares only the most recently activated
// can be edited
TEST_CASE("Two squares activated, only latest edits")
{
    Model model;
    model.activate_square(6, 2);
    model.activate_square(0, 0);
    model.write(6, 2, '2');
    model.write(0, 0, '2');
    CHECK(model.board_[0][0] == '2');
    CHECK(model.board_[6][2] == ' ');
    CHECK(model.is_empty(6, 2));
    CHECK_FALSE(model.is_empty(0, 0));
}

//Checking that you cannot change a number once the correct one is inputted
TEST_CASE("Can't change once correct")
{
    Model model;
    model.activate_square(0, 0);
    model.write(0, 0, '2');
    CHECK(model.board_[0][0] == '2');
    model.write(0, 0, '1');
    CHECK(model.board_[0][0] == '2');
}

//Checks that you can edit a square only as long as it is activated and does not
// yet have the correct solution.
TEST_CASE("Invalid then wrong then right then wrong input")
{
    Model model;
    model.write(0, 0, '2');
    CHECK(model.board_[0][0] == ' ');
    model.activate_square(0, 0);
    model.write(0, 0, '3');
    CHECK(model.board_[0][0] == '~');
    model.write(0, 0, '4');
    CHECK(model.board_[0][0] == '~');
    model.write(0, 0, '2');
    CHECK(model.board_[0][0] == '2');
    model.write(0, 0, '3');
    CHECK(model.board_[0][0] == '2');
}

//Checking if functions for checking rows, columns, and squares will
// recognize a wrong
// move
TEST_CASE("Incorrect move")
{
    Model model;
    //2 can't go in [1][4] by any metric
    CHECK(!model.check_square(1, 4, '2'));
    CHECK(!model.check_row(1, '2'));
    CHECK(!model.check_col(4, '2'));
}

//Checking if the column function will detect an input that is wrong only due
// to a column duplicate
TEST_CASE("Column check")
{
    Model model;
    //6 can't go in [0][4] only because of a column duplicate
    CHECK(model.check_square(0, 4, '6'));
    CHECK(model.check_row(0, '6'));
    CHECK_FALSE(model.check_col(4, '6'));
}

//Checking if the row function will detect an input that is wrong due
// only to a row duplicate
TEST_CASE("Row check")
{
    Model model;
    //5 can't go in [0][1] only because of a row duplicate
    CHECK(model.check_square(0, 1, '5'));
    CHECK_FALSE(model.check_row(0, '5'));
    CHECK(model.check_col(1, '5'));
}

//Checking if the square function will detect an input that is wrong only due
// to a 3x3 square duplicate
TEST_CASE("Square check")
{
    Model model;
    //1 can't go in [0][0] only because of a 3x3 square duplicate
    CHECK_FALSE(model.check_square(0, 0, '1'));
    CHECK(model.check_row(0, '1'));
    CHECK(model.check_col(0, '1'));
}


// Play through entire game and check for a win
TEST_CASE("Play through")
{
    Model model;
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (model.is_empty(i, j)){
                model.activate_square(i, j);
                model.write(i, j, model.board_sol[i][j]);
            }
        }
    }
    CHECK(model.check_win());
}