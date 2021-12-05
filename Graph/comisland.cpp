// https://www.interviewbit.com/problems/commutable-islands/
/*
  ->Just cal MST
   T.C-O(n^2)
*/
class DSU {

    int *parent;
    int *rank;

public:
    DSU(int n) {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }

    }
    //Union of two set
    void unite(int u, int v) {

        int s1 = find(u);
        int s2 = find(v);

        if (s1 != s2) {
            if (rank[s2] > rank[s1]) {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            } else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
    //Return the Leader
    int find(int i) {
        if (parent[i] == -1) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

};
int solve(int n, vector<vector<int>> &m) {

    vector<vector<int>>graph(m.size(),vector<int>(m[0].size()));

    for(int i=0;i<m.size();i++){
        int x=m[i][0];
        int y=m[i][1];
        int wt=m[i][2];
        graph.push_back({wt,x,y});
    }
    sort(graph.begin(),graph.end());
    DSU s(n+1);   

    int cost=0;

    for(auto x:graph){
        int weight=x[0];
        int src=x[1];
        int dest=x[2];

        if(s.find(src)!=s.find(dest)){
            s.unite(src,dest);
            cost+=weight;
        }
    }
    return cost;
}
