#include<iostream>
#include<vector>
#include <queue>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<bool> VB;
typedef vector<VB> VVB;

struct Pos{
  int i;
  int j;
  int dist;
};

static const int I[] = {-1, 0, 0, 1};
static const int J[] = {0, -1, 1, 0};


VVC graf;
VVB visitat;
int n, m;

int find_path(int f, int c){
  Pos start;
  start.i = f;
  start.j = c;
  start.dist = 0;
  queue<Pos> q;
  q.push(start);

  while ( !q.empty() ){
    Pos current = q.front();
    visitat[current.i][current.j] = true;
    q.pop();

    if(graf[current.i][current.j] == 't') return current.dist;

    for(int k = 0; k < 4; k++){
      Pos add;
      add.i = current.i + I[k];
      add.j = current.j + J[k];
      add.dist = current.dist + 1;
      if(add.i > 0 and add.j > 0 and add.i < n+1 and add.j < m+1 and (not visitat[add.i][add.j]) and graf[add.i][add.j] != 'X'){
        q.push(add);
      }
    }
  }

  return -1;
}

int main(){
  int f, c;
  cin >> n >> m;
  graf = VVC(n+1, VC(m+1, 'B'));
  visitat = VVB(n+1, VB(m+1, false));

  for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) cin >> graf[i][j];
  cin >> f >> c;
  int d = find_path(f, c);
  if (d == -1) cout << "no es pot arribar a cap tresor" << endl;
  else cout << "distancia minima: " << d << endl;

}
