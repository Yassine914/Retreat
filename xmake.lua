target("retreat")
    set_kind("binary")
    set_toolchains("@gcc")
    set_toolset("cxx", "g++")
    set_toolset("cc", "gcc")

    add_files("src/*.cpp")
    add_headerfiles("src/**.h")

    add_includedirs("thirdparty/SDL3/include")
    add_linkdirs("thirdparty/SDL3/bin")

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