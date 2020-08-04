// Copyright (c) 2020 by Chrono
//
// g++ sort.cpp -std=c++11 -o a.out;./a.out
// g++ sort.cpp -std=c++14 -o a.out;./a.out
// g++ sort.cpp -std=c++14 -I../common -o a.out;./a.out

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    std::vector<int> v = {42,9,4,2,5,10,1,0};

    auto bubble_sort = [=]() mutable
    {
        int len = v.size();

        for(int i = 0;i < len - 1; i++)
        {
            for(int j = 0; j < len - i - 1; j ++)
            {
                if (v[j] > v[j + 1])
                {
                    std::swap(v[j], v[j + 1]);
                }
            }
        }

        for(auto& x : v)
        {
            cout << x << ',';
        }

        cout << endl;
    };

    bubble_sort();
}
