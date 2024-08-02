/**
 * Author: Jack Robbins, jmr226
 * CS 610 SU24, Programming Assignment 3
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>


/**
 * Takes in and displays in a nice format an adjacnecy matrix of dimensions
 * num_vertices x num_vertices
 */
void print_matrix(short** adjacency_matrix, int num_vertices){
	printf("\t* ");
	//Print out the top row, which are vertex labels
	for(int i = 0; i < num_vertices; i++){
		printf("%d ", i + 1);
	}

	printf("\n");

	//Now we can print out what we actually have in the matrix
	for(int i = 0; i < num_vertices; i++){
		//Print out the column labels
		printf("\t%d ", i + 1);
		for(int j = 0; j < num_vertices; j++){
			printf("%d ", adjacency_matrix[i][j]);	
		}
		printf("\n");
	}

	printf("\n");
}


/**
 * Dynamically allocates and returns a reference to an adjacency matrix of dimensions
 * num_vertices x num_vertices
 */
short** create_adjacency_matrix(int num_vertices){
	//Once we know that the input is good, we can define our adjacency matrix
	short** adjacency_matrix = (short**)malloc(sizeof(short*) * num_vertices);

	//Reserve space for each row in the matrix
	for(int i = 0; i < num_vertices; i++){
		adjacency_matrix[i] = (short*)calloc(num_vertices, sizeof(short));
	}

	//Give the pointer back to the caller
	return adjacency_matrix;
}


/**
 * This function frees the memory from an adjacency matrix properly
 */
void teardown_adjacency_matrix(short** adjacency_matrix, int num_vertices){
	//Free each individual row pointer
	for(int i = 0; i < num_vertices; i++){
		free(adjacency_matrix[i]);
	}

	//Free the overall pointer
	free(adjacency_matrix);
}


/**
 * This function will parse the input lines taken from the user and load them into the adjacency matrix
 * accordingly
 */
void parse_and_input_line(std::string line, short** adjacency_matrix, int num_vertices){
	//Remove bad inputs
	if(line == "" || line == "d"){
		return;
	}

	//Grab a stringstream of the input
	std::stringstream input(line);
	
	char ch;
	int from_vertex, to_vertex;

	//The first char should be the 'from' vertex 
	input.get(ch);

	//Convert this into a number
	from_vertex = ch - '0';

	//Error handling for the from vertex
	if(from_vertex > num_vertices || from_vertex < 0){
		std::cerr << "Error: Vertex " << from_vertex << " is invalid and will not be entered" << std::endl;
		exit(1);
	}

	//Skip whitespace
	input >> std::ws;

	input.get(ch);

	to_vertex = ch - '0';

	//Error handling for the to vertex
	if(to_vertex > num_vertices || to_vertex < 0){
		std::cerr << "Error: Vertex " << to_vertex<< " is invalid and will not be entered" << std::endl;
		exit(1);
	}

	//Populate the adjacency_matrix
	adjacency_matrix[from_vertex - 1][to_vertex - 1] = 1;	
	
}


short** transitive_closure(short** adjacency_matrix, int num_vertices){
	short** transitive_closure = create_adjacency_matrix(num_vertices);

	//We'll just do a quick copy of what we were given into what will eventually become our transitive_closure
	for(int i = 0; i < num_vertices; i++){
		for(int j = 0; j < num_vertices; j++){
			transitive_closure[i][j] = adjacency_matrix[i][j];
		}
	}

	for(int k = 0; k < num_vertices; k++){
	
		for(int i = 0; i < num_vertices; i++){
			for(int j = 0; j < num_vertices; j++){
				transitive_closure[i][j] = transitive_closure[i][j] || transitive_closure[i][k] && transitive_closure[k][j];
			}
		}

		//Show the user what we have so far
		printf("G%d:\n", k);
		print_matrix(transitive_closure, num_vertices);
	}	

	return transitive_closure;
}


/**
 * The main function takes in user input and parses it into the adjacency matrix as the user inputs values.
 * Any command line arguments will be disregarded entirely
 */
int main(void){
	//Grab the number of nodes the user would like to have
	int num_vertices;
	std::cout << "Enter the number of vertices in the graph: ";
	std::cin >> num_vertices;

	//Some simple input validation
	if(num_vertices <= 0){
		std::cerr << "Input Error: The number of nodes must be a positive integer." << std::endl;
		exit(1);
	}

	//Initialize a matrix for us
	short** input_graph = create_adjacency_matrix(num_vertices);

	//We now need to construct the adjacency matrix based on what the user puts in
	std::cout << "Enter the adjacency list for the graph that you desire to use. When done entering, enter <d>" << std::endl;

	//Store our input here
	std::string input = "";

	//Keep grabbing input for the adjacency list
	while(input != "d" && input != "D"){
		std::getline(std::cin, input);
		parse_and_input_line(input, input_graph, num_vertices);		
	} 

	//Show the user what they've entered
	printf("You entered a graph described by the adjacency matrix below:\n");
	print_matrix(input_graph, num_vertices);

	printf("Now finding the transitive closure, G+, of the graph that was inputted\n");
	short** tran_closure = transitive_closure(input_graph, num_vertices);


	//Let the environment know all went well
	return 0;
}
