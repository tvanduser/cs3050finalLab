**Code choices
the way i decided to do this was: implement both algorithms, and then to "compare" them I wrote compareMSTOrders which just prints both of the MSTS in edge-order format that way I can visualize a direct comparison of how the two algorithms chose edges differently.

For Prim's I used an array-based implementation with linear seach to find the min key. I know this isn't the best for large graphs which is why i fixed the size to 5 (V = 5). 5 should be plenty for visualization and comparison in this case. I also used arrays for keys, parent relationships, and a boolean array to track which nodes are in or out of the MST. The edges i chose are stored in primOrder[].

For Kruskal, I found all unique edges by looking through the adjacency list while useing a seen matrix to avoid duplicates (since its undirected). Then I sorted the edges using qsort which made use of the compare helper func. From this a union-find struct was used with path compression and union by rank to form the MST which i stored in kruskalOrder[]

**Utility
I think that this program was useful for understanding the main differences between how prim and kruskal do MSTs. I found that prim builds using a starting node, while kruskal (I think this is better) sorts the edges and then chooses the lightest edges and avoids cycles. 

I think that Prims would be better to use when you have a dense graph while kruskal shines with graphs that are more spread out and have an explicit edge list. 

By clearly printing them out in my compare funciton. This program/problem helps in showing me how edge weights and graph density influence MST construction differently in the two algorithms for building MSTs.
