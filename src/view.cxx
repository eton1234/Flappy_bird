#include "view.hxx"
#include "game_config.hxx"
#include <ge211.hxx>

static ge211::Color const bird_color {255, 127, 127};
static ge211::Color const col_color {100, 100, 100};
View::View(Model const& model)
        : model_(model),
          bird_sprite(model.config.bird_radius, bird_color),
          top_1(ge211::Dims<int> {3,3}, col_color),
          bot_1(ge211::Dims<int> {3,3}, col_color),
          top_2(ge211::Dims<int> {3,3}, col_color),
          bot_2(ge211::Dims<int> {3,3}, col_color),
          top_3(ge211::Dims<int> {3,3}, col_color),
          bot_3(ge211::Dims<int> {3,3}, col_color),
          top_sprites{top_1,top_2,top_3},
          bot_sprites{bot_1,bot_2,bot_3}
{ }

void
View::draw(ge211::Sprite_set& set)
{
    /*
    for (Column col : model_.cols) {
        //top rect
        auto t_dims = (ge211::geometry::Dims<int>) col.top_col.dimensions();
        auto b_dims = (ge211::geometry::Dims<int>) col.bot_col.dimensions();
        set.add_sprite(ge211::Rectangle_sprite(t_dims,
                                               col_color),
                       (ge211::Posn<int>) col.top_col.top_left());
        //bottom rect

        set.add_sprite(ge211::Rectangle_sprite((ge211::geometry::Dims<int>)col.bot_col.dimensions(),col_color),
                       (ge211::Posn<int>) col.bot_col.top_left());

    } */
    //dims is supposed to be ge211::Dims<int>

    Column col = model_.cols[0];
   // Column col2 = model_.cols[1];

    //ge211::Dims<int> t_dims = col.top_col.dimensions().into<int>();
    //ge211::Dims<int> b_dims = col.top_col.dimensions().into<int>();

    ge211::Posn<int> s = col.top_col.top_left().into<int>();
    //TODO 6 col_rects for 3 different columns
    top_1 = ge211::Rectangle_sprite(col.top_col.dimensions().into<int>() ,
            col_color);
    bot_1 = ge211::Rectangle_sprite(col.bot_col.dimensions().into<int>() ,
                                    col_color);
    std::vector<Column> cols = model_.cols;
    for (size_t i = 0 ; i < 3; i++) {
        if (i < model_.cols.size() && top_sprites.size()) {
            top_sprites[i] = ge211::Rectangle_sprite(cols[i].top_col
                                                            .dimensions()
                                                            .into<int>(),
                                                     col_color);
            bot_sprites[i] = ge211::Rectangle_sprite(cols[i].bot_col.dimensions().into<int>(), col_color);
            set.add_sprite(top_sprites[i], cols[i].top_col.top_left().into<int>
                    ());
            set.add_sprite(bot_sprites[i],cols[i].bot_col.top_left().into<int>
                    ());
        }
    }
    set.add_sprite(bird_sprite,(ge211::Posn<int>) model_.bird.top_left() );
}

ge211::Dims<int>
View::initial_window_dimensions() const
{
    return model_.config.scene_dims;
}