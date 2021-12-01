//
// Created by sell4 on 11/29/2021.
//
#include "game_config.hxx"
#include "column.hxx"
//constructor
Column::Column(Game_config const& config)
    : velocity(config.col_v),
     rand_top_height(config.col_margin, config.scene_dims.height-config.col_margin-config.gap_size)
     {

        top_col = Rect(config.scene_dims.width, 0, config.col_width, rand_top_height.next());
        bot_col = Rect(config.scene_dims.width, top_col.height + config.gap_size, config.col_width,
                       config.scene_dims.height - (top_col.height + config.gap_size));
    }



    Column
    Column::next(double dt) {
        Column result (*this);
        result.top_col.x -= velocity*dt;
        result.bot_col.x -= velocity*dt;

        return result;
    }


