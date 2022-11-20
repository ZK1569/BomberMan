#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "../map/map.h"

// GamePlayer functions
void init_player(Game *game, GamePlayer *player, int x, int y);
void add_player(Game *game);
void draw_players(Game *game);
void draw_player(Game *game, GamePlayer *player);
void draw_player_powerups(Game *game, GamePlayer *player);
void draw_player_lives(Game *game, GamePlayer *player);
void move_player(Game *game, GamePlayer *player, Direction direction);
Powerup *collide_with_powerup(Game *game, int x, int y);
GameBomb *collide_with_bomb(Game *game, int x, int y);
bool consume_powerup(Game *game, GamePlayer *player, Powerup *powerup);
bool is_valid_move(Game *game, GamePlayer *player, SDL_Rect *rect);
bool kick_bomb(Game *game, GameBomb *bomb, Direction direction);
bool teleport_player(Game *game, GamePlayer *player, int x, int y);
void update_players(Game *game);
void update_player(Game *game, GamePlayer *player);
void update_player_rect(GamePlayer *player);
void take_damage(Game *game, GamePlayer *player, int damage);

bool kill_player(Game *game, GamePlayer *player);

const char *get_powerup_name(PowerupType type);
SDL_Rect get_powerup_rect(PowerupType type);
SDL_Color get_powerup_color(PowerupType type);

#endif