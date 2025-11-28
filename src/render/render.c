#include "render.h"
#include "raylib.h"
#include "space/body.h"
#include "space/solar_system.h"

void draw_trail(body_t *b, float AU_TO_PIXELS, Vector2 center) {

    if (b->trail_filled < 2)
        return;

    for (int i = 0; i < b->trail_filled - 1; i++) {

        int index1 = (b->trail_index + i) % TRAIL_LENGTH;
        int index2 = (b->trail_index + i + 1) % TRAIL_LENGTH;

        Vector2 p1 = b->trail[index1];
        Vector2 p2 = b->trail[index2];

        // if (p1.x == p2.x && p1.y == p2.y) {
        //     continue;
        // }

        p1.x += b->parent->pos.x;
        p1.y += b->parent->pos.y;
        p2.x += b->parent->pos.x;
        p2.y += b->parent->pos.y;

        Color c = b->color;
        c.a = 200 * (float)i / TRAIL_LENGTH;
        DrawLineV((Vector2){p1.x * AU_TO_PIXELS + center.x,
                            p1.y * AU_TO_PIXELS + center.y},
                  (Vector2){p2.x * AU_TO_PIXELS + center.x,
                            p2.y * AU_TO_PIXELS + center.y},
                  c);
    }
}

void draw_trjectory(body_t *b) {}
void draw_sim(sim_t *sim) {

    const float AU_TO_PIXELS = 10.0f;

    float render_scale = 25.0f;
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
            radius = b->radius * AU_TO_PIXELS * render_scale;
        }

        DrawCircleV(screen_pos, radius, b->color);
        draw_trail(b, AU_TO_PIXELS, center);
    }
}
