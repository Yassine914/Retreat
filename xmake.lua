add_rules("mode.debug", "mode.release")

-- target("console")
--     set_kind("binary")
--     add_files("src/*.c")
--     if is_mode("debug") then
--         add_defines("DEBUG")
--     end

target("retreat")
    set_kind("binary")
    
    set_toolchains("@gcc")
    set_toolset("cxx", "g++")
    set_toolset("cc", "gcc")
    
    add_files("src/*.cpp")
    add_headerfiles("src/**.h")
    add_files("src/core/*.cpp")
    
    add_includedirs("src")
    add_includedirs("src/core")
    add_includedirs("src/vk")

    add_includedirs("thirdparty/SDL3/include")
    add_linkdirs("thirdparty/SDL3/bin")

    add_includedirs("thirdparty/GLM/include")

    add_links("SDL3")

    if not is_plat("windows") or is_kind("mingw") then
        add_defines("_GNU_SOURCE")
    end

    if is_plat("windows") then
        add_includedirs(os.getenv("VULKAN_SDK") .. "/Include")
        add_linkdirs(os.getenv("VULKAN_SDK") .. "/Lib")
        add_links("vulkan-1")
    else
        add_links("vulkan")
    end

    after_build(function (target)
        os.cp("thirdparty/SDL3/bin/SDL3.dll", target:targetdir())
    end)

    if is_mode("debug") then
        add_defines("RETREAT_DEBUG")
    end

    if is_mode("release") then
        add_defines("RETREAT_NDEBUG")
    end