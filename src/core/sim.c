#include "sim.h"
#include "config.h"
#include "raylib.h"
#include <stdlib.h>

Sim *Sim_Create(void){
    Sim *sim = calloc(1, sizeof(Sim));
    if(!sim){
        return NULL;
    }

    sim->simTime = 0.0;
    sim->isPaused = false;
    sim->max_bodies = 100;
    sim->body_count = 0;

    return sim;
}

void Sim_Render(Sim *sim){
    DrawCircle(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 50, YELLOW);
}

void Sim_Destroy(Sim *sim){

    if(!sim){
        return;
    }

    free(sim);
}
