// Copyright (c) 2022 Exoteq. All Rights Reserved.

#include "Discord.h"

#define LOCTEXT_NAMESPACE "FDiscordModule"

void FDiscordModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FDiscordModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}


#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FDiscordModule, Discord)