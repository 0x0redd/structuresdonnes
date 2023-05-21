#include "pile.h"

void creerp(pile *p){
	(*p).ip=0;
}

int videp(pile p){
	if (p.ip) return 0;
	return 1;
}

int valeurp(pile p){
	if (!videp(p)) return p.tab_p[p.ip];
	printf("valeur non definie\n");
	exit(-1);
}

int ajouterp(int x,pile *p){
	(*p).ip++;
	if ((*p).ip < N) {
		(*p).tab_p[(*p).ip]=x;
		return 1;
	}
	printf("implementation insuffisante\n");
	exit(-1);
}

int supprimerp(pile *p){
	if (videp(*p)) {
		printf("suppression dans pile vide non definie\n");
		exit(-1);
	}
	(*p).ip--;
	return 1;
}

void aff_pile(pile p){//cette fonction viole les contraintes dâ€™accÃ¨s mais peut servir Ã  vÃ©rifier le contenu de la pile sans la modifier
	int i;
	for (i=1;(i<= p.ip);i++)
		printf("%c ",p.tab_p[i]);
	printf("\n");
	}
	
void remplir_pile(pile *p){
	int i;
	printf("remplir_pile_int\n");
	for (;;) {
		printf("donner un entier: (-1 pour arreter) :");
		scanf("%d",&i);
		if (i>=0) ajouterp(i,p);
		else break;	
	}
}