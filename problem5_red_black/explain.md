**Code Choices: **

This one seemed pretty similar to Kruskals, so I used Kruskal's algorithm as the base since it already produces a MST and I really just had to add the bottleneck value. I implemented the Union-Find data structure using a subset to manage connected components during edge selection. I chose to sort the edges using q sort, then iterated in order of increasing weight. This just makes sure that smaller edges are considered first to avoid a high bottleneck value.  

The way I chose to have this show that it is a BST is by storing the bottleneck value which is the edge with the highest weight and printing that out. 

I also made sure to free the malloced memory to avoid leaks.

**Utility: **
This is useful in network design where the goal is to avoid any single overly expensive connection. I also think of it like a map. It wouldn't make sense to have a route going from los angeles to NYC. Instead we could still have them be connected, but a connection that large would be ridiculous. This implementation is good becuase it works well on both sparse and dense graphs. 

I would say another utility for an algorithm like this is when a system is only as strong as its weakest link. By making the weakest link as strong as possible it can improbe the performance of the entire system. This would be super important in a situation where risk mitigation is key.
