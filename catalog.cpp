#include "catalog.h"

using namespace std;

void clear_buffer(){
	cin.clear();
	cin.ignore(1000000, '\n');
}

//function definitions go here
string get_filename(){
  cout << "What file are you accessing" << endl;
  string name;
  cin >> name;
  return name;
}

//function to open the file
int read_file(string filename, ifstream &file_reader){
  file_reader.open(filename);
  string word;
  file_reader >> word;
  return stoi(word);
}

void get_option(Team *team_list, int team_num, ofstream &file_writer){
	string option_choice = "";
	do {
		cout << endl;
		cout << "Which option would you like to choose (1, 2, 3, 4)" << endl;
		cout << "1. Search players by team name." << endl;
		cout << "2. Display top scorers of each team." << endl;
		cout << "3. Search players by nationality." << endl;
		cout << "4. Sort teams by total PPG." << endl;
		cout << "5. Quit." << endl;
		cout << endl;
		clear_buffer();
		cin >> option_choice;
		//error checking
		while (option_choice != "1" && option_choice != "2" && option_choice != "3" && option_choice != "4" && option_choice != "5"){
			cout << "This input is invalid, please retry." << endl;
			clear_buffer();
			cin >> option_choice;
		}

		if (option_choice == "1"){
			cout << "Search players by team name." << endl;
			search_player(team_list, team_num, file_writer);
		}
		else if (option_choice == "2"){
			cout << "Display top scorers of each team." << endl;
			display_top(team_list, team_num, file_writer);
		}
		else if (option_choice == "3"){
			cout << "Search player by nationality." << endl;
			search_nationality(team_list, team_num, file_writer);
		}
		else if (option_choice == "4"){
			cout << "Sort teams by total PPG." << endl;
			cout << "not finished yet lol." << endl;
		}
	} while (option_choice != "5");
}

string console_file(){
	cout << endl;
	cout << "would you like to print to console or a file." << endl;
	cout << "1: Console" << endl << "2. File" << endl;
	string option = "";
	clear_buffer();
	cin >> option;
	while (option != "1" && option != "2"){
		cout << "This input is invalid, please retry." << endl;
		clear_buffer();
		cin >> option;
	}
	return option;	
}

void search_player(Team * team_list, int team_num, ofstream &file_writer){
	string option = console_file();
	if (option == "1"){
		search_player_console(team_list, team_num);
	}
	else if (option == "2"){
		search_player_ofstream(team_list, team_num, file_writer);
	}
}

void search_player_console(Team * team_list, int team_num){
	string name;
	cout << endl;
	cout << "Please input a team name" << endl;
	clear_buffer();
	cin >> name;
	for (int i = 0; i < team_num; i++){
		if (team_list[i].name.compare(name) == 0){
			cout << endl;
			cout << "Team Name: " << team_list[i].name << endl;
			cout << "Owner: " << team_list[i].owner << endl;
			cout << "Market Value: " << team_list[i].market_value << endl;
			cout << "# of Players: " << team_list[i].num_player << endl;
			for (int j = 0; j < team_list[i].num_player; j++){
				cout << endl;
				cout << "Name: " << team_list[i].p[j].name << endl;
				cout << "Age: " << team_list[i].p[j].age << endl;
				cout << "Nation: " << team_list[i].p[j].nation << endl;
				cout << "PPG: " << team_list[i].p[j].ppg << endl;
				cout << "FG: " << team_list[i].p[j].fg << endl;
			}	
		}
	}
}

void search_player_ofstream(Team * team_list, int team_num, ofstream &file_writer){
	string filename = get_filename();
	file_writer.open(filename);
	string name = "";
	cout << endl;
	cout << "Please input a team name" << endl;
	clear_buffer();
	cin >> name;
	for (int i = 0; i < team_num; i++){
		if (team_list[i].name.compare(name) == 0){
			file_writer << endl;
			file_writer << "Team Name: " << team_list[i].name << endl;
			file_writer << "Owner: " << team_list[i].owner << endl;
			file_writer << "Market Value: " << team_list[i].market_value << endl;
			file_writer << "# of Players: " << team_list[i].num_player << endl;
			for (int j = 0; j < team_list[i].num_player; j++){
				file_writer << endl;
				file_writer << "Name: " << team_list[i].p[j].name << endl;
				file_writer << "Age: " << team_list[i].p[j].age << endl;
				file_writer << "Nation: " << team_list[i].p[j].nation << endl;
				file_writer << "PPG: " << team_list[i].p[j].ppg << endl;
				file_writer << "FG: " << team_list[i].p[j].fg << endl;
			}	
		}
	}
	file_writer.close();
}

