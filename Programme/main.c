#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include"gerant.h"
#include"caissier.h"
#include"affichage_gerant.h"
#include"affichage_client.h"
#include"client.h"

int main(){
    srand(time(NULL));
    int taille = taille_c("base_client");
    client* c = malloc((taille+1)*sizeof(client));
    printf("\e[1;1H\e[2J");
    printf("=========================================================================================================================================================\n");
    printf("                                                                        BIENVENUE \n");
    printf("=========================================================================================================================================================\n");
    printf("\n");
    printf("\n");
    printf("                    Choisir entre mode (C)aissier, mode (G)erant ou bien (Q)uitter\n");
    printf("\n");
    printf("\n");
    char choix;
    scanf("%c",&choix);
    majuscule(&choix);
    while(choix!='C' && choix!='G' && choix!='Q'){
        printf("Mauvaise manipulation merci de ressaisir :\n");
        printf("\n");
        printf("\n");
        scanf(" %c",&choix);
        majuscule(&choix);
    }
    while(choix!='Q'){
        if(choix=='C'){
            int identifiant = affichage_id(c);
            affichage_client(identifiant);
        }
        if(choix=='G'){
            affichage_gerant();
        }
        printf("\e[1;1H\e[2J");
        printf("=========================================================================================================================================================\n");
        printf("                                                                        BIENVENUE \n");
        printf("=========================================================================================================================================================\n");
        printf("\n");
        printf("\n");
        printf("                    Choisir entre mode (C)aissier, mode (G)erant ou bien (Q)uitter\n");
        printf("\n");
        printf("\n");
        scanf("%c",&choix);
        majuscule(&choix);
    }
}