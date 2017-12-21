#include <stdio.h>
#include "myscanner.h"

extern int yacclexo();
extern int yacclinha;
extern char* yacctexto;

char *names[] = {NULL, "db_type", "db_name", "db_table_prefix", "db_port"};

int main(void) 
{

	int ntoken, vtoken;

	ntoken = yacclexo();
	while(ntoken) {
		printf("%d\n", ntoken);
		if(yacclexo() != COLON) {
			printf("Erro de Sintaxe na linha %d, Esperava um ':' mas encontrou %s\n", yacclinha, yacctexto);
			return 1;
		}
		vtoken = yacclexo();
		switch (ntoken) {
		case TYPE:
		case NAME:
		case TABLE_PREFIX:
			if(vtoken != IDENTIFIER) {
				printf("Erro de sintaxe na linha %d, Esperava um identificador, mas encontrou %s\n", yacclinha, yacctexto);
				return 1;
			}
			printf("%s Está setado para %s\n", names[ntoken], yacctexto);
			break;
		case PORT:
			if(vtoken != INTEGER) {
				printf("Erro de sintaxe na linha %d, Esperava um inteiro, mas encontrou %s\n", yacclinha, yacctexto);
				return 1;
			}
			printf("%s Está setado para %s\n", names[ntoken], yacctexto);
			break;
		default:
			printf("Erro de Sintaxe na linha %d\n",yacclinha);
		}
		ntoken = yacclexo();
	}
	return 0;
}
