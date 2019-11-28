#include "SkittlesBag.h"
#include "omp.h"
#include "string.h"
int main() {

	SKITTLES_BAG* head;
	srand(time(0));
    int bagNum = 0;
    int sum = 0;
    int runs = 0;
    int averages;
		while (1) {
//			memset(bags, 0, 1000*sizeof(*bags));
			++runs;
			size = 0;
			head = addToList(createBag());
			bagNum++;
			while (checkForCopy(head) != 0) {
				head = addToList(createBag());
					bagNum++;
			}
			sum += bagNum;
			averages += (double) (sum);
			printf("Average copies: %f -> runs: %d\n", averages/runs, runs);

		}
    return 0;
}

