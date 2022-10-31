#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

// getting subvector 
//The idea is to get input iterators to the starting and ending position in the vector and pass them to the range constructor of the vector class to get a sub-vector.
// template<typename T>
// std::vector<T> slice(std::vector<T> const &v, int m, int n)
// {
//     auto first = v.cbegin() + m;
//     auto last = v.cbegin() + n + 1;
 
//     std::vector<T> vec(first, last);
//     return vec;
// }

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        int count = 0, sum = 0;
        std::unordered_map<int,int> sumDiffOccurenceMap;
        sumDiffOccurenceMap.emplace(0, 1);
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sumDiffOccurenceMap.count(sum - k) != 0){
                count += sumDiffOccurenceMap[sum - k];
            }
            sumDiffOccurenceMap[sum]++;
        }
        return count;
    }
    //dynamic programming approach
    // int subarraySum(std::vector<int>& nums, int k) {
    //     if(nums.size() == 0){
    //         if(k == 0){
    //             return 1;
    //         }
    //         return 0;
    //     }
    //     std::vector<int> sub_vec = slice(nums,0, nums.size()-1);
    //     return subarraySum(sub_vec,k - nums[nums.size()-1]) + subarraySum(sub_vec,k);
    // }
};

int main(){   
    std::vector<int> vec1 = {1,4,2,-2,3};
    std::vector<int>  vec2 = {-1,1,0,3,2};
    Solution s;
    int result1 = s.subarraySum(vec1,0); 
    int result2 = s.subarraySum(vec2,3); 
    int result3 = s.subarraySum(vec1,5); 
    return 0;
}