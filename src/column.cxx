#include "game_config.hxx"
#include "column.hxx"
//Col colors
static ge211::Color const best_color {255, 127, 127};
static ge211::Color const col_color {100, 100, 100};

//Constructor
Column::Column(Game_config const& config)
    : velocity{Velocity (config.col_v, 0)},
    color(col_color),
    cleared{false}
     {
        /*
         * Initializes a column, composed of a top and bottom rectangle
         * Initailized at x = scene_dims.width, or the right end of screen
         * Randomly generates the position of the gap between the  two rects
         * The position of gap is bounded by a column margin (like a word
           doc) */
        ge211::Random_source<int> rand(config.col_margin, config.scene_dims.height-config.col_margin-config.gap_size);
        top_col_h = rand.next();
        top_col = Rect(config.scene_dims.width, 0, config.col_width, top_col_h);
        bot_col = Rect(config.scene_dims.width, top_col.height + config.gap_size, config.col_width,
                       config.scene_dims.height - (top_col.height + config.gap_size));
     }
 //Col construtor for custom x position
Column::Column(Game_config const& config, int x_pos)
        : velocity{Velocity (config.col_v, 0)},
          color(col_color),
          cleared{false}
{
    ge211::Random_source<int> rand(config.col_margin, config.scene_dims.height-config.col_margin-config.gap_size);
    top_col_h = rand.next();
    top_col = Rect(x_pos, 0, config.col_width,
                   top_col_h);
    bot_col = Rect(x_pos, top_col.height + config
    .gap_size, config.col_width,
                   config.scene_dims.height - (top_col.height + config.gap_size));
}

//Get predicted next pos of the column
Column
Column::next(double dt) {
    Column result (*this);
    result.top_col.x = result.top_col.x - velocity.width*dt;
    result.bot_col.x -= velocity.width*dt;

    return result;
}