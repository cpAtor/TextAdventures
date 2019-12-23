#include<iostream>
#include<vector>
using namespace std;
typedef enum direction {East,West,North,South} direction;
typedef enum actions {Turn,Run} actions;
typedef struct position{
    int x;
    int y;
} coordinates;

class Player{
    private:
        coordinates position;
        direction lookingTowards;
        string message;
    void turnTowards(direction dir)
    {
        lookingTowards = dir;
        message = "I am looking towards " + dir;
    }

    bool moveForward(int distance)
    {
        switch(lookingTowards)
        {
            case direction::East:
                position.x += distance;
                break;
            case direction::West:
                position.x -= distance;
                break;
            case direction::North:
                position.y += distance;
                break;
            case direction::South:
                position.y -= distance;
                break;
        }
        message = "I moved to ( " + position.x + ', ' + position.y + ' ).'; 
       return true;
    }

    direction convertToDirection(string parameter)
    {
        if(parameter.compare("East") == 0)
            return direction::East;
        else if(parameter.compare("West") == 0)
            return direction::West;
        else if(parameter.compare("North") == 0)
            return direction::North;
        else if(parameter.compare("South") == 0)
            return direction::South;
        throw new exception();
        return direction::East;
    }

    actions convertToAction(string action)
    {
        if(action.compare("Turn")==0)
            return actions::Turn;
        else if(action.compare("Run")==0)
            return actions::Run;
        throw new exception();
        return actions::Run;
    }

    public:

    Player(int x = 0, int y = 0, direction dir = direction::East)
    {
        position.x = x;
        position.y = y;
        lookingTowards = dir;
    }


    bool performAction(string action , string parameter)
    {
        actions act = convertToAction(action);
        switch(act)
        {
            case actions::Turn:
            {
                direction dir = convertToDirection(parameter);
                turnTowards(dir);
                return true;
                break;
            } 
            case actions::Run:
            {
                int distance = stoi(parameter);
                moveForward(distance);
                return moveForward(distance);;
                break;
            }
        }
        return false;
    }

    string getPlayerMessage()
    {
        return message;
    }
};