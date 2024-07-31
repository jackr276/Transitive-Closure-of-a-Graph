/**
 * Author: Jack Robbins, jmr226
 * CS 610 SU24, Programming Assignment 3
 */

#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>


int main(void){


	//Grab the number of nodes the user would like to have
	int num_nodes;
	std::cout << "Enter the number of nodes in the graph: ";
	std::cin >> num_nodes;

	//Some simple input validation
	if(num_nodes <= 0){
		std::cerr << "Input Error: The number of nodes must be positive." << std::endl;
		exit(1);
	}

	//Once we know that the input is good, we can define our adjacency matrix
	short** adjacency_matrix = (short**)malloc(sizeof(short*) * num_nodes);

	//Reserve space for each row in the matrix
	for(int i = 0; i < num_nodes; i++){
		adjacency_matrix[i] = (short*)malloc(sizeof(short) * num_nodes);
	}

	//We now need to construct the adjacency matrix based on what the user puts in
	std::cout << "Enter the adjacency list for the graph that you desire to use. When done entering, enter <d>:" << std::endl;

	std::string input = "";

	//Keep grabbing input for the adjacency list
	while(input != "d" && input != "D"){
		std::getline(std::cin, input);
	}
	


	//Let the environment know all went well
	return 0;
}
