//////////////////////////////////
/*MORSE-CODE ENCRYPTOR AND	*/
/*DECRYPTOR			*/
/*Author: Enrico Di Benedetto	*/
/*Plese report any bug at	*/
/*enrico0014@gmail.com		*/
/*Main source code		*/
//////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codif.h"

int main(){
	printf("\t~ENCRYPTER-DECRYPTER MORSE CODE~");

	
	///*Crypted ords alphabet*///
	lettera_t *alfabeto = calloc(26,sizeof(lettera_t));

	/*Alphabet is charged by a specific config file*/
	FILE *fp;
	fp = fopen("morse.txt","r");
	carica_alfa(alfabeto,fp);
	fclose(fp);
	
	
	int enc=0,dec=0;
	char choice[2];
	char* stringa;	
	int LEN;
	do{
		printf("\nWhat do you wanna do?\n[a]Encrypt\n[b]Decrypt\n[q]Quit\n");
		do{
			printf(">");
			scanf("%s",choice);
			if(*choice!='a' && *choice!='b' && *choice!='q'){
				printf("Choice not permitted!\n");
			}
		}while(*choice!='a' && *choice!='b' && *choice!='q');
	
		switch(*choice){
			case 'a': enc = 1;dec=0; break;
			case 'b': dec = 1;enc=0; break;
			case 'q': enc=dec=0; break;
		}
	
		if(enc){
			stringa =insert_stringa();
			LEN = strlen(stringa);
			printf("The coded string is:\n");
			codifica(stringa,LEN,alfabeto);
		}else if(dec){
			stringa =insert_stringa();
			LEN = strlen(stringa);
			printf("The decoded string is:\n");
			decodifica(stringa,LEN,alfabeto);
		}
	}while(enc || dec);
	
	return 0;

}
