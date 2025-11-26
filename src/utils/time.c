#include "time.h"
#include "raylib.h"

void speed_time(sim_t *sim) {

    if (IsKeyDown(KEY_RIGHT)) {
        sim->time_scale += 10;
    }
    if (IsKeyDown(KEY_LEFT)) {
        sim->time_scale -= 10;
    }
    if (IsKeyPressed(KEY_UP)) {
        sim->time_scale += 1;
    }
    if (IsKeyPressed(KEY_DOWN)) {
        sim->time_scale -= 1;
    }

    if (sim->time_scale <= 0.0001) {
        sim->time_scale = 0;
    }
}
