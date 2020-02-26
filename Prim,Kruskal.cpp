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
/*void Prim(int s)//sΪ��� 
{
	//T��E�Ķ�����������ͬ
	visit[s] = true;//��ǽ���T�ĵ�
	for (i 1 ... n)//��ʼ��E�е���Ϣ
		dis[i] = G[s][i];
	for (i 1 ... n) 
	{
		tmp = choose_min_weight();//ѡ��E�б�Ȩ��С�ĵ��ֵ
		visit[tmp.index] = true;//����T�ĵ���
		sum += tmp.weight;//MST��Ȩֵ
		for (j 1 ... n)//����E�е���Ϣ
			if (!visit[j] && dis[j] > G[tmp.index][j])
				dis[j] = G[tmp.index][j];
	}
	cout << sum << endl;
}
void Kruskal() 
{
	sort(E, E + m);//���߼���Ȩֵ��������
	for (i 0...m) //�����߼�
		if (!is_same_set(E[i].u, E[i].v)) //��������㶼��ͬһ�������������u->v�߽��ṹ�ɻ�
		{
			merge_in_same_set(E[i].u, E[i].v);//�������ͬһ�����������������Ϻϲ�
			sum += E[i].w;//���ӸñߵĹ���
		}
	cout << sum << endl;//���MST��cost
}*/
void Prim(int s) //s�������
{
	int sum = 0;//MST��Ȩֵ
	memset(visit, false, sizeof(visit));//��ʼ���������
	visit[s] = true;
	for (int i = 1; i <= n; i++)//��ʼ��E
		dis[i] = G[s][i];
	for (int i = 1; i <= n - 1; i++) //���ϸ���T
	{
		int minn = inf, index = 0;
		for (int j = 1; j <= n; j++) //ѡ��E�б�Ȩ��С��
			if (minn > dis[j] && !visit[j])
			{
				minn = dis[j];
				index = j;
			}
		visit[index] = true;//��index����T��
		sum += minn;
		for (int j = 1; j <= n; j++)//����E���ȶ�δ����index�ͼ���index�Ժ�j��ľ��룬ȡ��Сֵ����
			if (!visit[j] && dis[j] > G[index][j])
				dis[j] = G[index][j];
	}
	cout << sum << endl;//���MSTȨֵ
}
int find(int x) //��ѯ���ϸ��ڵ�
{
	return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}
bool is_same_set(int x, int y) //�ж��Ƿ�Ϊһ������
{
	return find(x) == find(y);
}
void merge_in_same_set(int x, int y) //�ϲ�����
{
	fa[find(x)] = find(y);
}
void Kruskal() 
{
	int sum = 0;
	for (int i = 1; i <= n; i++)//��ʼ�����ϣ�ÿһ��������һ������
		fa[i] = i;
	sort(E, E + m, [](Edge& a, Edge& b) {return a.w < b.w; });//����
	for (int i = 0; i < m; i++)
		if (!is_same_set(E[i].u, E[i].v))//�ж��Ƿ���ͬһ����
		{
			merge_in_same_set(E[i].u, E[i].v);//�ϲ�����
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