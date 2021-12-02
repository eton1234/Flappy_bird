
#include "controller.hxx"
#include "model.hxx"
Controller::Controller(Model& model)
        :model_(model),
         config(Game_config()),
         view_(model)
{}
void
Controller::on_key(ge211::Key key)
{
    if (key == ge211::Key::code(' ')) {
        //model_.jump();
    } else if (key == ge211::Key::code('q')) {
        //model.launch();
    }
}
void
Controller::on_frame(double dt)
{
    model_.on_frame(dt);
}
ge211::Dims<int>
Controller::initial_window_dimensions() const
{
    return view_.initial_window_dimensions();
}
void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
}

