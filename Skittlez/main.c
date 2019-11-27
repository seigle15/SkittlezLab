#include "SkittlesBag.h"
#include "omp.h"
int main() {
    SKITTLES_BAG_NODE *head = NULL;

    srand(time(0));
    int bagNum = 0;
    int sum = 0;
    int runs = 0;
    double averages;
		while (1) {
			++runs;
			bagNum = 0;
			head = addToList(createBag(), head);
			bagNum++;
			while (checkForCopy(head, bagNum) != 0) {
				head = addToList(createBag(), head);
					bagNum++;
			}
			sum += bagNum;
			averages = (double) (sum) / runs;
			printf("Average copies: %f -> runs: %d\n", averages, runs);

		}
    return 0;
}

