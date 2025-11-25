#pragma once

#include "raylib.h"

typedef struct {
    Vector2 position;
    Vector2 velocity;
    float mass;
    float radius;
    Color color;
    const char *name;
} body_t;

body_t* new(Vector2 pos, Vector2 vel, float mass, float radius, Color color, const char* name);
void body_destroy(body_t *body);
