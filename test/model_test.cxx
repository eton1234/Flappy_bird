#include "model.hxx"
#include <catch.hxx>

Game_config const config;

TEST_CASE("example test (TODO: replace this)")
{
    CHECK(1 + 1 == 2);

    Model m = Model(config);

    //m.cols.clear();
    m.bird.velocity = {0, 2};
    m.bird.live = true;

    Position expected = m.bird.center;

    m.on_frame(.5);
    expected += .5 * m.bird.velocity;

    CHECK(m.bird.center == expected);
    CHECK(m.bird.lives == 3);
}

//
// TODO: Write preliminary model tests.
//
// These tests should demonstrate at least six of the functional
// requirements.
//

TEST_CASE("testing columns") {
    Model m = Model(config);
    m.cols.clear();
    Column col = Column(config);
    m.cols.push_back(col);
    m.bird.velocity = {0, 2};
    m.bird.live = true;

    Position expected = m.bird.center;

    m.on_frame(.5);
    expected += .5 * m.bird.velocity;

    int expected_col = config.scene_dims.width;
    expected_col -= .5 * m.config.col_v;

    CHECK(m.cols.at(0).top_col.x == expected_col);

    //1024, 768
    //512, 384

    m.cols.clear();
    m.cols.push_back(col);
    expected_col = config.scene_dims.width;
    m.bird.velocity.height = 0;
    m.bird.g = 0;
    m.on_frame(25);
    m.bird.live = true;

    expected_col -= 25 * m.config.col_v;

    CHECK(m.cols.at(0).top_col.x == expected_col);
    CHECK(not m.cols.at(0).cleared);

    m.on_frame(1);
    CHECK(m.cols.at(0).cleared);






}