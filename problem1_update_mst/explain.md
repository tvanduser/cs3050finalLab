**Code choices:**
the first choice I made was to just create a global adjacency list and hardcdoe that in with values that reflect an MST structure. This is because I didn't want to implement everything since that is what we are doing in problem 2. I defined an edge struct to represent the adjacency list nodes and provided helper functions for adding and creating edges.

The key logic is updateMST... To determine where the new vertex should connect, I look through all of its proposed edges and find the one with the lowest weight that is already connected to an existing vertex. This makes sure that the new vertex gets connected with the lightest valid edge. This helps preserve the MST structure.

I also made sure to handle special cases. such as if the new vertex has no valid connectores, it it connects to multiple then only the lightest edge is chosen, and if it connects to only one vertex, then that edge is added straight up. I also used the helper funciton print graph to help wth my debugging when new vertexes are added.

**Utility: **
This algorithm serves the purpose of helping incrimentally add routes when the graph is growing over time. An example of this could be adding new routers to a network. Instead of having to re figure out the MST everytime that something new is added, We can just incrimentally extend the MST way more efficiently.

This approach would be super useful in real-time or resource-constrained systems. What I mean by this is that it would be useful when recalculating the MST would be way to slow or cost the company a ton of money. This assumes that new edges are only from the new vertexes being added it is a good fit for things like mesh networks or growing infrastructure systems where you can't recompute all of the time.
