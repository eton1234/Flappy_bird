#include "view.hxx"
#include "game_config.hxx"
#include <ge211.hxx>

static ge211::Color const bird_color {255, 127, 127};
static ge211::Color const col_color {100, 100, 100};
View::View(Model const& model)
        : model_(model),
          bird_sprite(model.config.bird_radius, bird_color)
          /* ,
           * col_rect(ge211::Rectangle_sprite(col.top_col.dimensions(),
           * col_color)
           */
{ }

void
View::draw(ge211::Sprite_set& set)
{
    for (Column col : model_.cols) {
        //top rect
        set.add_sprite(ge211::Rectangle_sprite(col.top_col.dimensions(),col_color),
                       col.top_col.top_left());
        //bottom rect
        set.add_sprite(ge211::Rectangle_sprite(col.bot_col.dimensions(),col_color),
                       col.bot_col.top_left());
    }
    set.add_sprite(bird_sprite,(ge211::Posn<int>) model_.bird.top_left() );
}

ge211::Dims<int>
View::initial_window_dimensions() const
{
    return model_.config.scene_dims;
}