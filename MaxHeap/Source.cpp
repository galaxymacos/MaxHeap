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

template<typename T>
void heap_sort2(T arr[],int n)
{
	MaxHeap<int> maxheap(arr, n);
	for(int i = n-1;i>=0;i--)
	{
		arr[i] = maxheap.extract_max();
	}
}

template<class T>
void heap_sort3(T arr[],int n)
{
	
	for(int i = n-1;i>0;i--)
	{
		for(int j = (n-1)/2;j>=0;j--)
		{
			int l = j;
			while(2*l+1 < i)
			{
				int k = 2 * l + 1;
				if (arr[k + 1] > arr[k])
					k++;
				if (arr[k] > arr[l])
					swap(arr[k], arr[l]);
				l = k;
			}
		}
		swap(arr[0], arr[i]);
	}
}

template<class T>
void __shift_down(T arr[],int n,int k)	// n = size_of_the_array, k = the position of the element you want to shift down
{
	while (k * 2 + 1<n)
	{
		int j = k * 2 + 1;
		if (j + 1 < n&&arr[j + 1]>arr[j])
		{
			j++;
		}
		if (arr[j]>arr[k])
		{
			swap(arr[j], arr[k]);
			k = j;
		}
		else
		{
			break;
		}
	}
}

template<class T>
void heap_sort4(T arr[],int n)
{
	// heapify
	for(int i = (n-1)/2;i>=0;i--)
	{
		__shift_down(arr, n, i);
	}

	
	for(int i = n-1;i>0;i--)
	{
		swap(arr[0], arr[i]);
		__shift_down(arr, i, 0);
	}
}

int main()
{
	int arr[] = { 5,2,6,23,26,72,4,66,3 };

	heap_sort4(arr, 9);
	for(int i:arr)
	{
		cout << i << " ";
	}

//	MaxHeap<int> maxheap(arr, 10);
//	while (!maxheap.is_empty())
//		cout<<maxheap.extract_max()<<" ";
	getchar();
}