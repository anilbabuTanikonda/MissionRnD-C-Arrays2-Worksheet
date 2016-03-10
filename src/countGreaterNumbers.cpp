/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include<stdlib.h>
struct transaction
{
	int amount;
	char date[11];
	char description[20];
};





char s1[10], s2[10];

int conver_date(int i, int l, char *s)
{
	int m, k, j = 0;
	for (m = i; m<l; m++)
	{
		s1[j] = s[m];

		j++;
	}
	s1[j] = '\0';

	k = atoi(s1);
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
int conver_mntht(int i, int l, char *s)
{
	int m, k, j = 0;
	for (m = i; m<l; m++)
	{
		s1[j] = s[m];

		j++;
	}
	s1[j] = '\0';

	k = atoi(s1);
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
int conver_year(int i, int l, char *s)
{
	int m, k, j = 0;
	for (m = i; m<l; m++)
	{
		s1[j] = s[m];

		j++;
	}
	s1[j] = '\0';

	k = atoi(s1);
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
int isOlder(char *dob1, char *dob2) {

	int i, j, k, l, m, n, len, len1;

	for (len = 0; dob1[len] != '\0'; len++);
	for (len1 = 0; dob2[len1] != '\0'; len1++);
	if (len != 10 || len1 != 10)
		return -1;

	i = conver_date(0, 2, dob1);
	l = conver_date(0, 2, dob2);
	j = conver_mntht(3, 5, dob1);
	m = conver_mntht(3, 5, dob2);
	k = conver_year(6, 10, dob1);
	n = conver_year(6, 10, dob2);

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








int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	if (len == 0 || len < 0 || date == " " || date == '\0')
		return NULL;
	int i,j,n=0;
	for (i = 0; i < len; i++)
	{
		j=isOlder(Arr[i].date,date);
		if (j == 1)
			n++;
	}
	return n;
}
