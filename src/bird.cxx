//
// Created by sell4 on 11/28/2021.
//
#include "bird.hxx"
//constructor
Bird::Bird(Game_config const& config)
        : radius(config.ball_radius),
          center(above_block(paddle, config)),
          velocity(Velocity(config.ball_velocity_0)),
          live(false)
{ }

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
Bird::hits_top(Game_config const&) const
{
    return (center.y - radius < 0);
}
//hits bottom when > than screen_dim.height
bool
Bird::hits_bottom(Game_config const& config) const
{
    return (config.scene_dims.height < center.y + radius);
}


//TODO
bool
bool hits_col(Game_config const&) const {

}