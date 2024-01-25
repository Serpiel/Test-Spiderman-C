#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Spiderman {
    unsigned int vie;
    unsigned int attaque;
    unsigned int defense;

    union {
        char nom[10];
    } identite;
};

struct BouffonVert {
    unsigned int vie;
    unsigned int attaque;
    unsigned int defense;

    union {
        char nom[15];
    } identite;
};

struct Venom {
    unsigned int vie;
    unsigned int attaque;
    unsigned int defense;

    union {
        char nom[20];
    } identite;
};

struct MilesMorales {
    unsigned int vie;
    unsigned int attaque;
    unsigned int defense;

    union {
        char nom[25];
    } identite;
};

void attaqueSpiderman(struct Spiderman* spiderman, struct BouffonVert* bouffon) {
    bouffon->vie -= 110;
}
void attaqueVenom(struct Venom* venom, struct MilesMorales* miles) {
    miles->vie -= 205;
}
void degatsSpiderman(struct Venom* venom, struct Spiderman* spiderman) {
    spiderman->vie -= 190;
}


int main() {
    struct Spiderman spiderman;
    struct BouffonVert bouffon;
    struct Venom venom;
    struct MilesMorales miles;

    spiderman.vie = 1200;
    spiderman.attaque = 150;
    spiderman.defense = 60;
    strcpy(spiderman.identite.nom, "Peter Parker");

    bouffon.vie = 1500;
    bouffon.attaque = 170;
    bouffon.defense = 40;
    strcpy(bouffon.identite.nom, "Norman Osborn");
    printf("\033[31;01mSpiderman\033[00m\n");
    printf("Vie: %d\n", spiderman.vie);
    printf("Attaque: %d\n", spiderman.attaque);
    printf("Defense: %d\n", spiderman.defense);
    printf("Identite: Secrete (%s)\n\n", spiderman.identite.nom);

    printf("\033[32;01mBouffon Vert\033[00m\n");
    printf("Vie: %d\n", bouffon.vie);
    printf("Attaque: %d\n", bouffon.attaque);
    printf("Defense: %d\n", bouffon.defense);
    printf("Identite: Secrete (%s)\n\n", bouffon.identite.nom);

    venom.vie = 2000;
    venom.attaque = 250;
    venom.defense = 75;
    strcpy(venom.identite.nom, "Eddie Brock");
    printf("\033[34;01mVenom\033[00m\n");
    printf("Vie: %d\n", venom.vie);
    printf("Attaque: %d\n", venom.attaque);
    printf("Defense: %d\n", venom.defense);
    printf("Identite: %s\n\n", venom.identite.nom);

    miles.vie = 1000;
    miles.attaque = 100;
    miles.defense = 45;
    strcpy(miles.identite.nom, "Miles Morales");
    printf("\033[35;01mSpiderman (Earth-1610)\033[00m\n");
    printf("Vie: %d\n", miles.vie);
    printf("Attaque: %d\n", miles.attaque);
    printf("Defense: %d\n", miles.defense);
    printf("Identite: Secrete (%s)\n\n", miles.identite.nom);

    printf("\033[31;03mSpiderman attaque le Bouffon Vert et met %d degats !\033[00m\n", spiderman.attaque - bouffon.defense);
    attaqueSpiderman(&spiderman, &bouffon);
    printf("\033[32;03mVie restante du Bouffon Vert: %d\033[00m\n", bouffon.vie);
    printf("\033[32;03mLe bouffon vert est enerve, augmentation des degats de 20, attaque: %d\033[00m\n\n", bouffon.attaque + 20);
    printf("\033[35;03mSpiderman (Earth 1610) tente d'attaquer Venom\033[00m, \033[34;03mmais Venom contre-attaque et mets %d degats\033[00m\n", venom.attaque - miles.defense);
    attaqueVenom(&venom, &miles);
    printf("\033[35;03mVie restante de Spiderman (Earth 1610): %d\033[00m\n", miles.vie);
    printf("\033[35;03mSpiderman (Earth 1610) se replie\033[00m\n");
    printf("\033[31;03mSpiderman protege Spiderman (Earth 1610) et se prend %d degats\033[00m\n", venom.attaque - spiderman.defense);
    degatsSpiderman(&venom, &spiderman);
    printf("\033[31;03mVie restant de Spiderman: %d\033[00m\n", spiderman.vie);

    return 0;
}