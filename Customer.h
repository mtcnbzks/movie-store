#include "Person.h"
#include "Movie.h"

#include <unordered_map>

class MyHashFunction {
public:
    double operator()(const Movie &movie) const {
        return (movie.getPrice());
    }
};

class Customer : public Person {
private:
    std::unordered_map<Movie, bool, MyHashFunction> CustomerRentedMovies;
    double Balance;
    int RentLimit;
    int RentedMovieCount = 0;

public:
    Customer() {};

    ~Customer() {};

    Customer(int id, const string &name, const string &surname, int age, Gender gender, double balance) :
            Person(id, name, surname, age, gender) {
        if (age < 15) {
            RentLimit = 1;
            Balance = 34.99;
        } else if (age < 18 && age > 15) {
            RentLimit = 2;
            Balance = balance;
        } else {
            RentLimit = 5;
            Balance = balance;
        }
    }


    void printCustomer() {
        printPerson();
        std::cout << "Balance: " << "$" << Balance << std::endl;
    }

    void printCustomerActivelyRentedMovies() {
        for (auto &movie: CustomerRentedMovies) {
            if (movie.second == 1) {
                std::cout << movie.first.getTitle() << std::endl;
            }
        }
    }


    void printCustomerEarlierRentedMovies() {
        for (auto &movie: CustomerRentedMovies) {
            if (movie.second == 0) {
                std::cout << movie.first.getTitle() << std::endl;
            }
        }
    }

    void changeMovieRentStatus(Movie &movie, bool status) {
        if (CustomerRentedMovies.find(movie) != CustomerRentedMovies.end()) {
            CustomerRentedMovies[movie] = status;
        } else {
            std::cout << "Movie is not rented by customer." << std::endl;
        }
    }


    double getBalance() const {
        return Balance;
    }

    void setBalance(double b) {
        Balance = b;
    }

    int getRentLimit() const {
        return RentLimit;
    }

    void setRentLimit(int r) {
        RentLimit = r;
    }

    int getRentedMovieCount() const {
        return RentedMovieCount;
    }

    void setRentedMovieCount(int r) {
        RentedMovieCount = r;
    }

    std::unordered_map<Movie, bool, MyHashFunction> &getCustomerRentedMovies() {
        return CustomerRentedMovies;
    }

    void setCustomerRentedMovies(const std::unordered_map<Movie, bool, MyHashFunction> &customerRentedMovies) {
        CustomerRentedMovies = customerRentedMovies;
    }


};