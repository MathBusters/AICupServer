#ifndef _AICUP_SDK_COMMUNICATION_CLASS_H_
#define _AICUP_SDK_COMMUNICATION_CLASS_H_

#include "JsonSerializableAbstract.hpp"
#include "../core/GameMessage.hpp"

namespace AICup {

    namespace SDK {

        class Communication
        {
        public:
           static bool Serialize(JsonSerializableAbstract* pack, Core::GameMessage& output);
           static bool Deserialize(JsonSerializableAbstract* pack, Core::GameMessage& input);

        private:
           Communication() {}
        };
    }
}
#endif //_AICUP_SDK_COMMUNICATION_CLASS_H_
