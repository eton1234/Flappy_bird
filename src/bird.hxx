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

    /// Whether the bird is moving freely (true) or dead
    bool live;

    // Number of lives remaining
    int lives;

    //for the graphics
    Position top_left() const;

    Bird next(double dt) const;

    //functions
    bool hits(Game_config const& config) const;

    //custom functions
    bool hits_col(Column col, Game_config const&) const;

};
