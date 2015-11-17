//Primary author: Miranda Workman
//Shortest Seek Time First and Circular LOOK algorithms


/* Promise of Originality
I promise that this source code file has, in its entirety, been
written by myself or a member of my group and by no other person or
persons. If at any time an exact copy of this source code is found to
be used by another person outside my group in this term, I understand
that all members of my group and the members of the group that
submitted the copy will receive a zero on this assignment.
*/

#include<inttypes.h>

void sstf(int count, int *input)
{
	const int m = 9999999;
	int seek = 0;
	int cur_pos = input[0];
	int i, j, index, shortest;
	int visited[count];
	visited[0] = 1;
	for (i = 1; i < count; ++i)
	{
		visited[i] = 0;
	}

	for (i = 0; i < count; ++i)
	{
		shortest = m;
		for (j = 0; j < count; ++j)
		{
			if (visited[j] != 1)
			{
				if ( abs(cur_pos - input[j] ) < shortest )
				{
					index = j;
					shortest = abs(cur_pos - input[j]);
				}
			}
		}
		if (i != count-1)
		{
			seek += shortest;
			cur_pos = input[index];
			visited[index] = 1;
		}
	}

	printf("SSTF Total Seek: %d\n", seek);
}

void clook(int count, int *input)
{
	int i, j, temp, head, index, seek;
	int sorted[count];
	head = input[0];

	for (i = 0; i < count; ++i)
	{
		sorted[i] = input[i];
	}

	for (i = 0; i < count; ++i)
	{
		for (j = i + 1; j < count; ++j)
		{
			if (sorted[i] > sorted[j] )
			{
				temp = sorted[i];
				sorted[i] = sorted[j];
				sorted[j] = temp;
			}
		}
	}

	while(1)
	{
		if(sorted[index] == head)
			break;
		++index;
	}
	while (index < count - 1)
	{
		seek += sorted[index + 1] - sorted[index];
		++index;
	}

	index = 0;
	seek += sorted[count - 1] - sorted[0];
	while (sorted[index + 1] != head)
	{
		seek += sorted[index + 1] - sorted[index];
		++index;
	}


	printf("C-LOOK Total Seek: %d\n", seek);
}


