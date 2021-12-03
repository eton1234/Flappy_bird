#include "model.hxx"
#include "bird.hxx"
#include "column.hxx"

Model::Model(Game_config const& config) :
    bird{config},
    config{config}
{
    //one new column added to cols vec
    Column new_col = Column(config);
    cols.push_back(new_col);


    //sets the first column in the vector as the column of interest
    //cols[0].cleared = true;

}
void
Model::on_frame(double dt) {

    // Calculates the next positions of all the Columns & stores them in next cols vec
    std::vector<Column> next_cols;
    int special_index = 0;
    bool found = false;
    for (size_t i = 0; i < cols.size(); i++) {

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

    //TODO theoretically you can be pushing more than desired aount of columns
    if(next_cols.at(next_cols.size()-1).top_col.x <= config.scene_dims.width-config.col_spacing-config.col_spacing) {
        Column new_col = Column(config);
        next_cols.push_back(new_col);
    }

    // Checks to see if the first Column in the list needs to be removed
    if(next_cols.at(0).top_col.x < 0) {
        next_cols.erase(next_cols.begin());
    }

    if (bird.live) {

        Bird next = bird.next(dt);


        if(next.hits(config)) {
            Bird new_bird = Bird(config);
            new_bird.lives = bird.lives --;
            bird = new_bird;
            for (size_t i = 0; i < cols.size(); i++) {
                cols.at(i).velocity.width = 0;
            }
            return;
        } if (next.hits_col(next_cols.at(special_index), config)) {
            Bird new_bird = Bird(config);
            new_bird.lives = bird.lives --;
            bird = new_bird;
            for (size_t i = 0; i < cols.size(); i++) {
                cols.at(i).velocity.width = 0;
            }
            return;
        // checks if column has moved past the bird.
        }
        if (bird.live and (next_cols.at(special_index).top_col.x+config.col_width < bird.top_left().x)) {
            next_cols.at(special_index).cleared = true;
        }
        bird = next;
        cols = next_cols;
    } else {
    }
}

void Model::jump() {
    bird.velocity.height = config.jump_v;
}

