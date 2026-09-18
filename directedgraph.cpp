#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
using namespace std;
class Graph{
    int V;
    list<int> *l;
    public:
    Graph(int V){
        this->V= V;
        l= new list<int> [V];
    }
    void addedge(int u, int v){
    l[u].push_back(v);
    }
    //cycle detection
//o(v+E)
    // bool isCycleinDirectedDFS( int curr , vector<bool> &vis, vector<bool> &recpath){
        // vis[curr] = true;
        // recpath[curr] = true;
        // for(int v: l[curr]){
            // if(!vis[v]){
                // if(isCycleinDirectedDFS(v, vis,recpath)){
                    // return true;
                // }
// 
            // }
            // else if(recpath[v]){
                // return true;
            // }
        // }
        // recpath[curr] = false;
        // return false;
// 
    // }
    // bool isCycle(){
        // vector<bool> vis(V, false);
        // vector<bool> recpath(V, false);
        // for(int i=0; i<V; i++){
            // if(!vis[i]){
                // if(isCycleinDirectedDFS(i ,vis,recpath)){
                    // return true;
                // }
            // }
        // }
        // return false;
    // } 

    //topological; sorting o(V+E)
    void dfs(int curr,vector<bool> &vis, stack<int> &s){
        vis[curr] = true;
        for(int v: l[curr]){
            if(!vis[v]){
                dfs(v, vis,s);
            }
        }
        s.push(curr);
    }
    void topoSort(){
        vector<bool> vis(V, false);
        stack<int> s;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, vis, s);
            }
        }
        while(s.size() >0){
            cout<<s.top()<<" ";
            s.pop();

        }
        cout<<endl;

    
    }
};
int main(){
    // Graph n(4);
    // n.addedge(1,0);
    // n.addedge(0,2);
    // n.addedge(2,3);
    // n.addedge(3,0);
    // cout<<n.isCycle()<<endl;
    Graph g(6);
    g.addedge(3,1);
    g.addedge(2,3);
    g.addedge(4,0);
    g.addedge(4,1);
    g.addedge(5,0);
    g.addedge(5,3);
    g.topoSort();
    return 0;

}