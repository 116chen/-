#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
class node					//节点
{
public:
	node* left, * right;	//左右儿子
	int val, ID;			//频率和对应字符
	string code;			//编码
	node(int val, int ID)	//构造函数1
	{
		this->ID = ID;
		this->val = val;
		this->left = this->right = nullptr;
		this->code = "";
	}
	node(int val, node* L, node* R)	//构造函数2
	{
		this->val = val;
		this->left = L;
		this->right = R;
		code = "";
	}
	bool morethan(const node* p) const	//定义大于规则
	{
		return this->val > p->val;
	}
};
class nodeCompare						//优先队列的指针排序规则
{
public:
	nodeCompare() {}
	bool operator () (const node* p1, const node* p2) const
	{
		return p1->morethan(p2);
	}
};
priority_queue<node*,vector<node*>,nodeCompare>que;//优先队列
void TravelTree(node* root) 
{
	if (root) 
	{
		if (root->left)root->left->code = root->code + "1";//左叶子节点的编码修改
		if (root->right)root->right->code = root->code + "0";//右叶子节点的编码修改
		if (!root->left && !root->right)printf("%d %s\n", root->ID, root->code.c_str());//叶子节点输出编码
		TravelTree(root->left);
		TravelTree(root->right);
	}
}
node* createHuffmanTree(int fqy[], int n)//创建哈夫曼树
{
	for (int i = 1; i <= n; i++) 
	{
		node* tmp = new node(fqy[i - 1], i);
		que.push(tmp);
	}
	while (que.size() != 1)				//贪心构造哈夫曼森林，最后形成哈夫曼树
	{
		node* L = que.top();
		que.pop();
		node* R = que.top();
		que.pop();
		node* newNode = new node(L->val + R->val, L, R);
		que.push(newNode);
	}
	TravelTree(que.top());
	return nullptr;
}
int main() 
{
	int fqy[] = { 5,5,10,10,10,15,20,25 };
	createHuffmanTree(fqy, 8);
}
