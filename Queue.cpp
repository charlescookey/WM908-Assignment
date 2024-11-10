#include "Queue.h"

#include <iostream>

minPriQueue::minPriQueue(int i) {
	size = i;
	arr = GameArray<Opponent*>(i);
	for (int i = 0; i < size; i++) {
		arr[i] = nullptr;
	}

}
int minPriQueue::left(int i) {
	return (i * 2) + 1;
}
int minPriQueue::right(int i) {
	return (i * 2) + 2;
}
int minPriQueue::parent(int i) {
	return i / 2;
}
void minPriQueue::minHeapify(int i) {
	if (i > size || arr[i] == nullptr)return;

	int l = left(i);
	int r = right(i);
	int smallest = 0;

	if (l < size && arr[l] != nullptr && arr[l]->currHealth < arr[i]->currHealth) {
		smallest = l;
	}
	else smallest = i;

	if (r < size && arr[r] != nullptr && arr[r]->currHealth < arr[smallest]->currHealth) {
		smallest = r;
	}

	if (smallest != i) {
		std::swap(arr[i], arr[smallest]);
		minHeapify(smallest);
	}
}

void minPriQueue::buildMaxHeap() {
	for (int i = size / 2; i >= 0; i--) {
		minHeapify(i);
	}
}

void minPriQueue::add(Opponent* i) {
	if (arr.used < arr.size) {
		arr.add(i);
		if (arr.used == arr.size) {
			buildMaxHeap();
		}
		return;
	}
	if (arr[0] != nullptr && i->currHealth < arr[0]->currHealth)return;
	arr[0] = i;
	minHeapify(0);
}

void minPriQueue::testDraw() {
	int level = 1;
	int curr = 0;
	for (int i = 0; i < size; i++) {
		if (++curr == level) {
			std::cout << "\n";
			level *= 2;
		}
		if (arr[i])
			std::cout << arr[i]->currHealth << "\t";
	}
}
