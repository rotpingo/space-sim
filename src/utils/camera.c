#include "camera.h"
#include "raylib.h"
#include "raymath.h"
#include <math.h>

void camera_controls(Camera2D *camera){
    
if(IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        Vector2 delta = GetMouseDelta();
        delta = Vector2Scale(delta, -1.0f / camera->zoom);
        camera->target = Vector2Add(camera->target, delta);
    }

    float wheel = GetMouseWheelMove();
    if(wheel != 0){
        // Get the world point that is under the mouse
        Vector2 mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), *camera);

        // Set the offset to where the mouse is, so zoom is centered on mouse
        camera->offset = GetMousePosition();

        // Zoom exponentially
        camera->zoom += wheel *0.2f * camera->zoom;

        // Clamp zoom
        if(camera->zoom < 0.125f) camera->zoom = 0.125f;
        if(camera->zoom > 64.0f) camera->zoom = 64.0f;

        camera->target = mouseWorldPos;
        // Zoom increment
        // Uses log for scaling to provide consistent zoom speed
        // float scale = 0.2f* wheel;
        // camera->zoom = Clamp(expf(logf(camera->zoom) + scale), 0.125f, 64.0f);
    }
}   
