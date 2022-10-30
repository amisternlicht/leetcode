#include <vector>
#include <algorithm>
#include <iostream>

bool lessThan(const std::vector<int>& a,const std::vector<int>& b){
    return a[0] < b[0];
}

using intVec = std::vector<int>;

class Solution {
public:
    std::vector<intVec> merge(std::vector<intVec>& intervals) {
        std::vector<intVec> solution;
        //first sort the array by start_i
        std::sort(intervals.begin(),intervals.end(),lessThan);
        auto it = intervals.begin();
        int start = (*it)[0];
        int max = (*it)[1];
        for(auto it = intervals.begin();it != intervals.end(); it++){
            //if the next interval cant be merged then add the intervals up untill now 
            if((*it)[0] > max){
                intVec vec =  {start,max};
                solution.emplace_back(vec);
                start = (*it)[0];
                max = (*it)[1]; 
                //if this is the last interval add it as well
                if (it == intervals.end()-1){
                    intVec vec =  {start,max};
                    solution.emplace_back(vec); 
                }
            }
            //if the next interval can be merged and its end is larger than max
            else if((*it)[1] >= max){
                max = (*it)[1];
                //if its the last interval then add it
                if (it == intervals.end()-1){
                    intVec vec =  {start,max};
                    solution.emplace_back(vec); 
                }
            }
            else if(it == intervals.end()-1){
                intVec vec =  {start,max};
                solution.emplace_back(vec); 
            }
        }
        return solution;
    }
};

int main(){
    // intVec vec1 = {1,3};
    // intVec vec2 = {2,6};
    // intVec vec3 = {8,10};
    // intVec vec4 = {15,18};
    
    intVec vec1 = {1,4};
    intVec vec2 = {2,3};
    std::vector<intVec> vec = {vec1,vec2};
    Solution s;
    s.merge(vec);
}