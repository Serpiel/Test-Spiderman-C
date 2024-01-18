#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
struct Spiderman {
    unsigned int vie;
    unsigned int attaque;
    unsigned int defense;
    union {
        char nom[6];
    } identite;
};


    void afficherStatsSpiderman(struct Spiderman hero){
        printf("Spiderman - Vie: %d, Attaque: %d, Defense: %d\n", hero.vie, hero.attaque, hero.defense);
     }

    int main(){
        
        struct Spiderman spiderman1 = { 200, 150, 100 };

        afficherStatsSpiderman(spiderman1);
       
    

	return 0;
}
   