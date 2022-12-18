#include<stdio.h>
#include<stdlib.h>
#include"gerant.h"

void affichage_gerant(){
    printf("\e[1;1H\e[2J");
    printf("=========================================================================================================================================================\n");
    printf("                                                                        MODE GERANT \n");
    printf("=========================================================================================================================================================\n");
    printf("\n");
    printf("\n");
    printf("                    1 - Regarder la liste des produits en stock\n");
    printf("                    2 - Ajouter des produits dans le stock\n");
    printf("                    3 - Enlever des produits dans le stock\n");
    printf("                    4 - Quitter le mode gérant\n");
    printf("\n");
    printf("\n");
    printf("Veuillez choisir ce que vous allez faire :\n");
    printf("\n");
    printf("\n");
    int choix = 0;
    scanf("%i",&choix);
    while(choix!=4){
        if(choix==1){
            printf("\e[1;1H\e[2J");
            printf("=========================================================================================================================================================\n");
            printf("                                                                        MODE GERANT \n");
            printf("=========================================================================================================================================================\n");
            printf("\n");
            printf("\n");
            printf("                    1 - Regarder la liste des produits en stock\n");
            printf("                    2 - Ajouter des produits dans le stock\n");
            printf("                    3 - Enlever des produits dans le stock\n");
            printf("                    4 - Quitter le mode gérant\n");
            printf("\n");
            printf("\n");
            int n = taille("stock");
            produit* tab = malloc(n*sizeof(produit));
            charge(tab,n,"stock");
            print_tab(tab,n);
            free(tab);
            printf("\n");
            printf("\n");
            printf("Veuillez choisir ce que vous allez faire :\n");
            printf("\n");
            printf("\n");
            scanf("%i",&choix);
        }
        if(choix==2){
            printf("\e[1;1H\e[2J");
            printf("=========================================================================================================================================================\n");
            printf("                                                                        MODE GERANT \n");
            printf("=========================================================================================================================================================\n");
            printf("\n");
            printf("\n");
            printf("                    1 - Regarder la liste des produits en stock\n");
            printf("                    2 - Ajouter des produits dans le stock\n");
            printf("                    3 - Enlever des produits dans le stock\n");
            printf("                    4 - Quitter le mode gérant\n");
            printf("\n");
            printf("\n");
            int n = taille("stock");
            produit* tab = malloc(sizeof(produit));
            int rep = add(tab);
            if(rep==1){
                tab->id = n+1;
                sauvegarde_add(tab,1,"stock");
                free(tab);
            }
            printf("\n");
            printf("\n");
            printf("Veuillez choisir ce que vous allez faire :\n");
            printf("\n");
            printf("\n");
            scanf("%i",&choix);
        }
        if(choix==3){
            printf("\e[1;1H\e[2J");
            printf("=========================================================================================================================================================\n");
            printf("                                                                        MODE GERANT \n");
            printf("=========================================================================================================================================================\n");
            printf("\n");
            printf("\n");
            printf("                    1 - Regarder la liste des produits en stock\n");
            printf("                    2 - Ajouter des produits dans le stock\n");
            printf("                    3 - Enlever des produits dans le stock\n");
            printf("                    4 - Quitter le mode gérant\n");
            printf("\n");
            printf("\n");
            int n = taille("stock");
            produit* tab = malloc(n*sizeof(produit));
            charge(tab,n,"stock");
            produit* new_tab = malloc((n-1)*sizeof(produit));
            enleve(tab,new_tab,n);
            sauvegarde(new_tab,n-1,"stock");
            printf("\n");
            printf("\n");
            printf("Veuillez choisir ce que vous allez faire :\n");
            printf("\n");
            printf("\n");
            scanf("%i",&choix);
        }
    }
}