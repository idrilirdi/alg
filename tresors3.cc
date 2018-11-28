#include<iostream>
#include<vector>
#include <queue>
using namespace std;

struct Pos{
  int i;
  int j;
};

typedef vector<int> VE;
typedef vector<VE> VVE;
typedef vector<char> VC;
typedef vector<VC> VVC;

int dirs = 4;
static const int I[] = {-1, 0, 0, 1};
static const int J[] = {0, -1, 1, 0};


int n, m, max_tresors, f, c;
VE dist, pas;
VVC G;
VVE visitat;

void insert(queue<Pos>& q, int f, int c){
  Pos add;
  for(int k = 0; k < dirs; k++){
    add.i = f + I[k];
    add.j = c + J[k];
    if(add.i >= 0 and add.j >= 0 and add.i < n and add.j < m){
      if(not visitat[add.i][add.j]){
         q.push(add);
         //cout << "added: " << add.i << ' ' << add.j << endl;
       }
    }
  }
}

int arriba(int f, int c){
  queue<Pos> q;
  Pos start;
  start.i = f;
  start.j = c;
  q.push(start);
  int tresors = 0;

  while ( !q.empty() ) {
    Pos now = q.front();
    q.pop();
    visitat[now.i][now.j] = 1;

    if( G[now.i][now.j] == 't' ) tresors += 1;
    if(tresors == max_tresors) return tresors;

    insert(q, now.i, now.j);

  }
  return tresors;
}

int main(){
  while(cin >> n >> m){
    G = VVC(n, VC(m));
    visitat = VVE(n, VE(m, 0));
    max_tresors = 0;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        cin >> G[i][j];
        if (G[i][j] == 'X') visitat[i][j] = 1;
        if (G[i][j] == 't') max_tresors += 1;

      }
    }
    //cout << "max tresors = " << max_tresors << endl;
    cin >> f >> c;

    cout << arriba(f-1, c-1) << endl;
  }
}
