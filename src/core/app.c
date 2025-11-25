#include "app.h"
#include "config.h"
#include "core/sim.h"
#include "utils/ui_helper.h"

#include <raylib.h>

void App_Init(App *app) {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "space simulation");
    Sim_Init(&app->sim, 2);
    SetTargetFPS(TARGET_FPS);
}

bool App_ShouldClose(App *app) {
    (void)app;
    return WindowShouldClose();
}

void App_Run(App *app) {

    double elapsedTime = 0.0;
    while (!App_ShouldClose(app)) {
        float dt = GetFrameTime();
        elapsedTime += dt;

        BeginDrawing();
        ClearBackground(BLACK);

        Sim_Render(&app->sim);
        ui_timeHelper(elapsedTime);

        EndDrawing();
    }
}

void App_Shutdown(App *app) {
    (void)app;
    CloseWindow();
}
