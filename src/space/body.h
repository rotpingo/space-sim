#pragma once

#include "raylib.h"

typedef struct {
    Vector2 pos;
    Vector2 vel;
    Vector2 acc;
    Vector2 aphelion;
    Vector2 perihelion;
    float mass;
    float radius;
    Color color;
    const char *name;
} body_t;

body_t* new(Vector2 pos, Vector2 vel, Vector2 acc, float mass, float radius, Color color, const char* name);

body_t* new_orbiting(Vector2 perihelion, Vector2 aphelion, float mass, float radius, Color color, const char* name);
body_t* new_orbiting_child(body_t *parent, Vector2 perihelion, Vector2 aphelion, float mass, float radius, Color color, const char* name);

Vector2 orbit_clockwise(Vector2 r_hat, float v);
Vector2 orbit_counter_clockwise(Vector2 r_hat, float v);

void body_destroy(body_t *body);
