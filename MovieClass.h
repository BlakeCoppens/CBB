#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>
#include <cstdlib>

using namespace std;

class Movie {
private:
    string name;
    string genre;
    int year;
    float rating;

public:
    // Constructor
    Movie(const string& name, const string& genre, int year, float rating)
        : name(name), genre(genre), year(year), rating(roundf(rating * 100) / 100) {}

    // Getters
    string getName() const { return name; }
    string getGenre() const { return genre; }
    int getYear() const { return year; }
    float getRating() const { return rating; }

    // Static method to round a float to two decimals
    static float roundToTwoDecimals(float value) {
        return std::round(value * 100) / 100;
    }

    // Static method to generate 100,000 random movies
    static vector<Movie> generateRandom() {
        vector<string> genres = {
            "Action", "Comedy", "Drama", "Horror", "Sci-Fi", "Fantasy", "Romance", "Thriller",
            "Adventure", "Documentary", "Animation", "Crime", "Mystery", "Musical", "Biography",
            "Family", "Sport", "War", "Western", "History"
        };

        vector<Movie> movieList;
        movieList.reserve(100000);

        srand(static_cast<unsigned>(time(0)));

        for (int i = 0; i < 100000; i++) {
            // Generate random data
            string title = "Movie" + to_string(i);
            string genre = genres[rand() % genres.size()];
            int year = 1900 + rand() % 125;
            float rating = roundToTwoDecimals(static_cast<float>(rand() % 501) / 100.0);

            movieList.emplace_back(title, genre, year, rating);
        }

        return movieList;
    }
};






