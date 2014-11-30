#ifndef _CORE_BATTLE_LOG_CLASS_H_
#define _CORE_BATTLE_LOG_CLASS_H_

#include <string>
#include <fstream>

namespace AICup {

    namespace Core {

        class BattleLog
        {
        public:
            BattleLog();
//            ~BattleLog();

            void Start();
            void Draw();
            void Win(std::string ai);

            void Round();
            void Shot(std::string ai, int power, double angle, int wind, int coordinate, int epsilon);

        private:
            int _round;
            std::ofstream _log;
        };
    }
}
#endif //_CORE_BATTLE_LOG_CLASS_H_
