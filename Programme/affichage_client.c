#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include"gerant.h"
#include"caissier.h"
#include"client.h"

void entete_client(char* page){
    printf("\e[1;1H\e[2J");
    printf("=========================================================================================================================================================\n");
    printf("                                                                     %s\n",page);
    printf("=========================================================================================================================================================\n");
    printf("\n");
    printf("\n");
    printf("                    1 - Ajouter un produit dans le panier\n");
    printf("                    2 - Enlever un produit dans le panier\n");
    printf("                    3 - Afficher mon panier\n");
    printf("                    4 - Montrer et payer ma reçu\n");
    printf("                    5 - Quitter le mode caissier\n");
    printf("\n");
}

void bas_client(){
    printf("Veuillez choisir ce que vous allez faire :\n");
    printf("\n");
}

int taille1(char* nomfichier){
    FILE* fich = fopen(nomfichier,"rb");
    fseek(fich,0,SEEK_END);
    int file_size = ftell(fich);
    int n = file_size/sizeof(panier);
    return n;
}

void receipt(panier* p){
    time_t timestamp = time(NULL);
    date* date = localtime(&timestamp);
    client* tab = malloc((taille_c("base_client")+1)*sizeof(client));
    charge_c(tab,taille_c("base_client")+1,"base_client");
    FILE* compta = fopen("compta.csv","a+");
    int n = taille1("compta.csv");
    p->ticketid = n+1;
    p->date_ticket = date;
    printf("    Date : %4d-%02d-%02d\n",p->date_ticket->tm_year+1900, p->date_ticket->tm_mon+1, p->date_ticket->tm_mday);
    printf("    TicketID : %i\n",p->ticketid);
    printf("    ClientID : %i\n",p->clientid);
    printf("\n");
    printf("\n");
    printf("Quantité                                                            Désignation                                   Prix Unitaire en euros\n");
    printf("\n");
    affiche_panier(p);
    printf("                                                                                                                  Total HT : %.2lf euros\n",p->total*(1-(20/(double)100)));
    printf("                                                                                                                  Total TTC : %.2lf euros\n",p->total);
    if(p->clientid!=0){
        for(int i=0; i<taille_c("base_client")+1; i++){
            if(tab[i].id_client == p->clientid){
                printf("                                                                Votre ancienne cagnotte est de : %.2lf euros\n",tab[i].cagnotte);
                tab[i].cagnotte = tab[i].cagnotte + p->total*0.005; 
                printf("                                                                Votre nouvelle cagnotte est de : %.2lf euros\n",tab[i].cagnotte);
            }
        }
        change_c(tab,taille_c("base_client")+1,"base_client");
    }
    fprintf(compta,"%4d-%02d-%02d;%i;%i;%.2lf\n",date->tm_year+1900, date->tm_mon+1, date->tm_mday,p->ticketid,p->clientid,p->total);
    fclose(compta);
}

void affichage_client(int identifiant){
    panier* p = panier_init();
    p->clientid = identifiant;
    entete_client("MODE CAISSIER");
    bas_client();
    int choix;
    scanf("%i",&choix);
    while(choix!=5){
        if(choix==1){
            entete_client("AJOUTER AU PANIER");
            int n = taille("stock");
            produit* tab = malloc(n*sizeof(produit));
            charge(tab,n,"stock");
            print_tab(tab,n);
            free(tab);
            printf("\n");
            panier_add(p);
            printf("\n");
            bas_client();
            scanf("%i",&choix);
        }
        if(choix==2){
            entete_client("ENLEVER PRODUIT");
            printf("\n");
            affiche_panier(p);
            printf("\n");
            panier_remove(p);
            printf("\n");
            entete_client("MODE CAISSIER");
            bas_client();
            scanf("%i",&choix);
        }
        if(choix==3){
            entete_client("MON PANIER");
            printf("Quantité                                                            Désignation                                   Prix Unitaire en euros\n");
            affiche_panier(p);
            printf("\n");
            bas_client();
            scanf("%i",&choix);
        }
        if(choix==4){
            entete_client("RECU");
            receipt(p);
            printf("\n");
            bas_client();
            scanf("%i",&choix);
            choix = 5;
        }
    }
}