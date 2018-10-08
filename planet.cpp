#include "splashkit.h"
#include "terminal_user_input.h"
#include "planet.h"
#include "player.h"
#include "lost_in_space.h"

bitmap planet_bitmap(planet_kind planet)
{
    switch (planet)
    {
    case EARTH:
        return bitmap_named("earth");
    case JUPITER:
        return bitmap_named("jupiter");
    case MARS:
    return bitmap_named("mars");
    case MERCURY:
    return bitmap_named("mercury");
    case NEPTUNE:
    return bitmap_named("neptune");
    case PLUTO:
    return bitmap_named("pluto");
    case SATURN:
    return bitmap_named("saturn");
    case URANUS:
    return bitmap_named("uranus");
    case VENUS:
    return bitmap_named("venus");
    default:
        return bitmap_named("earth");
    }
}
planet_data new_planet(double x, double y)
{
    planet_data planet;
    
    bitmap default_bitmap = planet_bitmap(EARTH);
    planet.planet_sprite = create_sprite(planet_bitmap(static_cast<planet_kind>(rnd(9))));

    planet.tracker = false;

    sprite_set_x(planet.planet_sprite, x);
    sprite_set_y(planet.planet_sprite, y);

    sprite_set_dx(planet.planet_sprite, PLANET_SPEED);
    sprite_set_rotation(planet.planet_sprite, PLANET_ROTATE_SPEED);
    
    return planet;
}
void update_planet(planet_data &planet)
{
     update_sprite(planet.planet_sprite);
}
void draw_planet(const planet_data &planet)
{
     draw_sprite(planet.planet_sprite);

     if (planet.tracker)
     {
        circle c = sprite_circle(planet.planet_sprite);
        c.radius += 10;
        draw_circle(COLOR_BRIGHT_GREEN, c);
     }

}