#pragma once

#include "model.hxx"
#include <ge211.hxx>

class View
{
public:
    explicit View(Model const& model);

    void draw(ge211::Sprite_set& set);
    ge211::Dims<int> initial_window_dimensions() const;
private:
    Model const& model_;
    ge211::Circle_sprite const bird_sprite;
    //ge211::Rectangle_sprite const col_sprite;
};
