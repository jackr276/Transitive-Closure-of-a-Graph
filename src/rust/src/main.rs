/**
 * Author: Jack Robbins
 * This program finds the transitive closure of a graph that is inputted by the user as a
 * reachability list
 **/

use std::io::Write;


/**
 * Parse and interpret a line of text that represents reachability, entered by a user
 */
fn parse_and_interpret(input: &String, num_vertices: i8){

}


/**
 * The main entry point to our program. Makes appropriate function calls and grabs user
 * input
 */
fn main() {
    //We need a place to store our user's input
    let mut user_input = String::new();

    //Prompt our user
    print!("Enter the number of vertices in the graph: ");

    //Flush stdout to the screen
    let _ = std::io::stdout().flush();
  
    //Grab what the user wrote
    std::io::stdin().read_line(&mut user_input).expect("String entered improperly");

    //Convert to an int, the unwrap will cause a panic if it is bad
    let num_vertices = match user_input.trim().parse::<i8>() {
        Ok(n) => n, 
        Err(_) => { 
            println!("Bad input"); 
            1
        }
    };

    //Now get the user input line by line for the edge graph
    println!("Enter the edge list for the graph. When done, enter <d>");
    
    //So long as the input isn't "d", we'll keep parsing
    while !user_input.trim().eq(&String::from("d")) {      
        user_input.clear();
        std::io::stdin().read_line(&mut user_input).expect("String entered improperly");

        //Parse and interpret the line into our reachability matrix
        parse_and_interpret(&user_input, num_vertices)

    }
    

}
