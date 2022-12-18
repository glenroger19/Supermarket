#include<stdio.h>
#include"client.c"

void affiche_panier(panier* p){
    item_panier* ip;
    for(ip=p->first ; ip!=NULL ; ip=ip->suivant){
        printf("%i %f\n",ip->idProd,ip->quantite);
    }
    printf("\n");
}

void receipt(){
    panier* p = panier_init();
    affiche_panier(p);
    int choix;
    while(choix!=5){
        if(choix==1){
            panier_add(p);
        }
        if(choix==2){
            panier_remove(p);
        }
        if(choix==3){
            affiche_panier(p);
        }
    }
}

int main(){
    panier* p = panier_init();
    panier_add(p);
    affiche_panier(p);
}