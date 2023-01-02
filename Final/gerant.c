#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct{
    int id;
    char nom[64];
    double prix_unit;
    int stocks;
}produit;

void majuscule(char* mot){
    int i = 0;
    for (i = 0; mot[i] != '\0'; i ++){
        if (mot[i]  >= 'a' &&  mot[i] <= 'z')
         mot[i] -=  'a' - 'A';
    }
}

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

int add(produit* new){
    char nom[64];
    printf("Quel est le produit à ajouter ?\n");
    printf("\n");
    scanf(" %s",nom);
    int n = taille("stock");
    produit* tab = malloc(n*sizeof(produit));
    charge(tab,n,"stock");
    int i = 0;
    while(ordrealpha(tab[i].nom,nom)!=0 && i<n){
        i++;
    }
    if(i<n){
        char rep;
        printf("Voulez-vous changer le prix du produit ? (O)ui ou (N)on\n");
        printf("\n");
        scanf(" %c",&rep);
        printf("\n");
        majuscule(&rep);
        if(rep == 'O'){
            printf("Quel est le nouveau prix du produit ?\n");
            printf("\n");
            scanf("%lf",&tab[i].prix_unit);
        }
        char rep1;
        printf("Voulez-vous changer la quantité disponible ? (O)ui ou (N)on\n");
        printf("\n");
        scanf(" %c",&rep1);
        printf("\n");
        majuscule(&rep1);
        if(rep1 == 'O'){
            printf("Quel est le nouveau stock ?\n");
            printf("\n");
            scanf("%i",&tab[i].stocks);
            printf("\n");
        }
        sauvegarde(tab,n,"stock");
        return 0;
    }
    else{
        strcpy(new->nom,nom);
        printf("Quel est le prix du produit ?\n");
        printf("\n");
        scanf("%lf",&new->prix_unit);
        printf("Quel est la quantité en stock du produit ?\n");
        printf("\n");
        scanf("%i",&new->stocks);
        return 1;
    }
}

void enleve(produit* new, produit* new_copy, int n){
    int sup;
    printf("Quel est l'id du produit voulez-vous enlever ?\n");
    printf("\n");
    scanf("%i",&sup);
    int indice=0;
    while(new[indice].id != sup && indice<n){
        indice++;
    }
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