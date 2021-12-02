//
// Created by sell4 on 11/29/2021.
//

#pragma once
#include <ge211.hxx>
#include "game_config.hxx"
using Position = ge211::Posn<float>;
using Velocity = ge211::Dims<float>;
using Rect = ge211::Rect<int>;
struct Column
{

    Column(Game_config const&);

    Column next(double dt);

    int velocity;
    //ge211::Random_source<int> rand_top_height;
    int top_col_h;
    Rect bot_col;
    Rect top_col;
    //gap lower & upper bound (y1,y2)

    // Tag that keeps track of if the column has made it passed the bird
    bool cleared;

    // Checks if a column has reached the right most edge of the scene
    bool the_end_is_here();

    // Checks if a column has proceeded past a bird
    bool column_survived(Game_config const& config);
};

