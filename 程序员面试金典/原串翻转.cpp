#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
using namespace std;

/** \brief 在不使用额外数据结构和储存空间的情况下，翻转一个给定的字符串(可以使用单个过程变量)。
 */

string reverseString(string iniString)
{
	// write code here
	int n = iniString.length();

	for (int i = 0; i < n/2; i++)
	{
		iniString[i] ^= iniString[n - 1 - i] ^= iniString[i] ^= iniString[n - 1 - i];
	}

	return iniString;
}

int main()
{
	cout << reverseString("This is nowcoder") << endl;
	return 0;
}
