#ifndef _CORE_PHYS_CLASS_H_
#define _CORE_PHYS_CLASS_H_

namespace AICup {

    namespace Core {

        class Phys
        {
        public:
            Phys();
//            ~Phys();

            int generateWildSpeed(int lowerLimit, int upperLimit);
            int calculateDistance(int power, double angle, int windSpeed);
            int calculateEpsilon(int hitPosition, int enemyPosition);

            int getWindSpeed();

        private:
            int _windSpeed;
        };
    }
}
#endif //_CORE_PHYS_CLASS_H_
