/* CS216-003
** Author Eric Chheang
** Project 3
** header file for term
*/

#include "term.h"

// default constructor
Term :: Term(){
    query = "";
    weight = 0;
    
}

// initializes a term with the given query string and weight
Term :: Term(string query1, long weight1){
    query = query1;
    weight = weight1;
    
}

string Term :: getQuery() const {
	return query;
}

// compares the two terms in descending order by weight
// if the order of T1 and T2 in descending order by weight, return 1;
// if T1 and T2 are of the same weight, return 0;
// otherwise return -1
int Term :: compareByWeight(Term T1, Term T2){
    if (T1.weight > T2.weight) return 1;            // check this one; is it < or > ?
    else if (T2.weight == T1.weight) return 0;
    else return -1;
}

// compares the two terms in lexicographic order but using only the first r characters of each query
int Term :: compareByPrefix(Term T1, Term T2, int r){
#if 1
    return (T1.query.substr(0, r).compare(T2.query.substr(0, r)));
#else
    
   
   
#endif
}

int Term :: compareByQuery(Term t1, Term t2) {
	return t1.query.compare(t2.query);
}

// operator overloading for operators "<" and "<<"
// they are defined as friend functions

// define the operator "<" for Term class
bool operator<(Term T1, Term T2){
	if ( T1.query == T2.query ) {
		return T1.weight < T2.weight;
	}
	else {
		return T1.query < T2.query;
	}
}

// define the operator "<<" for Term class
// to send the Term object to the cout, in the following format:
// the weight, followed by a tab key, followed by the query
ostream& operator<<(ostream &out, const Term& t){                
    out << t.weight << "\t" << t.query;
    return out;
    
    
}

