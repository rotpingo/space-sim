#include "app.h"
#include "config.h"
#include "core/sim.h"
#include "physics/physics.h"
#include "render/render.h"
#include "space/solar_system.h"
#include "utils/camera.h"
#include "utils/time.h"
#include "utils/ui_helper.h"

#include <raylib.h>

#include <stdlib.h>

App *App_Create(void) {

    App *app = calloc(1, sizeof(App));
    if (!app) {
        return NULL;
    }
    app->sim = sim_create();
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

    create_solar_system(app->sim);

    while (!App_ShouldClose(app)) {
        float dt = GetFrameTime();
        app->sim->sim_time += dt;

        // Draw
        BeginDrawing();

        ClearBackground(BLACK);
        BeginMode2D(app->camera);
        draw_sim(app->sim);
        apply_physics(app->sim, dt);
        EndMode2D();

        EndDrawing();

        ui_timeHelper(app->sim->sim_time, app->sim->time_scale);
        speed_time(app->sim);
        camera_controls(&app->camera);
    }
}

void App_Destroy(App *app) {
    if (!app) {
        return;
    }

    sim_destroy(app->sim);
    app->sim = NULL;

    free(app);
    CloseWindow();
}
