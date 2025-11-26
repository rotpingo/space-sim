#include "body.h"
#include <stdlib.h>

body_t* new(Vector2 pos, Vector2 vel, Vector2 acc, float mass, float radius, Color color, const char* name){

    body_t *body = malloc(sizeof(*body));
    if(!body){
        return NULL;
    }

    body->pos = pos;
    body->vel = vel;
    body->acc = acc;
    body->mass = mass;
    body->radius = radius;
    body->color = color;
    body->name = name;

    return body;
}

void body_destroy(body_t *body){
    if(!body){
        return;
    }
    free(body);
}
