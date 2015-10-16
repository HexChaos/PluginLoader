/*
    Initial author: (https://github.com/)Convery
    License: LGPL 3.0
    Started: 2015-10-16
    Notes:
        API to be called from other applications.
*/

#pragma once

#include <Windows.h>
#include <string>
#include <vector>

// Wrap the functions in a namespace
// so we don't accidentally use them.
namespace PluginManager
{
    // Vectors of plugin info.
    std::vector<HANDLE> PluginHandles;
    std::vector<std::string> PluginNames;

    // Loading and unloading of plugins.
    bool Int_LoadAll(va_list Variadic);
    bool Int_LoadByName(va_list Variadic);
    bool Int_UnloadAll(va_list Variadic);
    bool Int_UnloadByName(va_list Variadic);

    // Fetching information about a plugin.
    bool Int_AuthorName(va_list Variadic);
    bool Int_AuthorSite(va_list Variadic);
    bool Int_InternalName(va_list Variadic);
    bool Int_OnDiskHash(va_list Variadic);
    bool Int_DependencyCount(va_list Variadic);
    bool Int_DependencyName(va_list Variadic);
    bool Int_WhitelistClaim(va_list Variadic);

    // Access to the plugins keyvalue storage.
    bool Int_ReadValue(va_list Variadic);
    bool Int_WriteValue(va_list Variadic);

    // Interplugin communication.
    bool Int_SendMessage(va_list Variadic);
    bool Int_BroadcastMessage(va_list Variadic);
};
