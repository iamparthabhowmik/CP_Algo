/* iamparthabhowmik */

class DisjointSet{
public:
    vector<int> parent, rank, size;
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0; i<=n; i++) parent[i]=i;  
    }
    int findUP(int node){
        if(parent[node]==node) return node; // base case
        return parent[node]=findUP(parent[node]); // compute
    }
    void unionByRank(int u, int v){
        int ulp_u=findUP(u);
        int ulp_v=findUP(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_u]=ulp_v; // ulp_u -> ulp_v
            rank[ulp_v]++;
        }
    }
    void unionBySize(int u, int v){
        int ulp_u=findUP(u);
        int ulp_v=findUP(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u] <= size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};