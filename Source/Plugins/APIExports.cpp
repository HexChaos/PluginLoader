/*
    Initial author: (https://github.com/)Convery
    License: LGPL 3.0
    Started: 2015-10-16
    Notes:
        API to be called from other applications.
*/

#include <string>
#include <stdarg.h>
#include "..\Utility\FNVHash.h"

// Macros to make it more readable.
#define EXPORTSTART(ExportName) \
__declspec(dllexport) bool __stdcall ExportName(size_t Command, ...)    \
{                               \
    bool Result = false;        \
    va_list Variadic;           \
    va_start(Variadic, Command);\
                                \
    switch(Command)             \
    {
#define EXPORTEND               \
    }                           \
                                \
    va_end(Variadic);           \
    return Result;              \
}
#define EXPORTFUNCTION(Command, Functor)    \
    case FNV1a_Compiletime(Command):        \
        Result = Functor(Variadic);         \
        break

// Exports for managing the plugins.
extern "C"
{
    // Loading and unloading of plugins.
    EXPORTSTART(PluginLoading);
    EXPORTFUNCTION("LoadAll", [](va_list Placeholder) { return false; });           // No arguments
    EXPORTFUNCTION("LoadByName", [](va_list Placeholder) { return false; });        // const char *Pluginname
    EXPORTFUNCTION("UnloadAll", [](va_list Placeholder) { return false; });         // No arguments
    EXPORTFUNCTION("UnloadByName", [](va_list Placeholder) { return false; });      // const char *Pluginname
    EXPORTEND;

    // Fetching information about a plugin.
    EXPORTSTART(PluginInformation);
    EXPORTFUNCTION("AuthorName", [](va_list Placeholder) { return false; });        // const char *Pluginname, const char *Result
    EXPORTFUNCTION("AuthorSite", [](va_list Placeholder) { return false; });        // const char *Pluginname, const char *Result
    EXPORTFUNCTION("InternalName", [](va_list Placeholder) { return false; });      // const char *Pluginname, const char *Result
    EXPORTFUNCTION("OnDiskHash", [](va_list Placeholder) { return false; });        // const char *Pluginname, size_t *Result
    EXPORTFUNCTION("DependencyCount", [](va_list Placeholder) { return false; });   // const char *Pluginname, size_t *Result
    EXPORTFUNCTION("DependencyName", [](va_list Placeholder) { return false; });    // const char *Pluginname, size_t Index, const char *Result
    EXPORTFUNCTION("WhitelistClaim", [](va_list Placeholder) { return false; });    // const char *Pluginname, bool *Result
    EXPORTEND;

    // Access to the plugins keyvalue storage.
    EXPORTSTART(PluginStorage);
    EXPORTFUNCTION("ReadValue", [](va_list Placeholder) { return false; });         // const char *Pluginname, size_t Key, const char *Value
    EXPORTFUNCTION("WriteValue", [](va_list Placeholder) { return false; });        // const char *Pluginname, size_t Key, const char *Value
    EXPORTEND;

    // Interplugin communication.
    EXPORTSTART(PluginCommunication);
    EXPORTFUNCTION("SendMessage", [](va_list Placeholder) { return false; });       // const char *Pluginname, size_t Command, const char *Message
    EXPORTFUNCTION("BroadcastMessage", [](va_list Placeholder) { return false; });  // size_t Command, const char *Message
    EXPORTEND;
};
