#include "model.hxx"
#include "bird.hxx"
#include "column.hxx"

Model::Model(Game_config const& config)

{
    Bird bird = Bird(config);
    Column col = Column(config);
}