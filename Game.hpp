/*
MacGregor Winegard
Start date: 12/20/2021
This is the game object, which will be called in the play game
*/


#include <vector>
#include <iostream>
#include <iterator>
#include <stdlib.h>
#include <iomanip>

#include "Player.hpp"
#include "Puzzle.hpp"

using namespace std;

class Game {
	private:
		vector <Player> player_list;
		Puzzle puzzle;
		int num_players;
		string known_puzzle;
		
	public:
		Game(){
			cout << "Welcome to... WHEEL OF FORTUNE!" << endl;
			
			Puzzle the_puzz;
			this -> puzzle = the_puzz;
			this -> num_players = 2;
			
			// This initializes the 3 players for the game
			for(int i = 0; i <= this -> num_players; i++)
			{
				string temp_name;
				cout << "Enter player " << i+1 << "'s name: ";
				cin >> temp_name;
				this -> player_list.emplace_back(temp_name);
			}
		}
		
		Player get_player(int player_num)
		{
			return this -> player_list[player_num];
		}
	
		Puzzle get_puzzle()
		{
			return this -> puzzle;
		}
		
		
		void gameplay()
		{
			this -> print_scoreboard();
		}
		
		
		void print_scoreboard()
		{
			system("cls");
			cout << "   Score Board   " << endl;
			cout << "|***************|" << endl;
			
			
			for (int i = 0; i <= this -> num_players; i++)
			{
				cout << "  "<<this -> player_list[i].get_name() 
				<< ": "	<< this -> player_list[i].get_score() 
				<< endl;
			}
			
			cout << "|***************|" << endl;
			
		}
		
};
	