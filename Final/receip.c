#include<stdio.h>
#include"client.c"

void affiche_panier(panier* p){
    item_panier* ip;
    for(ip=p->first ; ip!=NULL ; ip=ip->suivant){
        printf("%i %f",ip->idProd,ip->quantite);
    }
    printf("\n");
}

int main(){
    panier* p = panier_init();
    panier_add(p);
    affiche_panier(p);
}
