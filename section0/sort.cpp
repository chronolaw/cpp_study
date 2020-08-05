// Copyright (c) 2020 by Chrono
//
// g++ sort.cpp -std=c++11 -o a.out;./a.out
// g++ sort.cpp -std=c++14 -o a.out;./a.out
// g++ sort.cpp -std=c++14 -I../common -o a.out;./a.out

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

/*
template<typename T>
void quick_sort_impl(T& v, int left, int right)
{
    auto quick_partition = [](decltype(v)& arr, int left, int right)
    {
        // key => value type => int
        decltype(v.front()) key = arr[right];

        int i = left - 1;
        int j = left;

        for (; j < right; j++)
        {
            if (arr[j] < key)
            {
                std::swap(arr[j], arr[++i]);
            }
        }

        std::swap(arr[right], arr[++i]);

        return i;
    };

    if (left > right)
    {
        return;
    }

    int mid = quick_partition(v, left, right);

    quick_sort_impl(v, left, mid - 1);
    quick_sort_impl(v, mid + 1, right);
}
*/

int main()
{
    std::vector<int> v = {42,9,4,2,5,10,1,0};
    int len = v.size();

    // -----------------------------

    auto bubble_sort = [=]() mutable
    {
        for(int i = 0;i < len - 1; i++)
        {
            for(int j = 0; j < len - i - 1; j++)
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

    // -----------------------------

    auto select_sort = [=]() mutable
    {
        for (int i = 0; i < len - 1; i++)
        {
            int min = i;
            for(int j = i + 1; j < len; j ++)
            {
                if (v[min] > v[j])
                {
                    min = j;
                }

                swap(v[i], v[min]);
            }
        }

        for(auto& x : v)
        {
            cout << x << ',';
        }

        cout << endl;
    };

    select_sort();

    // -----------------------------

    auto insert_sort = [=]() mutable
    {
        int i, j;
        for(i = 0;i < len; i++)
        {
            int tmp = v[i];
            for(j = i; j > 0 && v[j - 1] > tmp; j--)
            {
                v[j] = v[j - 1];
            }

            v[j] = tmp;
        }

        for(auto& x : v)
        {
            cout << x << ',';
        }

        cout << endl;
    };

    insert_sort();

    // -----------------------------

    auto quick_partition = [](decltype(v)& arr, int left, int right)
    {
        // key => value type => int
        decltype(v.front()) key = arr[right];

        int i = left - 1;
        int j = left;

        for (; j < right; j++)
        {
            if (arr[j] < key)
            {
                std::swap(arr[j], arr[++i]);
            }
        }

        std::swap(arr[right], arr[++i]);

        return i;
    };

    std::function<void(decltype(v)&,int, int)> quick_sort_impl;

    quick_sort_impl =
    [&quick_sort_impl, &quick_partition](decltype(v)& v,int left, int right)
    {
        if (left > right)
        {
            return;
        }

        int mid = quick_partition(v, left, right);

        quick_sort_impl(v, left, mid - 1);
        quick_sort_impl(v, mid + 1, right);
    };

    auto quick_sort = [=]() mutable
    {
        quick_sort_impl(v, 0, len - 1);

        for(auto& x : v)
        {
            cout << x << ',';
        }

        cout << endl;
    };

    quick_sort();
}
