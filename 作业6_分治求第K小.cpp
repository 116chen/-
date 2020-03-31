#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
int ans;
void getKth(int arr[], int low, int high, int K)
{
    int tmp = arr[low], l = low, r = high;
    while (low < high) 
    {
        while (arr[high] >= tmp && low < high)
            high--;
        if (low < high)
            arr[low] = arr[high];
        while (arr[low] <= tmp && low < high)
            low++;
        if (low < high)
            arr[high] = arr[low];
    }
    arr[low] = tmp;
    if (K <= low - l)//左边个数比K大，递归左边
        getKth(arr, l, low - 1, K);
    else if (K > low - l + 1)//左边个数比K小，递归右边
        getKth(arr, low + 1, r, K - (low - l) - 1);
    else//相等则停止
        ans = arr[low];
}
int main()
{
    int arr[] = { 0,3,4,7,6,2,1,5,8 };
    getKth(arr, 1, 8, 7);
    cout << ans << endl;
    return 0;
}
