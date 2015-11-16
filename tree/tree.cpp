/*-------------------------------------
*   日期：2015-03-25
*   作者：SJF0115
*   题目: 二叉树各种遍历
*   来源：http://blog.csdn.net/sunnyyoona/article/details/24741311
*   博客：
------------------------------------*/
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// 二叉树节点结构
struct TreeNode
{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};
// 1.创建二叉树
void CreateTree(TreeNode *& root)
{
	int val;
	//按先序次序输入二叉树中结点的值,‘-1’表示空树
	cin >> val;

	// 空节点
	if (val == -1)
	{
		root = nullptr;
		return;
	}//if

	root = new TreeNode(val);
	//构造左子树
	CreateTree(root->left);
	//构造右子树
	CreateTree(root->right);
}
// 2.1 递归先序遍历
void PreOrder(TreeNode * root, vector<int> & result)
{
	if (root == nullptr)
	{
		return;
	}//if

	result.push_back(root->val);
	// 左子树
	PreOrder(root->left, result);
	// 右子树
	PreOrder(root->right, result);
}
// 2.2 非递归先序遍历
void PreOrder2(TreeNode * root, vector<int> & result)
{
	if (root == nullptr)
	{
		return;
	}//if

	stack<TreeNode *> s;
	s.push(root);
	TreeNode * node;

	while (!s.empty())
	{
		node = s.top();
		s.pop();
		result.push_back(node->val);

		// 右子树
		if (node->right)
		{
			s.push(node->right);
		}//if

		// 左子树
		if (node->left)
		{
			s.push(node->left);
		}//if
	}//while
}
// 3.1 递归中序遍历
void InOrder(TreeNode * root, vector<int> & result)
{
	if (root == nullptr)
	{
		return;
	}//if

	// 左子树
	InOrder(root->left, result);
	result.push_back(root->val);
	// 右子树
	InOrder(root->right, result);
}
// 3.2 非递归中序遍历
void InOrder2(TreeNode * root, vector<int> & result)
{
	if (root == nullptr)
	{
		return;
	}//if

	stack<TreeNode *> s;
	TreeNode * node = root;

	while (node != nullptr || !s.empty())
	{
		// 左子树
		if (node != nullptr)
		{
			s.push(node);
			node = node->left;
		}//if
		// 右子树
		else
		{
			node = s.top();
			s.pop();
			result.push_back(node->val);
			node = node->right;
		}
	}//while
}
// 4.1 递归后序遍历
void PostOrder(TreeNode * root, vector<int> & result)
{
	if (root == nullptr)
	{
		return;
	}//if

	// 左子树
	PostOrder(root->left, result);
	// 右子树
	PostOrder(root->right, result);
	result.push_back(root->val);
}
// 4.2 非递归后序遍历
void PostOrder2(TreeNode * root, vector<int> & result)
{
	if (root == nullptr)
	{
		return;
	}//if

	stack<TreeNode *> s;
	s.push(root);
	TreeNode * node;

	while (!s.empty())
	{
		node = s.top();
		s.pop();
		result.insert(result.begin(), node->val);

		// 左子树
		if (node->left)
		{
			s.push(node->left);
		}//if

		// 右子树
		if (node->right)
		{
			s.push(node->right);
		}//if
	}//while
}
// 5 层次遍历
void LevelOrder(TreeNode * root, vector<int> & result)
{
	if (root == nullptr)
	{
		return;
	}//if

	queue<TreeNode *> queue;
	queue.push(root);
	TreeNode * node;

	while (!queue.empty())
	{
		node = queue.front();
		queue.pop();
		result.push_back(node->val);

		// 左子树
		if (node->left)
		{
			queue.push(node->left);
		}//if

		// 右子树
		if (node->right)
		{
			queue.push(node->right);
		}//if
	}//while
}
// 输出结果
void Print(vector<int> result)
{
	int size = result.size();

	for (int i = 0; i < size; ++i)
	{
		cout << result[i] << " ";
	}//for

	cout << endl;
}
int main()
{
	TreeNode * root = nullptr;
	vector<int> result;
	// 创建二叉树
	cout << "1. 创建二叉树" << endl;
	CreateTree(root);
	cout << "-----------------------------" << endl;

	cout << "2.1 递归先序遍历" << endl;
	PreOrder(root, result);
	Print(result);
	result.clear();
	cout << "-----------------------------" << endl;

	cout << "2.2 非递归先序遍历" << endl;
	PreOrder2(root, result);
	Print(result);
	result.clear();
	cout << "-----------------------------" << endl;

	cout << "3.1 递归中序遍历" << endl;
	InOrder(root, result);
	Print(result);
	result.clear();
	cout << "-----------------------------" << endl;

	cout << "3.2 非递归中序遍历" << endl;
	InOrder2(root, result);
	Print(result);
	result.clear();
	cout << "-----------------------------" << endl;

	cout << "4.1 递归后序遍历" << endl;
	PostOrder(root, result);
	Print(result);
	result.clear();
	cout << "-----------------------------" << endl;

	cout << "4.2 非递归后序遍历" << endl;
	PostOrder2(root, result);
	Print(result);
	result.clear();
	cout << "-----------------------------" << endl;

	cout << "5 层次遍历" << endl;
	LevelOrder(root, result);
	Print(result);
	result.clear();
	cout << "-----------------------------" << endl;
	return 0;
}
