// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef REAPER_Terminal_generated_h
#error "Terminal.generated.h already included, missing '#pragma once' in Terminal.h"
#endif
#define REAPER_Terminal_generated_h

#define Reaper_Source_Reaper_Terminal_h_8_DELEGATE \
struct _Script_Reaper_eventTextUpdateSignature_Parms \
{ \
	FString Text; \
}; \
static inline void FTextUpdateSignature_DelegateWrapper(const FMulticastScriptDelegate& TextUpdateSignature, const FString& Text) \
{ \
	_Script_Reaper_eventTextUpdateSignature_Parms Parms; \
	Parms.Text=Text; \
	TextUpdateSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define Reaper_Source_Reaper_Terminal_h_16_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execDeactivateTerminal) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->DeactivateTerminal(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execActivateTerminal) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ActivateTerminal(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetScreenText) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetScreenText(); \
		P_NATIVE_END; \
	}


#define Reaper_Source_Reaper_Terminal_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execDeactivateTerminal) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->DeactivateTerminal(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execActivateTerminal) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ActivateTerminal(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetScreenText) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetScreenText(); \
		P_NATIVE_END; \
	}


#define Reaper_Source_Reaper_Terminal_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUTerminal(); \
	friend struct Z_Construct_UClass_UTerminal_Statics; \
public: \
	DECLARE_CLASS(UTerminal, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Reaper"), NO_API) \
	DECLARE_SERIALIZER(UTerminal)


#define Reaper_Source_Reaper_Terminal_h_16_INCLASS \
private: \
	static void StaticRegisterNativesUTerminal(); \
	friend struct Z_Construct_UClass_UTerminal_Statics; \
public: \
	DECLARE_CLASS(UTerminal, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Reaper"), NO_API) \
	DECLARE_SERIALIZER(UTerminal)


#define Reaper_Source_Reaper_Terminal_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UTerminal(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UTerminal) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UTerminal); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UTerminal); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UTerminal(UTerminal&&); \
	NO_API UTerminal(const UTerminal&); \
public:


#define Reaper_Source_Reaper_Terminal_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UTerminal(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UTerminal(UTerminal&&); \
	NO_API UTerminal(const UTerminal&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UTerminal); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UTerminal); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UTerminal)


#define Reaper_Source_Reaper_Terminal_h_16_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__MaxLines() { return STRUCT_OFFSET(UTerminal, MaxLines); } \
	FORCEINLINE static uint32 __PPO__MaxColumns() { return STRUCT_OFFSET(UTerminal, MaxColumns); }


#define Reaper_Source_Reaper_Terminal_h_13_PROLOG
#define Reaper_Source_Reaper_Terminal_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Reaper_Source_Reaper_Terminal_h_16_PRIVATE_PROPERTY_OFFSET \
	Reaper_Source_Reaper_Terminal_h_16_RPC_WRAPPERS \
	Reaper_Source_Reaper_Terminal_h_16_INCLASS \
	Reaper_Source_Reaper_Terminal_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Reaper_Source_Reaper_Terminal_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Reaper_Source_Reaper_Terminal_h_16_PRIVATE_PROPERTY_OFFSET \
	Reaper_Source_Reaper_Terminal_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	Reaper_Source_Reaper_Terminal_h_16_INCLASS_NO_PURE_DECLS \
	Reaper_Source_Reaper_Terminal_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> REAPER_API UClass* StaticClass<class UTerminal>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Reaper_Source_Reaper_Terminal_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
