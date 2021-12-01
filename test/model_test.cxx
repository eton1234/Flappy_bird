#include "model.hxx"
#include <catch.hxx>

Game_config const config;

TEST_CASE("example test (TODO: replace this)")
{
    CHECK(1 + 1 == 2);

    Model m = Model(config);

    m.cols.clear();
    m.bird.velocity = {0, 2};
    m.bird.live = true;

    Position expected = m.bird.center;

    m.on_frame(.5);
    expected += .5 * m.bird.velocity;

    CHECK(m.bird.center == expected);


}

//
// TODO: Write preliminary model tests.
//
// These tests should demonstrate at least six of the functional
// requirements.
//
