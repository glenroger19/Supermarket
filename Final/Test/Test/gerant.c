#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
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

int taille(char* nomfichier){
    FILE* fich = fopen(nomfichier,"rb");
    fseek(fich,0,SEEK_END);
    int file_size = ftell(fich);
    int n = file_size/sizeof(produit);
    return n;
}

void charge(produit* tab,int n, char* nomfichier){
    FILE* fich = fopen(nomfichier,"rb");
    fread(tab,sizeof(produit),n,fich);
    fclose(fich);
}

void print_tab(produit* tab,int n){
    for(int i=0; i<n; i++){
        printf("%s %.2f %d\n",tab[i].nom,tab[i].prix_unit,tab[i].stocks);
    }
}

void add(produit* new){
    printf("Quels est le produit à ajouter ?\n");
    scanf("%s",new->nom);
    printf("Quel est le prix du produit ?\n");
    scanf("%lf",&new->prix_unit);
    printf("Quel est la quantité en stock du produit ?\n");
    scanf("%i",&new->stocks);
}

/*int add_bin(char* nomfichier){
    FILE* stock = fopen("stock","ab");
    produit* new = malloc(sizeof(produit));
    add(new);
    fwrite(new,sizeof(produit),1,stock);
    fclose(stock);
    free(new);
    char rep;
    printf("Voulez vous ajouter d'autres produits ?\n");
    printf("Choisir (O)ui ou (N)on\n");
    scanf("%s",&rep);
    if(rep=='N'){
        return 0;
    }
}*/

void enleve(produit* new, int n){
    char sup;
    printf("Quel produit voulez-vous enlever ?\n");
    scanf("%s",&sup);
    int indice=0;
    while(ordrealpha(new[indice].nom,&sup)!=0 && indice<n){
        indice++;
    }
    printf("%i\n",indice);
    /*for(int i=0;i<n-1;i++){
        if(i<indice){
            for(int j=0;j<strlen(new[i].nom);j++){
                new[i].nom[j] = new[i].nom[j];
            }
            new[i].prix_unit = new[i].prix_unit;
            new[i].stocks = new[i].stocks;
        }
        else{
            for(int j=0;j<strlen(new[i].nom);j++){
                new[i].nom[j] = new[i+1].nom[j];
            }
            new[i].prix_unit = new[i+1].prix_unit;
            new[i].stocks = new[i+1].stocks;
        }
    }*/
}

int main(){
    FILE* stock = fopen("stock","ab");
    produit* new = malloc(sizeof(produit));
    add(new);
    fwrite(new,sizeof(produit),1,stock);
    fclose(stock);
    free(new);
    int n = taille("stock");
    //add_bin("stock");
    produit* tab = malloc(n*sizeof(produit));
    charge(tab,n,"stock");
    print_tab(tab,n);
    enleve(tab,n);
    print_tab(tab,n-1);
    free(tab);
}