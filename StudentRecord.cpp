#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    int n;
	    cin>>n;
	    string name;
	    int mark1,mark2,mark3;
	    vector <string> topscorers;
	    int avg_score,max_score=INT_MIN;
	    for(int i=0;i<n;i++)
	    {
	        cin>> name;
	        cin>>mark1>>mark2>>mark3;
	        avg_score = (mark1+mark2+mark3)/3 ;
	        if(avg_score >max_score)
	        {
	            max_score=avg_score;
	            topscorers.clear();
	            topscorers.push_back(name);
	        }
	        else if (avg_score == max_score)
	        {
	            topscorers.push_back(name);
	        }
	    }
	    for(int i=0;i<topscorers.size();i++)
	    {
	        cout<<topscorers[i]<<" "<<max_score;
	    }
	    cout<<endl;
	}
	return 0;
}
