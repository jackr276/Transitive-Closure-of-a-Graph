# Transitive Closure of a Graph 
Author: [Jack Robbins](https://www.github.com/jackr276)

## Introduction
The transitive closue of a directed, acyclic graph can be casually defined as the "reachability matrix" of any given graph. That is, a matrix in which the intersection of any two vertices is either 0, meaning that the column vertice cannot reach the row vertice, or 1, meaning the opposite.    

For a more formal definition, the transitive closure of a given graph $G$ is defined as follows: 
> Given a graph $G$ with $N$ vertices, the transitive closure $T$ is an $N \times N$ matrix where $T$($U$, $V$) = $1$ if and only if $V$ is reachable from $U$

It is easy to see the practical applications of this if our graph is representing real world data, such as a GPS map or network schema. This project, however, simply shows the theoretical side of computing the transitive closure.

## The Floyd-Warshall Algorithm

### Adapting the Floyd-Warshall Algorithm to fit this problem
