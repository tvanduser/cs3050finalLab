#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//edge struct that I will be using
typedef struct Edge{
    int destination;
    int source;
    // struct Edge * next; **don't need this since just checking if the edge exists**
} Edge;

//function to check if edge is in the MST
bool isEdgeInMST(Edge * mst, int mstSize, int check_dest, int check_source){
    for(int i = 0; i < mstSize; i++) {
        if((mst[i].destination == check_dest && mst[i].source == check_source) ||
                (mst[i].source == check_dest && mst[i].destination == check_source)){
            return true;
        }
    }

    return false;
}

int main() {
    // Check if a given edge is in the MST
    // TODO: Implement this problem's solution

    // **assuming that a MST will already be passed in and we are just checking if the edge is in it**
    int vertexCount = 4;
    int mstSize = vertexCount - 1; // MST has V-1 edges
    Edge* mst = (Edge*)malloc(mstSize * sizeof(Edge));

    // Sample MST edges (source, destination)
    mst[0].source = 2; mst[0].destination = 3; // Edge (2,3)
    mst[1].source = 0; mst[1].destination = 3; // Edge (0,3)
    mst[2].source = 0; mst[2].destination = 2; // Edge (0,2)

    // Edge to check
    int check_source = 0, check_destination = 2; // Example edge (0,1)
    int check_source1 = 0, check_destination1 = 1; // Example edge (0,1)

    //check exists
    if (isEdgeInMST(mst, mstSize, check_source, check_destination))
        printf("Edge (%d, %d) is in the MST\n", check_source, check_destination);
    else
        printf("Edge (%d, %d) is not in the MST\n", check_source, check_destination);
    //check not exist
    if (isEdgeInMST(mst, mstSize, check_source1, check_destination1))
        printf("Edge (%d, %d) is in the MST\n", check_source1, check_destination1);
    else
        printf("Edge (%d, %d) is not in the MST\n", check_source1, check_destination1);

    // Clean up
    free(mst);
    return 0;
}
