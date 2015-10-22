#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
using namespace std;

/** \brief 利用字符重复出现的次数，编写一个方法，实现基本的字符串压缩功能。
 *  比如，字符串“aabcccccaaa”经压缩会变成“a2b1c5a3”。若压缩后的字符串没有变短，则返回原先的字符串。
 */

string zipString(string iniString)
{
	// write code here
	int n = iniString.length();

	if (n < 2)
	{
		return iniString;
	}

	string newString = "";
	char c = iniString[0];
	char num = 1;

	for (int i = 1; i <= n; i++)
	{
		if (iniString[i] == c)
		{
			num++;
		}
		else
		{
			newString += c;
			char str[10];
			int j = 0;

			while (num)
			{
				str[j++] = num % 10 + '0';
				num /= 10;
			}

			while (j)
			{
				newString += str[--j];
			}

			c = iniString[i];
			num = 1;
		}
	}

	if (newString.length() < n)
	{
		return newString;
	}

	return iniString;
}

int main()
{
	cout << zipString("jjjjjjxxxxxxxooZLLLLLLLLQQQQQQQQQLLLLLLLLECXXXXXXXIIIIIIIIIhjjyyySSooooooooommmuuEEEEEEEEEnnnnnnnffffffAAAAAllllllllbbbbkkkkkkkkkkkkKKKKKKhhhhhhhhhooooooooooYCCCCCCOOOOOOOOOMMMMMMMMMMiiiiiivvvvvvvWWWWkkkkkkwwwwwwwMmmmmmmmmLLLwwwwwwwkkkjjjjjjttttQQQQQQQQQaaaaaaaFFFFFFFlllllllllggggggggggPPPPPPuuuuuuuuaYYYYYYwQQQFFFFFFFFFFaaaaapXXXXXXXxxxxxxQQQQQQQQQsssssGGGGfffffffddddddpppQQQQQQHHHTTTaaaaaaGGGGGGddyyyyyMhhllllllllllNNNNNNNNUUUWWWWWWLLLLLLLLLYYYYYYYYYYTTKKKKKKKKiiiiiiitttttttXXXXXXXXXLLLHZZZZZZZssssjjJJJEEEEEOOOOOttttttttttBBttttttTTTTTTTTTTrrrrttttRRRRRyyooooooaaaaaaaaarrrrrrrPPPPPPPjjPPPPddddddddddHHHHnnnnnnnnnnSSSSSSSSSSzzHHHHHHHHHddddddDDDzzzhhhhhfffffffffftttttteeeeeeeeEEEEEEEEEaaaaaaccccccccccFFFFFFFF") << endl;
	cout << zipString("welcometonowcoderrrrr") << endl;
	return 0;
}
