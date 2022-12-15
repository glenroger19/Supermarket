#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include"gerant.h"

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

void enleve_stock(int id, double quantite){
    int identifiant=0;
    int n = taille("stock");
    produit* tab = malloc(n*sizeof(produit));
    charge(tab,n,"stock");
    while(id!=tab[identifiant].id){
        identifiant++;
    }
    tab[identifiant].stocks=tab[identifiant].stocks - quantite;
    sauvegarde(tab,n,"stock");
    free(tab);
}

void remet_stock(int id, double quantite){
    int identifiant=0;
    int n = taille("stock");
    produit* tab = malloc(n*sizeof(produit));
    charge(tab,n,"stock");
    while(id!=tab[identifiant].id){
        identifiant++;
    }
    tab[identifiant].stocks=tab[identifiant].stocks + quantite;
    sauvegarde(tab,n,"stock");
    free(tab);
}

double prix(item_panier* ip){
    int identifiant=0;
    int n = taille("stock");
    produit* tab = malloc(n*sizeof(produit));
    charge(tab,n,"stock");
    while(ip->idProd!=tab[identifiant].id){
        identifiant++;
    }
    double prix = tab[identifiant].prix_unit * ip->quantite;
    return prix;
}

panier* panier_init(){
    panier* p = (panier*)malloc(sizeof(panier));
    p->first = NULL;
    return p;
}

void panier_add(panier* p){
    item_panier* ip = malloc(sizeof(item_panier));
    int id;
    double quantite;
    scanf("%i",&id);
    scanf("%lf",&quantite);
    ip->idProd = id;
    ip->quantite = quantite;
    ip->suivant = NULL;
    if(p->first == NULL){
        p->first = ip;
    }
    else{
        item_panier* ip1 = p->first;
        while(ip1->suivant != NULL){
            ip1 = ip1->suivant;
        }
        ip1->suivant = ip;
    }
    int identifiant = 0;
    int n = taille("stock");
    produit* tab = malloc(n*sizeof(produit));
    charge(tab,n,"stock");
    while(id!=tab[identifiant].id){
        identifiant++;
    }
    if(tab[identifiant].stocks >= quantite){
        enleve_stock(id, quantite);
        double prix = tab[identifiant].prix_unit * quantite;
        printf("Vous avez acheter %.2f euros de %s\n",prix,tab[identifiant].nom);
    }
    else{
        printf("Il n'y a pas assez dans le stock\n");
    }
}

int identifiant_p(int id, panier* p){
    item_panier* ip = p->first;
    int identifiant=0;
    while(ip != NULL && id != ip->idProd){
        ip = ip->suivant;
        identifiant++;
    }
    return identifiant;
}

void pop_front(panier* p){
    item_panier* ip = p->first;
    p->first = ip->suivant;
    free(ip);
}

void pop(panier* p, int id_rem){
    item_panier* ip = p->first;
    while(ip->suivant!=NULL && ip->suivant->idProd!=id_rem){
        ip = ip->suivant;
    }
    item_panier* ip1 = ip->suivant;
    ip->suivant = ip1->suivant;
    free(ip1);
}

void panier_remove(panier* p){
    assert(p->first!=NULL);
    int id_rem;
    int quant;
    scanf("%i",&id_rem);
    scanf("%i",&quant);
    int identifiant = identifiant_p(id_rem,p);
    printf("%i\n",identifiant);
    if(identifiant == 0){
        pop_front(p);
    }
    else{
        pop(p,id_rem);
    }
    remet_stock(id_rem,quant);
}

int main(){
    panier* p = panier_init();
    panier_add(p);
    //panier_add(p);
    panier_remove(p);
}