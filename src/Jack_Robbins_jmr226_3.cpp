/**
 * Author: Jack Robbins, jmr226
 * CS 610 SU24, Programming Assignment 3
 */

#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>


void print_matrix(short** adjacency_matrix, int num_vertices){
	
}


int main(void){
	//Grab the number of nodes the user would like to have
	int num_vertices;
	std::cout << "Enter the number of vertices in the graph: ";
	std::cin >> num_vertices;

	//Some simple input validation
	if(num_vertices <= 0){
		std::cerr << "Input Error: The number of nodes must be positive." << std::endl;
		exit(1);
	}

	//Once we know that the input is good, we can define our adjacency matrix
	short** adjacency_matrix = (short**)malloc(sizeof(short*) * num_vertices);

	//Reserve space for each row in the matrix
	for(int i = 0; i < num_vertices; i++){
		adjacency_matrix[i] = (short*)malloc(sizeof(short) * num_vertices);
	}

	//We now need to construct the adjacency matrix based on what the user puts in
	std::cout << "Enter the adjacency list for the graph that you desire to use. When done entering, enter <d>" << std::endl;

	//Store our input here
	std::string input = "";

	//We also don't want to overflow
	int entered_so_far = 0;

	//Keep grabbing input for the adjacency list
	while(input != "d" && input != "D"){
		std::getline(std::cin, input);
						
	}
	

	//Let the environment know all went well
	return 0;
}
