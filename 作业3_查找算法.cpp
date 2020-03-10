#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<unordered_map>
using namespace std;
const int MAXN = 10;
int T[MAXN];
int linearSearch(int* S, int n, int X)
{
	for (int i = 1; i <= n; i++)
		if (S[i] == X)
			return i;
	return 0;
}
int binarySearch(int* S, int n, int X)
{
	int l = 0, r = n + 1;
	while (l < r) 
	{
		int mid = (l + r) / 2;
		if (S[mid] < X)
			l = mid + 1;
		else
			r = mid;
	}
	return r;
}
int hashSearch(int* S, int n, int X) 
{
	unordered_map<int,int>Map;
	for (int i = 1; i <= MAXN; i++)
		Map[S[i]] = i;
	if (Map.count(X))
		return Map[X];
	else
		return 0;
}
int main() 
{
	srand(time(NULL));
	for (int i = 1; i <= MAXN; i++)
		T[i] = rand();
	sort(T + 1, T + MAXN + 1);
	for (int i = 1; i <= MAXN; i++)
		printf("%d%c", T[i], " \n"[i == MAXN]);
	int X = T[rand() % MAXN + 1];
	cout << "X=" << X << endl;
	//cout << linearSearch(T, MAXN, X) << endl;
	//cout << binarySearch(T, MAXN, X) << endl;
	cout << hashSearch(T, MAXN, X) << endl;
	return 0;
}