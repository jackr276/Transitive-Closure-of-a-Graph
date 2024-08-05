/**
 * Author: Jack Robbins
 * This program finds the transitive closure of a graph that is inputted by the user as a
 * reachability list
 **/

use std::io::Write;


/**
 * Parse and interpret a line of text that represents reachability, entered by a user
 */
fn parse_and_interpret(input: String){

}







/**
 * The main entry point to our program. Makes appropriate function calls and grabs user
 * input
 */
fn main() {
    //The number of vertices in our graph
    let num_vertices: i8;
  
    //We need a place to store our user's input
    let mut user_input = String::new();

    //Prompt our user
    print!("Enter the number of vertices in the graph: ");

    //Flush stdout to the screen
    let _ = std::io::stdout().flush();
  
    //Grab what the user wrote
    std::io::stdin().read_line(&mut user_input).expect("String entered improperly");

    println!("{}", user_input);




}
