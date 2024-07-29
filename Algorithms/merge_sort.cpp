#include <iostream>
#include <vector>

template <typename T>
void merge(std::vector<T>& a, int p, int q, int r );

template <typename T>
void merge_sort(std::vector<T>& a, int p, int r);

template <typename T>
std::vector<T> Input(const std::string& msg);

template <typename T>
void Output(std::vector<T>& my_vector);


int main(){
    std::vector<int> A = Input<int>("My vector is: ");
    merge_sort(A,0,A.size() - 1);
    Output(A);
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
    for(int i = 1; i <= n; ++i ){
        std::cin>>a;
        v.push_back(a);
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

template <typename T>
void merge(std::vector<T> &A, int p, int q, int r){
    int n1 = q - p + 1; 
    int n2 = r - q;
    std::vector<T> L;
    std::vector<T> R;
    for(int i = 0; i < n1; ++i ){
        L.push_back(A[p + i]);
    }
    for(int i = 0; i < n2; ++i ){
        R.push_back(A[q + i + 1]);
    }
    int i = 0, j = 0; 
    int k = p;
    while(i != n1  && j != n2 ){
        if(L[i] <= R[j]){
            A[k] = L[i];
            ++i;
        }
        else{
            A[k] = R[j];
            ++j;
        }
        ++k;
    }
    if(i == n1){
        for(int m = j; m < n2; ++m){
            A[k] = R[m];
            ++k;
        }
    }
    if(j == n2){
        for(int m = i; m < n1; ++m){
            A[k] = L[m];
            ++k;
        }
    }
}

template <typename T>
void merge_sort(std::vector<T> &A, int p, int r){
    if(p < r){
        int q = (p + r)/2;
        merge_sort(A,p,q);
        merge_sort(A,q + 1,r);
        merge(A,p,q,r);
    }
}
