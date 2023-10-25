
#include "PmergeMe.hpp"

// Const/Dest --- CopyConst/CopyAssign

void parsInt ( std::string str )
{
    for ( int i = 0 ; str[i] ; i++ )
        if ( !isdigit( str[i] ) )
            throw std::logic_error("Error : bad input");
}

// void    PmergeMe::fillVec ( int n1, int n2 )
// {
//     if ( n1 < n2 )
//         myVec.push_back(std::make_pair(n1, n2));
//     else
//         myVec.push_back(std::make_pair(n2, n1));
// }

// void    PmergeMe::fillList ( int n1, int n2 )
// {
//     if ( n1 < n2 )
//         myList.push_back(std::make_pair(n1,n2));
//     else
//         myList.push_back(std::make_pair(n2,n1));
// }

void    printCont( std::vector<int> &g )
{
    std::vector<int>::iterator it = g.begin();
    for ( ; it != g.end() ; it++ )
        std::cout << *it << "   ";
    std::cout << std::endl;
}

void print( std::vector<num> &g )
{
    std::vector<num>::iterator it = g.begin();
    for ( ; it != g.end() ; it++ ) 
    {
        std::cout << "int first : " << it->n << "   idxs first : ";
        printCont(it->idx);
        std::cout << "_________________________" << std::endl;
    }
}

void    printVecpairs( std::vector<std::pair<num, num> > &g )
{
    std::vector<std::pair<num, num> >::iterator it = g.begin();
    for ( ; it != g.end() ; it++ )
    {
        std::cout << "[" << it->first.n << ", " << it->second.n << "]";
    }
    std::cout << std::endl;
}

void    PmergeMe::parseFill( int ac, char **av )
{
    int j = ac;
    if ( ac % 2 != 0 )
        j = ac - 1;
    int d = 0;
    for ( int i = 1 ; i < j ; i+=2 )
    {
        parsInt( av[i] );
        parsInt( av[i + 1] );
        num n1;
        n1.n = std::stoi( av[i] );
        n1.idx.push_back(d);
        num n2;
        n2.n = std::stoi( av[i + 1]);
        n2.idx.push_back(d);
        myVec.push_back(n2);
        myVec.push_back(n1);
        // if ( s == "vec" )
        //     fillVec( n1, n2 );
        // else if ( s == "list" )
        //     fillList( n1, n2 );
        d++;
    }
    num g;
    if ( ac % 2 != 0 )
    {
        parsInt( av[ac] );
        g.n = std::stoi( av[ac] );
        // g.idx.push_back( ac / 2 );
        // last = std::stoi( av[ac] ); 
    }
    else
    {
        g.n = -1;
    }

    // else
    //     last = -1;
    fordVec(myVec);
    if ( g.n != -1 )
    {
        std::vector<num>::iterator u = std::lower_bound( finalVec.begin(), finalVec.end(), g );
        finalVec.insert(u, g);
    }
    print(finalVec);
    // recurse retour 
}

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe ( PmergeMe &src ) { *this = src; }
PmergeMe &PmergeMe::operator= ( PmergeMe &src )
{
    this->myVec = src.myVec;
    // this->myList = src.myList;
    // this->last = src.last;
    return *this;
}

/*  Vector   */
void    PmergeMe::fordVec ( std::vector<num> &vec )
{
    // print( vec );
    // (void)vec;
    // print(vec);
    if(vec.size() == 1)
    {
        vec[0].idx.pop_back();
        finalVec.push_back(vec[0]);
        return;
    }
    int d = 0;
    std::vector<std::pair<num, num> > vecPairs;
    std::vector<num> big;
    // std::vector<num>::iterator it = vec.begin();
    
    for ( size_t i = 0 ; i + 1 < vec.size() ; i+=2 )
    {
        
        if ( vec[i].n > vec[i + 1].n )
        {
            vec[i].idx.push_back(d);
            big.push_back(vec[i]);
            vecPairs.push_back(std::make_pair(vec[i], vec[i + 1]));
        }
        else
        {
            vec[i + 1].idx.push_back(d);
            big.push_back(vec[i + 1]);
            vecPairs.push_back(std::make_pair( vec[i + 1], vec[i] ));
        }
        
        // std::cout << vec[i].n << " -----------------------its d : " << d << std::endl;
        //std::cout <<
        
        // std::cout << vec[i + 1].n << " ---------------------its d : " << d << std::endl;
        //if(d == i / 2)
        d = i / 2 - d;
    }
    num last;
    if ( vec.size() % 2 != 0 )
    {
        last = vec[vec.size() - 1];
        last.idx.pop_back();
    }
    else
    {
        last.n = -1;
    }
    std::cout << "last n : " << last.n <<  std::endl;
        // save.push_back( vec[vec.size() - 1] );
    std::cout << "***********************************************************************************" << std::endl;
    fordVec(big);
    printVecpairs(vecPairs);
    // size_t s = ;
    for ( size_t i = 0 ; i < finalVec.size() ; i+=2 )
    {
        num ins;
        // size_t s = finalVec[i].idx.size();
        ins = vecPairs[finalVec[i].idx.back()].second; // problem in indexation of finalVec since it changes 
        // std::cout << "| | | | | | |" <<  << std::endl;
        ins.idx.pop_back();
        finalVec[i].idx.pop_back();
        std::vector<num>::iterator up = std::lower_bound( finalVec.begin(), finalVec.begin() + i, ins );
        finalVec.insert(up, ins);
    }
    if ( last.n != -1 )
    {
        std::vector<num>::iterator u = std::lower_bound( finalVec.begin(), finalVec.end(), last );
        finalVec.insert(u, last);
    }
    std::cout << "&&&&&&&&&& start final Vec &&&&&&&&&&" << std::endl;
    print(finalVec);
    std::cout << "&&&&&&&&&&& end final vec &&&&&&&&&" << std::endl;
    // std::cout << "seving : " << std::endl;
    // print(save);
    // start inserting in vecFinal 
    // 1- the save must be ghir a num and each recurse will save its num
    // 2- lower bound 3tiha lbegin  til the idx of its pair ,
}

/*   List   */
// std::list<int>  PmergeMe::fordList ()
// {

// }