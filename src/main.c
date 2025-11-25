#include "core/app.h"
#include "raylib.h"

int main ()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
    
    // App creation
    App app;

	// Create the window and OpenGL context
    App_Init(&app);
    App_Run(&app);
	
    App_Shutdown(&app);
	return 0;
}
