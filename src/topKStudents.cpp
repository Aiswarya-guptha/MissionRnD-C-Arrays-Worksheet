/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

struct student ** topKStudents(struct student *students, int len, int K) {
	
	if (K <= 0 )	return NULL;

	struct student **result = (struct student **)malloc(K *sizeof(struct student*));
	int iter;
	for (iter = 0; iter < K; iter++)
	{
		result[iter] = (struct student*)malloc(K* sizeof(struct student));
		result[iter] = &students[iter];
	}

	if (K > len)	return result;
	int max1=101, max2=0,iter1,index=0;
	for (iter = 0; iter < K; iter++,max2=0){
		for (iter1 = 0; iter1 < len; iter1++){
			if (students[iter1].score<max1 && students[iter1].score>max2){
				max2 = students[iter1].score;
				index = iter1;
			}
		}
		max1 = students[index].score;
		result[iter] = &students[index];
	}
	return result;
}