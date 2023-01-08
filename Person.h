#include <string>
#include <iostream>

using namespace std;

enum class Gender {
    MALE, FEMALE
};

class Person {
private:
    int ID;
    string Name;
    string Surname;
    int Age;

    Gender gender;

public:
    Person() {};

    ~Person() {};

    Person(int id, const string &name, const string &surname, int age, Gender g) {
        ID = id;
        Name = name;
        Surname = surname;
        Age = age;
        gender = g;
    }

    void printPerson() {
        cout << "ID: " << ID << endl;
        cout << "Name: " << Name << endl;
        cout << "Surname: " << Surname << endl;
        cout << "Age: " << Age << endl;
        cout << "Gender: " << getGenderString(gender) << endl;
    }


    int getId() const {
        return ID;
    }

    void setId(int i) {
        ID = i;
    }

    string getName() {
        return Name;
    }

    void setName(const string& n) {
        Name = n;
    }

    string getSurname() {
        return Surname;
    }

    void setSurname(const string& s) {
        Name = s;
    }

    int getAge() const {
        return Age;
    }

    void setAge(int a) {
        Age = a;
    }

    Gender getGender() {
        return gender;
    }

    void setGender(Gender g) {
        gender = g;
    }

    static string getGenderString(Gender g) {
        string genderString;
        if (g == Gender::MALE) {
            genderString = "Male";
        } else if (g == Gender::FEMALE) {
            genderString = "Female";
        }
        return genderString;
    }


};


