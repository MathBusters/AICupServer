#ifndef _AICUPAPP_CLASS_H_
#define _AICUPAPP_CLASS_H_

namespace AICup {

    class AICupApp
    {
    public:
        AICupApp(int port);
        ~AICupApp();

        int Run();

    private:
        int         _port;
    };
}
#endif //_AICUPAPP_CLASS_H_
