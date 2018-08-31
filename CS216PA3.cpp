/* CS216-003
** By: Eric Chheang
** Project 3
** main.cpp file 
*/


#include <iostream>
#include <fstream>
#include <cstdlib>
#include "term.h"
#include "SortingList.h"
#include "autocomplete.h"
using namespace std;

// most of these codes taken from Dr Pikes, Lab12.cpp (with permission)
int main(int argc, char ** argv) {
    Autocomplete Auto;
    
    long weight;
    string query;
    
    ifstream infile(argv[1]);
    
    if (argc == 3) {		//just loads the file 
        if (!infile.fail()) {		
            
			char ch;
            while (infile >> weight) {
                infile.ignore(); // ignore space between weight and query
                getline(infile, query);
                Term term(query, weight);
                Auto.insert(term);
            }
            infile.close();

			int maxprint = atoi(argv[2]);
            
            string prefix;
            cout << "Please input the search query(type \"exit\" to quit): "<< endl;
            getline(cin, prefix);

			while (prefix != "exit"){

                SortingList<Term> matchedTerms = Auto.allMatches(prefix); 
                Term toMatch (prefix, 0);

				if (matchedTerms.size() == 0) {
					cout << "No matched query !\n";
				}
				else {


	for (int i = 1; i < matchedTerms.size(); i++) {
		for (int j = 0; j < matchedTerms.size() - 1; j++) {
			if (Term::compareByWeight(matchedTerms[i], matchedTerms[j]) > 0) {
				swap(matchedTerms[i], matchedTerms[j]);
							}
						}
					}
	for (int k = 0 ; k < matchedTerms.size() && k < maxprint  ; k ++){
		cout << matchedTerms[k] << endl;
					}
				}//asks user for search query and option to exit
		cout << "Please input the search query(type \"exit\" to quit): "<< endl;
		getline (cin, prefix);
			}
        }
        else {
            cout << "failed to open " << argv[1] << endl;
        }

	}		//Will print out fail to open if file doesnt match
	
    else {
        cout << "Usage: " << argv[0] << " <file name>" << endl;
    }
	return 0;
}
