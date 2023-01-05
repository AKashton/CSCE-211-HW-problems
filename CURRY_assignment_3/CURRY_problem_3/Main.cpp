/////////////////////////////////////////////////////////////////// 
// CSCE A211
// Ashton Curry
// Due Date: 11/8/22
// Assignment #3 Problem 3: Array of classes
// Purpose: sort an array of classes alphabetically
///////////////////////////////////////////////////////////////////
#include "Movie.h"

/*****************************************************************
* Name: swap
* Description: Swaps two objects in the movie array
* Inputs: two pointers going to the objects to be swapped in the movie class array
* Returned value: Nothing is returned, but the objects in the array have swapped places.
*****************************************************************/
void swap(Movie *a, Movie *b)
{
	Movie temp = *a;
	*a = *b;
	*b = temp;
}

/*****************************************************************
* Name: movieSort
* Description: Sorts the Movie class array to alphabetical order
* Inputs: an array of type Movie, and a number representing the number of objects in the array.
* Returned value: Nothing returned, although the order of the array will change.
*****************************************************************/
void movieSort(Movie arr[], int nummovies)
{
	for (int i = 0; i < nummovies - 1; i++)
	{
		int indexOfMin = i;
		for (int j = i + 1; j < nummovies; j++)
		{
			//define two strings to compare from both movie classes
			//also get the length of the shortest string to compare
			string str1 = arr[j].name;
			string str2 = arr[indexOfMin].name;


			int strlength;
			//assigns comparison length to shortest string.
			if (str1.size() < str2.size())
			{
				strlength = str1.size();
			}
			else
			{
				strlength = str2.size();
			}
			//compares each character of the string, the smallest value character is 
			//colsest to the beggining of alphabet, so is assigned to index of min. 
			for (int k = 0; k < strlength; k++)
			{
				if (tolower(str1[k]) < tolower(str2[k]))
				{
					indexOfMin = j;
					break;
				}
				 //just breaks loop if comparison of both strings shows that they are in order
				//in respect to eachother
				else if (tolower(str1[k]) > tolower(str2[k]))
				{
					break;
				}
					
			}
		}
		swap(arr[i], arr[indexOfMin]);
	}
}

int main()
{
	Movie moviearr[6];
	Movie movie0("Black Panther", "PG - 13");
	Movie movie1("Avengers: Infinity War", "PG - 13");
	Movie movie2("A Wrinkle In Time", "PG");
	Movie movie3("Ready Player One", "PG - 13");
	Movie movie4("Red Sparrow", "R");
	Movie movie5("The Incredibles", "G");

	moviearr[0] = movie0;
	moviearr[1] = movie1;
	moviearr[2] = movie2;
	moviearr[3] = movie3;
	moviearr[4] = movie4;
	moviearr[5] = movie5;
	
	//sorts the movie object array alphabetically
	movieSort(moviearr, 6);
	//prints out movies in alphabetical order
	for (int i = 0; i < 6; i++)
	{
		cout << moviearr[i].getName() << " " << moviearr[i].getRating() << endl;
	}
	return 0;
}