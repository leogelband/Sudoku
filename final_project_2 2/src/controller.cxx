#include "controller.hxx"
#include <iostream>

Controller::Controller()
        : view_(model_)
{ }


void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set, {0,0});
}

void Controller::on_mouse_up(ge211::Mouse_button button, ge211::Posn<int> posn)
{
    key_typed = ' ';
    if (button == ge211::Mouse_button::left){
        if (posn.x / view_.get_size() < 9 && posn.y / view_.get_size() < 9) {
            position_y = posn.x / view_.get_size();
            position_x = posn.y / view_.get_size();
            //std::cout << model_.board_[position_x][position_y] << "\n";
            if (model_.is_empty(position_x,
                                position_y)) {
                model_.activate_square(position_x,
                                   position_y);
            }
        }
    }
}

void
Controller::on_key_down(ge211::Key key)
{
    if (key == ge211::Key::code('1')) {
        key_typed = '1';
    }
    if (key == ge211::Key::code('2')) {
        key_typed = '2';
    }
    if (key == ge211::Key::code('3')) {
        key_typed = '3';
    }
    if (key == ge211::Key::code('4')) {
        key_typed = '4';
    }
    if (key == ge211::Key::code('5')) {
        key_typed = '5';
    }
    if (key == ge211::Key::code('6')) {
        key_typed = '6';
    }
    if (key == ge211::Key::code('7')) {
        key_typed = '7';
    }
    if (key == ge211::Key::code('8')) {
        key_typed = '8';
    }
    if (key == ge211::Key::code('9')) {
        key_typed = '9';
    }

    if (key_typed == model_.board_sol[position_x][position_y] &&
        model_.check_col(position_y, key_typed) &&
        model_.check_row(position_x,key_typed) &&
        model_.check_square(position_x, position_y, key_typed)){
        if (position_x < 9 && position_x >= 0
            && position_y >= 0 && position_y < 9) {
            model_.write(position_x, position_y, key_typed);
        }
    }

    else if (key_typed != model_.board_sol[position_x][position_y] ||
    !model_.check_col(position_y, key_typed) ||
    !model_.check_row(position_x,key_typed) ||
    !model_.check_square(position_x, position_y, key_typed)) {
        if (position_x < 9 && position_x >= 0
            && position_y >= 0 && position_y < 9
            && model_.is_empty(position_x, position_y)) {
            model_.write(position_x, position_y, '~');
        }
    }
}
View::Dimensions
Controller::initial_window_dimensions() const
{
    return view_.initial_window_dimensions();
}
