//
// Created by Eigle, Sean on 2019-11-25.
//
#include "SkittlesBag.h"
#include "omp.h"

int spot = 0;
int size = 0;
SKITTLES_BAG bags[2000] = {0};
const SKITTLES_BAG empty;

SKITTLES_BAG* createBag() {
	//Set rand time to produce random numbers every time
	SKITTLES_BAG* bag;
	size++;
	size_t nodeSize;

	//create space for bag
	nodeSize = sizeof(SKITTLES_BAG);
	if ((bag = calloc(nodeSize, 1)) == NULL)
		printf("Memory allocation failed");

	//randomly assign number of skittles
//#pragma omp parallel
//	{
//#pragma omp for
		for (int i = 0; i < 60; i++) {
			switch ((rand() % 5) + 1) {
				case 1:
					++bag->green;
					break;
				case 2:
					++bag->orange;
					break;
				case 3:
					++bag->purple;
					break;
				case 4:
					++bag->red;
					break;
				case 5:
					++bag->yellow;
					break;
			}
		}
//	}
	return bag;

}

SKITTLES_BAG* addToList(SKITTLES_BAG* head) {
	bags[spot] = *head;
	spot++;
	return head;
}

int checkForCopy(SKITTLES_BAG* head) {
	int match = 1;
//#pragma omp parallel
//	{
//		int num_threads = omp_get_num_threads();
//		int id = omp_get_thread_num();
		for (int i = 0; i < size-1; i ++) {
			if (compareData(head, &bags[i]) == 0) {
				match = 0;
			}
		}
//	}
		return match;

	}

	int compareData(SKITTLES_BAG* newBag, SKITTLES_BAG* oldBag) {
		if ((newBag->orange == oldBag->orange) &&
				(newBag->yellow == oldBag->yellow) &&
				(newBag->green == oldBag->green) &&
				(newBag->red == oldBag->red) &&
				(newBag->purple == oldBag->purple)) {
			return 0;
		} else {
			return 1;
		}
	}