/**
 * Author: Jack Robbins, jmr226
 * CS 610 SU24, Programming Assignment 3
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>


void print_matrix(short** adjacency_matrix, int num_vertices){
	printf("* ");
	//Print out the top row, which are vertex labels
	for(int i = 0; i < num_vertices; i++){
		printf("%d ", i + 1);
	}

	printf("\n");

	//Now we can print out what we actually have in the matrix
	for(int i = 0; i < num_vertices; i++){
		//Print out the column labels
		printf("%d ", i + 1);
		for(int j = 0; j < num_vertices; j++){
			printf("%d ", adjacency_matrix[i][j]);	
		}
		printf("\n");
	}

	printf("\n");
}


short** create_adjacency_matrix(int num_vertices){
	//Once we know that the input is good, we can define our adjacency matrix
	short** adjacency_matrix = (short**)malloc(sizeof(short*) * num_vertices);

	//Reserve space for each row in the matrix
	for(int i = 0; i < num_vertices; i++){
		adjacency_matrix[i] = (short*)calloc(num_vertices, sizeof(short));
	}

	return adjacency_matrix;
}


void teardown_adjacency_matrix(short** adjacency_matrix, int num_vertices){
	for(int i = 0; i < num_vertices; i++){
		free(adjacency_matrix[i]);
	}

	free(adjacency_matrix);
}


void parse_and_input_line(std::string line, short** adjacency_matrix){
	if(line == "" || line == "d") return;
	//Grab a stringstream of the input
	std::stringstream input(line);
	
	char ch;
	int from_vertex, to_vertex;

	//The first char should be the 'from' vertex 
	input.get(ch);
	
	from_vertex = ch - '0';

	//Skip whitespace
	input >> std::ws;

	input.get(ch);

	to_vertex = ch - '0';

	//Populate the adjacency_matrix
	adjacency_matrix[from_vertex - 1][to_vertex - 1] = 1;	
	
}


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

	//We also don't want to overflow
	int entered_so_far = 0;

	//Keep grabbing input for the adjacency list
	while(input != "d" && input != "D"){
		std::getline(std::cin, input);
		parse_and_input_line(input, input_graph);		
	} 

	printf("You entered a graph described by the adjacency matrix below\n");
	print_matrix(input_graph, num_vertices);

	//Let the environment know all went well
	return 0;
}
