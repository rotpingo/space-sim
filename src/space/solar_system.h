#include "core/sim.h"
#include "space/body.h"

body_t *create_sun(void);
body_t *create_earth(body_t *b);
body_t *create_mars(body_t *b);
body_t *create_moon(body_t *b);
body_t *create_jupiter(body_t *b);
void create_solar_system(sim_t* sim);
