#include <bits/stdc++.h>
using namespace std;

// Data structure for Min Heap
vector<pair<int,int> > ans;
struct PriorityQueue 
{
private:
  // vector to store heap elements
  vector<int> A;

  // return parent of A[i]
  // don't call this function if it is already a root node
  int PARENT(int i) 
  { 
    return (i - 1) / 2; 
  }

  // return left child of A[i]  
  int LEFT(int i) 
  { 
    return (2 * i + 1); 
  }

  // return right child of A[i] 
  int RIGHT(int i) 
  { 
    return (2 * i + 2); 
  }


  // Recursive Heapify-up algorithm
  void heapify_up(int i)
  {
    // check if node at index i and its parent violates 
    // the heap property
    if (i && A[PARENT(i)] > A[i]) 
    {
      // swap the two if heap property is violated
      
      ans.push_back({i,PARENT(i)});
      swap(A[i], A[PARENT(i)]);
      
      // call Heapify-up on the parent
      heapify_up(PARENT(i));
    }
  }
  
public:

  void push(int key)
  {
    // insert the new element to the end of the vector
    A.push_back(key);

    // get element index and call heapify-up procedure
    int index = size() - 1;
    heapify_up(index);
  }

};

int main()
{
   /* #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
 */

  PriorityQueue pq;
  
  // Note - Priority is decided by element's value
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  for(int i=0;i<n;i++)
    pq.push(a[i]);

  cout<<ans.size()<<endl;
  for(auto x:ans)
    {cout<<x.first<<" "<<x.second<<endl;
      swap(a[x.first],a[x.second]);
      }
  /*for(int i=0;i<n;i++)
    cout<<a[i]<<" ";*/

  
  return 0;
}