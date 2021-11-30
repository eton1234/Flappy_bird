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
    const int col_width;

    // The size of the gap between the top rectangle and bottom rectangle
    int gap_size;

    // The number of pixels of space between each column horizontally
    int col_spacing;

    // The speed columns move (this is treated as a positive value)
    int col_v;

    // The bounds a column has. How high/low the column can be placed
    int col_margin;
    // The radius of the bird:
    int bird_radius;

    // The ball's initial gravity {height}:
    int g;

    // The amount of lives a bird has
    int lives;

    //The number of columns that need to be passed for an extra life to appear
    int extra_life;

    // The initial state of the bird. This is a member function because
    // it's computed from the other properties.
    ge211::Posn<int> bird_top_left_0() const;
};
