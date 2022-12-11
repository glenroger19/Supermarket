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
    scanf("%i",&ip->idProd);
    scanf("%lf",&ip->quantite);
    int identifiant=0;
    int n = taille("stock");
    produit* tab = malloc(n*sizeof(produit));
    charge(tab,n,"stock");
    while(ip->idProd!=tab[identifiant].id){
        identifiant++;
    }
    printf("%i\n",identifiant);
    printf("%f\n",tab[identifiant].prix_unit);
    if(tab[identifiant].prix_unit >= ip->quantite){
        ip->suivant = p->first;
        p->first = ip;
        enleve_stock(ip);
        free(ip);
        printf("Vous avez acheter %.2f de %s\n",tab[identifiant].prix_unit*(double)ip->quantite,tab[identifiant].nom);
    }
    else{
        printf("Il n'y a pas assez dans le stock\n");
    }
    
}

void panier_remove(panier* p){
    assert(p->first!=NULL);
    int rem;
    int quant;
    scanf("%i",&rem);
    scanf("%i",&quant);
    item_panier* ip = p->first;
    while(ip->suivant!=NULL && ip->suivant->idProd!=rem){
        ip = ip->suivant;
    }
    if(quant <= ip->suivant->quantite){
            if(rem==1){
        p->first = p->first->suivant;
        free(ip);
    }
    else if(ip->suivant==NULL){
        free(ip->suivant);
        ip = NULL;
    }
    else{
        item_panier* ip1 = ip->suivant;
        ip->suivant = ip->suivant->suivant;
        free(ip1);
    }
    item_panier* ip1 = malloc(sizeof(item_panier));
    ip1->idProd = rem;
    ip1->quantite = quant;
    remet_stock(ip1);
    free(ip1);
    }
    else{
        printf("Vous remettez plus d'article que vous en avez pris\n");
    }

}

int main(){
    panier* p = panier_init();
    panier_add(p);
    panier_add(p);
    panier_remove(p);
}