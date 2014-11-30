#ifndef _AICUP_DEV_COMMUNICATION_CLASS_H_
#define _AICUP_DEV_COMMUNICATION_CLASS_H_

#include <string>

#include "../sdk/JsonSerializableAbstract.hpp"

namespace AICup {

    namespace Dev {

        class Communication : public SDK::JsonSerializableAbstract
        {
        public:
            Communication();

            virtual ~Communication();
            virtual void Serialize(Json::Value& root);
            virtual void Deserialize(Json::Value& root);

        public:
            int _communicationInt;
            float _communicationFloat;
            std::string _communicationString;
            bool _communicationtBool;
        };
    }
}
#endif //_AICUP_DEV_COMMUNICATION_CLASS_H_
