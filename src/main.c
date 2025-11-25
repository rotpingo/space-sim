#include "core/app.h"
#include "raylib.h"

int main ()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
    
    // App creation
    App *app = App_Create();

    App_Run(app);
	
    App_Destroy(app);
	return 0;
}
