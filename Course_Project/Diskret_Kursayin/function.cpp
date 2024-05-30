#include "function.hpp"

using json = nlohmann::json;

using std::cout;
using std::cin;
using std::endl;

nlohmann::json open_file_give_jsonObj(){
    std::string k;
    cout << "Include  JSON absolute path:  ";
    cin >> k; 

    std::ifstream file(k);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        std::exit(0);
    }
    nlohmann::json data;
    try{
        file >> data;
    }catch(const nlohmann::detail::parse_error e){
        cout << "JSON format is not preserved " << endl;
        std::exit(0);
    }
    // or 
    // json data = json::parse(file);
    file.close();
    return data;
}


std::unordered_map<int , std::vector<int>> conv_to_map(json jsonData){
    std::unordered_map<int, std::vector<int>> map_data;
    for (auto& [key, value] : jsonData.items()) {
        int mapKey = stoi(key);
        std::vector<int> mapValue = value.get<std::vector<int>>();
        map_data[mapKey] = mapValue;
    }
    return map_data; 
}


std::vector<std::vector<int>> create_adj_matrix(std::unordered_map<int, std::vector<int>>& map){
    
    int size_matrix = map.size();
    std::vector<std::vector<int>> adj_matr(size_matrix, std::vector<int>(size_matrix, 0));
    for (auto it = map.begin(); it != map.end(); ++it) {
        int row = it->first;
        for (auto val : it->second) {
            adj_matr[row][val] = 1;
        }
    }
    return adj_matr;
}


bool adj_matrix_check(std::vector<std::vector<int>>& adj_matrix){
    int size_matrix = adj_matrix.size();
    for(int i = 0; i < size_matrix; ++i){
        for(int j = i; j < size_matrix; ++j){
            if(adj_matrix[i][j] != adj_matrix[j][i]){
                cout << "ERROR: adjacency matrix is'n sematric when i = "<< i << ": and j = "<< j << endl;
                return true;
            }
            if(adj_matrix[i][i] != 0){
                cout << "ERROR: graph have a cycle in "<< i << " edge"<< endl;
                return true;
            }
        }
    }
    return false;
}


/**************************************************class Graph defination***********************************************************/

Graph::Graph(int V) : V(V) {
        adj.resize(V);
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::DFSUtil(int v, std::vector<bool>& visited, std::vector<int>& path, std::vector<int>& longestPath) {
    visited[v] = true;
    path.push_back(v);

    for (int u : adj[v]) {
        if (!visited[u]) {
            DFSUtil(u, visited, path, longestPath);
        }
    }

    if (path.size() > longestPath.size()) {
        longestPath = path;
    }

    // Backtrack
    path.pop_back();
    visited[v] = false;
}

void Graph::findLongestChain() {
    std::vector<bool> visited(V, false);
    std::vector<int> path, longestPath;

    for (int v = 0; v < V; ++v) {
        if (!visited[v]) {
            DFSUtil(v, visited, path, longestPath);
        }
    }

    cout << "Longest chain length in the graph: " << longestPath.size() << endl;
    cout << "Edges in the longest chain:" << endl;
    for (int i = 0; i < longestPath.size() - 1; ++i) {
        if(i == longestPath.size() - 2){
            cout  << longestPath[i] << " -> " << longestPath[i + 1] << endl;
            continue;
        }
        cout << longestPath[i] << " -> ";
    }
}
