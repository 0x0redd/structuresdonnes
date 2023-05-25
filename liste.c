#include<stdio.h>
#include<stdlib.h>

typedef struct cellule{ 
    int val;
    struct cellule *lien;
}cellule;
//Allocation mémoire pour une cellule
cellule *creer_cellule(){
    cellule *c;
    c=(cellule *) malloc(1*sizeof(cellule));
    c->lien=NULL;
    return c;
}
//test de la liste vide 
int vide(cellule *p) {return (p==NULL);}
//Affectation d’une information à une cellule
void remplir(cellule *p){
    int x;
    printf("donner un entier: "); scanf("%d",&x);
    (*p).val=x;
}
// affichage du contenu dune liste 

void afficher_liste(cellule *liste){
    cellule *p=liste; // p est le pointeur de parcours
    while(p!=NULL){ 
        printf(" %d",(*p).val);
        p=p->lien;
    }
    printf("\n");
}
//Affichage de la valeur des pointeurs (adresses) de la liste
void afficher_liste_p(cellule *liste){
    cellule *p=liste;
    while(p!=NULL){
        printf(" %p %d %p\n",p,(*p).val,p->lien);
        p=p->lien;
    }
    printf("\n");
}
//Calcul de la longueur d’une liste chaînée (nombre de cellules existantes dans la liste)
int longueur(cellule *p){
    cellule *q=p;
    int c=0;
    while (q!=NULL) {
        c++; 
        q=q->lien;
    }
    return c;
}
//Insertion d’une cellule en début de liste
cellule *inserer_debut(cellule *liste,cellule *c) {
    c->lien=liste;
    liste=c;
    return liste;
}
//Insertion d’une cellule en fin de liste
cellule *inserer_fin(cellule *liste,cellule *c) {
    if (vide(liste)) 
        liste=c;
    else {
        cellule *q=liste;
        while(q->lien != NULL) 
            q=q->lien;
        q->lien =c;
    }
    return liste;
}
//Rechercher une information dans la liste
cellule *recherche_elt(int x,cellule *liste){
    cellule *p=liste;
    while ((p!=NULL) && ((*p).val !=x)) 
        p=p->lien;
    if (p == NULL) 
        return NULL;
    return p;
}
//Suppression d’un élément de la liste
cellule *recherche_elt_s(int x,cellule *liste){
    cellule *p=liste,*pp=NULL;
    while((p!=NULL) && (*p).val!=x){
    pp=p;
    p=p->lien;
    }
    return  p;
}

cellule *supprimer(cellule *liste,int x){
    cellule *pp,*p;
    if(liste==NULL) return NULL;
    if ((*liste).val==x){
        q=liste;
        liste=liste->lien;
        free(q);
        return liste;
    }
    if ((pp=recherche_elt_s(x,liste))->lien==NULL)
        printf("non trouve \n");
    else{
        q=pp->lien;
        pp->lien=q->lien;
        free(q);
        return liste;
    }
}
//Insertion d’un élément dans une liste triée :
cellule *recherche_precedent(int x,cellule *liste){

    // cas où l’insertion doit se dérouler en début de liste

    if ((liste==NULL) || ((*liste).val >x)) 
        return NULL;

    // cas où l’insertion doit se dérouler au milieu ou en fin de liste
    
    cellule *pp=liste;
    cellule *p=liste->lien;

    while ((p!=NULL)&&((*p).val <=x)) {
        pp=p;
        p=p->lien;
    }
    return pp;
}

cellule *inserer(cellule *liste,cellule *c){
    cellule *p,*pp;
    if (c==NULL) return liste ;
        pp=recherche_precedent((*c).val,liste);
    p=liste;
    if ((p==NULL)||(pp==NULL)) 
        liste=inserer_debut(liste,c);
    else {
        c->lien=pp->lien;
        pp->lien=c;
    }
    return liste;
}