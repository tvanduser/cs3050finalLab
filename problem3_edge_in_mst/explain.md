**Code Choices: **
For this one I am assuming that an MST would be provided and you will see in the main that I hardcoded a MST and check it twice, one where the edge existed in the MST and one where the edge didn't exit. 

To complete this problem I used a edge struct, for this I only needed the destination node and the source node since the weight is irrelevant in searching for it since it is either in the MST or not. I chose a bool for isEdgeInMST becuase we really only need true or false. The way it works is by looking at every edge in the MST and checking if the source and destination node match the edge's source and destination node that we are checking. Since it is undirected I also did it the other way around where I mismatched destination and source with the searched for destination and source.

I also chose to dynamically allocate the MST with malloc to simulate a real world scenario where the MST would be passed in from another part of the application. After the checks I made sure to free the memory in order to prevent leaks.

**Utility: **
The main use of this algorithm is just to provide a simple check on whether or not a specific edge is part of a known MST.

Some examples where this could be used are: Verifying correctness of MSTS and Debugging or testing phaess in MST related implementations. Because this is so simple it can easily be added or extended for more complex tasks involving MSTs.
