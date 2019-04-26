# Algorithms
This repository contains algorithms and data structures commonly used in programming contests. Every snippet from this repository is used on some CP contest.

Correctness of any implementation is __not guaranteed__.

## List of algorithms
### Graph algorithms
* [Bellman-Ford algorithm](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/Bellman-Ford.cpp) - Single-source-shortest-path algorithm. Can be used to determine if negative cycle exists.
* [Tarjan's bridge algorithm](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/Bridges.cpp) - Algorithm for finding bridges in the graph. Graph has to be undirected and contain no more than one edge between any pair of vertices.
* [Tarjan's SCC algorithm](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/Tarjan.cpp) - Algorithm for finding strongly connected components (SCC) of the graph. Constructs topological sort of the condensation graph as a byproduct.
* [DFS and BFS](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/DFS-BFS.cpp) - Basic graph traversal algorithms.
* [Dial's algorithm](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/Dial.cpp) - Modification of Dijkstra's algorithm useful in cases where maximum edge' weight isn't more than some small constant.
* [Dijkstra's algorithm](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/Dijkstra.cpp) - Single-source-shortest-path algorithm mostly used because of it's time complexity. Implementation relies on priority queue.
* [Dinic's algorithm](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/Dinic.cpp) - Fast maximum-flow algorithm. Implementation is cache friendly.
* [Floyd-Warshall algorithm](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/FloydWashall.cpp) - Multi-source-shortest-path algorithm used for calculating distance between any pair of vertices.
* [Ford-Fulkerson algorithm](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/Ford-Fulkerson.cpp) - Easiest maximum-flow algorithm. Implementation is cache friendly. Can be used for fast solution of matching problem.
* [Kosaraju's algorithm](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/Kosaraju.cpp) - Easiest algorithm for calculating strongly connected components (SCC) of the graph.
* [Kruskal's algorithm](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/Kruskal.cpp) - Algorithm used for calculating minimum spanning tree of the graph. Relies on DSU.
* [Prim's algorithm](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/Prim.cpp) - Algorithm used for calculating minimum spanning tree of the graph. Relies on greedy strategy.
* [Bellman-Ford MCMF](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/MCMF.cpp) - Algorithm used for calculating minimal-cost-maximum-flow. Effective on bipartite graph.
* [SPFA](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/SPFA.cpp) - Single-source-shortest-path algorithm based on Bellman-Ford algorithm.
* [Hopcroft-Karp](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/HopcroftKarp.cpp) - Optimal bipartite matching.
* [Hierholzer](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/Hierholzer.cpp) - Algorithm for fiding Eulerian path in a graph.
* [Topological sort](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/TopoSort.cpp) - Kahn's algorithm for topological sort of a DAG.
* [Transitive closure](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/TransitiveClosure.cpp) - Floyd-Warshall algorithm used for calculating transitive closure of the graph.
* [Heavy-light decomposition](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/Tree/HLD.cpp) - Decomposition of the tree in chains of nodes such that traversal between any pair of nodes never use more than O(logN) chains.
* [Binary lifting](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/Tree/LCA.cpp) - Can be used to find lowest common ancestor (LCA) of two nodes in the tree.
* [Centroid decomposition](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/Tree/CentroidDecomposition.cpp) - Decimposition of the tree by recursively finding centroids (after centroid is removed every component is no more than half of original size).
* [BST merging](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/Tree/MergingBST.cpp) - Method for merging smaller binary search trees into larger while performing traversal on the tree.
* [Center of the tree](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/Tree/Center.cpp) - Algorithm for finding a center of the tree. Ultimately, diameter and radius is found.

### Data structures
* [DSU](https://github.com/4eyes4u/Algorithms/blob/master/DataStructures/DSU.cpp) - Disjoint-Set-Union data structure that supports efficient 'find' and 'unite' operatios. Only *path compression* heuristic is used, while *union by rank* is not implemented since practital difference is negligible.
* [Bitwise trie (Radix tree)](https://github.com/4eyes4u/Algorithms/blob/master/DataStructures/BitwiseTrie.cpp) - Trie used for saving binary numbers. Can be used to find maximum XOR value.
* [Fibbonaci heap](https://github.com/4eyes4u/Algorithms/blob/master/DataStructures/FibbonaciHeap.cpp) - Mergeable heap with fast amortized operations. State of the art data structure for Dijkstra's algorithm but very slow in practice.
* [Binomial heap](https://github.com/4eyes4u/Algorithms/blob/master/DataStructures/BinomialHeap.cpp) - Mergeable heap with fast worst case operations. Given implementation doesn't use lazy propagation.
* [Trie](https://github.com/4eyes4u/Algorithms/blob/master/DataStructures/Trie.cpp) - General variant of a trie with some fixed alphabet. Supports efficient `insert` and `lookup` operations.
* [Cartesian tree](https://github.com/4eyes4u/Algorithms/blob/master/DataStructures/CartesianTree.cpp) - Simple data structure that can be used as a base for more complex ones. Preorder traversal gives original input sequence, while initialization is amortized linear. Not to be confused with [treap](https://github.com/4eyes4u/Algorithms/blob/master/DataStructures/ImplicitTreap.cpp).
* [Fenwick tree (BIT)](https://github.com/4eyes4u/Algorithms/blob/master/DataStructures/FenwickTree.cpp) - Supports efficient maintenance of cumulative sums. Can be used to create histogram of values.
* [2D Fenwick tree (BIT)](https://github.com/4eyes4u/Algorithms/blob/master/DataStructures/FenwickTree2D.cpp) - Generalization of Fenwick tree in two dimensions. Additional dimensions can be added, while increasing complexity by a logarithmic factor. Constant factor grows exponentially.
* [D-ary heap](https://github.com/4eyes4u/Algorithms/blob/master/DataStructures/Heap.cpp) - General variant of heap with an arbitrary degree.
* [AVL tree](https://github.com/4eyes4u/Algorithms/blob/master/DataStructures/AVL.cpp) - Self-balancing binary search trees. Absolute height difference of every node is not larger than 1. Slow in practice because of large constants.
* [Implicit treap](https://github.com/4eyes4u/Algorithms/blob/master/DataStructures/ImplicitTreap.cpp) - Implicit variant of treap. Treap is a priority queue that is BST by keys and heap by priorities.
* [Monotone queue](https://github.com/4eyes4u/Algorithms/blob/master/DataStructures/MonotoneQueue.cpp) - Preserving minimum/maximum for every position in the array. Can be further improved to keep track of minimum/maximum value on all segments of some fixed length. Can also be generalized to higher dimensions.
* [Augmented BST](https://github.com/4eyes4u/Algorithms/blob/master/DataStructures/OrderedStatisticSet.cpp) - Native support for ordered statistic set or augmented BST. Supports efficient `find_by_key` and `order_of_key` operations.
* [Classic segment tree](https://github.com/4eyes4u/Algorithms/blob/master/DataStructures/SegmentTree.cpp) - Supports efficient update on fixed point as well as range querying. Merge operation can be any additive/objective function such as addition, maximum/minimum, XOR.
* [Segment tree with lazy propagation](https://github.com/4eyes4u/Algorithms/blob/master/DataStructures/SegmentTreeLazy.cpp) - Classic segment tree with lazy propagation. Supports efficient update on interval. *Not every function can be used for this type of segment tree*.
* [Implicit (dynamic) segment tree](https://github.com/4eyes4u/Algorithms/blob/master/DataStructures/ImplicitSegmentTree.cpp) - Implicit variant of segment tree. Total consumed space is determined by a maximal number of present values.
* [Persistent segment tree](https://github.com/4eyes4u/Algorithms/blob/master/DataStructures/PersistentSegmentTree.cpp) - Full persistent variant of implicit segment tree. Total space complexity is kept the same.
* [Suffix array](https://github.com/4eyes4u/Algorithms/blob/master/DataStructures/SuffixArray.cpp) - Can be used for lexicographical sort of all suffixes of given string.
* [Mo's algorithm](https://github.com/4eyes4u/Algorithms/blob/master/DataStructures/Mo.cpp) - Can be used for *efficient* offline processing of queries without update. Since TL is usually tight, try to use any other data structure, unless it's not possible.

### Mathematical algorithms
#### Geometry
* [Closest pair of points](https://github.com/4eyes4u/Algorithms/blob/master/Math/Geometry/ClosestPairOfPoints.cpp) - Finding two poinst that are closest in the Cartesian plane. Very well optimized.
* [Convex hull](https://github.com/4eyes4u/Algorithms/blob/master/Math/Geometry/ConvexHull.cpp) - Andrew's monotone chain convex hull algorithm. Can be used for fiding only upper/lower envelope of points easily as well as any other specified part of hull.
* [Is point in polygon?](https://github.com/4eyes4u/Algorithms/blob/master/Math/Geometry/PointInConvexPolygon.cpp) - Determining if given point is in the given convex polygon by applying binary search.
* [Segment inersection](https://github.com/4eyes4u/Algorithms/blob/master/Math/Geometry/SegmentIntersection.cpp) - Checking if two line segments inersect in cartesian plane.
#### Linear algebra
* [Gaussian elimination](https://github.com/4eyes4u/Algorithms/blob/master/Math/LinearAlgebra/GaussianElimination.cpp) - Gaussian elimination for solving system of linear equations.
* [Gen(Z2)](https://github.com/4eyes4u/Algorithms/blob/master/Math/LinearAlgebra/GeneratorOfZ2.cpp) - Finding basis of Z2 space.
* [Matrix library](https://github.com/4eyes4u/Algorithms/blob/master/Math/LinearAlgebra/Matrix.cpp) - Library for basic matrix operations such as addition, multiplication and power.
#### Number theory
* [Euclidean's algorithm](https://github.com/4eyes4u/Algorithms/blob/master/Math/NumberTheory/Euclidean.cpp) - Finding greatest common divisor (gcd) of two numbers. C++ has native `__gcd` support.
* [Fast pow](https://github.com/4eyes4u/Algorithms/blob/master/Math/NumberTheory/ExponentialBySquaring.cpp) - Performing power in logarithmic time by applying squaring. Can be used to find modular inverse when moduo is prime number.
* [Sieve of Eratoshenes](https://github.com/4eyes4u/Algorithms/blob/master/Math/NumberTheory/SieveOfEratoshenes.cpp) - Finding primes up to given upper bound. Theoretically opimal implementation. Augmentation is peformed, so that prime factorization can be done in logarithmic time.
#### Miscellaneous
* [FFT](https://github.com/4eyes4u/Algorithms/blob/master/Math/FFT.cpp) - Fast Fourier transform in iterative variant. Almost fully optimized. Additional improvement can be made if manual operations are peformed in small sub-problems.

### Greedy
* [Event scheduling](https://github.com/4eyes4u/Algorithms/tree/master/Greedy) - Finding largest set of non-overlaping events.

### Searches
* [Binary search](https://github.com/4eyes4u/Algorithms/blob/master/Searches/BinarySearch.cpp) - Can be used only when searched function is (strongly) monotone.
* [Ternary search](https://github.com/4eyes4u/Algorithms/blob/master/Searches/TernarySearch.cpp) - Can be used when searched function is unimodal (__exactly__ one peak).
* [Interpolation search](https://github.com/4eyes4u/Algorithms/blob/master/Searches/InterpolationSearch.cpp) - Heuristic approach for searching on (strongly) monotone function. Optimal if values have Gaussian (normal) distribution.
* [Quickselect](https://github.com/4eyes4u/Algorithms/blob/master/Searches/Quickselect.cpp) - Searching for kth value in the given array. __Does not__ preserve original indices.

### Strings
* [KMP](https://github.com/4eyes4u/Algorithms/blob/master/Strings/KMP.cpp) - Knuth-Morris-Pratt algorithm for efficient pattern search in the given text.
* [Rolling hash](https://github.com/4eyes4u/Algorithms/blob/master/Strings/RollingHash.cpp) - Trivial hashing method for strings. Sub-string hash extraction can be performed in constant time. If collisions occur with high frequency rate, use double or even hash.

### Dynamic programming
* [Longest increasing subsequence](https://github.com/4eyes4u/Algorithms/blob/master/DynamicProgramming/LIS.cpp) - Efficient LIS implementation.
* [Kadane's algorithm](https://github.com/4eyes4u/Algorithms/blob/master/DynamicProgramming/Kadane.cpp) - Finding maximum sum of consecutive array elements of any length.
* [Bitset trick](https://github.com/4eyes4u/Algorithms/blob/master/DynamicProgramming/BitsetTrick.cpp) - Improving time and space complexity of knapsack problem by using `std::bitset` with constant factor less than 1.

### Other
* [Fast input](https://github.com/4eyes4u/Algorithms/tree/master/Other) - Use it if input is very large and TL is tight.

# License
MIT
