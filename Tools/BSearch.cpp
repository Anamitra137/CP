#include <iostream>
#include <vector>

using namespace std;

// Binary Search for leftmost occurence of x in A
int bsearch(const vector<int>& A, int x)
{
    int n = A.size();
    int lo = 0, hi = n - 1;
    int ans = -1;   // initialize according to problem

    while(lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if(A[mid] >= x)  // check by F() according to problem
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    return ans;
}

int main()
{

    return 0;
}