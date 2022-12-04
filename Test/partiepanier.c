#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct item_panier{
    int idProd;
    double quantite;
    struct item_panier* suivant;
}item_panier;

typedef struct panier{
struct item_panier* first; 
struct tm* date_ticket;
double total; 
int ticketid; 
int clientid; 
}panier;

// Creation d'un panier vide :
void panier_vide( panier *head){
    (head->first)=NULL;
}
item_panier * ajouteraupanier(panier *head ,int amount){
    item_panier *n;
    n=(item_panier *)malloc(sizeof(item_panier));
    (n->quantite)=amount;
    (n->suivant)=(head->first);
    (head->first)=n;
    }
item_panier * suppressionproduitdupanier(panier * head,int matricule){
     item_panier *n;
    // 1er cas si l'on veut supprimer article en fin de liste  
    // 2nd cas si l'on veut supprimer l'article en debut de liste 
    // 3rd cas si on veut supprimer l'article en position i de la liste
   
    // IL FAUDRA METTRE DES IF POUR SAVOIR DANS QUEL FONCTION ON RENTRE (Javais plus les idees clair donc je les ai pas mis pour pas  m embrouiller)
        // 1 // fonction qui supprime la fin d'une liste chainee :
        item_panier *temp;
        if((head->first)!=NULL){
            if((head->first->suivant)==NULL){
                free(head->first);
                (head->first)=NULL;
                                            }
            else {
                temp=(head->first);
                while((temp->suivant->suivant)!=NULL){
                    temp=(temp->suivant);             }
                    free(temp->suivant);
                    (temp->suivant)=NULL;
                                                    
                }
                               
                            }
        return (head->first); 
                                            
        // 2 // fonction qui supprime le debut d'une liste chainee :
        if((head->first)!=NULL){
            n=(head->first);
            (head->first)=(head->first->suivant);
            free(n);
                                }
            return (head->first);

        // 3// fonction qui supprime un element de position i: Je crois que ici il faut raisonner avec le matricule (l'id si tu preferes) de l'article en question comme une target
            item_panier *tmp,*P;
            if((head->first)!=NULL){
                    if((head->first->idProd)==matricule){
                            P=(head->first);
                            (head->first)=(head->first->suivant);
                            free(P);
                                                        }
                    else{
                        tmp=(head->first);
                        while((tmp->suivant)!=NULL && (tmp->suivant)->idProd!=matricule)
                        {
                            tmp=(tmp->suivant);
                        }
                        if((tmp->suivant)!=NULL)
                        {
                            P=(tmp->suivant);
                            (tmp->suivant)=(tmp->suivant->suivant);
                            free(P);
                        }
                        }
                                    }
                                    // return (head->first); Normalement c'est dans la fonction mais il faut d'abord creer le if qui nous oblige a passer dans cette partie de la fonction

}

void creation_d_un_panier_vide(){}
struct produit{
char nom[64]; 
double prix_unit; 
int stocks; 
 }product;

// item_panier * ajouterpanier(item_panier *debut,int amount,int matricule){ // On ajoute les elements les un apres les autres en les faisant passer au debut 
    // item_panier *A; // pointeur de type item panier prenant les infos pour les struct de type item_panier avant de le mettre au debut de la liste chainee
    // A=(item_panier *)malloc(sizeof(item_panier));
    // printf("Veuillez saisir la quantite a mettre au panier : ");
    // scanf("%d",&amount);
    // (A->quantite)=amount;
    // printf("Veuillez saisir l'id de l'article : ");
    // scanf("%d",&matricule);
    // (A->idProd)=matricule;
    // (A->suivant)=(debut); //** Pas sur , j'ai creer un pointeur debut de type item panier comme tete de liste mais quand je regarde la struct panier (plus precisement first ) je me dis que ca sert un peu a rien...Q
    // (panier->first)=(A->suivant);
    // return debut;
    // }
int main(){}



 
