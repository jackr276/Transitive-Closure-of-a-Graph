# Transitive Closure of a Graph 
Author: [Jack Robbins](https://www.github.com/jackr276)

## Introduction
The transitive closue of a directed, acyclic graph can be casually defined as the "reachability matrix" of any given graph. That is, a matrix in which the intersection of any two vertices is either 0, meaning that the column vertice cannot reach the row vertice, or 1, meaning the opposite.    

For a more formal definition, the transitive closure of a given graph $G$ is defined as follows: 
> Given a directed acyclic graph $G$ with $N$ vertices, the transitive closure $T$ is an $N \times N$ matrix where $T$($U$, $V$) = $1$ if and only if $V$ is reachable from $U$. In $T$, there exist a path from all vertices that is of length at most $N$

It is easy to see the practical applications of this if our graph is representing real world data, such as a GPS map or network schema. This project, however, simply shows the theoretical side of computing the transitive closure.

## The Floyd-Warshall Algorithm
The Floyd-Warshall Algorithm is a very simple procedure for finding the shortest path for all of the vertices on a graph. It is a very simple procedure that iterates through every intermediate node in the graph. For each intermediate node, it goes through every other node and updates the distance in adjacency matrix that holds the distance values. The Floyd-Warshall algorithm is as follows:   

   
![Screenshot from 2024-08-11 12-27-38](https://github.com/user-attachments/assets/49b05cb9-aa02-439b-bdf5-ed21d6e71df0)


For our cases though, the transitive closure of a graph does not care about minimum distance at all, so we can make the algorithm slightly simpler to reflect this.


### Adapting the Floyd-Warshall Algorithm to fit this problem

```cpp
//Go through all vertices K
for(int k = 0; k < num_vertices; k++){	
    //Go through all "source" vertices one by one
    for(int i = 0; i < num_vertices; i++){
        //Go through all "destination" vertices one by one
        for(int j = 0; j < num_vertices; j++){
          //If vertex K is is on the path from i to j, then we mark transitive_closure[i][j] as 1 because
          //it can be reached via i and j
          transitive_closure[i][j] = transitive_closure[i][j] ||
                                    (transitive_closure[i][k] && transitive_closure[k][j]);
        }
    }
}
```
In our adaptation here, we remove the storage of shortest distances because they are irrelevant to our transitive closure. Instead, we simply store 0 or 1 and use the binary `&&` and `||` operators to assign the matrix value to be 0 or 1 based on if we find a path that contains vertex `k` as an intermediary vertex between `i` and `j`. It is simple to see that this algorithm runs in $O$($V^3$) time, due to the triple for loop. Though this is not the best time complexity, it is acceptable for small graphs.   

## Running this program
To run this program for yourself, first clone the repository and `cd` into the location on your local machine. A simple runner script, [run.sh](https://github.com/jackr276/Transitive-Closure-of-a-Graph/blob/main/run.sh) is provided for convenience. We use to run the program in this way:
```console
example@bash: ~/Transitive-Closure-of-a-Graph $ chmod +x run.sh
example@bash: ~/Transitive-Closure-of-a-Graph $ ./run.sh
Enter the number of vertices in the graph: 5
Enter the adjacency list for the graph that you desire to use. When done entering, enter <d>
2 3
4 5
1 2
2 1
d

You entered a graph described by the reachability matrix below:
	* 1 2 3 4 5 
	1 1 1 0 0 0 
	2 1 1 1 0 0 
	3 0 0 1 0 0 
	4 0 0 0 1 1 
	5 0 0 0 0 1 

Now finding the transitive closure, G+, of the graph that was inputted

G1: All paths of length 1 or less accounted for
	* 1 2 3 4 5 
	1 1 1 0 0 0 
	2 1 1 1 0 0 
	3 0 0 1 0 0 
	4 0 0 0 1 1 
	5 0 0 0 0 1 

G2: All paths of length 2 or less accounted for
	* 1 2 3 4 5 
	1 1 1 1 0 0 
	2 1 1 1 0 0 
	3 0 0 1 0 0 
	4 0 0 0 1 1 
	5 0 0 0 0 1 

G3: All paths of length 3 or less accounted for
	* 1 2 3 4 5 
	1 1 1 1 0 0 
	2 1 1 1 0 0 
	3 0 0 1 0 0 
	4 0 0 0 1 1 
	5 0 0 0 0 1 

G4: All paths of length 4 or less accounted for
	* 1 2 3 4 5 
	1 1 1 1 0 0 
	2 1 1 1 0 0 
	3 0 0 1 0 0 
	4 0 0 0 1 1 
	5 0 0 0 0 1 

G5: All paths of length 5 or less accounted for
	* 1 2 3 4 5 
	1 1 1 1 0 0 
	2 1 1 1 0 0 
	3 0 0 1 0 0 
	4 0 0 0 1 1 
	5 0 0 0 0 1 

The transitive closure of the input graph, G+, is:
	* 1 2 3 4 5 
	1 1 1 1 0 0 
	2 1 1 1 0 0 
	3 0 0 1 0 0 
	4 0 0 0 1 1 
	5 0 0 0 0 1 

example@bash: ~/Transitive-Closure-of-a-Graph $
```
