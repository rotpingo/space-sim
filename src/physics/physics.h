#pragma once

#include "core/sim.h"
#include "space/body.h"

#define G 6.67430e-11

void apply_physics(sim_t *sim, double dt);
double calc_distance(const body_t *a, const body_t *b);
