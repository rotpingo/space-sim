#pragma once

#include <stdbool.h>

typedef struct {
    float deltaTime; // time between frames
    int body_count; // num of bodies: planets, stars, etc.
    int max_bodies;
    bool isPaused;
} Sim;

void Sim_Init(Sim *sim, int max_bodies); // Init the state of the simulation
void Sim_Update(Sim *sim, float deltaTime); // Update the state with dt = time
void Sim_Render(Sim *sim);
void Sim_Shutdown(Sim *sim);
