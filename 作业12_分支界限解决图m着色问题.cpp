#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 1e2 + 6;
int n, k, m;//n:结点数;k:边数;m:图染色的颜色数;
int mp[MAXN][MAXN];//无向图
int color[MAXN];//结点染几号颜色
bool OK;//是否存在染色方案
bool judge(int x) //判断x结点染色方案是否正确
{
	for (int i = 1; i < x; i++)
		if (mp[i][x] && color[x] == color[i])//两结点相连,且颜色一样,则方案不可行
			return false;
	return true;
}
void DFS(int i) 
{
	if (i > n) 
	{
		OK = true;
		for (int j = 1; j <= n; j++)//输出可行染色方案
			printf("%d%c", color[j], " \n"[j == n]);
		return;
	}
	for (int j = 1; j <= m; j++)
	{
		color[i] = j;//i结点染j色
		if (judge(i))//可行就进入下一个结点
			DFS(i + 1);
		color[i] = 0;//i结点回溯到无颜色状态
	}
}
int main()
{
	OK = false;
	memset(mp, 0, sizeof(mp));
	memset(color, false, sizeof(color));
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		mp[u][v] = mp[v][u] = 1;
	}
	printf("染色方案\n");
	DFS(1);
	return 0;
}
/*
5 8 4
1 2
1 3
1 4
2 3
2 4
2 5
3 4
4 5
*/
