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
};

static const int I[] = {-1, 0, 0, 1};
static const int J[] = {0, -1, 1, 0};


VVC graf;
VVB visitat;
int n, m;

bool find_path(int f, int c){
  Pos start;
  start.i = f;
  start.j = c;
  queue<Pos> q;
  q.push(start);

  while ( !q.empty() ){
    Pos current = q.front();
    visitat[current.i][current.j] = true;
    q.pop();

    if(graf[current.i][current.j] == 't') return true;
    for(int k = 0; k < 4; k++){
      Pos add;
      add.i = current.i + I[k];
      add.j = current.j + J[k];
      if(add.i > 0 and add.j > 0 and add.i < n+1 and add.j < m+1 and (not visitat[add.i][add.j]) and graf[add.i][add.j] != 'X'){
        q.push(add);
      }
    }
  }
  return false;
}

int main(){
  int f, c;
  cin >> n >> m;
  graf = VVC(n+1, VC(m+1, 'B'));
  visitat = VVB(n+1, VB(m+1, false));

  for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) cin >> graf[i][j];
  cin >> f >> c;

  cout << (find_path(f, c) ? "yes" : "no") << endl;

}
