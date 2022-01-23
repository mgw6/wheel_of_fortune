/* 
MacGregor Winegard
12/20/2021
This is a wheel object, that returns the result of spinning the wheel
*/

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

/*
Honestly I don't remember what my thought process was for this originally. 

Basically this just needs to simulate the wheel, 
return a score for what they get. 

I think I'll have it return 0 for bankrupt. 
I should look at the real wheel and try to mimic the scores.`
*/

class Wheel{
	
	public:
		Wheel()
		{}
		
		int spin()
		{
			
			int num_slices = 1; //This is the number of outcomes on the wheel
			srand(time(0)); // https://www.youtube.com/watch?v=naXUIEAIt4U
			int rand_num = rand() % num_slices; // generates a random number between 0 and list length
			
			if 
			
			
			
			
			
		}
		/*
		Potential wheel outcomes:
			$500 - x6	
			$550
			$600 - x4
			650 - x2
			$700 - x3
			$800
			$900
			$5000
			Bankrupt x2
			Lose a turn
			Free play (?)
		*/
}