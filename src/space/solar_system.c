#include "solar_system.h"
#include "core/sim.h"
#include "raylib.h"
#include "space/body.h"

body_t *create_sun(void) {

    double mass_solar = 1.0;
    double sun_au_radius = 0.00465247f;

    return new((Vector2){0, 0}, (Vector2){0, 0}, (Vector2){0, 0}, mass_solar,
               sun_au_radius, YELLOW, "Sun");
}

body_t *create_mercury(body_t *b) {

    Vector2 perihelion = {0.307499f, 0};
    Vector2 aphelion = {0.466697f, 0};

    double mass_solar = 1.66e-7;
    double au_radius = 1.63e-5;

    return new_orbiting_child(b, perihelion, aphelion, mass_solar, au_radius,
                        GRAY, "Mercury");
}

body_t *create_venus(body_t *b) {

    Vector2 perihelion = {0.718440f, 0};
    Vector2 aphelion = {0.728213f, 0};

    double mass_solar = 2.446e-6;
    double au_radius = 4.045e-5;

    return new_orbiting_child(b, perihelion, aphelion, mass_solar, au_radius,
                        GOLD, "Venus");
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

body_t *create_saturn(body_t *b) {

    Vector2 perihelion = {9.0412f, 0.0f};
    Vector2 aphelion = {10.1238f, 0.0f};

    double mass_solar = 2.857e-4;
    double radius_au = 3.89e-4;

    return new_orbiting_child(b, perihelion, aphelion, mass_solar, radius_au,
                              BEIGE, "Satrun");
}

body_t *create_uranus(body_t *b) {

    Vector2 perihelion = {18.2861f, 0.0f};
    Vector2 aphelion = {20.0985f, 0.0f};

    double mass_solar = 4.367e-5;
    double radius_au = 1.696e-4;

    return new_orbiting_child(b, perihelion, aphelion, mass_solar, radius_au,
                              SKYBLUE, "Uranus");
}

body_t *create_neptune(body_t *b) {

    Vector2 perihelion = {29.81f, 0.0f};
    Vector2 aphelion = {30.33f, 0.0f};

    double mass_solar = 5.15e-5;
    double radius_au = 1.646e-4;

    return new_orbiting_child(b, perihelion, aphelion, mass_solar, radius_au,
                              DARKBLUE, "Neptune");
}

body_t *create_pluto(body_t *b) {

    Vector2 perihelion = {29.658f, 0.0f};
    Vector2 aphelion = {49.305f, 0.0f};

    double mass_solar = 6.58e-9;
    double radius_au = 7.94e-6;

    return new_orbiting_child(b, perihelion, aphelion, mass_solar, radius_au,
                              LIGHTGRAY, "Pluto");
}

void create_solar_system(sim_t *sim) {
    sim->body_count = 0;
    add_body(sim, create_sun());
    add_body(sim, create_mercury(sim->bodies[0]));
    add_body(sim, create_venus(sim->bodies[0]));
    add_body(sim, create_earth(sim->bodies[0]));
    add_body(sim, create_mars(sim->bodies[0]));
    add_body(sim, create_moon(sim->bodies[3]));
    add_body(sim, create_jupiter(sim->bodies[0]));
    add_body(sim, create_saturn(sim->bodies[0]));
    add_body(sim, create_uranus(sim->bodies[0]));
    add_body(sim, create_neptune(sim->bodies[0]));
    add_body(sim, create_pluto(sim->bodies[0]));
}
