#include <stdio.h>

int main(){
	// this program demonstares () precedence
	// (this program can be compiled and run)
	int arr[] = {5, 10};
	
	// 1 is added to the array pointer and then it is dereferenced
	// equivalent to x = arr[1]
	int x = *(arr + 1);
	
	// arr is dereferenced and then 1 is added to the integer
	// equivalent to y = arr[0] + 1
	int y = *arr + 1;
	
	printf("x: %d\n", x);
	printf("y: %d\n", y);
}