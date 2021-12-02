#include "view.hxx"
#include "game_config.hxx"
#include <ge211.hxx>

static ge211::Color const bird_color {255, 127, 127};

View::View(Model const& model)
        : model_(model),
          bird_sprite(model.config.bird_radius, bird_color)
{ }

void
View::draw(ge211::Sprite_set& set)
{
    for (Column col : model_.cols) {
        set.add_sprite();
    }
    sprites.add_sprite(paddle_sprite,model.paddle.top_left());
    sprites.add_sprite(ball_sprite,(ge211::Posn<int>) model.ball.top_left() );
}
