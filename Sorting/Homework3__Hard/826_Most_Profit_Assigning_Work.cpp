#include "../Sorting.h"

/**
 * maxProfitAssignment - this function find the most profit that can be achieved
 *
 * @param difficulty : difficulty of each job
 * @param profit : profit of each job
 * @param worker : job difficulty that worker can handle
 * @return : an integer represents the most profit that can be achieved
 */

/*
 * this is a poor version based on brute force that may not fit at leetcode
 * For every person:
 * 	 For every job
 * 		if job's difficulty <= person's difficulty
 * 			maximize person's profit
 *
 * This is a simple O(NQ).
 */

int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    int size = difficulty.size();
    int sum = 0;
    int max_prof = 0;

    for(int i = 0; i < worker.size(); i++){
        for(int j = 0; j < size; j++){
            if(worker[i] >= difficulty[j]){
                if(max_prof < profit[j])
                    max_prof = profit[j];
            }
        }
        sum += max_prof;
        max_prof = 0;
    }
    return (sum);
}

/**
 * maxProfitAssignment_V2 - second version of function
 *
 * @param difficulty
 * @param profit
 * @param worker
 * @return
 */

int maxProfitAssignment_V2(vector<int>& diff, vector<int>& prof, vector<int>& worker){
    vector<pair<int, int>> jobs;
    // Sort by difficulty
    for (int i = 0; i < (int) diff.size(); i++)
        jobs.push_back({diff[i], prof[i]});
    sort(worker.begin(), worker.end());
    sort(jobs.begin(), jobs.end());

    int job = 0, mxProfitSoFar = 0, total_profit = 0;
    for (int i = 0; i < (int) worker.size(); i++) {
        for (; job < (int)jobs.size() && worker[i] >= jobs[job].first; ++job)
            mxProfitSoFar = max(mxProfitSoFar, jobs[job].second);

        total_profit += mxProfitSoFar;	// Best profit for the ith worker
    }
    return total_profit;
}

/*
 *Assume N is the number of jobs, and Q is the number of people
 *
 * Observe: workerA has difficulty 10 and workerB has difficulty 15
 * 		Then workerB includes the max profit from workerA
 * 		In other words: if we know workerA can do jobs (x,y,z) with profit 70
 * 			workerB doesn't need to check (x,y,z). Just start from previous profit 70
 *
 *
 * How can we use this hint to skip duplicate operations?
 * First: Sort both the jobs and workers based on difficulty
 *
 * Assume jobs after sorting are
 * 	difficulty: 5 10 12 15 40
 * 	profit:     7 2  6  3  17
 *
 * We have sorted workers  [10, 15]
 * WorkerA: Scan as long as the job's difficulty <= his difficulty
 * 	This scans (5, 10) and takes max (7, 2) = 7
 *
 * Now workerB should scan (5, 10) and takes max (7, 2, 6, 3)
 * 	But why do this duplicates work
 * 		Just continue after workerA consider his profit
 * 			so only scan (6, 3) and their max with 7 ==> 7
 *
 * This is an example of making the processing smarter and faster by
 * 	figuring out where are the duplicate processing and HOW TO UTILIZE older computations
 *
 * Time Complexity: O(NlogN + QlogQ)  for the first 2 sorting operations
 * The profit calculation are just O(N+Q)
 *
 * Space Complexity:O(N) for jobs vector
 */