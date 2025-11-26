#pragma once

#include "space/body.h"

#include <stdbool.h>
#include <sys/types.h>

typedef struct {
    double sim_time; // simulation time
    int body_count; // num of bodies: planets, stars, etc.
    int max_bodies;
    double time_scale;
    bool isPaused;

    body_t **bodies;
} sim_t;

sim_t *sim_create(void);
void add_body(sim_t *sim, body_t *body); // Add a body to the simulation
void sim_update(sim_t *sim, float deltaTime); // Update the state with dt = time
void sim_render(sim_t *sim);
void sim_destroy(sim_t *sim);
