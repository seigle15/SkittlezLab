/* Created by Sean Eigle and Trevor Ryles
	  11/30/19
*/

#ifndef SKITTLEZ_SKITTLESBAG_H
#define SKITTLEZ_SKITTLESBAG_H

#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#include "omp.h"


typedef struct skittlesBag {
		int purple, yellow, green, orange, red;
} SKITTLES_BAG;


extern int spot;
extern int size;
extern SKITTLES_BAG bags[2000];

SKITTLES_BAG *addToList(SKITTLES_BAG *head);

SKITTLES_BAG *createBag();

int checkForCopy(SKITTLES_BAG *);

int compareData(SKITTLES_BAG *newBag, SKITTLES_BAG *oldBag);

#endif //SKITTLEZ_SKITTLESBAG_H
