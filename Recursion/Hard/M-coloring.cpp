#include<iostream>
#include<vector>
using namespace std;


bool isSafe(int node,int col, bool graph[101][101], int color[],int N)
{
    for(int k=0;k<N;k++){
if(graph[node][k]&& color[k]==col) return false;
    }
    return true;
}
bool solve(int node,bool graph[101][101],int m ,int N,int color[]){
    if(node==N){
        return true;

    }

    for(int i=1;i<=m;i++){
        if(isSafe(node,i,graph,color,N)) {
            color[node]= i;
            if(solve(node+1, graph, m , N, color)) return true;
            color[node]=0;

        }
    }
    return false;
}

bool graphColoring (bool graph[101][101],int m , int N){
    int color[101]= {0};
    return solve(0,graph,m,N,color);

}

int main(){
    int N,M,E;
    cin>>N>>M>>E;
    bool graph[101][101];
    for(int i=0;i<101;i++){
        for(int j =0;j<101;j++){
            graph[i][j]= false;
        }
    }
    for(int i =0;i<E;i++){
        int u,v;
        cin>>u>>v;
        graph[u][v]=true;
        graph[v][u]=true;
    }

    if(graphColoring(graph,M,N)) cout<<1<<endl;
    else cout<<0<<endl;
    return 0;
}
