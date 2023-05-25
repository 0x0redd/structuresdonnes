//Implémenter une file d’attente circulaire avec une liste chainée.
#include <stdio.h>
#include <stdlib.h>
typedef struct cellule {
    int val;
    cellule *lien;
}cellule;

int videfc(cellule *p ){return (p==NULL)}

cellule *creer_cellulefc(){
    cellule *c;
    if ((c=(cellule*) malloc(1*sizeof(cellule)))==NULL){
        printf("impossible de creer une cellule \n");
        exit(-1);
    }
    c->lien=NULL;
    return c; 
}

cellule *ajouterfc(int x,cellule *f){
    cellule *q=creer_cellulefc(),*p;
    (*q).val=x;
    if(f==NULL){
        f=q;
        q->lien=f;
    }
    else{
        p=f->lien;
        f->lien=q;
        q->lien=p;
        f=q;
    }
    return f;
}

cellule suprimerfc(cellule *f){
    if (f==NULL){
        printf("suppression non definie sur file vide\n");
        exit(1);
    }
    cellule *q=f->lien;
    if (q!=f)
        f->lien = q->lien;
    else{
        free(f);
        return (cellule*) NULL;
    }
    free(q);
    return f;
}

int valeurfc(cellule *f){
    if (f!=NULL) 
        return (*(f->lien)).val;
    printf("valeur non definie sur pile vide\n");
    exit(1);
}

void afficher_listefc(cellule *f){
    cellule *p=f;
    if(p==NULL){
        printf("affichage non definie sue file vide\n");
        exit(1);
    }
    p=p->lien;
    while(p!=f){
        printf("%d",(*p).val);
        p=p->lien;
    }
    printf("%d"(*p).val);
    printf("\n");
    getchar();
}

