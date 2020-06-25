#include <vector>
#include <iostream>
#include <list>
/*
class Edge{
    public:
    Edge(){}
    Edge(std::vector<int>edges_){edges = edges_;};
    void print(){ for(int i = 0;i<edges.size();i++) std::cout<<edges.at(i); }
    std::vector<int>edges;
   
    friend class Vertex;
    //Vertex* next;
};
*/
class Vertex{
    public:
    Vertex() {}
    
    Vertex(std::vector<int>_vertices, std::vector<std::vector<int> >_edges,std::vector<int>neighbors_,int level_)
    {       
                vertices=_vertices, 
                edges = _edges, 
                neighbors=neighbors_;
                level = level_;
    };
   
    //void BFS(std::vector<Vertex> vList, int target);
    int operator[](int i){return vertices[i];};
    void printGraph();
    
    
    bool visited;
    int level;
    std::vector<std::vector<int> >edges;
    std::vector<int>vertices;
    std::vector<int>neighbors;
    //friend class Edge;
    
};

/*
void Vertex::BFS(std::vector<Vertex> vList,int target)
{
    int sum=0;
    for(int i = 0;i<vList.size();i++)
    {
        vList.at(i).visited=false;
    }

    std::list<Vertex>Q;
    vList.at(0).visited = true;
    Q.push_back(vList.at(0));
    std::list<Vertex>::iterator it;

    while(!Q.empty())
    {
        Vertex *currVertex = new Vertex;
        *currVertex = Q.front();
        for(int i = 0;i<currVertex->vertices.size();i++)
        {
            sum+=currVertex->vertices.at(i);
        }
        if(sum == target)
        {
            std::cout<<"target found"<<std::endl;
            break;
        }
        else sum=0;

        for(int i = 0;i<currVertex->neighbors.size();i++)
        {
            int adjvertex = currVertex->neighbors.at(i);
            if(!vList.at(adjvertex).visited)
            {
                vList.at(adjvertex).visited=true;
                Q.push_back(vList.at(adjvertex));
            }
        }
    }

    
}
*/