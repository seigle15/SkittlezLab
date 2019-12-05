//
// Created by Eigle, Sean on 2019-11-25.
//
#include "SkittlesBag.h"
#include "omp.h"

SKITTLES_BAG *createBag() {
	//Set rand time to produce random numbers every time
	SKITTLES_BAG *bag;
	size_t nodeSize;

	//create space for bag
	nodeSize = sizeof(SKITTLES_BAG);
	if ((bag = calloc(nodeSize, 1)) == NULL)
		printf("Memory allocation failed");

	//randomly assign number of skittles
#pragma omp parallel
	{
#pragma omp for
		for (int i = 0; i < 60; i++) {
			switch (arc4random_uniform(5) + 1) {
				case 1:
#pragma omp atomic
					++bag->green;
					break;
				case 2:
#pragma omp atomic
					++bag->orange;
					break;
				case 3:
#pragma omp atomic
					++bag->purple;
					break;
				case 4:
#pragma omp atomic
					++bag->red;
					break;
				case 5:
#pragma omp atomic
					++bag->yellow;
					break;
			}
		}
	}
	return bag;

}

SKITTLES_BAG_NODE *addToList(SKITTLES_BAG *bag, SKITTLES_BAG_NODE *head) {
	SKITTLES_BAG_NODE *node;
	size_t nodeSize;
	nodeSize = sizeof(SKITTLES_BAG_NODE);
	if ((node = calloc(nodeSize, 1)) == NULL)
		printf("Memory allocation failed");
	node->data = bag;
	node->next = NULL;

	if (head == NULL) {
		head = node;
	} else {
		node->next = head;
		head = node;
	}
	return (head);

}

int checkForCopy(SKITTLES_BAG_NODE *head, int bags) {
	if (bags == 1) {
		return 1;
	}
	int match = 1;
	int num_threads = 0;
#pragma omp parallel
	{
		SKITTLES_BAG_NODE *front;
		front = head->next;
		int id = omp_get_thread_num();
		num_threads = omp_get_num_threads();
		for (int j = 0; id < bags - 1 && j < id; j++) {
			front = front->next;
		}
		for (int i = id + num_threads; match != 0 && i < bags - 1; i += num_threads) {
		//for (int i = 0; i < bags - 1 && match != 0 ; i ++) {
			if (compareData(head->data, front->data) == 0) {
//				printf("Id: %d, found\n", id);
				match = 0;
			}
            for (int k = 0; k < num_threads; k++) {
            front = front->next;
            }
		}
//		if(match==0){
//			printf("another one\n");
//		}
	}
	return match;
}

int compareData(SKITTLES_BAG *newBag, SKITTLES_BAG *oldBag) {
	if ((newBag->orange == oldBag->orange) &&
			(newBag->yellow == oldBag->yellow) &&
			(newBag->green == oldBag->green) &&
			(newBag->red == oldBag->red) &&
			(newBag->purple == oldBag->purple)) {
//		printf("Comparing %d %d %d %d %d\n", oldBag->orange, oldBag->yellow, oldBag->green, oldBag->red, oldBag->purple );
//		printf("Comparing %d %d %d %d %d\n", newBag->orange, newBag->yellow, newBag->green, newBag->red, newBag->purple );
//		printf("Found\n");
		return 0;

	} else {
		return 1;
	}
}

