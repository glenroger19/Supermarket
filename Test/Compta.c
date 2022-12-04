#include<stdio.h>

void s_compta(void){
    FILE* fich;
    fich = fopen("Compta.csv","w");
    fprintf(fich,"Date,TicketID,ClienID,TOTAL\n");
    fclose(fich);
}

void ajout_compta(void){
    FILE* fich;
    fich = fopen("Compta.csv","a");
    s_compta();
    fprintf(fich,"10-08-22,1444,664515,200");
    fclose(fich);
}

void main(){
    ajout_compta();
}