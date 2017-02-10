#include <iostream>
#include <list>

using namespace std;

//Represents an undirected graph using adjacency list representation
class GraphUsingAdjacencyList
{
    int noOfVertices;
    list<int> *adjacencyList;
    bool *visited;
public:
    GraphUsingAdjacencyList(int vertices);
    void addEdge(int v1, int v2);
    void MarkAllVisitedAsFalse(int noOfVertices, bool visited[]);
    void PrintDFS(int vertexNo, bool visited[]);
    void DFSTraversal(int vertexNo);
    void BFSTraversal(int vertexNo);
};

//Constructor
GraphUsingAdjacencyList::GraphUsingAdjacencyList(int vertices)
{
    this->noOfVertices = vertices;
    adjacencyList = new list<int>[vertices];
    visited = new bool[noOfVertices];
}

//Function to add an edge between two vertices
void GraphUsingAdjacencyList::addEdge(int vertex1, int vertex2)
{
    adjacencyList[vertex1].push_back(vertex2);
}

//Function to mark all visited nodes to be false (at the beginning)
void GraphUsingAdjacencyList::MarkAllVisitedAsFalse(int noOfVertices, bool visited[])
{
    for(int i = 0; i < noOfVertices; i++)
        {
            visited[i] = false;
        }
}

//Recursive function to print the current visited vertex
void GraphUsingAdjacencyList::PrintDFS(int vertexNo, bool visited[])
{
    visited[vertexNo] = true;
    cout << vertexNo << " ";

    list<int>::iterator i;
    for (i = adjacencyList[vertexNo].begin(); i != adjacencyList[vertexNo].end(); i++)
    {
        if (!visited[*i])
        {
            PrintDFS(*i, visited);
        }
    }
}

//Function to do DFS (Depth First Search) traversal
void GraphUsingAdjacencyList::DFSTraversal(int vertexNo)
{
    MarkAllVisitedAsFalse(noOfVertices, visited);
    PrintDFS(vertexNo, visited);
}

//Function to do BFS (Breadth First Search) traversal
void GraphUsingAdjacencyList::BFSTraversal(int vertexNo)
{
    MarkAllVisitedAsFalse(noOfVertices, visited);

    list<int> queue;
    list<int>::iterator i;

    visited[vertexNo] = true;
    queue.push_back(vertexNo);

    while(!queue.empty())
    {
        vertexNo = queue.front();
        cout << vertexNo << " ";

        queue.pop_front();

        for(i = adjacencyList[vertexNo].begin(); i != adjacencyList[vertexNo].end(); i++)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

//Main function
int main()
{
    // Create a graph of 10 nodes
    GraphUsingAdjacencyList graph(10);

    // Add the edges as shown on the graph in the document
    graph.addEdge(0, 1);
    graph.addEdge(0, 5);
    graph.addEdge(0, 4);

    graph.addEdge(1, 0);
    graph.addEdge(1, 4);
    graph.addEdge(1, 5);
    graph.addEdge(1, 6);
    graph.addEdge(1, 2);

    graph.addEdge(2, 1);
    graph.addEdge(2, 5);
    graph.addEdge(2, 6);
    graph.addEdge(2, 7);
    graph.addEdge(2, 3);

    graph.addEdge(3, 2);
    graph.addEdge(3, 6);
    graph.addEdge(3, 7);

    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(4, 5);
    graph.addEdge(4, 8);

    graph.addEdge(5, 4);
    graph.addEdge(5, 0);
    graph.addEdge(5, 1);
    graph.addEdge(5, 2);
    graph.addEdge(5, 6);
    graph.addEdge(5, 8);

    graph.addEdge(6, 5);
    graph.addEdge(6, 1);
    graph.addEdge(6, 2);
    graph.addEdge(6, 3);
    graph.addEdge(6, 7);
    graph.addEdge(6, 9);

    graph.addEdge(7, 6);
    graph.addEdge(7, 2);
    graph.addEdge(7, 3);
    graph.addEdge(7, 9);

    graph.addEdge(8, 5);
    graph.addEdge(8, 4);
    graph.addEdge(8, 9);

    graph.addEdge(9, 8);
    graph.addEdge(9, 6);
    graph.addEdge(9, 7);

    cout << "DFS starting from vertex 0:" << '\n';
    graph.DFSTraversal(0);

    cout << '\n' << "BFS starting from vertex 5:" << '\n';
    graph.BFSTraversal(5);

    return 0;
}
