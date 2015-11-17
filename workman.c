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

void sstf(int count, int *input)
{
	int seek = 0;
	int cur_pos = input[0];
	int i;
	int shortest = 9999999;
	
	for (i = 0; i < count; ++i)
	{
		if (cur_pos < input[i+1])
		{
			if  (input[i+1] - cur_pos < shortest)
				shortest = input[i+1] - input[i];
		}
		else{
			if (cur_pos - input[i+1] < shortest)
				shortest = input[i+1] - input[i];
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


