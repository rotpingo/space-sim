#pragma once

#include "raylib.h"

typedef struct {
    Vector2 pos;
    Vector2 vel;
    Vector2 acc;
    float mass;
    float radius;
    Color color;
    const char *name;
} body_t;

body_t* new(Vector2 pos, Vector2 vel, Vector2 acc, float mass, float radius, Color color, const char* name);
void body_destroy(body_t *body);
