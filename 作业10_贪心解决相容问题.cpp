#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
const int MAXN = 25;
struct action 
{
	int s, f;
	bool operator <(const action& ac)
	{
		return f < ac.f;
	}
};
void solve(action ac[], int n)
{
	sort(ac, ac + n);
	action tmp[MAXN];
	int cnt = 0;
	tmp[0] = ac[0];
	for (int i = 1; i < n; i++) 
		if (ac[i].s > tmp[cnt].f)
			tmp[++cnt] = ac[i];
	for (int i = 0; i <= cnt; i++)
		printf("%d %d\n", tmp[i].s, tmp[i].f);
}
int main()
{
	action ac[] = { {3,4},{5,6},{7,8},{1,10},{9,10} };
	solve(ac, 5);
	return 0;
}
