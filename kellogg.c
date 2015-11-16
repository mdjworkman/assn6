//Code writer: Cody Kellogg
//Group project
//CS 3060-601 Fall 2015
//Assignment #6

/* Promise of Originality
I promise that this source code file has, in it's entirety, been
written by myself and by no other person or persons. If at any time an
exact copy of this source code is found to be used by another person in
this term, I understand that both myself and the student that submitted
the copy will receive a zero on this assignment.
*/

void
fcfs (int count, int *input)
{
  int complete = 0;
  int i = 0;
//  int j=1;
//  int head = input[0];
  int seek = 0;

  while (complete < count - 1)
    {

      if (input[i] > input[i + 1])
	{
	  seek += input[i] - input[i + 1];
	}
      else
	{
	  seek += input[i + 1] - input[i];
	}
      i++;
      complete++;

    }

  printf ("FCFS Total Seek: %d\n", seek);
}

look (int count, int *input)
{

  int completed = 0;
  int z;
  int h = 0, x = 0;
  int start = 0;
  int head = input[0];
  int seek1 = 0;
  int sorted[count];
  int i, y, j, a;
  int otherway = 0;

  for (z = 0; z < count; ++z)
    {
      sorted[z] = input[z];
    }

//sort the array
  for (i = 0; i < count; ++i)
    {
      for (j = i + 1; j < count; ++j)
	{
	  if (sorted[i] > sorted[j])
	    {
	      a = sorted[i];
	      sorted[i] = sorted[j];
	      sorted[j] = a;
	    }
	}
    }

//  printf ("The numbers arranged in ascending order are given below \n");
//  for (i = 0; i < count; ++i)
//  printf ("%d\n", sorted[i]);


  while (1)
    {
      if (sorted[x] == head)
	{
	  y = x;
	  break;
	}

      else
	{
	  ++x;
	}
    }

  while (completed < count-1)
    {

      if (y == count-1)
	{
	otherway = 1;
//	printf ("current: %d %d: %d\n",sorted[y],sorted[x],( sorted[y] - sorted[x]));
	seek1 += sorted[y] - sorted[x];
	y = x;
	}

      if (otherway == 0)
	{
//	printf ("current: %d %d: %d\n",sorted[y+1],sorted[y],( sorted[y+1] - sorted[y]));
        seek1 += sorted[y+1] - sorted[y];
	++y;
	}

      else
	{
   	seek1 += sorted[y] - sorted[y - 1];
// 	printf ("current: %d %d: %d\n",sorted[y], sorted[y-1], sorted[y] - sorted[y - 1]);
	--y;
	}

      ++completed;
    }

  printf ("C-LOOK Total Seek: %d\n", seek1);

}
