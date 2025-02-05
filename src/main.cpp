#include "core/defines.h"
#include "core/logger.h"
#include "core/error.h"

#include "vk/engine.h"

int main()
{
#ifdef RETREAT_NDEBUG
    LOG_CHANGE_PRIORITY(LOG_NONE);
#else
    LOG_CHANGE_PRIORITY(LOG_ALL);
#endif

    LLOG(GREEN_TEXT("[RETREAT]: "), "Engine Starting....\n");

    Engine *rengine;

    rengine->Init();

    rengine->Run();

    rengine->Cleanup();

    return 0;
}