#include "ui_helper.h"

#include "raylib.h"

#include <strings.h>
#include <stdio.h>

void ui_timeHelper(double time, double time_scale){
    DrawRectangle(0, 0, 200, 100, WHITE);
    char buffer[64];
    snprintf(buffer, sizeof(buffer), "Frame dt: %.1f\n", time);
    DrawText(buffer, 0, 0, 22, BLACK);

    snprintf(buffer, sizeof(buffer), "Speed: x%.f\n", time_scale);
    DrawText(buffer, 0, 40, 22, BLACK);
}
