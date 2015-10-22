#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
using namespace std;

/** \brief 请实现一个算法，确定一个字符串的所有字符是否全都不同。
 *  给定一个string iniString，请返回一个bool值,True代表所有字符全都不同，False代表存在相同的字符。
 *  保证字符串中的字符为ASCII字符。字符串的长度小于等于3000。
 */

bool checkDifferent(string iniString)
{
	// write code here
	int n = iniString.length();

	if (n > 256)
	{
		return false;
	}

	bool num[256]={0};

	for (int i = 0; i < n; i++)
	{
		if (num[i])
		{
			return false;
		}

		num[i] = true;
	}

	return true;
}

int main()
{
	cout << checkDifferent("D-5H0F6T%Z?QM9,\72:[A8X! ;YJ#")<< endl;
	return 0;
}
