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

look (int count, int *input){

int complete = 0;
printf("%d",count);
int z;
  int h = 0;
  int start = 0;
//  int head = input[0];
  int seek = 0;
  int sorted[count];
//for (z = 0; z < count-1; z++){
//printf("%d",z);
//sorted[z]= input[z];
//}
//printf("hello");
//sort the array

 int i, j, a, n;

    for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (sorted[i] > sorted[j])
            {
                a =  sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = a;
            }
        }
    }
    printf("The numbers arranged in ascending order are given below \n");
    for (i = 0; i < n; ++i)
        printf("%d\n", sorted[i]);


}
