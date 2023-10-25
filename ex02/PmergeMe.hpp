
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <exception>
#include <algorithm>
#include <ctime>
#include <iomanip>

typedef struct num {
    int n;
    std::vector<int> idx;
    bool operator<(const num& other) const {
        return n < other.n;
    }
} num;

class PmergeMe {
    private :
        std::vector<num> myVec;
        std::vector<num> vecNum;
        std::vector<num>    finalVec;
        std::vector<num>    save;
        // std::list<std::pair<int, int> > myList;
        // int last;
    public :
        PmergeMe ();
        PmergeMe ( PmergeMe &src );
        PmergeMe &operator= ( PmergeMe &src );
        ~PmergeMe();
        // void    fillVec( int n1, int n2 );
        // void    fillList( int n1, int n2 );
        void    fordVec( std::vector<num> &vec );
        // std::list<int>      fordList();
        void    parseFill( int ac, char **av );
};

#endif