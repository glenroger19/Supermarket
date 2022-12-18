#ifndef STRUCT1
#define STRUCT1

typedef struct tm date;

typedef struct item_panier{
    int idProd;
    double quantite;
    struct item_panier* suivant;
}item_panier;

typedef struct{
    item_panier* first;
    date* date_ticket;
    double total;
    int ticketid;
    int clientid;
}panier;

#endif
void entete_client(char* page);

void bas_client();

int taille1(char* nomfichier);

void receipt(panier* p);

void affichage_client();