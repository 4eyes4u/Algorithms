/*
  Data structure: Ordered statistic set
  Time complexity: O(logn) per operation [where n is number of elements in set]
  Memory complexity: O(n) [where n is number of elements in set]

* * *
set.order_of_key -- returns order of given key that does not have to be in set.
set.find_by_order -- returns iterator of element that is on given position in sorted array of keys.
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef
tree<
  int,
  null_type,
  less<int>,
  rb_tree_tag,
  tree_order_statistics_node_update>
myset;

myset skup;

int main()
{
  skup.insert(5);
  skup.insert(1);
  skup.insert(100);
  skup.insert(15);
  skup.insert(20);

  printf ("%d\n", skup.order_of_key(17));
  printf ("%d\n", skup.order_of_key(15));
  printf ("%d\n", *skup.find_by_order(0));
  printf ("%d\n", *skup.find_by_order(3));

  return 0;
}
