#include <stdio.h>

int main()
 {
	// this program demonstrates that the assignment operator '='
	// is not defined for arrays in c
	// (this does not compile)
    int  array_one[10];
    int  array_two[5];

    // Fill in some values for array two
    for (int i=0; i<5; i++)
    {
       array[i]=i;
    }

    array_one=array_two;      // What should happen here?
 }
   