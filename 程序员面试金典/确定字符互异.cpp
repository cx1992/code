#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
using namespace std;

/** \brief ��ʵ��һ���㷨��ȷ��һ���ַ����������ַ��Ƿ�ȫ����ͬ��
 *  ����һ��string iniString���뷵��һ��boolֵ,True���������ַ�ȫ����ͬ��False���������ͬ���ַ���
 *  ��֤�ַ����е��ַ�ΪASCII�ַ����ַ����ĳ���С�ڵ���3000��
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
