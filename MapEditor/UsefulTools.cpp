#include "UsefulTools.h"
#include <random>

int Random::getIntRandom(int min, int max)
{
    std::random_device generator;
    std::uniform_int_distribution<int> distribution(min,max);
    
    return distribution(generator);
}

float Random::getFloatRandom(float min, float max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distribution(min,max);
    
    return distribution(gen);

}