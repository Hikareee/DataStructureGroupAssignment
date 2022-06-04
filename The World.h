#include <chrono>

//Start taking in time 
 auto started = std::chrono::high_resolution_clock::now();
 
//The good stuff 
 
//stop time 
auto done = std::chrono::high_resolution_clock::now();

//Lets see if your code can run faster than my grand mother 
cout << "\n" << "The runtime for this code is " << std::chrono::duration_cast<std::chrono::milliseconds>(done - started).count() << " milliseconds";
