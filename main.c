#include "SkittlesBag.h"

int main() {
    //SKITTLES_BAG *test;
    SKITTLES_BAG_NODE *head = NULL;
    SKITTLES_BAG_NODE *tail = NULL;
    //test = createBag();
    srand(time(0));
    int bagNum = 0;

    bagNum++;
    addToList(createBag(), head, tail);
    while(checkForCopy(head, tail) != 0){
        addToList(createBag(), head, tail);
        printf("bag: %d\n", bagNum);
        bagNum++;
    }

    printf("Number of bags: %d\n", bagNum);
    printf("The Copy: green %d, orange %d, purple %d, red %d, yellow %d \n", head->data->green, head->data->orange, head->data->purple, head->data->red, head->data->yellow);

//    for(int i = 0; i < 9; i++){
//        head = addToList(createBag(), head, tail);
//        printf("%d, %d, %d, %d, %d \n", head->data->green, head->data->orange, head->data->purple, head->data->red, head->data->yellow);
//        printf("%d\n", head->data->green + head->data->orange + head->data->purple + head->data->red + head->data->yellow);
//    }


    return 0;
}