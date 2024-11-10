#pragma once
#include "GameArray.h"
#include "Opponent.h"

class minPriQueue {
public:
	GameArray<Opponent*> arr;
	int size;
	/// <summary>
	/// Constructor that initializes the array to nullptr
	/// </summary>
	/// <param name="i">Size</param>
	minPriQueue(int i);

	/// <summary>
	/// Returns the left child in the heap
	/// </summary>
	/// <param name="i">index</param>
	/// <returns>left index</returns>
	int left(int i);
	/// <summary>
	/// Returns the right child in the heap
	/// </summary>
	/// <param name="i">index</param>
	/// <returns>right index</returns>
	int right(int i);
	/// <summary>
	/// Returns the parent in the heap
	/// </summary>
	/// <param name="i">index</param>
	/// <returns>parent index</returns>
	int parent(int i);
	/// <summary>
	/// Min heapifies the array, ensure the parent is the smallest of all
	/// its children, if it isn't it would switch and re-minheapify
	/// </summary>
	/// <param name="i">index</param>
	void minHeapify(int i);
	/// <summary>
	/// Buils heap, start from middle and min heapifies
	/// </summary>
	void buildMaxHeap();

	/// <summary>
	/// adds to the heap, if it isnt up to size, it just add, else it adds then calls minheapify
	/// </summary>
	/// <param name="i">Opponent to add</param>
	void add(Opponent* i);
	/// <summary>
	/// Displays the heap as a treuu
	/// </summary>
	void testDraw();
};
