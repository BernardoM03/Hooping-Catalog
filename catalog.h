#include <iostream>
#include <fstream>

using namespace std;

//a struct to hold info of a team
struct Team {
  string name;        //name of the team
  string owner;       //owner of the team
  int market_value;   //market value of the team
  int num_player;     //number of players in the team
  struct Player *p;   //an array that holds all players
  float total_ppg;    //total points per game
};

//a struct to hold info of a player
struct Player {
  string name;      //name of the player
  int age;          //age of the player
  string nation;    //nationality of the player
  float ppg;        //points per game of the player
  float fg;         //field goal percentage
};


/**************************************************
 * Name: clear_buffer()
 * Description: clears error flags and discard extra characters
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: none
 ***********************************************/
void clear_buffer();

/**************************************************
 * Name: get_filename()
 * Description: Creates and returns a string input
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: a string for filename is inputted and returned 
 ***********************************************/
string get_filename();

/**************************************************
 * Name: read_file()
 * Description: Reads in first word of designated file
               and returns int of the number of teams
 * Parameters: filename - string of inputted filename
               &file_reader - reference to ifstream object
 * Pre-conditions: filename corresponds to an existing file
 * Post-conditions: ifstream object opens designated file
                     number of teams is returned
 ***********************************************/
int read_file(string filename, ifstream &file_reader);

/**************************************************
 * Name: get_option
 * Description: Do while loop that contains an options menu for all
               user options. Error checks invalid inputs, and proper
               inputs are redirected to functions that will execute
               the options.
 * Parameters: Team * team_list - pointer to the team_array
               int team_num - int of number of teams
               ofstream & file_writer - reference to ofstream object
 * Pre-conditions: Team/Player arrays have been allocated
                   ofstream object has been declared
 * Post-conditions: none
 ***********************************************/
void get_option(Team * team_list, int team_num, ofstream &file_writer);

/**************************************************
 * Name: console_file()
 * Description: Takes input for whether user wants to output information
               console or file. Error checks invalid inputs and returns
               string of desired input.
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: a string for console/file option is inputted and returned 
 ***********************************************/
string console_file();

/**************************************************
 * Name: search_player
 * Description: Depending on input generated from console_file(),
               call either search_player_console() or search_player_ofstream)
 * Parameters: Team * team_list - pointer to the team_array
               int team_num - int of number of teams
               ofstream & file_writer - reference to ofstream object
 * Pre-conditions: string option was generated as "1" or "2"
 * Post-conditions: none
 ***********************************************/
void search_player(Team * team_list, int team_num, ofstream &file_writer);

/**************************************************
 * Name: search_player_console()
 * Description: Take input for team name. Use a for loop to iterate
               through each index in allocated Team * array, and compare
               inputted team name with team name member variable of Team* array.
               If it matches, print out all player information of that team into 
               the console.
 * Parameters: Team * team_list - pointer to the team_array
               int team_num - int of number of teams
 * Pre-conditions: none
 * Post-conditions: prints specific team and corresponding
                   player information to console
 ***********************************************/
void search_player_console(Team * team_list, int team_num);

/**************************************************
 * Name: search_player_ofstream()
 * Description: Call get_filename() and open that files using ofstream object. 
               Take input for team name. Use a for loop to iterate
               through each index in allocated Team * array, and compare
               inputted team name with team name member variable of Team* array.
               If it matches, print out all player information of that team into 
               the file.
 * Parameters: Team * team_list - pointer to the team_array
               int team_num - int of number of teams
               ofstream & file_writer - reference to ofstream object
 * Pre-conditions: none
 * Post-conditions: prints specific team and corresponding
                   player information to file
 ***********************************************/
void search_player_ofstream(Team * team_list, int team_num, ofstream &file_writer);

/**************************************************
 * Name: display_top()
 * Description: Depending on input generated from console_file(),
               call either display_top_console() or display_top_ofstream)
 * Parameters: Team * team_list - pointer to the team_array
               int team_num - int of number of teams
               ofstream & file_writer - reference to ofstream object
 * Pre-conditions: string option was generated as "1" or "2"
 * Post-conditions: none
 ***********************************************/
void display_top(Team * team_list, int team_num, ofstream &file_writer);

/**************************************************
 * Name: display_top_console()
 * Description: Use a for loop to iterate through each index
                in allocated Team * array and print name of each
                team. Use a nested for loop to iterate through each 
                index in allocated Player * array and save the highest value
                of PPG as a temp variable. Use another nested for loop to 
                iterate through the Player * array and print all players who
                have the highest PPG into the console. 
 * Parameters: Team * team_list - pointer to the team_array
               int team_num - int of number of teams
 * Pre-conditions: none
 * Post-conditions:  prints top scorer of each team to console
 ***********************************************/
