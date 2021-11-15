#include "Pistol.h"

int glockFire(PlayerVitalData *targetData,Pistol *pistol){
    if(clipCheck(pistol)){
        return ZERO;
    }

    int damage;

    for(int i=0;i<FIRE_PER_ROUND;i++){
        if(!clipCheck(pistol)){
            damage = pistol->damagePerRound;
            if(targetData->armor>ZERO){
                if(damage/TWO>targetData->armor){
                    damage -= targetData->armor;
                    targetData->armor = ZERO;
                }
                else{
                    targetData->armor -= damage/TWO;
                    damage /= TWO;
                }
            }
            targetData->health -= damage;
            
            printf("Enemy left with: %d health and %d armor\n", targetData->health, targetData->armor);

            if(targetData->health <= ZERO){
                return ONE;
            }

            pistol->currClipBullets -= ONE;

        }
        else{
            return ZERO;
        }
    }
    return ZERO;
}

int deagleFire(PlayerVitalData *targetData,Pistol *pistol){
    if(clipCheck(pistol)){
        return ZERO;
    }

    int damage;

    damage = pistol->damagePerRound;
    if(targetData->armor>ZERO){
        if(damage/FOUR>targetData->armor){
            damage -= targetData->armor;
            targetData->armor = ZERO;
        }
        else{
            targetData->armor -= damage/FOUR;
            damage = (damage / FOUR) * THREE;
        }
    }
    targetData->health -= damage;
    
    printf("Enemy left with: %d health and %d armor\n", targetData->health, targetData->armor);
    
    if(targetData->health <= ZERO){
        return ONE;
    }

    pistol->currClipBullets -= ONE;

    return ZERO;
}

int clipCheck(Pistol *pistol){
    if(pistol->currClipBullets==ZERO){
        reloadPistol(pistol);
        return ONE;
    }
    return ZERO;
}

void reloadPistol(Pistol *pistol){
    if(pistol->remainingAmmo > ZERO){
        printf("Reloading...\n");
        if(pistol->remainingAmmo > pistol->clipSize){
            pistol->currClipBullets = pistol->clipSize;
            pistol->remainingAmmo -= pistol->clipSize;
        }
        else{
            pistol->currClipBullets = pistol->remainingAmmo;
            pistol->remainingAmmo = ZERO;
        }

        printf("currClipBullets: %d, remainingAmmo: %d\n", pistol->currClipBullets, pistol->remainingAmmo);
    }
    else{
        printf("No ammo left\n");
    }
}

void setPistol(Pistol *pistol){
    switch (pistol->pistolType)
    {
    case GLOCK:
        pistol->fire = &glockFire;
        break;

    case DESERT_EAGLE:
        pistol->fire = &deagleFire;
        break;

    default:
        printf("Pistol setting went wrong!!!\n");
        break;
    }
}