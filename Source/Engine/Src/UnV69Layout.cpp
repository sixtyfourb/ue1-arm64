/*=============================================================================
	UnV69Layout.cpp: Compile-time check that the C++ classes match the layout
	package version 69 (OldUnreal 469) gives them.

	UStruct::Link assigns every property an offset by walking the script class's
	own properties in order; the C++ class is only a view onto that memory. If
	the two disagree, native code silently reads the wrong field - the engine
	compares whole class sizes and never individual offsets, so nothing would
	say so. Every offset it reported is pinned here instead, and a mismatch
	fails the build.

	Generated, not edited: scripts/ut99-v69-layout.py asserts <warnings.txt>.
=============================================================================*/

#include "EnginePrivate.h"

// Bitfields are left out: they share a word, and offsetof cannot name them.
//
// A mismatch is reported as an incomplete type CppOffset<actual,expected>, so
// the diagnostic carries both numbers - static_assert can only carry a string,
// so it names the member and CppOffset supplies the arithmetic.
template< int Actual, int Expected > struct CppOffset;
template< int Same > struct CppOffset<Same,Same> { typedef int Matches; };

#define checkOffset(cls,member,off) \
	static_assert( __builtin_offsetof(cls,member)==off, \
		#cls "::" #member " is not where package version 69 puts it" ); \
	(void)sizeof( CppOffset< (int)__builtin_offsetof(cls,member), off >::Matches )

static void UnV69LayoutChecks()
{
	// Actor: script size 680
	checkOffset( AActor, Physics, 68 );                        // ByteProperty
	checkOffset( AActor, Role, 69 );                           // ByteProperty
	checkOffset( AActor, RemoteRole, 70 );                     // ByteProperty
	checkOffset( AActor, NetTag, 72 );                         // IntProperty
	checkOffset( AActor, Owner, 76 );                          // ObjectProperty
	checkOffset( AActor, InitialState, 84 );                   // NameProperty
	checkOffset( AActor, Group, 88 );                          // NameProperty
	checkOffset( AActor, TimerRate, 92 );                      // FloatProperty
	checkOffset( AActor, TimerCounter, 96 );                   // FloatProperty
	checkOffset( AActor, LifeSpan, 100 );                      // FloatProperty
	checkOffset( AActor, AnimSequence, 104 );                  // NameProperty
	checkOffset( AActor, AnimFrame, 108 );                     // FloatProperty
	checkOffset( AActor, AnimRate, 112 );                      // FloatProperty
	checkOffset( AActor, TweenRate, 116 );                     // FloatProperty
	checkOffset( AActor, SkelAnim, 120 );                      // ObjectProperty
	checkOffset( AActor, LODBias, 128 );                       // FloatProperty
	checkOffset( AActor, Level, 132 );                         // ObjectProperty
	checkOffset( AActor, XLevel, 140 );                        // ObjectProperty
	checkOffset( AActor, Tag, 148 );                           // NameProperty
	checkOffset( AActor, Event, 152 );                         // NameProperty
	checkOffset( AActor, Target, 156 );                        // ObjectProperty
	checkOffset( AActor, Instigator, 164 );                    // ObjectProperty
	checkOffset( AActor, AmbientSound, 172 );                  // ObjectProperty
	checkOffset( AActor, Inventory, 180 );                     // ObjectProperty
	checkOffset( AActor, Base, 188 );                          // ObjectProperty
	checkOffset( AActor, Region, 196 );                        // StructProperty
	checkOffset( AActor, AttachTag, 212 );                     // NameProperty
	checkOffset( AActor, StandingCount, 216 );                 // ByteProperty
	checkOffset( AActor, MiscNumber, 217 );                    // ByteProperty
	checkOffset( AActor, LatentByte, 218 );                    // ByteProperty
	checkOffset( AActor, LatentInt, 220 );                     // IntProperty
	checkOffset( AActor, LatentFloat, 224 );                   // FloatProperty
	checkOffset( AActor, LatentActor, 228 );                   // ObjectProperty
	checkOffset( AActor, Touching, 236 );                      // ObjectProperty
	checkOffset( AActor, Deleted, 268 );                       // ObjectProperty
	checkOffset( AActor, CollisionTag, 276 );                  // IntProperty
	checkOffset( AActor, LightingTag, 280 );                   // IntProperty
	checkOffset( AActor, OtherTag, 284 );                      // IntProperty
	checkOffset( AActor, ExtraTag, 288 );                      // IntProperty
	checkOffset( AActor, SpecialTag, 292 );                    // IntProperty
	checkOffset( AActor, Location, 296 );                      // StructProperty
	checkOffset( AActor, Rotation, 308 );                      // StructProperty
	checkOffset( AActor, OldLocation, 320 );                   // StructProperty
	checkOffset( AActor, ColLocation, 332 );                   // StructProperty
	checkOffset( AActor, Velocity, 344 );                      // StructProperty
	checkOffset( AActor, Acceleration, 356 );                  // StructProperty
	checkOffset( AActor, OddsOfAppearing, 368 );               // FloatProperty
	checkOffset( AActor, HitActor, 376 );                      // ObjectProperty
	checkOffset( AActor, DrawType, 384 );                      // ByteProperty
	checkOffset( AActor, Style, 385 );                         // ByteProperty
	checkOffset( AActor, Sprite, 388 );                        // ObjectProperty
	checkOffset( AActor, Texture, 396 );                       // ObjectProperty
	checkOffset( AActor, Skin, 404 );                          // ObjectProperty
	checkOffset( AActor, Mesh, 412 );                          // ObjectProperty
	checkOffset( AActor, Brush, 420 );                         // ObjectProperty
	checkOffset( AActor, DrawScale, 428 );                     // FloatProperty
	checkOffset( AActor, PrePivot, 432 );                      // StructProperty
	checkOffset( AActor, ScaleGlow, 444 );                     // FloatProperty
	checkOffset( AActor, VisibilityRadius, 448 );              // FloatProperty
	checkOffset( AActor, VisibilityHeight, 452 );              // FloatProperty
	checkOffset( AActor, AmbientGlow, 456 );                   // ByteProperty
	checkOffset( AActor, Fatness, 457 );                       // ByteProperty
	checkOffset( AActor, SpriteProjForward, 460 );             // FloatProperty
	checkOffset( AActor, MultiSkins, 468 );                    // ObjectProperty
	checkOffset( AActor, SoundRadius, 532 );                   // ByteProperty
	checkOffset( AActor, SoundVolume, 533 );                   // ByteProperty
	checkOffset( AActor, SoundPitch, 534 );                    // ByteProperty
	checkOffset( AActor, TransientSoundVolume, 536 );          // FloatProperty
	checkOffset( AActor, TransientSoundRadius, 540 );          // FloatProperty
	checkOffset( AActor, CollisionRadius, 544 );               // FloatProperty
	checkOffset( AActor, CollisionHeight, 548 );               // FloatProperty
	checkOffset( AActor, LightType, 556 );                     // ByteProperty
	checkOffset( AActor, LightEffect, 557 );                   // ByteProperty
	checkOffset( AActor, LightBrightness, 558 );               // ByteProperty
	checkOffset( AActor, LightHue, 559 );                      // ByteProperty
	checkOffset( AActor, LightSaturation, 560 );               // ByteProperty
	checkOffset( AActor, LightRadius, 561 );                   // ByteProperty
	checkOffset( AActor, LightPeriod, 562 );                   // ByteProperty
	checkOffset( AActor, LightPhase, 563 );                    // ByteProperty
	checkOffset( AActor, LightCone, 564 );                     // ByteProperty
	checkOffset( AActor, VolumeBrightness, 565 );              // ByteProperty
	checkOffset( AActor, VolumeRadius, 566 );                  // ByteProperty
	checkOffset( AActor, VolumeFog, 567 );                     // ByteProperty
	checkOffset( AActor, DodgeDir, 572 );                      // ByteProperty
	checkOffset( AActor, Mass, 576 );                          // FloatProperty
	checkOffset( AActor, Buoyancy, 580 );                      // FloatProperty
	checkOffset( AActor, RotationRate, 584 );                  // StructProperty
	checkOffset( AActor, DesiredRotation, 596 );               // StructProperty
	checkOffset( AActor, PhysAlpha, 608 );                     // FloatProperty
	checkOffset( AActor, PhysRate, 612 );                      // FloatProperty
	checkOffset( AActor, PendingTouch, 616 );                  // ObjectProperty
	checkOffset( AActor, AnimLast, 624 );                      // FloatProperty
	checkOffset( AActor, AnimMinRate, 628 );                   // FloatProperty
	checkOffset( AActor, OldAnimRate, 632 );                   // FloatProperty
	checkOffset( AActor, SimAnim, 636 );                       // StructProperty
	checkOffset( AActor, NetPriority, 652 );                   // FloatProperty
	checkOffset( AActor, NetUpdateFrequency, 656 );            // FloatProperty
	checkOffset( AActor, RenderIteratorClass, 664 );           // ClassProperty
	checkOffset( AActor, RenderInterface, 672 );               // ObjectProperty

	// ZoneInfo: script size 1112
	checkOffset( AZoneInfo, ZoneTag, 680 );                    // NameProperty
	checkOffset( AZoneInfo, ZoneGravity, 684 );                // StructProperty
	checkOffset( AZoneInfo, ZoneVelocity, 696 );               // StructProperty
	checkOffset( AZoneInfo, ZoneGroundFriction, 708 );         // FloatProperty
	checkOffset( AZoneInfo, ZoneFluidFriction, 712 );          // FloatProperty
	checkOffset( AZoneInfo, ZoneTerminalVelocity, 716 );       // FloatProperty
	checkOffset( AZoneInfo, ZonePlayerEvent, 720 );            // NameProperty
	checkOffset( AZoneInfo, ZonePlayerCount, 724 );            // IntProperty
	checkOffset( AZoneInfo, NumCarcasses, 728 );               // IntProperty
	checkOffset( AZoneInfo, DamagePerSec, 732 );               // IntProperty
	checkOffset( AZoneInfo, DamageType, 736 );                 // NameProperty
	checkOffset( AZoneInfo, DamageString, 740 );               // StrProperty
	checkOffset( AZoneInfo, ZoneName, 756 );                   // StrProperty
	checkOffset( AZoneInfo, locationid, 772 );                 // ObjectProperty
	checkOffset( AZoneInfo, MaxCarcasses, 780 );               // IntProperty
	checkOffset( AZoneInfo, EntrySound, 784 );                 // ObjectProperty
	checkOffset( AZoneInfo, ExitSound, 792 );                  // ObjectProperty
	checkOffset( AZoneInfo, EntryActor, 800 );                 // ClassProperty
	checkOffset( AZoneInfo, ExitActor, 808 );                  // ClassProperty
	checkOffset( AZoneInfo, SkyZone, 816 );                    // ObjectProperty
	checkOffset( AZoneInfo, AmbientBrightness, 828 );          // ByteProperty
	checkOffset( AZoneInfo, AmbientHue, 829 );                 // ByteProperty
	checkOffset( AZoneInfo, AmbientSaturation, 830 );          // ByteProperty
	checkOffset( AZoneInfo, FogColor, 832 );                   // StructProperty
	checkOffset( AZoneInfo, FogDistance, 836 );                // FloatProperty
	checkOffset( AZoneInfo, EnvironmentMap, 840 );             // ObjectProperty
	checkOffset( AZoneInfo, TexUPanSpeed, 848 );               // FloatProperty
	checkOffset( AZoneInfo, TexVPanSpeed, 852 );               // FloatProperty
	checkOffset( AZoneInfo, ViewFlash, 856 );                  // StructProperty
	checkOffset( AZoneInfo, ViewFog, 868 );                    // StructProperty
	checkOffset( AZoneInfo, SpeedOfSound, 884 );               // FloatProperty
	checkOffset( AZoneInfo, MasterGain, 888 );                 // ByteProperty
	checkOffset( AZoneInfo, CutoffHz, 892 );                   // IntProperty
	checkOffset( AZoneInfo, Delay, 896 );                      // ByteProperty
	checkOffset( AZoneInfo, Gain, 902 );                       // ByteProperty
	checkOffset( AZoneInfo, LensFlare, 908 );                  // ObjectProperty
	checkOffset( AZoneInfo, LensFlareOffset, 1004 );           // FloatProperty
	checkOffset( AZoneInfo, LensFlareScale, 1052 );            // FloatProperty
	checkOffset( AZoneInfo, MinLightCount, 1100 );             // ByteProperty
	checkOffset( AZoneInfo, MaxLightCount, 1101 );             // ByteProperty
	checkOffset( AZoneInfo, MinLightingPolyCount, 1104 );      // IntProperty
	checkOffset( AZoneInfo, MaxLightingPolyCount, 1108 );      // IntProperty

	// LevelInfo: script size 1488
	checkOffset( ALevelInfo, TimeDilation, 1112 );             // FloatProperty
	checkOffset( ALevelInfo, TimeSeconds, 1116 );              // FloatProperty
	checkOffset( ALevelInfo, Year, 1120 );                     // IntProperty
	checkOffset( ALevelInfo, Month, 1124 );                    // IntProperty
	checkOffset( ALevelInfo, Day, 1128 );                      // IntProperty
	checkOffset( ALevelInfo, DayOfWeek, 1132 );                // IntProperty
	checkOffset( ALevelInfo, Hour, 1136 );                     // IntProperty
	checkOffset( ALevelInfo, Minute, 1140 );                   // IntProperty
	checkOffset( ALevelInfo, Second, 1144 );                   // IntProperty
	checkOffset( ALevelInfo, Millisecond, 1148 );              // IntProperty
	checkOffset( ALevelInfo, Title, 1152 );                    // StrProperty
	checkOffset( ALevelInfo, Author, 1168 );                   // StrProperty
	checkOffset( ALevelInfo, IdealPlayerCount, 1184 );         // StrProperty
	checkOffset( ALevelInfo, RecommendedEnemies, 1200 );       // IntProperty
	checkOffset( ALevelInfo, RecommendedTeammates, 1204 );     // IntProperty
	checkOffset( ALevelInfo, LevelEnterText, 1208 );           // StrProperty
	checkOffset( ALevelInfo, LocalizedPkg, 1224 );             // StrProperty
	checkOffset( ALevelInfo, Pauser, 1240 );                   // StrProperty
	checkOffset( ALevelInfo, Summary, 1256 );                  // ObjectProperty
	checkOffset( ALevelInfo, VisibleGroups, 1264 );            // StrProperty
	checkOffset( ALevelInfo, Song, 1284 );                     // ObjectProperty
	checkOffset( ALevelInfo, SongSection, 1292 );              // ByteProperty
	checkOffset( ALevelInfo, CdTrack, 1293 );                  // ByteProperty
	checkOffset( ALevelInfo, PlayerDoppler, 1296 );            // FloatProperty
	checkOffset( ALevelInfo, Brightness, 1300 );               // FloatProperty
	checkOffset( ALevelInfo, Screenshot, 1304 );               // ObjectProperty
	checkOffset( ALevelInfo, DefaultTexture, 1312 );           // ObjectProperty
	checkOffset( ALevelInfo, HubStackLevel, 1320 );            // IntProperty
	checkOffset( ALevelInfo, LevelAction, 1324 );              // ByteProperty
	checkOffset( ALevelInfo, NetMode, 1332 );                  // ByteProperty
	checkOffset( ALevelInfo, ComputerName, 1336 );             // StrProperty
	checkOffset( ALevelInfo, EngineVersion, 1352 );            // StrProperty
	checkOffset( ALevelInfo, MinNetVersion, 1368 );            // StrProperty
	checkOffset( ALevelInfo, DefaultGameType, 1384 );          // ClassProperty
	checkOffset( ALevelInfo, Game, 1392 );                     // ObjectProperty
	checkOffset( ALevelInfo, NavigationPointList, 1400 );      // ObjectProperty
	checkOffset( ALevelInfo, PawnList, 1408 );                 // ObjectProperty
	checkOffset( ALevelInfo, NextURL, 1416 );                  // StrProperty
	checkOffset( ALevelInfo, NextSwitchCountdown, 1436 );      // FloatProperty
	checkOffset( ALevelInfo, AIProfile, 1440 );                // IntProperty
	checkOffset( ALevelInfo, AvgAITime, 1472 );                // FloatProperty
	checkOffset( ALevelInfo, SpawnNotify, 1480 );              // ObjectProperty

	// NavigationPoint: script size 1076
	checkOffset( ANavigationPoint, ownerTeam, 680 );           // NameProperty
	checkOffset( ANavigationPoint, upstreamPaths, 688 );       // IntProperty
	checkOffset( ANavigationPoint, Paths, 752 );               // IntProperty
	checkOffset( ANavigationPoint, PrunedPaths, 816 );         // IntProperty
	checkOffset( ANavigationPoint, VisNoReachPaths, 880 );     // ObjectProperty
	checkOffset( ANavigationPoint, visitedWeight, 1008 );      // IntProperty
	checkOffset( ANavigationPoint, RouteCache, 1012 );         // ObjectProperty
	checkOffset( ANavigationPoint, bestPathWeight, 1020 );     // IntProperty
	checkOffset( ANavigationPoint, nextNavigationPoint, 1024 );// ObjectProperty
	checkOffset( ANavigationPoint, nextOrdered, 1032 );        // ObjectProperty
	checkOffset( ANavigationPoint, prevOrdered, 1040 );        // ObjectProperty
	checkOffset( ANavigationPoint, startPath, 1048 );          // ObjectProperty
	checkOffset( ANavigationPoint, previousPath, 1056 );       // ObjectProperty
	checkOffset( ANavigationPoint, cost, 1064 );               // IntProperty
	checkOffset( ANavigationPoint, ExtraCost, 1068 );          // IntProperty

	// PlayerStart: script size 1084
	checkOffset( APlayerStart, TeamNumber, 1076 );             // ByteProperty

	// Pawn: script size 1440
	checkOffset( APawn, SightCounter, 688 );                   // FloatProperty
	checkOffset( APawn, PainTime, 692 );                       // FloatProperty
	checkOffset( APawn, SpeechTime, 696 );                     // FloatProperty
	checkOffset( APawn, AvgPhysicsTime, 700 );                 // FloatProperty
	checkOffset( APawn, FootRegion, 704 );                     // StructProperty
	checkOffset( APawn, HeadRegion, 720 );                     // StructProperty
	checkOffset( APawn, MoveTimer, 736 );                      // FloatProperty
	checkOffset( APawn, MoveTarget, 740 );                     // ObjectProperty
	checkOffset( APawn, FaceTarget, 748 );                     // ObjectProperty
	checkOffset( APawn, Destination, 756 );                    // StructProperty
	checkOffset( APawn, Focus, 768 );                          // StructProperty
	checkOffset( APawn, DesiredSpeed, 780 );                   // FloatProperty
	checkOffset( APawn, MaxDesiredSpeed, 784 );                // FloatProperty
	checkOffset( APawn, MeleeRange, 788 );                     // FloatProperty
	checkOffset( APawn, GroundSpeed, 792 );                    // FloatProperty
	checkOffset( APawn, WaterSpeed, 796 );                     // FloatProperty
	checkOffset( APawn, AirSpeed, 800 );                       // FloatProperty
	checkOffset( APawn, AccelRate, 804 );                      // FloatProperty
	checkOffset( APawn, JumpZ, 808 );                          // FloatProperty
	checkOffset( APawn, MaxStepHeight, 812 );                  // FloatProperty
	checkOffset( APawn, AirControl, 816 );                     // FloatProperty
	checkOffset( APawn, MinHitWall, 820 );                     // FloatProperty
	checkOffset( APawn, Visibility, 824 );                     // ByteProperty
	checkOffset( APawn, Alertness, 828 );                      // FloatProperty
	checkOffset( APawn, Stimulus, 832 );                       // FloatProperty
	checkOffset( APawn, SightRadius, 836 );                    // FloatProperty
	checkOffset( APawn, PeripheralVision, 840 );               // FloatProperty
	checkOffset( APawn, HearingThreshold, 844 );               // FloatProperty
	checkOffset( APawn, LastSeenPos, 848 );                    // StructProperty
	checkOffset( APawn, LastSeeingPos, 860 );                  // StructProperty
	checkOffset( APawn, LastSeenTime, 872 );                   // FloatProperty
	checkOffset( APawn, Enemy, 876 );                          // ObjectProperty
	checkOffset( APawn, Weapon, 884 );                         // ObjectProperty
	checkOffset( APawn, PendingWeapon, 892 );                  // ObjectProperty
	checkOffset( APawn, SelectedItem, 900 );                   // ObjectProperty
	checkOffset( APawn, ViewRotation, 908 );                   // StructProperty
	checkOffset( APawn, WalkBob, 920 );                        // StructProperty
	checkOffset( APawn, BaseEyeHeight, 932 );                  // FloatProperty
	checkOffset( APawn, EyeHeight, 936 );                      // FloatProperty
	checkOffset( APawn, Floor, 940 );                          // StructProperty
	checkOffset( APawn, SplashTime, 952 );                     // FloatProperty
	checkOffset( APawn, OrthoZoom, 956 );                      // FloatProperty
	checkOffset( APawn, FovAngle, 960 );                       // FloatProperty
	checkOffset( APawn, DieCount, 964 );                       // IntProperty
	checkOffset( APawn, ItemCount, 968 );                      // IntProperty
	checkOffset( APawn, KillCount, 972 );                      // IntProperty
	checkOffset( APawn, SecretCount, 976 );                    // IntProperty
	checkOffset( APawn, Spree, 980 );                          // IntProperty
	checkOffset( APawn, Health, 984 );                         // IntProperty
	checkOffset( APawn, SelectionMesh, 988 );                  // StrProperty
	checkOffset( APawn, SpecialMesh, 1004 );                   // StrProperty
	checkOffset( APawn, ReducedDamageType, 1020 );             // NameProperty
	checkOffset( APawn, ReducedDamagePct, 1024 );              // FloatProperty
	checkOffset( APawn, DropWhenKilled, 1028 );                // ClassProperty
	checkOffset( APawn, UnderWaterTime, 1036 );                // FloatProperty
	checkOffset( APawn, AttitudeToPlayer, 1040 );              // ByteProperty
	checkOffset( APawn, Intelligence, 1041 );                  // ByteProperty
	checkOffset( APawn, Skill, 1044 );                         // FloatProperty
	checkOffset( APawn, SpecialGoal, 1048 );                   // ObjectProperty
	checkOffset( APawn, SpecialPause, 1056 );                  // FloatProperty
	checkOffset( APawn, noise1spot, 1060 );                    // StructProperty
	checkOffset( APawn, noise1time, 1072 );                    // FloatProperty
	checkOffset( APawn, noise1other, 1076 );                   // ObjectProperty
	checkOffset( APawn, noise1loudness, 1084 );                // FloatProperty
	checkOffset( APawn, noise2spot, 1088 );                    // StructProperty
	checkOffset( APawn, noise2time, 1100 );                    // FloatProperty
	checkOffset( APawn, noise2other, 1104 );                   // ObjectProperty
	checkOffset( APawn, noise2loudness, 1112 );                // FloatProperty
	checkOffset( APawn, LastPainSound, 1116 );                 // FloatProperty
	checkOffset( APawn, nextPawn, 1120 );                      // ObjectProperty
	checkOffset( APawn, HitSound1, 1128 );                     // ObjectProperty
	checkOffset( APawn, HitSound2, 1136 );                     // ObjectProperty
	checkOffset( APawn, Land, 1144 );                          // ObjectProperty
	checkOffset( APawn, Die, 1152 );                           // ObjectProperty
	checkOffset( APawn, WaterStep, 1160 );                     // ObjectProperty
	checkOffset( APawn, bZoom, 1168 );                         // ByteProperty
	checkOffset( APawn, bRun, 1169 );                          // ByteProperty
	checkOffset( APawn, bLook, 1170 );                         // ByteProperty
	checkOffset( APawn, bDuck, 1171 );                         // ByteProperty
	checkOffset( APawn, bSnapLevel, 1172 );                    // ByteProperty
	checkOffset( APawn, bStrafe, 1173 );                       // ByteProperty
	checkOffset( APawn, bFire, 1174 );                         // ByteProperty
	checkOffset( APawn, bAltFire, 1175 );                      // ByteProperty
	checkOffset( APawn, bFreeLook, 1176 );                     // ByteProperty
	checkOffset( APawn, bExtra0, 1177 );                       // ByteProperty
	checkOffset( APawn, bExtra1, 1178 );                       // ByteProperty
	checkOffset( APawn, bExtra2, 1179 );                       // ByteProperty
	checkOffset( APawn, bExtra3, 1180 );                       // ByteProperty
	checkOffset( APawn, CombatStyle, 1184 );                   // FloatProperty
	checkOffset( APawn, home, 1188 );                          // ObjectProperty
	checkOffset( APawn, NextState, 1196 );                     // NameProperty
	checkOffset( APawn, NextLabel, 1200 );                     // NameProperty
	checkOffset( APawn, SoundDampening, 1204 );                // FloatProperty
	checkOffset( APawn, DamageScaling, 1208 );                 // FloatProperty
	checkOffset( APawn, AlarmTag, 1212 );                      // NameProperty
	checkOffset( APawn, SharedAlarmTag, 1216 );                // NameProperty
	checkOffset( APawn, carriedDecoration, 1220 );             // ObjectProperty
	checkOffset( APawn, PlayerReStartState, 1228 );            // NameProperty
	checkOffset( APawn, MenuName, 1232 );                      // StrProperty
	checkOffset( APawn, NameArticle, 1248 );                   // StrProperty
	checkOffset( APawn, VoicePitch, 1264 );                    // ByteProperty
	checkOffset( APawn, VoiceType, 1268 );                     // StrProperty
	checkOffset( APawn, OldMessageTime, 1284 );                // FloatProperty
	checkOffset( APawn, RouteCache, 1288 );                    // ObjectProperty
	checkOffset( APawn, PlayerReplicationInfoClass, 1416 );    // ClassProperty
	checkOffset( APawn, PlayerReplicationInfo, 1424 );         // ObjectProperty
	checkOffset( APawn, Shadow, 1432 );                        // ObjectProperty

	// GameInfo: script size 2144
	checkOffset( AGameInfo, ItemGoals, 680 );                  // IntProperty
	checkOffset( AGameInfo, KillGoals, 684 );                  // IntProperty
	checkOffset( AGameInfo, SecretGoals, 688 );                // IntProperty
	checkOffset( AGameInfo, Difficulty, 692 );                 // ByteProperty
	checkOffset( AGameInfo, AutoAim, 700 );                    // FloatProperty
	checkOffset( AGameInfo, GameSpeed, 704 );                  // FloatProperty
	checkOffset( AGameInfo, StartTime, 708 );                  // FloatProperty
	checkOffset( AGameInfo, DefaultPlayerClass, 712 );         // ClassProperty
	checkOffset( AGameInfo, DefaultWeapon, 720 );              // ClassProperty
	checkOffset( AGameInfo, MaxSpectators, 728 );              // IntProperty
	checkOffset( AGameInfo, NumSpectators, 732 );              // IntProperty
	checkOffset( AGameInfo, AdminPassword, 736 );              // StrProperty
	checkOffset( AGameInfo, GamePassword, 752 );               // StrProperty
	checkOffset( AGameInfo, ScoreBoardType, 768 );             // ClassProperty
	checkOffset( AGameInfo, GameMenuType, 776 );               // ClassProperty
	checkOffset( AGameInfo, BotMenuType, 784 );                // StrProperty
	checkOffset( AGameInfo, RulesMenuType, 800 );              // StrProperty
	checkOffset( AGameInfo, SettingsMenuType, 816 );           // StrProperty
	checkOffset( AGameInfo, GameUMenuType, 832 );              // StrProperty
	checkOffset( AGameInfo, MultiplayerUMenuType, 848 );       // StrProperty
	checkOffset( AGameInfo, GameOptionsMenuType, 864 );        // StrProperty
	checkOffset( AGameInfo, HUDType, 880 );                    // ClassProperty
	checkOffset( AGameInfo, MapListType, 888 );                // ClassProperty
	checkOffset( AGameInfo, MapPrefix, 896 );                  // StrProperty
	checkOffset( AGameInfo, BeaconName, 912 );                 // StrProperty
	checkOffset( AGameInfo, SpecialDamageString, 928 );        // StrProperty
	checkOffset( AGameInfo, SwitchLevelMessage, 944 );         // StrProperty
	checkOffset( AGameInfo, SentText, 960 );                   // IntProperty
	checkOffset( AGameInfo, DefaultPlayerName, 964 );          // StrProperty
	checkOffset( AGameInfo, LeftMessage, 980 );                // StrProperty
	checkOffset( AGameInfo, FailedSpawnMessage, 996 );         // StrProperty
	checkOffset( AGameInfo, FailedPlaceMessage, 1012 );        // StrProperty
	checkOffset( AGameInfo, FailedTeamMessage, 1028 );         // StrProperty
	checkOffset( AGameInfo, NameChangedMessage, 1044 );        // StrProperty
	checkOffset( AGameInfo, EnteredMessage, 1060 );            // StrProperty
	checkOffset( AGameInfo, GameName, 1076 );                  // StrProperty
	checkOffset( AGameInfo, MaxedOutMessage, 1092 );           // StrProperty
	checkOffset( AGameInfo, WrongPassword, 1108 );             // StrProperty
	checkOffset( AGameInfo, NeedPassword, 1124 );              // StrProperty
	checkOffset( AGameInfo, IPBanned, 1140 );                  // StrProperty
	checkOffset( AGameInfo, MaxPlayers, 1156 );                // IntProperty
	checkOffset( AGameInfo, NumPlayers, 1160 );                // IntProperty
	checkOffset( AGameInfo, CurrentID, 1164 );                 // IntProperty
	checkOffset( AGameInfo, IPPolicies, 1168 );                // StrProperty
	checkOffset( AGameInfo, DeathMessageClass, 1968 );         // ClassProperty
	checkOffset( AGameInfo, DMMessageClass, 1976 );            // ClassProperty
	checkOffset( AGameInfo, MutatorClass, 1984 );              // ClassProperty
	checkOffset( AGameInfo, BaseMutator, 1992 );               // ObjectProperty
	checkOffset( AGameInfo, DamageMutator, 2000 );             // ObjectProperty
	checkOffset( AGameInfo, MessageMutator, 2008 );            // ObjectProperty
	checkOffset( AGameInfo, WaterZoneType, 2016 );             // ClassProperty
	checkOffset( AGameInfo, DefaultPlayerState, 2024 );        // NameProperty
	checkOffset( AGameInfo, GameReplicationInfoClass, 2028 );  // ClassProperty
	checkOffset( AGameInfo, GameReplicationInfo, 2036 );       // ObjectProperty
	checkOffset( AGameInfo, ServerLogName, 2044 );             // StrProperty
	checkOffset( AGameInfo, LocalLog, 2060 );                  // ObjectProperty
	checkOffset( AGameInfo, WorldLog, 2068 );                  // ObjectProperty
	checkOffset( AGameInfo, LocalLogFileName, 2080 );          // StrProperty
	checkOffset( AGameInfo, WorldLogFileName, 2096 );          // StrProperty
	checkOffset( AGameInfo, StatLogClass, 2112 );              // ClassProperty
	checkOffset( AGameInfo, DemoBuild, 2120 );                 // IntProperty
	checkOffset( AGameInfo, DemoHasTuts, 2124 );               // IntProperty
	checkOffset( AGameInfo, EnabledMutators, 2128 );           // StrProperty

	// PlayerReplicationInfo: script size 808
	checkOffset( APlayerReplicationInfo, PlayerName, 680 );    // StrProperty
	checkOffset( APlayerReplicationInfo, OldName, 696 );       // StrProperty
	checkOffset( APlayerReplicationInfo, PlayerID, 712 );      // IntProperty
	checkOffset( APlayerReplicationInfo, TeamName, 716 );      // StrProperty
	checkOffset( APlayerReplicationInfo, Team, 732 );          // ByteProperty
	checkOffset( APlayerReplicationInfo, TeamID, 736 );        // IntProperty
	checkOffset( APlayerReplicationInfo, Score, 740 );         // FloatProperty
	checkOffset( APlayerReplicationInfo, Deaths, 744 );        // FloatProperty
	checkOffset( APlayerReplicationInfo, VoiceType, 748 );     // ClassProperty
	checkOffset( APlayerReplicationInfo, HasFlag, 756 );       // ObjectProperty
	checkOffset( APlayerReplicationInfo, Ping, 764 );          // IntProperty
	checkOffset( APlayerReplicationInfo, PacketLoss, 768 );    // ByteProperty
	checkOffset( APlayerReplicationInfo, TalkTexture, 776 );   // ObjectProperty
	checkOffset( APlayerReplicationInfo, PlayerZone, 784 );    // ObjectProperty
	checkOffset( APlayerReplicationInfo, PlayerLocation, 792 );// ObjectProperty
	checkOffset( APlayerReplicationInfo, StartTime, 800 );     // IntProperty
	checkOffset( APlayerReplicationInfo, TimeAcc, 804 );       // IntProperty

	// Teleporter: script size 1132
	checkOffset( ATeleporter, URL, 1076 );                     // StrProperty
	checkOffset( ATeleporter, ProductRequired, 1092 );         // NameProperty
	checkOffset( ATeleporter, TargetVelocity, 1100 );          // StructProperty
	checkOffset( ATeleporter, TriggerActor, 1112 );            // ObjectProperty
	checkOffset( ATeleporter, TriggerActor2, 1120 );           // ObjectProperty
	checkOffset( ATeleporter, LastFired, 1128 );               // FloatProperty

	// Inventory: script size 980
	checkOffset( AInventory, AutoSwitchPriority, 680 );        // ByteProperty
	checkOffset( AInventory, InventoryGroup, 681 );            // ByteProperty
	checkOffset( AInventory, PickupMessage, 688 );             // StrProperty
	checkOffset( AInventory, ItemName, 704 );                  // StrProperty
	checkOffset( AInventory, ItemArticle, 720 );               // StrProperty
	checkOffset( AInventory, RespawnTime, 736 );               // FloatProperty
	checkOffset( AInventory, PlayerLastTouched, 740 );         // NameProperty
	checkOffset( AInventory, PlayerViewOffset, 744 );          // StructProperty
	checkOffset( AInventory, PlayerViewMesh, 756 );            // ObjectProperty
	checkOffset( AInventory, PlayerViewScale, 764 );           // FloatProperty
	checkOffset( AInventory, BobDamping, 768 );                // FloatProperty
	checkOffset( AInventory, PickupViewMesh, 772 );            // ObjectProperty
	checkOffset( AInventory, PickupViewScale, 780 );           // FloatProperty
	checkOffset( AInventory, ThirdPersonMesh, 784 );           // ObjectProperty
	checkOffset( AInventory, ThirdPersonScale, 792 );          // FloatProperty
	checkOffset( AInventory, StatusIcon, 796 );                // ObjectProperty
	checkOffset( AInventory, ProtectionType1, 804 );           // NameProperty
	checkOffset( AInventory, ProtectionType2, 808 );           // NameProperty
	checkOffset( AInventory, Charge, 812 );                    // IntProperty
	checkOffset( AInventory, ArmorAbsorption, 816 );           // IntProperty
	checkOffset( AInventory, AbsorptionPriority, 824 );        // IntProperty
	checkOffset( AInventory, NextArmor, 828 );                 // ObjectProperty
	checkOffset( AInventory, MaxDesireability, 836 );          // FloatProperty
	checkOffset( AInventory, myMarker, 840 );                  // ObjectProperty
	checkOffset( AInventory, FlashCount, 852 );                // ByteProperty
	checkOffset( AInventory, OldFlashCount, 853 );             // ByteProperty
	checkOffset( AInventory, MuzzleFlashStyle, 854 );          // ByteProperty
	checkOffset( AInventory, MuzzleFlashMesh, 856 );           // ObjectProperty
	checkOffset( AInventory, MuzzleFlashScale, 864 );          // FloatProperty
	checkOffset( AInventory, MuzzleFlashTexture, 868 );        // ObjectProperty
	checkOffset( AInventory, PickupSound, 876 );               // ObjectProperty
	checkOffset( AInventory, ActivateSound, 884 );             // ObjectProperty
	checkOffset( AInventory, DeActivateSound, 892 );           // ObjectProperty
	checkOffset( AInventory, RespawnSound, 900 );              // ObjectProperty
	checkOffset( AInventory, Icon, 908 );                      // ObjectProperty
	checkOffset( AInventory, M_Activated, 916 );               // StrProperty
	checkOffset( AInventory, M_Selected, 932 );                // StrProperty
	checkOffset( AInventory, M_Deactivated, 948 );             // StrProperty
	checkOffset( AInventory, PickupMessageClass, 964 );        // ClassProperty
	checkOffset( AInventory, ItemMessageClass, 972 );          // ClassProperty

	// Mutator: script size 724
	checkOffset( AMutator, NextMutator, 680 );                 // ObjectProperty
	checkOffset( AMutator, NextDamageMutator, 688 );           // ObjectProperty
	checkOffset( AMutator, NextMessageMutator, 696 );          // ObjectProperty
	checkOffset( AMutator, NextHUDMutator, 704 );              // ObjectProperty
	checkOffset( AMutator, DefaultWeapon, 716 );               // ClassProperty

	// locationid: script size 708
	checkOffset( Alocationid, LocationName, 680 );             // StrProperty
	checkOffset( Alocationid, Radius, 696 );                   // FloatProperty
	checkOffset( Alocationid, NextLocation, 700 );             // ObjectProperty

	// SpawnNotify: script size 696
	checkOffset( ASpawnNotify, ActorClass, 680 );              // ClassProperty
	checkOffset( ASpawnNotify, Next, 688 );                    // ObjectProperty

	// PlayerPawn: script size 2368
	checkOffset( APlayerPawn, Player, 1440 );                  // ObjectProperty
	checkOffset( APlayerPawn, Password, 1448 );                // StrProperty
	checkOffset( APlayerPawn, DodgeClickTimer, 1464 );         // FloatProperty
	checkOffset( APlayerPawn, DodgeClickTime, 1468 );          // FloatProperty
	checkOffset( APlayerPawn, Bob, 1472 );                     // FloatProperty
	checkOffset( APlayerPawn, LandBob, 1476 );                 // FloatProperty
	checkOffset( APlayerPawn, AppliedBob, 1480 );              // FloatProperty
	checkOffset( APlayerPawn, bobtime, 1484 );                 // FloatProperty
	checkOffset( APlayerPawn, ShowFlags, 1488 );               // IntProperty
	checkOffset( APlayerPawn, RendMap, 1492 );                 // IntProperty
	checkOffset( APlayerPawn, Misc1, 1496 );                   // IntProperty
	checkOffset( APlayerPawn, Misc2, 1500 );                   // IntProperty
	checkOffset( APlayerPawn, ViewTarget, 1504 );              // ObjectProperty
	checkOffset( APlayerPawn, FlashScale, 1512 );              // StructProperty
	checkOffset( APlayerPawn, FlashFog, 1524 );                // StructProperty
	checkOffset( APlayerPawn, myHUD, 1536 );                   // ObjectProperty
	checkOffset( APlayerPawn, Scoring, 1544 );                 // ObjectProperty
	checkOffset( APlayerPawn, HUDType, 1552 );                 // ClassProperty
	checkOffset( APlayerPawn, ScoringType, 1560 );             // ClassProperty
	checkOffset( APlayerPawn, DesiredFlashScale, 1568 );       // FloatProperty
	checkOffset( APlayerPawn, ConstantGlowScale, 1572 );       // FloatProperty
	checkOffset( APlayerPawn, InstantFlash, 1576 );            // FloatProperty
	checkOffset( APlayerPawn, DesiredFlashFog, 1580 );         // StructProperty
	checkOffset( APlayerPawn, ConstantGlowFog, 1592 );         // StructProperty
	checkOffset( APlayerPawn, InstantFog, 1604 );              // StructProperty
	checkOffset( APlayerPawn, DesiredFOV, 1616 );              // FloatProperty
	checkOffset( APlayerPawn, DefaultFOV, 1620 );              // FloatProperty
	checkOffset( APlayerPawn, Song, 1624 );                    // ObjectProperty
	checkOffset( APlayerPawn, SongSection, 1632 );             // ByteProperty
	checkOffset( APlayerPawn, CdTrack, 1633 );                 // ByteProperty
	checkOffset( APlayerPawn, Transition, 1634 );              // ByteProperty
	checkOffset( APlayerPawn, shaketimer, 1636 );              // FloatProperty
	checkOffset( APlayerPawn, shakemag, 1640 );                // IntProperty
	checkOffset( APlayerPawn, shakevert, 1644 );               // FloatProperty
	checkOffset( APlayerPawn, maxshake, 1648 );                // FloatProperty
	checkOffset( APlayerPawn, verttimer, 1652 );               // FloatProperty
	checkOffset( APlayerPawn, CarcassType, 1656 );             // ClassProperty
	checkOffset( APlayerPawn, MyAutoAim, 1664 );               // FloatProperty
	checkOffset( APlayerPawn, Handedness, 1668 );              // FloatProperty
	checkOffset( APlayerPawn, JumpSound, 1672 );               // ObjectProperty
	checkOffset( APlayerPawn, ZoomLevel, 1688 );               // FloatProperty
	checkOffset( APlayerPawn, SpecialMenu, 1692 );             // ClassProperty
	checkOffset( APlayerPawn, DelayedCommand, 1700 );          // StrProperty
	checkOffset( APlayerPawn, MouseSensitivity, 1716 );        // FloatProperty
	checkOffset( APlayerPawn, WeaponPriority, 1720 );          // NameProperty
	checkOffset( APlayerPawn, SmoothMouseX, 1920 );            // FloatProperty
	checkOffset( APlayerPawn, SmoothMouseY, 1924 );            // FloatProperty
	checkOffset( APlayerPawn, BorrowedMouseX, 1928 );          // FloatProperty
	checkOffset( APlayerPawn, BorrowedMouseY, 1932 );          // FloatProperty
	checkOffset( APlayerPawn, MouseSmoothThreshold, 1936 );    // FloatProperty
	checkOffset( APlayerPawn, MouseZeroTime, 1940 );           // FloatProperty
	checkOffset( APlayerPawn, aBaseX, 1944 );                  // FloatProperty
	checkOffset( APlayerPawn, aBaseY, 1948 );                  // FloatProperty
	checkOffset( APlayerPawn, aBaseZ, 1952 );                  // FloatProperty
	checkOffset( APlayerPawn, aMouseX, 1956 );                 // FloatProperty
	checkOffset( APlayerPawn, aMouseY, 1960 );                 // FloatProperty
	checkOffset( APlayerPawn, aForward, 1964 );                // FloatProperty
	checkOffset( APlayerPawn, aTurn, 1968 );                   // FloatProperty
	checkOffset( APlayerPawn, aStrafe, 1972 );                 // FloatProperty
	checkOffset( APlayerPawn, aUp, 1976 );                     // FloatProperty
	checkOffset( APlayerPawn, aLookUp, 1980 );                 // FloatProperty
	checkOffset( APlayerPawn, aExtra4, 1984 );                 // FloatProperty
	checkOffset( APlayerPawn, aExtra3, 1988 );                 // FloatProperty
	checkOffset( APlayerPawn, aExtra2, 1992 );                 // FloatProperty
	checkOffset( APlayerPawn, aExtra1, 1996 );                 // FloatProperty
	checkOffset( APlayerPawn, aExtra0, 2000 );                 // FloatProperty
	checkOffset( APlayerPawn, SavedMoves, 2004 );              // ObjectProperty
	checkOffset( APlayerPawn, FreeMoves, 2012 );               // ObjectProperty
	checkOffset( APlayerPawn, PendingMove, 2020 );             // ObjectProperty
	checkOffset( APlayerPawn, CurrentTimeStamp, 2028 );        // FloatProperty
	checkOffset( APlayerPawn, LastUpdateTime, 2032 );          // FloatProperty
	checkOffset( APlayerPawn, ServerTimeStamp, 2036 );         // FloatProperty
	checkOffset( APlayerPawn, TimeMargin, 2040 );              // FloatProperty
	checkOffset( APlayerPawn, ClientUpdateTime, 2044 );        // FloatProperty
	checkOffset( APlayerPawn, MaxTimeMargin, 2048 );           // FloatProperty
	checkOffset( APlayerPawn, ProgressMessage, 2052 );         // StrProperty
	checkOffset( APlayerPawn, ProgressColor, 2180 );           // StructProperty
	checkOffset( APlayerPawn, ProgressTimeOut, 2212 );         // FloatProperty
	checkOffset( APlayerPawn, QuickSaveString, 2216 );         // StrProperty
	checkOffset( APlayerPawn, NoPauseMessage, 2232 );          // StrProperty
	checkOffset( APlayerPawn, ViewingFrom, 2248 );             // StrProperty
	checkOffset( APlayerPawn, OwnCamera, 2264 );               // StrProperty
	checkOffset( APlayerPawn, FailedView, 2280 );              // StrProperty
	checkOffset( APlayerPawn, GameReplicationInfo, 2296 );     // ObjectProperty
	checkOffset( APlayerPawn, ngWorldSecret, 2304 );           // StrProperty
	checkOffset( APlayerPawn, TargetViewRotation, 2324 );      // StructProperty
	checkOffset( APlayerPawn, TargetEyeHeight, 2336 );         // FloatProperty
	checkOffset( APlayerPawn, TargetWeaponViewOffset, 2340 );  // StructProperty
	checkOffset( APlayerPawn, DemoViewPitch, 2352 );           // IntProperty
	checkOffset( APlayerPawn, DemoViewYaw, 2356 );             // IntProperty
	checkOffset( APlayerPawn, LastPlaySound, 2360 );           // FloatProperty
	checkOffset( APlayerPawn, LastMessageWindow, 2364 );       // FloatProperty

	// Decoration: script size 740
	checkOffset( ADecoration, EffectWhenDestroyed, 680 );      // ClassProperty
	checkOffset( ADecoration, PushSound, 692 );                // ObjectProperty
	checkOffset( ADecoration, numLandings, 700 );              // IntProperty
	checkOffset( ADecoration, contents, 704 );                 // ClassProperty
	checkOffset( ADecoration, content2, 712 );                 // ClassProperty
	checkOffset( ADecoration, content3, 720 );                 // ClassProperty
	checkOffset( ADecoration, EndPushSound, 728 );             // ObjectProperty

	// Carcass: script size 772
	checkOffset( ACarcass, flies, 744 );                       // ByteProperty
	checkOffset( ACarcass, rats, 745 );                        // ByteProperty
	checkOffset( ACarcass, CumulativeDamage, 752 );            // IntProperty
	checkOffset( ACarcass, PlayerOwner, 756 );                 // ObjectProperty
	checkOffset( ACarcass, Bugs, 764 );                        // ObjectProperty

	// Brush: script size 776
	checkOffset( ABrush, CsgOper, 680 );                       // ByteProperty
	checkOffset( ABrush, UnusedLightMesh, 684 );               // ObjectProperty
	checkOffset( ABrush, PostPivot, 692 );                     // StructProperty
	checkOffset( ABrush, MainScale, 704 );                     // StructProperty
	checkOffset( ABrush, PostScale, 724 );                     // StructProperty
	checkOffset( ABrush, TempScale, 744 );                     // StructProperty
	checkOffset( ABrush, BrushColor, 764 );                    // StructProperty
	checkOffset( ABrush, PolyFlags, 768 );                     // IntProperty

	// Mover: script size 1276
	checkOffset( AMover, MoverEncroachType, 776 );             // ByteProperty
	checkOffset( AMover, MoverGlideType, 777 );                // ByteProperty
	checkOffset( AMover, BumpType, 778 );                      // ByteProperty
	checkOffset( AMover, KeyNum, 779 );                        // ByteProperty
	checkOffset( AMover, PrevKeyNum, 780 );                    // ByteProperty
	checkOffset( AMover, NumKeys, 781 );                       // ByteProperty
	checkOffset( AMover, WorldRaytraceKey, 782 );              // ByteProperty
	checkOffset( AMover, BrushRaytraceKey, 783 );              // ByteProperty
	checkOffset( AMover, MoveTime, 784 );                      // FloatProperty
	checkOffset( AMover, StayOpenTime, 788 );                  // FloatProperty
	checkOffset( AMover, OtherTime, 792 );                     // FloatProperty
	checkOffset( AMover, EncroachDamage, 796 );                // IntProperty
	checkOffset( AMover, PlayerBumpEvent, 804 );               // NameProperty
	checkOffset( AMover, BumpEvent, 808 );                     // NameProperty
	checkOffset( AMover, SavedTrigger, 812 );                  // ObjectProperty
	checkOffset( AMover, DamageThreshold, 820 );               // FloatProperty
	checkOffset( AMover, numTriggerEvents, 824 );              // IntProperty
	checkOffset( AMover, Leader, 828 );                        // ObjectProperty
	checkOffset( AMover, Follower, 836 );                      // ObjectProperty
	checkOffset( AMover, ReturnGroup, 844 );                   // NameProperty
	checkOffset( AMover, DelayTime, 848 );                     // FloatProperty
	checkOffset( AMover, OpeningSound, 852 );                  // ObjectProperty
	checkOffset( AMover, OpenedSound, 860 );                   // ObjectProperty
	checkOffset( AMover, ClosingSound, 868 );                  // ObjectProperty
	checkOffset( AMover, ClosedSound, 876 );                   // ObjectProperty
	checkOffset( AMover, MoveAmbientSound, 884 );              // ObjectProperty
	checkOffset( AMover, KeyPos, 892 );                        // StructProperty
	checkOffset( AMover, KeyRot, 988 );                        // StructProperty
	checkOffset( AMover, BasePos, 1084 );                      // StructProperty
	checkOffset( AMover, OldPos, 1096 );                       // StructProperty
	checkOffset( AMover, OldPrePivot, 1108 );                  // StructProperty
	checkOffset( AMover, SavedPos, 1120 );                     // StructProperty
	checkOffset( AMover, BaseRot, 1132 );                      // StructProperty
	checkOffset( AMover, OldRot, 1144 );                       // StructProperty
	checkOffset( AMover, SavedRot, 1156 );                     // StructProperty
	checkOffset( AMover, myMarker, 1168 );                     // ObjectProperty
	checkOffset( AMover, TriggerActor, 1176 );                 // ObjectProperty
	checkOffset( AMover, TriggerActor2, 1184 );                // ObjectProperty
	checkOffset( AMover, WaitingPawn, 1192 );                  // ObjectProperty
	checkOffset( AMover, RecommendedTrigger, 1204 );           // ObjectProperty
	checkOffset( AMover, SimOldPos, 1212 );                    // StructProperty
	checkOffset( AMover, SimOldRotPitch, 1224 );               // IntProperty
	checkOffset( AMover, SimOldRotYaw, 1228 );                 // IntProperty
	checkOffset( AMover, SimOldRotRoll, 1232 );                // IntProperty
	checkOffset( AMover, SimInterpolate, 1236 );               // StructProperty
	checkOffset( AMover, RealPosition, 1248 );                 // StructProperty
	checkOffset( AMover, RealRotation, 1260 );                 // StructProperty
	checkOffset( AMover, ClientUpdate, 1272 );                 // IntProperty

	// Weapon: script size 1248
	checkOffset( AWeapon, MaxTargetRange, 980 );               // FloatProperty
	checkOffset( AWeapon, AmmoName, 984 );                     // ClassProperty
	checkOffset( AWeapon, ReloadCount, 992 );                  // ByteProperty
	checkOffset( AWeapon, PickupAmmoCount, 996 );              // IntProperty
	checkOffset( AWeapon, AmmoType, 1000 );                    // ObjectProperty
	checkOffset( AWeapon, FiringSpeed, 1012 );                 // FloatProperty
	checkOffset( AWeapon, FireOffset, 1016 );                  // StructProperty
	checkOffset( AWeapon, ProjectileClass, 1028 );             // ClassProperty
	checkOffset( AWeapon, AltProjectileClass, 1036 );          // ClassProperty
	checkOffset( AWeapon, MyDamageType, 1044 );                // NameProperty
	checkOffset( AWeapon, AltDamageType, 1048 );               // NameProperty
	checkOffset( AWeapon, ProjectileSpeed, 1052 );             // FloatProperty
	checkOffset( AWeapon, AltProjectileSpeed, 1056 );          // FloatProperty
	checkOffset( AWeapon, aimerror, 1060 );                    // FloatProperty
	checkOffset( AWeapon, shakemag, 1064 );                    // FloatProperty
	checkOffset( AWeapon, shaketime, 1068 );                   // FloatProperty
	checkOffset( AWeapon, shakevert, 1072 );                   // FloatProperty
	checkOffset( AWeapon, AIRating, 1076 );                    // FloatProperty
	checkOffset( AWeapon, RefireRate, 1080 );                  // FloatProperty
	checkOffset( AWeapon, AltRefireRate, 1084 );               // FloatProperty
	checkOffset( AWeapon, FireSound, 1088 );                   // ObjectProperty
	checkOffset( AWeapon, AltFireSound, 1096 );                // ObjectProperty
	checkOffset( AWeapon, CockingSound, 1104 );                // ObjectProperty
	checkOffset( AWeapon, SelectSound, 1112 );                 // ObjectProperty
	checkOffset( AWeapon, Misc1Sound, 1120 );                  // ObjectProperty
	checkOffset( AWeapon, Misc2Sound, 1128 );                  // ObjectProperty
	checkOffset( AWeapon, Misc3Sound, 1136 );                  // ObjectProperty
	checkOffset( AWeapon, MessageNoAmmo, 1144 );               // StrProperty
	checkOffset( AWeapon, DeathMessage, 1160 );                // StrProperty
	checkOffset( AWeapon, NameColor, 1176 );                   // StructProperty
	checkOffset( AWeapon, AdjustedAim, 1180 );                 // StructProperty
	checkOffset( AWeapon, bMuzzleFlash, 1196 );                // ByteProperty
	checkOffset( AWeapon, FlashTime, 1200 );                   // FloatProperty
	checkOffset( AWeapon, MuzzleScale, 1204 );                 // FloatProperty
	checkOffset( AWeapon, FlashY, 1208 );                      // FloatProperty
	checkOffset( AWeapon, FlashO, 1212 );                      // FloatProperty
	checkOffset( AWeapon, FlashC, 1216 );                      // FloatProperty
	checkOffset( AWeapon, FlashLength, 1220 );                 // FloatProperty
	checkOffset( AWeapon, FlashS, 1224 );                      // IntProperty
	checkOffset( AWeapon, MFTexture, 1228 );                   // ObjectProperty
	checkOffset( AWeapon, MuzzleFlare, 1236 );                 // ObjectProperty
	checkOffset( AWeapon, FlareOffset, 1244 );                 // FloatProperty

	// Decal: script size 704
	checkOffset( ADecal, MultiDecalLevel, 680 );               // IntProperty
	checkOffset( ADecal, LastRenderedTime, 684 );              // FloatProperty
	checkOffset( ADecal, SurfList, 688 );                      // ArrayProperty

	// StatLog: script size 956
	checkOffset( AStatLog, Context, 680 );                     // IntProperty
	checkOffset( AStatLog, TimeStamp, 692 );                   // FloatProperty
	checkOffset( AStatLog, LocalStandard, 696 );               // StrProperty
	checkOffset( AStatLog, WorldStandard, 712 );               // StrProperty
	checkOffset( AStatLog, LogVersion, 728 );                  // StrProperty
	checkOffset( AStatLog, LogInfoURL, 744 );                  // StrProperty
	checkOffset( AStatLog, GameName, 760 );                    // StrProperty
	checkOffset( AStatLog, GameCreator, 776 );                 // StrProperty
	checkOffset( AStatLog, GameCreatorURL, 792 );              // StrProperty
	checkOffset( AStatLog, DecoderRingURL, 808 );              // StrProperty
	checkOffset( AStatLog, LocalBatcherURL, 824 );             // StrProperty
	checkOffset( AStatLog, LocalBatcherParams, 840 );          // StrProperty
	checkOffset( AStatLog, LocalStatsURL, 856 );               // StrProperty
	checkOffset( AStatLog, WorldBatcherURL, 872 );             // StrProperty
	checkOffset( AStatLog, WorldBatcherParams, 888 );          // StrProperty
	checkOffset( AStatLog, WorldStatsURL, 904 );               // StrProperty
	checkOffset( AStatLog, LocalLogDir, 920 );                 // StrProperty
	checkOffset( AStatLog, WorldLogDir, 936 );                 // StrProperty

	// GameReplicationInfo: script size 1148
	checkOffset( AGameReplicationInfo, GameName, 680 );        // StrProperty
	checkOffset( AGameReplicationInfo, GameClass, 696 );       // StrProperty
	checkOffset( AGameReplicationInfo, RemainingTime, 716 );   // IntProperty
	checkOffset( AGameReplicationInfo, ElapsedTime, 720 );     // IntProperty
	checkOffset( AGameReplicationInfo, RemainingMinute, 724 ); // IntProperty
	checkOffset( AGameReplicationInfo, SecondCount, 728 );     // FloatProperty
	checkOffset( AGameReplicationInfo, NumPlayers, 732 );      // IntProperty
	checkOffset( AGameReplicationInfo, SumFrags, 736 );        // IntProperty
	checkOffset( AGameReplicationInfo, UpdateTimer, 740 );     // FloatProperty
	checkOffset( AGameReplicationInfo, ServerName, 744 );      // StrProperty
	checkOffset( AGameReplicationInfo, ShortName, 760 );       // StrProperty
	checkOffset( AGameReplicationInfo, AdminName, 776 );       // StrProperty
	checkOffset( AGameReplicationInfo, AdminEmail, 792 );      // StrProperty
	checkOffset( AGameReplicationInfo, Region, 808 );          // IntProperty
	checkOffset( AGameReplicationInfo, MOTDLine1, 812 );       // StrProperty
	checkOffset( AGameReplicationInfo, MOTDLine2, 828 );       // StrProperty
	checkOffset( AGameReplicationInfo, MOTDLine3, 844 );       // StrProperty
	checkOffset( AGameReplicationInfo, MOTDLine4, 860 );       // StrProperty
	checkOffset( AGameReplicationInfo, GameEndedComments, 876 );// StrProperty
	checkOffset( AGameReplicationInfo, PRIArray, 892 );        // ObjectProperty

	// Menu: script size 1604
	checkOffset( AMenu, ParentMenu, 680 );                     // ObjectProperty
	checkOffset( AMenu, Selection, 688 );                      // IntProperty
	checkOffset( AMenu, MenuLength, 692 );                     // IntProperty
	checkOffset( AMenu, PlayerOwner, 700 );                    // ObjectProperty
	checkOffset( AMenu, HelpMessage, 708 );                    // StrProperty
	checkOffset( AMenu, MenuList, 1092 );                      // StrProperty
	checkOffset( AMenu, LeftString, 1476 );                    // StrProperty
	checkOffset( AMenu, RightString, 1492 );                   // StrProperty
	checkOffset( AMenu, CenterString, 1508 );                  // StrProperty
	checkOffset( AMenu, EnabledString, 1524 );                 // StrProperty
	checkOffset( AMenu, DisabledString, 1540 );                // StrProperty
	checkOffset( AMenu, MenuTitle, 1556 );                     // StrProperty
	checkOffset( AMenu, YesString, 1572 );                     // StrProperty
	checkOffset( AMenu, NoString, 1588 );                      // StrProperty

	// HUD: script size 740
	checkOffset( AHUD, HudMode, 680 );                         // IntProperty
	checkOffset( AHUD, Crosshair, 684 );                       // IntProperty
	checkOffset( AHUD, MainMenuType, 688 );                    // ClassProperty
	checkOffset( AHUD, HUDConfigWindowType, 696 );             // StrProperty
	checkOffset( AHUD, WhiteColor, 712 );                      // StructProperty
	checkOffset( AHUD, MainMenu, 716 );                        // ObjectProperty
	checkOffset( AHUD, HUDMutator, 724 );                      // ObjectProperty
	checkOffset( AHUD, PlayerOwner, 732 );                     // ObjectProperty

	// StatLogFile: script size 1000
	checkOffset( AStatLogFile, LogAr, 960 );                   // IntProperty
	checkOffset( AStatLogFile, StatLogFile, 968 );             // StrProperty
	checkOffset( AStatLogFile, StatLogFinal, 984 );            // StrProperty

	// InventorySpot: script size 1084
	checkOffset( AInventorySpot, markedItem, 1076 );           // ObjectProperty

	// SavedMove: script size 704
	checkOffset( ASavedMove, NextMove, 680 );                  // ObjectProperty
	checkOffset( ASavedMove, TimeStamp, 688 );                 // FloatProperty
	checkOffset( ASavedMove, Delta, 692 );                     // FloatProperty
	checkOffset( ASavedMove, DodgeMove, 700 );                 // ByteProperty

	// Pickup: script size 1016
	checkOffset( APickup, Inv, 980 );                          // ObjectProperty
	checkOffset( APickup, NumCopies, 988 );                    // IntProperty
	checkOffset( APickup, ExpireMessage, 996 );                // StrProperty

	// Ammo: script size 1052
	checkOffset( AAmmo, AmmoAmount, 1016 );                    // IntProperty
	checkOffset( AAmmo, MaxAmmo, 1020 );                       // IntProperty
	checkOffset( AAmmo, ParentAmmo, 1024 );                    // ClassProperty
	checkOffset( AAmmo, UsedInWeaponSlot, 1032 );              // ByteProperty
	checkOffset( AAmmo, PAmmo, 1044 );                         // ObjectProperty

	// Projectile: script size 736
	checkOffset( AProjectile, speed, 680 );                    // FloatProperty
	checkOffset( AProjectile, MaxSpeed, 684 );                 // FloatProperty
	checkOffset( AProjectile, Damage, 688 );                   // FloatProperty
	checkOffset( AProjectile, MomentumTransfer, 692 );         // IntProperty
	checkOffset( AProjectile, MyDamageType, 696 );             // NameProperty
	checkOffset( AProjectile, SpawnSound, 700 );               // ObjectProperty
	checkOffset( AProjectile, ImpactSound, 708 );              // ObjectProperty
	checkOffset( AProjectile, MiscSound, 716 );                // ObjectProperty
	checkOffset( AProjectile, ExploWallOut, 724 );             // FloatProperty
	checkOffset( AProjectile, ExplosionDecal, 728 );           // ClassProperty

	// Trigger: script size 744
	checkOffset( ATrigger, TriggerType, 680 );                 // ByteProperty
	checkOffset( ATrigger, Message, 684 );                     // StrProperty
	checkOffset( ATrigger, ClassProximityType, 704 );          // ClassProperty
	checkOffset( ATrigger, RepeatTriggerTime, 712 );           // FloatProperty
	checkOffset( ATrigger, ReTriggerDelay, 716 );              // FloatProperty
	checkOffset( ATrigger, TriggerTime, 720 );                 // FloatProperty
	checkOffset( ATrigger, DamageThreshold, 724 );             // FloatProperty
	checkOffset( ATrigger, TriggerActor, 728 );                // ObjectProperty
	checkOffset( ATrigger, TriggerActor2, 736 );               // ObjectProperty

	// LiftCenter: script size 1124
	checkOffset( ALiftCenter, LiftTag, 1076 );                 // NameProperty
	checkOffset( ALiftCenter, MyLift, 1080 );                  // ObjectProperty
	checkOffset( ALiftCenter, LiftTrigger, 1088 );             // NameProperty
	checkOffset( ALiftCenter, RecommendedTrigger, 1092 );      // ObjectProperty
	checkOffset( ALiftCenter, LastTriggerTime, 1100 );         // FloatProperty
	checkOffset( ALiftCenter, MaxZDiffAdd, 1104 );             // FloatProperty
	checkOffset( ALiftCenter, MaxDist2D, 1108 );               // FloatProperty
	checkOffset( ALiftCenter, LiftOffset, 1112 );              // StructProperty

	// LiftExit: script size 1104
	checkOffset( ALiftExit, LiftTag, 1076 );                   // NameProperty
	checkOffset( ALiftExit, MyLift, 1080 );                    // ObjectProperty
	checkOffset( ALiftExit, LiftTrigger, 1088 );               // NameProperty
	checkOffset( ALiftExit, RecommendedTrigger, 1092 );        // ObjectProperty
	checkOffset( ALiftExit, LastTriggerTime, 1100 );           // FloatProperty
}
