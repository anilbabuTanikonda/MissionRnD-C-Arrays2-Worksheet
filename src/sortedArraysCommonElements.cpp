/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<stdlib.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
}s[10];

char s11[10], s22[10];

int conver_date1(int i, int l, char *s)
{
	int m, k, j = 0;
	for (m = i; m<l; m++)
	{
		s11[j] = s[m];

		j++;
	}
	s11[j] = '\0';

	k = atoi(s11);
	if (k == 0 || k<0)
	{
		return -1;
	}
	else if (k>31)
	{
		return -1;
	}
	else
		return k;
}
int isOlder1(char *dob1, char *dob2) {

	int i, j, k, l, m, n, len, len1;

	for (len = 0; dob1[len] != '\0'; len++);
	for (len1 = 0; dob2[len1] != '\0'; len1++);
	if (len != 10 || len1 != 10)
		return -1;

	i = conver_date1(0, 2, dob1);
	l = conver_date1(0, 2, dob2);
	if (i == l)
		return 1;
	else return 0;
	
	
	

}







struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A==NULL || ALen==0 || ALen<0 || BLen==0 || BLen<0 || B==NULL)
	return NULL;
	int i,j,k,l=0;
	for (i = 0; i < ALen; i++)
	{
		for (j = 0; j < BLen; j++)
		{
			k = isOlder1(A[i].date,B[j].date);
			if (k == 1)
			{
				s[l].amount = A[i].amount;
				strcpy(s[l].date,A[i].date);

				strcpy(s[l].description, A[i].description);
				l++;
			}
		}
	}
	if (l == 0)
		return NULL;
	return s;
}