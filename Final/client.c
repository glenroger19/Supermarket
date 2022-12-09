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

void enleve_stock(item_panier* ip){
    int identifiant=0;
    int n = taille("stock");
    produit* tab = malloc(n*sizeof(produit));
    charge(tab,n,"stock");
    while(ip->idProd!=tab[identifiant].id){
        identifiant++;
    }
    tab[identifiant].stocks=tab[identifiant].stocks - ip->quantite;
    sauvegarde(tab,n,"stock");
    free(tab);
}

void remet_stock(item_panier* ip){
    int identifiant=0;
    int n = taille("stock");
    produit* tab = malloc(n*sizeof(produit));
    charge(tab,n,"stock");
    while(ip->idProd!=tab[identifiant].id){
        identifiant++;
    }
    tab[identifiant].stocks=tab[identifiant].stocks + ip->quantite;
    sauvegarde(tab,n,"stock");
    free(tab);
}

int loc_prod(panier *p, int rem){
    item_panier* ip = p->first;
    int loc = 0;
    while(ip!=NULL && ip->idProd!=rem){
        loc++;
        ip = ip->suivant;
    }
    return loc;
}

void pop_front(panier* p){
    item_panier* ip = p->first;
    p->first = p->first->suivant;
    free(ip);
}

void pop_end(panier* p){
    item_panier* ip = p->first;
    while(ip->suivant!=NULL){
        ip = ip->suivant;
    }
    free(ip->suivant);
    ip->suivant = NULL;    
}

void pop(panier* p, int rem){   //prend en argument un panier et l'id a supprimer
    item_panier* ip = p->first;
    while(ip->suivant!=NULL && ip->suivant->idProd != rem){
        ip = ip->suivant;
    }
    item_panier* ip1 = ip->suivant;
    ip->suivant = ip->suivant->suivant;
    free(ip1);
}

panier* panier_init(){
    panier* p = (panier*)malloc(sizeof(panier));
    p->first = NULL;
    return p;
}

void panier_add(panier* p){
    item_panier* ip = malloc(sizeof(item_panier));
    scanf("%i",&ip->idProd);
    scanf("%lf",&ip->quantite);
    ip->suivant = p->first;
    p->first = ip;
    enleve_stock(ip);
    free(ip);
}

void panier_remove(panier* p){
    //assert(p->first!=NULL);
    int rem;
    int quant;
    scanf("%i",&rem);
    scanf("%i",&quant);
    int loc = loc_prod(p, rem);
    printf("%i\n",loc);
    if(loc==1){
        pop_front(p);
    }
    else if(loc==0){
        pop_end(p);
    }
    else{
        pop(p,rem);
    }
    item_panier* ip = malloc(sizeof(item_panier));
    ip->idProd = rem;
    ip->quantite = quant;
    remet_stock(ip);
    free(ip);
}

int main(){
    panier* p = panier_init();
    panier_add(p);
    panier_add(p);
    panier_remove(p);
}