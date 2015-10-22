#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
using namespace std;

/** \brief �����ַ��ظ����ֵĴ�������дһ��������ʵ�ֻ������ַ���ѹ�����ܡ�
 *  ���磬�ַ�����aabcccccaaa����ѹ�����ɡ�a2b1c5a3������ѹ������ַ���û�б�̣��򷵻�ԭ�ȵ��ַ�����
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
