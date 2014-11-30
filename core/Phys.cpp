#include "Phys.hpp"

#define _USE_MATH_DEFINES

#include <cmath>
#include <random>

using namespace std;
using namespace AICup;
using namespace AICup::Core;

Phys::Phys()
{
}

int Phys::generateWildSpeed(int lowerLimit, int upperLimit)
{
    random_device rd;
    mt19937 e2(rd());
/*
    uniform_real_distribution<double> dist(lowerLimit, upperLimit);

    for(size_t i = 0; i < rows; ++i) {
        for(size_t j = 0; j < cols; ++j) {
            arr[i][j] = dist(e2);
        }
    }
*/
    uniform_int_distribution<int> dist(lowerLimit, upperLimit);

    _windSpeed = dist(e2);

    return _windSpeed;
}

int Phys::calculateDistance(int power, double angle, int windSpeed)
{
    int v0 = log2(power);
    v0 =- windSpeed;

    int s = v0 * v0 * sin(angle * M_PI / 180);

    return s;
}

int Phys::calculateEpsilon(int hitPosition, int enemyPosition)
{

    return abs(hitPosition - enemyPosition);
}

int Phys::getWindSpeed()
{

    return _windSpeed;
}
