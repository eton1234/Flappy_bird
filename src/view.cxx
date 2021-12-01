#include "view.hxx"

View::View(Model const& model)
        : model_(model),
          bird_sprite(model.config.bird_radius, //Color::gren()),
{ }

void
View::draw(ge211::Sprite_set& set)
{
    // This needs to do something!
}
