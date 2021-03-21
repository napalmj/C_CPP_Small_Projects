/*********************************************
 * Nathaniel
 *
 * Determines minimum distance between a group of numbers
 *********************************************/

#include<stdlib.h>
#include<stdio.h>

// finds the distance from x to y
int diff(int x, int y);

int main(int argc, char *argv[])
{
   if(argc < 3)
   {
      printf("More than 1 digit required as input\nFor example:\n");
      printf("%s 2 4 6\n", argv[0]);
      return 1;
   }

   int dmin = diff(atoi(argv[1]), atoi(argv[2]));

   int i, j;

   for(i = 1; i<argc; i++)
   {
      for(j = 1; j<argc; j++)
      {
         if(i != j && diff(atoi(argv[i]), atoi(argv[j])) < dmin)
         {
            dmin = diff(atoi(argv[i]), atoi(argv[j]));
         }
      }
   }

   printf("%d\n",dmin);
   return 0;

}

// finds the distance from x to y
int diff(int x, int y)
{
   int result = x - y;
   if(result < 0)
   {
      result = y-x;
   }
   return result;
}

