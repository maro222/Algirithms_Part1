#include "../BinarySearch.h"

/**
 *
 * @param bloomDay
 * @param total_bouquets
 * @param flowerPerBouquets
 * @param waitingDays
 * @return
 */
bool possible(vector<int> bloomDay, int total_bouquets, int flowerPerBouquets, int waitingDays){
    int flower_adj = 0, bouquets = 0;

    for (int i = 0; i < bloomDay.size(); i++){
        if (waitingDays >= bloomDay[i]){
            flower_adj++;

            if (flower_adj == flowerPerBouquets) // start counting for a new bouquet
                bouquets++, flower_adj = 0;

            if (bouquets == total_bouquets)  //more efficient to stop early
                return (true);
        }
        else
            flower_adj = 0;
    }
    return (false);
}

/**
 *
 * @param bloomDay
 * @param m
 * @param k
 * @return
 */

int minDays(vector<int> bloomDay, int m, int k){
    int start = 1, end = *max_element(bloomDay.begin(), bloomDay.end());
    int minDay = -1;

    if (m > bloomDay.size() / k)                // avoid overflow
        return (minDay);
    // binary search on days from day 1 to the last day of blooming all the flowers (virtual array sorted)
    while (start <= end){
        int mid = start + (end - start) / 2;

        if (possible(bloomDay, m, k, mid)){
            end = mid - 1;
            minDay = mid;
        }
        else
            start = mid + 1;
    }
    return (minDay);
}