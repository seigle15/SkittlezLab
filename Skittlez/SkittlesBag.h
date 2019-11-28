//
// Created by Eigle, Sean on 2019-11-25.
//

#ifndef SKITTLEZ_SKITTLESBAG_H
#define SKITTLEZ_SKITTLESBAG_H

#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#include "omp.h"


typedef struct skittlesBag {
int purple, yellow, green, orange, red;
} SKITTLES_BAG;

//typedef struct bagNode{
//    struct bagNode *next;
//    SKITTLES_BAG *data;
//} SKITTLES_BAG_NODE;

static int spot = 0;
static int size = 0;
static SKITTLES_BAG bags[1000];
SKITTLES_BAG* addToList(SKITTLES_BAG *bag);

SKITTLES_BAG* createBag();

int checkForCopy(SKITTLES_BAG*);

int compareData(SKITTLES_BAG *newBag, SKITTLES_BAG *oldBag);

#endif //SKITTLEZ_SKITTLESBAG_H
