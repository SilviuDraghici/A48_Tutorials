#include <stdio.h>

int main(int argc, char** argv){
	
	// this loop demonstrates that although c allows you to
	// go out of the bounds of an array, eventually the pointer
	// will go out of the bounds of the program's memory, resulting
	// in a segfault.
	// (This program can be compiled and run)
	
	int array[] = {1,2,3};
	for(int i = 0; i < 100000000000000000000; i++){
		printf("index : %d \n\n", i);
		printf("array value: %d \n", array[i]);	
	}
}
