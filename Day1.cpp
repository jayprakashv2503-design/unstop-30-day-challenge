#include <iostream>
#include <vector>
#include <deque>

std::vector<int> calculatePeakReadings(int n, int k, const std::vector<int>& readings) {
    std::vector<int> peaks;
    std::deque<int> dq;
    
    for (int i = 0; i < n; ++i) {
        // Remove elements not within the current window
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }
        
        // Remove elements that are smaller than the current element 
        // from the back of the deque
        while (!dq.empty() && readings[dq.back()] <= readings[i]) {
            dq.pop_back();
        }
        
        // Add current element's index
        dq.push_back(i);
        
        // Add to result if our window has reached size k
        if (i >= k - 1) {
            peaks.push_back(readings[dq.front()]);
        }
    }
    
    return peaks;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector<int> readings(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> readings[i];
    }
    
    std::vector<int> result = calculatePeakReadings(n, k, readings);
    
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i != result.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    
    return 0;
}
