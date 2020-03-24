#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 6;
struct Point 
{
    double x, y;
}point[MAXN];//point为点集，x升序排列，x相同时，按y升序排列
double dis(int i, int j) //求欧几里得距离的平方
{
    return (point[i].x - point[j].x) * (point[i].x - point[j].x) - (point[i].y - point[j].y) * (point[i].y - point[j].y);
}
double EfficientClosestPair(int left, int right)
{
    //点集小于等于3，直接输出
    if (left == right)return 0;
    else if (left + 1 == right)return dis(left, right);
    else if (left + 2 == right)return min(dis(left, right), min(dis(left + 1, right), dis(left, left + 1)));

    //分治左右区间
    int mid = (left + right) / 2;
    double d1 = EfficientClosestPair(left, mid);
    double d2 = EfficientClosestPair(mid + 1, right);

    //选取左右较小的最小点距并划分d空间里的数
    double d = min(d1, d2);
    int tmp[MAXN], cnt = 0;
    for (int i = left; i <= right; i++)
        if ((point[mid].x - point[i].x) * (point[mid].x - point[i].x) < d)
            tmp[++cnt] = i;

    //按y升序排列d空间里的点
    sort(tmp + 1, tmp + cnt + 1, [](Point& a, Point& b) {return a.y < b.y; });

    //判断左右点集中是否存在有小于d的点距，如果有则更新（更新点不超过6个）
    for (int i = 1; i <= cnt; i++)
        for (int j = i + 1; j <= cnt && (point[tmp[i]].y - point[tmp[j]].y) * (point[tmp[i]].y - point[tmp[j]].y) < d; j++)
            if (dis(tmp[i], tmp[j]) < d)
                d = dis(tmp[i], tmp[j]);
    return sqrt(d);
}
int main() 
{
    
    return 0;
}
