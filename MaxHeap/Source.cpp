#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include "Heap.h"

using namespace std;
#define NDEBUG

using namespace std;

template<typename T>
void heap_sort1(T arr[],int n)
{
	MaxHeap<int> maxheap = MaxHeap<int>(n);
	for(int i = 0;i<n;i++)
	{
		maxheap.insert(arr[i]);
	}

	for(int i = n-1;i>=0;i--)
	{
		arr[i] = maxheap.extract_max();
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
	MaxHeap<int> maxheap(arr, 10);
	while (!maxheap.is_empty())
		cout<<maxheap.extract_max()<<" ";
	getchar();
}