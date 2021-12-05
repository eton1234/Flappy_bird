//
// Created by sell4 on 11/29/2021.
//

#pragma once
#include <ge211.hxx>
#include "game_config.hxx"

using Position = ge211::Posn<float>;
using Velocity = ge211::Dims<float>;
using Rect = ge211::Rect<float>;
struct Column
{
    //Constructors
    Column(Game_config const&);
    Column(Game_config const& config, int x_pos);
    //variables
    Velocity velocity;
    float top_col_h; //top col height: note 0,0 is the top left of the screen
    Rect top_col;
    Rect bot_col;
    bool cleared; //if the col has made it past the ird
    //if you want to change the color of the best score column
    ge211::Color color;
    Column next(double dt);

    // Checks if a column has proceeded past a bird
    bool column_survived(Game_config const& config);
};

