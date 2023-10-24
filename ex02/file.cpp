
#include <iostream>
#include <vector>


void    printCont( std::vector<int> &g, std::string s )
{
    std::vector<int>::iterator it = g.begin();
    std::cout << s << " : ";
    for ( ; it != g.end() ; it++ )
        std::cout << *it << "   ";
    std::cout << std::endl;
}

void test ( std::vector<int> &g )
{
    std::vector<int> small;
    std::vector<int> big;
    if ( g.size() > 1 )
    {
        std::vector<int>::iterator it = g.begin();
        for ( ; it != g.end() ; it+=2 )
        {
            if ( it + 1 != g.end() )
            {
                if ( *it > *(it + 1) )
                {
                    big.push_back(*it);
                    small.push_back(*(it + 1));
                }
                else
                {
                    std::cout << *it << std::endl;
                    big.push_back(*(it + 1));
                    small.push_back(*it);
                }
            }
        }
    }
    // test(big);

    printCont(small, "small");
    printCont(big, "big");
}


int main ()
{
    std::vector<int> gg;
    gg.push_back(5);
    gg.push_back(2);
    gg.push_back(4);
    gg.push_back(3);
    gg.push_back(6);
    gg.push_back(1);
    printCont(gg, "initial");
    // int  num = 10;
    test(gg);
}