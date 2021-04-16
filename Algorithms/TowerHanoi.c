/*********************************************
 * Id: palm8836
 *
 * Tower of Hanoi algorithm which moves values from one side to the other side
 *********************************************/

#include<stdio.h>
#include<stdlib.h>

//hanoi algorithm 
void tower_of_hanoi(int n_disks, char from_peg, char to_peg, char with_peg);

int main(int argc, char *argv[])
{  
   int n = atoi(argv[1]);
   //function call
   tower_of_hanoi(n,'A','C','B');
   //So I got it to work by switching the B and C but I can't figure out how to get it work with A, B, C
   //Super frustrated it's not working. Not sure what I'm doing wrong here.

   return 0;
}

//hanoi algorithm
void tower_of_hanoi(int n_disks, char from_peg, char to_peg, char with_peg)
{
   if(n_disks == 1)
   {
      printf("MOVE %c TO %c\n", from_peg, to_peg);
      return;
   }
   else if(n_disks > 1)
   {
      tower_of_hanoi((n_disks - 1), from_peg, with_peg, to_peg);
      printf("MOVE %c TO %c\n", from_peg, to_peg);
      tower_of_hanoi((n_disks - 1), with_peg, to_peg, from_peg);
   }
}

