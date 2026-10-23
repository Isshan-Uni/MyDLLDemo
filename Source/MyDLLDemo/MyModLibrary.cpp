
#include "MyModLibrary.h"
#include "Misc/Paths.h"
#include "HAL/PlatformProcess.h"
#include <string>

void* UMyModLibrary::DllHandle = nullptr;
UMyModLibrary::SetLangFn UMyModLibrary::pSetLang = nullptr;
UMyModLibrary::GetLangFn UMyModLibrary::pGetLang = nullptr;
UMyModLibrary::ScaleSpeedFn UMyModLibrary::pScaleSpeed = nullptr;

bool UMyModLibrary::LoadMyModDLL()
{
    if (DllHandle)
        return true;

#if PLATFORM_WINDOWS
    const FString DLLPath = FPaths::Combine(
        FPaths::ProjectDir(),
        TEXT("Binaries/Win64/MyMod.dll")
    );

    DllHandle = FPlatformProcess::GetDllHandle(*DLLPath);

    if (!DllHandle)
        return false;

    pSetLang = reinterpret_cast<SetLangFn>(
        FPlatformProcess::GetDllExport(DllHandle, TEXT("SetPreferredLanguage"))
        );

    pGetLang = reinterpret_cast<GetLangFn>(
        FPlatformProcess::GetDllExport(DllHandle, TEXT("GetPreferredLanguage"))
        );

    pScaleSpeed = reinterpret_cast<ScaleSpeedFn>(
        FPlatformProcess::GetDllExport(DllHandle, TEXT("ScaleSpeed"))
        );

    if (!pSetLang || !pGetLang || !pScaleSpeed)
    {
        FPlatformProcess::FreeDllHandle(DllHandle);
        DllHandle = nullptr;
        return false;
    }

    return true;
#else
    return false;
#endif
}

void UMyModLibrary::SetPreferredLanguageBP(const FString& LangCode)
{
    if (!DllHandle && !LoadMyModDLL())
        return;

    std::string Language = TCHAR_TO_ANSI(*LangCode);
    pSetLang(Language.c_str());
}

FString UMyModLibrary::GetPreferredLanguageBP()
{
    if (!DllHandle && !LoadMyModDLL())
        return TEXT("en");

    const char* Language = pGetLang();
    return FString(ANSI_TO_TCHAR(Language ? Language : "en"));
}

float UMyModLibrary::ScaleSpeedBP(float BaseSpeed, float Multiplier)
{
    if (!DllHandle && !LoadMyModDLL())
        return BaseSpeed * Multiplier;

    return pScaleSpeed(BaseSpeed, Multiplier);
}
