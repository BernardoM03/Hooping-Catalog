#include "catalog.h"

using namespace std;

int main()
{
	//declare ifstream/ofstrem objects
	ofstream file_writer;
	ifstream file_reader;

	//read the filename for number of teams
	string filename = get_filename();
	int team_num = read_file(filename, file_reader);

	//create team and player arrays
	Team *team_list = create_teams(team_num);
	populate_team_data(team_list, team_num, file_reader);

	get_option(team_list, team_num, file_writer);
	delete_info(team_list, team_num);
}
