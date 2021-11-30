//
// Created by sell4 on 11/28/2021.
//

#pragma once

#include <ge211.hxx>

struct Game_config
{
    // Constructs an instance with the default parameters.
    Game_config();

    // The dimensions of the whole window:
    ge211::Dims<int> scene_dims;

    // The width of the columns:
    int col_width;

    // The number of pixels of space between each column
    int col_spacing;
    float col_v;
    int col_margin;
    // The radius of the bird:
    int bird_radius;

    // The ball's initial gravity {height}:
    ge211::Dims<int> g;

    // The amount of lives a bird has
    int lives;

    //The number of columns that need to be passed for an extra life to appear
    int extra_life;

    // The initial state of the bird. This is a member function because
    // it's computed from the other properties.
    ge211::Posn<int> bird_top_left_0() const;
};
