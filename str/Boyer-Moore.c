#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<limits.h>

/**
 *  ���������޿���ֻ���㻵�ַ��ĺ��ƣ��ú�׺��λ���ǿ�ѡ�ģ�
 *  ��˿���ɾ�� suffixes(), pre_gs() ����
 */


#define ASIZE 256

/** \brief Ԥ��������ÿ����ĸ��ҵ�λ��
 *
 * \param [in] pattern ģʽ��
 * \param [out] right ÿ����ĸ��ҵ�λ��
 * \return ��
 *
 */
static void pre_right(const char * pattern , int right[])
{
	int i;
	const int m = strlen(pattern);

	for (i = 0; i < ASIZE; ++i)
	{
		right[i] = -1;
	}

	for (i = 0; i < m; ++i)
	{
		right[(unsigned char)pattern[i]] = i;
	}
}

static void suffixes(const char * pattern, int suff[])
{
	int f, g, i;
	const int m = strlen(pattern);
	suff[m - 1] = m;
	g = m - 1;

	for (i = m - 2; i >= 0; --i)
	{
		if (i > g && suff[i + m - 1 - f] < i - g)
		{
			suff[i] = suff[i + m - 1 - f];
		}
		else
		{
			if (i < g)
			{
				g = i;
			}

			f = i;

			while (g >= 0 && pattern[g] == pattern[g + m - 1 - f])
			{
				--g;
			}

			suff[i] = f - g;
		}
	}
}

/** \brief Ԥ��������ú�׺�ĺ���λ��
 *
 * \param [in] pattern ģʽ��
 * \param [out] gs �ú�׺�ĺ���λ��
 * \return ��
 *
 */
static void pre_gs(const char pattern[], int gs[])
{
	int i, j;
	const int m = strlen(pattern);
	int * suff = (int *)malloc(sizeof(int) * (m - 1));
	suffixes(pattern, suff);

	for (i = 0; i < m; ++i)
	{
		gs[i] = m;
	}

	j = 0;

	for (i = m - 1; i >= 0; --i)
		if (suff[i] == i + 1)
			for (; j < m - 1 - i; ++j)
				if (gs[j] == m)
				{
					gs[j] = m - 1 - i;
				}

	for (i = 0; i <= m - 2; ++i)
	{
		gs[m - 1 - suff[i]] = m - 1 - i;
	}

	free(suff);
}

/** \brief Boyer-Moore �㷨
 *
 * \param [in] text �ı�
 * \param [out] pattern ģʽ��
 * \return �ɹ��򷵻ص�һ��ƥ���λ�ã�ʧ���򷵻�-1
 *
 */
int boyer_moore(const char * text, const char * pattern)
{
	int i, j;
	int right[ASIZE];/**< ���ַ�ƫ�� */
	const int n = strlen(text);
	const int m = strlen(pattern);
	int * gs = (int *)malloc(sizeof(int) * (m + 1)); /**< �ú�׺ƫ�� */

	/**< Ԥ���� */
	pre_right(pattern, right);
	pre_gs(pattern, gs);

	/**< ���� */
	j = 0;

	while (j <= n - m)
	{
		for (i = m - 1; i >= 0 && pattern[i] == text[i + j]; --i);

		if (i < 0)
		{
			/**< �ҵ�һ��ƥ�� */
			free(gs);
			return j;
		}
		else
		{
			/**< ���úú�׺λ�ƿ��޸ĳ�const int max =max(1,i - right[(unsigned char)text[i + j]]) */
			const int max = gs[i] > right[(unsigned char)text[i + j]]
			                - m + 1 + i ? gs[i] : i - right[(unsigned char)text[i + j]];
			j += max;
		}
	}

	free(gs);
	return -1;
}

int main(void)
{
	char text[] = "ABC ABCDAB ABCDABCDABDE";
	char pattern[] = "ABCDABD";
	char text1[] = "HERE IS A SIMPLE EXAMPLE";
	char pattern1[] = "EXAMPLE";

	int i = boyer_moore(text1, pattern1);
	char * ch = text1;
	if (i >= 0)
	{
		printf("matched @: %s\n", ch + i);
	}

	return 0;
}
