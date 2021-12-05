#pragma once

#include <ge211.hxx>
#include "game_config.hxx"
#include "column.hxx"
#include "bird.hxx"


struct Model
{
    //constructor
    explicit Model(Game_config const& config = Game_config());
    int col_reset_x_by(int last, int pen_ult);
    Bird bird;
    std::vector<Column> cols;
    Game_config const config;
    size_t score;
    size_t best_score;
    //last & penult keep track of the last two columns that the bird has passed
    int lives, last, penult;

    //functions
    void on_frame(double dt);
    void jump();
    void launch();
};
