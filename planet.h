#ifndef LOST_IN_SPACE_PLANET
#define LOST_IN_SPACE_PLANET

#include "splashkit.h"
#include <vector>

using namespace std;

#define PLANET_SPEED 0.1
#define PLANET_ROTATE_SPEED 0.1

enum planet_kind
{
   EARTH,
   JUPITER,
   MARS,
   MERCURY,
   NEPTUNE,
   PLUTO,
   SATURN,
   URANUS,
   VENUS
};
struct planet_data
{
    sprite      planet_sprite;
    int         score;
    planet_kind planet;
    bool        tracker;
    //  sprite planet_to_update;
    //  sprite planet_to_draw;
};
bitmap planet_bitmap(planet_kind planet);
planet_data new_planet(double x, double y);

void draw_planet(const planet_data &planet);

void update_planet(planet_data &planet);

#endif