/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
}st[10];



char string[10];

int conver_date3(int i, int l, char *s)
{
	int m, k, j = 0;
	for (m = i; m<l; m++)
	{
		string[j] = s[m];

		j++;
	}
	string[j] = '\0';

	k = atoi(string);
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
int conver_mntht3(int i, int l, char *s)
{
	int m, k, j = 0;
	for (m = i; m<l; m++)
	{
		string[j] = s[m];

		j++;
	}
	string[j] = '\0';

	k = atoi(string);
	if (k == 0 || k<0)
	{
		return -1;
	}
	else if (k>12)
	{
		return -1;
	}
	else
		return k;
}
int conver_year3(int i, int l, char *s)
{
	int m, k, j = 0;
	for (m = i; m<l; m++)
	{
		string[j] = s[m];

		j++;
	}
	string[j] = '\0';

	k = atoi(string);
	if (k == 0 || k<0)
	{
		return -1;
	}
	else if (k>2016 || k<1)
	{
		return -1;
	}
	else
		return k;
}
int isOlder3(char *dob1, char *dob2) {

	int i, j, k, l, m, n, len, len1;

	for (len = 0; dob1[len] != '\0'; len++);
	for (len1 = 0; dob2[len1] != '\0'; len1++);
	if (len != 10 || len1 != 10)
		return -1;

	i = conver_date3(0, 2, dob1);
	l = conver_date3(0, 2, dob2);
	j = conver_mntht3(3, 5, dob1);
	m = conver_mntht3(3, 5, dob2);
	k = conver_year3(6, 10, dob1);
	n = conver_year3(6, 10, dob2);

	if (j == 2)
	{
		if (k % 4 == 0)
		{
			if (i > 29)
				NULL;
		}
		else
		{
			if (i > 28)
				NULL;
		}
	}
	if (m == 2)
	{
		if (n % 4 == 0)
		{
			if (l > 29)
				return NULL;
		}
		else
		{
			if (l > 28)
				return NULL;
		}
	}
	if (i == 0 || l == 0 || j == 0 || m == 0 || k == 0 || n == 0)
		return NULL;
	if (i == -1 || l == -1 || j == -1 || m == -1 || k == -1 || n == -1)
		return NULL;
	if (k == n)
	{
		if (j == m)
		{
			if (i == l)
			{
				return 0;
			}
			else if (i>l)
			{
				return 1;
			}
			else
			{
				return 2;
			}
		}
		else if (j>m)
		{
			return 1;
		}
		else
		{
			return 2;
		}


	}
	else if (k>n)
	{
		return 1;
	}
	else
	{
		return 2;
	}


}







struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A==NULL || ALen==0 || ALen<0 || BLen==0 || BLen<0 || B==NULL)
	return NULL;
	int i, j,k, l = 0,n;
	char date[40],desc[40];
	for (i = 0; i < ALen; i++)
	{
		st[l].amount = A[i].amount;
		strcpy(st[l].date, A[i].date);
		strcpy(st[l].description, A[i].description);
		l++;
	}
	for (i = 0; i < BLen; i++)
	{
		st[l].amount = B[i].amount;
		strcpy(st[l].date, B[i].date);
		strcpy(st[l].description, B[i].description);
		l++;
	}
	for (i = 0; i < l; i++)
	{
		for (j = 0; j < l-i-1; j++)
		{

			n= isOlder3(st[j].date,st[j+1].date);
			if (n == 1)
			{
				k = st[j].amount;
				strcpy(date, st[j].date);
				strcpy(desc, st[j].description);
				st[j].amount = st[j + 1].amount;
				strcpy(st[j].date,st[j+1].date);
				strcpy(st[j].description,st[j+1].description);
				st[j + 1].amount = k;
				strcpy(st[j + 1].date,date);
				strcpy(st[j + 1].description,desc);                           


			}
		}
	}
	return st;
}