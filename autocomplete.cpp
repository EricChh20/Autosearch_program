/* CS216-003
** By: Eric Chheang
** Project 3
** cpp file for autcomplete
*/

#include <string>
#include "SortingList.h"
#include "term.h"
#include "autocomplete.h"

using namespace std;

// insert the newterm to the sequence
void Autocomplete :: insert(Term newterm){
    terms.insert(newterm);

}

// return all terms whose queries match the given prefix, // in descending order by weight
SortingList<Term> Autocomplete :: allMatches(string prefix){
    // create a SortingList object named matchedTerms to store the prefix-match terms
    SortingList<Term> matchedTerms;
    
	terms.sort();
			   //this would be implementing the binary search

    int left = 0, right = 0;
    search(prefix, left, right);


    if (left != -1) {
        for (int i = left; i <= right; i++) {
            matchedTerms.insert(terms[i]);
        }
		//returns the matched terms
    }
    
    return matchedTerms;
}

// first: the index of the first query whose prefix matches // the search key, or -1 if no such key
// last: the index of the last query whose prefix matches // the search key, or -1 if no such key
// key: the given prefix to match
void Autocomplete :: search(string key, int& first, int& last){
    Term toMatch (key, 0);
    int startIndex = binary_search(key);
    if (startIndex != -1) {
        first = startIndex;
        last = startIndex;
        
        while (first >= 0 && Term::compareByPrefix(terms[first], toMatch, key.length()) == 0) {
            first--;
        }
        first++;
        while (last < terms.size() && Term::compareByPrefix(terms[last], toMatch, key.length()) == 0) {
            last++;
        }
        last--;
    }
    else {
        first = -1;
        last = -1;
    }
}

// return the index number of the term whose query
// prefix-matches the given prefix, using binary search algorithm // Note that binary search can only be applied to sorted sequence
// Note that you may want a binary search helper function
int Autocomplete :: binary_search(string prefix){                      
	int mid, start = 0, end = terms.size() - 1, temp = prefix.length();
    string tempString;

	mid = (start + end) / 2;	//this will take the total length
			// and devide by 2, to find the mid 
	while (start != mid && mid != end && tempString != prefix) {
        tempString = terms[mid].getQuery().substr(0,temp);
        
		if (tempString == prefix) {
			return mid;
			//index = mid;
		}
		
		else if (tempString > prefix){
			end = mid;
		}
		//these if/elses will allow us to find the mid
			//depending on what the prefix is		
		else if (tempString < prefix){
			start = mid;
		}
		mid = (start + end) / 2;
	}
    return -1;
}

// display all the terms
void Autocomplete :: print() {
	terms.print();
}
