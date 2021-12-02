#pragma once


#include "view.hxx"
#include "game_config.hxx"
#include <ge211.hxx>

class Controller : public ge211::Abstract_game
{
public:
    Controller(Model&);


protected:
    void on_key(ge211::Key) override;
    void on_frame(double dt) override;
    ge211::Dims<int> initial_window_dimensions() const override;
    void draw(ge211::Sprite_set& set) override;

private:
    Model& model_;
    Game_config const config;
    View view_;
};
