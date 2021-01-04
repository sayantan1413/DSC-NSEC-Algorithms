/**
 * @file Rank
 * @brief In this program we have to find the maximum number of coins obtained after the beanpole cut
 * @Aprroach
   A dynamic programming function is created to return the maximum value in the function if the length of
   the pole is less than the max length the value will be considered else it wont be considered an external
   array ex_a[ ] [ ] would store the result
 * @details
 * Time complexity O(n) and Space Complexity O(n)
 * The crewmates have caught the impostor. However he wants to strike a deal with you in exchange for his freedom.
   There is a beanpole of length N. For length i between the range 1 to N the impostor offers Pi coins. It is your
   job to find out the maximum number of coins obtainable by cutting the beanpole in different length rods.
 * Input :
   The first line of the input contains a single integer T denoting the number of test cases T. T test cases follow
   The first line of each test case contains a single integer N
   The next line contains N space separated integers
 * Output :
   For each test case, print the maximum number of obtainable coins by cutting the beanpole in different lengths.
 * Sample input :
   1
   8
   1 5 8 9 10 17 17 20
 * Sample Output :
   22
 * Explanation :
   If the beanpole is cut in lengths of 2 and 6, maximum number of coins will be obtained (5+17).
 * @author [Sayantan Bose](https://github.com/sayantan1413)
 */
#include <bits/stdc++.h>
using namespace std;
// A DP function to return the max value
int max_value(int a[], int len[],int mv, int n)
{
int ex_a[n+1][n+1];
	if (n == 0 || mv == 0)
	{
		return 0;
	}
    // If the length of the beanpole is less than the maximum length, mv will consider it.
	if (len[n - 1] <= mv)
	{
		ex_a[n][mv]= max(a[n - 1]+ max_value(a, len,mv - len[n - 1], n),
				max_value(a, len, mv, n - 1));
	}
    // If the length of the rod is greater than the inputted size,mv we will not consider it.
	else
	{
		ex_a[n][mv]= max_value(a, len,mv, n - 1);
	}
    return ex_a[n][mv];
}
void solve() {
  //write your code here
  int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
        cin>>a[i];
	int len[n];
	for (int i = 0; i < n; i++) {
		len[i] = i + 1;
	}
	int mv = n;
cout<< max_value(a, len, n, mv) << endl;
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
