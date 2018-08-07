
#include <iostream>    // cin, cout
#include <algorithm>  // max
using namespace std;

#define MAX 10000



int solve(int A[], int N)
{
  int n;
  int s;
  for (n=s=0; n < N ; n++)
    s += ((A[n] % 2 )==0) ;
  return s;
}




int main()
{
  int n;
  int N;
  int A[MAX];
  cin >> n;
  for (int i=0; i < n ; i++)
    {
      cin >> N  ;
      for (int j=0; j < N ; j++)
	     cin >> A[j];
      cout << solve(A,N) << endl;
    }
  return 0;
}