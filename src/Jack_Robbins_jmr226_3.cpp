/**
 * Author: Jack Robbins, jmr226
 * CS 610 SU24, Programming Assignment 3
 */

#include <iostream>




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
	
	


	//Let the environment know all went well
	return 0;
}
