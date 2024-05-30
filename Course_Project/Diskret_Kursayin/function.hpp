#pragma once

#include <iostream>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <nlohmann/json.hpp>


nlohmann::json open_file_give_jsonObj();
std::unordered_map<int , std::vector<int>> conv_to_map(nlohmann::json jsonData);
bool adj_matrix_check(std::vector<std::vector<int>>& map);
std::vector<std::vector<int>> create_adj_matrix(std::unordered_map<int, std::vector<int>> &map);


class Graph {
    int V; 
    std::vector<std::vector<int>> adj;
public:
    Graph(int V);
    void addEdge(int u, int v);
    void DFSUtil(int v, std::vector<bool>& visited, std::vector<int>& path, std::vector<int>& longestPath);
    void findLongestChain();
};
