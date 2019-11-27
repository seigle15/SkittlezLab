//
// Created by Eigle, Sean on 2019-11-25.
//
#include "SkittlesBag.h"
#include "omp.h"

SKITTLES_BAG* createBag(){
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
	}
    return bag;

}

SKITTLES_BAG_NODE* addToList(SKITTLES_BAG *bag, SKITTLES_BAG_NODE *head){
    SKITTLES_BAG_NODE *node;
    size_t nodeSize;
    nodeSize = sizeof(SKITTLES_BAG_NODE);
    if ((node = calloc(nodeSize, 1)) == NULL)
        printf("Memory allocation failed");
    node->data = bag;
    node->next = NULL;

    if(head == NULL){
        head = node;
    } else{
        node->next = head;
        head = node;
    }
    return (head);

}

int checkForCopy(SKITTLES_BAG_NODE *head, int bags){
    if(bags == 1){
        return 1;
    }
    int match = 1;
//#pragma omp parallel
//	{
		SKITTLES_BAG_NODE *front;
		front = head->next;
//		int num_threads = omp_get_num_threads();
//		int id = omp_get_thread_num();
//		for(int j=0;j<id;j++){
//			front = front->next;
//		}
		for (int i = 0; i < bags - 1; i++) {
			if (compareData(head->data, front->data) == 0) {
				match = 0;
			} else {
				front = front->next;
			}
		}
//	}
    return match;

}

int compareData(SKITTLES_BAG *newBag, SKITTLES_BAG *oldBag){
    if ((newBag->orange == oldBag->orange) &&
            (newBag->yellow == oldBag->yellow) &&
            (newBag->green == oldBag->green) &&
            (newBag->red == oldBag->red) &&
            (newBag->purple == oldBag->purple)){
        return 0;

    }
    else{
        return 1;
    }

}