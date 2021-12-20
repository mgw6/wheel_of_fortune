#include <iostream>
#include "Player.hpp"

using namespace std;

int main()
{
	cout << "\nHello "<< "World\n";
	
	Player player1("Jack");
	
	cout << "Name: " << player1.get_name() << endl;
	
	player1.set_score(300);
	cout << player1.get_score() << endl;
	
	player1.increase_score(300);
	cout << player1.get_score() << endl;
	
	player1.decrease_score(300);
	cout << player1.get_score() << endl;
	
	return 0;
}