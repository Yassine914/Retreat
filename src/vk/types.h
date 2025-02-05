#pragma once

#include <memory>
#include <optional>
#include <vector>
#include <string>
#include <span>
#include <array>
#include <functional>
#include <deque>

#include <vulkan/vulkan.h>
#include <vulkan/vk_enum_string_helper.h>
#include <vma/vk_mem_alloc.h>

#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>

#include "../core/defines.h"
#include "../core/error.h"
#include "../core/logger.h"

#define VK_CHECK(x)                                                                                                    \
    do                                                                                                                 \
    {                                                                                                                  \
        VkResult err = x if(err)                                                                                       \
        {                                                                                                              \
            LERROR(true, RED_TEXT("[RETREAT::VULKAN]: "), string_VkResult(err));                                       \
            abort();                                                                                                   \
        }                                                                                                              \
    } while(0)
