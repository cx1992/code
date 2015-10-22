#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
using namespace std;

/**< 结点的类型 */
typedef int tree_node_elem_t;

/**< 二叉树结点 */
typedef struct binary_tree_node_t
{
	binary_tree_node_t * left; /**< 左孩子 */
	binary_tree_node_t * right; /**< 右孩子 */
	tree_node_elem_t elem; /**< 结点的数据 */
} binary_tree_node_t;

/** \brief 先序遍历，递归
 *
 * \param [in] root 根结点
 * \param [in] visit 访问数据元素的函数指针
 * \return 无
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

/**< 中序遍历,递归*/
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

/**< 后序遍历,递归*/
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

/** \brief 先序遍历，非递归
 *
 * \param [in] root 根结点
 * \param [in] visit 访问数据元素的函数指针
 * \return 无
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

/**< 中序遍历，非递归 */
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

/**< 后序遍历，非递归 */
void post_order(const binary_tree_node_t * root, int (*visit)(const binary_tree_node_t *))
{
	/**< p,正在访问的结点；q，刚刚访问过的结点 */
	const binary_tree_node_t * p, *q;
	stack<const binary_tree_node_t *> s;
	p = root;

	do
	{
		while (p != NULL) /**<往左下走  */
		{
			s.push(p);
			p = p->left;
		}

		q = NULL;

		while (!s.empty())
		{
			p = s.top();
			s.pop();

			/**< 右孩子不存在或已被访问，访问之 */
			if (p->right == q)
			{
				visit(p);
				q = p; /**< 保存刚访问过的结点 */
			}
			else
			{
				/**< 当前结点不能访问，需第二次进栈 */
				s.push(p);
				/**< 先处理右子树 */
				p = p->right;
				break;
			}
		}
	}
	while (!s.empty());
}

/** \brief 层次遍历，即BFS
 *
 * 跟先序遍历一样，把栈换成队列
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
