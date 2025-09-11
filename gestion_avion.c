#include <stdio.h>
#include <string.h>

int idAvion = 1;
int idAiroport = 1;
int nbAvions = 0;

typedef struct{
    int jour;
    int mois;
    int annee;
}Date;

typedef struct {
    int id;
    char modele[20];
    int capacite;
    char statut[20];
    Date dateEntree;
}Avion;

typedef struct {
    int id;
    char nome[20];
    Avion flotte[50];
}Airoport;



Airoport AjouterAeroport(){
    Airoport A;
    printf("enter nome: ");
    scanf(" %[^\n]",A.nome);

    return A;
}

void AfficherListeAvions(Airoport A){
    int i;
    printf("nome: %s\n",A.nome);
    for(i=0;i<nbAvions;i++){
        printf("-------- Avions %d --------\n",A.flotte[i].id);
        printf("id: %d | modele: %s | capacite: %d | statu: %s | date d\'Entree: %d / %d / %d\n",A.flotte[i].id,A.flotte[i].modele,A.flotte[i].capacite,A.flotte[i].statut
        ,A.flotte[i].dateEntree.jour,A.flotte[i].dateEntree.mois,A.flotte[i].dateEntree.annee);
        
    }
}

Avion AjouterAvion(Airoport A){
    Avion avi;
        avi.id = idAvion++;
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
    return avi;
}



Airoport AjouteAeroportAvi(Airoport A){
    A.flotte[nbAvions] = AjouterAvion(A);
    nbAvions++;
    return A;
}

Airoport RechercherAvion(Airoport A){
    int ID,i,found1=0,found=0;
    char modele[20];
    int choix;
    printf("enter 1 ou 2: ");
    scanf("%d",&choix);
    switch(choix){
        case 1:
        break;
        case 2:
        
    }
    
    printf("enter de l'avion doi rechercher: ");
    scanf("%d",&ID);
    for(i=0;i<nbAvions;i++){
        if(A.flotte[i].id == ID){
            found = 1;
            break;
        }
    }
    if(found == 1){
        printf("l'avion %d est prisent\n",ID);
        printf("-------- Avions %d --------\n",ID);
        printf("id: %d | modele: %s | capacite: %d | statu: %s | date d\'Entree: %d / %d / %d\n",A.flotte[i].id,A.flotte[i].modele,A.flotte[i].capacite,A.flotte[i].statut
        ,A.flotte[i].dateEntree.jour,A.flotte[i].dateEntree.mois,A.flotte[i].dateEntree.annee);
    }

    printf("enter le modele de l'avion:");
    scanf(" %[^\n]",modele);
    for(i=0;i<nbAvions;i++){
        if(strcmp(A.flotte[i].modele,modele) == 0){
            found1 = 1;
            break;
        }
    }
    if(found1 == 1){
        printf("l'avion %s est prisent\n",modele);
        printf("-------- Avions %d --------\n",ID);
        printf("id: %d | modele: %s | capacite: %d | statu: %s | date d\'Entree: %d / %d / %d\n",A.flotte[i].id,A.flotte[i].modele,A.flotte[i].capacite,A.flotte[i].statut
        ,A.flotte[i].dateEntree.jour,A.flotte[i].dateEntree.mois,A.flotte[i].dateEntree.annee);
    }
    return A;
}

Airoport ModifierAvion(Airoport A){
    printf("enter le modele de l'avion: ");

}

int main(){
    int choix=0,click=0;
    int i;
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
             while(i != 0){
                airoport = AjouteAeroportAvi(airoport);
                printf("pour continue les avions click sur un nombre.\n");
                printf("pour finie les avions click sur 0.\n");
                printf("enter 0 ou 1: ");
                scanf("%d",&i);
            }
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            AfficherListeAvions(airoport);
            break;
            case 5:
            airoport = RechercherAvion(airoport);
            break;
          }
        
         } 
        }
        else if(choix != 1);

        
        
        
    }while(choix != 200);

      
    return 0;
}