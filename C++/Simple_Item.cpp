#include <iostream>
#include <vector>

int findSimpleItem(const std::vector<char>& arr) {
    int result = 0;
    for (int num : arr) {
        result ^= num;
    }
    return result;
}

int main() {
    //std::vector<char> myVector = {'d', 'd', 's', 'r', 'y', 'o', 'r', 'o', 'y'};
    std::vector<char> myVector = {'1','2','3','4','5','4','3','2','1'};
    int result = findSimpleItem(myVector);
    std::cout << "Simple item: " << char(result) << std::endl;
    return 0;
}
