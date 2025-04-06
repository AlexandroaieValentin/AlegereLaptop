#include "Review.h"
using namespace std;

Review::Review(int rating, const string &comment)
    : rating(rating), comment(comment) {}

int Review::getRating() const {
    return rating;
}

string Review::getComment() const {
    return comment;
}

void Review::afiseazaReview() const {
    cout << "Rating: " << rating << "/5" << "\n";
    cout << "Comentariu: " << comment << "\n";
}
