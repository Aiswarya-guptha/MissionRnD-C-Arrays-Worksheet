
/*
OVERVIEW:  Write a function that takes ascending sorted student's score array and tells how many number of students got more marks and how many students got less marks than the given student.
E.g.: Input array: [10, 20, 30, 40, 50], score: 30, lessCount value is 2 (10, 20 are less than 30), moreCount value is 2 (40, 50 are greater than 30).

INPUTS: Ascending sorted student marks array, length of the array, one student score, lessCount and moreCount are to be
used to store final results.

OUTPUT: Update lessCount and moreCount with number of students less than and more than given score.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>


void * studentsCount(int *Arr, int len, int score, int *lessCount, int *moreCount) {

	if (Arr == NULL){
		//if arr is NULL
		return NULL;
	}
	int iter = 0;
	while (Arr[iter] >= 0){
		//count no of values in it
		iter++;
	}
	if (iter != (len))
		//if length is not equal to no. of values return invalid
		return NULL;

	for (int mid = len / 2, first = 0, c = 0, found = 0; found == 0;){
		if (score == Arr[mid]){
			//if score found
			if (score == Arr[mid - 1]){
				//if both values are same
				*lessCount = 0;
				*moreCount = 0;
				found = 1;
			}
			else{
				*lessCount = mid;
				*moreCount = len - mid - 1;
				found = 1;
			}
		}

		else if (score > Arr[mid]){
			if ((mid + 1) >= len || score < Arr[mid + 1]){
				//if single value or no value exists
				*lessCount = mid + 1;
				*moreCount = len - mid - 1;
				found = 1;
			}
			else{
				c = mid;
				mid = (mid + len) / 2;
				first = c;
			}
		}
		else{
			if ((mid - 1) < 0 || score > Arr[mid - 1]){
				//if single value or no value exists
				*lessCount = mid;
				*moreCount = len - mid;
				found = 1;
			}
			else{
				c = mid;
				mid = (mid + first) / 2;
				len = c;
			}
		}
	}
	return NULL;
}
