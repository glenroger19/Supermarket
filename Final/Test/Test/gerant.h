#ifndef STRUCT
#define STRUCT

typedef struct{
    int id;
    char nom[64];
    double prix_unit;
    int stocks;
}produit;

int ordrealpha(const char* s1,const char* s2);

int taille(char* nomfichier);

void sauvegarde_add(produit* tab, int n, char* nomfichier);

void sauvegarde(produit* tab, int n, char* nomfichier);

void charge(produit* tab,int n, char* nomfichier);

void print_tab(produit* tab,int n);

void add(produit* new);

void enleve(produit* new, produit* new_copy, int n);

#endif