//
// Created by sell4 on 11/28/2021.
//
#include "bird.hxx"
//constructor
Bird::Bird(Game_config const& config)
        : radius(config.bird_radius),
          center{ge211::Posn<int>{config.scene_dims.width/2, config.scene_dims.height/2}},
          velocity(0,0),
          g(config.g),
          //TODO remember to set this to false when launch function  is
          // programmed
          live(true),
          lives(config.lives)
{
    center.x = config.scene_dims.width/2;
    center.y = config.scene_dims.height/2;
}


Position
Bird::top_left() const
{
    Position result = Position(center.x - radius, center.y - radius);
    return result;
}

Bird
Bird::next(double dt) const
{
    Bird result(*this);
    /*
    result.velocity.height += g*dt;
    result.center.y += result.velocity.height*dt;
     */
    return result;
}
bool
Bird::hits(Game_config const& config) const
{
    return ((top_left().y - radius < 0) or (top_left().y + (2*radius) > config.scene_dims.height));
}



bool
Bird::hits_col(Column col, Game_config const& config) const {

    if (top_left().x < col.top_col.x + config.col_width and top_left().x + (2 * radius) > col.top_col.x) {
        if (top_left().y > col.top_col_h and (top_left().y + (2*radius)) < (col.top_col_h + config.gap_size) ) {
            return true;
        }
    }
    return false;
}
