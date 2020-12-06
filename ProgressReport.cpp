/*
given an array scores [][] = {“jerry”,”65”},{“bob”,”91”}, {“jerry”,”23”}, {“Eric”,”83”}} Find the student with highest average score
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    string name;
    int marks;
    map<string, pair<int,int>> records;
    double currentAvg=0, maxAvg=0;
    vector<string> topper;
    
    for(int i=0;i<n;i++)
    {
        cin>>name>>marks;
        if(records.find(name)==records.end())
        {
            records[name]= make_pair(marks,1);
        }
        else
        {
            records[name].first += marks;
            records[name].second++;
        }
        currentAvg = 1.0 * records[name].first / records[name].second;
        if(currentAvg> maxAvg)
        {
            maxAvg = currentAvg;
            topper.clear();
            topper.push_back(name);
        }
        else if (currentAvg == maxAvg)
        {
            topper.push_back(name);
        }
    }
    
   for(int i=0;i <topper.size();i++)
   {
       cout<<topper[i]<<" ";
   }
   cout<< maxAvg<<endl;
    return 0;
}

/*

Input:
5
Sravya 20
Kiran 30
Sravya 25
Kiran 27
sk 57
Output:
sk 57

*/
