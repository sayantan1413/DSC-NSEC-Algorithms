/**
 * @file Priority Tasks
 * @brief In this problem we have to find out the task with the next greater priority.
 * @Aprroach
   The solve function calls the stack_func which prints the output in thw stack_func elements are pushed into stack and checked
   If the stack is not empty then pop operation takes place if it does not have the next greater element it prints -1
   else it prints the pairs
 * @details
 * Time complexity O(n) and Space Complexity O(n)
 * You have to perform N more tasks in order to complete your duty and contribute in the filling of the task bar. The next N tasks have been assigned a
   priority number. Higher the priority number, higher the priority. 2 or more tasks may or may not have the same priority number. For each of the N tasks,
   your job is to find out the task with the next greater priority. Note that the priority arrangements are circular, ie, the next priority number of the
   last task is the priority number of the first task. If no such task exists for a particular task, return -1 for it.
 * Input :
   The first line of the input contains a single integer T denoting the number of test cases. T test cases folows
   The first line of each test case contains a single digit N
   The next line contains N space separated integers
 * Output :
   For each test case, print N space separated integers for which ith element denotes the task with the next greater priority number
 * Sample input :
   2
   3
   1 2 1
   4
   1 3 4 2
 * Sample Output :
   2 -1 2
   3 4 -1 3
 * Explanation :
   In test case 2,immediately next greater priority task to 1 is 3, to 3 is 4. There is no task with priority greater than 4, hence -1. The array ends after 2
   but it is a circular array, hence the searching begins from the beginning of the array and the priority task immediately greater than 2 is 3.
 * @author [Sayantan Bose](https://github.com/sayantan1413)
 */

#include <bits/stdc++.h>
using namespace std;


/* prints element and NGE pair for all
elements of a[] of size n */
void stack_func(int a[], int n) {
  stack < int > sf;

int c=0,b[n];
  /* push the first element to stack */
  sf.push(a[0]);

  // iterate for rest of the elements
  for (int i = 1; i < n; i++) {

    if (sf.empty()) {
      sf.push(a[i]);
      continue;
    }
    while (sf.empty() == false && sf.top() < a[i])
    {
        //cout << s.top() << " --> " << a[i] << endl;
        b[c]=a[i];
        sf.pop();
        c++;
    }
    /* for finding the next greater value */
    sf.push(a[i]);
  }
  while (sf.empty() == false) {
    b[c]=-1;
    c++;
    sf.pop();
        }
        for(int i=0;i<n-1;i++)
            cout<<b[i]<<" ";
        cout<<b[0]<<endl;
    }
void solve() {
  //write your code here
  int n,i;
  cin>>n;
  int a[n];
  for(i=0;i<n;i++)
    cin>>a[i];
 stack_func(a, n);
//  return 0;
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
