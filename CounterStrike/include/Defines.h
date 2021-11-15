#ifndef DEFINES_H_
#define DEFINES_H_
#include <stdio.h>

enum OurValues{
  ZERO=0,
  ONE=1,
  TWO = 2,
  THREE = 3,
  FOUR = 4
};

enum PistolType {
  GLOCK, DESERT_EAGLE
};

enum GlockDefines {
  FIRE_PER_ROUND = 3
};

enum PlayerDefines {
  PLAYER_ONE, PLAYER_TWO, PLAYERS_COUNT
};

typedef struct {
  int health;
  int armor;
} PlayerVitalData;

typedef struct Player Player;


typedef struct Pistol Pistol;

#endif /* DEFINES_H_ */
