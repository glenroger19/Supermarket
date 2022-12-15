#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct{
    int id;
    char nom[64];
    double prix_unit;
    int stocks;
}produit;

int ordrealpha(const char* s1,const char* s2){
    int n = strlen(s2);
    for(int i=0;i<n+1;i++){
        if(s1[i]>s2[i]){
            return -1;
        }
        else if(s1[i]<s2[i]){
            return 1;
        }
    }
    return 0;
}


void tri(produit* tab, int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(tab[i].id>tab[j].id){
                int a = tab[i].id;
                char b[64];
                strcpy(b, tab[i].nom);
                double c = tab[i].prix_unit;
                int d = tab[i].stocks;
                tab[i].id = tab[j].id;
                strcpy(tab[j].nom,tab[i].nom);
                tab[i].prix_unit = tab[j].prix_unit;
                tab[i].stocks = tab[j].stocks;
                tab[j].id = a;
                strcpy(tab[j].nom,b);
                tab[j].prix_unit = c;
                tab[j].stocks = d;
            }
        }
    }
}

int taille(char* nomfichier){
    FILE* fich = fopen(nomfichier,"rb");
    fseek(fich,0,SEEK_END);
    int file_size = ftell(fich);
    int n = file_size/sizeof(produit);
    return n;
}

void sauvegarde_add(produit* tab, int n, char* nomfichier){
    FILE* f = fopen(nomfichier,"ab");
    fwrite(tab,sizeof(produit),n,f);
    fclose(f);
}

void sauvegarde(produit* tab, int n, char* nomfichier){
    FILE* f = fopen(nomfichier,"w");
    fwrite(tab,sizeof(produit),n,f);
    fclose(f);
}

void charge(produit* tab,int n, char* nomfichier){
    FILE* fich = fopen(nomfichier,"rb");
    fread(tab,sizeof(produit),n,fich);
    fclose(fich);
}

void print_tab(produit* tab,int n){
    printf("                ID                  Nom du produit                  Prix unitaire                    Quantité\n");
    for(int i=0; i<n; i++){
        printf("                %i                       %s                           %.2f                            %d\n",tab[i].id,tab[i].nom,tab[i].prix_unit,tab[i].stocks);
    }
}

void add(produit* new){
    printf("Quel est l'id du produit à ajouter ?\n");
    scanf("%i",&new->id);
    printf("Quel est le produit à ajouter ?\n");
    scanf("%s",new->nom);
    printf("Quel est le prix du produit ?\n");
    scanf("%lf",&new->prix_unit);
    printf("Quel est la quantité en stock du produit ?\n");
    scanf("%i",&new->stocks);
}

void enleve(produit* new, produit* new_copy, int n){
    int sup;
    printf("Quel est l'id du produit voulez-vous enlever ?\n");
    scanf("%i",&sup);
    int indice=0;
    while(new[indice].id != sup && indice<n){
        indice++;
    }
    printf("%i\n",indice);
    for(int i=0;i<n-1;i++){
        if(i<indice){
            new_copy[i].id = new[i].id;
            strcpy(new_copy[i].nom,new[i].nom);
            new_copy[i].prix_unit = new[i].prix_unit;
            new_copy[i].stocks = new[i].stocks;
        }
        else{
            new_copy[i].id = new[i].id;
            strcpy(new_copy[i].nom,new[i+1].nom);
            new_copy[i].prix_unit = new[i+1].prix_unit;
            new_copy[i].stocks = new[i+1].stocks;
        }
    }
}