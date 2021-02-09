#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <vector>
using namespace std;
bool in(vector<int> vec, int args){
    for(int x: vec){
        if (args==x) return true;
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

void dfs(int node,vector<vector<vector<int>>> updated_con,vector<int>& storage,int node_count,vector<vector<int>>& ham_paths){
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

float getDist(vector<int>x, vector<int> y){
    int xDist=x[1]-y[1], yDist=x[0]-y[0];
    float Dist=sqrt(xDist*xDist+yDist*yDist);
    return Dist;
    }

float getAngle(vector<int> p1, vector<int> p2){
    float a=p2[1]-p1[1], b=p2[0]-p1[0];
    float c=atan2(a,b);
    float pi=2*acos(0.0);
    return 360-(c*180/pi);
}

int zoom(vector<vector<int>> nodes){
    vector<int> x=nodes[0], y=nodes[1];
    return int(250/getDist(x,y));
    }
int main(){
    vector<vector<int>> nodes={{0,0},{2,2},{2,0},{1,2}};
    vector<vector<int>> connections={{0,1},{1,2},{1,3},{2,3}};
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
    vector<vector<int>> zoomed_nodes;
    int magnitude = zoom(nodes);
    int WHeight=1000, WWidth=1000;
    for (vector<int> x: nodes){
        zoomed_nodes.push_back({x[0]*magnitude,x[1]*magnitude});
    }

    sf::RenderWindow window(sf::VideoMode(WHeight,WWidth), "Animation");
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        float Hcentre=WHeight/2, Wcentre=WWidth/2;
        for (vector<int> x : connections){
            sf::Vertex line[] =
            {
                sf::Vertex(sf::Vector2f(Hcentre+zoomed_nodes[x[0]][0], Wcentre-zoomed_nodes[x[0]][1])),
                sf::Vertex(sf::Vector2f(Hcentre+zoomed_nodes[x[1]][0], Wcentre-zoomed_nodes[x[1]][1]))
            };
            window.draw(line, 2, sf::Lines);
        }
        for (vector<int> node : zoomed_nodes){
            sf::CircleShape circle(10.f);
            circle.setPosition(Hcentre+node[0]-10,Wcentre-node[1]-10);
            window.draw(circle);
        }
        vector<int> path=ham_paths[0];
        for (int i=0; i<node_count-1; i++){
            vector<int> a=zoomed_nodes[path[i]], b=zoomed_nodes[path[i+1]];
            float dist=getDist(a,b), angle=getAngle(a,b);
            sf::RectangleShape line(sf::Vector2f(dist, 5.f));
            line.rotate(angle);
            line.setPosition(Hcentre+zoomed_nodes[i][0],Wcentre-zoomed_nodes[i][1]);
            window.draw(line);
    }
    window.display();
    }
}
