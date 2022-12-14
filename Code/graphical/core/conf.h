#ifndef _CONF_H_
#define _CONF_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#define TILE_SIZE 16
#define SCALE 3
#define TEXTURE_WIDTH 224
#define TEXTURE_HEIGHT 384
#define MAX_MAP_WIDTH 20
#define MAX_MAP_HEIGHT 20
#define UI_SIZE 20

#define MAX_BUFFER_SIZE 4096

#define MAX_NUMBER_OF_BOMBS 20
#define MAX_NUMBER_OF_POWERUPS 100
#define MAX_NUMBER_OF_PLAYERS 4
#define MAX_BOMB_RANGE 10

#define AI_PLAYER_ACTION_DELAY 500

#define BOMB_LIFE_TIME 3000
#define BOMB_SPREAD_LIFE_TIME 500
#define BOMB_ANIMATION_FRAME_DELAY 100
#define BOMB_MOVE_DELAY 25

// Powerups
#define POWERUP_LIFE_TIME 10000
#define POWERUP_DROP_RATE 0.8
#define POWERUP_SPANW_RATE 0.1
#define POWERUP_SPAWN_DELAY 10000
#define POWERUP_INVINCIBLE_DURATION 10

#endif