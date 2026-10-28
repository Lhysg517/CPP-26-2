
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Movie {
public:
    string name;
    double rating;

    Movie(string n, double r) {
        name = n;
        rating = r;
    }
};

int main()
{
    vector<Movie> movies;

    movies.push_back(Movie("titinic", 9.9));
    movies.push_back(Movie("gone with the wind", 9.6));
    movies.push_back(Movie("terminator", 9.7));

    for (int i = 0; i < movies.size(); i++) {
        cout << movies[i].name << ": "
             << movies[i].rating << endl;
    }

    return 0;
}
