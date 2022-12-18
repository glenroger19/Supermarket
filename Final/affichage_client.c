#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include"gerant.h"
#include"client.h"

void receipt(panier* p){
    time_t timestamp = time(NULL);
    struct tm * now = localtime(&timestamp);
    printf("=========================================================================================================================================================\n");
    printf("                                                                        RECU \n");
    printf("=========================================================================================================================================================\n");
    printf("\n");
    printf("\n");
    printf("    Date : %4d-%02d-%02d\n",now->tm_year+1900, now->tm_mon+1, now->tm_mday);
    printf("    Heure : %02d:%02d:%02d\n",now->tm_hour, now->tm_min, now->tm_sec);
    printf("\n");
    printf("\n");
    printf("Quantité                                                            Désignation                                   Prix Unitaire en euros\n");
    printf("\n");
    affiche_panier(p);
    printf("                                                                                                                  Total HT : %.2lf euros\n",p->total*(1-(20/(double)100)));
    printf("                                                                                                                  Total TTC : %.2lf euros\n",p->total);
}

void affichage_client(){
    panier* p = panier_init();
    printf("\e[1;1H\e[2J");
    printf("=========================================================================================================================================================\n");
    printf("                                                                     MODE CAISSIER \n");
    printf("=========================================================================================================================================================\n");
    printf("\n");
    printf("\n");
    printf("                    1 - Ajouter un produit dans le panier\n");
    printf("                    2 - Enlever un produit dans le panier\n");
    printf("                    3 - Afficher mon panier\n");
    printf("                    4 - Montrer et payer ma reçu\n");
    printf("                    5 - Quitter le mode caissier\n");
    printf("\n");
    printf("\n");
    printf("Veuillez choisir ce que vous allez faire :\n");
    printf("\n");
    printf("\n");
    int choix;
    scanf("%i",&choix);
    while(choix!=5){
        if(choix==1){
            printf("\e[1;1H\e[2J");
            printf("=========================================================================================================================================================\n");
            printf("                                                                     MODE CAISSIER \n");
            printf("=========================================================================================================================================================\n");
            printf("\n");
            printf("\n");
            printf("                    1 - Ajouter un produit dans le panier\n");
            printf("                    2 - Enlever un produit dans le panier\n");
            printf("                    3 - Afficher mon panier\n");
            printf("                    4 - Montrer et payer ma reçu\n");
            printf("                    5 - Quitter le mode caissier\n");
            printf("\n");
            printf("\n");
            int n = taille("stock");
            produit* tab = malloc(n*sizeof(produit));
            charge(tab,n,"stock");
            print_tab(tab,n);
            free(tab);
            printf("\n");
            printf("\n");
            panier_add(p);
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
            printf("                                                                     MODE CAISSIER \n");
            printf("=========================================================================================================================================================\n");
            printf("\n");
            printf("\n");
            printf("                    1 - Ajouter un produit dans le panier\n");
            printf("                    2 - Enlever un produit dans le panier\n");
            printf("                    3 - Afficher mon panier\n");
            printf("                    4 - Montrer et payer ma reçu\n");
            printf("                    5 - Quitter le mode caissier\n");
            printf("\n");
            printf("\n");
            panier_remove(p);
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
        if(choix==3){
            printf("\e[1;1H\e[2J");
            printf("=========================================================================================================================================================\n");
            printf("                                                                     MODE CAISSIER \n");
            printf("=========================================================================================================================================================\n");
            printf("\n");
            printf("\n");
            printf("                    1 - Ajouter un produit dans le panier\n");
            printf("                    2 - Enlever un produit dans le panier\n");
            printf("                    3 - Afficher mon panier\n");
            printf("                    4 - Montrer et payer ma reçu\n");
            printf("                    5 - Quitter le mode caissier\n");
            printf("\n");
            printf("\n");
            affiche_panier(p);
            printf("\n");
            printf("\n");
            printf("Veuillez choisir ce que vous allez faire :\n");
            printf("\n");
            printf("\n");
            scanf("%i",&choix);
        }
        if(choix==4){
            printf("\e[1;1H\e[2J");
            printf("=========================================================================================================================================================\n");
            printf("                                                                     MODE CAISSIER \n");
            printf("=========================================================================================================================================================\n");
            printf("\n");
            printf("\n");
            printf("                    1 - Ajouter un produit dans le panier\n");
            printf("                    2 - Enlever un produit dans le panier\n");
            printf("                    3 - Afficher mon panier\n");
            printf("                    4 - Montrer et payer ma reçu\n");
            printf("                    5 - Quitter le mode caissier\n");
            printf("\n");
            printf("\n");
            receipt(p);
            printf("\n");
            printf("\n");
            printf("Veuillez choisir ce que vous allez faire :\n");
            printf("\n");
            printf("\n");
            scanf("%i",&choix);
        }
    }
}