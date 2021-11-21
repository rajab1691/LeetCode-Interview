// https://www.techiedelight.com/arrival-departure-time-vertices-dfs/


void dfs(int src,vi adj[],vi &arrival,vi &dep,int &cnt,vi &visit){

    visit[src]=1;
    arrival[src]=++cnt;

    for(auto x:adj[src]){
        if(visit[x]==0){
            dfs(x,adj,arrival,dep,cnt,visit);
        }
    }

    dep[src]=++cnt;
}

int32_t main() {

    int n,m;
    cin>>n>>m;

    vector<int>adj[n];

    while(m--){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
    }

    vector<int>arrival(n);
    vector<int>dep(n);
    vector<int>visit(n,0);
    int cnt=-1;
    
    fo(i,n){
        if(visit[i]==0){
            dfs(i,adj,arrival,dep,cnt,visit);
        }
    }

    fo(i,n){
        cout<<i<<" "<<arrival[i]<<" "<<dep[i]<<endl;
    }
}




