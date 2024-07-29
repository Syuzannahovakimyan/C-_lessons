#include <iostream>
#include <vector>

std::vector<int> insertion_sort (std::vector<int> v );

std::vector<int> Input_vector(const std::string& msg);

int main(){
    std::vector<int> Sorting_vector = Input_vector("My vector is:");
    std::vector<int> My_vector = insertion_sort(Sorting_vector);
    std::cout<<"My result is:";
    for(int i = 0 ; i < My_vector.size(); ++i )
        std::cout<<My_vector[i]<<" ";
    std::cout<<std::endl;    
    return 0;
}

std::vector<int> Input_vector(const std::string& msg){
    std::vector<int> a;
    int n, k;
    std::cout<<"My vector size: ";
    std::cin>>n;
    if(!msg.empty()){
        std::cout<<msg;
    }
   
    for(int i = 0; i < n; ++i){
        std::cin>>k;
        a.push_back(k);
    }
    return a;
}

std::vector<int> insertion_sort (std::vector<int> v ){
    for(int j = 1; j < v.size(); ++j){
        int key = v[j];
        int i = j - 1;
        while(i > -1 && v[i] > key){
            v[i + 1] = v[i];
            i = i - 1;
        }
        v[i + 1] = key;
    }
    return v;
}