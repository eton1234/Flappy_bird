//
// Created by sell4 on 11/28/2021.
//

#include "game_config.hxx"

Game_config::Game_config()
        : scene_dims {600, 768},
          col_width {50},
          gap_size{100 },
          col_spacing {scene_dims.width/3},
          col_v {60},
          col_margin {scene_dims.height/30},
          bird_radius {10},
          jump_v {-300},
          col_nums {int(ceil(scene_dims.width / (col_width + col_spacing)))},
          g {2000},
          lives {3},
          extra_life {10}
{
    printf("math stuff 1: %f\n", scene_dims.width / (col_width + col_spacing));
    printf("math stuff 2: %f\n", float(scene_dims.width) / 60);
    printf("Column nums: %d\n\n", col_nums);

}

ge211::Posn<int>
Game_config::bird_top_left_0() const
{
    ge211::Posn<int> result(scene_dims/2);
    result.x = result.x;
    result.y = result.y;
    return result;
}