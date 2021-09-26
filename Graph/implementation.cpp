// Undirected and Unweighted Graph (Using HashMap)

class Graph {
    map<int, list<int>>l;
public:

    void addEdge(int x, int y) {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void print() {
        for (auto x : l) {
            int u = x.first;
            cout << u << "-> ";
            list<int>el = x.second;
            for (auto x : el) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
};
int32_t main() {

  Graph g;
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.print();
}

// Directed and Weighted Graph
class Graph {
    map<string, list<pair<string, int>>>l;

public:

    void addEdge(string x, string y, int weight) {

        l[x].push_back({y, weight});

    }
    void print() {

        for (auto x : l) {
            string src = x.fi;
            cout << src << "-> ";

            list<pair<string, int>>city = x.se;

            for (auto x : city) {
                string dest = x.fi;
                int wt = x.se;
                cout << "(" << dest << " " << wt << ")";
            }
            cout << endl;
        }
    }
};
int32_t main() {

    Graph g;
    g.addEdge("A", "C", 40);
    g.addEdge("C", "D", 30);
    g.addEdge("D", "B", 20);
    g.addEdge("B", "A", 10);
    g.print();
}


