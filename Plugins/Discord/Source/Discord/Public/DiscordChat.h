// Copyright (c) 2022 Exoteq. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Types.h"
#include "DiscordChat.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHttpRequestCompleted, bool, bSuccess);

UCLASS()
class DISCORD_API UDiscordChannelGetMessages : public UBlueprintAsyncActionBase
{
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnHttpRequestCompleted, const TArray<FDiscordMessage>&, DiscordMessages, const FString&, ResponseContent, bool, bSuccess);

	GENERATED_BODY()

protected:

	void HandleGetMessagesCompleted(FString ResponseString, bool bSuccess);

public:

	/** Execute the actual load */
	virtual void Activate() override;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", Category = "Discord", WorldContext = "WorldContextObject"))
		static UDiscordChannelGetMessages* DiscordRequestChannelMessages(UObject* WorldContextObject, FString ChannelID, FString Token);

	UPROPERTY(BlueprintAssignable)
		FOnHttpRequestCompleted  Completed;

	FString ChannelID;
	FString Token;
};

UCLASS()
class DISCORD_API UDiscordChannelAddMessage : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

protected:

	void HandleAddMessageCompleted(bool bSuccess);

public:

	/** Execute the actual load */
	virtual void Activate() override;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", Category = "Discord", WorldContext = "WorldContextObject"))
		static UDiscordChannelAddMessage* DiscordRequestAddMessage(UObject* WorldContextObject, FString ChannelID, FString Token, FDiscordMessage DiscordMessage);

	UPROPERTY(BlueprintAssignable)
		FOnHttpRequestCompleted Completed;

	FString ChannelID;
	FString Token;
	FDiscordMessage DiscordMessage;
};