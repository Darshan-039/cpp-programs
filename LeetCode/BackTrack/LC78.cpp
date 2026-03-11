// Online C++ compiler to run C++ program online
// Prints all the subsets of a given vector //
#include <iostream>
#include <vector>
using namespace std;

void subsets(vector<int> vc,vector<int> output,int index, vector<vector<int> >& ans) {
    if(index >= 3) {
        ans.push_back(output);
        return ;
    }
    
    // Exclude 
    subsets(vc,output,index+1,ans);
    
    // Include
    int element = vc[index];
    output.push_back(element);
    subsets(vc,output,index+1,ans);
}

int main() {
   vector<int> vc = {1,2,3};
   vector<vector<int> > ans;
   vector<int> output;
   int index = 0;
   
   subsets(vc,output,index,ans);
   
   for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}