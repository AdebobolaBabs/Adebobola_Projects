/*
Adebobola Babs-Ogunleye
CS120
Assignment 5
*/
#include<iostream>
#include<cstdlib>
#include<ctime>
// I changed the distance from 5 miles to 3 miles after 
//running the program the first time because the game was too long
using namespace std;
int start();
int event_1();
int event_2();
int event_3();
int event_4();
int event_5();
int event_6();
int water = 10;
int reask();
double dis = 3.25;//distance
int health = 100;
int roll;//for each roll
int animal;
int fruity;
int visited;
int visited1;

int main(){
     dis -= 0.25;
     start();
     while(dis > 0 && water > 0){
	cout << "You have " << water << " bottles of water.\n";
	cout << dis << " miles left.\n";
	cout << health << " health.\n\n\n";
	cout << "Press spacebar then enter to roll your next move." << endl;
	while (true) {
            // Check if the Enter key was pressed
            if (cin.get() != '\n') {
                break; // Exit the loop if Enter is pressed
            }
	}
	srand(static_cast<unsigned int>(time(nullptr)));
	roll = (rand() % 6) + 1;
	cout << "You rolled " << roll << endl;
    if (health <= 0){
        cout << "You took a nap." << endl;
	health = 100;
	}


	switch(roll){
	    case 0:
	        reask();
	        break;
	    case 1:
    	        event_1();
    	        break;
	    case 2:
    	        event_2();
    	        break;
	    case 3:
    	        event_3();
    	        break;
	    case 4:
    	        event_4();
    	        break;
	    case 5:
    	        event_5();
    	        break;
	    case 6:
    	        event_6();
    	        break;
	    default:
		cout << "Room not found.\n";
	}
    }
    if(water <= 0){
        cout << "You lose.\nYou ran out of water." << endl;
    }
    else{
    cout << "Congratulations, you escaped with " << water << " bottles of water";
    }
}

int reask(){
	cout << "You have " << water << " bottles of water.\n";
	cout << dis << " miles left.\n";
	cout << health << " health.\n\n\n";
	cout << "Press spacebar then enter to roll your next move." << endl;
	while (true) {
            // Check if the Enter key was pressed
            if (cin.get() != '\n') {
                break; // Exit the loop if Enter is pressed
            }
	}
	srand(static_cast<unsigned int>(time(nullptr)));
	roll = (rand() % 6) + 1;
	cout << "You rolled " << roll << " ." << endl;
    if (health <= 0){
        cout << "You took a nap." << endl;
	health = 100;
	}
    if(roll == 1){
        return 1;
        }
    if(roll == 2){
        return 2;
        }
    if(roll == 3){
        return 3;
        }
    if(roll == 4){
        return 4;
        }
    if(roll == 5){
        return 5;
        }
    if(roll == 6){
        return 6;
        }
        return 0; // if something went wrong, stay in this room, room 0.

}


int start(){
    cout << "You are in a forest\n";
    cout << "It seems like the nearest safehouse is " << dis << " miles away";
    cout << " and you have only 10 bottles of water\n";
    cout << "Roll a 6-sided dice for a random event to occur\n";
    cout << "Try to make it out without running out of water\n";
    cout << "Your health reduces over time due to fatigue\n";
    return 0;
}






int event_1(){
    visited1 += 1;
    cout << "You see a wild animal in the distance" << endl;
    cout << "What do you do?\nEnter 1 to Go closer or 2 to avoid the animal./n" << endl;
    cin >> animal;

    if(visited1 = 1){
        if(animal == 1){
	    cout << "You go closer.\nThe animal is a bear.\nIt seems the bear hates water.\nYou splash some water on the bear and it runs away.\n";
	    water -= 1;
            dis -= 0.1;
	    health -= 10;
	    return 0;
	}
        if(animal == 2){
            cout << "You avoid the animal and keep going." << endl;
            dis -= 0.25;
	    health -= 5;
            return 0;
        }
    }
    if(visited1 = 2){
        if(animal == 1){
	    cout << "You go closer.\nThe animal is another bear.\nIt seems the bear hates water.\nYou splash some water on the bear but it tries to attack.\nYou narrowly escape";
	    water -= 1;
            dis -= 0.1;
	    health -= 30;
	    return 0;
	}
        if(animal == 2){
            cout << "You avoid the animal and keep going." << endl;
            dis -= 0.25;
	    health -= 5;
            return 0;
        }
    }
    if(visited1 > 2){
        if(animal == 1){
	    cout << "You go closer.\nThe animal is a bear.\nIt seems the bear hates water.\nYou splash some water on the bear and it runs away.\n";
	    water -= 1;
            dis -= 0.1;
	    health -= 10;
	    return 0;
	}
        if(animal == 2){
            cout << "You avoid the animal and keep going." << endl;
            dis -= 0.25;
	    health -= 5;
            return 0;
        }
    }
    return 0;
}

