#pragma once

#include "game_config.hxx"
#include <ge211.hxx>
#include "column.hxx"

using Position = ge211::Posn<float>;
using Velocity = ge211::Dims<float>;

struct Bird {
    //constructors
    Bird(Game_config const&);
    Bird(Game_config const&, int custom_y);

    //variables
    int radius;
    Position center;
    Velocity velocity;
    float g;  //gravity
    bool live; //moving or stationary

    //functions

    //gets the top left position of the bird:: for graphics, which req top lefts
    Position top_left() const;

    //next position of the bird sprite
    Bird next(double dt) const;

    //hits top or bottom of the screen
    bool hits(Game_config const& config) const;
    //hits the col
    bool hits_col(Column col, Game_config const&) const;
};
