#include<stdio.h>
#include<stdlib.h>
#include"gerant.h"

void affichage_gerant(){
    printf("=========================================================================================================================================================\n");
    printf("                                                                        Mode Gerant \n");
    printf("=========================================================================================================================================================\n");
    printf("Veuillez choisir ce que vous allez faire :\n");
    int choix = 0;
    do{
        printf("\n");
        printf("\n");
        printf("                    1 - Regarder la liste des produits en stock\n");
        printf("                    2 - Ajouter des produits dans le stock\n");
        printf("                    3 - Enlever des produits dans le stock\n");
        printf("                    4 - Quitter le mode gérant\n");
        printf("\n");
        printf("\n");
        scanf("%i",&choix);
        if(choix==1){
            int n = taille("stock");
            produit* tab = malloc(n*sizeof(produit));
            charge(tab,n,"stock");
            print_tab(tab,n);
            free(tab);
        }
        if(choix==2){
            int n = taille("stock");
            produit* tab = malloc(sizeof(produit));
            tab->id = n+1;
            add(tab);
            sauvegarde_add(tab,1,"stock");
            free(tab);
        }
        if(choix==3){
            int n = taille("stock");
            produit* tab = malloc(n*sizeof(produit));
            charge(tab,n,"stock");
            produit* new_tab = malloc((n-1)*sizeof(produit));
            enleve(tab,new_tab,n);
            sauvegarde(new_tab,n-1,"stock");
        }
    }while(choix!=4);
}

int main(){
    affichage_gerant();
}