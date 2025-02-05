#include "engine.h"

#include <SDL2/SDL_vulkan.h>
#include <SDL3/SDL.h>

#include "types.h"
#include "initializers.h"

#include <chrono>
#include <thread>

constexpr bool use_validation_layers = false;

Engine *engine_ref = nullptr;

// clang-format off
Engine &Engine::Get() { return *engine_ref; }

void Engine::Init()
{
    // ensure only one instance exists
    assert(engine_ref == nullptr);
    engine_ref = this;

    // initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    SDL_WindowFlags window_flags = (SDL_WindowFlags)SDL_WINDOW_VULKAN;

    window = SDL_CreateWindow(
        "Retreat",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        window_extent.width,
        window_extent.height,
        window_flags
    );

    is_initialized = true;
}

// clang-format on

void Engine::Run()
{
    SDL_Event event;
    bool quit = false;

    // main loop
    while(!quit)
    {
        // handle events
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_EVENT_QUIT)
                quit = true;

            // stop rendering when minimized
            if(event.type == SDL_EVENT_WINDOW_MINIMIZED)
                stop_rendering = true;

            if(event.type == SDL_EVENT_WINDOW_RESTORED)
                stop_rendering = false;
        }

        if(stop_rendering)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            continue;
        }

        Draw();
    }
}

void Engine::Draw() {}

void Engine::Cleanup()
{
    if(is_initialized)
        SDL_DestroyWindow(window);

    // remove the instance reference
    engine_ref = nullptr;
}