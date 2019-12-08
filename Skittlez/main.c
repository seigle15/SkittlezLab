/**
 * @authors Trevor Ryles and Sean Eigle
 * @date 12/8/19
 * This program simulates opening packs of skittles
 * and then calculating the average number of packs until a duplicate is found.
 *
 * The main method runs a parallelized simulation of opening a bag
 * and checking for a copy.
 * Each thread stores data about its independent bag opening and comparison process.
 * Every after every 1000 runs of this process, the threads
 * add their information to the metadata, which uses this information to calculate
 * and output the current average number of packs until a duplicate is found.
 * The program runs until stopped, or indefinitely.
*/
#include "SkittlesBag.h"
#include "omp.h"

#define TRUE 1
#define FALSE 0
#define RELAY_NUM 1000

int main() {
	/*
	 * Terminology
	 *
	 * run - defined as one simulation of opening packs of skittles until
	 * 		a duplicate is found.
	*/

	/*
	 * Public variable declaration:
	 * defines shared variables public in scope to each thread.
	 *
	 * totalRuns - the combined total of runs from each thread.
	 *
	 * totalBagCount - the combined total of bags opened from each thread.
	 *
	 * collectData - used to output allAverages when each thread reaches an
	 * 		increment of RELAY_NUM
	 *
	 * num_threads - number of threads available to the program
	 */

	int totalRuns = 0;
	double totalBagCount = 0;
	int collectData = 0;

#pragma omp parallel
	{
		/*
		 * Private variable declaration:
 		 * defines variables private in scope to each thread.
		 *
		 * runs - number of accumulated runs
		 *
		 * bagCount - the total number of bags that have been opened
		 *
		 * *newBag - pointer to the newest bag opened
		 *
		 * bags[2000] - used to store bags
 		*/

		int runs = 0;
		SKITTLES_BAG *newBag;
		int bagCount = 0;
		SKITTLES_BAG bags[2000] = {0};

		while (TRUE) {
			/*
			 * Local scope variables:
			 * bagNum - number of the current bag that is being opened
			*/

			int bagNum = 0;
			// create the first skittles bag
			newBag = createBag();
			// add the the first bag to the collection
			bagNum = addToList(newBag, bags, bagNum);
			// while no copies of bags have been found
			// open a new bag, add it to the collection of bags, and compare it to the other bags
			while (!checkForCopy(newBag=createBag(), bags, bagNum)) {
                bagNum=addToList(newBag, bags, bagNum);
			 // stops when a copy has been found
			}
			// once a copy has been found
			// add the amount of newly opened bags
			// to the total number of bags that have been opened
			bagCount += bagNum;
			runs++;
			// every 1000 runs collect and output a summary
			// of information from all the threads
			// update the totalRuns and count of allBagsOpened from the threads
			if (runs % RELAY_NUM == 0) {
				totalBagCount += bagCount;
				totalRuns += runs;
				++collectData;
				if (collectData == omp_get_num_threads()) {
					printf("Average of all Averages %f -- Total Runs %d\n", totalBagCount / totalRuns, totalRuns);
					collectData = 0;
				}
			}
		}
	}
	return 0;
}

