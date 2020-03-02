#include <stdio.h>

// the function is defined at the bottom
void pokeAround(char *p);

int main()
  {
	// this program demonstrates that variables defined next to each other are
	// next to each other in memory (in theory)
	// Also, it is possible for a function to access variables not directly
	// passed to it using pointers
	// (this compiles and runs)
	char  oneStr[1024]="I am string ONE!";
	char  twoStr[1024]="I am string TWO!";
	char  c='C';
	char  d='*';
	char  e='!';
	char  f='@';
	int   x=65;

	pokeAround(&twoStr[0]);
  }
































  void pokeAround(char *p){
	 // this function should be able to access all the variables defined in main
	 // Whether or not this works varies from one computer to the next.
	 char *ptr;
	 printf("string One: %s\n", p - 1024);
	  
	 ptr=p;
	 
	 //printf("char c: %c\n", *(p + 1024));
  }
