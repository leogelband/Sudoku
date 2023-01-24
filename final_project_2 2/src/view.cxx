#include "view.hxx"

using Color = ge211::Color;
using Sprite_set = ge211::Sprite_set;

static int const grid_size = 60;

View::View(Model const& model)
        : model_(model),
          white_square({(int) (grid_size * .97), (int) (grid_size * .97)},
                       Color::from_rgba(100,100,100)),
          red_square({(int) (grid_size * .97), (int) (grid_size * .97)},
                     Color::medium_red()),
          yellow_square({(int) (grid_size * .97), (int) (grid_size * .97)},
                        Color::medium_yellow()),
          green_square({(int) (grid_size * .97), (int) (grid_size * .97)},
                     Color::medium_green()),
          num1("1", ge211::Font("sans.ttf", 20)),
          num2("2", ge211::Font("sans.ttf", 20)),
          num3("3", ge211::Font("sans.ttf", 20)),
          num4("4", ge211::Font("sans.ttf", 20)),
          num5("5", ge211::Font("sans.ttf", 20)),
          num6("6", ge211::Font("sans.ttf", 20)),
          num7("7", ge211::Font("sans.ttf", 20)),
          num8("8", ge211::Font("sans.ttf", 20)),
          num9("9", ge211::Font("sans.ttf", 20))
{}

void
View::draw(ge211::Sprite_set& set, Position pointer)
{

    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            Position posn = board_to_screen(Position {r, c});
            set.add_sprite(white_square, posn, 0);
        }
    }
    for (int r = 0; r < 9; r++){
        for (int c = 0; c < 9; c++){
            Position posn = board_to_screen(Position {c, r});
            if (model_.board_[r][c] != ' ' && model_.board_[r][c] != '~'){
                set.add_sprite(yellow_square, posn, 2);
            }
            if (model_.board_[r][c] == '~'){
                set.add_sprite(red_square, posn, 1);
            }
            if (model_.board_[r][c] == '1'){
                set.add_sprite(num1, {posn.x + 23, posn.y + 10}, 100);
            }
            if (model_.board_[r][c] == '2'){
                set.add_sprite(num2, {posn.x + 23, posn.y + 10}, 100);
            }
            if (model_.board_[r][c] == '3'){
                set.add_sprite(num3, {posn.x + 23, posn.y + 10}, 100);
            }
            if (model_.board_[r][c] == '4'){
                set.add_sprite(num4, {posn.x + 23, posn.y + 10}, 100);
            }
            if (model_.board_[r][c] == '5'){
                set.add_sprite(num5, {posn.x + 23, posn.y + 10}, 100);
            }
            if (model_.board_[r][c] == '6'){
                set.add_sprite(num6, {posn.x + 23, posn.y + 10}, 100);
            }
            if (model_.board_[r][c] == '7'){
                set.add_sprite(num7, {posn.x + 23, posn.y + 10}, 100);
            }
            if (model_.board_[r][c] == '8'){
                set.add_sprite(num8, {posn.x + 23, posn.y + 10}, 100);
            }
            if (model_.board_[r][c] == '9'){
                set.add_sprite(num9, {posn.x + 23, posn.y + 10}, 100);
            }
        }
    }
    if (model_.check_win()){
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                Position posn = board_to_screen(Position {r, c});
                set.add_sprite(green_square, posn, 5);
            }
        }
    }
}

int View::get_size() const{
    return grid_size;
}

View::Position
View::board_to_screen(Position pos) const
{
    return {grid_size * pos.x, grid_size * pos.y};
}

View::Dimensions
View::initial_window_dimensions() const
{
    return
    ge211::geometry::Dims<int> {grid_size * 9, grid_size * 9};
}
