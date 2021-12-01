//
// Created by sell4 on 11/28/2021.
//
#include "bird.hxx"
//constructor
Bird::Bird(Game_config const& config)
        : radius(config.bird_radius),
          center(0,0),
          g(config.g),
          live(false),
          lives(config.lives)
{
}

Position
Bird::top_left() const
{
    return {center.x - radius, center.y - radius};
}

Bird
Bird::next(double dt) const
{
    Bird result(*this);
    result.center.y += result.velocity.height*dt - g*dt*dt;
    return result;
}
bool
Bird::hits(Game_config const& config) const
{
    return ((center.y - radius < 0) or (center.y + radius > config.scene_dims.height));
}


//TODO
bool
Bird::hits_col(Column col, Game_config const& config) const {


    return true;
}
