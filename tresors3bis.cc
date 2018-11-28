#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Punt {
    int fil, col, dist;
};

int dist = 0;

void insereix(vector<vector<bool> >& M, queue<Punt>& q, int i, int j, int d) {
    if (i >= 0 and i < M.size() and j >= 0 and j < M[0].size() and not M[i][j]) {
        M[i][j] = true;
        Punt p;
        p.fil = i;
        p.col = j;
        p.dist = d;
        q.push(p);
    }
}

int arriba_tresor(vector<vector<bool> >& M, queue<Punt>& q, vector<vector<char> >& mat) {
    if (q.size() == 0) return 0;
    Punt p = q.front();
    q.pop();
    insereix(M, q, p.fil - 1, p.col, p.dist + 1);
    insereix(M, q, p.fil + 1, p.col, p.dist + 1);
    insereix(M, q, p.fil, p.col - 1, p.dist + 1);
    insereix(M, q, p.fil, p.col + 1, p.dist + 1);
    if (mat[p.fil][p.col] == 't'){
      dist = p.dist;
      return 1 + arriba_tresor(M, q, mat);
     }
    return arriba_tresor(M, q, mat);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char> > mat(n, vector<char> (m));
    vector<vector<bool> > M(n, vector<bool> (m, false));
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        cin >> mat[i][j];
        if (mat[i][j] == 'X') M[i][j] = true;
    }
    queue<Punt> q;
    int f, c;
    cin >> f >> c;
    insereix(M, q, f - 1, c - 1);
    int z = arriba_tresor(M, q, mat);
    cout << dist << endl;
}
