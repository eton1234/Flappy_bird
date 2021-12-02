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
    expected.y += .5 * m.bird.velocity.height;

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
    expected.y += .5 * m.bird.velocity.height;

    int expected_col = config.scene_dims.width;
    expected_col -= .5 * m.config.col_v;

    CHECK(m.cols.at(0).top_col.x == expected_col);

    //1024, 768
    //512, 384


}
TEST_CASE("testing columns position") {
    Model m = Model(config);
    Column col = Column(config);

    float expected_col = config.scene_dims.width;
    m.cols.clear();
    m.cols.push_back(col);
    expected_col = config.scene_dims.width;
    m.bird.velocity.height = 0;
    m.bird.g = 0;
    m.bird.live = true;
    m.on_frame(25);


    expected_col -= 25 * m.config.col_v;



    CHECK(m.cols.at(0).top_col.x == expected_col);
    CHECK(not m.cols.at(0).cleared);

    m.on_frame(3);
    CHECK(m.cols.at(0).cleared);
}

TEST_CASE("testing columns generation") {
    Model m = Model(config);
    m.bird.live = true;
    m.on_frame(3);

    printf("here we go again: %f\n", m.cols.at(0).top_col.x);
    CHECK(m.cols.size() == 2);

    m.on_frame(3);
    CHECK(m.cols.size() == 3);

    printf("Col 1: %f\n", m.cols.at(0).top_col.x);
    printf("Col 2: %f\n", m.cols.at(1).top_col.x);
    printf("Col 3: %f\n", m.cols.at(2).top_col.x);
    m.on_frame(3);


    for (size_t i = 0; i < m.config.col_nums; i++) {
        m.on_frame(3);
        printf("Column size: %d\n", m.cols.size());
    }

    CHECK(m.cols.size() == m.config.col_nums);

}