void display_top_console(Team * team_list, int team_num);

/**************************************************
 * Name: display_top_ofstream()
 * Description: Call get_filename() and open that files using ofstream object.
                Use a for loop to iterate through each index
                in allocated Team * array and print name of each
                team. Use a nested for loop to iterate through each 
                index in allocated Player * array and save the highest value
                of PPG as a temp variable. Use another nested for loop to 
                iterate through the Player * array and print all players who
                have the highest PPG into the file.
 * Parameters: Team * team_list - pointer to the team_array
               int team_num - int of number of teams
               ofstream & file_writer - reference to ofstream object
 * Pre-conditions: none
 * Post-conditions: prints top scorer of each team to file
 ***********************************************/
void display_top_ofstream(Team * team_list, int team_num, ofstream &file_writer);

/**************************************************
 * Name: search_nationality()
 * Description: Depending on input generated from console_file(),
               call either search_nationality_console() or 
               search_nationality_ofstream()
 * Parameters: Team * team_list - pointer to the team_array
               int team_num - int of number of teams
               ofstream & file_writer - reference to ofstream object
 * Pre-conditions: string option was generated as "1" or "2"
 * Post-conditions: none
 ***********************************************/
void search_nationality(Team * team_list, int team_num, ofstream &file_writer);

/**************************************************
 * Name: search_nationality_console()
 * Description: Take input for nationality. Use a for loop to iterate
               through each index in allocated Team * array, and a nested
               for loop to interate through each indes in allocated Player * array.
               Compare the inputted nationality to the member variable of the Player*
               struct. If it matches, print out player name and age to the console.
 * Parameters: Team * team_list - pointer to the team_array
               int team_num - int of number of teams
 * Pre-conditions: none
 * Post-conditions: prints player name and age of corresponding 
                   naitonality to console
 ***********************************************/
void search_nationality_console(Team * team_list, int team_num);

/**************************************************
 * Name: search_nationality_ofstream()
 * Description: Call get_filename() and open that files using ofstream object.
               Take input for nationality. Use a for loop to iterate
               through each index in allocated Team * array, and a nested
               for loop to interate through each indes in allocated Player * array.
               Compare the inputted nationality to the member variable of the Player*
               struct. If it matches, print out player name and age to the console.
 * Parameters: Team * team_list - pointer to the team_array
               int team_num - int of number of teams
               ofstream & file_writer - reference to ofstream object
 * Pre-conditions: none
 * Post-conditions: prints player name and age of corresponding 
                   naitonality to file
 ***********************************************/
void search_nationality_ofstream(Team * team_list, int team_num, ofstream &file_writer);

/**************************************************
 * Name: create_teams()
 * Description: This function will dynamically allocate
                an array of teams (of the requested size)
 * Parameters: int - size of the array
 * Pre-conditions: none
 * Post-conditions: a Team array of requested size is created and return
 ***********************************************/
Team* create_teams(int team_num);


/**************************************************
 * Name: populate_team_data()
 * Description: This function will fill a single team struct 
                with information that is read in from the file
 * Parameters:  Team* - pointer to the Team array
                int - index of the Team in the array to be filled 
                ifstream& - input file to get information from
 * Pre-conditions: Team array has been allocated; 
                   provided index is less than the array size
 * Post-conditions: a Team at provided index is populated
 ***********************************************/
void populate_team_data(Team* team_list, int team_num, ifstream &file_reader); 


/**************************************************
 * Name: create_players()
 * Description: This function will dynamically allocate
                an array of players (of the requested size)
 * Parameters: int - size of the array
 * Pre-conditions: none
 * Post-conditions: a Player array of requested size is created and return
 ***********************************************/
Player* create_players(int player_num);


/**************************************************
 * Name: populate_player_data()
 * Description: This function will fill a single player struct 
                with information that is read in from the file
 * Parameters:  Player* - pointer to the Player array
                int - index of the Player in the array to be filled 
                ifstream& - input file to get information from
 * Pre-conditions: Player array has been allocated; 
                   provided index is less than the array size
 * Post-conditions: a Player at provided index is populated
 ***********************************************/
void populate_player_data(Player* player_list, int player_num, ifstream &file_reader); 


/**************************************************
 * Name: delete_info()
 * Description: This function will  delete all the memory that was dynamically allocated
 * Parameters: Team* - the Team array
 * Pre-conditions: the provided Team array hasn't been freed yet
 * Post-conditions: the Team array, with all Players inside, is freed
 ***********************************************/
void delete_info(Team* team_list, int team_num);
