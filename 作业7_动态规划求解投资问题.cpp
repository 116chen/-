#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
int main()
{
    int n = 4, m = 5, dp[10][10], cost[10][10];
    int f[][6] = { {0},{0,11,12,13,14,15},{0,0,5,10,15,20},{0,2,10,30,32,40},{0,20,21,22,23,24,} };
    for (int i = 0; i <= m; i++)//确定边界
    {
        dp[1][i] = f[1][i];
        dp[i][0] = cost[i][0] = 0;
        cost[1][i] = i;
    }
    for (int i = 2; i <= n; i++)//遍历2-n项目
        for (int j = 1; j <= m; j++)//遍历金额
            for (int k = 0; k <= j; k++)//确定当前项目的投资金额
            {
                if (dp[i][j] < dp[i - 1][j - k] + f[i][k])
                {
                    dp[i][j] = dp[i - 1][j - k] + f[i][k];
                    cost[i][j] = k;
                }
                else if (dp[i][j] == dp[i - 1][j - k] + f[i][k])
                    cost[i][j] = min(cost[i][j], k);
            }
    printf("dp:\n");
    for (int i = 0; i <= m; i++)
        for (int j = 1; j <= n; j++)
            printf("%4d%c", dp[j][i], " \n"[j == n]);
    printf("\ncost:\n");
    for (int i = 0; i <= m; i++)
        for (int j = 1; j <= n; j++)
            printf("%4d%c", cost[j][i], " \n"[j == n]);
    printf("\n最大利润：%d\n", dp[n][m]);
    while (m) 
    {
        int y = cost[n][m];
        printf("x%d=%d\t", n, y);
        n--;
        m -= y;
    }
    return 0;
}