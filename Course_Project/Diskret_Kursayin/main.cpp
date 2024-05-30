#include "function.hpp"

using json = nlohmann::json;


int main() {

    json jsonData = open_file_give_jsonObj();

    std::unordered_map<int, std::vector<int>> map_data = conv_to_map(jsonData);

    auto adj_matrix = create_adj_matrix(map_data);

    if(adj_matrix_check(adj_matrix))
        return 1;

    Graph graph(adj_matrix.size());


    for(int i = 0; i < adj_matrix.size(); ++i){
        for(int j = i; j < adj_matrix.size(); ++j){
            if(adj_matrix[i][j] == 1)
                graph.addEdge(i,j);
        }
    }
    
    graph.findLongestChain();

    return 0;
}

