//
// Created by sell4 on 11/28/2021.
//

#include "game_config.hxx"

Game_config::Game_config()
        : scene_dims {1024, 768},
          col_width {20},
          col_margin {screen_dims.height/6},
          col_spacing {20},
          col_v {20},
          bird_radius {10},
          g {0, -9.8},
          lives {3},
          extra_life {10}
{ }

ge211::Posn<int>
Game_config::bird_top_left_0() const
{
    ge211::Posn<int> result(scene_dims);
    result.x /= 2;
    result.y /= 2;
    return result
}