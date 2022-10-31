#include <vector>
#include <algorithm>
#include <iostream>

using intVec = std::vector<int>;

/*by jianchao-li: Search from the top-right element and reduce the search space by one row or column at each time. complexity O(m+n)*/
class Solution {
public:
    bool searchMatrix(std::vector<intVec>& matrix, int target) {
        int row = 0;
        int col = matrix[0].size() - 1;

        while(row < matrix.size() && col >= 0){
            if(matrix[row][col] == target){
                return true;
            }
            if(matrix[row][col] < target){
            //we know that the rest of the numbers in the row (to the left of matrix[row][col]) are definitely smaller as well
                ++row;
            }
            else {
            //matrix[row][col] > target
            //we know that the rest of the numbers in the col (under matrix[row][col]) are definitely larger as well
                --col;
            }
        }
        return false;
    }
};

int main(){   
    intVec vec1 = {1,4,7,11,15};
    intVec vec2 = {2,5,8,12,19};
    intVec vec3 = {3,6,9,16,22};
    intVec vec4 = {10,13,14,17,24};
    intVec vec5 = {18,21,23,26,30};
    std::vector<intVec> matrix = {vec1,vec2,vec3,vec4,vec5};
    int target = 30;
    Solution s;
    //bottom right
    if(!s.searchMatrix(matrix,target)){
        std::cout << target << " not found" << std::endl;
    }
    //top left
    target = 1;
    if(!s.searchMatrix(matrix,target)){
        std::cout << target << " not found" << std::endl;
    }
    //middle
    target = 13;
    if(!s.searchMatrix(matrix,target)){
        std::cout << target << " not found" << std::endl;
    }
    //not found
    target = 40;
    if(!s.searchMatrix(matrix,target)){
        std::cout << target << " not found" << std::endl;
    }
    return 0;
}