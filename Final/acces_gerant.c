#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"gerant.h"

typedef struct{
    char login[64];
    char mdp[64];
}compte;

int taille_compte(char* nomfichier){
    FILE* fich = fopen(nomfichier,"rb");
    fseek(fich,0,SEEK_END);
    int file_size = ftell(fich);
    int n = file_size/sizeof(compte);
    return n;
}

void sauvegarde_compte(compte* tab, int n, char* nomfichier){
    FILE* f = fopen(nomfichier,"w");
    fwrite(tab,sizeof(compte),n,f);
    fclose(f);
}

void sauvegarde_add_compte(compte* tab, int n, char* nomfichier){
    FILE* f = fopen(nomfichier,"ab");
    fwrite(tab,sizeof(compte),n,f);
    fclose(f);
}

void charge_compte(compte* tab,int n, char* nomfichier){
    FILE* fich = fopen(nomfichier,"rb");
    fread(tab,sizeof(compte),n,fich);
    fclose(fich);
}

int accces_gerant(){
    char login[64];
    char mdp[64];
    printf("Entrer votre login : \n");
    printf("\n");
    scanf("%s",login);
    printf("\n");
    printf("Entrer votre mot de passe : \n");
    printf("\n");
    scanf("%s",mdp);
    compte* com = malloc(taille("base_employe")*sizeof(compte));
    charge_compte(com,taille("base_employe"),"base_employe");
    int n = 0;
    while(n<taille("base_employe")){
        if(ordrealpha(com[n].login,login)==0 && ordrealpha(com[n].mdp,mdp)==0){
            return 1;
        }            
        n++;
    }
    printf("\n");
    printf("Login ou mot de passe non trouvé\n");
    printf("\n");
    free(com);
}
