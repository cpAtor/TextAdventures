#include<iostream>
#include "player.h"
using namespace std;

void executeCommand(string);
vector<string> splitCommand(string);
Player player(0,0,direction::East);
int main(){
    while (true)
    {
        string command;
        cout << "What do you want me to do?" << endl;
        getline(cin, command);
        executeCommand(command);
    }
    
    return 0;
}
void executeCommand(string command){
    vector<string> cmd = splitCommand(command);
    if(cmd.size() != 2)
    {
        cout << "Sorry, the command is invalid." << endl;
    }
    else
    {
        player.performAction(cmd[0],cmd[1]);
        cout << player.getPlayerMessage() << endl;
    }
    
}

vector<string> splitCommand(string command)
{
    vector<string> cmd;
    string word;
    for(auto x : command)
    {
        if(x == ' ')
        {
            cmd.push_back(word);
            word = "";
        }
        else
        {
            word = word + x;
        }        
    }
    cmd.push_back(word);
    return cmd;
}