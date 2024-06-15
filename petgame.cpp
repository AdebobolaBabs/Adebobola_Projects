#include<iostream>
using namespace std;

class pet{
    public:
      int health;//health is 0-100
      int hunger;//hunger is 0-10, 0 being not hungry and 10 being starving
      int trained;//how much the dog is trained, 0-100
      int tired;//how tired the dog is from 0-10, with 10 being very tired
      string name;//takes the name of the pet user
      string species;//takes the species of the pet from the user
      string color;//takes the color of the pet from the user
      pet();//constructor
      string set_species();//will ask the user for what species they want
      string set_color();//will ask the user for what color they want
      void print();//prints the pet information
      pair<int, int> feed();//feed function that lowers hunger and increases health
      pair<int, int> train();//train function that increases hunger and increases trained
      pair<int, int> nap();//nap function that increases hunger and reduces tired
      pair<int, int> walk();//walk function that increases hunger and increase tired
      pair<int, int> rand1();//random event 1
      pair<int, int> rand2();//random event 2
      pair<int, int> rand3();//random event 3
};


int main(){
    pet petA;
    int ask;
    int test;
    
    while(test == 0 && petA.health > 0){
        
        petA.print();
        cout << "What do you want to do: " << endl;
        cout << "1. Feed Pet\n2. Train Pet\n3. Nap Pet\n4. Walk Pet\n5. Exit\n(Enter a number)" << endl;
        cin >> ask;

        switch (ask)
        {
        case 1:
            petA.feed();
            break;
        case 2:
            petA.train();
            break;
        case 3:
            petA.nap();
            break;
        case 4:
            petA.walk();
            break;
        case 5:
            test = 1;
            break;
        
        default:
            cout << "Wrong Input!" << endl;
            break;
        }
    srand(static_cast<unsigned int>(time(nullptr)));
    int roll = (rand() % 4) + 1;

    if(roll == 1){
        petA.rand1();
    }else if(roll == 2){
        petA.rand2();
    }else if(roll == 3){
        petA.rand3();
    }else{
        break;
    }

      
    }
    petA.print();
    cout << "Game Over" << endl;


}


pet::pet(){
    health = 100;
    hunger = 10;
    trained = 0;
    tired = 5;
    cout << "What is the name of your pet: ";
    cin >> name;
    set_species();//calling the set species function
    set_color();//calling the set color function

}

string pet::set_species(){
    int req;//an int for the user to input to select species
    cout << "These are the species available for your pet: " << endl;
    cout << "1. Dog\n2. Cat\n3. Bird\n4. Fish\n5. Rabbit" << endl;
    cout << "What species do you want your pet to be (Input a number): ";
    cin >> req;
    if(req == 1){
        species = "Dog";
    }else if(req == 2){
        species = "Cat";
    }else if(req == 3){
        species = "Bird";
    }else if(req == 4){
        species = "Fish";
    }else if(req == 5){
        species = "Rabbit";
    }else{
        species = "None";
    }
    return species;
}


void pet::print(){
    cout << "Name: " << name << endl;
    cout << "Species: " << species << endl;
    cout << "Color: " << color << endl;
    cout << "Health: " << health << endl;
    cout << "Hunger: " << hunger << endl;
    cout << "Training: " << trained << "%" << endl;
    cout << "Tired: " << tired << endl;
}

string pet::set_color(){
    int reqc;//an int for the user to input to select color
    cout << "These are the color available for your pet: " << endl;
    cout << "1. White\n2. Black\n3. Brown\n4. Tabby\n5. Ginger" << endl;
    cout << "What color do you want your pet to be (Input a number): ";
    cin >> reqc;
    if(reqc == 1){
        color = "White";
    }else if(reqc == 2){
        color = "Black";
    }else if(reqc == 3){
        color = "Brown";
    }else if(reqc == 4){
        color = "Tabby";
    }else if(reqc == 5){
        color = "Ginger";
    }else{
        color = "Black";
    }
    return color;
}

pair<int, int> pet::feed(){
    health = 100;
    cout << "Feeding pet (Enter 1 to continue): ";
    int en;
    cin >> en;
    if(en == 1){
        if(hunger >= 0 && hunger <=5){
        hunger = 0;
    }else{
        hunger -= 5;
    }
    }else{
        return make_pair(health, hunger);
    }

    return make_pair(health, hunger);
}


pair<int, int> pet::train(){
    if(hunger <= 7){
        hunger += 3;
    }else{
        hunger = 10;
    }

    cout << "What training do you want to do: \n";
    cout << "1. Basic Obedience Training\n2. House Training\n3. Socializing Training\n4. Agility Training\n5. Trick Training" << endl;
    int en;
    cin >> en;
    while(en >= 1 && en <= 5){
        en += 5;
        if(trained >= 0 && trained <=90){
        trained += 10;
        }else{
            trained = 100;

        }
    }

    return make_pair(hunger, trained);
}


pair<int, int> pet::nap(){
    if(hunger <= 7){
        hunger += 3;
    }else{
        hunger = 10;
    }
    cout << "Pet is napping (Enter 1 to continue): ";
    int en;
    cin >> en;
    if(en == 1){
        if(tired >= 2 && tired <=10){
        tired -= 2;
    }else{
        tired = 0;
    }
    }else{
        return make_pair(hunger, tired);
    }

    return make_pair(hunger, tired);
}


pair<int, int> pet::walk(){
    if(hunger <= 7){
        hunger += 3;
    }else{
        hunger = 10;
    }
    cout << "Walking pet (Enter 1 to continue): ";
    int en;
    cin >> en;
    if(en == 1){
        if(tired >= 0 && tired <=8){
        tired += 2;
    }else{
        tired = 10;
    }
    }else{
        return make_pair(hunger, tired);
    }

    return make_pair(hunger, tired);
}

pair<int, int> pet::rand1(){
    cout << "Your " << species << " ran away and came back after 5 hours" << endl;
    if(health >= 20){
        health -= 20;
    }else{
        health = 0;
    }
    
    if(hunger <= 7){
        hunger += 3;
    }else{
        hunger = 10;
    }
    return make_pair(health, hunger);

}


pair<int, int> pet::rand2(){
    cout << "Your " << species << " stepped on a nail outside\nYou treated the injury" << endl;
    if(health >= 10){
        health -= 10;
    }else{
        health = 0;
    }

    if(hunger <= 7){
        hunger += 3;
    }else{
        hunger = 10;
    }
    return make_pair(health, hunger);

}


pair<int, int> pet::rand3(){
    cout << "You left the " << species << " food out and your " << species << " ate a lot" << endl;
    if(health <= 80){
        health += 20;
    }else{
        health = 100;
    }
    
    if(hunger >= 3){
        hunger -= 3;
    }else{
        hunger = 0;
    }
    return make_pair(health, hunger);

}
