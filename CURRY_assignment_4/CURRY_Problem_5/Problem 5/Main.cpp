/******************************************
* Ashton Curry
* Assignment 4 problem 5: Movie Maven
* Due: 12/8/22
* This Program demonstrates the use of STL map and vectors by mapping a movie list to ratings. 
******************************************/

#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	ifstream movies;
	//ways to store numbers and titles
	int numbers;
	string titles;

	//store the integer vectors for each movie
	vector<int> movie_ratings[4];
	map<string, vector<int>> Movielist; // map with string that maps to a vector of ratings 
	
	//values listed
	Movielist["Black Panther"] = movie_ratings[0];
	Movielist["Ready Player One"] = movie_ratings[1];
	Movielist["Red Sparrow"] = movie_ratings[2];
	Movielist["A Wrinkle In Time"] = movie_ratings[3];

	movies.open("movies.txt"); // opens file
	if (!movies.is_open()) // checker to ensure file was open
	{
		cout << "Could not open file movies.txt." << endl;
		return 1;
	}
	while (getline(movies, titles)) //iterates through each line, comparing movie titles, and if found, storing the rating below the titles.
	{
		if (titles == "A Wrinkle In Time")
		{
			movies >> numbers;
			movie_ratings[0].push_back(numbers);
		}
		if (titles == "Black Panther")
		{
			movies >> numbers;
			movie_ratings[1].push_back(numbers);
		}
		if (titles == "Ready Player One")
		{
			movies >> numbers;
			movie_ratings[2].push_back(numbers);
		}
		if (titles == "Red Sparrow")
		{
			movies >> numbers;
			movie_ratings[3].push_back(numbers);
		}
	}
	movies.close();

	float averages[4] = { 0.0 }; //stores averages for each movie, with an array of 4 (4 movies)
	for (int i = 0; i < 4; i++)
	{
		for (int j : movie_ratings[i])
		{
			averages[i] += j; //adds all elements from vector in movie to averages
		}
		averages[i] /= movie_ratings[i].size(); //divides by size of vector, which would be how to obtain average.
	}
	int i = 0; // iterator to rotate through averages and vectors
	for (auto Movielists : Movielist)
	{
		cout << setprecision(2) << Movielists.first << ": " << movie_ratings[i].size() << " reviews, average of "
			<< averages[i] << " / 5" << endl;
		i++;
	}
}