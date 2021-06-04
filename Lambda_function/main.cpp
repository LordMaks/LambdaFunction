#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <cmath>
#include <functional>

#ifndef ARRAY_COMMON_U
#define ARRAY_COMMON_U

namespace arrays
{
    template <typename K>
    void swap(K& e1, K& e2) // xor swap
    {
        e1 ^= e2;
        e2 ^= e1;
        e1 ^= e2;
    }

    template <typename K>
    void sort_rule(std:: vector<K>& v, bool (*func)(K& e1, K& e2))
    {
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v.size(); j++)
            {
                if (!func(v[i], v[j]) and !(i == j))
                    swap((v[i]), (v[j]));
            }
        }
    }

    template <typename K>
    void sort_rule(std::vector<K>& v, std::function<bool(K& e1, K& e2)> func)
    {
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v.size(); j++)
            {
                if (!func(v[i], v[j]) and !(i == j))
                    swap((v[i]), (v[j]));
            }
        }
    }

    template <typename K>
    void print(const std::vector<K>& v)
    {
        std::string result = "[";
        for (auto i : v)
        {
            result += std::to_string(i) + ", ";
        }
        result.erase(result.size() - 2, 2);
        result.append("]");

        std::cout << result << std::endl;
    }

    template <typename K1, typename K2>
    void print(const std::vector<std::pair<K1, K2>>& v)
    {
        std::string result = "[";
        for (auto i : v)
        {
            result += "(" + std::to_string(i.first) + ", " + std::to_string(i.second) + "), ";
        }
        result.erase(result.size() - 2, 2);
        result.append("]");

        std::cout << result << std::endl;
    }

    template <typename K>
    void print(const std::vector<std::vector<K>>& v)
    {
        std::string result = "[";
        for (auto i : v)
        {
            result += "[";
            for (auto j : i)
            {
                result += std::to_string(j) + ", ";
            }
            result.erase(result.size() - 2, 2);
            result.append("]\n");
        }
        result.erase(result.end());
        result.append("]");

        std::cout << result << std::endl;
    }

    template <typename K>
    std::string to_str(const std::vector<K>& v)
    {
        std::string result = "[";
        for (auto i : v)
        {
            result += std::to_string(i) + ", ";
        }
        result.erase(result.size() - 2, 2);
        result.append("]");

        return result;
    }

    template <typename K>
    std::string to_str(const std::vector<std::vector<K>>& v)
    {
        std::string result = "[";
        for (auto i : v)
        {
            result += "[";
            for (auto j : i)
            {
                result += std::to_string(j) + ", ";
            }
            result.erase(result.size() - 2, 2);
            result.append("]\n");
        }
        result.erase(result.size() - 1);
        result.append("]");

        return result;
    }

    template <typename K>
    K sum(const std::vector<K>& v)
    {
        K result = 0;
        for (auto i : v)
            result += i;

        return result;
    }

    template <typename K>
    K sum(const std::vector<std::vector<K>>& v)
    {
        K result = 0;
        for (auto i : v)
        {
            for (auto j : i)
                result += j;
        }

        return result;
    }

    template <typename K>
    K max(const std::vector<K>& v)
    {
        K mx = v[0];
        for (auto i : v) {
            if (mx < i) mx = i;
        }

        return mx;
    }

    template <typename K>
    K min(const std::vector<K>& v)
    {
        K mx = v[0];
        for (auto i : v) {
            if (mx > i) mx = i;
        }

        return mx;
    }

    template <typename K>
    K max(const std::vector<std::vector<K>>& v)
    {
        K mx = v[0][0];
        for (auto i : v)
        {
            for (auto j : i)
            {
                if (mx < j) mx = j;
            }
        }

        return mx;
    }

    template <typename K>
    K min(const std::vector<std::vector<K>>& v)
    {
        K mx = v[0][0];
        for (auto i : v)
        {
            for (auto j : i)
            {
                if (mx > j) mx = j;
            }
        }

        return mx;
    }



}
#endif

template <typename K>
struct vec
{
public:
    K x, y;

    vec<int>& operator^=(vec<int>& y)
    {
        this->x ^= y.x;
        this->y ^= y.y;

        return *this;
    }
};

template <typename K>
vec<K> init_vec(K& x, K& y)
{
    vec<K> res;
    res.x = x;
    res.y = y;

    return res;
}

template <typename K>
vec<K> init_vec(K x, K y)
{
    vec<K> res;
    res.x = x;
    res.y = y;

    return res;
}

template <typename K>
void swap(K& e1, K& e2)
{
    e1 ^= e2;
    e2 ^= e1;
    e1 ^= e2;
}

template <typename K>
void sort_rule(std::vector<K>& v, bool (*func)(K& e1, K& e2))
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (!func(v[i], v[j]) and !(i == j))
                swap((v[i]), (v[j]));
        }
    }
}

template <typename K>
void sort_rule(std::vector<K>& v, std::function<bool(K& e1, K& e2)> func)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (!func(v[i], v[j]) and !(i == j))
                swap((v[i]), (v[j]));
        }
    }
}

bool foo1(int& a, int& b)
{
    if (a < b)
        return true;
    return false;
}

bool foo2(vec<int>& a, vec<int>& b)
{
    if (sqrt(a.x * a.x + a.y * a.y) < sqrt(b.x * b.x + b.y * b.y))
        return true;
    return false;
}

int main(int argc, char* argv[])
{

    std::vector<int> v = { -21, 37, 52, 4, 3, 0, 86, 654, 99, 21, 22 };

    std::cout << "Original: " << arrays::to_str(v) << std::endl;
    sort_rule<int>(v, &foo1);
    std::cout << "Sorted: " << arrays::to_str(v) << std::endl;

    std::vector<vec<int>> v2;
    for (int i = 0; i < 8; i++) // filling array
    {
        v2.push_back(init_vec<int>(int(i + 3), int((i + 4) * 3)));
    }

    std::cout << std::endl;

    std::cout << "Original: " << std::endl;
    for (auto i : v2)
    {
        std::cout << i.x << " : " << i.y << std::endl;
    }

    sort_rule<vec<int>>(v2, [&](vec<int> a, vec<int> b) -> bool {
        if (sqrt(a.x * a.x + a.y * a.y) < sqrt(b.x * b.x + b.y * b.y)) return true;
        return false;
        });

    std::cout << "Sorted: " << std::endl;
    for (auto i : v2)
    {
        std::cout << i.x << " : " << i.y << std::endl;
    }
}
