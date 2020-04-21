#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
#include<list>
#include<unordered_map>
#include<map>
#include<stack>
#include<functional>
using namespace std;
const int mod = 998244353;
typedef pair<int, int> Pair;
typedef unsigned long long ull;
typedef long long ll;
const ull INF = 0x3f3f3f3f3f3f3f;
const int MAXN = 25;
int dp[MAXN][MAXN], path[MAXN][MAXN];
stack<int>sta;
void find_LCS(int X[], int Y[], int n, int m)//递归求解LCS序列中具体的数
{
    if (!n || !m) return;
    if (path[n][m] == 1)//1代表需删除X序列中的最后一位
        find_LCS(X, Y, n - 1, m);
    else if (path[n][m] == 2)//2代表需删除Y序列中的最后一位
        find_LCS(X, Y, n, m - 1);
    else if (path[n][m] == 3)//3代表X[n-1]=Y[m-1]
    {
        sta.push(X[n - 1]);
        find_LCS(X, Y, n - 1, m - 1);
    }
}
void LCS(int X[], int Y[], int n, int m)//求解LCS
{
    memset(dp, 0, sizeof(dp));//初始化
    memset(path, 0, sizeof(path));
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                path[i][j] = 3;//代表X[i-1]和Y[j-1]相等
            }
            else
            {
                if (dp[i - 1][j] > dp[i][j - 1])
                {
                    dp[i][j] = dp[i - 1][j];
                    path[i][j] = 1;//删除X[i-1]更优
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                    path[i][j] = 2;//删除Y[j-1]更优
                }
            }
        }
    printf("最长公共子序列的长度=%d\n", dp[n][m]);
    find_LCS(X, Y, n, m);//递归求解LCS序列中具体的数
    while (!sta.empty()) //输出
    {
        printf("%d\t", sta.top());
        sta.pop();
    }
}
int main()
{
    int X[] = { 3,2,5,7,1 }, Y[] = { 2,7,9,1,4 };
    LCS(X, Y, 5, 5);
    return 0;
}