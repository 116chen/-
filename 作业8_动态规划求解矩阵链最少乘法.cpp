#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cstring>
using namespace std;
const int MAXN = 25;
const int inf = 0x3f3f3f3f;
int s[MAXN][MAXN];
void find_div(int l, int r) 
{
    if (!s[l][r])
        return;
    else
        printf("%d\t", s[l][r]);
    find_div(l, s[l][r]);
    find_div(s[l][r] + 1, r);
}
void min_multi_martix(int P[], int n)
{
    int dp[MAXN][MAXN];
    memset(dp, inf, sizeof(dp));//初始化
    if (n >= 2) //处理边界，直接将两个矩阵相乘
        for (int i = 1; i <= n - 1; i++)
        {
            dp[i][i + 1] = P[i] * P[i + 1] * P[i + 2];
            dp[i][i] = 0;
        }

    for (int len = 3; len <= n; len++)//枚举长度
        for (int i = 1; i <= n - len + 1; i++)//枚举起点
        {
            int j = i + len - 1;//确定终点
            for (int k = i; k < j; k++)//枚举分割点
                if (dp[i][j] > dp[i][k] + dp[k + 1][j] + P[i] * P[k + 1] * P[j + 1])//dp方程
                {
                    dp[i][j] = dp[i][k] + dp[k + 1][j] + P[i] * P[k + 1] * P[j + 1];
                    s[i][j] = k;
                }
        }
    printf("矩阵链最少乘法次数=%d\n", dp[1][n]);
    printf("分割点:");
    find_div(1, n);//输出分割点
}
int main()
{
    int P[] = { 0,3,5,4,8,2 };
    min_multi_martix(P, 4);
    return 0;
}