#include<iostream>
#include<queue>
#include<vector>
#include<list>
using namespace std;
class Graph{
    int V;
    list<int> *l ;//int *arr
    public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V];
        //arr = new int[V]
    }
    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);

    }
    //BFS traversal
    void bfs(){//o(V+E) means vertex and edges
queue<int> q;
vector<bool> vis(V, false);
q.push(0);
vis[0] = true;
while(q.size() > 0){
    int u= q.front();
    q.pop();
    cout<< u<<" ";
    for(int v: l[u]){
        //immmediate neighbour
        if(!vis[v]){
            vis[v] = true;
            q.push(v);
        }
    }
}
    }
    //DFS traversal
    void dfsHelper(int u, vector<bool> &vis){ //O(V+E)
        cout<<u<<" ";
        vis[u] = true;
        for(int v: l[u]){
            if(!vis[v]){
                dfsHelper(v,vis);
            }
        }
    }
    void dfs(){
        int src  = 0;
        vector<bool> vis(V,false);
        dfsHelper(src , vis);
        cout<<endl;
    }
    // bool isCycleUndirected(int src, vector<bool> vis){
        // queue<pair<int,int>> q;
        // q.push({src, -1});
        // vis[src] = true;
        // while(q.size() >0){
            // int u= q.front().first;
            // int parU = q.front().second;
            // q.pop();
// 
            // list<int> neighbors = l[u];
            // for(int v: neighbors){
                // if(!vis[v]){
                    // q.push({u,v});
                    // vis[v] = true;
// 
                // }
                // else if(v != parU){
                    // return true;
                // }
            // }
        // }
        // return false;
    // }
    // bool isCycle(){
        // vector<bool> vis(V , false);
        // for(int i=0; i<V; i++){
            // if(!vis[i]){
                // if (isCycleUndirected(i , vis)){
                    // return true;
                // }
            // }
        // }
        // return false;
    // 
    // }
    bool isCycleUndirectDFS(int src, int par, vector<bool> &vis){
        vis[src] = true;
        list<int> neighbours = l[src];
        for(int v : neighbours){
            if(!vis[v]){
                if(isCycleUndirectDFS(v, src, vis)){
                    return true;
                }
                
            }
            else if( v != par){
                return  true;
            }
        }
        return false;
    }
    bool isCycleDFS(){
        vector<bool> vis(V, false);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(isCycleUndirectDFS(i , -1, vis)){
                    return true;
                }
            }
        }
        return false;
    }
};
int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(3,4);
    cout<<"bfs : ";
    g.bfs();
    cout<<endl;
     cout<<"dfs: ";
     g.dfs();
     cout << g.isCycleDFS() << endl;
     return 0;
}