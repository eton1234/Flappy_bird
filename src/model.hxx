#pragma once

#include <ge211.hxx>
#include "game_config.hxx"



class Model
{


    explicit Model(Game_config const& config = Game_config());
    //TODO Functions
    //void restart();
    //void launch();
    void on_frame(double dt);
    //TODO variables
    //Bird bird;
    //Col col;
   // std::vector<Col> cols;
   // Game_config const config;


};
