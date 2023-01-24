#pragma once

#include "model.hxx"
#include <ge211.hxx>

#include <string>

static const int cell_size = 100;

class View
{
public:

    using Dimensions = ge211::Dims<int>;

    /// View positions will use `int` coordinates.
    using Position = ge211::Posn<int>;

    explicit View(Model const& model);

    Dimensions initial_window_dimensions() const;

    void draw(ge211::Sprite_set& set, ge211::Posn<int> position);

    //Position screen_to_board(Position screen_pos) const;
    Position board_to_screen(Position pos) const;

    int get_size() const;

    //void draw_reds(ge211::Sprite_set& set, int, int) const;


private:

    Model const& model_;
    ge211::sprites::Rectangle_sprite const white_square;
    ge211::sprites::Rectangle_sprite const red_square;
    ge211::sprites::Rectangle_sprite const yellow_square;
    ge211::sprites::Rectangle_sprite const green_square;
    ge211::sprites::Text_sprite const num1;
    ge211::sprites::Text_sprite const num2;
    ge211::sprites::Text_sprite const num3;
    ge211::sprites::Text_sprite const num4;
    ge211::sprites::Text_sprite const num5;
    ge211::sprites::Text_sprite const num6;
    ge211::sprites::Text_sprite const num7;
    ge211::sprites::Text_sprite const num8;
    ge211::sprites::Text_sprite const num9;

};

