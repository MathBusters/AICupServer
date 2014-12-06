#ifndef _AICUP_DEV_COMMUNICATIONPACK_CLASS_H_
#define _AICUP_DEV_COMMUNICATIONPACK_CLASS_H_

#include <string>

#include "../sdk/Communication.hpp"
#include "../sdk/JsonSerializableAbstract.hpp"

namespace AICup {
    namespace Dev {

        class CommunicationPack : public SDK::JsonSerializableAbstract
        {
        public:
            CommunicationPack();

            virtual ~CommunicationPack() {}
            virtual void Serialize(Json::Value& root);
            virtual void Deserialize(Json::Value& root);

        public:
            int CommunicationInt;
            double CommunicationDouble;
            std::string CommunicationString;
            bool CommunicationtBool;
        };
    }
}
#endif //_AICUP_DEV_COMMUNICATIONPACK_CLASS_H_
