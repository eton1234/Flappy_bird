#include "model.hxx"
#include "bird.hxx"
#include "column.hxx"

Model::Model(Game_config const& config) :
    config(config),
    bird(config)
{

    Column new_col = Column(config.scene_dims.width, config);
    cols.push_back(new_col);


    //sets the first column in the vector as the column of interest
    //cols[0].cleared = true;

}
void
Model::on_frame(double dt) {

    std::vector<Column> next_cols;
    int special_index = 0;
    for (int i = 0; i < cols.size(); i++) {
        bool found = false;
        next_cols.push_back(cols[i].next(dt));

        if(not found) {
            if(not cols[i].cleared) {
                found = true;
                special_index = i;
            }
        }
    }

    if (bird.live) {

        Bird next = bird.next(dt);


        if(next.hits(config)) {
            bird.live = false;
            Bird new_bird = Bird(config);
            bird = new_bird;

        } if (next.hits_col(next_cols[special_index], config)) {
            bird.live = false;
        }
    }
}
