#include <stdio.h>

struct my_struct{
	int n;
	char c;
	char str[10];
};

int main(){
	// declare a struct variable and use . 
	// to access it's fields
	struct my_struct s;
	s.n = 11;
	printf("s.n: %d\n", s.n);
	
	// struct pointers use -> to access fields
	struct my_struct *s_p = &s;
	s_p->n += 1;
	printf("s.n: %d\n", s.n);
	
	int *ip = &(s_p->n);
	
	// you can make arrays of structs
	struct my_struct struct_arr[10];
	struct_arr[0].n = 42;
	
}