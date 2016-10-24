#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libresistance.h"

int main(int argc, char **argv) 
{
	float values[10];
	float value;
	char buf[100];
	int count=0;
	float result;
	char method;

	do {
		printf("Skriv S för seriekoppling, P för parrallellkoppling:");
		if (fgets(buf, sizeof(buf), stdin) != NULL){
			method = buf[0];
		}
	}while(method!='S' && method!='P');

	printf("Skriv ett valfritt antal resistanser som ska summeras.\n");
	printf("Ange <return> mellan varje tal, avsluta med <return>:\n");
	
  	while (fgets(buf, sizeof(buf), stdin) != NULL){
    		value = atof(buf);
		if (value==0){
			break;
		}
		values[count++] = value;
  	} 

	if (count==0){
		fprintf(stderr, "Inga resistanser angivna!\n");		
		exit(EXIT_FAILURE);
	}
 
	result = calc_resistance(count, method, values);
	if (result == -1){
		fprintf(stderr, "Felaktigt indata!\n");		
		exit(EXIT_FAILURE);
	}
	printf("Summan blev %f\n", result);

	exit(0);
}

