/*
    Initial author: (https://github.com/)Convery
    License: LGPL 3.0
    Started: 2015-10-14
    Notes:
        API to be called from other applications.
*/

#include <string>
#include <stdarg.h>
#include "Hashing.h"
#include "Warnings.h"

// Interfaces for managing plugins.
extern "C"
{
    // Plugin loading and unloading commands.
    __declspec(dllexport) bool __stdcall PluginLoad(size_t Command, ...)
    {
        bool Result = false;
        va_list Variadic;
        va_start(Variadic, Command);

        // Switch on the command and call the requested function.
        switch (Command)
        {
            /* No arguments */
            case FNV1a_Compiletime("LoadAll"):
                Result = /* TODO: Call func */ false;
                break;

            /* const char *PluginName */
            case FNV1a_Compiletime("LoadByName"):
                Result = /* TODO: Call func */ false;
                break;

            /* const char *PluginName */
            case FNV1a_Compiletime("PreInitialization"):
                Result = /* TODO: Call func */ false;
                break;

            /* const char *PluginName */
            case FNV1a_Compiletime("PostInitialization"):
                Result = /* TODO: Call func */ false;
                break;
        }

        va_end(Variadic);
        return Result;
    }
    __declspec(dllexport) bool __stdcall PluginUnload(size_t Command, ...)
    {
        bool Result = false;
        va_list Variadic;
        va_start(Variadic, Command);

        // Switch on the command and call the requested function.
        switch (Command)
        {
            /* No arguments */
            case FNV1a_Compiletime("UnloadAll"):
                Result = /* TODO: Call func */ false;
                break;

            /* const char *PluginName */
            case FNV1a_Compiletime("UnloadByName"):
                Result = /* TODO: Call func */ false;
                break;
        }

        va_end(Variadic);
        return Result;
    }

    // Information about a plugin.
    __declspec(dllexport) bool __stdcall PluginInfo(size_t Command, ...)
    {
        bool Result = false;
        va_list Variadic;
        va_start(Variadic, Command);

        // Switch on the command and call the requested function.
        switch (Command)
        {
            /* const char *PluginName, const char *Result */
            case FNV1a_Compiletime("GetAuthorName"):
                Result = /* TODO: Call func */ false;
                break;

            /* const char *PluginName, const char *Result */
            case FNV1a_Compiletime("GetAuthorSite"):
                Result = /* TODO: Call func */ false;
                break;

            /* const char *PluginName, const char *Result */
            case FNV1a_Compiletime("GetInternalPluginName"):
                Result = /* TODO: Call func */ false;
                break;

            /* const char *PluginName, size_t *Result */
            case FNV1a_Compiletime("GetPluginHash"):
                Result = /* TODO: Call func */ false;
                break;

            /* const char *PluginName, size_t *Count */
            case FNV1a_Compiletime("GetDependencyCount"):
                Result = /* TODO: Call func */ false;
                break;

            /* const char *PluginName, size_t Index, const char *Dependency */
            case FNV1a_Compiletime("GetDependency"):
                Result = /* TODO: Call func */ false;
                break;

            /* const char *PluginName, bool *Status */
            case FNV1a_Compiletime("GetWhitelistStatus"):
                Result = /* TODO: Call func */ false;
                break;
        }

        va_end(Variadic);
        return Result;
    }

    // Access to the plugin key-value storage.
    __declspec(dllexport) bool __stdcall PluginKeyval(size_t Command, ...)
    {
        bool Result = false;
        va_list Variadic;
        va_start(Variadic, Command);

        // Switch on the command and call the requested function.
        switch (Command)
        {
            /* const char *PluginName, size_t Key, const char *Value */
            case FNV1a_Compiletime("ReadValue"):
                Result = /* TODO: Call func */ false;
                break;

            /* const char *PluginName, size_t Key, const char *Value */
            case FNV1a_Compiletime("WriteValue"):
                Result = /* TODO: Call func */ false;
                break;
        }

        va_end(Variadic);
        return Result;
    }

    // Inter plugin communication.
    __declspec(dllexport) bool __stdcall PluginCommunication(size_t Command, ...)
    {
        bool Result = false;
        va_list Variadic;
        va_start(Variadic, Command);

        // Switch on the command and call the requested function.
        switch (Command)
        {
            /* const char *PluginName, size_t Command, const char *Message */
            case FNV1a_Compiletime("SendMessage"):
                Result = /* TODO: Call func */ false;
                break;

            /* size_t Command, const char *Message */
            case FNV1a_Compiletime("BroadcastMessage"):
                Result = /* TODO: Call func */ false;
                break;
        }

        va_end(Variadic);
        return Result;
    }
};
