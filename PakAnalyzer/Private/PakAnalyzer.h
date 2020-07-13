// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "HAL/CriticalSection.h"
#include "Misc/Guid.h"

#include "IPakAnalyzer.h"

struct FPakEntry;

class FPakAnalyzer : public IPakAnalyzer, public TSharedFromThis<FPakAnalyzer>
{
public:
	FPakAnalyzer();
	virtual ~FPakAnalyzer();

	virtual bool LoadPakFile(const FString& InPakPath) override;
	virtual int32 GetFileCount() const override;
	virtual const TArray<FPakFileEntryPtr>& GetFiles() const override;
	virtual FString GetLastLoadGuid() const override;
	virtual bool IsLoadDirty(const FString& InGuid) const override;
	virtual const FPakFileSumary& GetPakFileSumary() const override;
	virtual FString GetPakFilePath() const override;
	virtual bool GetPakFilesInDirectory(const FString& InDirectory, bool bIncludeFiles, bool bIncludeDirectories, bool bRecursive, TArray<FPakTreeEntryPtr>& OutFiles) const override;

protected:
	void Reset();

protected:
	FCriticalSection CriticalSection;
	TArray<FPakFileEntryPtr> Files;

	TSharedPtr<class FPakFile> PakFile;

	FGuid LoadGuid;

	FPakFileSumary PakFileSumary;

	FString PakFilePath;
};
