/* Created by Sean Eigle and Trevor Ryles
	  11/30/19
*/
#include "SkittlesBag.h"
#include "omp.h"
#define TRUE 1
#define FALSE 0



int main() {
    int id, thread_count;
    int totalRuns = 0;
    double allAverages = 0;
    int collectData = 0;
#pragma omp parallel private(thread_count, id)
	{
        int runs = 0;
        double averages;
        SKITTLES_BAG *newBag;
        id = omp_get_thread_num();
        int position = 0;
        SKITTLES_BAG bags[2000] = {0};

        //for(int i = 0; i < 5000; i++){
        while (TRUE) {
            int bagNum = 0;
            int sum = 0;
            position = 0;
            newBag = createBag();
            position = addToList(newBag, bags, position);
            bagNum++;
            while (!checkForCopy(newBag, bags, position)) {
                newBag = createBag();
                position = addToList(newBag, bags, position);
                bagNum++;
            }
            sum += bagNum;
            averages += (double) (sum);
            runs++;
            if(runs % 1000 == 0) {
                //printf("Average copies: %f -> runs: %d\n", (averages / runs), runs);
                allAverages += averages;
                totalRuns += runs;
                ++collectData;
                if (collectData == omp_get_num_threads()){
                    printf("Average of all Averages %f -- Total Runs %d\n", allAverages / totalRuns, totalRuns);
                    collectData = 0;
                }
            }
       }

	}


	return 0;
}

