#include "splashkit.h"
#include "player.h"
#include "planet.h"
#include "terminal_user_input.h"
#include "lost_in_space.h"

/**
 * Load the game images, sounds, etc.
 */
void load_resources()
{
    load_resource_bundle("game_bundle", "lost_in_space.txt");
}
int main()
{
    open_window("Lost In Space", 800, 600);
    load_resources();

    game_data game;
    game = new_game();

    while ( not quit_requested() )
    {
        // Handle input to adjust player movement
        process_events();
        handle_input(game.player);

        // Perform movement and update the camera
        update_game(game);
        
        // Redraw everything
        draw_game(game);
    }

    return 0;
}