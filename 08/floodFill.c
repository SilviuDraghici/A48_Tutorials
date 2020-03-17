#include<stdio.h>
#include<stdlib.h>

void printImgArray(char array[10][10])
{
 // Print out the contents of the array, it can be
 // used with the original array, or with the labeled
 // output after calling cell_count().
  
 printf("------ Image Contents -------\n");
 for (int i=0; i<10; i++)
 {
   printf("        |");
   for (int j=0; j<10; j++)
     printf("%c",array[i][j]);
   printf("|\n");
 }
 printf("-----------------------------\n");
}

void floodFill(char image[10][10], int r, int c, char value, char bound)
{
 // This function takes as input a 2D image array
 // which contains pixel values. 
 //
 // It floodFills (if you haven't tried floodfill,
 // open up a picture editor and use the paint tool!)
 // starting at location (r,c), filling the image
 // with the specified 'value', up to (but not
 // including) the boundary of the shape in the
 // picture, whose colour is given by 'bound'
 //
 // This function should do its work NON-recursively!
  
 // TO DO: Complete this function!

}

void floodFill_R(char image[10][10], int r, int c, char value, char bound)
{
 // This function takes as input a 2D image array
 // which contains pixel values. 
 //
 // It floodFills (if you haven't tried floodfill,
 // open up a picture editor and use the paint tool!)
 // starting at location (r,c), filling the image
 // with the specified 'value', up to (but not
 // including) the boundary of the shape in the
 // picture, whose colour is given by 'bound'
 //
 // This function should do its work recursively!
 
 
  if (r < 0 || r >= 10) return; //out of bounds
  if (c < 0 || c >= 10) return; // out of bounds
  if (image[r][c] == bound) return; // at chacter boundary
  if (image[r][c] == value) return; // this stops it from infinitely going back
                                    // and forth over the same area
									// (stack overflow)
  
  //printf("(%d, %d)\n", r, c); <- I used this to debug
  image[r][c] = value;
  
  //These are the recursive calls, they 
  floodFill_R(image, r - 1, c    , value, bound);
  floodFill_R(image, r + 1, c    , value, bound);
  floodFill_R(image, r    , c - 1, value, bound);
  floodFill_R(image, r    , c + 1, value, bound);
 
}

int main()
{
  char polyImg[10][10]={{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                        {' ',' ','X',' ',' ',' ',' ','X',' ',' '},
                        {' ','X',' ','X',' ',' ','X',' ','X',' '},
                        {' ','X',' ',' ','X',' ','X',' ','X',' '},
                        {' ',' ','X',' ','X','X',' ',' ','X',' '},
                        {' ',' ','X',' ',' ',' ',' ','X','X',' '},
                        {' ','X',' ',' ',' ','X',' ','X',' ',' '},
                        {' ',' ','X',' ','X','X',' ',' ','X',' '},
                        {' ',' ',' ','X',' ',' ','X','X','X',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};
  printf("Original Image:\n");
  printImgArray(polyImg);             
  
  floodFill_R(polyImg, 5, 4, 'a', 'X');
  printf("\nFlood Fill starting at (5,4):\n");
  printImgArray(polyImg);
  
  char polyImg2[10][10]={{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ',' ','X',' ',' ',' ',' ','X',' ',' '},
                         {' ','X',' ','X',' ',' ','X',' ','X',' '},
                         {' ','X',' ',' ','X',' ','X',' ','X',' '},
                         {' ',' ','X',' ','X','X',' ',' ','X',' '},
                         {' ',' ','X',' ',' ',' ',' ','X','X',' '},
                         {' ','X',' ',' ',' ','X',' ','X',' ',' '},
                         {' ',' ','X',' ','X','X',' ',' ','X',' '},
                         {' ',' ',' ','X',' ',' ','X','X','X',' '},
                         {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};
  floodFill_R(polyImg2, 3, 0, 's', 'X');
  printf("\nFlood Fill starting at (3,0):\n");
  printImgArray(polyImg2);
  
  
  return 0;
}