int event_2(){
    cout << "A sudden rainstorm hits the jungle, you have the chance to collect rainwater." << endl;
    cout << "You collect up to 2 bottles of water and purified.\nAfter purification, you got 1 bottle of clean water." <<endl;
    water += 1;
    dis -= 0.1;
    health -= 5;
    return 0;
}


int event_3(){
    cout << "You discover an unusual fruit tree." << endl;
    cout << "Eating the fruit could quench your thirst, but it might also have side effects." << endl;
    cout << "Choose wisely" << endl;
    cout << "Enter 1 to eat or 2 to keep going./n" << endl;
    cin >> fruity;
    if(fruity == 1){
	cout << "You ate the fruit.\nIt quenched your thirst\n";
        dis -= 0.2;
	health -= 5;
	return 0;
    }
    if(fruity == 2){
	cout << "You leave the fruit and drink a bottle of your water to quench your thirst." << endl;
	dis -= 0.25;
        water -= 1;
        health -= 5;
        return 0;
    }
    return 0;
}


int event_4(){
    visited += 1;
    if(visited == 1){
        cout << "You come across a hidden oasis along a riverbank." << endl;
        cout << "It is a great opportunity to refill your water bottles." << endl;
        cout << "Accessing it may require some effort, and there might be a surprise waiting for you" << endl;
	int oasis;
        cout << "What do you do.\nEnter 1 to get water from the oasis.\nEnter 2 to ignore and keep going." << endl;
	cin >> oasis;

	if(oasis == 1){
	    cout << "You enter the oasis.\nAfter getting 1 bottle of water you see a shortcut out of the jungle and take it." << endl;
	    dis -= 1;
	    water += 1;
	    health -= 5;
	    return 0;
	}

	if(oasis == 2){
	    cout << "You ignore the oasis and keep walking." << endl;
	    water -= 1;
	    dis -= 0.5;
	    health -= 10;
	    return 0;
	}
     return 0;
    }

    if(visited > 1){
        cout << "You come across another oasis along a riverbank." << endl;
        cout << "It is a great opportunity to refill your water bottles." << endl;
        cout << "Accessing it may require some effort, and there might be a surprise waiting for you" << endl;
	int oasis;
        cout << "What do you do.\nEnter 1 to get water from the oasis.\nEnter 2 to ignore and keep going." << endl;
	cin >> oasis;

	if(oasis == 1){
	    cout << "You enter the oasis.\nYou get your water and continue on your journey" << endl;
	    dis -= 0.5;
	    water += 1;
	    health -= 10;
	    return 0;
	}

	if(oasis == 2){
	    cout << "You ignore the oasis and keep walking." << endl;
	    water -= 1;
	    dis -= 0.5;
	    health -= 10;
	    return 0;
	}
    }
    return 0;
}
int event_5(){
    cout << "You lose your way in the dense jungle and spend some time trying to find the right direction." << endl;
    cout << "You are finally on track but you drank 2 bottles of water/n" << endl;
    water -= 2;
    dis += 1;
    health -= 5;
    return 0;
}


int event_6(){
    cout << "You encounter an area with rugged and difficult terrain.\n" << endl;
    cout << "You cross it safely but used up a lot of energy and had to drink a bottle of water.\n" << endl;
    water -= 1;
    dis -= 0.25;
    health -= 20;

    return 0;
}
