#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    char nom[64];
    double prix_unit;
    int stocks;
}produit;

int taille_fich(char* nomfichier){
    FILE* fich = fopen(nomfichier,"rb");
    fseek(fich,0,SEEK_END);
    int file_size  = ftell(fich);
    int n = file_size/sizeof(produit);
    return n;
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

void stock(){
    FILE* stock = fopen("stock","w+");
    produit tab[256] = {{"Banane",1.30,20},{"Pomme",1.20,40},{"Savon",3.30,100}};
    fwrite(tab,sizeof(produit),3,stock);
    fclose(stock);
}

void add(){
    FILE* stock = fopen("stock","ab");
    produit* new = malloc(sizeof(produit));
    printf("Quel est le produit ?\n");
    scanf("%s",new->nom);
    printf("Quel est le prix du produit ?\n");
    scanf("%lf",&new->prix_unit);
    printf("Quel est la quantité en stock du produit ?\n");
    scanf("%i",&new->stocks);
    fwrite(new,sizeof(produit),1,stock);
    fclose(stock);
    free(new);
}

void charge(int n, char* nomfichier){
    FILE* fich = fopen(nomfichier,"rb");
    produit* copietab = malloc(n*sizeof(produit));
    fread(copietab,sizeof(produit),n,fich);
    for(int i =0; i<n; i++){
        printf("%s %.2f %d\n",copietab[i].nom,copietab[i].prix_unit,copietab[i].stocks);
    }
    fclose(fich);
}

int main(){
    //stock();
    add();
    int n = taille_fich("stock");
    charge(n,"stock");
}
