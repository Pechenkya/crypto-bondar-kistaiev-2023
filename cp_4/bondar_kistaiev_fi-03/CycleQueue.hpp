#pragma once
#include <vector>

template <typename T>
class CycleQueue
{
private:
    std::vector<T> quque;
    size_t beg_pos = 0;
    size_t s;

public:
    CycleQueue(size_t sz) : quque{std::vector<T>(sz)}, s{sz} {}

    void push(T a)
    {
        quque.at(beg_pos) = a;
        beg_pos = (beg_pos + 1) % s;
    }

    T at(size_t pos) { return quque.at(pos); }
};