//trying to solve this problem in O(n)
#include <bits/stdc++.h>
#include<iostream>
using namespace std;

//profit funtion which will collect the shares list and its length
int profit(vector<int> shares, int n){
    //intializing the require variable
    int profit=0,temp=0;
    
    //pushing the minimum value of int in end of vector
    //reason of adding minimum value so that i+1 cannot go out of range
    // and shares[i]>shares[i+1] condition could always consider the last element of vector 
    shares.push_back(INT_MIN);
    
    //loop will go from 0 to size of vector-1;
    for(int i=0;i<n;i++){
        
        //if shares of index i+1 will less than index i than it would be loss,
        //so for getting maxmiun profit the given condition is there
        if(shares[i]>shares[i+1]){
            
            //it will show the present profit calculated from which day to which day with the profit amount
            //as instruct in pdf
            cout<<"Shares bought on Day "<<temp+1<<" and sold on Day"<<i+1<<"- "<<shares[i]-shares[temp]<<endl;
            
            //it adding the present profit to total profit
            profit+=shares[i]-shares[temp];
            
            //it storing the first day of next profit period
            temp=i+1;
        }
    }
    
    //returning profit to main function
    return profit;
}
 
//Main Fuction & PROGRAM START POINT
int main()
{   
    //intializing the shares list
    vector<int> shares{165,177,181,178,202,177,181,180,189};
    
    //calling profit Fuction to calculate the max profit and storing in a variable
    int p=profit(shares,shares.size());
    
    //showing Total Profit
    cout<<"Total Profit would be:"<<p;
    return 0;
}