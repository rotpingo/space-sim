#include "core/sim.h"
#include "raylib.h"
#include "space/body.h"
#include <math.h>

body_t *create_sun(void) {

    double mass_solar = 1.0;
    double sun_au_radius = 0.00465247f;

    return new((Vector2){0, 0}, (Vector2){0, 0}, (Vector2){0, 0}, mass_solar,
               sun_au_radius, YELLOW, "Sun");
}

body_t *create_earth(void) {

    // Earth mass = 1 / 332846 solar masses
    double mass_solar = 3.003e-6;
    double earth_au_radius = 4.2635e-5f;
    double orbital_speed = 2.0 * PI;

    return new((Vector2){1.0, 0}, (Vector2){0, orbital_speed}, (Vector2){0, 0},
               mass_solar, earth_au_radius, BLUE, "Earth");
}

body_t *create_mars(void) {

    double mass_solar = 3.23e-7;
    double mars_au_radius = 3.3895e-5f;
    double distance_au = 1.5237;
    double orbital_speed = 2.0 * PI / sqrt(distance_au);

    return new((Vector2){distance_au, 0}, (Vector2){0, orbital_speed},
               (Vector2){0, 0}, mass_solar, mars_au_radius, MAROON, "Mars");
}

body_t *create_moon(void) {

    double distance_from_earth_au = 0.00256956;

    double moon_orbital_period_years = 27.3217 / 365.25;
    double moon_speed_au_per_year = 2.0 * PI / moon_orbital_period_years;

    double mass_solar = 3.69e-8;
    double moon_au_radius = 1.162e-5f;

    Vector2 moon_pos = {1.0 + distance_from_earth_au, 0.0};

    Vector2 moon_vel = {0.0, 2.0 * PI + moon_speed_au_per_year};

    return new(moon_pos, moon_vel, (Vector2){0, 0}, mass_solar, moon_au_radius,
               LIGHTGRAY, "Moon");
}

void create_solar_system(sim_t *sim) {
    sim->body_count = 0;
    add_body(sim, create_sun());
    add_body(sim, create_earth());
    add_body(sim, create_mars());
    add_body(sim, create_moon());
}
