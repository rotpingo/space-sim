#include "app.h"
#include "config.h"
#include "core/sim.h"
#include "utils/ui_helper.h"

#include <raylib.h>
#include <stdlib.h>

App *App_Create(void) {

    App *app = calloc(1, sizeof(App));
    if (!app) {
        return NULL;
    }
    app->sim = Sim_Create();
    if (!app->sim) {
        free(app);
        return NULL;
    }
    app->camera = (Camera2D){.zoom = 1.0f};

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "space simulation");
    SetTargetFPS(TARGET_FPS);
    return app;
}

bool App_ShouldClose(App *app) {
    (void)app;
    return WindowShouldClose();
}

void App_Run(App *app) {

    double elapsedTime = 0.0;
    u_int16_t timeScale = 1;
    while (!App_ShouldClose(app)) {
        float dt = GetFrameTime();
        elapsedTime += dt;

        BeginDrawing();
        ClearBackground(BLACK);

        Sim_Render(app->sim);
        ui_timeHelper(elapsedTime);

        EndDrawing();
    }
}

void App_Destroy(App *app){
    if(!app){
        return;
    }

    Sim_Destroy(app->sim);
    app->sim = NULL;

    free(app);
    CloseWindow();
}
