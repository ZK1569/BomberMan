#ifndef GAMEMODE_H
#define GAMEMODE_H

typedef enum
{
    START = 1,
    START_GRAPHICAL,
    START_SERVER,
    JOIN_SERVER,
} GameMode;

int setGameMode(void);

extern GameMode mode;
#endif