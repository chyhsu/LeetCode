/*You are given a 0-indexed integer array costs where costs[i] is the cost of hiring the ith worker.

You are also given two integers k and candidates. We want to hire exactly k workers according to the following rules:

You will run k sessions and hire exactly one worker in each session.
In each hiring session, choose the worker with the lowest cost from either the first candidates workers or the last candidates workers. Break the tie by the smallest index.
For example, if costs = [3,2,7,7,1,2] and candidates = 2, then in the first hiring session, we will choose the 4th worker because they have the lowest cost [3,2,7,7,1,2].
In the second hiring session, we will choose 1st worker because they have the same lowest cost as 4th worker but they have the smallest index [3,2,7,7,2]. Please note that the indexing may be changed in the process.
If there are fewer than candidates workers remaining, choose the worker with the lowest cost among them. Break the tie by the smallest index.
A worker can only be chosen once.
Return the total cost to hire exactly k workers.*/
#include <functional>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long total_cost = 0;
        priority_queue<int, vector<int>, greater<int>> first_heap;
        priority_queue<int, vector<int>, greater<int>> second_heap;

        int n = costs.size();
        int left = 0;
        int right = n - 1;

        // Initially, fill the heaps with the first and last 'candidates' workers,
        // ensuring we don't double-count if the ranges overlap.
        for (int i = 0; i < candidates; ++i) {
            if (left <= right) {
                first_heap.push(costs[left++]);
            }
        }
        for (int i = 0; i < candidates; ++i) {
            if (left <= right) {
                second_heap.push(costs[right--]);
            }
        }

        for (int i = 0; i < k; ++i) {
            // Use a large value for empty heaps to simplify comparison
            long long cost1 = first_heap.empty() ? LLONG_MAX : first_heap.top();
            long long cost2 = second_heap.empty() ? LLONG_MAX : second_heap.top();

            if (cost1 <= cost2) {
                total_cost += cost1;
                first_heap.pop();
                // Add the next worker from the left pool if available
                if (left <= right) {
                    first_heap.push(costs[left++]);
                }
            } else {
                total_cost += cost2;
                second_heap.pop();
                // Add the next worker from the right pool if available
                if (left <= right) {
                    second_heap.push(costs[right--]);
                }
            }
        }

        return total_cost;
    }
};

/*
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans=0;
        if(candidates*2>=costs.size()){
          sort(costs.begin(), costs.end());
          for(int i=0; i<k; i++){
            ans+=costs[i];
          }
          return ans;
        }
         priority_queue<int, vector<int>, greater<int>>pq1;    priority_queue<int, vector<int>, greater<int>>pq2; 
         int a=candidates; int b=costs.size()-candidates-1;
         for(int i=0; i<candidates; i++){
            pq1.push(costs[i]);
            pq2.push(costs[costs.size()-1-i]);
         }
         //int a=candidates; int b=costs.size()-candidates-1; 
         while(k){

           if(a>b){
             if(pq1.empty()){
                ans+=pq2.top(); pq2.pop();
             }
             else if(pq2.empty()){
                ans+=pq1.top(); pq1.pop();
             }

             else if(pq1.top()<=pq2.top()){
                ans+=pq1.top(); pq1.pop();
                
             }
             else{
                ans+=pq2.top(); pq2.pop();
             }
             
           } 

           else if(pq1.top()<=pq2.top()){
             ans+=pq1.top(); pq1.pop();
                pq1.push(costs[a]);
                a++;
           }

           else{
            ans+=pq2.top(); pq2.pop();
                pq2.push(costs[b]);
                b--;

           }

           k--; 
         }
         return ans;
    }
};
*/