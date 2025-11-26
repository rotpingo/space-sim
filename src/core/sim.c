#include "sim.h"
#include <stdlib.h>

sim_t *sim_create(void) {
    sim_t *sim = calloc(1, sizeof(sim_t));
    if (!sim) {
        return NULL;
    }

    sim->sim_time = 0.0;
    sim->time_scale = 1.0;
    sim->render_scale = 250.0f;
    sim->isPaused = false;
    sim->max_bodies = 100;
    sim->body_count = 0;
    sim->bodies = calloc(sim->max_bodies, sizeof(body_t *));
    return sim;
}

void add_body(sim_t *sim, body_t *body) {

    if (sim->body_count >= sim->max_bodies) {
        if (sim->max_bodies == 0) {
            sim->max_bodies = 16;
        } else {
            sim->max_bodies *= 2;
        }
        sim->bodies = realloc(sim->bodies, sizeof(body_t *) * sim->max_bodies);
    }

    sim->bodies[sim->body_count] = body;

    sim->body_count++;
}

void sim_destroy(sim_t *sim) {

    if (!sim) {
        return;
    }

    if (sim->bodies) {
        for (int i = 0; i < sim->body_count; i++) {
            body_destroy(sim->bodies[i]);
        }
        free(sim->bodies);
        sim->bodies = NULL;
    }

    free(sim);
}
