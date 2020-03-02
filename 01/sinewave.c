#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char** argv) {
	printf("Sinewave\n");
	
	int mode = 0;
	if (argc > 1){
		mode = atoi(argv[1]);
	}
	printf("mode: %d\n", mode);
	
	int  steps = 25;
	if (argc > 2){
		steps = atoi(argv[2]);
	}
	
	double pi = M_PI;
	int spaces;
	if (mode == 0){
		for(int i = 0; i < steps + 1; i++){
			//printf("%f\n", sin(i*2*pi/steps));
			spaces  = 10 + 5 * sin(i*2*pi/steps);
			for(int j = 0; j < spaces; j++){
				printf(" ");
			}
			printf("*\n");
		}
	}
	else{
		for(int i = 0; i < steps + 1; i++){
			//printf("%f\n", sin(i*2*pi/steps));
			spaces  = 10 + 5 * sin(i*2*pi/steps);
			for(int j = 0; j < 20; j++){
				if(j != spaces + 1 && j != 11){
					printf(" ");
				}else if(j == spaces + 1){
					printf("*");
				}else{
					printf("|");
				}
			}
			if (spaces < 10){
				
			}
			printf("\n");
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	double test = 5/2;
	printf("test result: %f\n", test);
}