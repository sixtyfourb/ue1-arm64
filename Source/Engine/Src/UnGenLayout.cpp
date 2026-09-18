/*=============================================================================
	Generated: every native class member pinned to the offset UStruct::Link
	gives its script property.

	The engine compares whole class sizes and never individual offsets, so a
	member in the wrong place is never reported - it just reads the wrong
	field. These are computed straight from the game's packages by
	scripts/ue1-layout.py, which is also what regenerates this file.
=============================================================================*/

#include "EnginePrivate.h"

// Bitfields are left out: they share a word, and offsetof cannot name them.
// A mismatch surfaces as an incomplete CppOffset<actual,expected>, because
// static_assert can only carry a string - it names the member, and the
// template carries the arithmetic.
template< int Actual, int Expected > struct CppOffset;
template< int Same > struct CppOffset<Same,Same> { typedef int Matches; };

#define checkOffset(cls,member,off) \
	static_assert( __builtin_offsetof(cls,member)==off, \
		#cls "::" #member " is not where the game's packages put it" ); \
	(void)sizeof( CppOffset< (int)__builtin_offsetof(cls,member), off >::Matches )

static void GeneratedLayoutChecks()
{
	// Actor: PropertiesSize 652
	checkOffset( AActor, Physics, 68 );                          // ByteProperty
	checkOffset( AActor, Role, 69 );                             // ByteProperty
	checkOffset( AActor, RemoteRole, 70 );                       // ByteProperty
	checkOffset( AActor, Owner, 72 );                            // ObjectProperty
	checkOffset( AActor, InitialState, 80 );                     // NameProperty
	checkOffset( AActor, Group, 84 );                            // NameProperty
	checkOffset( AActor, TimerRate, 88 );                        // FloatProperty
	checkOffset( AActor, TimerCounter, 92 );                     // FloatProperty
	checkOffset( AActor, LifeSpan, 96 );                         // FloatProperty
	checkOffset( AActor, AnimSequence, 100 );                    // NameProperty
	checkOffset( AActor, AnimFrame, 104 );                       // FloatProperty
	checkOffset( AActor, AnimRate, 108 );                        // FloatProperty
	checkOffset( AActor, TweenRate, 112 );                       // FloatProperty
	checkOffset( AActor, Level, 116 );                           // ObjectProperty
	checkOffset( AActor, XLevel, 124 );                          // ObjectProperty
	checkOffset( AActor, Tag, 132 );                             // NameProperty
	checkOffset( AActor, Event, 136 );                           // NameProperty
	checkOffset( AActor, Target, 140 );                          // ObjectProperty
	checkOffset( AActor, Instigator, 148 );                      // ObjectProperty
	checkOffset( AActor, Inventory, 156 );                       // ObjectProperty
	checkOffset( AActor, Base, 164 );                            // ObjectProperty
	checkOffset( AActor, Region, 172 );                          // StructProperty
	checkOffset( AActor, AttachTag, 188 );                       // NameProperty
	checkOffset( AActor, StandingCount, 192 );                   // ByteProperty
	checkOffset( AActor, MiscNumber, 193 );                      // ByteProperty
	checkOffset( AActor, LatentByte, 194 );                      // ByteProperty
	checkOffset( AActor, LatentInt, 196 );                       // IntProperty
	checkOffset( AActor, LatentFloat, 200 );                     // FloatProperty
	checkOffset( AActor, LatentActor, 204 );                     // ObjectProperty
	checkOffset( AActor, Touching, 212 );                        // ObjectProperty
	checkOffset( AActor, Deleted, 244 );                         // ObjectProperty
	checkOffset( AActor, CollisionTag, 252 );                    // IntProperty
	checkOffset( AActor, LightingTag, 256 );                     // IntProperty
	checkOffset( AActor, NetTag, 260 );                          // IntProperty
	checkOffset( AActor, OtherTag, 264 );                        // IntProperty
	checkOffset( AActor, ExtraTag, 268 );                        // IntProperty
	checkOffset( AActor, SpecialTag, 272 );                      // IntProperty
	checkOffset( AActor, Location, 276 );                        // StructProperty
	checkOffset( AActor, Rotation, 288 );                        // StructProperty
	checkOffset( AActor, OldLocation, 300 );                     // StructProperty
	checkOffset( AActor, ColLocation, 312 );                     // StructProperty
	checkOffset( AActor, Velocity, 324 );                        // StructProperty
	checkOffset( AActor, Acceleration, 336 );                    // StructProperty
	checkOffset( AActor, OddsOfAppearing, 352 );                 // FloatProperty
	checkOffset( AActor, DrawType, 356 );                        // ByteProperty
	checkOffset( AActor, Style, 357 );                           // ByteProperty
	checkOffset( AActor, Sprite, 360 );                          // ObjectProperty
	checkOffset( AActor, Texture, 368 );                         // ObjectProperty
	checkOffset( AActor, Skin, 376 );                            // ObjectProperty
	checkOffset( AActor, Mesh, 384 );                            // ObjectProperty
	checkOffset( AActor, Brush, 392 );                           // ObjectProperty
	checkOffset( AActor, DrawScale, 400 );                       // FloatProperty
	checkOffset( AActor, PrePivot, 404 );                        // StructProperty
	checkOffset( AActor, ScaleGlow, 416 );                       // FloatProperty
	checkOffset( AActor, AmbientGlow, 420 );                     // ByteProperty
	checkOffset( AActor, Fatness, 421 );                         // ByteProperty
	checkOffset( AActor, VisibilityRadius, 428 );                // FloatProperty
	checkOffset( AActor, VisibilityHeight, 432 );                // FloatProperty
	checkOffset( AActor, MultiSkins, 440 );                      // ObjectProperty
	checkOffset( AActor, SoundRadius, 504 );                     // ByteProperty
	checkOffset( AActor, SoundVolume, 505 );                     // ByteProperty
	checkOffset( AActor, SoundPitch, 506 );                      // ByteProperty
	checkOffset( AActor, AmbientSound, 508 );                    // ObjectProperty
	checkOffset( AActor, TransientSoundVolume, 516 );            // FloatProperty
	checkOffset( AActor, TransientSoundRadius, 520 );            // FloatProperty
	checkOffset( AActor, CollisionRadius, 524 );                 // FloatProperty
	checkOffset( AActor, CollisionHeight, 528 );                 // FloatProperty
	checkOffset( AActor, LightType, 536 );                       // ByteProperty
	checkOffset( AActor, LightEffect, 537 );                     // ByteProperty
	checkOffset( AActor, LightBrightness, 538 );                 // ByteProperty
	checkOffset( AActor, LightHue, 539 );                        // ByteProperty
	checkOffset( AActor, LightSaturation, 540 );                 // ByteProperty
	checkOffset( AActor, LightRadius, 541 );                     // ByteProperty
	checkOffset( AActor, LightPeriod, 542 );                     // ByteProperty
	checkOffset( AActor, LightPhase, 543 );                      // ByteProperty
	checkOffset( AActor, LightCone, 544 );                       // ByteProperty
	checkOffset( AActor, VolumeBrightness, 545 );                // ByteProperty
	checkOffset( AActor, VolumeRadius, 546 );                    // ByteProperty
	checkOffset( AActor, VolumeFog, 547 );                       // ByteProperty
	checkOffset( AActor, DodgeDir, 552 );                        // ByteProperty
	checkOffset( AActor, Mass, 556 );                            // FloatProperty
	checkOffset( AActor, Buoyancy, 560 );                        // FloatProperty
	checkOffset( AActor, RotationRate, 564 );                    // StructProperty
	checkOffset( AActor, DesiredRotation, 576 );                 // StructProperty
	checkOffset( AActor, PhysAlpha, 588 );                       // FloatProperty
	checkOffset( AActor, PhysRate, 592 );                        // FloatProperty
	checkOffset( AActor, AnimLast, 596 );                        // FloatProperty
	checkOffset( AActor, AnimMinRate, 600 );                     // FloatProperty
	checkOffset( AActor, OldAnimRate, 604 );                     // FloatProperty
	checkOffset( AActor, SimAnim, 608 );                         // StructProperty
	checkOffset( AActor, NetPriority, 624 );                     // FloatProperty
	checkOffset( AActor, NetUpdateFrequency, 628 );              // FloatProperty
	checkOffset( AActor, RenderIteratorClass, 636 );             // ClassProperty
	checkOffset( AActor, RenderInterface, 644 );                 // ObjectProperty

	// Pawn: PropertiesSize 1360
	checkOffset( APawn, SightCounter, 656 );                     // FloatProperty
	checkOffset( APawn, PainTime, 660 );                         // FloatProperty
	checkOffset( APawn, SpeechTime, 664 );                       // FloatProperty
	checkOffset( APawn, AvgPhysicsTime, 668 );                   // FloatProperty
	checkOffset( APawn, FootRegion, 672 );                       // StructProperty
	checkOffset( APawn, HeadRegion, 688 );                       // StructProperty
	checkOffset( APawn, MoveTimer, 704 );                        // FloatProperty
	checkOffset( APawn, MoveTarget, 708 );                       // ObjectProperty
	checkOffset( APawn, FaceTarget, 716 );                       // ObjectProperty
	checkOffset( APawn, Destination, 724 );                      // StructProperty
	checkOffset( APawn, Focus, 736 );                            // StructProperty
	checkOffset( APawn, DesiredSpeed, 748 );                     // FloatProperty
	checkOffset( APawn, MaxDesiredSpeed, 752 );                  // FloatProperty
	checkOffset( APawn, MeleeRange, 756 );                       // FloatProperty
	checkOffset( APawn, GroundSpeed, 760 );                      // FloatProperty
	checkOffset( APawn, WaterSpeed, 764 );                       // FloatProperty
	checkOffset( APawn, AirSpeed, 768 );                         // FloatProperty
	checkOffset( APawn, AccelRate, 772 );                        // FloatProperty
	checkOffset( APawn, JumpZ, 776 );                            // FloatProperty
	checkOffset( APawn, MaxStepHeight, 780 );                    // FloatProperty
	checkOffset( APawn, AirControl, 784 );                       // FloatProperty
	checkOffset( APawn, MinHitWall, 788 );                       // FloatProperty
	checkOffset( APawn, Visibility, 792 );                       // ByteProperty
	checkOffset( APawn, Alertness, 796 );                        // FloatProperty
	checkOffset( APawn, Stimulus, 800 );                         // FloatProperty
	checkOffset( APawn, SightRadius, 804 );                      // FloatProperty
	checkOffset( APawn, PeripheralVision, 808 );                 // FloatProperty
	checkOffset( APawn, HearingThreshold, 812 );                 // FloatProperty
	checkOffset( APawn, LastSeenPos, 816 );                      // StructProperty
	checkOffset( APawn, LastSeeingPos, 828 );                    // StructProperty
	checkOffset( APawn, LastSeenTime, 840 );                     // FloatProperty
	checkOffset( APawn, Enemy, 844 );                            // ObjectProperty
	checkOffset( APawn, Weapon, 852 );                           // ObjectProperty
	checkOffset( APawn, PendingWeapon, 860 );                    // ObjectProperty
	checkOffset( APawn, SelectedItem, 868 );                     // ObjectProperty
	checkOffset( APawn, ViewRotation, 876 );                     // StructProperty
	checkOffset( APawn, WalkBob, 888 );                          // StructProperty
	checkOffset( APawn, BaseEyeHeight, 900 );                    // FloatProperty
	checkOffset( APawn, EyeHeight, 904 );                        // FloatProperty
	checkOffset( APawn, Floor, 908 );                            // StructProperty
	checkOffset( APawn, SplashTime, 920 );                       // FloatProperty
	checkOffset( APawn, OrthoZoom, 924 );                        // FloatProperty
	checkOffset( APawn, FovAngle, 928 );                         // FloatProperty
	checkOffset( APawn, DieCount, 932 );                         // IntProperty
	checkOffset( APawn, ItemCount, 936 );                        // IntProperty
	checkOffset( APawn, KillCount, 940 );                        // IntProperty
	checkOffset( APawn, SecretCount, 944 );                      // IntProperty
	checkOffset( APawn, Spree, 948 );                            // IntProperty
	checkOffset( APawn, Health, 952 );                           // IntProperty
	checkOffset( APawn, ReducedDamageType, 956 );                // NameProperty
	checkOffset( APawn, ReducedDamagePct, 960 );                 // FloatProperty
	checkOffset( APawn, DropWhenKilled, 964 );                   // ClassProperty
	checkOffset( APawn, UnderWaterTime, 972 );                   // FloatProperty
	checkOffset( APawn, AttitudeToPlayer, 976 );                 // ByteProperty
	checkOffset( APawn, Intelligence, 977 );                     // ByteProperty
	checkOffset( APawn, Skill, 980 );                            // FloatProperty
	checkOffset( APawn, SpecialGoal, 984 );                      // ObjectProperty
	checkOffset( APawn, SpecialPause, 992 );                     // FloatProperty
	checkOffset( APawn, noise1spot, 996 );                       // StructProperty
	checkOffset( APawn, noise1time, 1008 );                      // FloatProperty
	checkOffset( APawn, noise1other, 1012 );                     // ObjectProperty
	checkOffset( APawn, noise1loudness, 1020 );                  // FloatProperty
	checkOffset( APawn, noise2spot, 1024 );                      // StructProperty
	checkOffset( APawn, noise2time, 1036 );                      // FloatProperty
	checkOffset( APawn, noise2other, 1040 );                     // ObjectProperty
	checkOffset( APawn, noise2loudness, 1048 );                  // FloatProperty
	checkOffset( APawn, LastPainSound, 1052 );                   // FloatProperty
	checkOffset( APawn, nextPawn, 1056 );                        // ObjectProperty
	checkOffset( APawn, HitSound1, 1064 );                       // ObjectProperty
	checkOffset( APawn, HitSound2, 1072 );                       // ObjectProperty
	checkOffset( APawn, Land, 1080 );                            // ObjectProperty
	checkOffset( APawn, Die, 1088 );                             // ObjectProperty
	checkOffset( APawn, WaterStep, 1096 );                       // ObjectProperty
	checkOffset( APawn, bZoom, 1104 );                           // ByteProperty
	checkOffset( APawn, bRun, 1105 );                            // ByteProperty
	checkOffset( APawn, bLook, 1106 );                           // ByteProperty
	checkOffset( APawn, bDuck, 1107 );                           // ByteProperty
	checkOffset( APawn, bSnapLevel, 1108 );                      // ByteProperty
	checkOffset( APawn, bStrafe, 1109 );                         // ByteProperty
	checkOffset( APawn, bFire, 1110 );                           // ByteProperty
	checkOffset( APawn, bAltFire, 1111 );                        // ByteProperty
	checkOffset( APawn, bFreeLook, 1112 );                       // ByteProperty
	checkOffset( APawn, bExtra0, 1113 );                         // ByteProperty
	checkOffset( APawn, bExtra1, 1114 );                         // ByteProperty
	checkOffset( APawn, bExtra2, 1115 );                         // ByteProperty
	checkOffset( APawn, bExtra3, 1116 );                         // ByteProperty
	checkOffset( APawn, CombatStyle, 1120 );                     // FloatProperty
	checkOffset( APawn, home, 1124 );                            // ObjectProperty
	checkOffset( APawn, NextState, 1132 );                       // NameProperty
	checkOffset( APawn, NextLabel, 1136 );                       // NameProperty
	checkOffset( APawn, SoundDampening, 1140 );                  // FloatProperty
	checkOffset( APawn, DamageScaling, 1144 );                   // FloatProperty
	checkOffset( APawn, AlarmTag, 1148 );                        // NameProperty
	checkOffset( APawn, SharedAlarmTag, 1152 );                  // NameProperty
	checkOffset( APawn, carriedDecoration, 1156 );               // ObjectProperty
	checkOffset( APawn, PlayerReStartState, 1164 );              // NameProperty
	checkOffset( APawn, MenuName, 1168 );                        // StrProperty
	checkOffset( APawn, NameArticle, 1184 );                     // StrProperty
	checkOffset( APawn, VoicePitch, 1200 );                      // ByteProperty
	checkOffset( APawn, VoiceType, 1204 );                       // ClassProperty
	checkOffset( APawn, OldMessageTime, 1212 );                  // FloatProperty
	checkOffset( APawn, RouteCache, 1216 );                      // ObjectProperty
	checkOffset( APawn, PlayerReplicationInfoClass, 1344 );      // ClassProperty
	checkOffset( APawn, PlayerReplicationInfo, 1352 );           // ObjectProperty

	// PlayerPawn: PropertiesSize 2084
	checkOffset( APlayerPawn, Player, 1360 );                    // ObjectProperty
	checkOffset( APlayerPawn, Password, 1368 );                  // StrProperty
	checkOffset( APlayerPawn, DodgeClickTimer, 1384 );           // FloatProperty
	checkOffset( APlayerPawn, DodgeClickTime, 1388 );            // FloatProperty
	checkOffset( APlayerPawn, Bob, 1392 );                       // FloatProperty
	checkOffset( APlayerPawn, bobtime, 1396 );                   // FloatProperty
	checkOffset( APlayerPawn, ShowFlags, 1400 );                 // IntProperty
	checkOffset( APlayerPawn, RendMap, 1404 );                   // IntProperty
	checkOffset( APlayerPawn, Misc1, 1408 );                     // IntProperty
	checkOffset( APlayerPawn, Misc2, 1412 );                     // IntProperty
	checkOffset( APlayerPawn, ViewTarget, 1416 );                // ObjectProperty
	checkOffset( APlayerPawn, FlashScale, 1424 );                // StructProperty
	checkOffset( APlayerPawn, FlashFog, 1436 );                  // StructProperty
	checkOffset( APlayerPawn, myHUD, 1448 );                     // ObjectProperty
	checkOffset( APlayerPawn, Scoring, 1456 );                   // ObjectProperty
	checkOffset( APlayerPawn, HUDType, 1464 );                   // ClassProperty
	checkOffset( APlayerPawn, ScoringType, 1472 );               // ClassProperty
	checkOffset( APlayerPawn, DesiredFlashScale, 1480 );         // FloatProperty
	checkOffset( APlayerPawn, ConstantGlowScale, 1484 );         // FloatProperty
	checkOffset( APlayerPawn, InstantFlash, 1488 );              // FloatProperty
	checkOffset( APlayerPawn, DesiredFlashFog, 1492 );           // StructProperty
	checkOffset( APlayerPawn, ConstantGlowFog, 1504 );           // StructProperty
	checkOffset( APlayerPawn, InstantFog, 1516 );                // StructProperty
	checkOffset( APlayerPawn, DesiredFOV, 1528 );                // FloatProperty
	checkOffset( APlayerPawn, DefaultFOV, 1532 );                // FloatProperty
	checkOffset( APlayerPawn, Song, 1536 );                      // ObjectProperty
	checkOffset( APlayerPawn, SongSection, 1544 );               // ByteProperty
	checkOffset( APlayerPawn, CdTrack, 1545 );                   // ByteProperty
	checkOffset( APlayerPawn, Transition, 1546 );                // ByteProperty
	checkOffset( APlayerPawn, shaketimer, 1548 );                // FloatProperty
	checkOffset( APlayerPawn, shakemag, 1552 );                  // IntProperty
	checkOffset( APlayerPawn, shakevert, 1556 );                 // FloatProperty
	checkOffset( APlayerPawn, maxshake, 1560 );                  // FloatProperty
	checkOffset( APlayerPawn, verttimer, 1564 );                 // FloatProperty
	checkOffset( APlayerPawn, CarcassType, 1568 );               // ClassProperty
	checkOffset( APlayerPawn, MyAutoAim, 1576 );                 // FloatProperty
	checkOffset( APlayerPawn, Handedness, 1580 );                // FloatProperty
	checkOffset( APlayerPawn, JumpSound, 1584 );                 // ObjectProperty
	checkOffset( APlayerPawn, ZoomLevel, 1600 );                 // FloatProperty
	checkOffset( APlayerPawn, SpecialMenu, 1604 );               // ClassProperty
	checkOffset( APlayerPawn, DelayedCommand, 1612 );            // StrProperty
	checkOffset( APlayerPawn, MouseSensitivity, 1628 );          // FloatProperty
	checkOffset( APlayerPawn, WeaponPriority, 1632 );            // NameProperty
	checkOffset( APlayerPawn, NetSpeed, 1712 );                  // IntProperty
	checkOffset( APlayerPawn, LanSpeed, 1716 );                  // IntProperty
	checkOffset( APlayerPawn, SmoothMouseX, 1720 );              // FloatProperty
	checkOffset( APlayerPawn, SmoothMouseY, 1724 );              // FloatProperty
	checkOffset( APlayerPawn, KbdAccel, 1728 );                  // FloatProperty
	checkOffset( APlayerPawn, MouseSmoothThreshold, 1732 );      // FloatProperty
	checkOffset( APlayerPawn, aBaseX, 1736 );                    // FloatProperty
	checkOffset( APlayerPawn, aBaseY, 1740 );                    // FloatProperty
	checkOffset( APlayerPawn, aBaseZ, 1744 );                    // FloatProperty
	checkOffset( APlayerPawn, aMouseX, 1748 );                   // FloatProperty
	checkOffset( APlayerPawn, aMouseY, 1752 );                   // FloatProperty
	checkOffset( APlayerPawn, aForward, 1756 );                  // FloatProperty
	checkOffset( APlayerPawn, aTurn, 1760 );                     // FloatProperty
	checkOffset( APlayerPawn, aStrafe, 1764 );                   // FloatProperty
	checkOffset( APlayerPawn, aUp, 1768 );                       // FloatProperty
	checkOffset( APlayerPawn, aLookUp, 1772 );                   // FloatProperty
	checkOffset( APlayerPawn, aExtra4, 1776 );                   // FloatProperty
	checkOffset( APlayerPawn, aExtra3, 1780 );                   // FloatProperty
	checkOffset( APlayerPawn, aExtra2, 1784 );                   // FloatProperty
	checkOffset( APlayerPawn, aExtra1, 1788 );                   // FloatProperty
	checkOffset( APlayerPawn, aExtra0, 1792 );                   // FloatProperty
	checkOffset( APlayerPawn, SavedMoves, 1796 );                // ObjectProperty
	checkOffset( APlayerPawn, FreeMoves, 1804 );                 // ObjectProperty
	checkOffset( APlayerPawn, CurrentTimeStamp, 1812 );          // FloatProperty
	checkOffset( APlayerPawn, LastUpdateTime, 1816 );            // FloatProperty
	checkOffset( APlayerPawn, ServerTimeStamp, 1820 );           // FloatProperty
	checkOffset( APlayerPawn, TimeMargin, 1824 );                // FloatProperty
	checkOffset( APlayerPawn, MaxTimeMargin, 1828 );             // FloatProperty
	checkOffset( APlayerPawn, ProgressMessage, 1832 );           // StrProperty
	checkOffset( APlayerPawn, ProgressColor, 1912 );             // StructProperty
	checkOffset( APlayerPawn, ProgressTimeOut, 1932 );           // FloatProperty
	checkOffset( APlayerPawn, QuickSaveString, 1936 );           // StrProperty
	checkOffset( APlayerPawn, NoPauseMessage, 1952 );            // StrProperty
	checkOffset( APlayerPawn, ViewingFrom, 1968 );               // StrProperty
	checkOffset( APlayerPawn, OwnCamera, 1984 );                 // StrProperty
	checkOffset( APlayerPawn, FailedView, 2000 );                // StrProperty
	checkOffset( APlayerPawn, CantChangeNameMsg, 2016 );         // StrProperty
	checkOffset( APlayerPawn, GameReplicationInfo, 2032 );       // ObjectProperty
	checkOffset( APlayerPawn, ngWorldSecret, 2040 );             // StrProperty
	checkOffset( APlayerPawn, TargetViewRotation, 2056 );        // StructProperty
	checkOffset( APlayerPawn, TargetEyeHeight, 2068 );           // FloatProperty
	checkOffset( APlayerPawn, TargetWeaponViewOffset, 2072 );    // StructProperty

	// Brush: PropertiesSize 748
	checkOffset( ABrush, CsgOper, 652 );                         // ByteProperty
	checkOffset( ABrush, UnusedLightMesh, 656 );                 // ObjectProperty
	checkOffset( ABrush, PostPivot, 664 );                       // StructProperty
	checkOffset( ABrush, MainScale, 676 );                       // StructProperty
	checkOffset( ABrush, PostScale, 696 );                       // StructProperty
	checkOffset( ABrush, TempScale, 716 );                       // StructProperty
	checkOffset( ABrush, BrushColor, 736 );                      // StructProperty
	checkOffset( ABrush, PolyFlags, 740 );                       // IntProperty

	// Mover: PropertiesSize 1252
	checkOffset( AMover, MoverEncroachType, 748 );               // ByteProperty
	checkOffset( AMover, MoverGlideType, 749 );                  // ByteProperty
	checkOffset( AMover, BumpType, 750 );                        // ByteProperty
	checkOffset( AMover, KeyNum, 751 );                          // ByteProperty
	checkOffset( AMover, PrevKeyNum, 752 );                      // ByteProperty
	checkOffset( AMover, NumKeys, 753 );                         // ByteProperty
	checkOffset( AMover, WorldRaytraceKey, 754 );                // ByteProperty
	checkOffset( AMover, BrushRaytraceKey, 755 );                // ByteProperty
	checkOffset( AMover, MoveTime, 756 );                        // FloatProperty
	checkOffset( AMover, StayOpenTime, 760 );                    // FloatProperty
	checkOffset( AMover, OtherTime, 764 );                       // FloatProperty
	checkOffset( AMover, EncroachDamage, 768 );                  // IntProperty
	checkOffset( AMover, PlayerBumpEvent, 776 );                 // NameProperty
	checkOffset( AMover, BumpEvent, 780 );                       // NameProperty
	checkOffset( AMover, SavedTrigger, 784 );                    // ObjectProperty
	checkOffset( AMover, DamageThreshold, 792 );                 // FloatProperty
	checkOffset( AMover, numTriggerEvents, 796 );                // IntProperty
	checkOffset( AMover, Leader, 800 );                          // ObjectProperty
	checkOffset( AMover, Follower, 808 );                        // ObjectProperty
	checkOffset( AMover, ReturnGroup, 816 );                     // NameProperty
	checkOffset( AMover, DelayTime, 820 );                       // FloatProperty
	checkOffset( AMover, OpeningSound, 824 );                    // ObjectProperty
	checkOffset( AMover, OpenedSound, 832 );                     // ObjectProperty
	checkOffset( AMover, ClosingSound, 840 );                    // ObjectProperty
	checkOffset( AMover, ClosedSound, 848 );                     // ObjectProperty
	checkOffset( AMover, MoveAmbientSound, 856 );                // ObjectProperty
	checkOffset( AMover, KeyPos, 864 );                          // StructProperty
	checkOffset( AMover, KeyRot, 960 );                          // StructProperty
	checkOffset( AMover, BasePos, 1056 );                        // StructProperty
	checkOffset( AMover, OldPos, 1068 );                         // StructProperty
	checkOffset( AMover, OldPrePivot, 1080 );                    // StructProperty
	checkOffset( AMover, SavedPos, 1092 );                       // StructProperty
	checkOffset( AMover, BaseRot, 1104 );                        // StructProperty
	checkOffset( AMover, OldRot, 1116 );                         // StructProperty
	checkOffset( AMover, SavedRot, 1128 );                       // StructProperty
	checkOffset( AMover, myMarker, 1140 );                       // ObjectProperty
	checkOffset( AMover, TriggerActor, 1148 );                   // ObjectProperty
	checkOffset( AMover, TriggerActor2, 1156 );                  // ObjectProperty
	checkOffset( AMover, WaitingPawn, 1164 );                    // ObjectProperty
	checkOffset( AMover, RecommendedTrigger, 1176 );             // ObjectProperty
	checkOffset( AMover, SimOldPos, 1184 );                      // StructProperty
	checkOffset( AMover, SimOldRotPitch, 1196 );                 // IntProperty
	checkOffset( AMover, SimOldRotYaw, 1200 );                   // IntProperty
	checkOffset( AMover, SimOldRotRoll, 1204 );                  // IntProperty
	checkOffset( AMover, SimInterpolate, 1208 );                 // StructProperty
	checkOffset( AMover, RealPosition, 1220 );                   // StructProperty
	checkOffset( AMover, RealRotation, 1232 );                   // StructProperty
	checkOffset( AMover, ServerUpdate, 1244 );                   // IntProperty
	checkOffset( AMover, ClientUpdate, 1248 );                   // IntProperty

	// InterpolationPoint: PropertiesSize 704
	checkOffset( AInterpolationPoint, Position, 652 );           // IntProperty
	checkOffset( AInterpolationPoint, RateModifier, 656 );       // FloatProperty
	checkOffset( AInterpolationPoint, GameSpeedModifier, 660 );  // FloatProperty
	checkOffset( AInterpolationPoint, FovModifier, 664 );        // FloatProperty
	checkOffset( AInterpolationPoint, ScreenFlashScale, 672 );   // FloatProperty
	checkOffset( AInterpolationPoint, ScreenFlashFog, 676 );     // StructProperty
	checkOffset( AInterpolationPoint, Prev, 688 );               // ObjectProperty
	checkOffset( AInterpolationPoint, Next, 696 );               // ObjectProperty

	// GameReplicationInfo: PropertiesSize 832
	checkOffset( AGameReplicationInfo, GameName, 652 );          // StrProperty
	checkOffset( AGameReplicationInfo, RemainingTime, 672 );     // IntProperty
	checkOffset( AGameReplicationInfo, ElapsedTime, 676 );       // IntProperty
	checkOffset( AGameReplicationInfo, ServerName, 680 );        // StrProperty
	checkOffset( AGameReplicationInfo, ShortName, 696 );         // StrProperty
	checkOffset( AGameReplicationInfo, AdminName, 712 );         // StrProperty
	checkOffset( AGameReplicationInfo, AdminEmail, 728 );        // StrProperty
	checkOffset( AGameReplicationInfo, Region, 744 );            // IntProperty
	checkOffset( AGameReplicationInfo, MOTDLine1, 752 );         // StrProperty
	checkOffset( AGameReplicationInfo, MOTDLine2, 768 );         // StrProperty
	checkOffset( AGameReplicationInfo, MOTDLine3, 784 );         // StrProperty
	checkOffset( AGameReplicationInfo, MOTDLine4, 800 );         // StrProperty
	checkOffset( AGameReplicationInfo, GameEndedComments, 816 ); // StrProperty

	// PlayerReplicationInfo: PropertiesSize 744
	checkOffset( APlayerReplicationInfo, PlayerName, 652 );      // StrProperty
	checkOffset( APlayerReplicationInfo, PlayerID, 668 );        // IntProperty
	checkOffset( APlayerReplicationInfo, TeamName, 672 );        // StrProperty
	checkOffset( APlayerReplicationInfo, Team, 688 );            // ByteProperty
	checkOffset( APlayerReplicationInfo, TeamID, 692 );          // IntProperty
	checkOffset( APlayerReplicationInfo, Score, 696 );           // FloatProperty
	checkOffset( APlayerReplicationInfo, Spree, 700 );           // FloatProperty
	checkOffset( APlayerReplicationInfo, VoiceType, 704 );       // ClassProperty
	checkOffset( APlayerReplicationInfo, HasFlag, 712 );         // ObjectProperty
	checkOffset( APlayerReplicationInfo, Ping, 720 );            // IntProperty
	checkOffset( APlayerReplicationInfo, TalkTexture, 728 );     // ObjectProperty
	checkOffset( APlayerReplicationInfo, PlayerZone, 736 );      // ObjectProperty

	// StatLog: PropertiesSize 828
	checkOffset( AStatLog, Context, 652 );                       // IntProperty
	checkOffset( AStatLog, TimeStamp, 664 );                     // FloatProperty
	checkOffset( AStatLog, LocalStandard, 668 );                 // StrProperty
	checkOffset( AStatLog, WorldStandard, 684 );                 // StrProperty
	checkOffset( AStatLog, LogVersion, 700 );                    // StrProperty
	checkOffset( AStatLog, LogInfoURL, 716 );                    // StrProperty
	checkOffset( AStatLog, GameName, 732 );                      // StrProperty
	checkOffset( AStatLog, GameCreator, 748 );                   // StrProperty
	checkOffset( AStatLog, GameCreatorURL, 764 );                // StrProperty
	checkOffset( AStatLog, DecoderRingURL, 780 );                // StrProperty
	checkOffset( AStatLog, LocalLogDir, 796 );                   // StrProperty
	checkOffset( AStatLog, WorldLogDir, 812 );                   // StrProperty

	// StatLogFile: PropertiesSize 872
	checkOffset( AStatLogFile, LogAr, 832 );                     // IntProperty
	checkOffset( AStatLogFile, StatLogFile, 840 );               // StrProperty
	checkOffset( AStatLogFile, StatLogFinal, 856 );              // StrProperty

	// SavedMove: PropertiesSize 680
	checkOffset( ASavedMove, NextMove, 652 );                    // ObjectProperty
	checkOffset( ASavedMove, TimeStamp, 660 );                   // FloatProperty
	checkOffset( ASavedMove, Delta, 664 );                       // FloatProperty
	checkOffset( ASavedMove, DodgeMove, 672 );                   // ByteProperty

	// ZoneInfo: PropertiesSize 1140
	checkOffset( AZoneInfo, ZoneTag, 652 );                      // NameProperty
	checkOffset( AZoneInfo, ZoneGravity, 656 );                  // StructProperty
	checkOffset( AZoneInfo, ZoneVelocity, 668 );                 // StructProperty
	checkOffset( AZoneInfo, ZoneGroundFriction, 680 );           // FloatProperty
	checkOffset( AZoneInfo, ZoneFluidFriction, 684 );            // FloatProperty
	checkOffset( AZoneInfo, ZoneTerminalVelocity, 688 );         // FloatProperty
	checkOffset( AZoneInfo, ZonePlayerEvent, 692 );              // NameProperty
	checkOffset( AZoneInfo, ZonePlayerCount, 696 );              // IntProperty
	checkOffset( AZoneInfo, NumCarcasses, 700 );                 // IntProperty
	checkOffset( AZoneInfo, DamagePerSec, 704 );                 // IntProperty
	checkOffset( AZoneInfo, DamageType, 708 );                   // NameProperty
	checkOffset( AZoneInfo, DamageString, 712 );                 // StrProperty
	checkOffset( AZoneInfo, ZoneName, 728 );                     // StrProperty
	checkOffset( AZoneInfo, LocationStrings, 744 );              // StrProperty
	checkOffset( AZoneInfo, MaxCarcasses, 808 );                 // IntProperty
	checkOffset( AZoneInfo, EntrySound, 812 );                   // ObjectProperty
	checkOffset( AZoneInfo, ExitSound, 820 );                    // ObjectProperty
	checkOffset( AZoneInfo, EntryActor, 828 );                   // ClassProperty
	checkOffset( AZoneInfo, ExitActor, 836 );                    // ClassProperty
	checkOffset( AZoneInfo, SkyZone, 844 );                      // ObjectProperty
	checkOffset( AZoneInfo, AmbientBrightness, 856 );            // ByteProperty
	checkOffset( AZoneInfo, AmbientHue, 857 );                   // ByteProperty
	checkOffset( AZoneInfo, AmbientSaturation, 858 );            // ByteProperty
	checkOffset( AZoneInfo, FogColor, 860 );                     // StructProperty
	checkOffset( AZoneInfo, FogDistance, 864 );                  // FloatProperty
	checkOffset( AZoneInfo, EnvironmentMap, 868 );               // ObjectProperty
	checkOffset( AZoneInfo, TexUPanSpeed, 876 );                 // FloatProperty
	checkOffset( AZoneInfo, TexVPanSpeed, 880 );                 // FloatProperty
	checkOffset( AZoneInfo, ViewFlash, 884 );                    // StructProperty
	checkOffset( AZoneInfo, ViewFog, 896 );                      // StructProperty
	checkOffset( AZoneInfo, SpeedOfSound, 912 );                 // FloatProperty
	checkOffset( AZoneInfo, MasterGain, 916 );                   // ByteProperty
	checkOffset( AZoneInfo, CutoffHz, 920 );                     // IntProperty
	checkOffset( AZoneInfo, Delay, 924 );                        // ByteProperty
	checkOffset( AZoneInfo, Gain, 930 );                         // ByteProperty
	checkOffset( AZoneInfo, LensFlare, 936 );                    // ObjectProperty
	checkOffset( AZoneInfo, LensFlareOffset, 1032 );             // FloatProperty
	checkOffset( AZoneInfo, LensFlareScale, 1080 );              // FloatProperty
	checkOffset( AZoneInfo, MinLightCount, 1128 );               // ByteProperty
	checkOffset( AZoneInfo, MaxLightCount, 1129 );               // ByteProperty
	checkOffset( AZoneInfo, MinLightingPolyCount, 1132 );        // IntProperty
	checkOffset( AZoneInfo, MaxLightingPolyCount, 1136 );        // IntProperty

	// WarpZoneInfo: PropertiesSize 1364
	checkOffset( AWarpZoneInfo, OtherSideURL, 1140 );            // StrProperty
	checkOffset( AWarpZoneInfo, ThisTag, 1156 );                 // NameProperty
	checkOffset( AWarpZoneInfo, iWarpZone, 1164 );               // IntProperty
	checkOffset( AWarpZoneInfo, WarpCoords, 1168 );              // StructProperty
	checkOffset( AWarpZoneInfo, OtherSideActor, 1216 );          // ObjectProperty
	checkOffset( AWarpZoneInfo, OtherSideLevel, 1224 );          // ObjectProperty
	checkOffset( AWarpZoneInfo, Destinations, 1232 );            // StrProperty
	checkOffset( AWarpZoneInfo, numDestinations, 1360 );         // IntProperty

	// LevelInfo: PropertiesSize 1484
	checkOffset( ALevelInfo, TimeDilation, 1140 );               // FloatProperty
	checkOffset( ALevelInfo, TimeSeconds, 1144 );                // FloatProperty
	checkOffset( ALevelInfo, Year, 1148 );                       // IntProperty
	checkOffset( ALevelInfo, Month, 1152 );                      // IntProperty
	checkOffset( ALevelInfo, Day, 1156 );                        // IntProperty
	checkOffset( ALevelInfo, DayOfWeek, 1160 );                  // IntProperty
	checkOffset( ALevelInfo, Hour, 1164 );                       // IntProperty
	checkOffset( ALevelInfo, Minute, 1168 );                     // IntProperty
	checkOffset( ALevelInfo, Second, 1172 );                     // IntProperty
	checkOffset( ALevelInfo, Millisecond, 1176 );                // IntProperty
	checkOffset( ALevelInfo, Title, 1180 );                      // StrProperty
	checkOffset( ALevelInfo, Author, 1196 );                     // StrProperty
	checkOffset( ALevelInfo, IdealPlayerCount, 1212 );           // StrProperty
	checkOffset( ALevelInfo, RecommendedEnemies, 1228 );         // IntProperty
	checkOffset( ALevelInfo, RecommendedTeammates, 1232 );       // IntProperty
	checkOffset( ALevelInfo, LevelEnterText, 1236 );             // StrProperty
	checkOffset( ALevelInfo, LocalizedPkg, 1252 );               // StrProperty
	checkOffset( ALevelInfo, Pauser, 1268 );                     // StrProperty
	checkOffset( ALevelInfo, Summary, 1284 );                    // ObjectProperty
	checkOffset( ALevelInfo, Song, 1296 );                       // ObjectProperty
	checkOffset( ALevelInfo, SongSection, 1304 );                // ByteProperty
	checkOffset( ALevelInfo, CdTrack, 1305 );                    // ByteProperty
	checkOffset( ALevelInfo, PlayerDoppler, 1308 );              // FloatProperty
	checkOffset( ALevelInfo, Brightness, 1312 );                 // FloatProperty
	checkOffset( ALevelInfo, Screenshot, 1316 );                 // ObjectProperty
	checkOffset( ALevelInfo, DefaultTexture, 1324 );             // ObjectProperty
	checkOffset( ALevelInfo, HubStackLevel, 1332 );              // IntProperty
	checkOffset( ALevelInfo, LevelAction, 1336 );                // ByteProperty
	checkOffset( ALevelInfo, NetMode, 1337 );                    // ByteProperty
	checkOffset( ALevelInfo, ComputerName, 1340 );               // StrProperty
	checkOffset( ALevelInfo, EngineVersion, 1356 );              // StrProperty
	checkOffset( ALevelInfo, MinNetVersion, 1372 );              // StrProperty
	checkOffset( ALevelInfo, DefaultGameType, 1388 );            // ClassProperty
	checkOffset( ALevelInfo, Game, 1396 );                       // ObjectProperty
	checkOffset( ALevelInfo, NavigationPointList, 1404 );        // ObjectProperty
	checkOffset( ALevelInfo, PawnList, 1412 );                   // ObjectProperty
	checkOffset( ALevelInfo, NextURL, 1420 );                    // StrProperty
	checkOffset( ALevelInfo, NextSwitchCountdown, 1440 );        // FloatProperty
	checkOffset( ALevelInfo, AIProfile, 1444 );                  // IntProperty
	checkOffset( ALevelInfo, AvgAITime, 1476 );                  // FloatProperty

	// GameInfo: PropertiesSize 1332
	checkOffset( AGameInfo, ItemGoals, 652 );                    // IntProperty
	checkOffset( AGameInfo, KillGoals, 656 );                    // IntProperty
	checkOffset( AGameInfo, SecretGoals, 660 );                  // IntProperty
	checkOffset( AGameInfo, Difficulty, 664 );                   // ByteProperty
	checkOffset( AGameInfo, AutoAim, 672 );                      // FloatProperty
	checkOffset( AGameInfo, GameSpeed, 676 );                    // FloatProperty
	checkOffset( AGameInfo, StartTime, 680 );                    // FloatProperty
	checkOffset( AGameInfo, DefaultPlayerClass, 684 );           // ClassProperty
	checkOffset( AGameInfo, DefaultWeapon, 692 );                // ClassProperty
	checkOffset( AGameInfo, MaxSpectators, 700 );                // IntProperty
	checkOffset( AGameInfo, NumSpectators, 704 );                // IntProperty
	checkOffset( AGameInfo, AdminPassword, 708 );                // StrProperty
	checkOffset( AGameInfo, GamePassword, 724 );                 // StrProperty
	checkOffset( AGameInfo, ScoreBoardType, 740 );               // ClassProperty
	checkOffset( AGameInfo, GameMenuType, 748 );                 // ClassProperty
	checkOffset( AGameInfo, BotMenuType, 756 );                  // StrProperty
	checkOffset( AGameInfo, RulesMenuType, 772 );                // StrProperty
	checkOffset( AGameInfo, SettingsMenuType, 788 );             // StrProperty
	checkOffset( AGameInfo, GameUMenuType, 804 );                // StrProperty
	checkOffset( AGameInfo, MultiplayerUMenuType, 820 );         // StrProperty
	checkOffset( AGameInfo, GameOptionsMenuType, 836 );          // StrProperty
	checkOffset( AGameInfo, HUDType, 852 );                      // ClassProperty
	checkOffset( AGameInfo, MapListType, 860 );                  // ClassProperty
	checkOffset( AGameInfo, MapPrefix, 868 );                    // StrProperty
	checkOffset( AGameInfo, BeaconName, 884 );                   // StrProperty
	checkOffset( AGameInfo, SpecialDamageString, 900 );          // StrProperty
	checkOffset( AGameInfo, SwitchLevelMessage, 916 );           // StrProperty
	checkOffset( AGameInfo, SentText, 932 );                     // IntProperty
	checkOffset( AGameInfo, DefaultPlayerName, 936 );            // StrProperty
	checkOffset( AGameInfo, LeftMessage, 952 );                  // StrProperty
	checkOffset( AGameInfo, FailedSpawnMessage, 968 );           // StrProperty
	checkOffset( AGameInfo, FailedPlaceMessage, 984 );           // StrProperty
	checkOffset( AGameInfo, FailedTeamMessage, 1000 );           // StrProperty
	checkOffset( AGameInfo, NameChangedMessage, 1016 );          // StrProperty
	checkOffset( AGameInfo, EnteredMessage, 1032 );              // StrProperty
	checkOffset( AGameInfo, GameName, 1048 );                    // StrProperty
	checkOffset( AGameInfo, MaxedOutMessage, 1064 );             // StrProperty
	checkOffset( AGameInfo, WrongPassword, 1080 );               // StrProperty
	checkOffset( AGameInfo, NeedPassword, 1096 );                // StrProperty
	checkOffset( AGameInfo, MaxPlayers, 1112 );                  // IntProperty
	checkOffset( AGameInfo, NumPlayers, 1116 );                  // IntProperty
	checkOffset( AGameInfo, CurrentID, 1120 );                   // IntProperty
	checkOffset( AGameInfo, MutatorClass, 1124 );                // ClassProperty
	checkOffset( AGameInfo, BaseMutator, 1132 );                 // ObjectProperty
	checkOffset( AGameInfo, WaterZoneType, 1140 );               // ClassProperty
	checkOffset( AGameInfo, DefaultPlayerState, 1148 );          // NameProperty
	checkOffset( AGameInfo, GameReplicationInfoClass, 1152 );    // ClassProperty
	checkOffset( AGameInfo, GameReplicationInfo, 1160 );         // ObjectProperty
	checkOffset( AGameInfo, ServerLogName, 1168 );               // StrProperty
	checkOffset( AGameInfo, LocalLog, 1184 );                    // ObjectProperty
	checkOffset( AGameInfo, WorldLog, 1192 );                    // ObjectProperty
	checkOffset( AGameInfo, LocalLogFileName, 1204 );            // StrProperty
	checkOffset( AGameInfo, WorldLogFileName, 1220 );            // StrProperty
	checkOffset( AGameInfo, LocalBatcherURL, 1236 );             // StrProperty
	checkOffset( AGameInfo, LocalBatcherParams, 1252 );          // StrProperty
	checkOffset( AGameInfo, LocalStatsURL, 1268 );               // StrProperty
	checkOffset( AGameInfo, WorldBatcherURL, 1284 );             // StrProperty
	checkOffset( AGameInfo, WorldBatcherParams, 1300 );          // StrProperty
	checkOffset( AGameInfo, WorldStatsURL, 1316 );               // StrProperty

	// Mutator: PropertiesSize 668
	checkOffset( AMutator, NextMutator, 652 );                   // ObjectProperty
	checkOffset( AMutator, DefaultWeapon, 660 );                 // ClassProperty

	// NavigationPoint: PropertiesSize 1052
	checkOffset( ANavigationPoint, ownerTeam, 652 );             // NameProperty
	checkOffset( ANavigationPoint, upstreamPaths, 660 );         // IntProperty
	checkOffset( ANavigationPoint, Paths, 724 );                 // IntProperty
	checkOffset( ANavigationPoint, PrunedPaths, 788 );           // IntProperty
	checkOffset( ANavigationPoint, VisNoReachPaths, 852 );       // ObjectProperty
	checkOffset( ANavigationPoint, visitedWeight, 980 );         // IntProperty
	checkOffset( ANavigationPoint, RouteCache, 984 );            // ObjectProperty
	checkOffset( ANavigationPoint, bestPathWeight, 992 );        // IntProperty
	checkOffset( ANavigationPoint, nextNavigationPoint, 996 );   // ObjectProperty
	checkOffset( ANavigationPoint, nextOrdered, 1004 );          // ObjectProperty
	checkOffset( ANavigationPoint, prevOrdered, 1012 );          // ObjectProperty
	checkOffset( ANavigationPoint, startPath, 1020 );            // ObjectProperty
	checkOffset( ANavigationPoint, previousPath, 1028 );         // ObjectProperty
	checkOffset( ANavigationPoint, cost, 1036 );                 // IntProperty
	checkOffset( ANavigationPoint, ExtraCost, 1040 );            // IntProperty
	checkOffset( ANavigationPoint, PathDescription, 1048 );      // ByteProperty

	// LiftExit: PropertiesSize 1080
	checkOffset( ALiftExit, LiftTag, 1052 );                     // NameProperty
	checkOffset( ALiftExit, MyLift, 1056 );                      // ObjectProperty
	checkOffset( ALiftExit, LiftTrigger, 1064 );                 // NameProperty
	checkOffset( ALiftExit, RecommendedTrigger, 1068 );          // ObjectProperty
	checkOffset( ALiftExit, LastTriggerTime, 1076 );             // FloatProperty

	// LiftCenter: PropertiesSize 1084
	checkOffset( ALiftCenter, LiftTag, 1052 );                   // NameProperty
	checkOffset( ALiftCenter, MyLift, 1056 );                    // ObjectProperty
	checkOffset( ALiftCenter, LiftTrigger, 1064 );               // NameProperty
	checkOffset( ALiftCenter, RecommendedTrigger, 1068 );        // ObjectProperty
	checkOffset( ALiftCenter, LastTriggerTime, 1076 );           // FloatProperty
	checkOffset( ALiftCenter, MaxZDiffAdd, 1080 );               // FloatProperty

	// WarpZoneMarker: PropertiesSize 1076
	checkOffset( AWarpZoneMarker, markedWarpZone, 1052 );        // ObjectProperty
	checkOffset( AWarpZoneMarker, TriggerActor, 1060 );          // ObjectProperty
	checkOffset( AWarpZoneMarker, TriggerActor2, 1068 );         // ObjectProperty

	// InventorySpot: PropertiesSize 1060
	checkOffset( AInventorySpot, markedItem, 1052 );             // ObjectProperty

	// PlayerStart: PropertiesSize 1060
	checkOffset( APlayerStart, TeamNumber, 1052 );               // ByteProperty

	// Teleporter: PropertiesSize 1104
	checkOffset( ATeleporter, URL, 1052 );                       // StrProperty
	checkOffset( ATeleporter, ProductRequired, 1068 );           // NameProperty
	checkOffset( ATeleporter, TargetVelocity, 1076 );            // StructProperty
	checkOffset( ATeleporter, TriggerActor, 1088 );              // ObjectProperty
	checkOffset( ATeleporter, TriggerActor2, 1096 );             // ObjectProperty

	// Decoration: PropertiesSize 712
	checkOffset( ADecoration, EffectWhenDestroyed, 652 );        // ClassProperty
	checkOffset( ADecoration, PushSound, 664 );                  // ObjectProperty
	checkOffset( ADecoration, numLandings, 672 );                // IntProperty
	checkOffset( ADecoration, contents, 676 );                   // ClassProperty
	checkOffset( ADecoration, content2, 684 );                   // ClassProperty
	checkOffset( ADecoration, content3, 692 );                   // ClassProperty
	checkOffset( ADecoration, EndPushSound, 700 );               // ObjectProperty

	// Carcass: PropertiesSize 744
	checkOffset( ACarcass, flies, 716 );                         // ByteProperty
	checkOffset( ACarcass, rats, 717 );                          // ByteProperty
	checkOffset( ACarcass, CumulativeDamage, 724 );              // IntProperty
	checkOffset( ACarcass, PlayerOwner, 728 );                   // ObjectProperty
	checkOffset( ACarcass, Bugs, 736 );                          // ObjectProperty

	// Menu: PropertiesSize 1576
	checkOffset( AMenu, ParentMenu, 652 );                       // ObjectProperty
	checkOffset( AMenu, Selection, 660 );                        // IntProperty
	checkOffset( AMenu, MenuLength, 664 );                       // IntProperty
	checkOffset( AMenu, PlayerOwner, 672 );                      // ObjectProperty
	checkOffset( AMenu, HelpMessage, 680 );                      // StrProperty
	checkOffset( AMenu, MenuList, 1064 );                        // StrProperty
	checkOffset( AMenu, LeftString, 1448 );                      // StrProperty
	checkOffset( AMenu, RightString, 1464 );                     // StrProperty
	checkOffset( AMenu, CenterString, 1480 );                    // StrProperty
	checkOffset( AMenu, EnabledString, 1496 );                   // StrProperty
	checkOffset( AMenu, DisabledString, 1512 );                  // StrProperty
	checkOffset( AMenu, MenuTitle, 1528 );                       // StrProperty
	checkOffset( AMenu, YesString, 1544 );                       // StrProperty
	checkOffset( AMenu, NoString, 1560 );                        // StrProperty

	// HUD: PropertiesSize 692
	checkOffset( AHUD, HudMode, 652 );                           // IntProperty
	checkOffset( AHUD, Crosshair, 656 );                         // IntProperty
	checkOffset( AHUD, MainMenuType, 660 );                      // ClassProperty
	checkOffset( AHUD, HUDConfigWindowType, 668 );               // StrProperty
	checkOffset( AHUD, MainMenu, 684 );                          // ObjectProperty

	// Trigger: PropertiesSize 716
	checkOffset( ATrigger, TriggerType, 652 );                   // ByteProperty
	checkOffset( ATrigger, Message, 656 );                       // StrProperty
	checkOffset( ATrigger, ClassProximityType, 676 );            // ClassProperty
	checkOffset( ATrigger, RepeatTriggerTime, 684 );             // FloatProperty
	checkOffset( ATrigger, ReTriggerDelay, 688 );                // FloatProperty
	checkOffset( ATrigger, TriggerTime, 692 );                   // FloatProperty
	checkOffset( ATrigger, DamageThreshold, 696 );               // FloatProperty
	checkOffset( ATrigger, TriggerActor, 700 );                  // ObjectProperty
	checkOffset( ATrigger, TriggerActor2, 708 );                 // ObjectProperty

	// Inventory: PropertiesSize 936
	checkOffset( AInventory, AutoSwitchPriority, 652 );          // ByteProperty
	checkOffset( AInventory, InventoryGroup, 653 );              // ByteProperty
	checkOffset( AInventory, PickupMessage, 660 );               // StrProperty
	checkOffset( AInventory, ItemName, 676 );                    // StrProperty
	checkOffset( AInventory, ItemArticle, 692 );                 // StrProperty
	checkOffset( AInventory, RespawnTime, 708 );                 // FloatProperty
	checkOffset( AInventory, PlayerLastTouched, 712 );           // NameProperty
	checkOffset( AInventory, PlayerViewOffset, 716 );            // StructProperty
	checkOffset( AInventory, PlayerViewMesh, 728 );              // ObjectProperty
	checkOffset( AInventory, PlayerViewScale, 736 );             // FloatProperty
	checkOffset( AInventory, BobDamping, 740 );                  // FloatProperty
	checkOffset( AInventory, PickupViewMesh, 744 );              // ObjectProperty
	checkOffset( AInventory, PickupViewScale, 752 );             // FloatProperty
	checkOffset( AInventory, ThirdPersonMesh, 756 );             // ObjectProperty
	checkOffset( AInventory, ThirdPersonScale, 764 );            // FloatProperty
	checkOffset( AInventory, StatusIcon, 768 );                  // ObjectProperty
	checkOffset( AInventory, ProtectionType1, 776 );             // NameProperty
	checkOffset( AInventory, ProtectionType2, 780 );             // NameProperty
	checkOffset( AInventory, Charge, 784 );                      // IntProperty
	checkOffset( AInventory, ArmorAbsorption, 788 );             // IntProperty
	checkOffset( AInventory, AbsorptionPriority, 796 );          // IntProperty
	checkOffset( AInventory, NextArmor, 800 );                   // ObjectProperty
	checkOffset( AInventory, MaxDesireability, 808 );            // FloatProperty
	checkOffset( AInventory, myMarker, 812 );                    // ObjectProperty
	checkOffset( AInventory, FlashCount, 824 );                  // ByteProperty
	checkOffset( AInventory, OldFlashCount, 825 );               // ByteProperty
	checkOffset( AInventory, MuzzleFlashStyle, 826 );            // ByteProperty
	checkOffset( AInventory, MuzzleFlashMesh, 828 );             // ObjectProperty
	checkOffset( AInventory, MuzzleFlashScale, 836 );            // FloatProperty
	checkOffset( AInventory, MuzzleFlashTexture, 840 );          // ObjectProperty
	checkOffset( AInventory, PickupSound, 848 );                 // ObjectProperty
	checkOffset( AInventory, ActivateSound, 856 );               // ObjectProperty
	checkOffset( AInventory, DeActivateSound, 864 );             // ObjectProperty
	checkOffset( AInventory, RespawnSound, 872 );                // ObjectProperty
	checkOffset( AInventory, Icon, 880 );                        // ObjectProperty
	checkOffset( AInventory, M_Activated, 888 );                 // StrProperty
	checkOffset( AInventory, M_Selected, 904 );                  // StrProperty
	checkOffset( AInventory, M_Deactivated, 920 );               // StrProperty

	// Weapon: PropertiesSize 1200
	checkOffset( AWeapon, MaxTargetRange, 936 );                 // FloatProperty
	checkOffset( AWeapon, AmmoName, 940 );                       // ClassProperty
	checkOffset( AWeapon, ReloadCount, 948 );                    // ByteProperty
	checkOffset( AWeapon, PickupAmmoCount, 952 );                // IntProperty
	checkOffset( AWeapon, AmmoType, 956 );                       // ObjectProperty
	checkOffset( AWeapon, FiringSpeed, 968 );                    // FloatProperty
	checkOffset( AWeapon, FireOffset, 972 );                     // StructProperty
	checkOffset( AWeapon, ProjectileClass, 984 );                // ClassProperty
	checkOffset( AWeapon, AltProjectileClass, 992 );             // ClassProperty
	checkOffset( AWeapon, MyDamageType, 1000 );                  // NameProperty
	checkOffset( AWeapon, AltDamageType, 1004 );                 // NameProperty
	checkOffset( AWeapon, ProjectileSpeed, 1008 );               // FloatProperty
	checkOffset( AWeapon, AltProjectileSpeed, 1012 );            // FloatProperty
	checkOffset( AWeapon, aimerror, 1016 );                      // FloatProperty
	checkOffset( AWeapon, shakemag, 1020 );                      // FloatProperty
	checkOffset( AWeapon, shaketime, 1024 );                     // FloatProperty
	checkOffset( AWeapon, shakevert, 1028 );                     // FloatProperty
	checkOffset( AWeapon, AIRating, 1032 );                      // FloatProperty
	checkOffset( AWeapon, RefireRate, 1036 );                    // FloatProperty
	checkOffset( AWeapon, AltRefireRate, 1040 );                 // FloatProperty
	checkOffset( AWeapon, FireSound, 1044 );                     // ObjectProperty
	checkOffset( AWeapon, AltFireSound, 1052 );                  // ObjectProperty
	checkOffset( AWeapon, CockingSound, 1060 );                  // ObjectProperty
	checkOffset( AWeapon, SelectSound, 1068 );                   // ObjectProperty
	checkOffset( AWeapon, Misc1Sound, 1076 );                    // ObjectProperty
	checkOffset( AWeapon, Misc2Sound, 1084 );                    // ObjectProperty
	checkOffset( AWeapon, Misc3Sound, 1092 );                    // ObjectProperty
	checkOffset( AWeapon, MessageNoAmmo, 1100 );                 // StrProperty
	checkOffset( AWeapon, DeathMessage, 1116 );                  // StrProperty
	checkOffset( AWeapon, AdjustedAim, 1132 );                   // StructProperty
	checkOffset( AWeapon, bMuzzleFlash, 1148 );                  // ByteProperty
	checkOffset( AWeapon, FlashTime, 1152 );                     // FloatProperty
	checkOffset( AWeapon, MuzzleScale, 1156 );                   // FloatProperty
	checkOffset( AWeapon, FlashY, 1160 );                        // FloatProperty
	checkOffset( AWeapon, FlashO, 1164 );                        // FloatProperty
	checkOffset( AWeapon, FlashC, 1168 );                        // FloatProperty
	checkOffset( AWeapon, FlashLength, 1172 );                   // FloatProperty
	checkOffset( AWeapon, FlashS, 1176 );                        // IntProperty
	checkOffset( AWeapon, MFTexture, 1180 );                     // ObjectProperty
	checkOffset( AWeapon, MuzzleFlare, 1188 );                   // ObjectProperty
	checkOffset( AWeapon, FlareOffset, 1196 );                   // FloatProperty

	// Projectile: PropertiesSize 700
	checkOffset( AProjectile, speed, 652 );                      // FloatProperty
	checkOffset( AProjectile, MaxSpeed, 656 );                   // FloatProperty
	checkOffset( AProjectile, Damage, 660 );                     // FloatProperty
	checkOffset( AProjectile, MomentumTransfer, 664 );           // IntProperty
	checkOffset( AProjectile, MyDamageType, 668 );               // NameProperty
	checkOffset( AProjectile, SpawnSound, 672 );                 // ObjectProperty
	checkOffset( AProjectile, ImpactSound, 680 );                // ObjectProperty
	checkOffset( AProjectile, MiscSound, 688 );                  // ObjectProperty
	checkOffset( AProjectile, ExploWallOut, 696 );               // FloatProperty

	// LevelSummary: PropertiesSize 136
	checkOffset( ULevelSummary, Title, 64 );                     // StrProperty
	checkOffset( ULevelSummary, Author, 80 );                    // StrProperty
	checkOffset( ULevelSummary, IdealPlayerCount, 96 );          // StrProperty
	checkOffset( ULevelSummary, RecommendedEnemies, 112 );       // IntProperty
	checkOffset( ULevelSummary, RecommendedTeammates, 116 );     // IntProperty
	checkOffset( ULevelSummary, LevelEnterText, 120 );           // StrProperty
}
