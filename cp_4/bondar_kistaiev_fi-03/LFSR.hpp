#include <vector>
#include <cstdint>

// Limit polynomial deg with 32 bits (uint32_t)
// That is useful for our task
class LFSR
{
    const uint32_t __mask_for_bit_to_pop = 1;
    uint32_t __mask_for_bit_to_set;
    uint8_t max_bit_n;
    uint32_t recurvia;

public:
    LFSR(uint32_t recurv_coefs);

    std::vector<bool> generate(uint32_t initial_fill, size_t length);
};

LFSR::LFSR(uint32_t recurv_coefs) : recurvia{recurv_coefs}
{
    __mask_for_bit_to_set = 0x80000000; // Set msb to 1
    max_bit_n = 31;
    while (!(__mask_for_bit_to_set & recurv_coefs))
    {
        __mask_for_bit_to_set >>= 1;
        max_bit_n -= 1;
    }
};

std::vector<bool> LFSR::generate(uint32_t filling, size_t length)
{
    std::vector<bool> feedback(length);

    for (size_t i = 0; i < length; ++i)
    {
        feedback.at(i) = filling & __mask_for_bit_to_pop;
        filling = (filling >> 1) ^ ((__builtin_popcount(filling & recurvia) & 1u) << max_bit_n);
    }

    return feedback;
}