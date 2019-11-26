//
// Created by Eigle, Sean on 2019-11-25.
//
#include "SkittlesBag.h"

SKITTLES_BAG *createBag(){
    //Set rand time to produce random numbers every time
    SKITTLES_BAG *bag;
    size_t nodeSize;

    //create space for bag
    nodeSize = sizeof(SKITTLES_BAG);
    if ((bag = calloc(nodeSize, 1)) == NULL)
        printf("Memory allocation failed");

    //randomly assign number of skittles
    while ((bag->green + bag->orange + bag->purple + bag->red + bag->yellow) < 60){
        switch ((rand() % 5) + 1){
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

SKITTLES_BAG_NODE* addToList(SKITTLES_BAG *bag, SKITTLES_BAG_NODE *head, SKITTLES_BAG_NODE *tail){
    SKITTLES_BAG_NODE *node;
    size_t nodeSize;
    nodeSize = sizeof(SKITTLES_BAG_NODE);
    if ((node = calloc(nodeSize, 1)) == NULL)
        printf("Memory allocation failed");
    node->data = bag;

    if(head == NULL){
        head = node;
        head->next = NULL;
        head->prev = NULL;
        tail = head;
        return head;
    }
    if(tail == head){
        node->prev = NULL;
        tail->prev = node;
        node->next = head;
        head = node;
    } else{
        node->prev = NULL;
        head->prev = node;
        node->next = head;
        head = node;
    }
    return head;

}

int checkForCopy(SKITTLES_BAG_NODE *head, SKITTLES_BAG_NODE *tail){
    if(head == tail){
        return 1;
    }
    SKITTLES_BAG_NODE *front, *back;
    front = head;
    back = tail;
    int match = 1;

    while(front != back && match != 0){
        if((head->data == front->data || head->data == back->data)){
            match = 0;
        }
        else{
            front = front->next;
            back = back->prev;
        }
    }
    return match;

}

int compareData(SKITTLES_BAG ){

}