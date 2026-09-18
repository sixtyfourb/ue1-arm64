/*=============================================================================
	UnV69Classes.h: Classes that package version 69 (OldUnreal 469) declares
	native but version 68 (436-era) declared as plain script classes.

	469 only moved the `native` keyword onto these; their properties are
	unchanged.  The C++ side needs a registered class whose autoclassAXxx
	export the loader can bind to, and members laid out exactly as
	UStruct::Link lays out the script ones - GCC_PACK(4) because the base
	class ends on a 4-byte boundary that C++ would otherwise pad past.

	Harmless against version 68 packages too -- a class that registers here
	but loads from a .u that never flagged it native simply keeps the
	constructor registration already gave it.
=============================================================================*/

#ifndef _UNV69CLASSES_H_
#define _UNV69CLASSES_H_

class ENGINE_API APickup : public AInventory
{
public:
	class AInventory* Inv GCC_PACK(4);
	INT NumCopies;
	BITFIELD bCanHaveMultipleCopies:1 GCC_PACK(4);
	BITFIELD bCanActivate:1;
	FString ExpireMessage GCC_PACK(4);
	BITFIELD bAutoActivate:1 GCC_PACK(4);
	DECLARE_CLASS(APickup,AInventory,0)
	NO_DEFAULT_CONSTRUCTOR(APickup)
};

class ENGINE_API AAmmo : public APickup
{
public:
	INT AmmoAmount GCC_PACK(4);
	INT MaxAmmo;
	// Packed so the class as a whole aligns to 4, not 8: script rounds Ammo's
	// size to 1052 and an 8-aligned C++ class would pad to 1056.
	class UClass* ParentAmmo GCC_PACK(4);
	BYTE UsedInWeaponSlot[10];
	class AAmmo* PAmmo GCC_PACK(4);
	DECLARE_CLASS(AAmmo,APickup,0)
	NO_DEFAULT_CONSTRUCTOR(AAmmo)
};

class ENGINE_API AClipMarker : public AKeypoint
{
public:
	DECLARE_CLASS(AClipMarker,AKeypoint,0)
	NO_DEFAULT_CONSTRUCTOR(AClipMarker)
};

#endif
