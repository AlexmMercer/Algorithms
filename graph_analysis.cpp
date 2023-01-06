#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

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


void 
int main() {
    vector<string> list;
    fstream graph;
    string text;
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
   isLoop(list);
   if(Full(list) == false && Oriented(list) == true) {
      cout << "Graph is not full and oriented." << endl;
  }
   if(Full(list) == false && Oriented(list) == false) {
      cout << "Graph is not full and not oriented." << endl;
  }
   if(Full(list) == true && Oriented(list) == true) {
      cout << "Graph is full and oriented." << endl;
  } 
   if(Full(list) == true && Oriented(list) == false) {
      cout << "Graph is full and not oriented." << endl;
  }
    return 0;
  }  

}
