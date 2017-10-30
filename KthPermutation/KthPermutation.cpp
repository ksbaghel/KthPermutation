// KthPermutation.cpp : Defines the entry point for the console application.
/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3 ) :

Given n and k, return the kth permutation sequence.
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;


int factorial(int n)
{
	if (n > 12) return INT_MAX;
	int fact = 1;
	for (int i = 2; i <= n; i++)
	{
		fact *= i;
	}
	return fact;
}

string getPermutation(int K, vector<int>& A)
{
	int n = A.size();
	
	if (n == 0) return "";

	if (K > factorial(n)-1) return ""; //Should never be the case
	
	int fact = factorial(n - 1);
	int pos = K / fact;
	K = K%fact;
	string ch = to_string(A[pos]);

	//Now remove pos char from the array
	A.erase(A.begin() + pos);

	return ch + getPermutation(K, A);
}

void print_kth_permutation(int n, int k)
{
	vector<int> A;

	for (int i = 1; i <= n; i++)
	{
		A.push_back(i);
	}

	string res = getPermutation(k, A);

	cout << k << "th permutation is: " << res << endl;
}

int main()
{
	int n, k;

	cin >> n >> k;

	print_kth_permutation(n, k-1);

    return 0;
}

