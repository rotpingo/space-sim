#include "body.h"
#include "physics/physics.h"
#include <math.h>
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

body_t* new_orbiting(Vector2 perihelion, Vector2 aphelion, float mass, float radius, Color color, const char* name){
    body_t* obj = malloc(sizeof(body_t));
    if(!obj){
        return NULL;
    }

    obj->perihelion = perihelion;
    obj->aphelion = aphelion;
    obj->mass = mass;
    obj->radius = radius;
    obj->color = color;
    obj->name = name;

    // distances from Sun
    float r_peri = sqrtf(perihelion.x * perihelion.x + perihelion.y * perihelion.y);
    float r_aph = sqrtf(aphelion.x * aphelion.x + aphelion.y * aphelion.y);
    //
    // compute semi-major axis
    float a = (r_peri + r_aph) / 2.0f;

    // start at perihelion
    obj->pos = perihelion;

    // tangential velocity using vis-viva
    float v = sqrtf(G * 1.0f * (2.0f / r_peri - 1.0f / a));

    // compute tangential direction perpendicular to radius vector from Sun (0,0)
    Vector2 r_hat = {obj->pos.x / r_peri, obj->pos.y /r_peri};
    obj->vel.x = -r_hat.y * v; // clockwise
    obj->vel.y = r_hat.x * v; 

    // initialize acceleration to zero
    obj->acc = (Vector2){0,0};

    return obj;
}

void body_destroy(body_t *body){
    if(!body){
        return;
    }
    free(body);
}
