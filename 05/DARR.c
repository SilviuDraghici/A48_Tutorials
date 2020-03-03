// Dynamic Arrays for Restaurant Reviews (DARR)
// F. Estrada, Feb 2020

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STR_LEN 1024

typedef struct review_struct
{
    char name[MAX_STR_LEN];
    int score;
} review;

typedef struct dyn_array_struct
{
    // Here we will keep a pointer to the reviews array,
    // the size of this array, and the index of the next
    // entry to be added whenever the user wants to input
    // a new review.

    review *all_reviews;        
    int size;                   
    int index;    

} dyn_array;

int init_array(dyn_array *the_array, int size)
{
    // This function should reserve memory for an array of reviews
    // with the specified size, then use the pointer to the 
    // dyn_array to update the fields in the dyn_array CDT.
    //
    // You should expect to need calloc(). 
    // Question: Since calloc() sets the whole chunk of memory to
    // contain zeros, what will be the *value* of the name strings
    // for the reviews in the array? what wil be the scores for the
    // reviews? (it may help if you draw the array!)
    //
    // Return value: 
    //  0 - If the function completed successfully
    //  1 - If something went wrong (out of memory)
    
	review *array  = (review *)calloc(size, sizeof(review));
	the_array->all_reviews = array;
	the_array->size = size;
    
    return 0;
}

int add_review(dyn_array *the_array)
{
    // This function reads information for a new review from the terminal
    // and inserts it into the array.
    //
    // Return value:
    // 0 - If the review was successfully added
    // 1 - If something went wrong (e.g. out of memory!)
    
    char name[MAX_STR_LEN];
    int score;
    review *current_review=NULL;
    review *new_reviews_array=NULL;
    
    // ADD code below to prompt the user to input the restaurant's name
    // and the score, and read them into the 'name' and 'score' variables
    // defined above.
    
	printf("Input restaurant name:\n");
	fgets(name, MAX_STR_LEN, stdin);
	
	printf("Input restaurant score:\n");
	scanf("%d", &score);
	getchar();
	
	if(the_array->index >= the_array->size){
		the_array->size = the_array->size * 2;
		printf("size: %d\n", the_array->size);
		review *new_array = (review*)calloc(the_array->size, sizeof(review));
		for(int i = 0; i < the_array->index; i++){
			new_array[i] = the_array->all_reviews[i];
		}
		free(the_array->all_reviews);
		the_array->all_reviews = new_array;
	}
	
	current_review = &(the_array->all_reviews[the_array->index]);
	strcpy(current_review->name, name);
	current_review->score = score;
	
	the_array->index++;
    
     return 0;    
}

int main()
{
    dyn_array review_DB={NULL,0,0};
    review one_review;
    
    if (init_array(&review_DB,1))
    {
        printf("Unable to intialize array :(\n");
        return 1;
    }

    // Let's add 10 reviews - we expect the array to
    // resize when we insert reviews at index 1, 2, 4, and 8
    for (int i=0; i<5; i++)
    {
        printf("Inserting a review at index %d\n\n",review_DB.index);
        if (add_review(&review_DB))
        {
            printf("Out of memory!\n");
            return 1;
        }
    }
    
    // Let's print out our reviews and make sure they're all there
    // Because the review_DB is a nested CDT, accessing it directly requires
    // some ugly syntax. So to make it easier, we'll just copy the entry we
    // want to print to a regular review variable.
    for (int i=0; i<review_DB.index; i++)
    {
        one_review=*(review_DB.all_reviews+i);    // review_DB.all_reviews is a pointer :)
                                                  // we use an offset to get the review at
                                                  // index i, and then copy 'the contents of'
                                                  // that locker to our review variable.
                                                  
        printf("Restaurant name: %s -->score=%d\n",one_review.name,one_review.score);
        
        // If you're curious about the ugly syntax way to do this (without copying
        // it to a review variable, it's shown below)
        // printf("Restaurant name %s, score=%d\n",(*(review_DB.all_reviews+i)).name,(*(review_DB.all_reviews+i)).score);
    }
    
    // Done! let's release the memory we reserved and exit.
    free(review_DB.all_reviews);
    return 0;
}