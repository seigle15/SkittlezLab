/* Created by Sean Eigle and Trevor Ryles
	  11/30/19
*/
#include "SkittlesBag.h"
#include "omp.h"
#define TRUE 1
#define FALSE 0

int spot = 0;
int size = 0;
SKITTLES_BAG bags[2000] = {0};

SKITTLES_BAG *createBag() {
	//Set rand time to produce random numbers every time
	SKITTLES_BAG *bag;
	size++;
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
					bag->green++;
					break;
				case 2:
					bag->orange++;
					break;
				case 3:
					bag->purple++;
					break;
				case 4:
					bag->red++;
					break;
				case 5:
					bag->yellow++;
					break;
			}
		}
	}
	return bag;

}

SKITTLES_BAG *addToList(SKITTLES_BAG *head) {
	bags[spot] = *head;
	spot++;
	return head;
}

int checkForCopy(SKITTLES_BAG *head) {
	int match = FALSE;
#pragma omp parallel
	{
#pragma omp for
		for (int i = 0; i < size - 1; i++) {
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