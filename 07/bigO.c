#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	//(this compiles and runs)
	// use: ./bigO 'int size'
	int N = 0;
	if (argc > 1){
		N = atoi(argv[1]);
	} else {
		printf("use: ./bigO 'int size'\n");
		return 1;
	}
	int steps_1 = 0;
	// What is the big O of this nested loop?
	// N * 4 * N = O(N^2)
	for(int i  = 0; i < N; i++){
		for(int j = 0; j < 4; j++){
			for(int k = 0; k < N; k++){
				steps_1 += 1;
			}
		}
	}
	printf("O(N^2) Steps: %d\n", steps_1);
	
	// What is the big O of this loop?
	// 64 = O(1)
	int steps_2 = 0;
	for(int i = 0; i < 64; i++){
		steps_2 += 1;
	}
	printf("\nO(1) Steps: %d\n", steps_2);
	
	// What is the big O of this loop?
	// (2/3) * N * 5 = O(N)
	int steps_3 = 0;
	for(int i = 0; i < (2.0/3) * N; i++){
		steps_3 += 5;
	}
	printf("\nO(N) Steps: %d\n", steps_3);
	
	// Whats the big O of the overall function?
	// (N * 4 * N) + (64) + ((2/3) * N * 5) = O(N^2) 
	printf("\nTotal Steps: %d + %d + %d = %d\n", steps_1, steps_2, steps_3,
                                                 steps_1 + steps_2 + steps_3);
}