/*
Napisz program, ktory wczyta slowa z pliku otrzymanego od nauczyciela
(np. slowa.txt), nastepnie posortuje je w porzadku leksykograficznym
i zapisze w pliku tekstowym o nazwie slownik.txt.
*/

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <queue>
#include <locale.h>

using namespace std;

const string alfabet="abcdefghijklmnopqrstuvwxyz";
const int N = 26;

void BudujListe(list<string> &lista, int &mdl)
{
    ifstream we("slowa.txt");
    string s;
    mdl = 0;

    while(we >> s)
    {
        lista.push_back(s);

        if(s.size() > mdl)
            mdl = s.size();
    }

    we.close();
}

void ZapiszListe(list<string> lista)
{
    ofstream wy("slownik.txt");
    list<string>::iterator it;

    for(it = lista.begin(); it != lista.end(); it++)
        wy << *it << endl;

    wy.close();
}

void SortujSlowa(list<string> &lista, int mdl)
{
    queue<string> Kubelki[N];
    list<string>::iterator it;
    int i, j;
    string s;

    for(i = mdl - 1; i >= 0; i--)
    {
        it = lista.begin();
        while(it != lista.end())
        {
       
            s = *it;
      
            if(s.size() > i)
            {
                it = lista.erase(it);
          
                j = alfabet.find(s[i]);
              
                Kubelki[j].push(s);
             
            }
            else
                it++;
         
        }

        for(j = 0; j < N; j++)
        {
            while(!Kubelki[j].empty())
            {
               lista.push_back(Kubelki[j].front());
             
                Kubelki[j].pop();
            }
        }
    }
}

int main()
{
  setlocale(LC_CTYPE, "Polish");
    list<string> lista;
    int mdl;

    BudujListe(lista, mdl);
    SortujSlowa(lista, mdl);
    ZapiszListe(lista);
    cout<<"Slowa zostaly posortowane."<<endl;

    return 0;
}
