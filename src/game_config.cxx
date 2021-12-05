#include "game_config.hxx"

Game_config::Game_config()
        : scene_dims {600, 768},
          col_width {70},
          gap_size{200 },
          col_spacing {scene_dims.width/3},
          col_v {150},
          col_margin {scene_dims.height/10},
          bird_radius {10},
          jump_v {-500},
          col_nums {int(ceil(scene_dims.width / (col_width + col_spacing)))},
          g {2000},
          lives {3},
          extra_life {10}
{}