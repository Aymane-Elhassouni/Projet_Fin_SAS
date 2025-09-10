#include <stdio.h>
#include <string.h>

typedef struct{
    int jour;
    int mois;
    int annee;
}Date;

typedef struct {
    char modele[20];
    int capacite;
    char statut[20];
    Date dateEntree;
}Avion;

typedef struct {
    char nome[20];
    Avion flotte[20]; 
    int nbAvions;
}Airoport;



Airoport AjouterAeroport(){
    Airoport A;
    printf("enter nome: ");
    scanf(" %[^\n]",A.nome);

    return A;
}

Avion AjouterAvion(Airoport A){
    Avion avi;
    int i;
    printf("pour finie les avions click sur 0\n");
    printf("pour continue les avions click sur 1\n");
    while(i != 0){
    printf("enter modele de l'avion: ");
    scanf(" %[^\n]",avi.modele);
    printf("enter capacite de l'avion: ");
    scanf("%d",&avi.capacite);
    printf("enter statu de l'avion: ");
    scanf(" %[^\n]",avi.statut);
    printf("enter jeur entree de l'avion: ");
    scanf("%d",&avi.dateEntree.jour);
    printf("enter mois entree de l'avion: ");
    scanf("%d",&avi.dateEntree.mois);
    printf("enter annee entree de l'avion: ");
    scanf("%d",&avi.dateEntree.annee);
    printf("enter 0 ou 1: ");
    scanf("%d",&i);
    }
    return avi;
}
int main(){
    int choix=0,click=0;
    Airoport airoport;
    
     
    do{
        printf("-------- MENU --------\n");
        printf("1 - Ajouter Airoport.\n");
        scanf("%d",&choix);

        if(choix == 1){
            airoport = AjouterAeroport();
            while(click != 200){
          
          printf("-------- MENU --------\n");
          printf("1 - Ajouter un avion (ou plusieurs).\n");
          printf("2 - Modifier un avion.\n");
          printf("3 - Supprimer un avion.\n");
          printf("4 - Afficher la liste des avions.\n");
          printf("5 - Rechercher un avion.\n");
          printf("6 - Trier les avions.\n");
          scanf("%d",&click);
          switch(click){
            case 1 :
            AjouterAvion(airoport);
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            break;
          }
        
         } 
        }
        else if(choix != 1);

        
        
        
    }while(choix != 200);

      
    return 0;
}