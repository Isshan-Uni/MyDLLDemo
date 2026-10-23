
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyModLibrary.generated.h"

UCLASS()
class MYDLLDEMO_API UMyModLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "MyMod")
    static bool LoadMyModDLL();

    UFUNCTION(BlueprintCallable, Category = "MyMod")
    static void SetPreferredLanguageBP(const FString& LangCode);

    UFUNCTION(BlueprintPure, Category = "MyMod")
    static FString GetPreferredLanguageBP();

    UFUNCTION(BlueprintPure, Category = "MyMod")
    static float ScaleSpeedBP(float BaseSpeed, float Multiplier);

private:
    static void* DllHandle;

    typedef void (*SetLangFn)(const char*);
    typedef const char* (*GetLangFn)();
    typedef float (*ScaleSpeedFn)(float, float);

    static SetLangFn pSetLang;
    static GetLangFn pGetLang;
    static ScaleSpeedFn pScaleSpeed;
};
