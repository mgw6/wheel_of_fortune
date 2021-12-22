/*
MacGregor Winegard
Start date: 12/20/2021
This is the initial file I made to test the Player object, 
and eventually just became a scratch pad for testing stuff. 
*/

#include <iostream>
#include <stdio.h>
#include "Player.hpp"
#include "Puzzle.hpp"

using namespace std;

int test = 21;

int main()
{
	
	cout << "\nHello "<< "World\n";
	
	Puzzle puz1;
	
	cout << puz1.get_category() << endl;
	
	
	
	
	return 0;
}


/*
	cout << test << endl;
	
	Player player1("Jack");
	
	cout << "Name: " << player1.get_name() << endl;
	
	player1.set_score(300);
	player1.increase_score(300);
	
	cout << player1.get_score() << endl;
*/
