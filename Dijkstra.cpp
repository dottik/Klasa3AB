#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct krawedz {
  int w2;  //nr wierzchołka - końca krawędzi
  int waga; //waga krawędzi
};

typedef vector<vector<krawedz>> tgraf;

void Czytaj(tgraf &Graf) {
  int m, n, w1;
  krawedz kraw;
  ifstream we("graf_1.txt");
  we>>n>>m;
  Graf.resize(n);
  for(int i=0; i<m; i++) {
    we>>w1>>kraw.w2>>kraw.waga;
    Graf[w1].push_back(kraw);
  }
  we.close();
}

void Dijkstra(tgraf Graf, int pocz, vector<int> &koszt) {
  krawedz kraw;
  int i, j, k, w1;
  vector <bool> Odwiedzone;
  Odwiedzone.resize(Graf.size(), false);
  koszt[pocz]=0;
  for(i=0; i<Graf.size();i++) {
    
    k=0; while(Odwiedzone[k]) k++; w1=k;
    
    for(j=k+1; j<Graf.size(); j++) {
      if(!Odwiedzone[j]&&koszt[j]<koszt[w1])  w1=j;
    }
      Odwiedzone[w1]=true;
      for(int j=0; j<Graf[w1].size(); j++) {
        kraw = Graf[w1][j];
        if(!Odwiedzone[kraw.w2]&&koszt[w1]+kraw.waga<koszt[kraw.w2])
          koszt[kraw.w2]=koszt[w1]+kraw.waga;
      }
     
    }
    
  
}

int main() {
  tgraf Graf;
  Czytaj(Graf);
  vector <int> koszt;
  koszt.resize(Graf.size(), 1000);
  int pocz;
  cout<<"Numer wierzchołka początkowego: ";
  cin>>pocz;
  Dijkstra(Graf, pocz, koszt);
  cout<<"Koszt dojścia z wierzchołka "<<pocz;
  cout<<" do wierzchołka: "<<endl;
  for(int i=0; i<Graf.size(); i++) 
      if(i!=pocz) cout<<i<<":  "<<koszt[i]<<endl;

  return 0;
}
