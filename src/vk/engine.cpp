#include "engine.h"

#include <SDL2/SDL_vulkan.h>
#include <SDL2/SDL.h>

#include "types.h"
#include "initializers.h"

#include <chrono>
#include <thread>

constexpr bool use_validation_layers = false;

Engine *engine = nullptr;

// clang-format off
Engine &Engine::Get() { return *engine; }

void Engine::Init()
{
    // ensure only one instance exists
    assert(engine == nullptr);
    engine = this;

    // initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    SDL_WindowFlags window_flags = (SDL_WindowFlags)SDL_WINDOW_VULKAN;

    window = SDL_CreateWindow(
        "Retreat",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        window_extent.width,
        window_extent.height,
        window_flags);

    is_initialized = true;
}