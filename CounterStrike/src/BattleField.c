#include "BattleField.h"

#include <stdio.h>

void createPlayers(BattleField *bf){
  int playerHealth = 0;
  int playerArmor = 0;
  Player players[PLAYERS_COUNT];
  for (int i = 0; i < PLAYERS_COUNT; ++i) {
    scanf("%d %d", &playerHealth, &playerArmor);
    players[i].playerData.health=playerHealth;
    players[i].playerData.armor=playerArmor;
    players[i].playerId=i;
  }
  buyPistols(&players[PLAYER_ONE]);
  buyPistols(&players[PLAYER_TWO]);
  bf->players[PLAYER_ONE]=players[PLAYER_ONE];
  bf->players[PLAYER_TWO]=players[PLAYER_TWO];
}

void buyPistols(Player *player){
  int pistolId = 0;
  int pistolDamagePerRound = 0;
  int pistolClipSize = 0;
  int pistolRemainingAmmo = 0;
  Pistol pistol;
  scanf("%d %d %d %d", &pistolId, &pistolDamagePerRound, &pistolClipSize, &pistolRemainingAmmo);
      pistol.pistolType=pistolId;
      pistol.damagePerRound=pistolDamagePerRound;
      pistol.clipSize=pistolClipSize;
      pistol.currClipBullets=pistolClipSize;
      pistol.remainingAmmo=pistolRemainingAmmo;
      setPistol(&pistol);
  
  player->pistol=pistol;
}

void startBattle(BattleField *bf) {
  int victor;
  while(1){
    printf("\nPlayerID %d turn:\n", PLAYER_ONE);
    if(bf->players[PLAYER_ONE].pistol.fire(&bf->players[PLAYER_TWO].playerData, &bf->players[PLAYER_ONE].pistol)){
      victor = PLAYER_ONE;
      break;
    }
    printf("\nPlayerID %d turn:\n", PLAYER_TWO);
    if(bf->players[PLAYER_TWO].pistol.fire(&bf->players[PLAYER_ONE].playerData, &bf->players[PLAYER_TWO].pistol)){
      victor = PLAYER_TWO;
      break;
    }
  }
  printf("\nPlayer with ID: %d wins!\n", victor);
}

