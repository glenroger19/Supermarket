#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    int choix=0;
    do{
        printf("***********************************************************************************\n");      
        printf("***********************   Bienvenue   *********************************************\n");
        printf("****Choisissez le mode : (1) Caissier ou (2) Gerant ou (3) Quitter le programme *** \n");
        printf("\nVotre choix : ");
        scanf("%d",&choix);
        switch(choix)
        {   
            
            case 1 :{;break;};
            case 2 :{;break;};
            case 3 :{;break;};
            
            
            default  : printf("Nous n'avons pas compris votre choix, recommencez svp\n");
        
        }
    }while(choix!=0);

    void modecaissier(){
        int choix2;
        printf("***********************************************************************************\n");      
        printf("***********************  Mode CAISSIER  *******************************************\n");
        printf("***********************************************************************************\n");
        printf("Appuyez sur :\n");
        printf("1) Pour demarrer un nouveau ticket");
        printf("2) Pour revenir au menu principal");
        scanf("%d",&choix2);
        switch(choix2)
        {   
            
            case 1 :{;break;};
            case 2 :{;break;};
        
            default  : printf("Nous n'avons pas compris votre choix, recommencez svp\n");
        }
        printf("Saisissez :\n");
        printf("\t\t\t-un entier XXX correspondant a l'ID du produit\n");
        int XXX;
        printf("\t\t\t-PXXX/YYY pour un produit au poids (XXX etant l'ID et YYY le poids\n");
        float PXXX/YYY;
        printf("\t\t\t-PANIER pour afficher le panier en cours\n");
        printf("\t\t\t-FIN pour finir la commande\n");
        printf("\t\t\t-GERANT pour basculer en mode GERANT\n");
        char mot[10];
               
        }
    
    
    void modegerant(){
        int choix3;
        printf("***********************************************************************************\n");      
        printf("***********************  Mode CAISSIER  *******************************************\n");
        printf("***********************************************************************************\n");
        printf("1) Voir la liste des produits en stocks\n");
        printf("2) Modifier un produit\n");
        printf("3) Ajouter un nouveau produit catalogue\n");
        printf("4) Afficher compta\n");
        printf("Quitter le mode Gerant\n")
        
        switch(choix3)
        {   
            
            case 1 :{;break;};
            case 2 :{;break;};
            case 3 :{;break;};
            case 4 :{;break;};
            case 5 :{;break;};
            
        
            default  : printf("Nous n'avons pas compris votre choix, recommencez svp\n");
        }
    }
}