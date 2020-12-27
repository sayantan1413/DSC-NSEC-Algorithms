/**
 * @file Beanpole Cut
 * @brief Maximum number of coins by cutting the beanpole in different length rod
 * @approach 
   In this problem we are using recursive way to solve this problem. The main concept is
   that for each integer length we have 2 choices either we can cut the beanpole further
   or can skip the cutting. We assume that we will cut the rod from left to right. The maximum
   number of coins depend on the final lengths of beanpole because the maximum number of coins
   are added based on the corresponding number for the length of the rod.
 * @details
 * Time Complexity O(2^n) and space complexity O(1). The solution can be modified by using unbounded Knapsack approach.
 * The crewmates have caught the impostor. However he wants to strike a deal with you
   in exchange for his freedom. There is a beanpole of length N. For length i between
   the range 1 to N the impostor offers Pi coins. It is your job to find out the maximum
   number of coins obtainable by cutting the beanpole in different length rods.
 * Input :
   The first line of the input contains a single integer T denoting the number of test cases T. T test cases follow
   The first line of each test case contains a single integer N
   The next line contains N space separated integers
 * Output :
   For each test case, print the maximum number of obtainable coins by cutting the beanpole in different lengths.
 * Sample Input :
   1
   8
   1 5 8 9 10 17 17 20
 * Sample Output :
   22
 * @author [Sayantan Bose](https://github.com/sayantan1413)
 */

#include <bits/stdc++.h>
using namespace std;

int BeanpoleCut(int a[], int n)
{
    //Base case
    if(n <= 0)
    {
        return 0;
    }
    int max_value = INT_MIN;
    for(int i=0;i<n;i++)
    {
        max_value = max(max_value, a[i] + BeanpoleCut(a, n-i-1));
    }
    return max_value;
}

void solve() {
  //write your code here
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  {
      cin>>a[i];
  }
  int result = BeanpoleCut(a,n);
  cout<<result<<endl;
}
// Main function
int main() {
  int t;
  cin>>t;
  while(t--) {
    solve();
  }
  return 0;
}

