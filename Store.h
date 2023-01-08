#include "Customer.h"

#include <unordered_map>


class Store {
private:
    double Balance;
    std::unordered_map<Movie, int, MyHashFunction> StoreMovieList;

public:
    Store() {
        Balance = 0;
    }

    ~Store() {};

    void printMovieList() {
        // print all movies in the store
        for (auto &movie: StoreMovieList) {
            std::cout << movie.first.getTitle() << ", Stock: " << movie.second << std::endl;
        }
    }

    void addMovie(const Movie &movie, int quantity) {
        // If movie is already in the store, increase the quantity by 1
        if (StoreMovieList.find(movie) != StoreMovieList.end()) {
            std::cout << "Movie is already in the store. Increasing the quantity by 1" << std::endl;
            StoreMovieList[movie] += 1;
        } else {
            // add movie to the store
            StoreMovieList[movie] = quantity;
        }
    }

    void removeMovie(const Movie &movie) {
        // if movie is in the store, remove it
        if (StoreMovieList.find(movie) != StoreMovieList.end()) {
            StoreMovieList.erase(movie);
            std::cout << "Movie is removed from the store" << std::endl;
        } else {
            std::cout << "Movie is not in the store" << std::endl;
        }
    }

    void refundMovie(Customer &customer, Movie &movie) {
        if (customer.getCustomerRentedMovies().find(movie) != customer.getCustomerRentedMovies().end()) {
            // if movie is in the customer rented movies, refund it
            customer.changeMovieRentStatus(movie, false);
            Balance -= movie.getPrice() * 0.25;
            customer.setBalance(customer.getBalance() + movie.getPrice() * 0.25);
            StoreMovieList[movie] += 1;
            std::cout << "Movie is refunded" << std::endl;
        } else {
            std::cout << "Movie is not in the customer rented movies" << std::endl;
        }
    }


    void rentMovie(Customer &customer, Movie &movie) {
        if (StoreMovieList.find(movie) == StoreMovieList.end()) {
            std::cout << "This movie is not available in the store." << std::endl;
            return;
        }
        if (customer.getBalance() < movie.getPrice()) {
            std::cout << "You do not have sufficient balance to rent this movie." << std::endl;
            return;
        }
        if (customer.getRentLimit() <= customer.getRentedMovieCount()) {
            std::cout << "You have reached your rent limit." << std::endl;
            return;
        }
        if (customer.getCustomerRentedMovies().find(movie) != customer.getCustomerRentedMovies().end()) {
            std::cout << "You have already rented this movie." << std::endl;
            return;
        }
        if (!isMovieAppropriateForCustomer(customer, movie)) {
            std::cout << "This movie is not appropriate for your age." << std::endl;
            return;
        }
        // decrease the quantity of the movie by 1
        StoreMovieList[movie] -= 1;
        // add movie to the customer rented movies
        customer.getCustomerRentedMovies()[movie] = true;
        // increase the balance of the store
        Balance += movie.getPrice();
        // decrease the balance of the customer
        customer.setBalance(customer.getBalance() - movie.getPrice());
        std::cout << "Movie is rented" << std::endl;
        // increase the rented movie count of the customer
        customer.setRentedMovieCount(customer.getRentedMovieCount() + 1);
    }


    static bool isMovieAppropriateForCustomer(Customer &customer, Movie &movie) {
        bool b;

        Rating movieRating = movie.getRating();
        int customerAge = customer.getAge();

        if (movieRating == Rating::G) {
            b = true;
        } else if (movieRating == Rating::PG && customerAge >= 13) {
            b = true;
        } else if (movieRating == Rating::R && customerAge >= 17) {
            b = true;
        } else {
            b = false;
        }
        return b;
    }

    void printStore() {
        std::cout << "Store Balance: " << Balance << std::endl;
        std::cout << "Store Movies: " << std::endl;
        printMovieList();
    }

    double getBalance() const {
        return Balance;
    }

    void setBalance(double b) {
        Balance = b;
    }

    std::unordered_map<Movie, int, MyHashFunction> &getMovieList() {
        return StoreMovieList;
    }

    void setMovieList(const std::unordered_map<Movie, int, MyHashFunction> &movieList) {
        StoreMovieList = movieList;
    }

};