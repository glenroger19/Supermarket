#include<stdio.h>
#include<time.h>
#include<string.h>

typedef struct tm date;

typedef struct{
    char nom[64];
    double prix_unit;
    int stocks;
}produit;

typedef struct item_panier{
    int idProd;
    double quantite;
    struct item_panier* suivant;
}item_panier;

typedef struct{
    item_panier* first;
    date* date_ticket;
    double total;
    int ticketid;
    int clientid;
}panier;

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
    FILE* stock = fopen("stock.csv","w");
    produit banane = {"Banane",1.30,20};
    produit pomme = {"Pomme",1.20,40};
    produit savon = {"Savon",3.30,100};
    fprintf(stock,"%s,%.2f,%i\n",banane.nom,banane.prix_unit,banane.stocks);
    fprintf(stock,"%s,%.2f,%i\n",pomme.nom,pomme.prix_unit,pomme.stocks);
    fprintf(stock,"%s,%.2f,%i\n",savon.nom,savon.prix_unit,savon.stocks);
    fclose(stock);
}

//Gérant
void add_stock(){
    FILE* stock = fopen("stock.csv","a");
    produit new;
    printf("Quel est le produit ?\n");
    scanf("%s",new.nom);
    printf("Quel est le prix du produit ?\n");
    scanf("%lf",&new.prix_unit);
    printf("Quel est la quantité en stock du produit ?\n");
    scanf("%i",&new.stocks);
    fprintf(stock,"%s,%.2f,%i\n",new.nom,new.prix_unit,new.stocks);
    fclose(stock);
}

void remove_stock(){
    FILE* stock = fopen("stock.csv","r");
    FILE* stock_new = fopen("stock_new.csv","w");
    produit rm;
    printf("Quel produit voulez-vous effacer ?\n");
    scanf("%s",rm.nom);
    remove_linebyline(stock,stock_new,rm);
    fclose(stock_new);
    remove("stock.csv");
    rename("stock_new.csv", "stock.csv");
}

int main(){
    stock();
    //add_stock();
    remove_stock();
}
