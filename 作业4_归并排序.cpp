#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
void Merge(int A[], int l, int r) 
{
	int mid = (l + r) / 2;
	int i = l, j = mid + 1;
	int tmp[9] = { 0 }, cnt = 0;
	while (i <= mid && j <= r) 
	{
		if (A[i] < A[j])
			tmp[++cnt] = A[i++];
		else
			tmp[++cnt] = A[j++];
	}
	while (i <= mid)tmp[++cnt] = A[i++];
	while (j <= r)tmp[++cnt] = A[j++];
	cnt = 0;
	while (l <= r)A[l++] = tmp[++cnt];
}
void MergeSort(int A[], int l, int r) 
{
	if (l == r)return;
	int mid = (l + r) / 2;
	MergeSort(A, l, mid);
	MergeSort(A, mid + 1, r);
	Merge(A, l, r);
}
int main()
{
	int A[9] = { -1,8,5,4,1,3,7,6,2 };
	MergeSort(A, 1, 8);
	for (int i = 1; i <= 8; i++)
		printf("%d%c", A[i], " \n"[i == 8]);
	return 0;
}
