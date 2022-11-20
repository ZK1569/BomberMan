#ifndef _BOMBS_H_
#define _BOMBS_H_

#include "powerup.h"

// Bombs functions
void init_bombs(Game *game);
void init_bomb(GameBomb *bomb, GamePlayer *owner);
void add_bomb(Game *game, GamePlayer *owner);
bool place_bomb(Game *game, GamePlayer *owner);
bool can_place_bomb(Game *game, SDL_Rect *rect);
void update_bombs(Game *game);
void update_bomb(Game *game, GameBomb *bomb);
void move_bomb(Game *game, GameBomb *bomb, Direction direction);
void draw_bombs(Game *game);
void draw_bomb(Game *game, GameBomb *bomb);
void explode_bomb(Game *game, GameBomb *bomb);
bool add_explosion(Game *game, GameBomb *bomb, Direction direction, int col, int row, int range);
void handle_explosion_direction(Game *game, GameBomb *bomb, Direction direction, int col, int row, int range);
bool handle_player_explosion(Game *game, GameBomb *bomb, int col, int row);
bool drop_powerup(Game *game, int col, int row);
void spread_explosion(Game *game, GameBomb *bomb, int col, int row);
void free_bomb(GameBomb *bomb);

#endif