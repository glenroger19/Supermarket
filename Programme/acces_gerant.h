#ifndef STRUCT4
#define STRUCT4

typedef struct{
    char login[64];
    char mdp[64];
}compte;

int taille_compte(char* nomfichier);

void sauvegarde_compte(compte* tab, int n, char* nomfichier);

void sauvegarde_add_compte(compte* tab, int n, char* nomfichier);

void charge_compte(compte* tab,int n, char* nomfichier);

int accces_gerant();

#endif