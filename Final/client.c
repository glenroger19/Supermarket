#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

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
