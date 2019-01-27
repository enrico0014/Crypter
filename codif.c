//////////////////////////////////
/*MORSE-CODE ENCRYPTOR AND	*/
/*DECRYPTOR			*/
/*Author: Enrico Di Benedetto	*/
/*Plese report any bug at	*/
/*enrico0014@gmail.com		*/
/*Library source code		*/
//////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEM 500

typedef struct {
		char lettera_cod[2];
		char codifica[5];

		}lettera_t;

void carica_alfa(lettera_t *alfabeto, FILE *fp){
	char c;
	for(int k=0;k<26;k++){
		for(int i=0;i<2;i++){
			alfabeto[k].lettera_cod[i] = 0;
		}
		for(int i=0;i<5;i++){
			alfabeto[k].codifica[i] = 0;
		}
	}	
	int i=0,j=0;
	while(fscanf(fp,"%c",&c)>0){
		if(c>47 && c!='\t' && c!='\n'){
			alfabeto[i].lettera_cod[0] = c;
			alfabeto[i].lettera_cod[1] = c + 32;
		}else if(c==45 || c==46){
			alfabeto[i].codifica[j] = c;
			j++;
		}
		if(c=='\n'){
			i++;
			j=0;
		}
	}
}

char* insert_stringa(){
	
	/*Inserisco la stringa su cui lavorare*/
	char* input = malloc(MEM*sizeof(*input));
	printf("Insert string,please:\n");
	do{
		input[MEM-1] = '\0';
		getchar();
		fgets(input,MEM,stdin);
		if(input[MEM-1] != '\0'){
			printf("Reached the maximum of %d characters!\n",MEM);
		}
	}while(input[MEM-1] != '\0');
	int LEN = strlen(input)-1;
	char* stringa = calloc(LEN,sizeof(*stringa));
	for(int i=0;i<LEN;i++){
		stringa[i] = input[i];
	}
	free(input);
	
	return stringa;
}

void codifica(char* stringa, int LEN, lettera_t* alfabeto){
	int buff=0;
	while(buff<LEN){
		switch(stringa[buff]){
			case 'a': case 'A': printf("%s  ",alfabeto[0].codifica); break;
			case 'b': case 'B': printf("%s  ",alfabeto[1].codifica); break;
			case 'c': case 'C': printf("%s  ",alfabeto[2].codifica); break;
			case 'd': case 'D': printf("%s  ",alfabeto[3].codifica); break;
			case 'e': case 'E': printf("%s  ",alfabeto[4].codifica); break;
			case 'f': case 'F': printf("%s  ",alfabeto[5].codifica); break;
			case 'g': case 'G': printf("%s  ",alfabeto[6].codifica); break;
			case 'h': case 'H': printf("%s  ",alfabeto[7].codifica); break;
			case 'i': case 'I': printf("%s  ",alfabeto[8].codifica); break;
			case 'j': case 'J': printf("%s  ",alfabeto[9].codifica); break;
			case 'k': case 'K': printf("%s  ",alfabeto[10].codifica); break;
			case 'l': case 'L': printf("%s  ",alfabeto[11].codifica); break;
			case 'm': case 'M': printf("%s  ",alfabeto[12].codifica); break;
			case 'n': case 'N': printf("%s  ",alfabeto[13].codifica); break;
			case 'o': case 'O': printf("%s  ",alfabeto[14].codifica); break;
			case 'p': case 'P': printf("%s  ",alfabeto[15].codifica); break;
			case 'q': case 'Q': printf("%s  ",alfabeto[16].codifica); break;
			case 'r': case 'R': printf("%s  ",alfabeto[17].codifica); break;
			case 's': case 'S': printf("%s  ",alfabeto[18].codifica); break;
			case 't': case 'T': printf("%s  ",alfabeto[19].codifica); break;
			case 'u': case 'U': printf("%s  ",alfabeto[20].codifica); break;
			case 'v': case 'V': printf("%s  ",alfabeto[21].codifica); break;
			case 'w': case 'W': printf("%s  ",alfabeto[22].codifica); break;
			case 'x': case 'X': printf("%s  ",alfabeto[23].codifica); break;
			case 'y': case 'Y': printf("%s  ",alfabeto[24].codifica); break;
			case 'z': case 'Z': printf("%s  ",alfabeto[25].codifica); break;
			default: printf("STOP  "); break;
		}
		
		buff++;
	}
	printf("\n");
}

void decodifica(char* stringa, int LEN, lettera_t* alfabeto){
	int i=0,j;
	int buff=0;
	char* temp = calloc(5,sizeof(*temp));
	while(buff<LEN){
		j=0;
		while(stringa[buff] != 32 && stringa[buff] != 0){
			temp[j] = stringa[buff];
			j++;
			buff++;
		}
		for(int k=0;k<26;k++){
			if(strcmp(temp,alfabeto[k].codifica)==0){
				printf("%c",alfabeto[k].lettera_cod[1]);
				break;
			}
		}
		buff++;
		for(int k=0;k<5;k++){
			temp[k] = 0;
		}
	}
	printf("\n");
}
