#include "model.hxx"
//#include "bird.hxx"
//#include "column.hxx"

Model::Model(Game_config const& config) :
    bird{config},
    config{config},
    score{0},
    best_score{0},
    last{-1},
    lives{config.lives},
    penult{-1}
{
    //initialize one col
    Column new_col = Column(config);
    cols.push_back(new_col);
}
void
Model::on_frame(double dt) {
    //vector of updated cols
    std::vector<Column> next_cols;
    for (size_t i = 0; i < cols.size(); i++) {
        next_cols.push_back(cols.at(i).next(dt));
    }
    //adds new cols if the prev has moved enough to permit another col: max =3
    if(next_cols.at(next_cols.size()-1).top_col.x <= config.scene_dims.width-config.col_spacing-config.col_spacing
                && next_cols.size() < 3) {
        Column new_col = Column(config);
        next_cols.push_back(new_col);
    }
    //resets pos of cols that go off screen
    for(size_t i = 0; i < cols.size(); i++) {
        if(next_cols[i].top_col.x < 0) {
            next_cols[i] = Column(config);
        }
    }

    //BIRD INTERACTIONS
    if (bird.live && lives > 0) {
        Bird next = bird.next(dt);

        if(next.hits(config)) {
            bird = Bird(config);
            lives -=1;
            //freeze the cols
            for (size_t i = 0; i < cols.size(); i++) {
                cols.at(i).velocity.width = 0;
            }
            return;
        }

        //HITS COLUMN
        int last_x, pen_y;
        for (size_t i = 0; i < cols.size(); i++) {
            if (next.hits_col(next_cols.at(i), config)) {
                if (lives == 1) {
                    lives = 0;
                    return;
                //place it in between last and penultimate
                } else {
                    if (last != -1) {
                        last_x = cols.at(last).bot_col.top_left().x;
                        if (penult != -1) {
                             pen_y  = cols.at(penult).bot_col.top_left().x;
                        } else {
                            pen_y = last_x;
                        }
                    } else {
                        last_x = 0;
                        pen_y = 0;
                    }
                }
                int new_y = cols.at(i).top_col_h + config.gap_size;
                Bird new_bird = Bird(config,config.scene_dims.height/2);
                lives -= 1;
                bird = new_bird;
                int shift = col_reset_x_by(last_x,pen_y);
                //freeze the cols & shift them
                for (size_t i = 0; i < cols.size(); i++) {
                    cols.at(i).velocity.width = 0;
                    cols.at(i) = Column(config, cols.at(i).bot_col.top_left()
                    .x + shift );
                }
                return;
            }
        }
        // checks if non_cleared column has moved past the bird: updates last
        // and second to last
        for (size_t i = 0; i < cols.size(); i++) {
            if (!cols[i].cleared && (next_cols[i].top_col.x+config.col_width
                    < bird.top_left().x)) {
                next_cols[i].cleared = true;
                //scoring + last column to be cleared
                penult = last;
                last = i;
                score++;
                if (score > best_score) {
                    best_score = score;
                }
            }}
        bird = next;
        cols = next_cols;
    } else if (lives == 0){
        if (score > best_score) {
            best_score = score;
        }
        score = 0;
        lives = config.lives;
        //beginning
        std::vector<Column> reset_cols;
        reset_cols.push_back(Column(config));
        cols = reset_cols;
    }
}

void Model::launch() {
    bird.live = true;
    for (size_t i = 0; i < cols.size(); i++) {
        cols.at(i).velocity.width = config.col_v;
    }
}

void Model::jump() {
    bird.velocity.height = config.jump_v;
}

int Model::col_reset_x_by(int last, int pen_ult) {
    int ball_to_last = config.scene_dims.width/2 - last;
    return  (ball_to_last + (last - pen_ult)/2) + config.bird_radius*2;
}