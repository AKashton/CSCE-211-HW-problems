#include "Movie.h"

//default constructor 
Movie::Movie()
{
	name = "no name";
	rating = "no rating";
}

//constructor passes name and rating of movie.
Movie::Movie(string newname, string newrating)
{
	name = newname;
	rating = newrating;
}

//returns the name of the movie
string Movie::getName()
{
	return name;
}

//returns the rating of the movie
string Movie::getRating()
{
	return rating;
}
