/*-------------------------------------
*   ���ڣ�2015-03-25
*   ���ߣ�SJF0115
*   ��Ŀ: ���������ֱ���
*   ��Դ��http://blog.csdn.net/sunnyyoona/article/details/24741311
*   ���ͣ�
------------------------------------*/
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// �������ڵ�ṹ
struct TreeNode
{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};
// 1.����������
void CreateTree(TreeNode *& root)
{
	int val;
	//�������������������н���ֵ,��-1����ʾ����
	cin >> val;

	// �սڵ�
	if (val == -1)
	{
		root = nullptr;
		return;
	}//if

	root = new TreeNode(val);
	//����������
	CreateTree(root->left);
	//����������
	CreateTree(root->right);
}
// 2.1 �ݹ��������
void PreOrder(TreeNode * root, vector<int> & result)
{
	if (root == nullptr)
	{
		return;
	}//if

	result.push_back(root->val);
	// ������
	PreOrder(root->left, result);
	// ������
	PreOrder(root->right, result);
}
// 2.2 �ǵݹ��������
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

		// ������
		if (node->right)
		{
			s.push(node->right);
		}//if

		// ������
		if (node->left)
		{
			s.push(node->left);
		}//if
	}//while
}
// 3.1 �ݹ��������
void InOrder(TreeNode * root, vector<int> & result)
{
	if (root == nullptr)
	{
		return;
	}//if

	// ������
	InOrder(root->left, result);
	result.push_back(root->val);
	// ������
	InOrder(root->right, result);
}
// 3.2 �ǵݹ��������
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
		// ������
		if (node != nullptr)
		{
			s.push(node);
			node = node->left;
		}//if
		// ������
		else
		{
			node = s.top();
			s.pop();
			result.push_back(node->val);
			node = node->right;
		}
	}//while
}
// 4.1 �ݹ�������
void PostOrder(TreeNode * root, vector<int> & result)
{
	if (root == nullptr)
	{
		return;
	}//if

	// ������
	PostOrder(root->left, result);
	// ������
	PostOrder(root->right, result);
	result.push_back(root->val);
}
// 4.2 �ǵݹ�������
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

		// ������
		if (node->left)
		{
			s.push(node->left);
		}//if

		// ������
		if (node->right)
		{
			s.push(node->right);
		}//if
	}//while
}
// 5 ��α���
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

		// ������
		if (node->left)
		{
			queue.push(node->left);
		}//if

		// ������
		if (node->right)
		{
			queue.push(node->right);
		}//if
	}//while
}
// ������
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
	// ����������
	cout << "1. ����������" << endl;
	CreateTree(root);
	cout << "-----------------------------" << endl;

	cout << "2.1 �ݹ��������" << endl;
	PreOrder(root, result);
	Print(result);
	result.clear();
	cout << "-----------------------------" << endl;

	cout << "2.2 �ǵݹ��������" << endl;
	PreOrder2(root, result);
	Print(result);
	result.clear();
	cout << "-----------------------------" << endl;

	cout << "3.1 �ݹ��������" << endl;
	InOrder(root, result);
	Print(result);
	result.clear();
	cout << "-----------------------------" << endl;

	cout << "3.2 �ǵݹ��������" << endl;
	InOrder2(root, result);
	Print(result);
	result.clear();
	cout << "-----------------------------" << endl;

	cout << "4.1 �ݹ�������" << endl;
	PostOrder(root, result);
	Print(result);
	result.clear();
	cout << "-----------------------------" << endl;

	cout << "4.2 �ǵݹ�������" << endl;
	PostOrder2(root, result);
	Print(result);
	result.clear();
	cout << "-----------------------------" << endl;

	cout << "5 ��α���" << endl;
	LevelOrder(root, result);
	Print(result);
	result.clear();
	cout << "-----------------------------" << endl;
	return 0;
}
