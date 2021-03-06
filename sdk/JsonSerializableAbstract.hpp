#ifndef _AICUP_SDK_JSONSERIALIZABLEABSTRACT_CLASS_H_
#define _AICUP_SDK_JSONSERIALIZABLEABSTRACT_CLASS_H_

#include <jsoncpp/json/json.h>

namespace AICup {

    namespace SDK {

        class JsonSerializableAbstract
        {
        public:
            virtual ~JsonSerializableAbstract() {}
            virtual void Serialize(Json::Value& root) =0;
            virtual void Deserialize(Json::Value& root) =0;
        };
    }
}
#endif //_AICUP_SDK_JSONSERIALIZABLEABSTRACT_CLASS_H_
