#include <iostream>
#include <vector>
using namespace std;

class Player {
    // Attributes
    string name;
    int health;
    int xp;
    int *cash;

    public :
    // Methods

    // CONST -- Explicitely telling the compiler that this method will not change the object attribute
    void getter () const {
        cout << "Your player name is : " << name << endl;
        cout << "Your health is :" << health << endl;
        cout << "Your xp is :" << xp << endl;
        cout << "Your cash is :" << *cash << endl;
    }

    // Methods implemented outside the Class
    void first_aid (int health);
    void increase_xp (int n);
    void add_cash (int n);
    
    // Constructor with default parameters
    Player (string n = "", int h = 0, int x = 0, int mon = 0) 
    : name{n}, health{h}, xp{x} {
        cash = new int;
        *cash = mon;
    }
    

    // Destructor
    ~Player() {
        delete cash;
        cout << "Destructor is called!" << endl;
    }

    // Deep Copy constructor
    Player(const Player &source) 
    :Player{source.name, source.health, source.xp, *source.cash} {
        cout << "Copy Constructor is called!" << endl;
    }

    // Move constructor
    Player(Player &&source) 
    :Player{source.name, source.health, source.xp, *source.cash} {
        source.cash = nullptr;
        cout << "Move Constructor is Called" << endl;
    }

};

int main() {
    Player Muskan{"Musku", 10, 20, 1000};
    Muskan.getter();
    cout << endl;

    Muskan.first_aid(20);
    Muskan.increase_xp(2);
    Muskan.add_cash(1000);
    Muskan.getter();
    cout << endl;

    Player Reva{Muskan};
    Reva.getter();
    cout << endl;

    vector<Player>vec;
    vec.push_back(Player("BRUH"));
    // vec.push_back(Player("BRUHmeme"));
    // vec.push_back(Player("BRUHland"));
    // vec.push_back(Player("BRUHbuub"));
    cout << endl;

    Player *Animesh = new Player{"ONU", 100, 100, 50000};
    Animesh->getter();
    cout << endl;

}

void Player::first_aid (int health) {
    this->health += health;
    // cout << "Current health : " << health << endl;
}  

void Player::increase_xp (int n) {
    xp += n;
    // cout << "Current XP : " << xp << endl;
}
void Player::add_cash (int n) {
    *cash += n;
    // cout << "Current Balance : $" << cash << endl;
}