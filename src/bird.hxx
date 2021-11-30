//
// Created by sell4 on 11/28/2021.
//
#pragma once

#include "game_config.hxx"
#include <ge211.hxx>
#include "column.hxx"

using Position = ge211::Posn<float>;

using Velocity = ge211::Dims<float>;

struct Bird {
    Bird(Game_config const&);
    int radius;
    Position center;
    Velocity velocity;
    int g;

    /// Whether the ball is moving freely (true) or stuck to the top of
    /// the paddle (false).
    bool live;
    //for the graphics
    Position top_left() const;

    Bird next(double dt) const;

    //functions
    bool hits_top(Game_config const&) const;
    bool hits_bottom(Game_config const&) const;
    //custom functions
    bool hits_col(Column col, Game_config const&) const;

};
