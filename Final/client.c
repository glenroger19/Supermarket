#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include"gerant.h"

typedef struct{
    char nom[64];
    char prenom[64];
    int id_client;
}client;

void delay(int i){ //code pris sur internet
    clock_t start,end;
    start=clock();
    while(((end=clock())-start)<=i*CLOCKS_PER_SEC);
}

int taille_c(char* nomfichier){
    FILE* fich = fopen(nomfichier,"a+");
    fseek(fich,0,SEEK_END);
    int file_size = ftell(fich);
    int n = file_size/sizeof(client);
    return n;
}

void charge_c(client* tab,int n, char* nomfichier){
    FILE* fich = fopen(nomfichier,"rb");
    fread(tab,sizeof(client),n,fich);
    fclose(fich);
}

void sauvegarde_c(client* tab, int n, char* nomfichier){
    FILE* f = fopen(nomfichier,"ab");
    fwrite(tab,sizeof(client),n,f);
    fclose(f);
}

int identifiant_c(){
    FILE* fich = fopen("base_client","a+");
    int taille = taille_c("base_client");
    client* c = malloc((taille+1)*sizeof(client));
    charge_c(c,taille+1,"base_client");
    int id = 1+(rand()/(double)RAND_MAX)*(9999);
    int n = 0;
    while(n<taille+1){
        if(id==c->id_client){
            identifiant_c();
        }
        n++;
    }
    return id;
}

void print_c(client* tab,int n){
    for(int i=0; i<n; i++){
        printf("                %i                       %s                           %s\n",tab[i].id_client,tab[i].nom,tab[i].prenom);
    }
}

int affichage_id(client* c){
    int identifiant;
    int taille = taille_c("base_client");
    charge_c(c,taille+1,"base_client");
    char rep;
    int count=0;
    printf("\e[1;1H\e[2J");
    printf("=========================================================================================================================================================\n");
    printf("                                                                     CLIENT\n");
    printf("=========================================================================================================================================================\n");
    printf("\n");
    printf("Avez-vous un identifiant ? (O)ui ou (N)on\n");
    printf("\n");
    scanf(" %c",&rep);
    majuscule(&rep);
    printf("\n");
    int quitter = 0;
    while(quitter!=1){
        if(rep=='O'){
            int id;
            printf("\n");
            printf("Entrer votre identifiant : ");
            scanf("%i",&id);
            printf("\n");
            for(int i=0; i<taille+1; i++){
                if(c[i].id_client == id){
                    printf("Bienvenue %s\n",c[i].nom);
                    identifiant = id;
                    quitter = 1;
                    delay(5);
                }
            }
            if(quitter != 1){
                printf("Votre identtifiant n'existe pas\n");
                printf("\n");
                if(count<3){
                    printf("Réessayer s'il vous plait\n");
                    rep = 'O';
                    count++;
                }
                else{
                    rep = 'N';
                    quitter = 1;
                }
            }
        }
        else{
            char rep1;
            printf("Voulez-vous créer un compte ? (O)ui ou (N)on\n");
            printf("\n");
            scanf(" %s",&rep1);
            printf("\n");
            majuscule(&rep1);
            if(rep1 == 'O'){
                char nom[64];
                char prenom[64];
                printf("Entrer votre nom : ");
                scanf("%s",nom);
                strcpy(c->nom,nom);
                printf("\n");
                printf("Entrer votre prénom : ");
                scanf("%s",prenom);
                strcpy(c->nom,prenom);
                printf("\n");
                identifiant = identifiant_c();
                printf("Voici votre identifiant : %i, merci de le mémoriser \n",identifiant);
                c->id_client = identifiant;
                sauvegarde_c(c,1,"base_client");
                quitter = 1;
                delay(10);
            }
            else{
                identifiant = 0;
                quitter = 1;
            }
        }
    }
    return identifiant;
}