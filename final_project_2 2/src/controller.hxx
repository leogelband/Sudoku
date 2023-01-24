#pragma once

#include "model.hxx"
#include "view.hxx"
#include <ge211.hxx>

class Controller : public ge211::Abstract_game
{
public:
    Controller();
    int position_x;
    int position_y;
    char key_typed;

protected:
    void draw(ge211::Sprite_set& set) override;
    View::Dimensions initial_window_dimensions() const override;

    void on_mouse_up(ge211::Mouse_button, ge211::Posn<int>) override;

    void on_key_down(ge211::Key) override;

private:
    Model model_;
    View view_;
    //ge211::Posn<int> pointer_;

};
