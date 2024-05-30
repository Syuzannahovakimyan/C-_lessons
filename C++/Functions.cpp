#include <iostream>

int max_of_four(int, int, int, int);

int main() {
    int a,b,c,d;
    std::cout<<"my_numbers:";
    std::cin>>a>>b>>c>>d;
    std::cout<< "max_of_four is:"<<max_of_four(a,b,c,d)<<std::endl;
    return 0;
}



int max_of_two(int a, int b){
    if(a > b)
        return a;
    else 
        return b;
}

int max_of_four(int a , int b , int c , int d ){
    return max_of_two(max_of_two(a,b), max_of_two(c,d));
    
}
