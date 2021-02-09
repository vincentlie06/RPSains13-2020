#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <vector>
using namespace std;

float getDist(vector<float>x, vector<float> y){
    float xDist=x[1]-y[1], yDist=x[0]-y[0];
    float Dist=sqrt(xDist*xDist+yDist*yDist);
    return Dist;
    }

float getAngle(vector<float> p1, vector<float> p2){
    float a=p2[1]-p1[1], b=p2[0]-p1[0];
    float c=atan2(a,b);
    float pi=2*acos(0.0);
    return 360-(c*180/pi);
}
int zoom(vector<vector<float>> nodes){
    vector<float> x=nodes[0], y=nodes[1];
    return int(100/getDist(x,y));
    }

int main(){
	vector<vector<float>> zoomed_nodes;
    int magnitude = zoom(nodes);
    int WHeight=1280, WWidth=720;
    for (vector<float> x: nodes){
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
    for (vector<float> node : zoomed_nodes){
            sf::CircleShape circle(10.f);
            circle.setPosition(Hcentre+node[0]-10,Wcentre-node[1]-10);
            window.draw(circle);
        }
    for (vector<int> x : connections){
            sf::Vertex line[] =
            {
                sf::Vertex(sf::Vector2f(Hcentre+zoomed_nodes[x[0]][0], Wcentre-zoomed_nodes[x[0]][1])),
                sf::Vertex(sf::Vector2f(Hcentre+zoomed_nodes[x[1]][0], Wcentre-zoomed_nodes[x[1]][1]))
            };
            window.draw(line, 2, sf::Lines);
        }
    vector<int> path=ham_paths[0];
        for (int i=0; i<node_count-1; i++){
            vector<float> a=zoomed_nodes[path[i]], b=zoomed_nodes[path[i+1]];
            float dist=getDist(a,b), angle=getAngle(a,b);
            sf::RectangleShape line(sf::Vector2f(dist, 5.f));
            line.rotate(angle);
            line.setPosition(Hcentre+zoomed_nodes[path[i]][0],Wcentre-zoomed_nodes[path[i]][1]);
            window.draw(line);
    }
    window.display();
    }
}
