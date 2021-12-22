/* 
MacGregor Winegard
Start Date: 12/20/2021

This is the Player object, which the game will use. 
Pretty straightforward and self-explanatory. 
*/

#include <iostream>

using namespace std;

class Player {
	private:
		std::string name; 
		int score;
	
	public: 
		Player(string name)
		{
			this -> name = name;
			this -> score = 0;
		}

	string get_name()
	{
		return this -> name;
	}
	
	int get_score()
	{
		return this -> score;
	}
	
	void set_score(int score)
	{
		this -> score = score;
	}
	
	void increase_score(int score)
	{
		this -> score = this -> score + score;
	}
	
	void decrease_score(int score)
	{
		this -> score = this -> score - score;
	}
};