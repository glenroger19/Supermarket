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
    double quantite;
    scanf("%lf",&quantite);
    ip->quantite = quantite;
    int identifiant=0;
    int n = taille("stock");
    produit* tab = malloc(n*sizeof(produit));
    charge(tab,n,"stock");
    while(ip->idProd!=tab[identifiant].id){
        identifiant++;
    }
    if(tab[identifiant].stocks >= ip->quantite){
        ip->suivant = p->first;
        p->first = ip;
        enleve_stock(ip);
        free(ip);
        double prix = tab[identifiant].prix_unit * quantite;
        printf("Vous avez acheter %.2f euros de %s\n",prix,tab[identifiant].nom);
    }
    else{
        printf("Il n'y a pas assez dans le stock\n");
    }
}

/*void panier_remove(panier* p){
    assert(p->first!=NULL);
    int id_rem;
    int quant;
    scanf("%i",&id_rem);
    scanf("%i",&quant);
    item_panier* ip = p->first;
    int identifiant=0;
    int n = taille("stock");
    produit* tab = malloc(n*sizeof(produit));
    charge(tab,n,"stock");
    while(id_rem!=p.){
        identifiant++;
    }
    printf("%d\n",identifiant);
    if(identifiant==0){
        if(quant <= ip->suivant->quantite){
            free(ip);
            p->first = p->first->suivant;
            item_panier* ip1 = malloc(sizeof(item_panier));
            ip1->idProd = id_rem;
            ip1->quantite = quant;
            remet_stock(ip1);
            free(ip1);
        }
        else{
            printf("Vous remettez plus d'article que vous en avez pris\n");
        }
    }
    else{
        while(ip->suivant!=NULL && ip->suivant->idProd!=id_rem){
            ip = ip->suivant;
        }
        if(quant <= ip->suivant->quantite){
            if(ip->suivant==NULL){
                free(ip->suivant);
                ip = NULL;
            }
            else{
                item_panier* ip1 = ip->suivant;
                ip->suivant = ip->suivant->suivant;
                free(ip1);
            }
        item_panier* ip1 = malloc(sizeof(item_panier));
        ip1->idProd = id_rem;
        ip1->quantite = quant;
        remet_stock(ip1);
        free(ip1);
        }
        else{
            printf("Vous remettez plus d'article que vous en avez pris\n");
        }
    }
    free(tab);
}*/

void panier_remove(panier* p){
    assert(p->first!=NULL);
    int id_rem;
    int quant;
    scanf("%i",&id_rem);
    scanf("%i",&quant);
    item_panier* ip = p->first;
    int identifiant=0;
    while(id_rem != ip->idProd){
        identifiant++;
    }
    printf("%i\n",identifiant);
    free(ip);
    if(identifiant == 0){
        item_panier* ip = p->first;
        p->first = ip->suivant;
        free(ip);
    }
    else{
        item_panier* ip = ip->suivant;
        while(ip->suivant!=NULL && ip->suivant->idProd!=id_rem){
            ip = ip->suivant;
        }
        ip->suivant = ip->suivant->suivant;
        free(ip);
    }
    item_panier* ip1 = malloc(sizeof(item_panier));
    ip1->idProd = id_rem;
    ip1->quantite = quant;
    remet_stock(ip1);
    free(ip1);
}

int main(){
    panier* p = panier_init();
    panier_add(p);
    panier_remove(p);
}