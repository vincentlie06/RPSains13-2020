#include <iostream>
#include <vector>
using namespace std;

bool in(vector<int> vec, int args){
    for(int x: vec){
        if (args==x)return true;
    }
    return false;
}

void print_ham(vector<int> vec){
    int s=vec.size();
    cout<<vec[0];
    for(int x=1; x<s; x++){
        cout<<" -> "<<vec[x];
    }
    cout<<endl;
}

vector<vector<int>> find_connection(int node,int connection_count, vector<vector<int>> connections){
    vector<vector<int>> arr;
    for(int x=0; x<connection_count; x+=1){
        if (connections[x][0]==node){
            arr.push_back(connections[x]);
        }
        else if(connections[x][1]==node){
            arr.push_back({node,connections[x][0]});
        }
    }
    return arr;
}

void dfs(int node,vector<vector<vector<int>>> updat-ed_con,vector<int>& storage,int node_count,vector<vector<int>>& ham_paths){
    int updated_con_size=(updated_con[node]).size();
    for(int a=0; a<updated_con_size;a+=1){
        int current_node=updated_con[node][a][1];
        if(!in(storage,current_node)){
            storage.push_back(current_node);
            dfs(current_node,updated_con,storage,node_count,ham_paths);
            storage.pop_back();
        }
    }
    if((storage.size())==node_count){
        ham_paths.push_back(storage);
    }
}
void find_ham(int node,vector<vector<vector<int>>> updated_con,int node_count,vector<vector<int>>& ham_paths){
    vector<int> storage;
    storage.push_back(node);
    dfs(node,updated_con,storage,node_count,ham_paths);
}

int main(){
    vector<vector<int>> connections= {{0, 1}, {1, 2}, {1, 3}, {2, 3}};
    vector<vector<float>> nodes= {{0, 0}, {1, 2}, {1, 3}, {2, 3}};
    vector<vector<int>> ham_paths;
    int node_count=nodes.size();
    int connection_count=connections.size();
    vector<vector<vector<int>>> updated_con;
    for(int a=0; a<node_count; a+=1){
        updated_con.push_back(find_connection(a,connection_count,connections));
    }
    for(int x=0; x<node_count; x+=1){
        find_ham(x,updated_con,node_count,ham_paths);
    }
    cout<<"List of Hamiltonian Paths: "<<endl;
    for(vector<int> ham_path: ham_paths){
        print_ham(ham_path);
    }
    return 0;
}
