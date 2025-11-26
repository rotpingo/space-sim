#include "core/sim.h"
#include "raylib.h"
#include "space/body.h"

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

    return new((Vector2){1.0, 0}, (Vector2){0, orbital_speed}, (Vector2){0, 0}, mass_solar,
               earth_au_radius, BLUE, "Earth");
}

void create_solar_system(sim_t *sim) {
    sim->body_count = 0;
    add_body(sim, create_sun());
    add_body(sim, create_earth());
}
