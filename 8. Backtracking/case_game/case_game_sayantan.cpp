
/**
 * @file Case Game
 * @brief You take an alphanumeric string and transform every letter individually to be lowercase or
          uppercase to create another string. Find out all the possible string created in the above manner
 * @approach In this program in the first check we are converting all the alphabets to lowercase and printing it
             then we are going through a while loop where if it is a digit we continue the loop but if a alphabet
             then we change the upper to lower case or vice versa one by one. We have all this condition if the length
             of the string is greater than 2. If the string size is 2 we only execute the lower and upper case.
 * @details
 * Time complexity O(n) and space complexity O(n)
 * Your crewmates are busy doing tasks and at the moment you have none. To keep
   yourself busy, you invented a new game for yourself. You take an alphanumeric
   string and transform every letter individually to be lowercase or uppercase to
   create another string. Find out all the possible string created in the above manner
 * Input :
   The first line of the input contains a single integer T denoting the number of test cases T. T test cases follow
   The first line of each test case contains a single integer N
   The next line contains an alphanumeric string S
 * Output :
   For each test case, print all combinations of string formed after transforming every character to lowercase and uppercase case.
 * Sample Input :
   1
   4
   a1b2
 * Sample Output
   a1b2
   A1b2
   a1B2
   A1B2
 * @author [Sayantan Bose](https://github.com/sayantan1413)
 */
 #include <bits/stdc++.h>
using namespace std;

//Convert the upper to lower or vice versa
int convert(string &str, int i)
{
    if (str[i]>='a' && str[i]<='z')
    {
        //Convert lowercase to uppercase
        str[i] = str[i] - 32;
    }
    else if(str[i]>='A' && str[i]<='Z')
    {
        //Convert uppercase to lowercase
        str[i] = str[i] + 32;
    }
    return 0;
}

void solve() {
  //write your code here
   int n,c=0,d=0;
    cin>>n;
    string str,new_str;
    cin>>str;
    new_str=str;
    //In the first check make all the characters in lowercase and print
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    cout<<str<<endl;
    while(c!=n)
    {
       if(isdigit(str[c]) == true)
       { c++;
        continue;

    }
        else
        {
            str=new_str;
            convert(str,c);
            c++;
            d++;
            cout<<str<<endl;
        }
    }
if(d>1)
{
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout<<str;
}
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
