#pragma once

#include <ctime>
#include <cassert>
#include <iostream>
using namespace std;

template<typename Item>
class MaxHeap
{
	Item* data_;
	int count_;
	int capacity_;

	void shift_up(int k)
	{
		Item unsort = data_[k];
		while (k > 1 && data_[k / 2] < unsort)
		{
			data_[k] = data_[k / 2];
			k /= 2;
		}
		data_[k] = unsort;
	}
	void shift_down(int k)
	{
		const int unsort = data_[k];
		while (2 * k <= count_)	// decide if the element has child
		{
			int j = 2 * k;
			if (j + 1 <= count_ && data_[j + 1] > data_[j])
				j++;
			if (unsort >= data_[j])
			{
				data_[k] = unsort;
				break;
			}
			data_[k] = data_[j];
			k = j;
		}
		data_[k] = unsort;

	}

public:

	Item extract_max()
	{
		assert(count_ > 0);
		Item ret = data_[1];
		swap(data_[count_], data_[1]);
		count_--;
		shift_down(1);
		return ret;
	}

	MaxHeap(int capacity)
	{
		data_ = new Item[capacity + 1];
		count_ = 0;
		this->capacity_ = capacity;
	}

	MaxHeap(Item arr[],int size)
	{
		data_ = new Item[size + 1];
		for(int i = 0;i<size;i++)
		{
			data_[i + 1] = arr[i];
		}
		count_ = size;
		for(int i = count_/2;i>=1;i--)
		{
			shift_down(data_[i]);
		}
	}

	~MaxHeap()
	{
		delete[] data_;
	}

	int size() const
	{
		return count_;
	}

	bool is_empty() const
	{
		return count_ == 0;
	}

	void insert(Item item)
	{
		assert(count_ + 1 <= capacity_);
		data_[count_ + 1] = item;
		shift_up(count_ + 1);
		count_++;
	}

	void test_print()
	{
		for (int i = 0; i<capacity_; i++)
		{
			cout << data_[i] << " ";
		}
	}
};