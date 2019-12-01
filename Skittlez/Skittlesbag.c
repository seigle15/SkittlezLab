/* Created by Sean Eigle and Trevor Ryles
	  11/30/19
*/
#include "SkittlesBag.h"
#include "omp.h"
#define TRUE 1
#define FALSE 0

int position = 0;
SKITTLES_BAG bags[2000] = {0};

SKITTLES_BAG *createBag() {
	//Set rand time to produce random numbers every time
	SKITTLES_BAG *bag;
	size_t nodeSize;
	//create space for bag
	nodeSize = sizeof(SKITTLES_BAG);
	if ((bag = calloc(nodeSize, TRUE)) == NULL)
		printf("Memory allocation failed");
	//randomly assign number of skittles
#pragma omp parallel
	{
#pragma omp for
		for (int i = 0; i < 60; i++) {
			switch ((rand() % 5) + 1) {
				case 1:
#pragma omp atomic
					bag->green++;
					break;
				case 2:
#pragma omp atomic
					bag->orange++;
					break;
				case 3:
#pragma omp atomic
					bag->purple++;
					break;
				case 4:
#pragma omp atomic
					bag->red++;
					break;
				case 5:
#pragma omp atomic
					bag->yellow++;
					break;
			}
		}
	}
	return bag;

}

SKITTLES_BAG *addToList(SKITTLES_BAG *head) {
	bags[position] = *head;
	position++;
	return head;
}

int checkForCopy(SKITTLES_BAG *head) {
	int match = FALSE;
#pragma omp parallel
	{
		int thread_count = omp_get_num_threads();
		int id = omp_get_thread_num();
		for (int i = id; !match && i < position - 1; i += thread_count) {
			if (compareData(head, &bags[i])) {
				match = TRUE;
			}
		}
	}
	return match;

}

int compareData(SKITTLES_BAG *newBag, SKITTLES_BAG *oldBag) {
	int matchFound = FALSE;
	if ((newBag->orange == oldBag->orange) &&
			(newBag->yellow == oldBag->yellow) &&
			(newBag->green == oldBag->green) &&
			(newBag->red == oldBag->red) &&
			(newBag->purple == oldBag->purple)) {
//					printf("Comparing %d %d %d %d %d\n", oldBag->orange, oldBag->yellow, oldBag->green, oldBag->red, oldBag->purple );
//		printf("Comparing %d %d %d %d %d\n", newBag->orange, newBag->yellow, newBag->green, newBag->red, newBag->purple );
//		printf("Found\n");
		matchFound = TRUE;
	}
	return matchFound;
}