#include <stdio.h>
#include <string.h>

// the function definition is at the bottom
void strswap(char s1[], char *s2);
// notice that 'varname[]' and '*varname' are equivalent

int main(int argc, char** argv){
	// (this program can be compiled and run)
	char a[1024];
	char b[1024];
	
	strcpy(a, "Hello");
	strcpy(b, "Goodbye");
	
	printf("string a: %s\n", a);
	printf("string b: %s\n", b);
	
	strswap(a, b);
	
	printf("string a: %s\n", a);
	printf("string b: %s\n", b);
	
}


// char c;
// (c == '\0') !?















































void strswap(char *s1, char *s2){
	// cntr counts the number of '\0' that have been encountered
	int cntr = 0;
	
	// steps counts the number of swaps made by the algorithm
	int steps = 0;
	
	char temp;
	
	// the loop exits when both '\0' have been encountered.
	// the function does not need to know the string lengths
	while(cntr < 2){
		temp = s1[steps];
		s1[steps] = s2[steps];
		s2[steps] = temp;
		if (s1[steps] == '\0' || s2[steps] == '\0'){
			cntr++;
		}
		steps++;
	}
	
	printf("\nSwap completed in %d steps\n\n", steps + 1);
}