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

    Column next(double dt) const;

    Velocity velocity;
    Position position;
    //ge211::Random_source<int> rand_top_height;
    Rect bot_col;
    Rect top_col;
    //gap lower & upper bound (y1,y2)
};
