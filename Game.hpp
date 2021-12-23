/*
MacGregor Winegard
Start date: 12/20/2021
This is the game object, which will be what we build the actual game around.
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
		string current_board;
		vector <char> consonants_not_guessed;
		vector <char> vowels_not_guessed;
		
		
		
	public:
		Game(){
			cout << "Welcome to... WHEEL OF FORTUNE!" << endl;
			
			Puzzle the_puzz;
			this -> puzzle = the_puzz; 
			this -> num_players = 2;
			this -> current_board = "";
			
			this -> consonants_not_guessed = {
				'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 
				'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 
				'X', 'Y', 'Z' };
			
			this -> vowels_not_guessed = {
				'A', 'E', 'I', 'O', 'U'	};
			
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
		
		
	/*
		This is the main function that the game will be really played in
	*/
		void gameplay()
		{
			/*
				Initializes whose turn it is, is the game over and sets up the board
			*/
			int current_turn = 0;
			bool game_over = false;
			this ->initialize_current_board();
			
			while(!game_over)
			{
				this -> print_scoreboard();
				this -> print_vanna();
				game_over = this -> player_turn(current_turn);
				
				//break;
				
			}
		}
		
		// Takes the phrase for the puzzle and turns it into blanks
		void initialize_current_board()
		{
			// http://www.cplusplus.com/forum/beginner/33835/
			string phrase = this->puzzle.get_phrase();
			
			for (int i = 0; i < phrase.length(); i++)
			{
				if(phrase.at(i) == ' ')
					this-> current_board = 
						this-> current_board + " ";
				else
					this-> current_board = 
						this-> current_board + "_";
			}
		}
		
		// Prints all 3 player names and their scores
		void print_scoreboard()
		{
			system("cls");
			cout << "\n   Score Board   " << endl;
			cout << "|***************|" << endl;	
			
			for (int i = 0; i <= this -> num_players; i++)
				cout << "  "<<this -> player_list[i].get_name() 
					<< ": "	<< this -> player_list[i].get_score() 
					<< endl;
			
			cout << "|***************|\n" << endl;
		}
		
		
		// Prints the state of the board
		void print_vanna()
		{
			cout << "The board:" << endl;
			cout << this -> current_board << "\n\n"<< endl;
		}
		
		/*
			The entirety of a players turn will be built out of this. 
			First it asks if they want to 
				1) Spin the wheel
				2) Buy a vowel
				3) solve the puzzle
				
			If they spin the wheel:
				Use a random num generator to get wheel result
				Ask them to input a char
				Check if that char has already been guessed
				if !already guessed then add to guessed and see if in phrase
				
			If they Buy a vowel:
				Check if already bought, then if not let them buy it
			
			If they want to solve the puzzle
				Have them type out the full sentance, we'll have to do a string compare then. 
				
				
			inputs:
				Index of player whose turn it is.
			
			returns:
				A boolean of whether or not they solved the puzzle
		*/
		bool player_turn(int turn_index)
		{
			cout << "Pat: \"" << this -> get_player(turn_index).get_name()
				<< ", it is your turn!\"" << endl;
				
				int player_choice = this -> player_choice_input();
				
				
				switch(player_choice)
				{
					case 1:
						cout << "Player chose to spin the wheel." << endl;
						break;
					
					case 2:
						cout << "Player chose to buy a vowel." << endl;
						break;
					case 3:
						cout << "Player chose to solve the puzzle." << endl;
						break;
					default:
						cout << "Not valid choice!" << endl;
						break;
				}
				
			return true;
		}
		
		int player_choice_input()
		{
			cout << "Pat: \"Choose what to do: \" " << endl;
			cout << "\t1) Spin the wheel" << endl;
			cout <<"\t2) Buy a vowel" << endl;
			cout <<"\t3) solve the puzzle" << endl;
			cout << "choice: ";
			
			int return_player_choice;
			cin >> return_player_choice;
			
			return return_player_choice;
		}
		
		void buy_vowel(int turn_index)
		{
			int vowel_cost = 250;
			
			
			
		}
		
};
	