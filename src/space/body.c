#include "body.h"
#include "physics/physics.h"
#include <math.h>
#include <stdlib.h>

body_t *new(Vector2 pos, Vector2 vel, Vector2 acc, float mass, float radius,
            Color color, const char *name) {

    body_t *body = malloc(sizeof(*body));
    if (!body) {
        return NULL;
    }

    body->parent = NULL;
    body->pos = pos;
    body->vel = vel;
    body->acc = acc;
    body->mass = mass;
    body->radius = radius;
    body->color = color;
    body->name = name;
    body->trail_filled = 0;

    return body;
}

body_t *new_orbiting_child(body_t *parent, Vector2 perihelion, Vector2 aphelion, float mass, float radius,
                           Color color, const char *name) {

    if (!parent) {
        return NULL;
    }

    body_t *obj = malloc(sizeof(body_t));
    if (!obj) {
        return NULL;
    }

    obj->parent = parent;
    obj->perihelion = perihelion;
    obj->aphelion = aphelion;
    obj->mass = mass;
    obj->radius = radius;
    obj->color = color;
    obj->name = name;

    // distances from parent
    float dx_peri = obj->perihelion.x - parent->pos.x;
    float dy_peri = obj->perihelion.y - parent->pos.y;

    float dx_aph = obj->aphelion.x - parent->pos.x;
    float dy_aph = obj->aphelion.y - parent->pos.y;

    float r_peri = sqrtf(dx_peri * dx_peri + dy_peri * dy_peri);
    float r_aph = sqrtf(dx_aph * dx_aph + dy_aph * dy_aph);

    // compute semi-major axis
    float a = (r_peri + r_aph) / 2.0f;

    // start at perihelion
    obj->pos = perihelion;

    // fill the positions of the trail with the initial pos of the object
    for(int i = 0; i < TRAIL_LENGTH; i++){
        obj->trail[i] = obj->pos;
    }
    obj->trail_index = 0;
    obj->trail_filled = 1;

    // tangential velocity using vis-viva
    float v = sqrtf(G * parent->mass * (2.0f / r_peri - 1.0f / a));

    // compute tangential direction perpendicular to radius vector from parent
    Vector2 r_hat = {dx_peri / r_peri, dy_peri / r_peri};

    // relative velocity
    obj->vel.x = -r_hat.y * v; // clockwise
    obj->vel.y = r_hat.x * v;

    // add parent's velocity so the child follows the parent in space

    obj->vel.x += parent->vel.x;
    obj->vel.y += parent->vel.y;

    // initialize acceleration to zero
    obj->acc = (Vector2){0, 0};

    return obj;
}

// Vector2 orbit_clockwise(Vector2 r_hat, float v) {
//
//     Vector2 vel = {-r_hat.y * v, r_hat.x * v};
//     return vel;
// }
// Vector2 orbit_counter_clockwise(Vector2 r_hat, float v) {
//
//     Vector2 vel = {r_hat.y * v, -r_hat.x * v};
//     return vel;
// }

void body_destroy(body_t *body) {
    if (!body) {
        return;
    }
    free(body);
}
