
#include "PmergeMe.hpp"

template <typename T>
void    printCont( T &g )
{
    typename T::iterator it = g.begin();
    std::cout << "After  : ";
    for ( ; it != g.end() ; it++ )
        std::cout << *it << "   ";
    std::cout << std::endl;
}

int main ( int ac, char **av )
{
    if ( ac > 1 )
    {
        try
        {
            /*      List Sorting    */
            // clock_t start, end;
            // double time;
            PmergeMe g;
            // start = clock();
            g.parseFill( ac - 1, av );

            // std::list<int> lst = g.fordList();
            // end = clock();
            // time = ((float)(end) - (float)(start)) / CLOCKS_PER_SEC * 1000000.0f;

            /*    Vector Sorting    */
            // clock_t s, e;
            // s = clock();
            // g.parseFill( ac - 1, av, "vec" );
            // std::vector<int> vec = g.fordVec();
            // e = clock();
            // double t = ((float)(e) - (float)(s)) / CLOCKS_PER_SEC * 1000000.0f;
            // std::cout << "Before : ";
            // for ( int i = 1 ; av[i] ; i++ )
            //     std::cout << av[i] << "   ";
            // std::cout << std::endl;
            // printCont( lst );
            // std::cout << "Time to process a range of "<< ac - 1 << " elements with std::vector : " << std::fixed << std::setprecision(6) << t << " us" << std::endl;
            // std::cout << "Time to process a range of "<< ac - 1 << " elements with std::list   : " << time << " us" << std::endl;

        }
        catch ( std::exception &e )
        {
            std::cout << e.what() << std::endl;
        }
    }
    else
        std::cout << "Wrong number of arguments" << std::endl;
}