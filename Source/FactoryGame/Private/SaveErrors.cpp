// This file has been automatically generated by the Unreal Header Implementation tool

#include "SaveErrors.h"

void FSaveErrors::AddUnknownClass(const FString& unknowClass){ }
void FSaveErrors::AddUnknownLevel(const FString& unknownLevel){ }
void FSaveErrors::AddUnknownObject(const FObjectReferenceDisc& unknownReference){ }
void FSaveErrors::DumpSaveErrors(){ }
void FSaveErrors::SetCurrentLoadLevel( ULevel* level){ }
bool FSaveErrors::IsAnyErrorsOnDisc(){ return bool(); }
void FSaveErrors::GetErrorsFromDisc(FErrors& out_errors){ }
void FSaveErrors::SetSaveErrors(const FErrors& errors, bool save){ }
FString FSaveErrors::GetSaveErrorDirectory(){ return FString(); }
FString FSaveErrors::GetSaveErrorFileName(){ return FString(); }
void FSaveErrors::DumpErrorsToFile(){ }
FErrors FSaveErrors::Errors = FErrors();
FString FSaveErrors::CurrentLevel = FString();
