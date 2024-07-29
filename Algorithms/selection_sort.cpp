#include <iostream>
#include <vector>

template <typename T>
std::vector<T> Input(const std::string& msg);

template <typename T>
std::vector<T> selection_sort(std::vector<T> v);

template <typename T>
void Output(std::vector<T>& my_vector);

int main(){
    auto my_vector = Input<int>("My_vector is:");
    my_vector = selection_sort(my_vector);
    Output(my_vector);
    return 0;
}


template <typename T>
std::vector<T> Input(const std::string& msg){
    std::vector<T> v;
    int n;
    std::cout<<"My vector size is:";
    std::cin>>n;
    if(!msg.empty()){
        std::cout<<msg;
    }
    T a;
    for(int i = 0; i < n; ++i ){
        std::cin>>a;
        v.push_back(a);
    }
    return v;
}

template <typename T>
std::vector<T> selection_sort(std::vector<T> v){
    for(auto i = 0; i < v.size() - 1; ++i){
        auto min = i;
        for(int j = i + 1; j < v.size(); ++j){
            if(v[j] < v[min])
                min = j;
        } 
    std::swap(v[min],v[i]);    
    }
    return v;
}

template <typename T>
void Output(std::vector<T>& my_vector){
    for(int i = 0; i < my_vector.size(); ++i ){
        std::cout<<my_vector[i]<<" ";
    }
    std::cout<<std::endl;
}
