//Bibliotek 3, test program for libcomponent.so, Burleigh HT16
#include <stdio.h>

//declarations
int findresistors(float orig_resistance, float *res_array);
float res_array[3]; 
int answer;
 
//main program
int main(void){
	//user input to test code
	while(1){
		float orig_resistance;                                                                                                                                                                             
		printf("Enter a resistor value: ");                                                                                                                                                                
		scanf("%f", &orig_resistance); 
		answer = findresistors(orig_resistance, res_array);
		int j;
		for (j = 0; j < 3; j++) printf("%f  ", res_array[j]);
		printf("\nThus %d resistors are needed (value of count).\n\n",  answer);		
	}
}
