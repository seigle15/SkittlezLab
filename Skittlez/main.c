#include "SkittlesBag.h"

int main() {
    SKITTLES_BAG_NODE *head = NULL;

    srand(time(0));
    int bagNum = 0;

    bagNum++;
    head = addToList(createBag(), head);
    while(checkForCopy(head, bagNum) != 0){
        head = addToList(createBag(), head);
        bagNum++;
    }

    printf("Number of bags: %d\n", bagNum);
    printf("The Copy: green %d, orange %d, purple %d, red %d, yellow %d \n", head->data->green, head->data->orange, head->data->purple, head->data->red, head->data->yellow);

    return 0;
}