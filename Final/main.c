#include<stdio.h>
#include<stdlib.h>
#include"gerant.h"
#include"client.h"
#include"affichage_gerant.h"
#include"affichage_client.h"

int main(){
    printf("\e[1;1H\e[2J");
    printf("=========================================================================================================================================================\n");
    printf("                                                                        BIENVENUE \n");
    printf("=========================================================================================================================================================\n");
    printf("\n");
    printf("\n");
    printf("                    Choisir entre mode (C)aissier, mode (G)erant ou bien (Q)uitter\n");
    printf("\n");
    printf("\n");
    char choix = 0;
    scanf(" %c",&choix);
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
            affichage_client();
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
        scanf(" %c",&choix);
        majuscule(&choix);
    }
}