#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
using namespace std;

/** \brief 给定两个字符串，请编写程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。这里规定大小写为不同字符，且考虑字符串重点空格。
 */

bool checkSam(string stringA, string stringB)
{
	// write code here
	if (stringA.length() != stringB.length())
	{
		return false;
	}

	int n = stringA.length();
	char num[256] = {0};

	for (int i = 0; i < n; i++)
	{
		num[stringA[i]]++;
		num[stringB[i]]--;
	}

	for (int i = 0; i < 256; i++)
		if (num[i])
		{
			return false;
		}

	return true;
}

int main()
{
	cout << checkSam("This is nowcoder", "is This nowcoder") << endl;
	cout << checkSam("Here you are","Are you here") << endl;
	return 0;
}
