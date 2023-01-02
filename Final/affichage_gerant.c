#include<stdio.h>
#include<stdlib.h>
#include"gerant.h"
#include"acces.h"

void entete_gerant(char* page){
    printf("\e[1;1H\e[2J");
    printf("=========================================================================================================================================================\n");
    printf("                                                                        %s\n",page);
    printf("=========================================================================================================================================================\n");
    printf("\n");
    printf("\n");
    printf("                    1 - Regarder la liste des produits en stock\n");
    printf("                    2 - Ajouter des produits dans le stock\n");
    printf("                    3 - Enlever des produits dans le stock\n");
    printf("                    4 - Afficher la comptabilité\n");
    printf("                    5 - Ajouter un compte d'accès au mode gérant\n");
    printf("                    6 - Quitter le mode gérant\n");
    printf("\n");
}

void bas_gerant(){
    printf("Veuillez choisir ce que vous allez faire :\n");
    printf("\n");
}

void affichage_gerant(){
    printf("\e[1;1H\e[2J");
    printf("=========================================================================================================================================================\n");
    printf("                                                                        MODE GERANT\n");
    printf("=========================================================================================================================================================\n");
    printf("\n");
    printf("\n");
    int acces = 0;
    while(acces != 1){
        acces = accces_gerant();
    }
    entete_gerant("GERANT");
    bas_gerant();
    int choix = 0;
    scanf("%i",&choix);
    while(choix!=6){
        if(choix==1){
            entete_gerant("LISTE DES PRODUITS");
            int n = taille("stock");
            produit* tab = malloc(n*sizeof(produit));
            charge(tab,n,"stock");
            print_tab(tab,n);
            free(tab);
            printf("\n");
            bas_gerant();
            scanf("%i",&choix);
        }
        if(choix==2){
            entete_gerant("AJOUTER DES PRODUITS");
            int n = taille("stock");
            produit* tab = malloc(sizeof(produit));
            int rep = add(tab);
            if(rep==1){
                tab->id = n+1;
                sauvegarde_add(tab,1,"stock");
                free(tab);
            }
            printf("\n");
            bas_gerant();
            scanf("%i",&choix);
        }
        if(choix==3){
            entete_gerant("ENLEVER DES PRODUITS");
            int n = taille("stock");
            produit* tab = malloc(n*sizeof(produit));
            charge(tab,n,"stock");
            produit* new_tab = malloc((n-1)*sizeof(produit));
            enleve(tab,new_tab,n);
            sauvegarde(new_tab,n-1,"stock");
            printf("\n");
            bas_gerant();
            scanf("%i",&choix);
        }
        if(choix==4){
            entete_gerant("COMPTABILITE");
            FILE* fich = fopen("compta.csv","r");
            char c;
            while((c = fgetc(fich))!=EOF){
                if(c==';' || c==','){
                    printf("\t\t\t\t");
                }
                else{
                    printf("%c",c);
                }
            }
            fclose(fich);
            printf("\n");
            bas_gerant();
            scanf("%i",&choix);
        }
        if(choix==5){
            entete_gerant("AJOUT ACCES");
            compte* com = malloc(sizeof(compte));
            char login[64];
            char mdp[64];
            printf("Entrer votre login : \n");
            printf("\n");
            scanf("%s",login);
            printf("\n");
            printf("Entrer votre mot de passe : \n");
            printf("\n");
            scanf("%s",mdp);
            sauvegarde_add_compte(com,1,"base_employe");
            printf("\n");
            bas_gerant();
            scanf("%i",&choix);
        }
    }
}