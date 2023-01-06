#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<queue>
using namespace std;

void DFS(int start, int n,vector<bool> & visited,vector<string> & list)
{    
     visited.resize(n);
     cout<<start+1<<" ";
     visited[start]=true;
     for (int i=0; i<n; i++) {
     if ((list[start][i]!='0') && (!visited[i]))
         DFS(i,n,visited,list);
     }
}

void isLoop(vector<string> &list){
     for(int i = 0;i<list.size();i++) {
           if(list[i][i] == '1') {
              cout << "There are some loops in your graph." << endl;
              break; 
      }  
   }
}

bool Full(vector<string> &list) {
    bool result = true; 
    for(int i = 0; i<list.size();i++) {
         for(int j = 0;j< list[i].length();j++) {
             if(list[i][j] == '0') {
                if(i==j) {
                   if(list[i][j] == '0') {
                  }
                   if(list[i][j] == '1') {
                      
                   }
                } else result = false;
           }
       }
    }
    return result;
}

bool Oriented(vector<string> &list) {
      bool oriented = true;
      int b =0;
      for(int i = 0;i<list.size();i++) {
         for(int j =0; j<list[i].length();j++) {
             if((list[i][j]=='0'&&list[j][i]=='0')||(list[i][j]=='1'&&list[j][i]=='1')) {
               b++;    
          }        
      }
   }
     if(b!=0) { return oriented;} else { return !oriented;}
}


int main() {
    int n;
    int start;
    cin >> start;
    vector<string> list;
    fstream graph;
    string text;
    vector<bool> visited;
    graph.open("matrix.txt");
    if(!graph.is_open()) {
       cout << "File is not opened." << endl;
  } else {
       cout << "File is sucessfully opened" << endl;
       while(getline(graph,text)) {
             list.push_back(text); 
     }
    cout <<"This is your graph in adjancecy matrix: " <<endl;
    for(int i = 0;i<list.size();i++) {
        cout << list[i]<<endl;      
  } 
    n = list.size();
    visited.resize(n);
    for(int i = 0; i<n;i++) {
      visited[i] = false;
    }
    DFS(start-1,n,visited,list);
    return 0;
  }  

}
