#include "physics.h"
#include "raylib.h"
#include "space/body.h"

#include <math.h>

void apply_physics(sim_t *sim, double frame_dt) {

    // if paused -> do nothing
    if(sim->isPaused) return;

    double dt = frame_dt * sim->time_scale;

    const double SOFTENING = 0.1e-6; // 0.1*10^-6;

    // reset all accelerations to zero
    // We accumulate new gravitational acceleration each physics step
    for (int i = 0; i < sim->body_count; i++) {
        sim->bodies[i]->acc.x = 0.0;
        sim->bodies[i]->acc.y = 0.0;
    }

    // calculate gravitational acceleration between every pair
    for (int i = 0; i < sim->body_count; i++) {
        for (int j = i + 1; j < sim->body_count; j++) {

            // Vector from body i to body j
            double dx = sim->bodies[j]->pos.x - sim->bodies[i]->pos.x;
            double dy = sim->bodies[j]->pos.y - sim->bodies[i]->pos.y;

            // Distance squared with a tiny softening to prevent division by
            // zero
            double r_square = dx * dx + dy * dy + SOFTENING;

            // inverse distance
            double inv_r = 1.0 / sqrt(r_square);

            // this is the inverse distance cubed : 1/r^3
            double inv_r_cubed = inv_r * inv_r * inv_r;

            /* Acceleration contribution on body i caused by body j
             * F = G * mass_j / r^2 -> a = F/mass_i = G * mass_j / r^2 * dx or dy
             * Direction = dx, dy
             */

            double ax_i = G * sim->bodies[j]->mass * inv_r_cubed * dx;
            double ay_i = G * sim->bodies[j]->mass * inv_r_cubed * dy;

            // Apply Newton's Third Law

            double ax_j = -G * sim->bodies[i]->mass * inv_r_cubed * dx;
            double ay_j = -G * sim->bodies[i]->mass * inv_r_cubed * dy;

            // apply results

            sim->bodies[i]->acc.x += ax_i;
            sim->bodies[i]->acc.y += ay_i;

            sim->bodies[j]->acc.x += ax_j;
            sim->bodies[j]->acc.y += ay_j;
        }
    }

    // Integrate - Update velocity and position
    // using Semi-implicit Euler (velocity first, then posiiton)
    // much more stable than basic Euler

    for (int i = 0; i <sim->body_count; i++){
        body_t *b = sim->bodies[i];

        // vel = vel + acc * dt
        b->vel.x += b->acc.x * dt;
        b->vel.y += b->acc.y * dt;

        // xPos = xPos + vel * dt
        b->pos.x += b->vel.x * dt;
        b->pos.y += b->vel.y * dt;
    }
}

