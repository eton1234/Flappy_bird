#pragma once

#include <ge211.hxx>
#include "game_config.hxx"
#include "column.hxx"
#include "bird.hxx"


struct Model
{


    explicit Model(Game_config const& config = Game_config());
    //TODO Functions
    //void restart();
    //void launch();
    void on_frame(double dt);
    void jump();
    //TODO variables
    Bird bird;
    //Col col;
    std::vector<Column> cols;
    Game_config const config;


};
