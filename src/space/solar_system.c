#include "config.h"
#include "core/sim.h"
#include "space/body.h"
#include "raylib.h"

body_t *create_sun(void) {

    return new(
        (Vector2){WINDOW_WIDTH / 2 , WINDOW_HEIGHT / 2}, 
        (Vector2){0, 0}, 
        500, 
        50, 
        YELLOW, 
        "Sun"
    );
}

body_t *create_earth(void) {

    return new(
        (Vector2){400, 400}, 
        (Vector2){0, 0}, 
        50, 
        10, 
        BLUE, 
        "Earth"
    );
}

void create_solar_system(sim_t *sim){
    sim->body_count = 0;
    add_body(sim, create_sun());
    add_body(sim, create_earth());
}
