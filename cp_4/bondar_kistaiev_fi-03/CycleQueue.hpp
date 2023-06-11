#pragma once
#include <vector>

template <typename T>
class CycleQueue
{
private:
    std::vector<T> quque;
    size_t insert_p = 0;
    size_t s;

public:
    CycleQueue(size_t sz) : quque{std::vector<T>(sz)}, s{sz} {}

    void push(T a)
    {
        quque.at(insert_p) = a;
        insert_p = (insert_p + 1) % s;
    }

    T at(size_t pos) { return quque.at(pos); }
};