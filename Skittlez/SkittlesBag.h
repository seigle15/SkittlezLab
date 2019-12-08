/**
 * @authors Trevor Ryles and Sean Eigle
 * @date 12/8/19
 */

#ifndef SKITTLEZ_SKITTLESBAG_H
#define SKITTLEZ_SKITTLESBAG_H

#include <stdlib.h>
#include <stdio.h>

// struct containing attributes for the count of each color
// in the skittles bag
typedef struct skittlesBag {
		int purple, yellow, green, orange, red;
} SKITTLES_BAG;

/**
 * Adds a new bag to the list of old bags
 *
 * @param newBag - pointer to a newly created bag
 * @param bags  - list of old bags
 * @param bagNum  - number of the newly created bag
 * @return - next bag number
 */
int addToList(SKITTLES_BAG *newBag, SKITTLES_BAG bag[], int bagNum);

/**
 * Creates a new skittles bag and randomly assigns the number of skittles colors
 * to each bag out of a total of BAG_SIZE
 *
 * @return pointer to newly created SKITTLES_BAG
 */
SKITTLES_BAG *createBag();

/**
 * Checks for a copy of the new bag of skittles from the old bags of skittles
 *
 * @param newBag - new skittles bag
 * @param bags - old bags of skittles
 * @param bagNum - number of the new bag
 * @return - TRUE if a copy is found or false otherwise
 */
int checkForCopy(SKITTLES_BAG *newBag, SKITTLES_BAG bags[], int bagNum);

/**
 * Compares the new bag of skittles an old bag of skittles
 *
 * @param newBag - pointer to the new bag of skittles
 * @param oldBag - pointer to the old bag of skittles
 * @return - TRUE if both bags contain the same numbers of each color of skittle
 * 		or false otherwise
 */
int compareData(SKITTLES_BAG *newBag, SKITTLES_BAG *oldBag);

#endif //SKITTLEZ_SKITTLESBAG_H
