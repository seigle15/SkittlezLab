/* Created by Sean Eigle and Trevor Ryles
	  11/30/19
*/
#include "SkittlesBag.h"

#define TRUE 1
#define FALSE 0

SKITTLES_BAG *createBag() {
	//Set rand time to produce random numbers every time
	SKITTLES_BAG *bag;
	size_t nodeSize;
	//create space for bag
	nodeSize = sizeof(SKITTLES_BAG);
	if ((bag = calloc(nodeSize, TRUE)) == NULL)
		printf("Memory allocation failed");
	//randomly assign number of skittles
	for (int i = 0; i < 60; i++) {
		switch (arc4random_uniform(5) + 1) {
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
	return bag;

}

int addToList(SKITTLES_BAG *head, SKITTLES_BAG bags[], int position) {
	bags[position] = *head;
	position++;
	return position;
}

int checkForCopy(SKITTLES_BAG *head, SKITTLES_BAG bags[], int position) {
	int match = FALSE;
    for (int i = 0; !match && i < position - 1; ++i){
		//for (int i = id; !match && i < position - 1; i += thread_count) {
			if (compareData(head, &bags[i])) {
				match = TRUE;
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