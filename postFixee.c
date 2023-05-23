#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#include <stdlib.h> 
#include "pile.h" 

#define TBLOC 8 
char *lireChaine()  { 
 	int taille = TBLOC; 
 	char *buffer = (char *) malloc(taille*sizeof(char)); 
 	char *p=buffer; 
 	printf("taper une phrase ou un mot: "); 
 	for (;;) { /* boucle de lecture */  
 		if ((*p=getchar()) == '\n'){ 
 			/* lecture d'un \n */  
 			if ((p==buffer) || (*(p-1) != '\\'))
 				break; 
 			p--; /* annulation du \n (precede de \)*/
 			continue; 
 		}
		if (++p == buffer + taille) { 
			/* Agrandissement de la memoire de lecture*/ 
			buffer= (char *) realloc(buffer,taille+TBLOC); 
		  	p=buffer+taille; 
		  	taille += TBLOC; 
		} 
	}
	*p='\0'; /*Allocation d'un zone de la taille de la chaine*/ 
	p= (char *)malloc(p-buffer+1); 
	strcpy(p,buffer); /*liberation de la memoire intermediaire*/ 
	free(buffer); 
	return p; 
}
int operande(char x){ 
	 if (((x>='a') &&(x<='z')) || ((x>='A') && (x<='Z')))
	 	return 1;
	 if (isdigit(x))
	 	return 1; 
 return 0; 
}
int prio(char x) { 
	switch (x) { 
		case '(' : return 0; 
		case '+':  
		case '-': return 1;  
		case '*': 
		case '/': return 2;
		case '^':{return 3; break;} 
		default: {printf("erreur d''operateur\n");getchar();exit(1);}  } 
} 
void postfixee(char *e){ 
  pile p; 
  char x=e[0]; 
  int i=0; 
 	creerp(&p); 
 	ajouterp('(',&p); 
	for (i=1;x != '\0';i++) { 
		if (operande(x))
			printf("%c",x); 
 		else if (x=='(')
 			ajouterp(x,&p); 
		else if (x==')') { 
			while(valeurp(p)!='(') { 
 		 		printf("%c",valeurp(p)); 
 				supprimerp(&p);
 			} 
 		supprimerp(&p);
		}else { 
 			while(prio(valeurp(p)) >= prio(x)) { 
 				printf("%c",valeurp(p));
 				supprimerp(&p); 
			} 
 			printf(" "); 
 			ajouterp(x,&p); 
	 	} 
 		x=e[i]; 
 	}  
 	while (valeurp(p)!='(') { 
 		printf("%c",valeurp(p)); 
		supprimerp(&p); 
 	}  
  printf("\n"); 
} 
int main(){ 
	char *s=lireChaine(); 
	postfixee(s); 
}
