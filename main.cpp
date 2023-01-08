#include "Store.h"

using namespace std;

int main() {
    Customer mehmetcan(1, "Mehmetcan", "Bozkuş", 17, Gender::MALE, 500);
    std::unordered_map<Movie, bool, MyHashFunction> customerRentedMovies = mehmetcan.getCustomerRentedMovies();

    Store store;

    Movie TDK("tt0468569", "The Dark Knight", "Christopher Nolan", Date(18, 7, 2008),
              165, Genre::ACTION, Rating::G, 19.99);
    Movie AvengersEG("tt4154796", "Avengers: Endgame", "Anthony Russo", Date(26, 4, 2019),
                     181, Genre::ACTION, Rating::PG, 18.99);
    Movie AvengersIW("tt4154756", "Avengers: Infinity War", "Anthony Russo", Date(27, 4, 2018),
                     149, Genre::ACTION, Rating::R, 19.99);
    

    store.addMovie(TDK, 3);
    store.addMovie(AvengersIW, 10);
    store.addMovie(AvengersEG, 5);

    store.removeMovie(AvengersIW);

    store.rentMovie(mehmetcan, TDK);
    store.rentMovie(mehmetcan, AvengersEG);
    store.rentMovie(mehmetcan, AvengersIW);

    store.refundMovie(mehmetcan, AvengersEG);


    cout << "Customer Actively Rented Movies: " << endl;
    mehmetcan.printCustomerActivelyRentedMovies();

    cout << "Customer Earlier Rented Movies: " << endl;
    mehmetcan.printCustomerEarlierRentedMovies();

    store.printStore();


    return 0;
}
