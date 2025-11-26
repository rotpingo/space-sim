#include "render.h"
#include "raylib.h"
#include "space/solar_system.h"

void draw_sim(sim_t *sim) {

    const float AU_TO_PIXELS =  300.0f;

    Vector2 center = {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};

    for (int i = 0; i < sim->body_count; i++) {

        body_t *b = sim->bodies[i];

        // convert physics position (in AU) -> screen positions (pixels)
        Vector2 screen_pos = {b->pos.x * AU_TO_PIXELS + center.x,
                              b->pos.y * AU_TO_PIXELS + center.y};

        float radius;

        if (i == 0) {
            // radius = 38.0f * 18.0f;
            radius = b->radius * AU_TO_PIXELS * 10.0f;
        } else {
            radius = b->radius * AU_TO_PIXELS * 200.0f;
        }

        DrawCircleV(screen_pos, radius, b->color);
    }
}
