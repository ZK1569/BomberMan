#ifndef _GAME_H_
#define _GAME_H_

#include "../menu/menu.h"

void start_game();

// Game functions
void init_game(Game *game);
void load_texture(Game *game, const char *filename);
void load_font(Game *game, const char *filename);
void process_input(Game *game);
void update(Game *game);
void render(Game *game);
void destroy_game(Game *game);

#endif