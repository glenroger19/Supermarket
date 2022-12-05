#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

typedef struct tm date;

typedef struct{
    char nom[64];
    double prix_unit;
    int stocks;
}produit;

void binaire(FILE* f_in,char* nomfichier){
    FILE* f_out = fopen(nomfichier,"wb");
    fseek(f_in,0,SEEK_END);
    int file_size = ftell(f_in);
    char* tampon = malloc(file_size*sizeof(produit));
    rewind(f_in);
    fread(tampon,sizeof(produit),ftell(f_in),f_in);
    fwrite(tampon,sizeof(produit),ftell(f_in),f_out);
    fclose(f_out);
    free(tampon);
}

void remove_linebyline(FILE* f_in, FILE* f_out, produit p){
    int remove = strlen(p.nom);
    char line[512];
    int stop = 0;
    int cores = 0;
    while(fgets(line,512,f_in)!=NULL){
        for(int i=0;i<remove;i++){
            if(line[i]==p.nom[i]);
            cores++;
        }
        if(cores!=remove){
            fputs(line,f_out);
        }
    }
}

void stock(){
    FILE* stock = fopen("stock.txt","wb");
    produit banane = {.nom="Banane",.prix_unit=1.30,.stocks=20};
    produit pomme = {.nom="Pomme",.prix_unit=1.20,.stocks=40};
    produit savon = {.nom="Savon",.prix_unit=3.30,.stocks=100};
    fprintf(stock,"%s,%.2f,%i\n",banane.nom,banane.prix_unit,banane.stocks);
    fprintf(stock,"%s,%.2f,%i\n",pomme.nom,pomme.prix_unit,pomme.stocks);
    fprintf(stock,"%s,%.2f,%i\n",savon.nom,savon.prix_unit,savon.stocks);
    fclose(stock);
}

//Gérant
void add_stock(){
    FILE* stock = fopen("stock","ab");
    produit new;
    printf("Quel est le produit ?\n");
    scanf("%s",new.nom);
    printf("Quel est le prix du produit ?\n");
    scanf("%lf",&new.prix_unit);
    printf("Quel est la quantité en stock du produit ?\n");
    scanf("%i",&new.stocks);
    produit* tampon = &new;
    fwrite(tampon,sizeof(produit),ftell(stock),stock);
    //fprintf(stock,"%s,%.2f,%i\n",new.nom,new.prix_unit,new.stocks);
    fclose(stock);
}

void remove_stock(){
    FILE* stock = fopen("stock","rb");
    FILE* stock_new = fopen("stock_new","w");
    produit rm;
    printf("Quel produit voulez-vous effacer ?\n");
    scanf("%s",rm.nom);
    remove_linebyline(stock,stock_new,rm);
    fclose(stock_new);
    remove("stock");
    rename("stock_new", "stock");
}


void charge(char* tab, int n, char* nomfichier){
    FILE* fich = fopen(nomfichier,"rb");
    /*fseek(fich,0,SEEK_END);
    int file_size  = ftell(fich);
    int n = file_size/sizeof(produit);
    printf("%i\n",n);*/
    fread(tab,sizeof(produit),n,fich);
    fclose(fich);
}

int taille_fich(char* nomfichier){
    FILE* fich = fopen(nomfichier,"rb");
    int file_size  = ftell(fich);
    int n = file_size/sizeof(produit);
    return n;
}

int main(){
    stock();
    FILE* stock = fopen("stock.txt","r");
    binaire(stock,"stock");
    //add_stock();
    //remove_stock();
    int n = 3;
    char* tab = malloc(n*sizeof(produit));
    charge(tab,n,"stock");
    printf("%s\n",tab);
}
