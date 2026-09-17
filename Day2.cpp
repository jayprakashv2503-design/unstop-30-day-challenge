#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestAffordableStreak(const vector<long long>& cost, int n, long long budget) {
    int max_streak = 0;
    int left = 0;
    long long current_spend = 0;
    
    for (int right = 0; right < n; ++right) {
        // Expand the window by including the current day's cost
        current_spend += cost[right];
        
        // If the window exceeds the budget, shrink it from the left
        while (current_spend > budget && left <= right) {
            current_spend -= cost[left];
            left++;
        }
        
        // Update the maximum streak found so far
        max_streak = max(max_streak, right - left + 1);
    }
    
    return max_streak;
}

int main() {
    int n;
    long long budget;
    
    // Read input for n and budget
    if (!(cin >> n >> budget)) return 0;
    
    // Read the entry fees for each day
    vector<long long> cost(n);
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }
    
    // Call the user logic function and print the output
    int result = longestAffordableStreak(cost, n, budget);
    cout << result << endl;
    
    return 0;
}
