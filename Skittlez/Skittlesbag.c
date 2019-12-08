/**
 * @authors Trevor Ryles and Sean Eigle
 * @date 12/8/19
 */
#include "SkittlesBag.h"

#define TRUE 1
#define FALSE 0
#define BAG_SIZE 60

/**
 * Creates a new skittles bag and randomly assigns the number of skittles colors
 * to each bag out of a total of BAG_SIZE
 *
 * @return pointer to newly created SKITTLES_BAG
 */
SKITTLES_BAG *createBag() {
	SKITTLES_BAG *bag;
	size_t nodeSize;
	nodeSize = sizeof(SKITTLES_BAG);
	// allocate space for the bag
	if ((bag = calloc(nodeSize, TRUE)) == NULL)
		printf("Memory allocation failed");
	//randomly assign the number of skittles colors to a bag out of 60 total
	for (int i = 0; i < BAG_SIZE; i++) {
		switch (arc4random_uniform(5) + 1) {
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
	return bag;
}

/**
 * Adds a new bag to the list of old bags
 *
 * @param newBag - pointer to a newly created bag
 * @param bags  - list of old bags
 * @param bagNum  - number of the newly created bag
 * @return - next bag number
 */
int addToList(SKITTLES_BAG *newBag, SKITTLES_BAG bags[], int bagNum) {
	// adds newBag to list
	bags[bagNum] = *newBag;
	++bagNum;
	return bagNum;
}

/**
 * Checks for a copy of the new bag of skittles from the old bags of skittles
 *
 * @param newBag - new skittles bag
 * @param bags - old bags of skittles
 * @param bagNum - number of the new bag
 * @return - TRUE if a copy is found or false otherwise
 */
int checkForCopy(SKITTLES_BAG *newBag, SKITTLES_BAG bags[], int bagNum) {
	int match = FALSE;
	// for each bag of skittles in the list except for the newBag
	for (int i = 0; !match && i < bagNum - 1; ++i) {
		// compare the new bag to the current skittle
		if (compareData(newBag, &bags[i])) {
			match = TRUE;
		}
	}
	return match;

}

/**
 * Compares the new bag of skittles an old bag of skittles
 *
 * @param newBag - pointer to the new bag of skittles
 * @param oldBag - pointer to the old bag of skittles
 * @return - TRUE if both bags contain the same numbers of each color of skittle
 * 		or false otherwise
 */
int compareData(SKITTLES_BAG *newBag, SKITTLES_BAG *oldBag) {
	int matchFound = FALSE;
	// if the color count of the new pack is equal to the color count of the old pack
	if ((newBag->orange == oldBag->orange) &&
			(newBag->yellow == oldBag->yellow) &&
			(newBag->green == oldBag->green) &&
			(newBag->red == oldBag->red) &&
			(newBag->purple == oldBag->purple))
		matchFound = TRUE;
	return matchFound;
}