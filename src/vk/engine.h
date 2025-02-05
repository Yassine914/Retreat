#pragma once

#include "types.h"

class Engine
{
    private:
    bool is_initialized{false};
    i32 frame_no{0};
    bool stop_rendering{false};
    VkExtent2D window_extent{1700, 900};

    struct SDL_Window *window{nullptr};

    static Engine &Get();

    public:
    void Init();
    void Draw();
    void Run();
    void Cleanup();
};