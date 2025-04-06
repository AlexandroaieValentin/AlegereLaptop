#ifndef REVIEW_H
#define REVIEW_H

#include <string>
#include <iostream>
using namespace std;

class Review {
private:
    int rating;
    string comment;

public:
    Review(int rating, const string &comment);

    int getRating() const;
    string getComment() const;
    void afiseazaReview() const;
};

#endif // REVIEW_H
