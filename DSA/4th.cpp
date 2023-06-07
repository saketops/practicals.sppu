/*
Experiment 4 : There are flight paths between cities. If there is a flight between City A and City B then there is an edge between the cities. 
The cost of the edge can be the time that flight take to reach city B from A, or the amount of fuel used for the journey. Represent this as a graph.
The node can be represented by the airport name or name of the city. Use adjacency list representation of the graph or use adjacency matrix representation of the graph.
*/

#include <iostream>
#include <queue>
using namespace std;
int adj_mat[50][50] = {0, 0};
int visited[50] = {0};
void dfs(int s, int n, string arr[])
{
    visited[s] = 1;
    cout << arr[s] << " ";
    for (int i = 0; i < n; i++)
    {
        if (adj_mat[s][i] && !visited[i])
            dfs(i, n, arr);
    }
}
void bfs(int s, int n, string arr[])
{
    bool visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    int v;
    queue<int> bfsq;
    if (!visited[s])
    {
        cout << arr[s] << " ";
        bfsq.push(s);
        visited[s] = true;
        while (!bfsq.empty())
        {
            v = bfsq.front();
            for (int i = 0; i < n; i++)
            {
                if (adj_mat[v][i] && !visited[i])
                {
                    cout << arr[i] << " ";
                    visited[i] = true;
                    bfsq.push(i);
                }
            }
            bfsq.pop();
        }
    }
}
int main()
{
    cout << "Enter no. of cities: ";
    int n, u;
    cin >> n;
    string cities[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter city #" << i << " (Airport Code): ";
        cin >> cities[i];
    }
    
    cout << "\nYour cities are: " << endl;
    for (int i = 0; i < n; i++)
        cout << "city #" << i << ": " << cities[i] << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            cout << "Enter distance between " << cities[i] << " and " << cities[j] << " : ";
            cin >> adj_mat[i][j];
            adj_mat[j][i] = adj_mat[i][j];
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << "\t" << cities[i] << "\t";
    for (int i = 0; i < n; i++)
    {
        cout << "\n"
             << cities[i];
        for (int j = 0; j < n; j++)
            cout << "\t" << adj_mat[i][j] << "\t";
        cout << endl;
    }
    cout << "Enter Starting Vertex: ";
    cin >> u;
    cout << "DFS: ";
    dfs(u, n, cities);
    cout << endl;
    cout << "BFS: ";
    bfs(u, n, cities);
    return 0;
}

/******OUTPUT*****
 * Enter no. of cities: 3
Enter city #0 (Airport Code): 1
Enter city #1 (Airport Code): 2
Enter city #2 (Airport Code): 3

Your cities are: 
city #0: 1
city #1: 2
city #2: 3
Enter distance between 1 and 2 : 20
Enter distance between 1 and 3 : 90
Enter distance between 2 and 3 : 60

        1               2               3
1       0               20              90

2       20              0               60

3       90              60              0
Enter Starting Vertex: 1
DFS: 2 1 3 
BFS: 2 1 3

This code implements a graph traversal program using Depth-First Search (DFS) and Breadth-First Search (BFS) algorithms in C++.

Here's a breakdown of the code:

1. The code includes necessary header files: `iostream` for input/output and `queue` for using the queue data structure.

2. The code declares and initializes an adjacency matrix `adj_mat` with a size of 50x50, and an array `visited` to keep track of visited nodes.

3. The `dfs()` function performs a Depth-First Search traversal. It takes the starting node `s`, the total number of cities `n`, and an array `arr` containing the city names as parameters. The function marks the current node as visited, prints its name, and recursively calls itself on adjacent nodes that haven't been visited.

4. The `bfs()` function performs a Breadth-First Search traversal. It takes the starting node `s`, the total number of cities `n`, and an array `arr` containing the city names as parameters. The function initializes a boolean array `visited` to track visited nodes. It uses a queue `bfsq` to store nodes to be visited. It starts by enqueuing the starting node, marks it as visited, and prints its name. Then, it dequeues a node, visits its adjacent unvisited nodes, enqueues them, and marks them as visited. This process continues until the queue becomes empty.

5. In the `main()` function, the user is prompted to enter the number of cities (`n`). An array `cities` is declared to store the names of the cities.

6. The code prompts the user to enter the names of the cities and stores them in the `cities` array.

7. Next, the code prompts the user to enter the distances between the cities and constructs the adjacency matrix `adj_mat`. The distances are symmetric, so the matrix is filled accordingly.

8. The adjacency matrix is displayed to the user.

9. The user is prompted to enter the starting vertex (`u`) for the traversal.

10. The DFS traversal is performed by calling the `dfs()` function with the starting vertex, the total number of cities, and the `cities` array.

11. The BFS traversal is performed by calling the `bfs()` function with the starting vertex, the total number of cities, and the `cities` array.

That's the overall explanation of the code. It allows the user to input cities and their distances, and then performs both DFS and BFS traversals on the given graph.
*/