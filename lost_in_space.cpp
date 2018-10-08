#include "splashkit.h"
#include "planet.h"
#include "player.h"
#include "lost_in_space.h"
#include "terminal_user_input.h"

void setup_level(game_data &game, int width, int height, int num_planets)
{
    for (int i = 0; i < game.planets.size(); i++)
    {
        free_sprite(game.planets[i].planet_sprite);
    }
    game.planets.clear();

    if ( num_planets <= 0) num_planets = 1;

    for (int i = 0; i < num_planets; i++)
    {
        game.planets.push_back(new_planet(rnd(width) - width / 2, rnd(height) - height / 2));
    }

    timed_message msg;
    msg.text = "Beginning new game...";
    msg.end_time = timer_ticks(game.game_timer) + 3000; //5 seconds until this message disappears
    game.messages.push_back(msg); //push message back onto list of messages
}
game_data new_game()
{
    game_data result;

    result.player = new_player();
    // set up game in a space that is 3000px wide and 3000 px high with 10 planets
    setup_level(result, 3000, 3000, NUM_PLANETS);

    result.game_timer = create_timer("game_timer");
    result.fuel_timer = create_timer("fuel_timer");

    reset_timer(result.game_timer);
    start_timer(result.game_timer);

    reset_timer(result.fuel_timer);
    start_timer(result.fuel_timer);

    result.game_over = false;

    return result;
}
 void draw_game(game_data game)
{

        clear_screen(COLOR_BLACK);

        for (int i = 0; i < game.planets.size(); i++)
        {
            draw_planet(game.planets[i]);
        }
        int idx;
        idx = closest_planet_index(game.player, game.planets);

        double time_pct = (LEVEL_TIME - timer_ticks(game.fuel_timer)) / LEVEL_TIME;
        if (time_pct < 0 ) time_pct = 0;

        if( idx != -1){
            draw_hud(game.player, game.planets[idx], time_pct);}
        else
        {
            draw_hud(game.player, game.planets[0], time_pct);
        }
        //as well as the player who can move
        draw_player(game.player);

        if (game.game_over)
        {
        draw_text("GAME OVER", COLOR_WHITE, 300, 300, option_to_screen());
     
        game.messages.pop_back();
        }


        for (int i=0; i < game.messages.size(); i++)
        {
            if (timer_ticks(game.game_timer) < game.messages[i].end_time)
            {
                draw_text(game.messages[i].text, COLOR_WHITE, 300, 300, option_to_screen());
            }

        }
        refresh_screen(60);

}
void check_collision(game_data &game)
{
    for(int i = 0; i < game.planets.size(); i++)
    {
        if( (not game.planets[i].tracker) && (sprite_collision(game.player.player_sprite, game.planets[i].planet_sprite)))
        {
            game.planets[i].tracker = true;
            reset_timer(game.fuel_timer);
            load_sound_effect("my man", "my_man.wav");
            play_sound_effect("my man");
        }
    }
}
void update_game(game_data &game)
{
    update_player(game.player);
    check_collision(game);

    if (timer_ticks(game.fuel_timer) > LEVEL_TIME)
    {
        game.game_over = true;
        stop_timer(game.fuel_timer);
        stop_timer(game.game_timer);
    }
    if (closest_planet_index(game.player, game.planets) == -1)
    {
        game.messages.pop_back();
        setup_level(game, 3000, 3000, game.planets.size() - 1);
    }
}