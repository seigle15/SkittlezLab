#include "SkittlesBag.h"

int main() {
    SKITTLES_BAG_NODE *head = NULL;

    srand(time(0));
    int bagNum = 0;
    int sum = 0;
    int runs = 0;
    double averages;
    while(1){
        runs++;
        bagNum = 0;
        head = addToList(createBag(), head);
        bagNum++;
        while(checkForCopy(head, bagNum) != 0){
            head = addToList(createBag(), head);
            bagNum++;
        }
        sum += bagNum;
        averages = (double)(sum) / runs;
        printf("Average copies: %f\n", averages);

    }

//    for(int i = 0; i < 1000; i++){
//        bagNum = 0;
//        head = addToList(createBag(), head);
//        bagNum++;
//        while(checkForCopy(head, bagNum) != 0){
//            head = addToList(createBag(), head);
//            bagNum++;
//        }
//        sum += bagNum;
//    }
//    double averages;
//    averages = (double)(sum) / 1000.0;
//    printf("Average copies: %f", averages);



    return 0;
}