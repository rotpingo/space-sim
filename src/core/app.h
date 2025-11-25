#pragma once

#include "raylib.h"
#include "sim.h"

#include <stdbool.h>

typedef struct {
    sim_t *sim;
    Camera2D camera;
} App;

App *App_Create(void);
bool App_ShouldClose(App *app);
void App_Run(App *app);
void App_Destroy(App *app);
