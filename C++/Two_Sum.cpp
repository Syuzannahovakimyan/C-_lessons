#include <iostream>
#include <vector>

class Solution {   
public:
         Solution(){};
         ~Solution(){};
         std:: vector<int> twoSum(std::vector<int>& nums, int target) {
             std:: vector<int> Sum;
             for(int i = 0; i < nums.size();++i){
                 for(int j = i+1; j < nums.size();++j){
                     if(nums[i] + nums[j] == target){
                         Sum.push_back(i);
                         Sum.push_back(j);
                     }
                 }   
             }
             return Sum;
         }   
};

int main(){
    Solution ob;
    //std::vector<int> MyVector = {4,6,8,5};
    std::vector<int> MyVector = {8,5,1,10,4};
    int Target = 14;
    std::vector<int> Solution = ob.twoSum(MyVector,Target);
    std::cout << "Two_Sum: ";
    for(int i = 0; i < Solution.size(); ++i)
        std::cout << Solution[i] << " ";
    std::cout << std::endl;    

}