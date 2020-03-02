#include <stdio.h>

// the definition is at the bottom
void reverse(char *input); 

int main(){
	// (this compiles and runs)
	char mystr[1024] = "gnirtS drawkcaB A";
	
	reverse(mystr);
	
	printf("reversed string: %s \n", mystr);
	
}


































void reverse(char *input){
	int len = 0;
	char *ptr = input;
	// this is basically just an implementation of strlen
	while(*ptr != '\0'){
		len++;
		ptr++;
	}
	
	//this sawps the first and last characters and then moves inwards, repeating
	//the process half as many times as the length of the string
	char temp;
	for(int i = 0; i < len/2; i++){
		temp = input[len - 1 - i];
		input[len - 1 - i] = input[i];
		input[i] = temp;
		
	}
}