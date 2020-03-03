#include <stdio.h>
#include <stdlib.h>

void print_data(int *data, int size);

int main(){
  // this program demonstrated a memory leak when line 21 "free(data)"
  // a memory leak is a block of data without a pointer.
  // if a malloced (or calloced) block is not freed the operating system
  // will not release it until the program terminates.
  // was not included
  // (this can be compiled and run)
  int mem_size = 2;
  int * data = (int *)calloc(mem_size, sizeof(int));
  data[0] = 1, data[1] = 2;
  print_data(data, mem_size);
	
  int *bigger_data = (int *)calloc(2*mem_size, sizeof(int));
  for(int i = 0 ; i < mem_size; i++){
	bigger_data[i] = data[i];
  }
  mem_size *=2;
  
  free(data); //<- don't forget this 
  data = bigger_data;
  print_data(data, mem_size);
}

void print_data(int *data, int size){
	printf("Data: { ");
	for (int i = 0; i < size; i++){
		printf("%d ", data[i]);
	}
	printf("}\n");
}
