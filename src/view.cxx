#include "view.hxx"
#include "game_config.hxx"
#include <ge211.hxx>

static ge211::Color const ball_color {255, 127, 127};

View::View(Model const& model)
        : model_(model),
          bird_sprite(model.config.bird_radius, ball_color)

{ }

void
View::draw(ge211::Sprite_set& set)
{
    // This needs to do something!
}
