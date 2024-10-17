#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int minSubarray(vector<int>& nums, int p) {
    int totalSum = 0;
    
    // Calculate total sum at once
    for (int num : nums) {
        totalSum += num;
    }
    
    // Apply modulo at the end
    int target = totalSum % p;
    if (target == 0) return 0;  // Already divisible by p, no need to remove anything
    
    unordered_map<int, int> prefixModIndex;
    prefixModIndex[0] = -1;  // To handle case where removing prefix makes sum divisible
    int prefixSum = 0;
    int minLen = nums.size();
    
    for (int i = 0; i < nums.size(); ++i) {
        prefixSum = (prefixSum + nums[i]) % p;
        int neededSum = (prefixSum - target + p) % p;
        
        if (prefixModIndex.find(neededSum) != prefixModIndex.end()) {
            minLen = min(minLen, i - prefixModIndex[neededSum]);
        }
        
        // Update map with current prefix sum mod p
        prefixModIndex[prefixSum] = i;
    }
    
    return minLen == nums.size() ? -1 : minLen;
}

int main() {
    vector<int> nums = {3, 1, 4, 2};
    int p = 6;
    cout << minSubarray(nums, p) << endl;
    return 0;
}
