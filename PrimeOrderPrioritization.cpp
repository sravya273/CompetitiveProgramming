/*

Prime Order Prioritization:

Amazon is planning to release a new order prioritization algorithm to optimize fulfilling Prime deliveries on time.
All orders (Prime or otherwise) are given an alphanumeric ID code. However, Prime orders are given additional metadata that consists of a space delimited list of 
lowercase English letters, whereas non-Prime orders are given metadata that consists only of a space delimited string of positive integers.
Each order is therefore defined as their alphanumeric id code, followed by a space, followed by their space delimited metadata.
You have been tasked with sorting a list of all orders in the order queue to assist in prioritization of fulfillment. They should be sorted according to the following order:

1. The Prime orders should be returned first, sorted by lexicographic sort of the alphabetic metadata.
2. Only in the case of ties, the identifier should be used as a backup sort.
3. The remaining non-Prime orders must all come after, in the original order they were given in the input.
Write a function or method to sort the orders according to this system.

Input:
The input to the function/method consists of one argument:
orderList, a list of strings representing all orders.

Output:
Return a list of strings representing the correctly prioritized orders according to this system.

Constraints:
0<= number of orders <= 10^3

Note:
The order identifier consists of only lower case English characters and numbers. 
Sort for tie breaks should use ASCII value - as an example, the order identifier 'a1' should come before order identifier 'aa'

Example1:

Input:
orderList = 
[zid 93 12]
[fp kindle book]
[10a echo show]
[17g 12 25 6]
[ab1 kindle book]
[125 echo dot second generation]

Output:
[125 echo dot second generation]
[10a echo show]
[ab1 kindle book]
[fp kindle book]
[zid 93 12]
[17g 12 25 6]

Explaination:
There are four prime orders (lines with words) in this order list. Because "echo" comes before "kindle", those lines should come first, with "dot" coming before "show".
Because two lines have the metadata "kindle book", their tie should be broken by the identifier, where "ab1" comes before the "fp". Finally, the non-Prime numeric orders 
should come last, in the original order, they were in the input. Amazon is planning to release a new order prioritization algorithm to optimize fulfilling Prime deliveries 
on time. All orders (Prime or Otherwise) are given an alphanumeric ID code. However, Prime orders are given additional metadata that consists of  a space- delimited list of 
lower case English letters, where as non Prime orders are given metdata that consists only of a space -delimited string of positive integers. Each order is therefore defined
as their alphanumeric id code,followed by a space, follwed by their space-delimited metadata.

*/

#include <bits/stdc++.h>
using namespace std;

void primeOrderPrioritize(vector<string> orderList, vector<string> &ans) {

    vector<string> nonPrimeOrders;
    map<string,set<string>> primeOrders;

    for(int i=0;i<orderList.size();i++) 
    {
        bool nonPrimeOrder = false;
        for(int j=0;j<orderList[i].length();j++) {
            if(orderList[i][j]>='0'&&orderList[i][j]<='9') {
                nonPrimeOrders.push_back(orderList[i]);
                nonPrimeOrder = true;
                break;
            }
        }

        if(!nonPrimeOrder) {
            int firstSpace = orderList[i].find(" ");
            string metadata = orderList[i].substr(firstSpace, orderList[i].length()-firstSpace);
            primeOrders[metadata].insert(orderList[i]);
        }

    }
    for(map<string,set<string>>::iterator mapIter=primeOrders.begin();mapIter!=primeOrders.end();mapIter++) {
        set<string> temp = mapIter->second;
        for(set<string>::iterator setIter=temp.begin();setIter!=temp.end();setIter++) {
            ans.push_back(*setIter);
        }
    }

    for(int i=0;i<nonPrimeOrders.size();i++) {
        ans.push_back(nonPrimeOrders[i]);
    }

}

int main()
{
    int n;
    cin>>n;
    string s;
    vector<string> orderList;
    vector<string> ans;
    while(n--)
    {
        getline(cin,s);
        orderList.push_back(s);
    }
    for(int i=0;i<orderList.size();i++)
    {
        cout<<orderList[i]<<endl;
    }
    // cout<<"hi"<<endl;
    primeOrderPrioritize(orderList,ans);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
}
 
