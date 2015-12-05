/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	if (Arr == NULL || len < 0)
		return NULL;
	//int iter[5] = { Arr[0], Arr[1], Arr[2], Arr[3], Arr[4] };
	
	//Arr = (int *)realloc(Arr, (int)len + 1);
	/*Arr[0]=iter[0];
	Arr[1] = iter[1];
	Arr[2] = iter[2];
	Arr[3] = iter[3];
	Arr[4] = iter[4];*/
	int i;
	for (i = (len - 1); Arr[i] > num && i >= 0; i--){
		Arr[i + 1] = Arr[i];
	}
	Arr[i + 1] = num;
	return Arr;
}

