#include <stdio.h>


int main(){
    int choix;
    
    do{
        printf("-------- MENU --------\n");
        printf("1 - Ajouter Aeroport.\n");
        scanf("%d",&choix);
        printf("1 - Ajouter un avion (ou plusieurs).\n");
        printf("2 - Modifier un avion.\n");
        printf("3 - Supprimer un avion.\n");
        printf("4 - Afficher la liste des avions.\n");
        printf("5 - Rechercher un avion.\n");
        printf("6 - Trier les avions.\n");
        scanf("%d",&choix);
    }while(choix != 0);

      
    return 0;
}