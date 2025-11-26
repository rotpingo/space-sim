#pragma once

#include "core/sim.h"
#include "space/body.h"

//G in (AU^3 / solar_mass / year^2)
// #define G (39.4784176)

// #define G 6.67430e-11

//1 AU in meters
#define AU (149597870700.0)

void apply_physics(sim_t *sim, double dt);
double calc_distance(const body_t *a, const body_t *b);
