//////////////////////////////////
/*MORSE-CODE ENCRYPTOR AND	*/
/*DECRYPTOR			*/
/*Author: Enrico Di Benedetto	*/
/*Plese report any bug at	*/
/*enrico0014@gmail.com		*/
/*Library header		*/
//////////////////////////////////

typedef struct {
		char lettera_cod[2];
		char codifica[5];

		}lettera_t;
		
void carica_alfa(lettera_t *alfabeto, FILE *fp);

char* insert_stringa();

void codifica(char* stringa, int LEN, lettera_t* alfabeto);

void decodifica(char* stringa, int LEN, lettera_t* alfabeto);
