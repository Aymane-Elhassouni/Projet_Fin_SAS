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
    int nbAvions;
}Airoport;



Airoport AjouterAeroport(){
    Airoport A;
    printf("enter nome: ");
    scanf(" %[^\n]",A.nome);

    return A;
}

void AfficherListeAvions(Airoport A){
    Avion avi;
    int i;
    printf("nome: %s\n",A.nome);
    for(i=0;i<nbAvions;i++){
        printf("-------- Avions %d --------\n",A.flotte[i].id);
        printf("id: %d | modele: %s | capacite: %d | statu: %s | date d\'Entree: %d / %d / %d\n"
            ,A.flotte[i].id,A.flotte[i].modele,A.flotte[i].capacite,A.flotte[i].statut
        ,A.flotte[i].dateEntree.jour,A.flotte[i].dateEntree.mois,A.flotte[i].dateEntree.annee);
        
    }
}

Airoport ModifierAvion(Avion avi,Airoport A){
    AfficherListeAvions(A);
    char modele[20],statut[20];
    int i,j,id,capacite,found=0;
    
    while(j != 0){
        printf("enter Avion doi modifer: ");
        scanf("%d",&id);
       for(i=0;i<A.nbAvions;i++){
        if(A.flotte[i].id == id){
            found = 1;
            break;
        }
       }
        printf("1 - Modifier le modele \n");
        printf("2 - Modifier la capacite \n");
        printf("3 - Modifier le statut \n");
        scanf("%d",&j);
        switch(j){
            case 1:
            printf("enter le nouvelle modele de l'avion: ");
            scanf(" %[^\n]",A.flotte[i].modele);
            break;
            case 2:
            printf("enter le nouvelle capacite de l'avion: ");
            scanf("%d",A.flotte[i].capacite);
            break;
            case 3:
            printf("enter le nouvelle statut de l'avion(Disponible,En maintenance,En vol): ");
            scanf(" %[^\n]",A.flotte[i].statut);
            break;
        }
       
        
       
    }
    
    
    return A;

}

Avion AjouterAvion(Airoport A){
    Avion avi;
    int statut;
    avi.id = idAvion++;
    printf("enter modele de l'avion: ");
    scanf(" %[^\n]",avi.modele);
    printf("enter capacite de l'avion: ");
    scanf("%d",&avi.capacite);
    printf("enter statu de l'avion(Disponible,En maintenance,En vol): ");
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
    int i,found1=0,found=0;
    char modele[20];
    int ID;
    int choix;
    printf("1 - Recherch by id.\n");
    printf("2 - Recherch by modele.\n");
    printf("enter 1 ou 2: ");
    scanf("%d",&choix);
    switch(choix){
        case 1:
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
        break;
        case 2:
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
        break;
        
    }
    
    

    
    return A;
}



int main(){
    int choix=0,click=0;
    int i;
    Airoport airoport;
    Avion avi;
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
            while(click == 1){
                airoport = AjouteAeroportAvi(airoport);
                printf("1 - continue les avions.\n");
                printf("0 - finie les avions.\n");
                scanf("%d",&click);
            }
            break;
            case 2:
            airoport = ModifierAvion(avi,airoport);
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