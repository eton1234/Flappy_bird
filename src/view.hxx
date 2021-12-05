#pragma once

#include "model.hxx"
#include <ge211.hxx>

class View
{
public:
    explicit View(Model const&);
    void draw(ge211::Sprite_set& set);
    ge211::Dims<int> initial_window_dimensions() const;
private:
    //so text can be displayed
    ge211::Font sans28{"sans.ttf", 28};
    Model const& model_;
    ge211::Text_sprite info;
    ge211::Circle_sprite const bird_sprite;
    //cannot make an infinite amount of sprites as the game goes on, so recycle
    //split into top and bottom column sprites
    ge211::Rectangle_sprite top_1;
    ge211::Rectangle_sprite bot_1;
    ge211::Rectangle_sprite top_2;
    ge211::Rectangle_sprite bot_2;
    ge211::Rectangle_sprite top_3;
    ge211::Rectangle_sprite bot_3;
    std::vector<ge211::Rectangle_sprite> top_sprites;
    std::vector<ge211::Rectangle_sprite> bot_sprites;
};
