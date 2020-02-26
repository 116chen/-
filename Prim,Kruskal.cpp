#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN = 1e3 + 6;
const int inf = 0x3f3f3f3f;
int n, m;
int G[MAXN][MAXN], dis[MAXN], fa[MAXN];
bool visit[MAXN];
struct Edge 
{
	int u, v, w;
}E[MAXN];
/*
6 8
1 2 2
1 5 3
1 4 7
2 4 6
2 6 8
3 6 6
5 3 5
3 4 4
*/
/*void Prim(int s)//s为起点 
{
	//T，E的定于与上述相同
	visit[s] = true;//标记进入T的点
	for (i 1 ... n)//初始化E中的信息
		dis[i] = G[s][i];
	for (i 1 ... n) 
	{
		tmp = choose_min_weight();//选出E中边权最小的点和值
		visit[tmp.index] = true;//放入T的点标记
		sum += tmp.weight;//MST的权值
		for (j 1 ... n)//更新E中的信息
			if (!visit[j] && dis[j] > G[tmp.index][j])
				dis[j] = G[tmp.index][j];
	}
	cout << sum << endl;
}
void Kruskal() 
{
	sort(E, E + m);//将边集按权值升序排序
	for (i 0...m) //遍历边集
		if (!is_same_set(E[i].u, E[i].v)) //如果两个点都在同一个集合中则添加u->v边将会构成环
		{
			merge_in_same_set(E[i].u, E[i].v);//如果不在同一个集合中则将两个集合合并
			sum += E[i].w;//增加该边的贡献
		}
	cout << sum << endl;//输出MST的cost
}*/
void Prim(int s) //s代表起点
{
	int sum = 0;//MST的权值
	memset(visit, false, sizeof(visit));//初始化标记数组
	visit[s] = true;
	for (int i = 1; i <= n; i++)//初始化E
		dis[i] = G[s][i];
	for (int i = 1; i <= n - 1; i++) //不断更新T
	{
		int minn = inf, index = 0;
		for (int j = 1; j <= n; j++) //选出E中边权最小的
			if (minn > dis[j] && !visit[j])
			{
				minn = dis[j];
				index = j;
			}
		visit[index] = true;//将index放入T中
		sum += minn;
		for (int j = 1; j <= n; j++)//更新E，比对未加入index和加入index以后到j点的距离，取较小值更新
			if (!visit[j] && dis[j] > G[index][j])
				dis[j] = G[index][j];
	}
	cout << sum << endl;//输出MST权值
}
int find(int x) //查询集合根节点
{
	return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}
bool is_same_set(int x, int y) //判断是否为一个集合
{
	return find(x) == find(y);
}
void merge_in_same_set(int x, int y) //合并集合
{
	fa[find(x)] = find(y);
}
void Kruskal() 
{
	int sum = 0;
	for (int i = 1; i <= n; i++)//初始化集合，每一个数都是一个集合
		fa[i] = i;
	sort(E, E + m, [](Edge& a, Edge& b) {return a.w < b.w; });//排序
	for (int i = 0; i < m; i++)
		if (!is_same_set(E[i].u, E[i].v))//判断是否在同一集合
		{
			merge_in_same_set(E[i].u, E[i].v);//合并集合
			sum += E[i].w;
		}
	cout << sum << endl;
}
int main()
{
	memset(G, inf, sizeof(G));
	int u, v, w;
	cin >> n >> m;
	for (int i = 0; i < m; i++) 
	{
		cin >> u >> v >> w;
		G[u][v] = G[v][u] = w;
		E[i] = { u,v,w };
	}
	Prim(1);
	Kruskal();
	return 0;
}