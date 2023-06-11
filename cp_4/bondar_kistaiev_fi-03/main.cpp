#include "LFSR.hpp"
#include "Geffe.hpp"
#include <iostream>
#include <string>
#include "CycleQueue.hpp"

const std::string DUMMY_STRING = "00111100011010100111011000000101011111001011010000101001001111010011101111110010011010000011011110100001011001001000010010111010001110000100010100110111100011010110100111100111001110000010111011111111010110010110011010101110110111011010000101000010010000010111010100010111010010001101010001010111000010111100011110100011100011011010010011001001011100001101100100110000011110101100100001000100000101011111111101010101110011001000111001110110110001110001000010101001011010010101011011110000111101101000111001111101111011010101100110001001010000010010001100100001110001010100010011011111100111011111010110000001111000010000111110101111010111111011101001011010000100001010101101000100010011101011111111101011000000001110011011101100110110001010010011001101100110100011011000111000111110100110100010101010100011111010111010110101100011000000010000010111000101100001010111001000000100010100101011000100110110101100111010110111001110001001001111010011011110010101011100100110110111110111110111010110100010110111010110101011101011100100010101011000100101111011110101010100101101010111011111100001101111010100011011011011111100010100110111100110111111011011101010011011111110100101001100111010101101000010111010010000111001110001000001110011010111111111101111111000110011001010011110001111100011110100110100001010001111000100110011000101000011100001000001110001001100011000010111111010001100101110011110001111101101101001010010011100101100111110010100101100110001111101011001101111001011001001001110000110000110000001001101101100110001000101010010001110000110010001000001000110101000011100100101101011101101111101000100110000100101000110001101010011100101011110001111000100111110010111010000111101010001100101011111100110110011110001110000100101110101110011100110111101011100111101001000101000001100100001101110000101101011011001010101100110110110111000111011101111001110010010000010111010001111000000011001010010100000110001100000010101000111110101000100001100100101000011000010100100001110110011101101111010001100100101001011011111001110001011010010110011";
const std::string DEFAULT_STRING = "01101110110010000110100111111011101110110010001010000011111100101001011111001001001100001100101010011011110010010111110100011000010000010110010000001001110110101000111111111001100010111000000001000001000110011111001100000000101010011110101110010110111000001000000111111011000011010000101110100000010000000111101110010111100100111111000110111101101110001110101010110111000101011100011011111010101101111001000000100100000000110011011100011001001000000101110010111010011000001010101110011010100011100000110000011000111110110001000100001011111010000001010000011011000010001010111001101010100011100001111001110101011100111101101010010101001010101110100101100110101011111011101001001011000110010000010011111000000000010001100110100000101000000010010110000011110100110110001010010101110111000001011001100100011100001111011010101011000011111101001101001000111011101100000011001111001111101010101111010010001011010000110000110010101011110001011101001111010110000010001000111010010010110111001001101111110111000110000110010000101100100010001001011101001011101101111101111011110001110111101001101000011101111000000011111111111111001101101000100110101000110111001000000111101011011000000100110011100001010000011101010001110111011001100100010000100111110110000110110011100111110000111011001111010111110001110110111110001000111000010010100000101010101010001111000110011011011110010110100110100000000000110000111000011011110100000001000000001100101011100000000110001000110100110001011010110101010001100101111011010011111010010110100101110100100101101001111001101010111000011101101011001001101100011001111110001000100100010011000001000101100111111000001110010010100110100001110110010111101111100101011010011101000100001111110010101100101011101110001000001100110110101100010011010110001000010110110001011011101001010101000000001101000101011001100110101001101111100101100101111111010101010000110001101101001000100111101100100010111000101110100101110000001111110001101100011110110001110100000011000001100110111001110011011101111100011001110000000111010110111001011110";

// !WARNING: NOT MEMORY-EFFICIENT SOLUTION (Maksym)!
int main()
{
    float aplha = 0.01;

    // Default complexity
    // uint32_t L1_rec = (1u << 6) ^ (1u << 5) ^ (1u << 1) ^ 1u;
    // uint8_t L1_deg = 30;
    // uint32_t L2_rec = (1u << 3) ^ 1u;
    // uint8_t L2_deg = 31;
    // uint32_t L3_rec = (1u << 7) ^ (1u << 5) ^ (1u << 3) ^ (1u << 2) ^ (1u << 1) ^ 1u;
    // uint8_t L3_deg = 32;

    // uint32_t N = DEFAULT_STRING.size();
    // std::vector<uint8_t> r_seq(N);
    // for (size_t i = 0; i < N; ++i)
    // {
    //     r_seq[i] = DEFAULT_STRING[i] - 48;
    // }
    //

    // Dummy complexity
    uint32_t L1_rec = (1u << 3) ^ 1;
    uint8_t L1_deg = 25;
    uint32_t L2_rec = (1u << 6) ^ (1u << 2) ^ (1u << 1) ^ 1u;
    uint8_t L2_deg = 26;
    uint32_t L3_rec = (1u << 5) ^ (1u << 2) ^ (1u << 1) ^ 1u;
    uint8_t L3_deg = 27;

    uint32_t N = DUMMY_STRING.size();
    std::vector<uint8_t> r_seq(N);
    for (size_t i = 0; i < N; ++i)
    {
        r_seq[i] = DUMMY_STRING[i] - 48;
    }

    uint32_t N1_req = 222;
    uint32_t C1 = 71;
    uint32_t N1_req = 229;
    uint32_t C1 = 74;
    //

    LFSR L1 = LFSR(L1_rec, L1_deg);
    LFSR L2 = LFSR(L2_rec, L2_deg);
    LFSR L3 = LFSR(L3_rec, L3_deg);

    //----- L1 -----
    uint32_t best_fit_L1_fill = 0;
    {
        std::vector<std::pair<CycleQueue<uint8_t>, size_t>> candidates;

        uint64_t cyclen = (uint64_t(1) << L1_deg) + uint64_t(N1_req);
        auto cyc1 = L1.generate_from_fill(1, cyclen);

        CycleQueue<uint8_t> filling(L1_deg);

        size_t R = 0;
        uint64_t t = 0;
        for (; t < L1_deg; ++t)
            filling.push(cyc1[t]);
        for (size_t i = 0; i < N1_req; ++i)
            R += size_t(cyc1.at(t) ^ r_seq.at(t));

        if (R < C1)
        {
            candidates.push_back({filling, R});
        }

        // uint8_t fill_next = cyc1.at(t); ???
        size_t stat_diff = r_seq.at(0) ^ cyc1.at(0);
        for (uint64_t i = 0; i < cyclen - N1_req; ++i)
        {
            filling.push(cyc1.at(i + L1_deg));
            R = R - stat_diff + size_t(cyc1.at(i + N1_req) ^ r_seq.at(i + N));
        }
    }
    std::cout << "L1 finished";

    //----- L2 -----
    uint32_t best_fit_L2_fill = 0;
    {
        // for (uint64_t i = 0)
    }
    std::cout << "L2 finished";

    //----- L3 -----
    uint32_t best_fit_L3_fill = 0;
    {
        // for (uint64_t i = 0)
    }
    std::cout << "L3 finished";

    // Geffe generator
    Geffe generator(L1, L2, L3);
}