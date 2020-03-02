#include <stdio.h>

// Students were asked to draw diagrams depicting
// the state of memory at each highlighted points.


void func1(char g){
	int b = 5;
	g = 't';
	//what is the memory like here?    LINE 6
}
char func2(int a, double f){
	char g = 'g';
	a++; 
	// what is the memory like here?    LINE 11
	func1(g);
	return g;
}

int main(){
	
	int arr[] = {1,2};
	//char str[] = "hi"; // = {'h','i','\0'};
	int a = 3;
	
	char c = func2(a, 6.28); 
	// what is the memory like here?    LINE 22
	
}