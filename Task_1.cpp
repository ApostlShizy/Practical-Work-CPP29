#include <iostream>

class Talent {
public :
    virtual void heCan() = 0;
};

class Swimming : virtual public Talent {
public:
    virtual void heCan() {
        std::cout << " he can swimming ";
    }
};

class Dancing : virtual public Talent {
public:
    virtual void heCan() {
        std::cout << " he can daincing ";
    }
};

class Counting : virtual public Talent {
public:
    virtual void heCan() {
        std::cout << " he can counting ";
    }
};

class Dog {
    std::string name = "none";
    Talent** hisTalents = nullptr;

    Talent* getTalent(int i) {
        if (hisTalents[i] == nullptr) return nullptr;
        else return hisTalents[i];
    }

public:
    Dog() {
        hisTalents = new Talent * [3];
        char choice;
        std::cout << "\nEnter dog name : ";
        std::cin >> name;
        std::cout << "\nHe can swimm (y/n) ? : ";
        std::cin >> choice;
        if (choice == 'y') {
            hisTalents[0] = new Swimming();
        }
        else {
            hisTalents[0] = nullptr;
        }
        std::cout << "\nHe can danc (y/n) ? : ";
        std::cin >> choice;
        if (choice == 'y') {
            hisTalents[1] = new Dancing();
        }
        else {
            hisTalents[1] = nullptr;
        }
        std::cout << "\nHe can count (y/n) ? : ";
        std::cin >> choice;
        if (choice == 'y') {
            hisTalents[2] = new Counting();
        }
        else {
            hisTalents[2] = nullptr;
        }
    }

    void showHisTalents() {
        std::cout << "Dog name " << name << " can : ";
        for (int i = 0; i < 3; ++i) {
            if (getTalent(i) != nullptr) getTalent(i)->heCan();
        }
    }
};

int main()
{
    Dog first;
    first.showHisTalents();
}