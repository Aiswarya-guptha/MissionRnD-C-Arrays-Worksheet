/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

INPUTS: Integer array and length of the array.

OUTPUT: Update input array by removing duplicate values.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>

void * removeArrayDuplicates(int *Arr, int len)
{
	if (Arr==NULL||len<0)
		return NULL;
	int arr[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int pos, iter;
	for (pos = 0, iter = 0; iter < len; iter++){
		if (arr[Arr[iter]] == 1){
			//skip if repeatation occurs
			continue;
		}
		if (iter != pos){
			//shift when repeatation occured atleast once
			Arr[pos] = Arr[iter];
			pos++;
			arr[Arr[iter]] = 1;
		}
		else{
			arr[Arr[iter]] = 1;
			pos++;
		}
	}
}
