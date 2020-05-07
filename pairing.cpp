#include<bits/stdc++.h>
using namespace std;
int product=1;
class Graph{
	int V;
	list<int> *adjList;
	Graph(int v){
		V=v;
		adjList=new list<int>[V];
	}
	void addEdge(int u,int v,bool bidir=true){
		adjList[u].push_back(v);
		if(bidir){
			adjList[v].push_back(u);
		}
	}
	void dfsHelper(int src,int visited[],int count){
		visited[src]=1;
		count++;
		for(auto neighbour:adjList[src]){
			dfsHelper(neighbour,visited,count);
		}

	}
	void findConnectedComponents(){
		int count=0;
		int visited[V]={0};
		dfsHelper(0,visited,count);
		product=product*count;
		while(count<V){
			for(int i=0;i<V;i++){
				if(visited[i]==0){
					dfsHelper(i,visited,count);
				}
			}
		}

	}
}
int main(){



	return 0;
}