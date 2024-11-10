#pragma once
#include <algorithm>

template<typename T>
class GameArray
{
public:
	T* data;
	int size;
	int used;
	/// <summary>
	/// Default constructor
	/// </summary>
	GameArray()
	{
		size = 1;
		data = new T[size];
		used = 0;
	}
	/// <summary>
	/// Constructor with specified size
	/// </summary>
	/// <param name="i">Size</param>
	GameArray(int i)
	{
		size = i;
		data = new T[size];
		used = 0;
	}
	/// <summary>
	/// Adds an element to the array
	/// </summary>
	/// <param name="element">element to add</param>
	void add(T element)
	{
		if (used < size)
		{
			data[used] = element;
			used++;
		}
		if (used == size)
		{
			T* newdata;
			size *= 2;
			newdata = new T[size];
			memcpy(newdata, data, used * sizeof(T));
			delete[] data;
			data = newdata;
		}
	}
	//ensure this class is only used for data on the heap
	//deleting variables on teh stcak is crazyy

	/// <summary>
	/// removing elements from the array
	/// </summary>
	/// <param name="index">index to remove element from</param>
	void remove(unsigned int index) {
		if (index >= used)return;

		//we swap with the last element and delete the last
		std::swap(data[used - 1], data[index]);
		//also reducing the used
		delete data[--used];

	}
	/// <summary>
	/// Returns a reference to the element at a specified index
	/// </summary>
	/// <param name="index">Index to get element</param>
	/// <returns>Reference to the element</returns>
	T& operator[](unsigned int index) {
		return data[index];
	}
};