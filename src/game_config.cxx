//
// Created by sell4 on 11/28/2021.
//

#include "game_config.hxx"

Game_config::Game_config()
        : scene_dims {1024, 768},
          col_width {20},
          gap_size{40},
          col_spacing {20},
          col_v {20},
          col_margin {scene_dims.height/6},
          bird_radius {10},
          col_nums {int(ceil(scene_dims.width / (col_width + col_spacing)))},
          g {-9},
          lives {3},
          extra_life {10}
{ }

ge211::Posn<int>
Game_config::bird_top_left_0() const
{
    ge211::Posn<int> result(scene_dims/2);
    result.x = result.x;
    result.y = result.y;
    return result;
}