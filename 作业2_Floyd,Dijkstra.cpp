#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN = 1e3 + 6;
const int inf = 0x3f3f3f3f;
//mp表示存储图的数据结构，dis[i]表示Dijkstra中起点到i的最短距离，path[i]表示i的前驱节点
int mp[MAXN][MAXN], dis[MAXN], path[MAXN];
//vis[i]表示Dijkstra中i是否被访问过
bool vis[MAXN];
//n表示点数，m表示边数
int n, m;
void Floyd()
{
	for (int k = 1; k <= n; k++)//遍历中间点
		for (int i = 1; i <= n; i++)////i，j遍历整图
			for (int j = 1; j <= n; j++)
				if (mp[i][k] + mp[k][j] < mp[i][j])//若经过中间点k以后i，j的距离比i直接到j要短，则更新
					mp[i][j] = mp[i][k] + mp[k][j];
}
void Dijkstra(int s, int t)//s为起点，t为终点
{
	//初始化
	memset(dis, inf, sizeof(dis));
	memset(vis, false, sizeof(vis));
	memset(path, -1, sizeof(path));
	dis[s] = 0;
	for (int i = 2; i <= n; i++)
	{
		int minn = inf, p = 0;
		for (int j = 1; j <= n; j++)//找到未被标记且dis最小的点
			if (!vis[j] && dis[j] < minn)
			{
				minn = dis[j];
				p = j;
			}
		if (!p)break;
		vis[p] = true;//标记被找到的点
		for (int j = 1; j <= n; j++)
			if (!vis[j] && mp[p][j] != inf)//未被标记且存在边
				if (dis[j] > dis[p] + mp[p][j])//若经过p点起点到j的距离比直接到j要短，则更新距离和j的前驱节点
				{
					dis[j] = dis[p] + mp[p][j];
					path[j] = p;
				}
	}
	//输出最短路和路径
	vector<int>ve;
	cout << s << "->" << t << "的最短路径值是" << dis[t] << endl;
	while (t != -1)
	{
		ve.push_back(t);
		t = path[t];
	}
	cout << s << "到" << t << "的最短路径是：" << endl;
	for (int i = ve.size() - 1; i >= 0; i--)
	{
		cout << ve[i];
		if (i)cout << "->";
		else cout << endl;
	}
}
int main()
{
	memset(mp, inf, sizeof(mp));
	//输入点数和边数
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		mp[u][v] = w;
	}
	/*
	8 11
	1 2 1
	2 4 2
	3 1 2
	4 6 8
	5 4 2
	5 7 2
	6 5 2
	7 6 3
	7 8 3
	8 6 2
	4 3 1
	*/
	Dijkstra(1, 8);
	/*
	4 8
	1 2 2
	1 3 6
	1 4 4
	2 3 3
	3 1 7
	3 4 1
	4 1 5
	4 3 12
	*/
	//Floyd();
	return 0;
}
