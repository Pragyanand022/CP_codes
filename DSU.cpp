struct DSU{
        int n;
        vector<int> parent;
        vector<int> andd;

        DSU(int n){
            parent.resize(n);
            andd.resize(n);
            for(int i=0;i<n;i++){
                parent[i] = i;
                andd[i] = INT_MAX;
            }
        }

        int find(int a){
            return parent[a] = (parent[a]==a? a : find(parent[a]));
        }

        void unionByRank(int a, int b, int w){
            a = find(a);
            b = find(b);
            if(a<b){
                parent[b] = a;
                andd[a] &= w;
                andd[a] &= andd[b];
            }else{
                parent[a] = b;
                andd[b] &= w;
                andd[b] &= andd[a];
            }
        }
    };
