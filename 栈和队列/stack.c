#include<stdlib.h> /**< for malloc() */
#include<stdio.h>
#include<assert.h>
#include<string.h> /**< for memcpy() */
#include<limits.h>

/**
 * ջ��C����ʵ�֣�C++��ֱ��ʹ��stack
 */

typedef int stack_elem_t; // Ԫ������

typedef struct stack_t
{
	int size; /**< ʵ��Ԫ�ظ��� */
	int capacity; /**< ��������Ԫ��Ϊ��λ */
	stack_elem_t * elems; /**< ջ������ */
} stack_t;

/** \brief ����ջ
 *
 * \param [in] capacity ��ʼ����
 * \return ջ�����ָ��
 *
 */
stack_t * stack_create(const int capacity)
{
	stack_t * s = (stack_t *)malloc(sizeof(stack_t));
	s->size = 0;
	s->capacity = capacity;
	s->elems = (stack_elem_t *)malloc(capacity * sizeof(stack_elem_t));
	return s;
}

/** \brief ����ջ
 *
 * \param [inout] s ջ�����ָ��
 * \return ��
 *
 */
void stack_destroy(stack_s * s)
{
	free(s->elems);
	free(s);
}

/** \brief �ж�ջ�Ƿ�Ϊ��
 *
 * \param [in] s ջ�����ָ��
 * \return �գ�����1�����򷵻�0
 *
 */
int stack_empty(const stack_t * s)
{
	return s->size == 0;
}

/** \brief ��ȡԪ�ظ���
 *
 * \param [in] s ջ�����ָ��
 * \param [in] x Ҫ��ջ��Ԫ��
 * \return ��
 *
 */
void stack_push(stack_t * s, const stack_elem_t x)
{
	if (s->size == s->capacity) /**< ���������·����ڴ� */
	{
		stack_elem_t * tmp = (stack_elem_t *)realloc(s->elems, s->capacity * 2 * sizeof(stack_elem_t));
		s->capacity *= 2;
		s->elems = temp;
	}

	s->elems[s->size++] = x;
}

/** \brief ��ջ
 *
 * \param [in] s ջ�����ָ��
 * \return ��
 *
 */
void stack_pop(stack_t * s)
{
	s->size--;
}

/** \brief ��ȡջ��Ԫ��
 *
 * \param [in] s ջ�����ָ��
 * \return ջ��Ԫ��
 *
 */
stack_elem_t stack_top(const stack_t * s)
{
	return s->elems[s->size - 1];
}

