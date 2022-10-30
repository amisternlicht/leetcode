#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int mid = 2;
        while(matrix[mid][mid] > target || matrix[mid+1][mid+1] < target){
             if(matrix[mid][mid] > target){
                mid = mid/2;
             }
             else if(matrix[mid+1][mid+1] < target){
                mid = mid + (matrix[0].size()-mid)/2;
             }
        }
        if(matrix[mid][mid] == target){
            return true;
        }
        std::vector<int> temp1,temp2;
        for(int i=0; i<mid+1; i++){
           temp1.emplace_back(matrix[mid+1][i]);
           temp2.emplace_back(matrix[i][mid+1]); 
        }
        int result1 = std::binary_search(temp1.begin(),temp1.end(),target);
        int result2 = std::binary_search(temp2.begin(),temp2.end(),target);
        return result1 || result2;
    }
};

int main(){   
    std::vector<int> vec1 = {1,4,7,11,15};
    std::vector<int> vec2 = {2,5,8,12,19};
    std::vector<int> vec3 = {3,6,9,16,22};
    std::vector<int> vec4 = {10,13,14,17,24};
    std::vector<int> vec5 = {18,21,23,26,30};
    std::vector<std::vector<int>> matrix = {vec1,vec2,vec3,vec4,vec5};
    int target = 30;
    Solution s;
    s.searchMatrix(matrix,target);
    return 0;
}