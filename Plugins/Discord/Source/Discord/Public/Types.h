// Copyright (c) 2022 Exoteq. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Types.generated.h"

USTRUCT(Blueprintable)
struct DISCORD_API FDiscordAuthor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Discord")
		FString authorID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Discord")
		FString username;
};

USTRUCT(Blueprintable)
struct DISCORD_API FDiscordEmbedAuthor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Discord")
		FString name;
};

USTRUCT(Blueprintable)
struct DISCORD_API FDiscordEmbedFields
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Discord")
		FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Discord")
		FString value;
};

USTRUCT(Blueprintable)
struct DISCORD_API FDiscordEmbed
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Discord")
		FString type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Discord")
		FString title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Discord")
		FString description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Discord")
		FDiscordEmbedAuthor author;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Discord")
		TArray<FDiscordEmbedFields> fields;
};

USTRUCT(Blueprintable)
struct DISCORD_API FDiscordMessage
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Discord")
		FString channelID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Discord")
		FDiscordAuthor author;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Discord")
		TArray<FDiscordEmbed> embeds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Discord")
		FString content;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Discord")
		FString timestamp;
};

UCLASS()
class DISCORD_API UTypes : public UObject
{
	GENERATED_BODY()
	
};
