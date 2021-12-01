#include "game_config.hxx"
#include "column.hxx"
//constructor
Column::Column(Game_config const& config)
    : velocity(config.col_v)
     {
        ge211::Random_source<int> rand(config.col_margin, config.scene_dims.height-config.col_margin-config.gap_size);
        top_col_h = rand.next();
        top_col = Rect(config.scene_dims.width, 0, config.col_width, top_col_h);
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


