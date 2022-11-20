#ifndef _MENU_H_
#define _MENU_H_

#include "../objects/bombs.h"

void init_menu(Game *game);

void add_menu_option(Game *game, Menu *menu, char *text, int x, int y, int width, int height, int font_size, SDL_Color color, SDL_Color hover_color, SDL_Color active_color, void (*callback)(Game *game));

void update_menu(Game *game);
void update_menu_options(Game *game, Menu *menu);
void update_menu_option(Game *game, Menu *menu, MenuOption *option);

void render_menu(Game *game);
void render_menu_options(Game *game, Menu *menu);
void render_menu_option(Game *game, Menu *menu, MenuOption *option);

#endif