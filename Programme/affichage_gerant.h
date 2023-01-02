#ifndef STRUCT
#define STRUCT

typedef struct{
    int id;
    char nom[64];
    double prix_unit;
    int stocks;
}produit;

#endif
void entete_gerant(char* page);

void bas_gerant();

void affichage_gerant();