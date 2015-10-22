#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
using namespace std;

/**< �������� */
typedef int tree_node_elem_t;

/**< ��������� */
typedef struct binary_tree_node_t
{
	binary_tree_node_t * left; /**< ���� */
	binary_tree_node_t * right; /**< �Һ��� */
	tree_node_elem_t elem; /**< �������� */
} binary_tree_node_t;

/** \brief ����������ݹ�
 *
 * \param [in] root �����
 * \param [in] visit ��������Ԫ�صĺ���ָ��
 * \return ��
 *
 */
void pre_order_r(const binary_tree_node_t * root, int (*visit)(const binary_tree_node_t *))
{
	if (root == NULL)
	{
		return;
	}

	visit(root);
	pre_order_r(root->left, visit);
	pre_order_r(root->right, visit);
}

/**< �������,�ݹ�*/
void in_order_r(const binary_tree_node_t * root, int (*visit)(const binary_tree_node_t *))
{
	if (root == NULL)
	{
		return;
	}

	pre_order_r(root->left, visit);
	visit(root);
	pre_order_r(root->right, visit);
}

/**< �������,�ݹ�*/
void post_order_r(const binary_tree_node_t * root, int (*visit)(const binary_tree_node_t *))
{
	if (root == NULL)
	{
		return;
	}

	pre_order_r(root->left, visit);
	pre_order_r(root->right, visit);
	visit(root);
}

/** \brief ����������ǵݹ�
 *
 * \param [in] root �����
 * \param [in] visit ��������Ԫ�صĺ���ָ��
 * \return ��
 *
 */
void pre_order(const binary_tree_node_t * root, int (*visit)(const binary_tree_node_t *))
{
	const binary_tree_node_t * p;
	stack<const binary_tree_node_t *> s;
	p = root;

	if (p != NULL)
	{
		s.push(p);
	}

	while (!s.empty())
	{
		p = s.top();
		s.pop();
		visit(p);

		if (p->right != NULL)
		{
			s.push(p->right);
		}

		if (p->left != NULL)
		{
			s.push(p->left);
		}
	}
}

/**< ����������ǵݹ� */
void in_order(const binary_tree_node_t * root, int (*visit)(const binary_tree_node_t *))
{
	const binary_tree_node_t * p;
	stack<const binary_tree_node_t * p>s;
	p = root;

	while (!s.empty || p != NULL)
	{
		if (p != NULL)
		{
			s.push(p);
			p = p->left;
		}
		else
		{
			p = s.top();
			s.pop();
			visit(p);
			p = p->right;
		}
	}
}

/**< ����������ǵݹ� */
void post_order(const binary_tree_node_t * root, int (*visit)(const binary_tree_node_t *))
{
	/**< p,���ڷ��ʵĽ�㣻q���ոշ��ʹ��Ľ�� */
	const binary_tree_node_t * p, *q;
	stack<const binary_tree_node_t *> s;
	p = root;

	do
	{
		while (p != NULL) /**<��������  */
		{
			s.push(p);
			p = p->left;
		}

		q = NULL;

		while (!s.empty())
		{
			p = s.top();
			s.pop();

			/**< �Һ��Ӳ����ڻ��ѱ����ʣ�����֮ */
			if (p->right == q)
			{
				visit(p);
				q = p; /**< ����շ��ʹ��Ľ�� */
			}
			else
			{
				/**< ��ǰ��㲻�ܷ��ʣ���ڶ��ν�ջ */
				s.push(p);
				/**< �ȴ��������� */
				p = p->right;
				break;
			}
		}
	}
	while (!s.empty());
}

/** \brief ��α�������BFS
 *
 * ���������һ������ջ���ɶ���
 */
void level_order(const binary_tree_node_t * root, int (*visit)(const binary_tree_node_t *))
{
	const binary_tree_node_t * p;
	queue<const binary_tree_node_t *> s;
	p = root;

	if (p != NULL)
	{
		s.push(p);
	}

	while (!s.empty())
	{
		p = s.front();
		s.pop();
		visit(p);

		if (p->left != NULL)
		{
			s.push(p->left);
		}

		if (p->right != NULL)
		{
			s.push(p->right);
		}
	}
}
