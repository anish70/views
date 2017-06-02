#include <iostream>   
#include <time.h>     
#include <fstream>
#include <map>
#include <cstdlib>
#include <iomanip>
#include <vector>

void display(std::map <int, std::vector<int> > hash);

int main(){
    srand (time(NULL));
    int temp;
    int tempCount = 1;
    int count = 0;
    int number;
    int k = 10; //sum for pairs in an array

    //create array for testing
    int size = 15;
    int foo[15] = {};
    for(int i = 0; i < size; ++i){
        foo[i] = ((double)rand() * (10 - 1) / (double)RAND_MAX + 1);
    }

    //print array:
    for(int i = 0; i < size; ++i){
        std::cout << foo[i] << std::endl;
    }

   //Find pairs in an array whose sum is equal to ten using hash map    
    std::map <int, std::vector<int> > hash;
    const std::pair<int, int> pairs[15];
    for(int i = 0; i < size; i++){
        std::make_pair(pairs[foo[i]] , i);
    }

    const int N = sizeof(pairs) / sizeof(pairs[0]);
    for(int i = 0; i < N; ++i){
        const int& key = pairs[i].first;
        const int value = pairs[i].second;
        hash[key].push_back(value);
    }
    display(hash);
}

void display (std::map <int, std::vector<int> > hash)
{
    std::cout << "\tTotal size: " << hash.size() << std::endl; /* Output the size */
    /* Create an iterator, much like vector iterators */
    std::map <int, std::vector<int> >::iterator it;
    for (it = hash.begin(); it != hash.end(); it++){
        /* Output first (which is index) and second (which is the element) */

        const int& key = it->first ;
        std::cout << "key: " << key << "  values: ";

        const std::vector<int>& values = it->second ;
        for(std::size_t i = 0; i < values.size(); ++i)
            std::cout << values[i] << ' ';
        std::cout << '\n';
    }

    std::cout << std::endl; /* Print a new line */
}
