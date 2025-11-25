#pragma once

#include "sim.h"

#include <stdbool.h>

typedef struct {
    Sim sim;
} App;

void App_Init(App *app);
bool App_ShouldClose(App *app);
void App_Run(App *app);
void App_Shutdown(App *app);
