//
// Created by sell4 on 11/29/2021.
//
#include "game_config.hxx"
#include "column.hxx"
//constructor
Column::Column(Game_config const& config)
    : velocity(config.col_v),
     // rand_top_height(config.col_margin,
              //TODO note:column spacing is supposed to be the gap
       //               config.screen_dims.height - low_bound - col_spacing)
    {


    }

Column next(double dt) {
    position.x = velocity.x*dt;
}
