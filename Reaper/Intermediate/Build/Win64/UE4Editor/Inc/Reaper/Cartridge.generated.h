// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef REAPER_Cartridge_generated_h
#error "Cartridge.generated.h already included, missing '#pragma once' in Cartridge.h"
#endif
#define REAPER_Cartridge_generated_h

#define Reaper_Source_Reaper_Cartridge_h_13_RPC_WRAPPERS
#define Reaper_Source_Reaper_Cartridge_h_13_RPC_WRAPPERS_NO_PURE_DECLS
#define Reaper_Source_Reaper_Cartridge_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCartridge(); \
	friend struct Z_Construct_UClass_UCartridge_Statics; \
public: \
	DECLARE_CLASS(UCartridge, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Reaper"), NO_API) \
	DECLARE_SERIALIZER(UCartridge)


#define Reaper_Source_Reaper_Cartridge_h_13_INCLASS \
private: \
	static void StaticRegisterNativesUCartridge(); \
	friend struct Z_Construct_UClass_UCartridge_Statics; \
public: \
	DECLARE_CLASS(UCartridge, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Reaper"), NO_API) \
	DECLARE_SERIALIZER(UCartridge)


#define Reaper_Source_Reaper_Cartridge_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCartridge(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCartridge) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCartridge); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCartridge); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCartridge(UCartridge&&); \
	NO_API UCartridge(const UCartridge&); \
public:


#define Reaper_Source_Reaper_Cartridge_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCartridge(UCartridge&&); \
	NO_API UCartridge(const UCartridge&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCartridge); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCartridge); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCartridge)


#define Reaper_Source_Reaper_Cartridge_h_13_PRIVATE_PROPERTY_OFFSET
#define Reaper_Source_Reaper_Cartridge_h_10_PROLOG
#define Reaper_Source_Reaper_Cartridge_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Reaper_Source_Reaper_Cartridge_h_13_PRIVATE_PROPERTY_OFFSET \
	Reaper_Source_Reaper_Cartridge_h_13_RPC_WRAPPERS \
	Reaper_Source_Reaper_Cartridge_h_13_INCLASS \
	Reaper_Source_Reaper_Cartridge_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Reaper_Source_Reaper_Cartridge_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Reaper_Source_Reaper_Cartridge_h_13_PRIVATE_PROPERTY_OFFSET \
	Reaper_Source_Reaper_Cartridge_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	Reaper_Source_Reaper_Cartridge_h_13_INCLASS_NO_PURE_DECLS \
	Reaper_Source_Reaper_Cartridge_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> REAPER_API UClass* StaticClass<class UCartridge>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Reaper_Source_Reaper_Cartridge_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
