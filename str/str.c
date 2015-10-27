#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<limits.h>

//ʵ��strlen,��ȡ�ַ�������
size_t my_strlen(const char * str)
{
	//assert(str!=NULL);
	const char * s = str;

	while (*s++);

	return (s - str - 1);
}

//ʵ��strcpy,�ַ�������
char * my_strcpy(char * to, const char * from)
{
	//assert(to != NULL && from != NULL);
	char * p = to;

	while ((*p++ = *from++) != '\0');

	return to;
}

//ʵ��strstr,�Ӵ����ң������㷨���Ӷ�o(m*n)
char * my_strstr(const char * haystack, const char * needle)
{
	//assert(haystack != NULL && needle != NULL);
	if (*needle == '\0')
	{
		return (char *)haystack;
	}

	const char * p1, *p2, n = strlen(needle);

	for (p1 = haystack; * (p1 + n - 1); p1++)
	{
		const char * p1_old = p1;
		p2 = needle;

		while (*p1 && *p2 && *p1 == *p2)
		{
			p1++;
			p2++;
		}

		if (*p2 == '\0')
		{
			return (char *)p1_old;
		}

		p1 = p1_old;
	}

	return NULL;
}

//ʵ��atoi,��һ���ַ���ת��Ϊ����
//atoi�������ԣ����Կ�ͷ�������ո�����ǰ�����������ţ�ת��ֱ����һ���������ַ���
int my_atoi(const char * str)
{
	int num = 0;
	int sign = 1;
	const int len = strlen(str);
	int i = 0;

	while (str[i] == ' ' && i < len)
	{
		i++;
	}

	if (str[i] == '+')
	{
		i++;
	}

	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}

	for (; i < len; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			break;
		}

		if (num > INT_MAX / 10 || (num == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10))
		{
			return sign == -1 ? INT_MIN : INT_MAX;
		}

		num = num * 10 + str[i] - '0';
	}

	return num * sign;
}

int main(void)
{
	char a[10] = "abc";
	char * b = "dfgh";
	char * c = "fg";
	char * d = "   -3924x8fc";
	printf("%d\n", my_strlen(a));
	printf("a=%s\n", a);
	my_strcpy(a, b);
	printf("a=%s\n", a);
	printf("%s\n", my_strstr(a, c));
	printf("%d\n", my_atoi(d));
	return 0;
}
