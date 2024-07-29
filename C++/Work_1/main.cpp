#include "calculator.hpp"

int main(){
    // std::string string;
    // std::cout<<"Input expration: ";
    // std::cin>>string;

    std::string string = "1 * 2 + 6 - 3 / 7";
    Calculator ob;
    std::cout << ob.calculate(string) << std::endl;
}