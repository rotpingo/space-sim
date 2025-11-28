#include "core/sim.h"
#include "physics/physics.h"
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

    Vector2 perihelion = {1.38f, 0};
    Vector2 aphelion = {1.67f, 0};
    double orbital_speed = 24.07f;

    double mass_solar = 3.23e-7;
    double mars_au_radius = 3.3895e-5f;
    double distance_au = 1.5237;

    return new_orbiting(perihelion, aphelion, mass_solar, mars_au_radius,
                        MAROON, "Mars");
}

body_t *create_moon(body_t *b) {

    double distance_from_earth_au = 0.00256956;
    double moon_orbital_period_years = 27.3217 / 365.25;

    double moon_speed_relative = sqrt(G * b->mass / distance_from_earth_au);

    Vector2 moon_pos = {b->pos.x + distance_from_earth_au, b->pos.y};

    // Vector from planet to moon
    double dx = moon_pos.x - b->pos.x;
    double dy = moon_pos.y - b->pos.y;
    double r = sqrt(dx * dx + dy + dy);

    // Tangential velocity (perpendicular to radius, counter clock-wise)
    Vector2 tangential = {-dy / r * moon_speed_relative,
                          dx / r * moon_speed_relative};

    // Moon Velocity = planet velocity + tangential velocity
    Vector2 moon_vel = {b->vel.x + tangential.x, b->vel.y + tangential.y};

    double mass_solar = 3.69e-8;
    double moon_au_radius = 1.162e-5f;

    return new(moon_pos, moon_vel, (Vector2){0, 0}, mass_solar, moon_au_radius,
               LIGHTGRAY, "Moon");
}

body_t *create_jupiter(void) {

    Vector2 perihelion = {4.95f, 0.0f};
    Vector2 aphelion = {5.46f, 0.0f};
    double orbital_speed = 13.06f;

    double distance_au = 5.2;
    double mass_solar = 9.55e-4;
    double radius_au = 4.67e-4;

    // return new((Vector2){distance_au, 0},(Vector2){0, orbital_speed},
    // (Vector2){0,0}, mass_solar, radius_au, ORANGE, "Jupiter");
    return new_orbiting(perihelion, aphelion, mass_solar, radius_au, ORANGE,
                        "Jupiter");
}

void create_solar_system(sim_t *sim) {
    sim->body_count = 0;
    add_body(sim, create_sun());
    add_body(sim, create_earth());
    add_body(sim, create_mars());
    add_body(sim, create_moon(sim->bodies[1]));
    add_body(sim, create_jupiter());
}
