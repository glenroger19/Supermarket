#ifndef STRUCT
#define STRUCT

typedef struct{
    int id;
    char nom[64];
    double prix_unit;
    int stocks;
}produit;

#endif

void affichage_gerant();