#include <string>

#include "Date.h"

using namespace std;


enum class Genre {
    ACTION,
    ADVENTURE,
    ANIMATION,
    COMEDY,
    CRIME,
    DRAMA,
    FAMILY,
    FANTASY,
    HISTORY,
    HORROR,
    MYSTERY,
    ROMANCE,
    SCI_FI,
    SPORT,
    THRILLER,
    WAR,
};

enum class Rating {
    G, PG, R,
};

class Movie {
private:
    string IMDB_ID;
    string Title;
    string Director;
    Date ReleaseDate;
    int Duration;
    Genre genre;

    Rating rating;

    bool IsRented;
    double Price;

public:
    Movie() {};

    ~Movie() {};


    Movie(const string &imdbId, const string &title, const string &director, const Date &releaseDate,
          int duration, Genre g, Rating rating, double price) {
        IMDB_ID = imdbId;
        Title = title;
        Director = director;
        ReleaseDate = releaseDate;
        Duration = duration;
        genre = g;
        rating = rating;
        IsRented = false;
        Price = price;
    }


    void printMovie() {
        cout << "IMDB ID: " << IMDB_ID << endl;
        cout << "Title: " << Title << endl;
        cout << "Director: " << Director << endl;
        cout << "Release Date: " << ReleaseDate.dateToString() << endl;
        cout << "Duration: " << Duration << endl;
        cout << "Genre: " << getGenreString() << endl;
        cout << "Rating: " << getRatingString() << endl;
        cout << "Price: " << "$" << Price << endl;
    }

    Movie &operator=(const Movie &other) {
        IMDB_ID = other.IMDB_ID;
        Title = other.Title;
        Director = other.Director;
        ReleaseDate = other.ReleaseDate;
        Duration = other.Duration;
        genre = other.genre;
        rating = other.rating;
        Price = other.Price;
        return *this;
    }

    bool operator==(const Movie &movie) const {
        return IMDB_ID == movie.IMDB_ID;
    }

    string getImdbId() const {
        return IMDB_ID;
    }

    void setImdbId(const string &id) {
        IMDB_ID = id;
    }

    string getTitle() const {
        return Title;
    }

    void setTitle(const string &t) {
        Title = t;
    }

    string getDirector() const {
        return Director;
    }

    void setDirector(const string &d) {
        Director = d;
    }

    Date getReleaseDate() {
        return ReleaseDate;
    }

    void setReleaseDate(const Date &d) {
        ReleaseDate = d;
    }

    int getDuration() const {
        return Duration;
    }

    void setDuration(int d) {
        Duration = d;
    }

    Genre getGenre() {
        return genre;
    }

    string getGenreString() {
        string genreString;
        if (genre == Genre::ACTION) {
            genreString = "Action";
        } else if (genre == Genre::ADVENTURE) {
            genreString = "Adventure";
        } else if (genre == Genre::ANIMATION) {
            genreString = "Animation";
        } else if (genre == Genre::COMEDY) {
            genreString = "Comedy";
        } else if (genre == Genre::CRIME) {
            genreString = "Crime";
        } else if (genre == Genre::DRAMA) {
            genreString = "Drama";
        } else if (genre == Genre::FAMILY) {
            genreString = "Family";
        } else if (genre == Genre::FANTASY) {
            genreString = "Fantasy";
        } else if (genre == Genre::HISTORY) {
            genreString = "History";
        } else if (genre == Genre::HORROR) {
            genreString = "Horror";
        } else if (genre == Genre::MYSTERY) {
            genreString = "Mystery";
        } else if (genre == Genre::ROMANCE) {
            genreString = "Romance";
        } else if (genre == Genre::SCI_FI) {
            genreString = "Sci-Fi";
        } else if (genre == Genre::SPORT) {
            genreString = "Sport";
        } else if (genre == Genre::THRILLER) {
            genreString = "Thriller";
        } else if (genre == Genre::WAR) {
            genreString = "War";
        }
        return genreString;
    }

    void setGenre(Genre g) {
        genre = g;
    }

    Rating getRating() {
        return rating;
    }

    string getRatingString() {
        string ratingString;
        if (rating == Rating::G) {
            ratingString = "G";
        } else if (rating == Rating::PG) {
            ratingString = "PG";
        } else if (rating == Rating::R) {
            ratingString = "R";
        }
        return ratingString;
    }

    void setRating(Rating r) {
        rating = r;
    }

    bool getIsRented() {
        return IsRented;
    }

    void setIsRented(bool r) {
        IsRented = r;
    }

    double getPrice() const {
        return Price;
    }

    void setPrice(double p) {
        Price = p;
    }


};




