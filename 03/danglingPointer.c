#include <stdio.h>

int main(){
	// A dangling pointer is a pointer without a memory address to point to.
	// the pointer x has not been pointed at any variable.
	// Trying to de-reference the pointer (*x) will access a 
	// random location in memory.
	// The location accessd will probably be outside of the programs
	// memory, resulting in a segfault.
	// (this program compiles and crashes at runtime)
	int *x;
	
	*x += 1;
	
	printf("x: %d\n", *x);
	
}