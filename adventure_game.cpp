/*
Adebobola Babs-Ogunleye
Assignment 4: Adventure Game
CS120
*/


#include<iostream>
using namespace std;

int start_room();
int room1();
int room2();
int room3();
int room4();
int room5();
int room6();
int visited = 0;
int visited5 = 0;
int health = 100;
int hours = 20;
int reask();
int dead();

int main(){
    int room = 0; // 0 is the first room

    while(hours > 0 && health > 0){
	hours--;
	cout << "Your health is " << health << ".\n";
	cout << "You have " << hours << " hours left to escape.\n\n";
	switch(room){
	    case 0:
		room = start_room();
		break;
	    case 1:
		room = room1();
		break;
	    case 2:
		room = room2();
		break;
	    case 3:
		room = room3();
		break;
	    case 4:
		room = room4();
		break;
	    case 5:
		room = room5();
		break;
	    case 6:
		room = room6();
		break;
	    case 7:
		room = reask();
		break;
	    case 8:
		room = dead();
		break;
	    case 9:
		break;
	    default:
		cout << "Room not found.\n";
		}
	}
	if(health <= 0){//if they dies
	    cout << "You died.\n" << endl;
	}
	else{//if they survive for the full time
	cout << "Congratulations,emergency rescue comes to save you, you escaped with " << health;
	cout << " health.\n\n";
	}
    }


int start_room(){//Starting room function
    int choice = 0;
    cout << "They almost caught up with you.";
    cout << "That was a close call, ";
    cout << "but running into an abandoned building was probably not the best idea.\n";
    cout << "The door shuts behind you.It's so dark\n";
    cout << "You turn on the lights and there are about 13 dead bodies around the room.\n";
    cout << "There are 6 doors.\nTry not to die before the timer runs out\n";
    cout << "Door 1 looks like there is a light coming from under the door.\nIt could be a trap\n";
    do{
	cout << "Where do you want to go?\nEnter a door number from 1-6 ";
	cin >> choice;
    }while (choice < 1 || choice > 6);
    if(choice == 1){
	return 1;
	}
    if(choice == 2){
	return 2;
	}
    if(choice == 3){
	return 3;
	}
    if(choice == 4){
	return 4;
	}
    if(choice == 5){
	return 5;
	}
    if(choice == 6){
	return 6;
	}
	return 0; // if something went wrong, stay in this room, room 0.
    }

int reask(){
    int choice = 0;
    do{
	cout << "Where do you want to go?\nEnter a door number from 1-6 ";
	cin >> choice;
    }while (choice < 1 || choice > 6);
    if(choice == 1){
	return 1;
	}
    if(choice == 2){
	return 2;
	}
    if(choice == 3){
	return 3;
	}
    if(choice == 4){
	return 4;
	}
    if(choice == 5){
	return 5;
	}
    if(choice == 6){
	return 6;
	}
	return 0; // if something went wrong, stay in this room, room 0.

}

//----------------------Room Functions----------------------------
 int room1(){//room1 function
	visited += 1;
	cout << "You entered room one\n";
	if(visited == 1){
	    cout << "There is a metotrophite, a harmful snake from a neighboring planet.\nThe snake tries to attack you but you narrowly escape with a bite.\n\n\n";
	    health = health - 30; // reduced health
	    return 7;
	}
	if(visited == 2){
	    cout << "They snake is waiting at the door, as soon as you open the door, it strikes and hits a vital spot.\n";
	    cout << "The snake lets go because too much human blood is poisonous to the snake.\n\n\n";
            health = health - 20;//a second snake bite
	    visited = 2;
	    return 7;
	}
	if(visited == 3){
	    cout << "They snake is weak from taking too much blood.\nYou eat the snake and regain some health.\n\n\n";
	    if( health >= 80){;//regain some health
	    health = 100;
	    }
	    if(health < 80){
	    health += 20;
	    }
	    visited += 1;
	    return 7; // Automatically returns to room1, needs a choice

	}
	if(visited > 3){
	    cout << "You walk into room 1 again and the room is empty\n\n\n";
	    return 7;//if you go back to the room it's empty
	}
	return 7;
    }

    int room2(){ //Room2 function
	int app = 5;
	int app_req;
	cout << "You entered room 2.\n";
	cout << "The room is empty, there are " << app << " apples on the floor.\n";
	cout << "Do you eat one or go back?\n";
	cout << "Enter 1 to eat or 2 to go back ";
	cin >> app_req;
	if(app_req == 1){
	    cout << "Oh no! It's a poison apple\n\n\n";
	    health = health - 10;
	    return 7;
	}
	if(app_req == 2){
		return 7;
	}
	return 7;
    }

   int dead(){
	health = 0;
	cout << "Game Over, you died" << endl;
	return 9;
    }

    int room3(){ //Room3 function
	int pea_req;
	cout << "You entered room 3.\n";
	cout << "Room 3 is empty but you found a peanut.\n";
	cout << "Do you eat one or go back?\n";
	cout << "Enter 1 to eat or 2 to go back ";
	cin >> pea_req;
	if(pea_req == 1){
	    cout << "Oh no! It's a bad peanut\n\n\n";
	    health = health - 10;
	    return 7;
	}
	if(pea_req == 2){
		return 7;
	}
	return 7;
    }


int room4(){
     cout << "You entered room 4\n";
     cout << "The room is empty but it's safe\n\n\n";
     return 7;
	}

int room5(){
    visited5 += 1;
    if(visited5 == 1){
        cout << "You entered room 5.\n";
        cout << "There is a scorpion in the room.\n";
        cout << "You try to run out but it catches you on the heel but you make it out\n\n\n";
        health = health - 10;
	return 7;
	}
    if(visited5 == 2){
        cout << "You entered room 5.\n";
        cout << "Your old friend Jack the Scorpion is waiting for you.\n";
        cout << "He strikes you again, and its in deep this time.\nYou smash its head on the wall and quickly run out\n\n\n";
        health = health - 20;
	return 7;
	}
    if(visited5 >= 3){
        cout << "You entered room 5.\n";
        cout << "The scorpion is dead.\n";
        return 7;
	}

        return 7;
}

int room6(){
    cout << "You entered room 6.\n";
    cout << "Room 6 is a healing room\n";
    cout << "You gained some health\n\n\n";
    health = 100;
    return 7;
}
