#ifndef STRUCT2
#define STRUCT2

typedef struct{
    char nom[64];
    char prenom[64];
    int id_client;
    double cagnotte;
}client;

void delay(int i);

int taille_c(char* nomfichier);

void charge_c(client* tab,int n, char* nomfichier);

void sauvegarde_c(client* tab, int n, char* nomfichier);

void change_c(client* tab, int n, char* nomfichier);

int identifiant_c();

void print_c(client* tab,int n);

int affichage_id(client* c);

#endif