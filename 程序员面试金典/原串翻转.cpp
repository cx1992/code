#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
using namespace std;

/** \brief �ڲ�ʹ�ö������ݽṹ�ʹ���ռ������£���תһ���������ַ���(����ʹ�õ������̱���)��
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
