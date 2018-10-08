#ifndef LOST_IN_SPACE_GAME
#define LOST_IN_SPACE_GAME

#define NUM_PLANETS 10

#define LEVEL_TIME 15000.00

#include "planet.h"
#include "player.h"

#include <vector>

using std::vector;
struct timed_message
{
    string text;
    int end_time;
};
struct game_data
{
    player_data player;
    planet_data planet;
    vector<planet_data> planets;
    timer game_timer;
    timer fuel_timer;
    bool game_over;

    vector<timed_message> messages;
};

// void load_resources();

void setup_level(game_data &game, int width, int height, int num_planets);

game_data new_game();

void draw_game(game_data game);

void update_game(game_data &game);

// void check_collision(game_data &game);


#endif