#ifndef  TABLE_DB_H
#define TABLE_DB_H

#include "FileIO.h"
#include "person.h"
#include "HashTable.h"
#include "List.h"
#include "binary_search_tree.h"
#include "Movie.h"
#include "Actor.h"
#include "stack.h"

class NotIMDB_Database
{
	
private:
	// movie titles & actor names are keys for accessing the table
	HashTable<Movie*>					__movieDB;
	Stack<Movie*>*						__deletedMovies;
	// ------------------------------------------
	// Internal Helper Method Section
	// ------------------------------------------
	void								__loadMovies(List<Movie>* movies);
	/* requires that the movies have been loaded to further map a movie to an actor via
	the list of Movie* stored in an actor value */
	void								__clear();
public:
	int									__binarySearch_byMovieName(List<std::string>* moviesSortedByID,
													int l, int r, std::string targetString) const;
	
	// ------------------------------------------
	// Constructor & Destructor Section
	// ------------------------------------------
	NotIMDB_Database()  {
		__deletedMovies = new Stack<Movie*>();
	}
	virtual ~NotIMDB_Database();
	// ------------------------------------------
	// Create/FileIO Section
	// ------------------------------------------
	bool  				loadFromFile(std::string path);
	// save to a default path or a custom path/name
	void  				saveToFile(string path = "data//output.tsv");

	// ------------------------------------------
	// Delete Section
	// ------------------------------------------
	// add the deleted movie to the stack
	bool				deleteMovie(std::string key);
	// ------------------------------------------
	// Update Section
	// ------------------------------------------
	// find movie by oldName, hold a copy of the movie delete movie of old name, update copy to newName, finally 
	// add back into table
	bool				updateMovieName(std::string oldMovieName, std::string newMovieName);
	bool				updateMovieYear(std::string key, std::string newYearReleased);
	bool				updateMovieID(std::string key, std::string newID);
	bool				updateMovieRuntime(std::string key, std::string newRuntime);
	// op 0 appends to the genre string, op 1 sets the genre to newGenreName
	bool				updateMovieGenre(std::string key, std::string newGenreName, int op);
	bool 				updateMovieRating(std::string key, std::string newKey);

	
	// ------------------------------------------
	// Search Section
	// ------------------------------------------
	/* Verify movie and actor existence */
	/* can either verify via BST or movieDB */
	bool  				foundMovie(std::string movieName) const;
	bool				searchByGenre(std::string genre, std::string movieName) const;
	bool				foundMovie(int genreIndex);
	/* verify using actorDB */

	// ------------------------------------------
	// Read Section
	// ------------------------------------------
	void  				displayMovieTableStats() const;
	bool				readMovie(std::string key) const;

};

#endif // ! TABLE_DB_H
