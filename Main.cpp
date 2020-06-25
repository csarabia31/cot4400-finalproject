#include<vector>
#include<list>
#include<iostream>
#include<fstream>
#include<map>
#include <algorithm>
#include "Graph.h"

std::vector<int> BFS(std::vector<Vertex> vList,int target)
{
    int sum=0;
	int count=0;
	std::map<int,int>mapV;
	
	std::vector<int>moves(target,0);
	for(int i = 0;i<vList.size();i++)
    {
        vList.at(i).visited=false;
    }

	std::vector<bool>targets;
	for(int i = 0;i<target;i++)
		targets.push_back(false);

    std::list<Vertex>Q;
    vList.at(0).visited = true;
	vList.at(0).level=0;
    Q.push_back(vList.at(0));
    //std::list<Vertex>::iterator it;

	
	
    while(!Q.empty())
    {
		sum=0;
        Vertex *currVertex = new Vertex;
        *currVertex = Q.front();
		Q.pop_front();

        for(int i = 0;i<currVertex->vertices.size();i++)
        {
            sum+=currVertex->vertices.at(i);
        }

		if(moves.at(sum)!=0);
		else
		{
			moves.at(sum) = currVertex->level;
			if(mapV[currVertex->level] != 0)
			{
				if(sum < mapV.at(currVertex->level))
					mapV[currVertex->level] = sum;
			}
			else mapV[currVertex->level] = sum;
		}
        

		
		
        for(int i = 0;i<currVertex->neighbors.size();i++)
        {
			
            int adjvertex = currVertex->neighbors.at(i);
            if(!vList.at(adjvertex).visited)
            {
				//if(vList.at)
				vList.at(currVertex->neighbors.at(i)).level = currVertex->level+1;
                vList.at(adjvertex).visited=true;
                Q.push_back(vList.at(adjvertex));
            }
			
				
        }
		
    }


	std::make_heap(moves.begin(),moves.end());

	//for(int i = 0;i<10;i++)
		//std::cout<<moves.at(i) <<std::endl;
	std::vector<int>output;
	output.push_back(mapV.at(moves.front()));
	output.push_back((moves.front()));
	return output;
    
}

int main()
{
	int count;
	int count2=0;
	int size;
	std::vector<int>bucketSizes;
	std::vector<int>neighbors;

	std::ifstream input;
	input.open("input.txt");
	if(!input)
	{
		std::cout << "Couldn't open file" << std::endl;
		exit(1);
	}

	while(input>>size)
	{
		bucketSizes.push_back(size);	
	}
	
	int n = bucketSizes.at(0);
	bucketSizes.erase(bucketSizes.begin());
	std::vector<int>v2;

	std::vector<Vertex>verticesList;
	std::vector<std::vector<int> >edgeList;
	
	int level = 0;
	for(int i =0;i<bucketSizes.size();i++)
			v2.push_back(0);

	while(*v2.begin()<=*bucketSizes.begin())
	{
		
		//vertices.addVertex(v2);
		Vertex* v = new Vertex(v2, edgeList,neighbors,level);
		verticesList.push_back(*v);
		
		//v->addVertex(v2);
		count=bucketSizes.size()-1;

		while(v2.at(count)>=bucketSizes.at(count))
		{
			v2.at(count)=0;
			//v2[count]=1;
			count -= 1;
			//count!=1;
			if(count==-1)
				break;
		}
		if(count==-1)
			break;
		v2.at(count) +=1;
		
		
	}

	std::map<std::vector<int>,int>map;
	for(int i = 0;i<verticesList.size();i++)
	{
			map[verticesList.at(i).vertices] = i;

	}
	
	int count3 = 0;
	//std::cout<<verticesList.size() << std::endl;
	//filling
	//std::cout << bucketSizes.size() << std::endl;
	
	for(int i = 0;i<verticesList.size();i++)
	{
		//count3=verticesList.at(i).edges.size();
		for(int j = 0; j < bucketSizes.size();j++)
		{
			if(verticesList.at(i).vertices.at(j)>=0 && verticesList.at(i).vertices.at(j) < bucketSizes.at(j))
			{
				
				
				verticesList.at(i).edges.push_back(verticesList.at(i).vertices);
				verticesList.at(i).edges.at(count3).at(j) = bucketSizes.at(j);
				verticesList.at(i).neighbors.push_back(map.at(verticesList.at(i).edges.at(count3)));
				
				count3++;
			}


			
		}
		count3=0;
	}

	
	
	//dumping
	
	for(int i = 0;i<verticesList.size();i++)
	{
		count3=verticesList.at(i).edges.size();
		for(int j = 0; j < bucketSizes.size();j++)
		{
			if(verticesList.at(i).vertices.at(j)>0)
			{
				
				
				verticesList.at(i).edges.push_back(verticesList.at(i).vertices);
				verticesList.at(i).edges.at(count3).at(j) = 0;
				verticesList.at(i).neighbors.push_back(map.at(verticesList.at(i).edges.at(count3)));
			
				count3++;

			}

			
		}
		//count3=0;
	}
	
	//pouring

	
	int sum=0;
	
	for(int i = 0;i<verticesList.size();i++)
	{
		for(int j = 0; j < bucketSizes.size();j++)
		{
			count3=verticesList.at(i).edges.size();
			for(int k=0;k<bucketSizes.size();k++)
			{
				if(k!=j)
				{
					if(verticesList.at(i).vertices.at(j)>0&&(verticesList.at(i).vertices.at(k)>=0&&verticesList.at(i).vertices.at(k)<bucketSizes.at(k)))
					{
						//Edge* e = new Edge(verticesList.at(i).vertices);
						verticesList.at(i).edges.push_back(verticesList.at(i).vertices);
						sum=verticesList.at(i).vertices.at(j)+verticesList.at(i).vertices.at(k);
						if(sum>bucketSizes.at(k))
						{	
							sum -= bucketSizes.at(k);
							
							verticesList.at(i).edges.at(count3).at(k) = bucketSizes.at(k);
							verticesList.at(i).edges.at(count3).at(j) = verticesList.at(i).vertices.at(j) - (bucketSizes.at(k) - verticesList.at(i).vertices.at(k));
							verticesList.at(i).neighbors.push_back(map.at(verticesList.at(i).edges.at(count3)));
							
						}
						else
						{
							
							verticesList.at(i).edges.at(count3).at(k) = sum;
							verticesList.at(i).edges.at(count3).at(j) = 0;
							verticesList.at(i).neighbors.push_back(map.at(verticesList.at(i).edges.at(count3)));
							
						}
						count3++;

					}
				}
			}	
		}
	}
	
	
	
	int size2 = 0;
	int counter = 0;

	int sumEdges = 0;
	//printing edges size
		
	


		
	for(int i = 0;i<verticesList.size();i++)
	{
		
		sumEdges += verticesList.at(i).edges.size();
		//std::cout << verticesList.at(i).edges.size() << std::endl;
	}
	


	int sumTarget = 0;
	for(int i = 0;i<bucketSizes.size();i++)
		sumTarget+=bucketSizes.at(i);

	std::vector<int> m ;
	//std::cout << sumTarget;
	m=BFS(verticesList,sumTarget+1);
	//std::cout << m;

	std::ofstream myfile;
	myfile.open("output.txt");
	myfile << verticesList.size() << " " <<	sumEdges << " " << m.at(0) << " " << m.at(1);

	//std::cout << sumEdges << std::endl;
	//system("pause");
	return 0;

}

