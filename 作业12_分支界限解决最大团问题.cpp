#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 1e2 + 6;
int cn, bestn, n, m;//cn:当前团结点数;bestn:最大团结点数;n:总结点数;m:总边数
int mp[MAXN][MAXN];//无向图
bool used[MAXN];//标记是否处在当前团
void DFS(int i) 
{
	bool flag = false;
	if (i > n) //输出最大团
	{
		bestn = cn;
		for (int j = 1; j <= n; j++)
			if (used[j])
				printf("%d ", j);
		printf("\n");
		return;
	}
	for (int j = 1; j < i; j++)//是否与其余结点有边相连
		if (used[j] && !mp[i][j]) 
		{
			flag = true;
			break;
		}
	if (!flag) 
	{
		cn++;//将i添加进当前团
		used[i] = true;
		DFS(i + 1);//进入下一个结点
		cn--;//回溯
	}
	if (cn + n - i >= bestn) //上界条件
	{
		used[i] = false;//将i移出当前团
		DFS(i + 1);//进入下一个结点
	}
}
int main()
{
	memset(mp, 0, sizeof(mp));
	memset(used, false, sizeof(used));
	cn = bestn = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		mp[u][v] = mp[v][u] = 1;
	}
	printf("最大团集\n");
	DFS(1);
	return 0;
}
/*
5 7
1 2
1 4
1 5
2 3
2 5
3 5
4 5
*/
