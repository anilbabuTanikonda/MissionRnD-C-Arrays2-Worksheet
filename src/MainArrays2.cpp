/*
Well Done for completing the first part of the C Course ,If you didnt finish 
Do complete them and come here again . 

Use MainArrays2 File for testing any other function in other Cpp files of the Strings Project.

DO NOT write main function in any other File or else your Build Fails.s

Objectives of C-Arrays-2 Lesson:

->Handling Arrays of Structures
->Sorting Arrays
->Learning Complexities of your Algorithm

*/
#include <stdio.h>
#include<conio.h>
#include "FunctionHeadersArrays2.h"
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int main(){

	//Test countGreaterNumbers

	//Test findSingleOccurenceNumber

	//Test mergeSortedArray
	struct transaction A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
	struct transaction B[3] = { { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 60, "22-04-2006", "Sixth" } };
	struct transaction *result1 = mergeSortedArrays(A, 3, B, 3);
	//Test sortedArraysCommonElements
	printf("%d",result1[0].amount);
	printf("%d", result1[1].amount);
	getch();
	return 0;
}