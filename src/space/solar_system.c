#include "core/sim.h"
#include "raylib.h"
#include "space/body.h"

body_t *create_sun(void) {

    double mass_solar = 1.0;
    double sun_au_radius = 0.00465247f;

    return new((Vector2){0, 0}, (Vector2){0, 0}, (Vector2){0, 0}, mass_solar,
               sun_au_radius, YELLOW, "Sun");
}

body_t *create_earth(body_t *b) {

    Vector2 perihelion = {0.98f, 0};
    Vector2 aphelion = {1.01f, 0};

    // Earth mass = 1 / 332846 solar masses
    double mass_solar = 3.003e-6;
    double earth_au_radius = 4.2635e-5f;

    return new_orbiting_child(b, perihelion, aphelion, mass_solar, earth_au_radius, BLUE,
                        "Earth");
}

body_t *create_mars(body_t *b) {

    Vector2 perihelion = {1.38f, 0};
    Vector2 aphelion = {1.67f, 0};

    double mass_solar = 3.23e-7;
    double mars_au_radius = 3.3895e-5f;

    return new_orbiting_child(b, perihelion, aphelion, mass_solar, mars_au_radius,
                        MAROON, "Mars");
}

body_t *create_moon(body_t *b) {

    Vector2 perihelion = {b->pos.x + 0.00257f, b->pos.y};
    Vector2 aphelion = {b->pos.x + 0.00265f, b->pos.y};

    double mass_solar = 3.69e-8;
    double moon_au_radius = 1.162e-5f;

    return new_orbiting_child(b, perihelion, aphelion, mass_solar,
                              moon_au_radius, LIGHTGRAY, "Moon");
}

body_t *create_jupiter(body_t *b) {

    Vector2 perihelion = {4.95f, 0.0f};
    Vector2 aphelion = {5.46f, 0.0f};

    double mass_solar = 9.55e-4;
    double radius_au = 4.67e-4;

    return new_orbiting_child(b, perihelion, aphelion, mass_solar, radius_au,
                              ORANGE, "Jupiter");
}

void create_solar_system(sim_t *sim) {
    sim->body_count = 0;
    add_body(sim, create_sun());
    add_body(sim, create_earth(sim->bodies[0]));
    add_body(sim, create_mars(sim->bodies[0]));
    add_body(sim, create_moon(sim->bodies[1]));
    add_body(sim, create_jupiter(sim->bodies[0]));
}
