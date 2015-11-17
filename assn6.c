//Miranda Workman and Cody Kellogg
//Assignment 6: Block Access Algorithms

/* Promise of Originality
I promise that this source code file has, in its entirety, been
written by myself or a member of my group and by no other person or
persons. If at any time an exact copy of this source code is found to
be used by another person outside my group in this term, I understand
that all members of my group and the members of the group that
submitted the copy will receive a zero on this assignment.
*/

#include"assn6.h"
#include<stdio.h>
#include<stdlib.h>

#define MAX_INPUT (100)
int count;

int
main (int argc, char *argv[])
{
  printf
    ("Assignment 6: Block Access Algorithm\nBy: Miranda Workman and Cody Kellogg\n\n");

  FILE *fp = stdin;
  if (argc == 2)
    {
      fp = fopen (argv[1], "r");
    }
  if (!fp)
    {
      perror ("Problem opening file.");
      return -1;
    }
  int input[MAX_INPUT];
//  int i;

//  while (fscanf (fp, "%d", &input[i]) == 1)
//    ++i;

while (fscanf (fp, "%d", &input[count]) == 1) count++;

  fcfs (count, input);
  sstf (count, input);
  look (count, input);
  clook (count, input);

  return 0;
}
