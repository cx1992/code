#include<stdlib.h> /**< for malloc() */
#include<stdio.h>
#include<assert.h>
#include<string.h> /**< for memcpy() */
#include<limits.h>

/**
 * 栈的C语言实现，C++可直接使用stack
 */

typedef int stack_elem_t; // 元素类型

typedef struct stack_t
{
	int size; /**< 实际元素个数 */
	int capacity; /**< 容量，以元素为单位 */
	stack_elem_t * elems; /**< 栈的数组 */
} stack_t;

/** \brief 创建栈
 *
 * \param [in] capacity 初始容量
 * \return 栈对象的指针
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

/** \brief 销毁栈
 *
 * \param [inout] s 栈对象的指针
 * \return 无
 *
 */
void stack_destroy(stack_s * s)
{
	free(s->elems);
	free(s);
}

/** \brief 判断栈是否为空
 *
 * \param [in] s 栈对象的指针
 * \return 空，返回1，否则返回0
 *
 */
int stack_empty(const stack_t * s)
{
	return s->size == 0;
}

/** \brief 获取元素个数
 *
 * \param [in] s 栈对象的指针
 * \param [in] x 要进栈的元素
 * \return 无
 *
 */
void stack_push(stack_t * s, const stack_elem_t x)
{
	if (s->size == s->capacity) /**< 已满，重新分配内存 */
	{
		stack_elem_t * tmp = (stack_elem_t *)realloc(s->elems, s->capacity * 2 * sizeof(stack_elem_t));
		s->capacity *= 2;
		s->elems = temp;
	}

	s->elems[s->size++] = x;
}

/** \brief 进栈
 *
 * \param [in] s 栈对象的指针
 * \return 无
 *
 */
void stack_pop(stack_t * s)
{
	s->size--;
}

/** \brief 获取栈顶元素
 *
 * \param [in] s 栈对象的指针
 * \return 栈顶元素
 *
 */
stack_elem_t stack_top(const stack_t * s)
{
	return s->elems[s->size - 1];
}

