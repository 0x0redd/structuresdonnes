#include"file.h"
	
void creerf( file *f){
	(*f).it=(*f).iq=0;
}
int videf(file f){
	if (f.it==f.iq)
		return 1;
	return 0;
}
int valeurf(file f){
	if (!videf(f))
		return f.tab_f[f.it+1];
	printf("valeur non dÃ©finie\n");
	exit(-1);
}	
	
	
int ajouterf(int x,file *f){
	(*f).iq++;
	if ((*f).iq < N) {
		(*f).tab_f[(*f).iq]=x;
		return 1;
	}	
	printf("implementation insuffisante\n");
	exit(-1);
}
int supprimerf(file *f){
	if (videf(*f)) {
		printf("suppression dans pile vide non definie\n");
		exit(-1);
	}
	(*f).it++;
	return 1;
}
int aff_file(file f){ //cette fonction viole les contraintes dâ€™accÃ¨s mais peut servir Ã  vÃ©rifier le contenu de la file sans la modifier
	int i;
	if (videf(f)) {
		printf("file vide\n");
		return 0;
	}
	printf("tete de file = %d\n",valeurf(f));
	for (i=f.it+1;(i<= f.iq);i++)
		printf("%d ",f.tab_f[i]);
	printf("\n");
}
void remplir_file(file *f){
	int i;
	printf("remplir_file_int\n");
	for (;;) {
		printf("donner un entier: (-1 pour arreter) :");
		scanf("%d",&i);
		if (i>=0)
			ajouterf(i,f);
		else break;
	}
}	
