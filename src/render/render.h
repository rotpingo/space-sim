#pragma once

#include "core/sim.h"
#include "space/body.h"

void draw_sim(sim_t* sim);
void draw_trail(body_t *b, float AU_TO_PIXELS, Vector2 center);
void draw_trjectory(body_t *b);
