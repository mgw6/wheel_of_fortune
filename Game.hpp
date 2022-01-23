/*
MacGregor Winegard
Start date: 12/20/2021
This is the game object, which will be what we build the actual game around.
*/

/*
Right now we need to write the choose letter method. 

This will be similar to the buy vowel method.

*/


#include <vector>
#include <iostream>
#include <iterator>
//#include <stdlib.h>
//#include <iomanip>
#include <algorithm> 
#include <chrono>
#include <thread>

using namespace std::this_thread;
using namespace std::chrono;
using namespace std;

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
				
				game_over = this -> player_turn(current_turn);
				
				if(!game_over)
				{
					current_turn++;
					if (current_turn > 2)
						current_turn = 0;
				}
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
			cout << "The Category is: \n"
				<< this ->puzzle.get_category()
				<< "\n" << endl;
			
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
			system("cls");
			cout << "Pat: \"" << this -> get_player(turn_index).get_name()
				<< ", it is your turn!\"" << endl;
				
				
				bool turn_over = false;
				while (!turn_over)
				{
					this -> print_scoreboard();
					this -> print_vanna();
					
					int player_choice = this -> player_choice_input();
					
					switch(player_choice)
					{
						case 1:
							cout << "Player chose to spin the wheel." << endl;
							cout << "This method has not been built yet." << endl;
							break;
						
						case 2:
							cout << "Player chose to buy a vowel." << endl;
							turn_over = this->buy_vowel(turn_index);
							break;
						case 3:
							cout << "Player chose to solve the puzzle." << endl;
							cout << "This method has not been built yet." << endl;
							// Will straight return whether or not they solve it correctly
							break;
						default:
							cout << "Not valid choice!" << endl;
							break;
					}
				}
				
			return false; // will eventually return false
		}
		
		
		/*
			Displays the player's choices on their turn
			
			Returns:
				What their choice was
		*/
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
		
		bool buy_vowel(int turn_index)
		{
			int vowel_cost = 250;
			char vowel_choice;
			
			cout << "What vowel would you like to buy? " << endl;
			cout << "Choice: ";
			cin >> vowel_choice;
			
			vowel_choice = toupper(vowel_choice);
			cout << vowel_choice << endl;
			
			
			std::vector<char>::iterator iter = std::find(
					this -> vowels_not_guessed.begin(), 
					this -> vowels_not_guessed.end(), 
					vowel_choice); // Checks if letter has been guessed yet
			
			if (iter != this -> vowels_not_guessed.end())
			{ // if it has not been guessed yet
		
				cout << "vowel not chosen" << endl;
				
				this -> vowels_not_guessed.erase(
					remove(
						this -> vowels_not_guessed.begin(),
						this -> vowels_not_guessed.end(),
						vowel_choice),
					this->vowels_not_guessed.end()
				);
				
				int num_appear = this -> find_letter_in_phrase(vowel_choice);
				
				if (num_appear == 0)
				{
					cout << vowel_choice << " is not in the phrase."
						<< endl;
					sleep_until(system_clock::now() + seconds(2));
					return true;
				}
				else
				{
					cout << vowel_choice << " is in the phrase "
						<< num_appear << " times." << endl;
					this->player_list[turn_index].decrease_score(num_appear * vowel_cost);
					sleep_until(system_clock::now() + seconds(2));
					return false;
				}
					
			} else { // vowel cannot be guessed	
				cout << "This input cannot be chosen." << endl;
				return true;
			}
			
			cout << "I'm pretty sure that if you're reading this then" <<
				"there has been an issue.\n" <<
				"Message from end of buy_vowel()" << endl;
				
			return false;
		}
	
	
	
	int find_letter_in_phrase(char letter)
	{
		string phrase = this->puzzle.get_phrase();
		int count = 0;
		
		for (int i = 0; i < phrase.length(); i++)
		{
			if(phrase.at(i) == letter)
			{
				this-> current_board[i] = 
					letter;
				count++;
			}
		}
		return count;
	}
		
};
	