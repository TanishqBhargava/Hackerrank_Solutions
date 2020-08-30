#include <iostream>
#include <vector>
#include <queue>

using std::vector;

vector<vector<int>> adjacency(int n, const vector<int> &u, const vector<int> &v){
  vector<vector<int>> adj(n);
  for(int i=0;i<u.size();++i){
    adj[u[i]].push_back(v[i]);
  }
  return adj;
}

int excludant(const vector<int> &nim, const vector<int> &subadj){
  int res=0;
  std::priority_queue<int> q;
  for(int x: subadj){
    if(nim[x]==res){
      ++res;
      while(!q.empty() && -res==q.top()){
    ++res;
    while(!q.empty() && -q.top()<res) q.pop();
      }
    }else if(nim[x]>res) q.push(-nim[x]);
  }
  return res;
}

vector<int> nimber(const vector<vector<int>> &adj){
  const int n=adj.size(), unvis=-1;
  vector<int> nim(n,unvis), ind(n,0), dfs;
  for(int i=0;i<n;){
    dfs.push_back(i);
    while(!dfs.empty()){
      const int x=dfs.back(), nx=adj[x].size();
      int &i=ind[x];
      while(i!=nx && nim[adj[x][i]]!=unvis) ++i;
      if(i==nx){
    nim[x]=excludant(nim,adj[x]);
    dfs.pop_back();
      }else dfs.push_back(adj[x][i++]);
    }
    while(i<n && nim[i]!=unvis) ++i;
  }
  return nim;
}

bool win(const vector<int> &b, const vector<int> &nim){
  int nimsum=0;
  for(int x: b) nimsum^=nim[x];
  return nimsum!=0;
}

int main(){
  int n=0, m=0; std::cin >> n >> m;
  vector<int> u,v;
  while(m--){
    int x=0,y=0; std::cin >> x >> y;
    u.push_back(--x);
    v.push_back(--y);
  }
  auto adj=adjacency(n,u,v);
  vector<int> nim{nimber(adj)};
  int q=0; std::cin >> q;
  while(q--){
    int k=0; std::cin >> k;
    vector<int> b;
    while(k--){
      int x=0; std::cin >> x;
      b.push_back(--x);
    }
    std::cout << (win(b,nim)?"Bumi\n":"Iroh\n");
  }
}