void display_top(Team * team_list, int team_num, ofstream &file_writer){
	string option = console_file();
	if (option == "1"){
		display_top_console(team_list, team_num);
	}
	else if (option == "2"){
		display_top_ofstream(team_list, team_num, file_writer);
	}
}

void display_top_console(Team * team_list, int team_num){
	for (int i = 0; i < team_num; i++){
		cout << endl;
		cout << "Team: " << team_list[i].name << endl;
		float max = 0;
		for (int j = 0; j < team_list[i].num_player; j++){
			if (team_list[i].p[j].ppg > max){
				max = team_list[i].p[j].ppg;
			}
		}
		for (int j = 0; j < team_list[i].num_player; j++){
			if (team_list[i].p[j].ppg == max){
				cout << "Name: " << team_list[i].p[j].name << endl;
				cout << "PPG: " << team_list[i].p[j].ppg << endl;
			}
		}
	}
}

void display_top_ofstream(Team * team_list, int team_num, ofstream &file_writer){
	string filename = get_filename();
	file_writer.open(filename);
	for (int i = 0; i < team_num; i++){
		file_writer << endl;
		file_writer << "Team: " << team_list[i].name << endl;
		float max = 0;
		for (int j = 0; j < team_list[i].num_player; j++){
			if (team_list[i].p[j].ppg > max){
				max = team_list[i].p[j].ppg;
			}
		}
		for (int j = 0; j < team_list[i].num_player; j++){
			if (team_list[i].p[j].ppg == max){
				file_writer << "Name: " << team_list[i].p[j].name << endl;
				file_writer << "PPG: " << team_list[i].p[j].ppg << endl;
			}
		}
	}
}

void search_nationality(Team * team_list, int team_num, ofstream &file_writer){
	string option = console_file();
	if (option == "1"){
		search_nationality_console(team_list, team_num);
	}
	else if (option == "2"){
		search_nationality_ofstream(team_list, team_num, file_writer);
	}
}

void search_nationality_console(Team * team_list, int team_num){
	string nation = "";
	cout << endl;
	cout << "Please input a nationality" << endl;
	clear_buffer();
	cin >> nation;
	for (int i = 0; i < team_num; i++){
		for (int j = 0; j < team_list[i].num_player; j++){
			if (team_list[i].p[j].nation.compare(nation) == 0){
				cout << endl;
				cout << "Name: " << team_list[i].p[j].name << endl;
				cout << "Age: " << team_list[i].p[j].age << endl;
			}
		}
	}
}

void search_nationality_ofstream(Team * team_list, int team_num, ofstream &file_writer){
	string filename = get_filename();
	file_writer.open(filename);
	string nation = "";
	cout << endl;
	cout << "Please input a nationality" << endl;
	clear_buffer();
	cin >> nation;
	for (int i = 0; i < team_num; i++){
		for (int j = 0; j < team_list[i].num_player; j++){
			if (team_list[i].p[j].nation.compare(nation) == 0){
				file_writer << endl;
				file_writer << "Name: " << team_list[i].p[j].name << endl;
				file_writer << "Age: " << team_list[i].p[j].age << endl;
			}
		}
	}
	file_writer.close();
}

Team* create_teams(int team_num){
	Team* teamslist = new Team[team_num];
	return teamslist;
}

void populate_team_data(Team * team_list, int team_num, ifstream &file_reader){
	for (int i = 0; i < team_num; i++){
		file_reader >> team_list[i].name >> team_list[i].owner >> 
			team_list[i].market_value >> team_list[i].num_player;
		team_list[i].p = create_players(team_list[i].num_player);
		populate_player_data(team_list[i].p, team_list[i].num_player, file_reader);
	}
}

Player* create_players(int player_num){
	Player* playerslist = new Player[player_num];
	return playerslist;

}
void populate_player_data(Player * player_list, int player_num, ifstream &file_reader){
	for (int i = 0; i < player_num; i++){
		file_reader >> player_list[i].name >> player_list[i].age >>
			player_list[i].nation >> player_list[i].ppg >>
			player_list[i].fg;
	}
}

void delete_info(Team * team_list, int team_num){
	for (int i = 0; i < team_num; i++){
		delete [] team_list[i].p; 
	}
	delete [] team_list;
}
