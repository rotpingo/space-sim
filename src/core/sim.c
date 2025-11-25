#include "sim.h"
#include "config.h"
#include "raylib.h"

void Sim_Init(Sim *sim, int max_bodies){
    sim->deltaTime = 0.016f; // ~60FPS`
    sim->body_count = 0;
    sim->isPaused = false;
    sim->max_bodies = max_bodies;
}

void Sim_Render(Sim *sim){
    DrawCircle(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 50, YELLOW);
}
