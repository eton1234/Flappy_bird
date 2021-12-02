#include "model.hxx"
#include "bird.hxx"
#include "column.hxx"

Model::Model(Game_config const& config) :
    config(config),
    bird(config)
{

    Column new_col = Column(config);
    cols.push_back(new_col);


    //sets the first column in the vector as the column of interest
    //cols[0].cleared = true;

}
void
Model::on_frame(double dt) {

    // Calculates the next positions of all the Columns
    std::vector<Column> next_cols;
    int special_index = 0;
    for (int i = 0; i < cols.size(); i++) {
        bool found = false;
        next_cols.push_back(cols.at(i).next(dt));

        // Finds the first column that has not been cleared by the bird
        if(not found) {
            if(not cols.at(i).cleared) {
                found = true;
                special_index = i;
            }
        }
    }
    // Checks to see if the last Column in the vector is far enough away from the right border to add a new one
    if(next_cols.at(next_cols.size()-1).top_col.x <= config.scene_dims.width-config.col_spacing-config.col_spacing) {
        Column new_col = Column(config);
        cols.push_back(new_col);
    }

    // Checks to see if the first Column in the list needs to be removed
    if(next_cols.at(0).top_col.x < 0) {
        next_cols.erase(next_cols.begin());
    }

    if (bird.live) {

        Bird next = bird.next(dt);


        if(next.hits(config)) {
            bird.live = false;
            Bird new_bird = Bird(config);
            bird = new_bird;
            bird.lives --;
            return;

        } if (next.hits_col(next_cols.at(special_index), config)) {
            bird.live = false;
            bird.g = 0;
            for (int i = 0; i < cols.size(); i++) {
                cols.at(i).velocity = 0;
            }
            bird.lives --;
            return;
        } if (next_cols.at(special_index).column_survived(config)) {
            next_cols.at(special_index).cleared = true;
        }

        bird = next;
        cols = next_cols;


    }
}
