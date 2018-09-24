# Algorithms
This repository contains algorithms and data structures commonly used in programming contests. Every snippet from this repository is used on some CP contest.

Correctness of any implementation is _not guaranteed_.

## List of algorithms
### Graph algorithms
* [Bellman-Ford algorithm](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/Bellman-Ford.cpp) - Single-source-shortest-path algorithm. Can be used to determine if negative cycle exists.
* [Tarjan's algorithm](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/Bridges.cpp) - Algorithm for finding bridges in the graph. Graph has to be undirected and contain no more than one edge between any pair of vertices.
* [DFS and BFS](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/DFS-BFS.cpp) - Basic graph traversal algorithms.
* [Dial's algorithm](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/Dial.cpp) - Modification of Dijkstra's algorithm useful in cases where maximum edge' weight isn't more than some small constant.
* [Dijkstra's algorithm](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/Dijkstra.cpp) - Single-source-shortest-path algorithm mostly used because of it's time complexity. Implementation relies on priority queue.
* [Dinic's algorithm](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/Dinic.cpp) - Fast maximum-flow algorithm. Implementation is cache friendly.
* [Floyd-Warshall algorithm](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/FloydWashall.cpp) - Multi-source-shortest-path algorithm used for calculating distance between any pair of vertices.
* [Ford-Fulkerson algorithm](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/Ford-Fulkerson.cpp) - Easiest maximum-flow algorithm. Implementation is cache friendly. Can be used for fast solution of matching problem.
* [Kosaraju's algorithm](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/Kosaraju.cpp) - Easiest algorithm for calculating strongly connnected components (SCC) of the graph.
* [Kruskal's algorithm](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/Kruskal.cpp) - Algorithm used for calculating minimum spanning tree of the graph. Relies on DSU.
* [Prim's algorithm](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/Prim.cpp) - Algorithm used for calculating minimum spanning tree of the graph. Relies on greedy strategy.
* [Bellman-Ford MCMF](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/MCMF.cpp) - Algorithm used for calculating minimal-cost-maximum-flow. Effective on bipartite graph.
* [SPFA](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/SPFA.cpp) - Single-source-shortest-path algorithm based on Bellman-Ford algorithm.
* [Topological sort](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/TopoSort.cpp) - Kahn's algorithm for topological sort of a DAG.
* [Transitive closure](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/TransitiveClosure.cpp) - Floyd-Warshall algorithm used for calculating transitive closure of the graph.
* [Heavy-light decomposition](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/Tree/HLD.cpp) - Decomposition of the tree in chains of nodes such that traversal between any pair of nodes never use more than O(logN) chains.
* [Binary lifting](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/Tree/LCA.cpp) - Can be used to find lowest common ancestor (LCA) of two nodes in the tree.
* [Centroid decomposition](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/Tree/CentroidDecomposition.cpp) - Decimposition of the tree by recursively finding centroids (after centreoid is removed every component is no more than half of original size).
* [BST merging](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/Tree/MergingBST.cpp) - Method for merging smaller binary search trees into larger while performing traversal on the tree.
* [Center of the tree](https://github.com/4eyes4u/Algorithms/blob/master/Graphs/Tree/Center.cpp) - Algorithm for finding a center of the tree. Ultimately, diameter and radius is found.



# License
MIT
