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

void enleve_stock(int id, double quantite);

void remet_stock(int id, double quantite);

double prix(item_panier* ip);

panier* panier_init();

void panier_add(panier* p);

int identifiant_p(int id, panier* p);

void pop_front(panier* p);

void pop(panier* p, int id_rem);

void panier_remove(panier* p);

#endif