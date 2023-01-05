// This class stores movie names and ratings
//

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Movie
{
private:
	string name;
	string rating;

	//friend function used to sort the movies to alphabetical order
	friend void movieSort(Movie arr[], int nummovies);

	//swaps the array of classes
	friend void swap(Movie* a, Movie* b);

	

public:
	//defualt constructor, fills in "no name" for name and "no rating" for rating.
	Movie();
	//contstructor that takes the name and rating of a movie.
	Movie(string newname, string newrating);
	//getters to retrieve the name and rating of the movies.
	string getName();
	string getRating();
};

