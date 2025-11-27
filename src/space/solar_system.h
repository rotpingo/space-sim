#include "core/sim.h"
#include "space/body.h"

body_t *create_sun(void);
body_t *create_earth(void);
body_t *create_mars(void);
body_t *create_moon(body_t *b);
body_t *create_jupiter(void);
void create_solar_system(sim_t* sim);
