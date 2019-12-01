/* Created by Sean Eigle and Trevor Ryles
	  11/30/19
*/
#include "SkittlesBag.h"
#include "omp.h"
#include "string.h"
#define TRUE 1
#define FALSE 0

int main() {
	SKITTLES_BAG *newBag;
	srand(time(NULL));
	int runs = 0;
	double averages;
	while (TRUE) {
		int bagNum = 0;
		int sum = 0;
		newBag = addToList(createBag());
		bagNum++;
		while (!checkForCopy(newBag)) {
			newBag = addToList(createBag());
			bagNum++;
		}
		position = 0;
		sum += bagNum;
		averages += (double) (sum);
		runs++;
		printf("Average copies: %f -> runs: %d\n", (averages / runs), runs);
//		memset(bags, 0, sizeof(bags));
	}
	return 0;
}

