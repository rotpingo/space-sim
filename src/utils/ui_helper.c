#include "ui_helper.h"

#include "raylib.h"

#include <stdio.h>
#include <string.h>
#include <strings.h>

void ui_timeHelper(double time, double time_scale) {
    DrawRectangleRounded((Rectangle){5, 5, 300, 150}, 0.2f, 20,
                         Fade(RED, 0.65f));

    // current simulatiom time - converted to human-readable years
    char buffer[64];
    snprintf(buffer, sizeof(buffer), "Sim time: %.f\n", time);
    DrawText(buffer, 12, 12, 22, (time > 1e6) ? ORANGE : GREEN);

    char scale_str[64];
    Color speed_color = GREEN;
    if (time_scale > 1e6) {
        speed_color = RED;
        snprintf(scale_str, sizeof(scale_str), "Speed: x%.f", time_scale);
    } else if (time_scale >= 1000) {
        speed_color = ORANGE;
        snprintf(scale_str, sizeof(scale_str), "Speed: x%.f", time_scale);
    } else if (time_scale > 1.0) {
        speed_color = YELLOW;
        snprintf(scale_str, sizeof(scale_str), "Speed: x%.f", time_scale);
    } else if (time_scale > 0.01) {
        speed_color = SKYBLUE;
        snprintf(scale_str, sizeof(scale_str), "Speed: x%.2f", time_scale);
    } else {
        speed_color = DARKGRAY;
        strcpy(scale_str, "PAUSED");
    }

    DrawText(scale_str, 12, 42, 28, speed_color);
}
