#include "space/solar_system.h"
#include "render.h"
#include "raylib.h"

void draw_sim(sim_t* sim){

    for(int i = 0; i<sim->body_count; i++){
        DrawCircleV(sim->bodies[i]->position, sim->bodies[i]->radius, sim->bodies[i]->color);
    }
}
