#include <stdio.h>
#include <stdlib.h>

double func1(int a, int *b);
double func2(int p, int *q);

void   func3(int a, double (*func)(int x, int *y));

int main(){
// (this compiles and runs)
// this is the syntax for a function pointer: 	
//<return_type> (*<pointer_name>) (<function_arguments>);
	double (*func_pointer)(int x, int *y);
	func_pointer = &func1;
	
	int a = 5, b = 10;
    double result;
	
	result = (*func_pointer)(a, &b);                                                          printf("\n");
	
	func_pointer = &func2;
	result = (*func_pointer)(a, &b);                                                          printf("\n");
	
	func3(a, func_pointer);                                                                   printf("\n");
	
	func3(a, &func1);
}

double func1(int a, int *b){
	printf("Function 1\n");
	return drand48();
}

double func2(int p, int *q){
	printf("Function 2\n");
	return drand48();
}

int funci(int p, int *q){
	printf("Function 2\n");
	return drand48();
}

void func3(int a, double (*func)(int x, int *y)){
	// this function takes a function pointer as input
	printf("Function 3\n");
	(*func)(a, &a);
	
}