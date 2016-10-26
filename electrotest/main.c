#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libresistance/libresistance.h"

int main(int argc, char **argv) 
{
	float* values;  // Pekare till array med värden
	float value;
	char buf[100];
	int count=0;
	float result;
	char method;
	int loop;

	/* Kopplingstyp */
	do {
		printf("Ange koppling [S|P]: ");
		if (fgets(buf, sizeof(buf), stdin) != NULL){
			method = buf[0];
		}
	}while(method!='S' && method!='P');

	/* Antal komponenter */
	do {
		printf("Antal komponenter: ");
		if (fgets(buf, sizeof(buf), stdin) != NULL){
			count = atoi(buf);
		}
	}while(count<=0);

	/* Reservera plats för komponenterna */
	values = malloc(sizeof(int)*count);

	/* Läs in komponenterna */
	for (loop=0 ; loop<count ; loop++){
		printf("Komponent %d i ohm: ", loop+1);
  		if (fgets(buf, sizeof(buf), stdin) != NULL){
    			value = atof(buf);
			if (value==0){
				count = loop;
				printf("Avbryter inmatningen. %d resistanser angivna.\n", count);
				break;
			}
			values[loop] = value;
 	 	} 
	}

	if (count==0){
		fprintf(stderr, "Inga resistanser angivna. Avslutar!\n");		
		goto error;
	}
 
	result = calc_resistance(count, method, values);
	if (result == -1){
		fprintf(stderr, "Felaktigt indata!\n");		
		goto error;
	}
	printf("Ersättningsresistans:\n %.1f ohm\n", result);
	goto cleanup;

cleanup:
	free(values);
	exit(0);

error:
	free(values);
	exit(EXIT_FAILURE);

}

