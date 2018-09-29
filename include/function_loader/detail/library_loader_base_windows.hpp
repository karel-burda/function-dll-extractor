#pragma once

#include <string>

#include <windows.h>

namespace burda
{
namespace function_loader
{
namespace detail
{
class library_loader_base
{
public:
    HMODULE get_handle() const
    {
        return handle;
    }

protected:
    void load_library(const std::string & path)
    {
        handle = LoadLibraryExA(path.c_str(), nullptr, 0);
    }

    void unload_library()
    {
        if (handle)
        {
            FreeLibrary(handle);

            handle = nullptr;
        }
    }

    const char * get_last_error()
    {
        last_error = std::to_string(GetLastError());

        return last_error.c_str();
    }

    HMODULE handle = nullptr;

private:
    std::string last_error;
};
}
}
}