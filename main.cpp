#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "heap.h"
#include "MinMedianMaxSketch.h"
using namespace std;

int main(int argc, char *argv[])
{
    string type_implement = argv[1];
    string f_insert = argv[2];
    string remove = argv[3];
    if (type_implement == "heap"){
        std::ifstream myfile;
        myfile.open(f_insert);
        string line;
        int size = 0;
        std::vector<int> heap_array;
        heap<int> heap1(heap_array, 0, true);
        heap<int> MAX(heap_array, 0, false);
        while (getline(myfile, line)){
            size += 1;
            heap1.insert(stoi(line));
            MAX.insert(stoi(line));
        }
        myfile.close();

        
        // std::ifstream myfile1;
        // myfile1.open(remove);
        // string line1;
        // while (getline(myfile1, line1)){
        //     heap1.remove(stoi(line1));
        //     MAX.remove(stoi(line1));
        // }
        // myfile1.close();

        cout << "Min Heap:" << endl;
        cout << "Size = " << heap1.get_size() << endl;
        cout << "Min = " << heap1.get_min() << endl;
        cout << "Min = " << heap1.get_max()  << endl;
        cout << "Root = " << heap1.get_root()  << endl;

        cout << "Max Heap:" << endl;
        cout << "Size = " << MAX.get_size() << endl;
        cout << "Min = " << MAX.get_min() << endl;
        cout << "Min = " << MAX.get_max()  << endl;

        cout << "Root = " << MAX.get_root()    << endl;






    }
    else if (type_implement == "minmedianmax")
    {
    }
}