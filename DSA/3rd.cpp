/*
Experiment 3 : Represent a given graph using adjacency matrix/list to perform DFS and using adjacency list to perform BFS. 
                Use the map of the area around the college as a graph. Identify the prominent land marks as nodes and perform DFS and BFS on that.
Adjacency Matrix : using adj matrix -BFS(Que)
*/

#include <iostream>
#include <stdlib.h>
using namespace std;
int cost[10][10], i, j, k, n, qu[10], front, rear, v, visit[10], visited[10];
int stk[10], top, visit1[10], visited1[10];
int main()
{
    int m;
    cout << "Enter number of vertices : ";
    cin >> n;
    cout << "Enter number of edges : ";
    cin >> m;
    
    cout << "\nEDGES :\n";
    for (k = 1; k <= m; k++)
    {
        cin >> i >> j;
        cost[i][j] = 1;
        cost[j][i] = 1;
    }
    
    //display function
    cout << "The adjacency matrix of the graph is : " << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << " " << cost[i][j];
        }
        cout << endl;
    }
    
    cout << "Enter initial vertex : ";
    cin >> v;
    cout << "The BFS of the Graph is\n";
    cout << v<<endl;
    visited[v] = 1;
    k = 1;
    while (k < n)
    {
        for (j = 1; j <= n; j++)
            if (cost[v][j] != 0 && visited[j] != 1 && visit[j] != 1)
            {
                visit[j] = 1;
                qu[rear++] = j;
            }
        v = qu[front++];
        cout << v << " ";
        k++;
        visit[v] = 0;
        visited[v] = 1;
    }
    
    cout <<endl<<"Enter initial vertex : ";
    cin >> v;
    cout << "The DFS of the Graph is\n";
    cout << v<<endl;
    visited[v] = 1;
    k = 1;
    while (k < n)
    {
        for (j = n; j >= 1; j--)
            if (cost[v][j] != 0 && visited1[j] != 1 && visit1[j] != 1)
            {
                visit1[j] = 1;
                stk[top] = j;
                top++;
            }
        v = stk[--top];
        cout << v << " ";
        k++;
        visit1[v] = 0;
        visited1[v] = 1;
    }
    return 0;
}

/******OUTPUT*****
 * Enter number of vertices : 3
Enter number of edges : 6

EDGES :
1
2
1
3
2
2
2
3
3
1
3 
2
The adjacency matrix of the graph is : 
 0 0 0
 0 0 1
 0 1 1
Enter initial vertex : 0
The BFS of the Graph is
0
0 0
Enter initial vertex : 1
The DFS of the Graph is
1
2 1




The code you provided demonstrates the implementation of Breadth-First Search (BFS) and Depth-First Search (DFS) algorithms on a graph using an adjacency matrix representation. Here's a breakdown of the code:

1. Declarations and Definitions:
   - The code starts by declaring and defining various variables and arrays used in the program.
   - `cost` is a 2D array used as an adjacency matrix to represent the graph.
   - `qu` is an array used as a queue for BFS.
   - `stk` is an array used as a stack for DFS.
   - `visit`, `visited`, `visit1`, `visited1` are arrays used to keep track of visited and unvisited vertices during BFS and DFS.

2. Input:
   - The user is prompted to enter the number of vertices (`n`) and the number of edges (`m`).
   - The user is then prompted to enter the edges between the vertices.
   - The adjacency matrix `cost` is populated based on the entered edges.

3. Displaying the Adjacency Matrix:
   - The program displays the adjacency matrix of the graph, showing the connections between vertices.

4. Breadth-First Search (BFS):
   - The user is prompted to enter the initial vertex for BFS.
   - BFS traversal begins from the initial vertex.
   - The algorithm visits all connected vertices in breadth-first order and prints them.
   - The `visited` and `visit` arrays are used to keep track of visited and unvisited vertices during traversal.

5. Depth-First Search (DFS):
   - The user is prompted to enter the initial vertex for DFS.
   - DFS traversal begins from the initial vertex.
   - The algorithm explores as far as possible along each branch before backtracking.
   - The `visited1` and `visit1` arrays are used to keep track of visited and unvisited vertices during traversal.

Note: The code assumes that the vertices are numbered from 1 to `n`. The adjacency matrix is populated based on the entered edges, where `cost[i][j] = 1` indicates an edge between vertices `i` and `j`.

Overall, this code demonstrates the implementation of BFS and DFS algorithms on a graph using an adjacency matrix representation. It allows you to enter the graph's edges, displays the adjacency matrix, and performs BFS and DFS traversals from a specified initial vertex.

*/