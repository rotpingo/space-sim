#pragma once

#include <stdbool.h>
#include <sys/types.h>

typedef struct {
    double simTime; // simulation time
    int body_count; // num of bodies: planets, stars, etc.
    int max_bodies;
    bool isPaused;
} Sim;

Sim *Sim_Create(void);
void Sim_Update(Sim *sim, float deltaTime); // Update the state with dt = time
void Sim_Render(Sim *sim);
void Sim_Destroy(Sim *sim);
