// Copyright (c) 2022 Exoteq. All Rights Reserved.

#include "DiscordChat.h"
#include "Types.h"
#include "JsonObjectConverter.h"

void UDiscordChannelGetMessages::Activate()
{
	// Create HTTP Request
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetVerb("GET");
	HttpRequest->SetHeader("Content-Type", "application/json");
	HttpRequest->SetHeader("Authorization", "Bot " + Token);
	HttpRequest->SetURL("https://discord.com/api/channels/" + ChannelID + "/messages");

	// user image = https://cdn.discordapp.com/avatars/<authorId>/<avatar>.webp?size=128

	// Setup Async response
	HttpRequest->OnProcessRequestComplete().BindLambda([this](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
		{
			FString ResponseString = "";
			if (bSuccess)
			{
				ResponseString = Response->GetContentAsString();
			}

			this->HandleGetMessagesCompleted(ResponseString, Response->GetResponseCode() == 200);
		});

	// Handle actual request
	HttpRequest->ProcessRequest();
}


void UDiscordChannelGetMessages::HandleGetMessagesCompleted(FString ResponseString, bool bSuccess)
{
	FString OutString;
	TArray<FDiscordMessage> discordMessages;

	if (bSuccess)
	{
		/* Deserialize object */
		//TArray<TSharedPtr<FJsonValue>> JsonArray;
		//TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<>::Create(ResponseString);
		//FJsonSerializer::Deserialize(JsonReader, JsonArray);

		FJsonObjectConverter::JsonArrayStringToUStruct(ResponseString, &discordMessages, 0, 0);
	}

	Completed.Broadcast(discordMessages, ResponseString, bSuccess);
}


UDiscordChannelGetMessages* UDiscordChannelGetMessages::DiscordRequestChannelMessages(UObject* WorldContextObject, FString ChannelID, FString Token)
{
	// Create Action Instance for Blueprint System
	UDiscordChannelGetMessages* Action = NewObject<UDiscordChannelGetMessages>();
	Action->ChannelID = ChannelID;
	Action->Token = Token;
	Action->RegisterWithGameInstance(WorldContextObject);

	return Action;
}

void UDiscordChannelAddMessage::Activate()
{
	// Create HTTP Request
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetVerb("POST");
	HttpRequest->SetHeader("Content-Type", "application/json");
	HttpRequest->SetHeader("Authorization", "Bot " + Token);
	HttpRequest->SetURL("https://discord.com/api/channels/" + ChannelID + "/messages");

	FString JSONPayload;
	FJsonObjectConverter::UStructToJsonObjectString(DiscordMessage, JSONPayload, 0, 0);

	HttpRequest->SetContentAsString(JSONPayload);

	// Setup Async response
	HttpRequest->OnProcessRequestComplete().BindLambda([this](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
		{
			this->HandleAddMessageCompleted(Response->GetResponseCode() == 200);
		});

	// Handle actual request
	HttpRequest->ProcessRequest();
}


void UDiscordChannelAddMessage::HandleAddMessageCompleted(bool bSuccess)
{
	Completed.Broadcast(bSuccess);
}


UDiscordChannelAddMessage* UDiscordChannelAddMessage::DiscordRequestAddMessage(UObject* WorldContextObject, FString ChannelID, FString Token, FDiscordMessage DiscordMessage)
{
	// Create Action Instance for Blueprint System
	UDiscordChannelAddMessage* Action = NewObject<UDiscordChannelAddMessage>();
	Action->ChannelID = ChannelID;
	Action->Token = Token;
	Action->DiscordMessage = DiscordMessage;
	Action->RegisterWithGameInstance(WorldContextObject);

	return Action;
}