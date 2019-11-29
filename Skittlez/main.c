#include "SkittlesBag.h"
#include "omp.h"
#include "string.h"
int main() {
	static const SKITTLES_BAG new;
	SKITTLES_BAG* head;
	srand(time(0));
    int bagNum = 0;
    int sum = 0;
    int runs = 0;
    double averages;
		while (1) {
			bagNum = 0;
			sum = 0;
			memset(bags, 0, sizeof(bags));
			++runs;
			size = 0;
			head = addToList(createBag());
			bagNum++;
			while (checkForCopy(head) != 0) {
				head = addToList(createBag());
					bagNum++;
			}
			spot = 0;
			sum += bagNum;
			averages += (double) (sum);
			printf("Average copies: %f -> runs: %d\n", (averages/runs), runs);
		}
    return 0;
}

