/* 
MacGregor Winegard
12/20/2021
This is a puzzle object that contains a category and the phrase that is the answer
*/

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int len_of_list = 3; // Must match the first []
string list_of_puzzles [3] [2] = {
	/* 
	This will bea list of lists of all of the categories
	and their resulting puzzles
	*/
	{"The answer is test1", "test1"},
	{"The answer is test2", "test2"},
	{"The answer is test3", "test3"},
};


class Puzzle {
	private:
		string category;
		string phrase;
		
	public: 
		Puzzle()
		{
			srand(time(0)); // https://www.youtube.com/watch?v=naXUIEAIt4U
			int rand_num = rand() % len_of_list; // generates a random number between 0 and list length
			//cout << "Random number: " << rand_num << endl;
			this -> category = list_of_puzzles [rand_num] [0]; // extracts catgoru
			this -> phrase = list_of_puzzles [rand_num] [1]; // and puzzle
		}
		
		/* 
		Only writing getters since the puzzle is set
		on initialization and should not be changed
		*/
		string get_category()
		{
			return this -> category;
		}
		
		string get_phrase()
		{
			return this -> phrase;
		}
};