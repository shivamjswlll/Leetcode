class Solution {
    class DSU{
         public:
        vector<int> parent,size;
            DSU(int n){
                parent.resize(n+1);
                size.resize(n+1);

                for(int i = 0;i<= n ;i++){
                    parent[i] = i;
                    size[i] = 1;
                }
            }
           
            int finduPar(int node){
                if(parent[node] == node) return node;

                return parent[node] = finduPar(parent[node]);
            }

            void findUnionBySize(int u,int v){
                int ulp_u = finduPar(u);
                int ulp_v = finduPar(v);

                if(ulp_u == ulp_v) return;

                if(size[ulp_u] >= size[ulp_v]){
                    parent[ulp_v] = ulp_u;
                    size[ulp_u] += size[ulp_v];
                }
                else{
                    parent[ulp_u] = ulp_v;
                    size[ulp_v] += size[ulp_u];
                }
            }


    };
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        DSU graph(n);
        int wires = connections.size();
        if(wires < n-1) return -1;
        for(int i = 0;i<connections.size();i++){
            graph.findUnionBySize(connections[i][0],connections[i][1]);
        }
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(graph.parent[i] == i) cnt++;
        }
        return cnt-1;
    }
};