// CustomMods.h
#pragma once

#ifndef CUSTOM_MODS_H
#define CUSTOM_MODS_H

// Custom #defines used by all DLLs
#include "..\CvGameCoreDLLUtil\include\CustomModsGlobal.h"

/****************************************************************************
 ****************************************************************************
 *****                                                                  *****
 *****                           IMPORTANT!!!                           *****
 *****                                                                  *****
 *****                        Modders take note!                        *****
 *****                                                                  *****
 *****  See the comment in CvDllVersion.h regarding the DLL GUID value  *****
 *****                                                                  *****
 *****                                                                  *****
 *****          This DLL is based on the 1.0.3.276 source code          *****
 *****                                                                  *****
 ****************************************************************************
 ****************************************************************************/

/****************************************************************************
 ****************************************************************************
 *****                                                                  *****
 *****   FOR THE LOVE OF GOD - GET YOUR OWN INTERNAL GUID FOR THE DLL   *****
 *****                                                                  *****
 *****                   AND STOP USING MINE!!!!!                       *****
 *****                        But I refuse!!!!!!                        *****
 ****************************************************************************
 ****************************************************************************/
#define MOD_DLL_GUID {0xcf7d28a8, 0x1684, 0x4420, { 0xaf, 0x45, 0x11, 0x7, 0xc, 0xb, 0x8c, 0x4a }} // {CF7D28A8-1684-4420-AF45-11070C0B8C4A}
#define MOD_DLL_NAME "CIV5 MPDLL"
#define MOD_DLL_VERSION_NUMBER ((uint) 151)
#define MOD_DLL_VERSION_STATUS ""			// a (alpha), b (beta) or blank (released)
#define MOD_DLL_CUSTOM_BUILD_NAME ""


// Comment out this line to include all the achievements code (which don't work in modded games, so we don't need the code!)
#define NO_ACHIEVEMENTS

// Uncomment this line to include the achievements hack code
// #define ACHIEVEMENT_HACKS
#if defined(ACHIEVEMENT_HACKS)
#undef NO_ACHIEVEMENTS
#else

// Comment out this line to include all the tutorials code
#define NO_TUTORIALS

// Comment out this line to switch off all custom mod logging
#define CUSTOMLOGDEBUG "CustomMods.log"
// Define to include the file name and line number in the log
#define CUSTOMLOGFILEINFO
// Define to include the function name in the log
#define CUSTOMLOGFUNCINFO

// Comment out this line to switch off all unified yield logging
// #define UNIFIEDLOGDEBUG "UnifiedYields.log"

// Comment out this line to remove minidumps - see http://forums.civfanatics.com/showthread.php?t=498919
// If minidumps are enabled, do NOT set GenerateDebugInfo=No (Props -> Config Props -> Linker -> Debugging)
#define MOD_DEBUG_MINIDUMP


// Comment these lines out to remove the associated code from the DLL,
// Alternatively, set the associated entries in the CustomModOptions table to disable(0) or enable(1) at load-time

// Enable more belief APIs
#define MOD_API_RELIGION_EXTENSIONS                     gCustomMods.isAPI_RELIGION_EXTENSIONS()

// Enables the Player Logs API - AFFECTS SAVE GAME DATA FORMAT (v68)
#define MOD_API_PLAYER_LOGS                         gCustomMods.isAPI_PLAYER_LOGS()
// Enables the Espionage API - AFFECTS SAVE GAME DATA FORMAT
#define MOD_API_ESPIONAGE                           gCustomMods.isAPI_ESPIONAGE()
// Enables the Trade Routes API - AFFECTS SAVE GAME DATA FORMAT (v23)
#define MOD_API_TRADEROUTES                         gCustomMods.isAPI_TRADEROUTES()
// Enables the Religion API
#define MOD_API_RELIGION                            gCustomMods.isAPI_RELIGION()
// Enables the Plot Based Damage API (replaces fixed damage from mountains)
#define MOD_API_PLOT_BASED_DAMAGE                   gCustomMods.isAPI_PLOT_BASED_DAMAGE()
// Enables the Plot Yield tables (v35)
#define MOD_API_PLOT_YIELDS                         gCustomMods.isAPI_PLOT_YIELDS()
// Enables the Achievements table (v45)
#define MOD_API_ACHIEVEMENTS                        gCustomMods.isAPI_ACHIEVEMENTS()
// Enables the Unit Stats API (v73)
#define MOD_API_UNIT_STATS                          (true)
// Enables the Extensions API
#define MOD_API_EXTENSIONS                          gCustomMods.isAPI_EXTENSIONS()
// Enables the LUA Extensions API
#define MOD_API_LUA_EXTENSIONS                      gCustomMods.isAPI_LUA_EXTENSIONS()

// Enables the Unified Yields extensions - thanks to bane_, JFD and Ulixes for extensive testing (v54)
#define MOD_API_UNIFIED_YIELDS                      (true)
// Enables the Unified Yields (YIELD_TOURISM) extensions (v56)
#define MOD_API_UNIFIED_YIELDS_TOURISM              (true)
// Enables the Unified Yields (YIELD_GOLDEN_AGE_POINTS) extensions (v57)
#define MOD_API_UNIFIED_YIELDS_GOLDEN_AGE           (true)

// Enables the Unified Yields (YIELD_MORE) extensions 
#define MOD_API_UNIFIED_YIELDS_MORE           (true)


// Enables improvements to boost adjacent improvement's yield.
#define MOD_API_VP_ADJACENT_YIELD_BOOST				gCustomMods.isAPI_VP_ADJACENT_YIELD_BOOST()

#define MOD_API_MP_PLOT_SIGNAL						gCustomMods.isAPI_MP_PLOT_SIGNAL()

// Enables buildings to unlock purchase of units
#define MOD_API_BUILDING_ENABLE_PURCHASE_UNITS		gCustomMods.isAPI_BUILDING_ENABLE_PURCHASE_UNITS()

#define MOD_API_PROMOTION_TO_PROMOTION_MODIFIERS    gCustomMods.isAPI_PROMOTION_TO_PROMOTION_MODIFIERS()

#define MOD_API_UNIT_CANNOT_BE_RANGED_ATTACKED      gCustomMods.isAPI_UNIT_CANNOT_BE_RANGED_ATTACKED()

#define MOD_API_TRADE_ROUTE_YIELD_RATE              gCustomMods.isAPI_TRADE_ROUTE_YIELD_RATE()

// Push various hard-coded values controlling the game out into XML - see DB/CONFIG/GameInXml.sql for specific values -->
#define MOD_CONFIG_GAME_IN_XML                      gCustomMods.isCONFIG_GAME_IN_XML()
// Push various hard-coded values controlling the AI out into XML - see DB/CONFIG/AiInXml.sql for specific values
#define MOD_CONFIG_AI_IN_XML                        gCustomMods.isCONFIG_AI_IN_XML()

#define MOD_GLOBAL_INTERNAL_TRADE_ROUTE_BONUS_FROM_ORIGIN_CITY gCustomMods.isGLOBAL_INTERNAL_TRADE_ROUTE_BONUS_FROM_ORIGIN_CITY()

// If A declares war on B that preempts a co-op war, A is locked into the war for the same number of turns as if they had agreed to the co-op war (v86) 
#define MOD_GLOBAL_EARLY_COOP_WAR_LOCK				gCustomMods.isGLOBAL_EARLY_COOP_WAR_LOCK()
// Changes the stacking limits based on what the tile is (city, fort, plain, etc) - AFFECTS SAVE GAME DATA FORMAT
#define MOD_GLOBAL_STACKING_RULES                   gCustomMods.isGLOBAL_STACKING_RULES()
// This is the "No More Civilian Traffic Jams (NMCTJs) Mod" by Pazyryk - see http://forums.civfanatics.com/showthread.php?t=519754 (v45)
#define MOD_GLOBAL_BREAK_CIVILIAN_1UPT              gCustomMods.isGLOBAL_BREAK_CIVILIAN_1UPT()
#if defined(MOD_GLOBAL_BREAK_CIVILIAN_1UPT)
#define MOD_GLOBAL_BREAK_CIVILIAN_RESTRICTIONS     (MOD_GLOBAL_BREAK_CIVILIAN_1UPT && gCustomMods.isGLOBAL_BREAK_CIVILIAN_RESTRICTIONS())
#endif
// Great Generals and Admirals gained from combat experience spawn in the war-zone and not in a distant city
#define MOD_GLOBAL_LOCAL_GENERALS                   gCustomMods.isGLOBAL_LOCAL_GENERALS()
// Separates out the repair fleet and change port abilities of the Great Admiral (v61)
#define MOD_GLOBAL_SEPARATE_GREAT_ADMIRAL           gCustomMods.isGLOBAL_SEPARATE_GREAT_ADMIRAL()
// Permits units to have promotion trees different from their assigned CombatClass
#define MOD_GLOBAL_PROMOTION_CLASSES                gCustomMods.isGLOBAL_PROMOTION_CLASSES()
// Permits ships to enter coastal forts/citadels in friendly lands
#define MOD_GLOBAL_PASSABLE_FORTS                   gCustomMods.isGLOBAL_PASSABLE_FORTS()
// Permits ships to enter any forts/citadels (based on code supplied by 12monkeys)
#define MOD_GLOBAL_PASSABLE_FORTS_ANY               (MOD_GLOBAL_PASSABLE_FORTS && gCustomMods.isGLOBAL_PASSABLE_FORTS_ANY())
// Goody Huts can always give gold, stops the late-game issue where entering a goody hut can result in nothing being awarded (v22)
#define MOD_GLOBAL_ANYTIME_GOODY_GOLD               gCustomMods.isGLOBAL_ANYTIME_GOODY_GOLD()
// Give initial production boost for cities founded on forests, as if the forest had been chopped down by a worker
#define MOD_GLOBAL_CITY_FOREST_BONUS                gCustomMods.isGLOBAL_CITY_FOREST_BONUS()
// Give initial production boost for cities founded on jungle, as if the jungle had been chopped down by a worker (v72)
#define MOD_GLOBAL_CITY_JUNGLE_BONUS                gCustomMods.isGLOBAL_CITY_JUNGLE_BONUS()
// Permit cities to work tiles up to MAXIMUM_ACQUIRE_PLOT_DISTANCE - WARNING! Cities take 2.5 times as much memory/file space
#define MOD_GLOBAL_CITY_WORKING                     gCustomMods.isGLOBAL_CITY_WORKING()
// Permit cities to have automaton workers (v89)
#define MOD_GLOBAL_CITY_AUTOMATON_WORKERS           gCustomMods.isGLOBAL_CITY_AUTOMATON_WORKERS()
// Enables rebasing to and airlifting to/from improvements (v74)
#define MOD_GLOBAL_RELOCATION                       gCustomMods.isGLOBAL_RELOCATION()
// Mountain plots return their terrain as TERRAIN_MOUNTAIN and any land unit may enter a mountain that has a road/rail route
#define MOD_GLOBAL_ALPINE_PASSES                    gCustomMods.isGLOBAL_ALPINE_PASSES()
// Permits City States to gift ships
#define MOD_GLOBAL_CS_GIFT_SHIPS                    gCustomMods.isGLOBAL_CS_GIFT_SHIPS()
// Permits units to upgrade in allied militaristic City States
#define MOD_GLOBAL_CS_UPGRADES                      gCustomMods.isGLOBAL_CS_UPGRADES()
// City States will only raze captured cities if they are very unhappy
#define MOD_GLOBAL_CS_RAZE_RARELY                   gCustomMods.isGLOBAL_CS_RAZE_RARELY()
// City States can be liberated after they have been "bought" (Austria's or Venice's UA)
#define MOD_GLOBAL_CS_LIBERATE_AFTER_BUYOUT         gCustomMods.isGLOBAL_CS_LIBERATE_AFTER_BUYOUT()
// City States give different gifts depending on their type (cultural, religious, maritime, etc)
#define MOD_GLOBAL_CS_GIFTS                         gCustomMods.isGLOBAL_CS_GIFTS()
// Units gifted from City States receive XP from their spawning city, not the CS capital (v84)
#define MOD_GLOBAL_CS_GIFTS_LOCAL_XP                gCustomMods.isGLOBAL_CS_GIFTS_LOCAL_XP()
// City States allied to a major behave as an overseas territory of that major (v39)
#define MOD_GLOBAL_CS_OVERSEAS_TERRITORY            gCustomMods.isGLOBAL_CS_OVERSEAS_TERRITORY()
// City States at war with each other but allied to the same major will declare peace (v39)
#define MOD_GLOBAL_CS_NO_ALLIED_SKIRMISHES          gCustomMods.isGLOBAL_CS_NO_ALLIED_SKIRMISHES()
// Mercantile City States acquired via a Merchant of Venice do not lose their unique resources (v22)
#define MOD_GLOBAL_VENICE_KEEPS_RESOURCES           gCustomMods.isGLOBAL_VENICE_KEEPS_RESOURCES()
// Mercantile City States acquired via Diplomatic Marriage do not lose their unique resources (v81)
#define MOD_GLOBAL_CS_MARRIAGE_KEEPS_RESOURCES      gCustomMods.isGLOBAL_CS_MARRIAGE_KEEPS_RESOURCES()
// Units attacking from designated improvements (forts, citadels, etc) will not follow-up if they kill the defender (v87)
#define MOD_GLOBAL_NO_FOLLOWUP                      gCustomMods.isGLOBAL_NO_FOLLOWUP()
// Units attacking from cities will not follow-up if they kill the defender
#define MOD_GLOBAL_NO_FOLLOWUP_FROM_CITIES          gCustomMods.isGLOBAL_NO_FOLLOWUP_FROM_CITIES()
// Units that can move after attacking can also capture civilian units (eg workers in empty barbarian camps) (v32)
#define MOD_GLOBAL_CAPTURE_AFTER_ATTACKING          gCustomMods.isGLOBAL_CAPTURE_AFTER_ATTACKING()
// Trade routes can't be plundered on ocean tiles - too much sea to hide in, too many directions to escape in (v39)
#define MOD_GLOBAL_NO_OCEAN_PLUNDERING              gCustomMods.isGLOBAL_NO_OCEAN_PLUNDERING()
// Remove assembled spaceship parts from conquered capitals
#define MOD_GLOBAL_NO_CONQUERED_SPACESHIPS          gCustomMods.isGLOBAL_NO_CONQUERED_SPACESHIPS()
// Modified blockade logic (v52)
// The standard logic says "if there is an enemy ship within two hexes of a port, it is blockaded"
// HOWEVER - this includes the situations where
//   a) an enemy ship on the other side of a two-wide strip of land can blockade a port (ie enemy-land-port-water blockades the port)
//   b) a port with two non-adjacent exits (ie on a one-wide strip of land) can be blockaded by a non-adjacent enemy (ie enemy-water-port-water blockades the port)
// What is needed is a check for every adjacent water plot to the port being blockaded, not a simple check of the port itself
#define MOD_GLOBAL_ADJACENT_BLOCKADES               gCustomMods.isGLOBAL_ADJACENT_BLOCKADES()
// Adjacent allied ships block blockades by enemy ships 2 or more tiles away
#define MOD_GLOBAL_ALLIES_BLOCK_BLOCKADES           gCustomMods.isGLOBAL_ALLIES_BLOCK_BLOCKADES()
// Embarked combat units only blockade adjacent tiles
#define MOD_GLOBAL_SHORT_EMBARKED_BLOCKADES         gCustomMods.isGLOBAL_SHORT_EMBARKED_BLOCKADES()
// Other player's settlers captured from Barbarians will sometimes remain as settlers
#define MOD_GLOBAL_GRATEFUL_SETTLERS                gCustomMods.isGLOBAL_GRATEFUL_SETTLERS()
// Units that can found a city take their religion with them (v34)
#define MOD_GLOBAL_RELIGIOUS_SETTLERS               gCustomMods.isGLOBAL_RELIGIOUS_SETTLERS()
// Route To will only build roads, or upgrade road to rail, for human players (v44)
#define MOD_GLOBAL_QUICK_ROUTES                     gCustomMods.isGLOBAL_QUICK_ROUTES()
// Subs under ice are immune to all attacks except from other subs
#define MOD_GLOBAL_SUBS_UNDER_ICE_IMMUNITY          gCustomMods.isGLOBAL_SUBS_UNDER_ICE_IMMUNITY()
// Paratroops can move/attack after the drop, if the drop is not at max range
#define MOD_GLOBAL_PARATROOPS_MOVEMENT              gCustomMods.isGLOBAL_PARATROOPS_MOVEMENT()
// Paratroops take AA damage from hostile units
#define MOD_GLOBAL_PARATROOPS_AA_DAMAGE             gCustomMods.isGLOBAL_PARATROOPS_AA_DAMAGE()
// Nukes will melt ice
#define MOD_GLOBAL_NUKES_MELT_ICE                   gCustomMods.isGLOBAL_NUKES_MELT_ICE() 




// Great Works can generate different yields than just culture (v25)
#define MOD_GLOBAL_GREATWORK_YIELDTYPES             gCustomMods.isGLOBAL_GREATWORK_YIELDTYPES() 
// Great Artists, Writers and Musicians that do NOT create Great Works can be "reborn" (v84)
#define MOD_GLOBAL_NO_LOST_GREATWORKS               gCustomMods.isGLOBAL_NO_LOST_GREATWORKS() 
// Units of this type will not be gifted by City States (v46)
#define MOD_GLOBAL_EXCLUDE_FROM_GIFTS               gCustomMods.isGLOBAL_EXCLUDE_FROM_GIFTS()
// Units of this type may move after being upgraded (v46)
#define MOD_GLOBAL_MOVE_AFTER_UPGRADE               gCustomMods.isGLOBAL_MOVE_AFTER_UPGRADE()
// Units of this type may never embark (v46)
#define MOD_GLOBAL_CANNOT_EMBARK                    gCustomMods.isGLOBAL_CANNOT_EMBARK()
// Separates the Engineer, Scientist and Merchant GP counters (v52)
#define MOD_GLOBAL_SEPARATE_GP_COUNTERS             gCustomMods.isGLOBAL_SEPARATE_GP_COUNTERS()
// Removes free GP (from buildings, policies, traits, etc) from the GP counters (v61)
#define MOD_GLOBAL_TRULY_FREE_GP                    gCustomMods.isGLOBAL_TRULY_FREE_GP()

// Displays the opinion weight in the tooltip when meeting a leader (v80)
#define MOD_DIPLOMACY_BY_NUMBERS                    gCustomMods.isDIPLOMACY_BY_NUMBERS()
// Tech bonuses from other teams require an embassy or spy in their capital and not from just having met them (v30)
#define MOD_DIPLOMACY_TECH_BONUSES                  gCustomMods.isDIPLOMACY_TECH_BONUSES()
// Human players will auto-denounce AI players before going to war with them (v39)
#define MOD_DIPLOMACY_AUTO_DENOUNCE                 gCustomMods.isDIPLOMACY_AUTO_DENOUNCE()
// Gags the AI for annoying, inter-turn, so called, diplomacy messages "You're army is weak", "You're so powerful", etc. (v67)
//   GameEvents.DiplomacyStfu.Add(function(iAI, iResponseType, iDiploMessage, iDiploUIState, iAction, iExtraData) return GameInfoTypes.STFU_DEFAULT; end)
#define MOD_DIPLOMACY_STFU                          gCustomMods.isDIPLOMACY_STFU()
// Don't display leader heads (behaves more like multi-player diplomacy) (v67)
#define MOD_DIPLOMACY_NO_LEADERHEADS                gCustomMods.isDIPLOMACY_NO_LEADERHEADS()

// Permits units to earn GG/GA points from killing barbarians (v83)
#define MOD_TRAITS_GG_FROM_BARBARIANS               gCustomMods.isTRAITS_GG_FROM_BARBARIANS()
// Permits land units to cross ice - AFFECTS SAVE GAME DATA FORMAT
#define MOD_TRAITS_CROSSES_ICE                      gCustomMods.isTRAITS_CROSSES_ICE()
// Permits cities to work more rings - AFFECTS SAVE GAME DATA FORMAT
#define MOD_TRAITS_CITY_WORKING                     gCustomMods.isTRAITS_CITY_WORKING()
// Permit cities to have automaton workers - AFFECTS SAVE GAME DATA FORMAT (v90)
#define MOD_TRAITS_CITY_AUTOMATON_WORKERS           gCustomMods.isTRAITS_CITY_AUTOMATON_WORKERS()
// Enables traits to be enabled/obsoleted via beliefs and policies (v77)
#define MOD_TRAITS_OTHER_PREREQS                    gCustomMods.isTRAITS_OTHER_PREREQS()
// Enables any belief to be selected, even if already taken (v46)
#define MOD_TRAITS_ANY_BELIEF                       gCustomMods.isTRAITS_ANY_BELIEF()
// Enables additional trade route related traits (v52)
#define MOD_TRAITS_TRADE_ROUTE_BONUSES              gCustomMods.isTRAITS_TRADE_ROUTE_BONUSES()
// Enables additional unit supply from traits (v78)
#define MOD_TRAITS_EXTRA_SUPPLY                     gCustomMods.isTRAITS_EXTRA_SUPPLY()
// Enables found cities on mountains from traits (CIV5MPDLL)
#define MOD_TRAITS_CAN_FOUND_MOUNTAIN_CITY          gCustomMods.isTRAITS_CAN_FOUND_MOUNTAIN_CITY()
// Enables found cities on mountains from traits (CIV5MPDLL)
#define MOD_TRAITS_CAN_FOUND_COAST_CITY             gCustomMods.isTRAITS_CAN_FOUND_COAST_CITY()

// Permits cities to work more rings - AFFECTS SAVE GAME DATA FORMAT
#define MOD_POLICIES_CITY_WORKING                   gCustomMods.isPOLICIES_CITY_WORKING()
// Permit cities to have automaton workers - AFFECTS SAVE GAME DATA FORMAT (v90)
#define MOD_POLICIES_CITY_AUTOMATON_WORKERS         gCustomMods.isPOLICIES_CITY_AUTOMATON_WORKERS()

// Permits cities to work more rings - AFFECTS SAVE GAME DATA FORMAT
#define MOD_TECHS_CITY_WORKING                      gCustomMods.isTECHS_CITY_WORKING()
// Permit cities to have automaton workers - AFFECTS SAVE GAME DATA FORMAT (v89)
#define MOD_TECHS_CITY_AUTOMATON_WORKERS            gCustomMods.isTECHS_CITY_AUTOMATON_WORKERS()

// Permits variable great general and admiral aura ranges (v83)
#define MOD_PROMOTIONS_AURA_CHANGE                  gCustomMods.isPROMOTIONS_AURA_CHANGE()
// Permits units to earn GG/GA points from killing barbarians (v83)
#define MOD_PROMOTIONS_GG_FROM_BARBARIANS           gCustomMods.isPROMOTIONS_GG_FROM_BARBARIANS()
// Permits variable recon ranges by creating extra recon range promotions (like extra sight range)
#define MOD_PROMOTIONS_VARIABLE_RECON               gCustomMods.isPROMOTIONS_VARIABLE_RECON()
// Permits land units to cross mountains (like the Carthage trait)
#define MOD_PROMOTIONS_CROSS_MOUNTAINS              gCustomMods.isPROMOTIONS_CROSS_MOUNTAINS()
// Permits coastal units to cross oceans
#define MOD_PROMOTIONS_CROSS_OCEANS                 gCustomMods.isPROMOTIONS_CROSS_OCEANS()
// Permits land units to cross ice
#define MOD_PROMOTIONS_CROSS_ICE                    gCustomMods.isPROMOTIONS_CROSS_ICE()
// Adds a HalfMove feature to the UnitPromotions_Terrains and UnitPromotions_Features tables
#define MOD_PROMOTIONS_HALF_MOVE                    gCustomMods.isPROMOTIONS_HALF_MOVE()
// Permits Deep Water (Ocean) embarkation for hovering units - AFFECTS SAVE GAME DATA FORMAT
#define MOD_PROMOTIONS_DEEP_WATER_EMBARKATION       gCustomMods.isPROMOTIONS_DEEP_WATER_EMBARKATION()
// Permits naval units to transfer their moves to Great Admirals (like land units can to Great Generals) (v39)
#define MOD_PROMOTIONS_FLAGSHIP                     gCustomMods.isPROMOTIONS_FLAGSHIP()
// Permits units to be named based on a promotion they have (v46)
#define MOD_PROMOTIONS_UNIT_NAMING                  gCustomMods.isPROMOTIONS_UNIT_NAMING()
// Permits units to receive a combat bonus from being near an improvement (v46)
#define MOD_PROMOTIONS_IMPROVEMENT_BONUS            gCustomMods.isPROMOTIONS_IMPROVEMENT_BONUS()
// Permits units to receive a combat bonus from Ally City States
#define MOD_PROMOTIONS_ALLYCITYSTATE_BONUS			gCustomMods.isPROMOTIONS_ALLYCITYSTATE_BONUS()
// Permits units to receive defense bonus from Left/Used Moves
#define MOD_DEFENSE_MOVES_BONUS						gCustomMods.isDEFENSE_MOVES_BONUS()
// Permits units to receive a combat bonus from Extra Resourses/Hapiness
#define MOD_PROMOTIONS_EXTRARES_BONUS				gCustomMods.isPROMOTIONS_EXTRARES_BONUS()

// Permit the focus (gold/production/culture) of puppet cities to be set (but not what is being built or how specialists are allocated)
#define MOD_UI_CITY_PRODUCTION                      gCustomMods.isUI_CITY_PRODUCTION()
// Permit human players to choose they own city tiles due to cultural expansion
#define MOD_UI_CITY_EXPANSION                       gCustomMods.isUI_CITY_EXPANSION()

// National Wonders (NW) requiring a building in every city exclude those being razed (in addition to excluding puppets) (v63)
#define MOD_BUILDINGS_NW_EXCLUDE_RAZING             gCustomMods.isBUILDINGS_NW_EXCLUDE_RAZING()
// Purchase of buildings in cities allows for any current production
#define MOD_BUILDINGS_PRO_RATA_PURCHASE             gCustomMods.isBUILDINGS_PRO_RATA_PURCHASE()
// Permits cities to work more rings - AFFECTS SAVE GAME DATA FORMAT
#define MOD_BUILDINGS_CITY_WORKING                  gCustomMods.isBUILDINGS_CITY_WORKING()
// Permit cities to have automaton workers - AFFECTS SAVE GAME DATA FORMAT (v90)
#define MOD_BUILDINGS_CITY_AUTOMATON_WORKERS        gCustomMods.isBUILDINGS_CITY_AUTOMATON_WORKERS()

#define MOD_BUILDINGS_YIELD_FROM_OTHER_YIELD        gCustomMods.isBUILDINGS_YIELD_FROM_OTHER_YIELD()

#define MOD_BUILDINGS_GOLDEN_AGE_EXTEND             gCustomMods.isBUILDINGS_GOLDEN_AGE_EXTEND()

// Scales trade routes based on map size and game speed (v52)
#define MOD_TRADE_ROUTE_SCALING                     gCustomMods.isTRADE_ROUTE_SCALING()

// Permits wonder resource (ie Marble) trade routes to be established (v43)
#define MOD_TRADE_WONDER_RESOURCE_ROUTES            gCustomMods.isTRADE_WONDER_RESOURCE_ROUTES()

// Permits units to have no supply cost (v77)
#define MOD_UNITS_NO_SUPPLY                         gCustomMods.isUNITS_NO_SUPPLY()
// Permits units to have other than GameDefines.MAX_HIT_POINTS maximum hit points (v77)
#define MOD_UNITS_MAX_HP                            gCustomMods.isUNITS_MAX_HP()
// Enables the XP times 100 API (v77)
#define MOD_UNITS_XP_TIMES_100                      gCustomMods.isUNITS_XP_TIMES_100()
// Restricts worker suggestions to local tiles
#define MOD_UNITS_LOCAL_WORKERS                     gCustomMods.isUNITS_LOCAL_WORKERS()
// Hovering unit can only heal over land
#define MOD_UNITS_HOVERING_LAND_ONLY_HEAL           gCustomMods.isUNITS_HOVERING_LAND_ONLY_HEAL()
// Permits hovering units to attack coastal shipping
#define MOD_UNITS_HOVERING_COASTAL_ATTACKS          gCustomMods.isUNITS_HOVERING_COASTAL_ATTACKS()

// Removes religion preference
#define MOD_RELIGION_NO_PREFERRENCES                gCustomMods.isRELIGION_NO_PREFERRENCES()
// Randomises religion choice (if preferred religion unavailable)
#define MOD_RELIGION_RANDOMISE                      gCustomMods.isRELIGION_RANDOMISE()
// Adds ConversionModifier and GlobalConversionModifier (in the same vein as espionage modifiers) to buildings - AFFECTS SAVE GAME DATA FORMAT
#define MOD_RELIGION_CONVERSION_MODIFIERS           gCustomMods.isRELIGION_CONVERSION_MODIFIERS()
// Keeps overflow faith from spawning a Great Prophet if the base spawn chance is 100% (v21)
#define MOD_RELIGION_KEEP_PROPHET_OVERFLOW          gCustomMods.isRELIGION_KEEP_PROPHET_OVERFLOW()
// Inquisitors will keep religion out of allied City State cities if positioned adjacent (v60)
#define MOD_RELIGION_ALLIED_INQUISITORS             gCustomMods.isRELIGION_ALLIED_INQUISITORS()
// Send purchase notifications at every boundary and not just the first (v42)
#define MOD_RELIGION_RECURRING_PURCHASE_NOTIFIY     gCustomMods.isRELIGION_RECURRING_PURCHASE_NOTIFIY()
// Adds support for the Belief_PlotYieldChanges table (v35)
#if defined(MOD_API_PLOT_YIELDS)
#define MOD_RELIGION_PLOT_YIELDS                    (gCustomMods.isRELIGION_PLOT_YIELDS() && MOD_API_PLOT_YIELDS)
#endif
// Adds support for Great People being purchased by faith to be specified on a policy (usually a finisher) and not hard-coded (v53)
#define MOD_RELIGION_POLICY_BRANCH_FAITH_GP         gCustomMods.isRELIGION_POLICY_BRANCH_FAITH_GP()
// Adds support for "local" religions (ie ones that only have influence within the civ's own territory) (v48)
#define MOD_RELIGION_LOCAL_RELIGIONS                gCustomMods.isRELIGION_LOCAL_RELIGIONS()

// Enables production to be stockpiled (v28)
#define MOD_PROCESS_STOCKPILE                       gCustomMods.isPROCESS_STOCKPILE()

// Stops the AI from adding zero-value items (eg late game horses) into trade offers (v85)
#define MOD_AI_NO_ZERO_VALUE_TRADE_ITEMS            gCustomMods.isAI_NO_ZERO_VALUE_TRADE_ITEMS()

// Fixes the AI's inability to use combat units as secondary workers (v26)
#define MOD_AI_SECONDARY_WORKERS                    gCustomMods.isAI_SECONDARY_WORKERS()
// Fixes the AI's inability to use combat units for founding cities (v26)
#define MOD_AI_SECONDARY_SETTLERS                   gCustomMods.isAI_SECONDARY_SETTLERS()

// Fixes the AI's inability to pick free Great Prophets, Merchants of Venice, Great Musicians and Great Writers (v82)
#define MOD_AI_GREAT_PEOPLE_CHOICES                 gCustomMods.isAI_GREAT_PEOPLE_CHOICES()

// Enables JdH's MP Diplomacy code (v84)
#define MOD_AI_MP_DIPLOMACY                         gCustomMods.isAI_MP_DIPLOMACY()

// Features from the "Smart AI V3 mod" by Ninakoru - see http://forums.civfanatics.com/showthread.php?t=562319 (v85)
#define MOD_AI_SMART_V3                             gCustomMods.isAI_SMART_V3()

// Events sent when terraforming occurs (v33)
//   GameEvents.TerraformingMap.Add(function(iEvent, iLoad) end)
//   GameEvents.TerraformingPlot.Add(function(iEvent, iPlotX, iPlotY, iInfo, iNewValue, iOldValue, iNewExtra, iOldExtra) end)
#define MOD_EVENTS_TERRAFORMING                     gCustomMods.isEVENTS_TERRAFORMING()

// Events sent when plots change from worker actions (v44)
//   GameEvents.TileFeatureChanged.Add(function(iPlotX, iPlotY, iOwner, iOldFeature, iNewFeature) end)
//   GameEvents.TileImprovementChanged.Add(function(iPlotX, iPlotY, iOwner, iOldImprovement, iNewImprovement, bPillaged) end)
//   GameEvents.TileOwnershipChanged.Add(function(iPlotX, iPlotY, iOwner, iOldOwner) end) (v46)
//   GameEvents.TileRouteChanged.Add(function(iPlotX, iPlotY, iOwner, iOldRoute, iNewRoute, bPillaged) end)
#define MOD_EVENTS_TILE_IMPROVEMENTS                gCustomMods.isEVENTS_TILE_IMPROVEMENTS()

// Event sent when a plot is revealed (v58)
//   GameEvents.TileRevealed.Add(function(iPlotX, iPlotY, iteam, iFromTeam, bFirst) end)
#define MOD_EVENTS_TILE_REVEALED                    gCustomMods.isEVENTS_TILE_REVEALED()

// Event sent when a team circumnavigates the globe
//   GameEvents.CircumnavigatedGlobe.Add(function(iTeam) end)
#define MOD_EVENTS_CIRCUMNAVIGATION                 gCustomMods.isEVENTS_CIRCUMNAVIGATION()

// Event sent when the player enters a new era, see also NewEraPopup.lua and BUTTONPOPUP_NEW_ERA
//   GameEvents.TeamSetEra.Add(function(eTeam, eEra, bFirst) end)
//   GameEvents.PlayerSetEra.Add(function(ePlayer, eEra, bFirst) end)
#define MOD_EVENTS_NEW_ERA                          gCustomMods.isEVENTS_NEW_ERA()

#define MOD_EVENTS_PLAYER_SET_HAS_TECH              gCustomMods.isEVENTS_PLAYER_SET_HAS_TECH()

// Event sent when the team discovers a new Natural Wonder
//   GameEvents.NaturalWonderDiscovered.Add(function(iTeam, iFeature, iX, iY, bFirst) end)
#define MOD_EVENTS_NW_DISCOVERY                     gCustomMods.isEVENTS_NW_DISCOVERY()

// Event sent during Game.DoFromUIDiploEvent, see also DiscussionDialog.lua
//   GameEvents.UiDiploEvent.Add(function(iEvent, iAIPlayer, iArg1, iArg2) end)
#define MOD_EVENTS_DIPLO_EVENTS                     gCustomMods.isEVENTS_DIPLO_EVENTS()

// Enhanced Diplomacy Modifiers events (v53)
//   GameEvents.GetDiploModifier.Add(function(iEvent, iFromPlayer, iToPlayer) return 0 end)
#define MOD_EVENTS_DIPLO_MODIFIERS                  gCustomMods.isEVENTS_DIPLO_MODIFIERS()

// Events sent on status change with City States
//   GameEvents.MinorFriendsChanged.Add(function(iMinor, iMajor, bIsFriend, iOldFriendship, iNewFriendship) end)
//   GameEvents.MinorAlliesChanged.Add(function(iMinor, iMajor, bIsAlly, iOldFriendship, iNewFriendship) end)
#define MOD_EVENTS_MINORS                           gCustomMods.isEVENTS_MINORS()

// Event sent upon a City State giving a gift (v73)
//   GameEvents.MinorGift.Add(function(iMinor, iMajor, iGoldGift, iGift, 0, bFirstMajorCiv, false, szTxtKeySuffix) end)
#define MOD_EVENTS_MINORS_GIFTS                     gCustomMods.isEVENTS_MINORS_GIFTS()

// Events sent on interaction with City States (v68)
//   GameEvents.PlayerCanProtect.Add(function(iPlayer, iCS) return true end)
//   GameEvents.PlayerProtected.Add(function(iPlayer, iCS) end)
//   GameEvents.PlayerCanRevoke.Add(function(iPlayer, iCS) return true end)
//   GameEvents.PlayerRevoked.Add(function(iPlayer, iCS, bPledgeNowBroken) end)
//   GameEvents.PlayerCanBuyOut.Add(function(iPlayer, iCS) return true end)
//   GameEvents.PlayerBoughtOut.Add(function(iPlayer, iCS) end)
//   GameEvents.PlayerCanBullyGold.Add(function(iPlayer, iCS) return true end)
//   GameEvents.PlayerCanBullyUnit.Add(function(iPlayer, iCS) return true end)
//   GameEvents.PlayerBullied.Add(function(iPlayer, iCS, iGold, iUnitType, iPlotX, iPlotY) end)
//   GameEvents.PlayerCanGiftGold.Add(function(iPlayer, iCS) return true end)
//   GameEvents.PlayerCanGiftUnit.Add(function(iPlayer, iCS, iUnit) return true end)
//   GameEvents.PlayerCanGiftImprovement.Add(function(iPlayer, iCS) return true end)
//   GameEvents.PlayerGifted.Add(function(iPlayer, iCS, iGold, iUnitType, iPlotX, iPlotY) end)
//   GameEvents.PlayerCanTransitMinorCity.Add(function(iPlayer, iCS, iCity, iPlotX, iPlotY) return true end) (v74)
//   GameEvents.UnitCanTransitMinorCity.Add(function(iPlayer, iUnit, iCS, iCity, iPlotX, iPlotY) return true end) (v74)
#define MOD_EVENTS_MINORS_INTERACTION               gCustomMods.isEVENTS_MINORS_INTERACTION()

// Events sent by City State quests (v81)
//   GameEvents.QuestIsAvailable(iPlayer, iCS, iQuest, iData1, iData2) return false end)
//   GameEvents.QuestIsCompleted.Add(function(iPlayer, iCS, iQuest, bLastTurn) return false end)
//   GameEvents.QuestIsRevoked.Add(function(iPlayer, iCS, iQuest) return false end)
//   GameEvents.QuestIsExpired.Add(function(iPlayer, iCS, iQuest) return false end)
//   GameEvents.QuestStart.Add(function(iPlayer, iCS, iQuest, iStartTurn, iData1, iData2) end)
//   GameEvents.QuestGetData.Add(function(iPlayer, iCS, iQuest, bData1) return 0 end)
//   GameEvents.QuestSendNotification.Add(function(iPlayer, iCS, iQuest, iStartTurn, iEndTurn, iData1, iData2, bStarted, bFinished, sNames) end)
//   GameEvents.QuestContestValue.Add(function(iPlayer, iCS, iQuest) return 0 end)
#define MOD_EVENTS_QUESTS                           gCustomMods.isEVENTS_QUESTS()

// Events sent by Barbarians (v68)
//   GameEvents.BarbariansCanFoundCamp.Add(function(iPlotX, iPlotY) return true end)
//   GameEvents.BarbariansCampFounded.Add(function(iPlotX, iPlotY) end)
//   GameEvents.BarbariansCampCleared.Add(function(iPlotX, iPlotY, iPlayer) end)
//   GameEvents.BarbariansCampCanSpawnUnit.Add(function(iPlotX, iPlotY) return true end)
//   GameEvents.BarbariansCampGetSpawnUnit.Add(function(iPlotX, iPlotY, iPrefUnitType) return iPrefUnitType end)
//   GameEvents.BarbariansSpawnedUnit.Add(function(iPlotX, iPlotY, iUnitType) end)
#define MOD_EVENTS_BARBARIANS                       gCustomMods.isEVENTS_BARBARIANS()

// Event sent when a Goody Hut is entered (v33)
//   GameEvents.GoodyHutCanNotReceive.Add(function(iPlayer, iUnit, eGoody, bPick) return false end)
#define MOD_EVENTS_GOODY_CHOICE                     gCustomMods.isEVENTS_GOODY_CHOICE()

// Events sent if a Goody Hut is giving a tech
//   GameEvents.GoodyHutCanResearch.Add(function(iPlayer, eTech) return true end)
//   GameEvents.GoodyHutTechResearched.Add(function(iPlayer, eTech) end)
#define MOD_EVENTS_GOODY_TECH                       gCustomMods.isEVENTS_GOODY_TECH()

// Event sent to allow Lua to override the AI's choice of tech (v30)
//   GameEvents.AiOverrideChooseNextTech.Add(function(iPlayer, bFreeTech) return iChoosenTech end)
#define MOD_EVENTS_AI_OVERRIDE_TECH                 gCustomMods.isEVENTS_AI_OVERRIDE_TECH()

// Events sent by Great People actions
//   GameEvents.GreatPersonExpended.Add(function(iPlayer, iUnit, iUnitType, iX, iY) end)
#define MOD_EVENTS_GREAT_PEOPLE                     gCustomMods.isEVENTS_GREAT_PEOPLE()

// Events sent when a player is about to found a religion
//   GameEvents.PlayerCanFoundPantheon.Add(function(iPlayer) return true end)
//   GameEvents.PlayerCanFoundReligion.Add(function(iPlayer, iCity) return true end)
//   GameEvents.GetReligionToFound.Add(function(iPlayer, iPreferredReligion, bIsAlreadyFounded) return iPreferredReligion end)
//   GameEvents.PantheonFounded.Add(function(iPlayer, iCapitalCity, iReligion, iBelief1) end)
//   GameEvents.ReligionFounded.Add(function(iPlayer, iHolyCity, iReligion, iBelief1, iBelief2, iBelief3, iBelief4, iBelief5) end)
//   GameEvents.ReligionEnhanced.Add(function(iPlayer, iReligion, iBelief1, iBelief2) end)
//   GameEvents.ReligionReformed.Add(function(iPlayer, iReligion, iBelief1) end) (v65)
#define MOD_EVENTS_FOUND_RELIGION                   gCustomMods.isEVENTS_FOUND_RELIGION()

// Events sent when choosing beliefs
//   GameEvents.PlayerCanHaveBelief.Add(function(iPlayer, iBelief) return true end)
//   GameEvents.ReligionCanHaveBelief.Add(function(iPlayer, iReligion, iBelief) return true end)
#define MOD_EVENTS_ACQUIRE_BELIEFS                  gCustomMods.isEVENTS_ACQUIRE_BELIEFS()

// Events sent to see if religion missions are valid (v46)
//   GameEvents.PlayerCanSpreadReligion.Add(function(iPlayer, iUnit, iPlotX, iPlotY) return true end)
//   GameEvents.PlayerCanRemoveHeresy.Add(function(iPlayer, iUnit, iPlotX, iPlotY) return true end)
#define MOD_EVENTS_RELIGION                         gCustomMods.isEVENTS_RELIGION()

// Events sents on espionage outcomes (v63)
//   GameEvents.EspionageResult.Add(function(iPlayer, iSpy, iResult, iCityX, iCityY) end)
//   GameEvents.EspionageState.Add(function(iPlayer, iSpy, iState, iCityX, iCityY) end)
//   GameEvents.EspionageCanMoveSpyTo.Add(function(iPlayer, iCityOwner, iCity) return true)
//   GameEvents.EspionageCanStageCoup.Add(function(iPlayer, iCityOwner, iCity) return true)
#define MOD_EVENTS_ESPIONAGE                         gCustomMods.isEVENTS_ESPIONAGE()

// Event sent to ascertain if a unit can start a paradrop from this tile
//   GameEvents.CanParadropFrom.Add(function(iPlayer, iUnit, iPlotX, iPlotY) return false end)
//   GameEvents.CannotParadropFrom.Add(function(iPlayer, iUnit, iPlotX, iPlotY) return false end)
//   GameEvents.ParadropAt.Add(function(iPlayer, iUnit, iFromX, iFromY, iToX, iToY) end)
#define MOD_EVENTS_PARADROPS                        gCustomMods.isEVENTS_PARADROPS()

// Event sent to ascertain if a unit can perform a ranged attack on a tile (v90)
//   GameEvents.UnitCanRangeAttackAt.Add(function(iPlayer, iUnit, iPlotX, iPlotY, bNeedWar) return false end)
//   GameEvents.UnitRangeAttackAt.Add(function(iPlayer, iUnit, iPlotX, iPlotY) return 0; end)
#define MOD_EVENTS_UNIT_RANGEATTACK                 gCustomMods.isEVENTS_UNIT_RANGEATTACK()

// Event sent when a unit is created (v46)
//   GameEvents.UnitCreated.Add(function(iPlayer, iUnit, iUnitType, iPlotX, iPlotY) end)
#define MOD_EVENTS_UNIT_CREATED                     gCustomMods.isEVENTS_UNIT_CREATED()

// Event sent when a unit founds a city (v58)
//   GameEvents.UnitCityFounded.Add(function(iPlayer, iUnit, iUnitType, iPlotX, iPlotY) end)
#define MOD_EVENTS_UNIT_FOUNDED                     gCustomMods.isEVENTS_UNIT_FOUNDED()

// Event sent just before a unit is killed (via CvUnit::kill()) (v22)
//   GameEvents.UnitPrekill.Add(function(iPlayer, iUnit, iUnitType, iX, iY, bDelay, iByPlayer) end)
#define MOD_EVENTS_UNIT_PREKILL                     gCustomMods.isEVENTS_UNIT_PREKILL()

// Event sent as a unit is captured (v46)
//   GameEvents.UnitCaptured.Add(function(iByPlayer, iByUnit, iCapturedPlayer, iCapturedUnit, bWillBeKilled, iReason) end) (v69)
//   iReason - 0=Move, 1=Combat, 2=Trait (barb land), 3=Trait (barb naval), 4=Belief (barb)
//   GameEvents.UnitCaptureType.Add(function(iPlayer, iUnit, iUnitType, iByCiv) return iCaptureUnitType; end)
#define MOD_EVENTS_UNIT_CAPTURE                     gCustomMods.isEVENTS_UNIT_CAPTURE()

// Events sent as units perform actions (v86)
//   GameEvents.UnitCanPillage.Add(function(iPlayer, iUnit, iImprovement, iRoute) return true end)
//   GameEvents.UnitPillageGold.Add(function(iPlayer, iUnit, iImprovement, iGold) return iGold end)
//   GameEvents.UnitCanFollowupFrom.Add(function(iPlayer, iUnit, iImprovement, iFromX, iFromY, iToX, iToY) return true end) (v87)
#define MOD_EVENTS_UNIT_ACTIONS                     gCustomMods.isEVENTS_UNIT_ACTIONS()

// Events sent as units are promoted/upgraded
//   GameEvents.CanHavePromotion.Add(function(iPlayer, iUnit, iPromotionType) return true end)
//   GameEvents.UnitCanHavePromotion.Add(function(iPlayer, iUnit, iPromotionType) return true end)
//   GameEvents.UnitPromoted.Add(function(iPlayer, iUnit, iPromotionType) end)
//   GameEvents.CanHaveAnyUpgrade.Add(function(iPlayer, iUnit) return true end)
//   GameEvents.UnitCanHaveAnyUpgrade.Add(function(iPlayer, iUnit) return true end)
//   GameEvents.CanHaveUpgrade.Add(function(iPlayer, iUnit, iUnitClassType, iUnitType) return true end)
//   GameEvents.UnitCanHaveUpgrade.Add(function(iPlayer, iUnit, iUnitClassType, iUnitType) return true end)
//   GameEvents.UnitUpgraded.Add(function(iPlayer, iOldUnit, iNewUnit, bGoodyHut) end)
#define MOD_EVENTS_UNIT_UPGRADES                    gCustomMods.isEVENTS_UNIT_UPGRADES()

// Events sent as units are created (v51)
//   GameEvents.UnitCanHaveName.Add(function(iPlayer, iUnit, iName) return true end)
//   GameEvents.UnitCanHaveGreatWork.Add(function(iPlayer, iUnit, iGreatWork) return true end)
#define MOD_EVENTS_UNIT_DATA                        gCustomMods.isEVENTS_UNIT_DATA()

// Event sent to ascertain if a unit can move into a given plot - VERY, VERY CPU INTENSIVE!!!
//   GameEvents.CanMoveInto.Add(function(iPlayer, iUnit, iPlotX, iPlotY, bAttack, bDeclareWar) return true end)
#define MOD_EVENTS_CAN_MOVE_INTO                    gCustomMods.isEVENTS_CAN_MOVE_INTO()

// Event sent as ascertain if a trade route can be created (v68)
//   GameEvents.PlayerCanCreateTradeRoute.Add(function(iFromPlayer, iFromCity, iToPlayer, iToCity, iDomain, iConnectionType) return true end)
#define MOD_EVENTS_TRADE_ROUTES                     gCustomMods.isEVENTS_TRADE_ROUTES()

// Event sent as a trade route is plundered (v52)
//   GameEvents.PlayerPlunderedTradeRoute.Add(function(iPlayer, iUnit, iPlunderedGold, iFromPlayer, iFromCity, iToPlayer, iToCity, iRouteType, iRouteDomain) end)
#define MOD_EVENTS_TRADE_ROUTE_PLUNDERED            gCustomMods.isEVENTS_TRADE_ROUTE_PLUNDERED()

// Event sent when a nuke is fired
//   GameEvents.NuclearDetonation.Add(function(iPlayer, iX, iY, bWar, bBystanders) end)
#define MOD_EVENTS_NUCLEAR_DETONATION               gCustomMods.isEVENTS_NUCLEAR_DETONATION()

// Events sent about war and peace
//   GameEvents.PlayerCanDeclareWar.Add(function(iPlayer, iAgainstTeam) return true end)
//   GameEvents.IsAbleToDeclareWar.Add(function(iPlayer, iAgainstTeam) return true end) - deprecated, use PlayerCanDeclareWar
//   GameEvents.DeclareWar.Add(function(iPlayer, iAgainstTeam, bAggressor) end)
//   GameEvents.PlayerCanMakePeace.Add(function(iPlayer, iAgainstTeam) return true end)
//   GameEvents.IsAbleToMakePeace.Add(function(iPlayer, iAgainstTeam) return true end) - deprecated, use PlayerCanMakePeace
//   GameEvents.MakePeace.Add(function(iPlayer, iAgainstTeam, bPacifier) end)
#define MOD_EVENTS_WAR_AND_PEACE                    gCustomMods.isEVENTS_WAR_AND_PEACE()

// Events sent about resolutions (v51)
//   GameEvents.PlayerCanPropose.Add(function(iPlayer, iResolution, iChoice, bEnact) return true end)
//   GameEvents.ResolutionProposing.Add(function(iPlayer, iLeague) return false; end) (v88)
//   GameEvents.ResolutionVoting.Add(function(iPlayer, iLeague) return false; end) (v88)
//   GameEvents.ResolutionResult.Add(function(iResolution, iChoice, bEnact, bPassed) end)
#define MOD_EVENTS_RESOLUTIONS                      gCustomMods.isEVENTS_RESOLUTIONS()

// Events sent about ideologies and tenets (v51)
//   GameEvents.PlayerCanAdoptIdeology.Add(function(iPlayer, iIdeology) return true end)
//   GameEvents.PlayerCanAdoptTenet.Add(function(iPlayer, iTenet) return true end)
#define MOD_EVENTS_IDEOLOGIES                       gCustomMods.isEVENTS_IDEOLOGIES()

// Events sent by plots (v30)
//   GameEvents.PlayerCanBuild.Add(function(iPlayer, iUnit, iX, iY, iBuild) return true end)
//   GameEvents.PlotCanImprove.Add(function(iX, iY, iImprovement) return true end)
//   GameEvents.PlayerBuilding.Add(function(iPlayer, iUnit, iX, iY, iBuild, bStarting) end) (v46)
//   GameEvents.PlayerBuilt.Add(function(iPlayer, iUnit, iX, iY, iBuild) end) (v46)
#define MOD_EVENTS_PLOT                             gCustomMods.isEVENTS_PLOT()

// Event sent by ending turn (v94)
//   GameEvents.PlayerDoneTurn.Add(function(iPlayer) end)
//   GameEvents.PlayerTurnStart.Add(function(iPlayer) end)
#define MOD_EVENTS_PLAYER_TURN                      gCustomMods.isEVENTS_PLAYER_TURN()

// Event sent by golden ages (v52)
//   GameEvents.PlayerGoldenAge.Add(function(iPlayer, bStart, iTurns) end)
#define MOD_EVENTS_GOLDEN_AGE                       gCustomMods.isEVENTS_GOLDEN_AGE()

// Events sent after a city produces/buys something
//   GameEvents.CityTrained.Add(function(iPlayer, iCity, iUnit, bGold, bFaith) end)
//   GameEvents.CityConstructed.Add(function(iPlayer, iCity, iBuilding, bGold, bFaith) end)
//   GameEvents.CityCreated.Add(function(iPlayer, iCity, iProject, bGold, bFaith) end)
//   GameEvents.CityPrepared.Add(function(iPlayer, iCity, iSpecialist, bGold, bFaith) end) (v33)
//   GameEvents.CityBoughtPlot.Add(function(iPlayer, iCity, iPlotX, iPlotY, bGold, bCulture) end)
//   GameEvents.CitySoldBuilding.Add(function(iPlayer, iCity, iBuilding) end)
#define MOD_EVENTS_CITY                             gCustomMods.isEVENTS_CITY()

// Event sent after a civilization moves their capital (v73)
//   GameEvents.CapitalChanged.Add(function(iPlayer, iNewCapital, iOldCapital) end)
#define MOD_EVENTS_CITY_CAPITAL                     gCustomMods.isEVENTS_CITY_CAPITAL()

// Event sent to ascertain if a city can acquire a plot (v20)
//   GameEvents.CityCanAcquirePlot.Add(function(iPlayer, iCity, iPlotX, iPlotY) return true end)
#define MOD_EVENTS_CITY_BORDERS                     gCustomMods.isEVENTS_CITY_BORDERS()
	
// Event sent about city founding (v68)
//   GameEvents.PlayerCanFoundCity.Add(function(iPlayer, iPlotX, iPlotY) return true end)
//   GameEvents.PlayerCanFoundCityRegardless.Add(function(iPlayer, iPlotX, iPlotY) return false end)
#define MOD_EVENTS_CITY_FOUNDING                    gCustomMods.isEVENTS_CITY_FOUNDING()
	
// Event sent to ascertain if a player can liberate another player (v68)
//   GameEvents.PlayerCanLiberate.Add(function(iPlayer, iOtherPlayer) return true end)
//   GameEvents.PlayerLiberated.Add(function(iPlayer, iOtherPlayer, iCity) end)
#define MOD_EVENTS_LIBERATION                       gCustomMods.isEVENTS_LIBERATION()
	
// Event sent to ascertain if a player can over-ride the standard razing rules for the specified city and raze it anyway (v20)
//   GameEvents.PlayerCanRaze.Add(function(iPlayer, iCity) return false end)
#define MOD_EVENTS_CITY_RAZING                      gCustomMods.isEVENTS_CITY_RAZING()
	
// Event sent to ascertain if a city can perform airlifts (v68)
//   GameEvents.CityCanAirlift.Add(function(iPlayer, iCity) return false end)
#define MOD_EVENTS_CITY_AIRLIFT                     gCustomMods.isEVENTS_CITY_AIRLIFT()

// Events sent to ascertain the bombard range for a city, and if indirect fire is allowed (v32)
//   updated to permit a range of 0 for no bombardment possible (v95)
// Return a negative range if indirect fire is permitted
//   GameEvents.GetBombardRange.Add(function(iPlayer, iCity) return (-1 * GameDefines.CITY_ATTACK_RANGE) end)
#define MOD_EVENTS_CITY_BOMBARD                     gCustomMods.isEVENTS_CITY_BOMBARD()

#define MOD_ROG_CORE_BOMBARD_RANGE_BUILDINGS      gCustomMods.isROG_CORE_BOMBARD_RANGE_BUILDINGS()

// Events sent to ascertain if one city is connected to another (v33)
//   GameEvents.CityConnections.Add(function(iPlayer, bDomestic) return false end)
//   GameEvents.CityConnected.Add(function(iPlayer, iCityX, iCityY, iToCityX, iToCityY, bDomestic) return false end)
#define MOD_EVENTS_CITY_CONNECTIONS                 gCustomMods.isEVENTS_CITY_CONNECTIONS()

// Events sent to ascertain if an area can have civ specific resources and to place those resources (v20)
//   GameEvents.AreaCanHaveAnyResource.Add(function(iPlayer, iArea) return true end)
//   GameEvents.PlaceResource.Add(function(iPlayer, iResource, iCount, iPlotX, iPlotY) end)
#define MOD_EVENTS_AREA_RESOURCES                   gCustomMods.isEVENTS_AREA_RESOURCES()

// Events sent to ascertain if a unit can airlift from/to a specific plot (v74)
//   GameEvents.CanAirliftFrom.Add(function(iPlayer, iUnit, iPlotX, iPlotY) return false end)
//   GameEvents.CanAirliftTo.Add(function(iPlayer, iUnit, iPlotX, iPlotY) return false end)
#define MOD_EVENTS_AIRLIFT                           gCustomMods.isEVENTS_AIRLIFT()

// Events sent to ascertain if a unit can rebase to a specific plot (either a city or a carrier)
//   GameEvents.CanLoadAt.Add(function(iPlayer, iUnit, iPlotX, iPlotY) return false end)
//   GameEvents.CanRebaseInCity.Add(function(iPlayer, iUnit, iPlotX, iPlotY) return false end)
//   GameEvents.CanRebaseTo.Add(function(iPlayer, iUnit, iPlotX, iPlotY, bIsCity) return false end)
//   GameEvents.RebaseTo.Add(function(iPlayer, iUnit, iPlotX, iPlotY) end)
#define MOD_EVENTS_REBASE                           gCustomMods.isEVENTS_REBASE()

// Event sent to see if a command is valid (v46)
//   GameEvents.CanDoCommand.Add(function(iPlayer, iUnit, iCommand, iData1, iData2, iPlotX, iPlotY, bTestVisible) return true end)
#define MOD_EVENTS_COMMAND                          gCustomMods.isEVENTS_COMMAND()

// Events sent for custom missions (v46)
//   CUSTOM_MISSION_NO_ACTION       = 0
//   CUSTOM_MISSION_ACTION          = 1
//   CUSTOM_MISSION_DONE            = 2
//   CUSTOM_MISSION_ACTION_AND_DONE = 3
//   GameEvents.CustomMissionPossible.Add(function(iPlayer, iUnit, iMission, iData1, iData2, iFlags=0, iTurn=-1, iPlotX, iPlotY, bTestVisible) return false end)
//   GameEvents.CustomMissionStart.Add(function(iPlayer, iUnit, iMission, iData1, iData2, iFlags, iTurn) return CUSTOM_MISSION_ACTION end)
//   GameEvents.CustomMissionSetActivity.Add(function(iPlayer, iUnit, iMission, iData1, iData2, iFlags, iTurn) return CUSTOM_MISSION_ACTION_AND_DONE end)
//   GameEvents.CustomMissionDoStep.Add(function(iPlayer, iUnit, iMission, iData1, iData2, iFlags, iTurn) return CUSTOM_MISSION_ACTION_AND_DONE end)
//   GameEvents.CustomMissionCompleted.Add(function(iPlayer, iUnit, iMission, iData1, iData2, iFlags, iTurn) return false end)
//   GameEvents.CustomMissionTargetPlot.Add(function(iPlayer, iUnit, iMission, iData1, iData2, iFlags, iTurn) return iPlotIndex end)
//   GameEvents.CustomMissionCameraTime.Add(function(iPlayer, iUnit, iMission, iData1, iData2, iFlags, iTurn) return iCameraTime end) -- iCameraTime is 0, 1, 5 or 10
//   GameEvents.CustomMissionTimerInc.Add(function(iPlayer, iUnit, iMission, iData1, iData2, iFlags, iTurn) return iTimerInc end)
#define MOD_EVENTS_CUSTOM_MISSIONS                  gCustomMods.isEVENTS_CUSTOM_MISSIONS()

// Events sent during combat (v68)
//   GameEvents.BattleStarted.Add(function(iType, iPlotX, iPlotY) end)
//   GameEvents.BattleJoined.Add(function(iPlayer, iUnitOrCity, iRole, bIsCity) end)
//   GameEvents.BattleFinished.Add(function() end)
#define MOD_EVENTS_BATTLES                          gCustomMods.isEVENTS_BATTLES()
//   GameEvents.BattleDamageDelta.Add(function(iRole, iBaseDamage) return 0 end)
#define MOD_EVENTS_BATTLES_DAMAGE                   (MOD_EVENTS_BATTLES && gCustomMods.isEVENTS_BATTLES_DAMAGE())
#define MOD_EVENTS_BATTLES_CUSTOM_DAMAGE            (MOD_EVENTS_BATTLES && gCustomMods.isEVENTS_BATTLES_CUSTOM_DAMAGE())

//   GameEvents.TradeRouteMove.Add(function(iX, iY, iUnit, iOwner, iOriginalPlayer, iOriginalCity, iDestPlayer, iDestCity) end)
#define MOD_EVENTS_TRADE_ROUTE_MOVE                 (gCustomMods.isEVENTS_TRADE_ROUTE_MOVE())

// Minor bug fixes (missing catch-all else clauses, etc) (v30 onwards)
#define MOD_BUGFIX_MINOR 							(true)
// Minor bug fixes in the Lua API (v86 onwards)
#define MOD_BUGFIX_LUA_API 							(true)
// Adds validation to setting plot values (type, terrain, feature, resource, improvement and route) to stop CTDs in the graphics engine (v86)
#define MOD_BUGFIX_PLOT_VALIDATION					(true)
// Fixes some minor issues with the random number generator (v83)
#define MOD_BUGFIX_RANDOM							(true)
// Recodes direct access to (certain) member variables to use the associated getter/setter methods (v72 onwards)
#define MOD_BUGFIX_USE_GETTERS                      (true)
// Fixes the spy name crash (v53)
#define MOD_BUGFIX_SPY_NAMES                        (true)
// Fixes the bug when giving free religious units after the player has founded a religion not appearing in a religious city! (v78)
#define MOD_BUGFIX_FREE_RELIGIOUS_UNITS             (true)
// Fixes the issues with using dummy policies, thanks to LeeS for assistance with this (v77)
#define MOD_BUGFIX_DUMMY_POLICIES                   gCustomMods.isBUGFIX_DUMMY_POLICIES()
// Fixes the 'radaring' bug/exploit - see https://www.reddit.com/r/nqmod/comments/34reu9/how_to_remove_radaring/ (v74)
#define MOD_BUGFIX_RADARING                         gCustomMods.isBUGFIX_RADARING()
// Fixes the research NaN issue (v90)
#define MOD_BUGFIX_RESEARCH_NAN						(true)
// Fixes the research overflow bug/exploit (v52)
#define MOD_BUGFIX_RESEARCH_OVERFLOW                gCustomMods.isBUGFIX_RESEARCH_OVERFLOW()
// Fixes the bug where a city doesn't work its centre tile (v45)
#define MOD_BUGFIX_CITY_CENTRE_WORKING              (true)
// Fixes the bug of creating a capital from a puppet city, and leaving it that way (v73)
#define MOD_BUGFIX_NO_PUPPET_CAPITALS               (true)
// Adds missing policy events when adopting an ideology (v33)
#define MOD_BUGFIX_MISSING_POLICY_EVENTS			(true)
// Fixes trade routes sticking to coastal water when the player has the EmbarkAllWater trait (v33)
#define MOD_BUGFIX_TRADE_ROUTES_EMBARK_ALL_WATER	(true)
// Fixes the bug where Venice puppets it's own capital (v42)
#define MOD_BUGFIX_VENICE_PUPPETS_CAPITAL			(true)
// Fixes the bug in the Lua Plot:ChangeVisibilityCount() method where iChange is treated as a boolean and not a signed int (v23)
#define MOD_BUGFIX_LUA_CHANGE_VISIBILITY_COUNT      gCustomMods.isBUGFIX_LUA_CHANGE_VISIBILITY_COUNT()
// Fixes the bug that excludes spy pressure (Underground Sects) from the city banner tooltip display (v45)
#define MOD_BUGFIX_RELIGIOUS_SPY_PRESSURE           gCustomMods.isBUGFIX_RELIGIOUS_SPY_PRESSURE()
// Fixes the CanMoveAfterPurchase() bug where it is only tested for at one specific point in the code (v26)
#define MOD_BUGFIX_MOVE_AFTER_PURCHASE              gCustomMods.isBUGFIX_MOVE_AFTER_PURCHASE()
// Fixes the issues caused by using UNIT_XYZ instead of UNITCLASS_XYZ (v26)
#define MOD_BUGFIX_UNITCLASS_NOT_UNIT               gCustomMods.isBUGFIX_UNITCLASS_NOT_UNIT()
// Fixes the issues caused by using BUILDING_XYZ instead of INGCLASS_XYZ (v26)
#define MOD_BUGFIX_BUILDINGCLASS_NOT_BUILDING       gCustomMods.isBUGFIX_BUILDINGCLASS_NOT_BUILDING()
// Fixes the NumCitiesFreeFoodBuilding (policy finisher) bug where the civilization has a UB for the Aqueduct - AFFECTS SAVE GAME DATA FORMAT
#define MOD_BUGFIX_FREE_FOOD_BUILDING               gCustomMods.isBUGFIX_FREE_FOOD_BUILDING()
// Fixes the bug where the naval Civilization_FreeUnits start on land
#define MOD_BUGFIX_NAVAL_FREE_UNITS                 gCustomMods.isBUGFIX_NAVAL_FREE_UNITS()
// Fixes the bug where the naval units jump to the nearest city and not the nearest available non-lake water plot
#define MOD_BUGFIX_NAVAL_NEAREST_WATER              gCustomMods.isBUGFIX_NAVAL_NEAREST_WATER()
// Fixes the bug where naval units in hill cities attack from the top of the hill, not the harbour (v95)
#define MOD_BUGFIX_NAVAL_TARGETING					(true)
// Fixes the bug where stacked ranged units may attack out of cities but melee units may not
#define MOD_BUGFIX_CITY_STACKING                    gCustomMods.isBUGFIX_CITY_STACKING()
// Fixes the bug in goody hut messages that have parameters (v38)
#define MOD_BUGFIX_GOODY_HUT_MESSAGES               (true)
// Fixes the bug where Barb Camps ignore the ValidTerrains and ValidFeatures tables
#define MOD_BUGFIX_BARB_CAMP_TERRAINS               gCustomMods.isBUGFIX_BARB_CAMP_TERRAINS()
// Fixes the bug where Barb Camps won't spawn units if they are added via pPlot:SetImprovementType() (v21)
#define MOD_BUGFIX_BARB_CAMP_SPAWNING               gCustomMods.isBUGFIX_BARB_CAMP_SPAWNING()
// Fixes the bug where ranged combat (archers, catapults, ships and planes) against barbarians generates Great People XP (v43)
#define MOD_BUGFIX_BARB_GP_XP                       gCustomMods.isBUGFIX_BARB_GP_XP()
// Fixes the bug where you can't remove roads in no-mans-land originally built by a now dead player
#define MOD_BUGFIX_REMOVE_GHOST_ROUTES              gCustomMods.isBUGFIX_REMOVE_GHOST_ROUTES()
// Fixes healing units ignoring enemy units and sleeping units under direct fire remaining asleep - thanks to hulkster for highlighting the latter issue
#define MOD_BUGFIX_UNITS_AWAKE_IN_DANGER            gCustomMods.isBUGFIX_UNITS_AWAKE_IN_DANGER()
// Fixes workers stopping what they are doing at any hint of danger to only when they can see an enemy unit
#define MOD_BUGFIX_WORKERS_VISIBLE_DANGER           gCustomMods.isBUGFIX_WORKERS_VISIBLE_DANGER()
// Fixes the hard-coding of what builds remove which features (v45)
#define MOD_BUGFIX_FEATURE_REMOVAL                  gCustomMods.isBUGFIX_FEATURE_REMOVAL()
// Fixes the bug in calculating AA interception strength which takes terrain into account
#define MOD_BUGFIX_INTERCEPTOR_STRENGTH             gCustomMods.isBUGFIX_INTERCEPTOR_STRENGTH()
// Fixes the very dodgy maths in the calculation of a unit's power
#define MOD_BUGFIX_UNIT_POWER_CALC                  gCustomMods.isBUGFIX_UNIT_POWER_CALC()
// Fixes the Anti-Air non-domain bonuses issue, requires BUGFIX_UNIT_POWER_CALC to be enabled
#define MOD_BUGFIX_UNIT_POWER_BONUS_VS_DOMAIN_ONLY  gCustomMods.isBUGFIX_UNIT_POWER_BONUS_VS_DOMAIN_ONLY()
// Fixes the naval imbalance in a unit's power calculation, requires BUGFIX_UNIT_POWER_CALC to be enabled
#define MOD_BUGFIX_UNIT_POWER_NAVAL_CONSISTENCY     gCustomMods.isBUGFIX_UNIT_POWER_NAVAL_CONSISTENCY()
// Fixes the bug where units can upgrade even without any pre-req project being available (v22)
#define MOD_BUGFIX_UNIT_PREREQ_PROJECT              gCustomMods.isBUGFIX_UNIT_PREREQ_PROJECT()
// Fixes a bug where hovering units can be chosen as rebels! (v39)
#define MOD_BUGFIX_NO_HOVERING_REBELS               gCustomMods.isBUGFIX_NO_HOVERING_REBELS()
// Fixes a bug in the pathfinder code for hovering units at the seaside!
#define MOD_BUGFIX_HOVERING_PATHFINDER              gCustomMods.isBUGFIX_HOVERING_PATHFINDER()
// Fixes a bug in the pathfinder code for embarking
#define MOD_BUGFIX_EMBARKING_PATHFINDER             gCustomMods.isBUGFIX_EMBARKING_PATHFINDER()

#define MOD_BUGFIX_BUILDING_FREEBUILDING             gCustomMods.isBUGFIX_BUILDING_FREEBUILDING()

#define MOD_BUGFIX_INVISIBLE_UNIT_MOVE_ENEMY_CITY             gCustomMods.isBUGFIX_INVISIBLE_UNIT_MOVE_ENEMY_CITY()

#define MOD_BALANCE_CORE                            gCustomMods.isBALANCE_CORE()
#define MOD_VOLCANO_BREAK                            gCustomMods.isVOLCANO_BREAK()
#define MOD_ERA_EFFECTS_EXTENSIONS                  gCustomMods.isERA_EFFECTS_EXTENSIONS()

// Enables improvements create sources or new improvement when built (CIV5MPDLL)
#define MOD_IMPROVEMENTS_CREATE_ITEMS            	gCustomMods.isIMPROVEMENTS_CREATE_ITEMS()

#define MOD_IMPROVEMENTS_UPGRADE                    gCustomMods.isIMPROVEMENTS_UPGRADE()

// Enables the Improvement Trade Route Bonus
#define MOD_IMPROVEMENT_TRADE_ROUTE_BONUSES			gCustomMods.isIMPROVEMENT_TRADE_ROUTE_BONUSES()

#define MOD_GLOBAL_WAR_CASUALTIES                   gCustomMods.isGLOBAL_WAR_CASUALTIES()

#define MOD_TRAIT_RELIGION_FOLLOWER_EFFECTS         gCustomMods.isTRAIT_RELIGION_FOLLOWER_EFFECTS()

#define MOD_BATTLE_CAPTURE_NEW_RULE         gCustomMods.isBATTLE_CAPTURE_NEW_RULE()

#endif // ACHIEVEMENT_HACKS


//
// MOD_PROMOTIONS_XYZ changes manage/grant the promotions and may affect the game saving code
// MOD_PATHFINDER_XYZ changes only affect the path finding code so can be disabled if necessary
//

#if defined(MOD_PROMOTIONS_CROSS_MOUNTAINS)
#define MOD_PATHFINDER_CROSS_MOUNTAINS         MOD_PROMOTIONS_CROSS_MOUNTAINS
#endif
#if defined(MOD_PROMOTIONS_CROSS_OCEANS)
#define MOD_PATHFINDER_CROSS_OCEANS            MOD_PROMOTIONS_CROSS_OCEANS
#endif
#if defined(MOD_PROMOTIONS_CROSS_ICE)
#define MOD_PATHFINDER_CROSS_ICE               MOD_PROMOTIONS_CROSS_ICE
#endif
#if defined(MOD_PROMOTIONS_DEEP_WATER_EMBARKATION)
#define MOD_PATHFINDER_DEEP_WATER_EMBARKATION  MOD_PROMOTIONS_DEEP_WATER_EMBARKATION
#endif

// ONLY CHANGE THIS IF YOU TRULY KNOW WHAT YOU ARE DOING IN THE PATHFINDER CODE!!!
#if defined(MOD_PATHFINDER_CROSS_ICE) || defined(MOD_PATHFINDER_DEEP_WATER_EMBARKATION)
#define MOD_PATHFINDER_TERRAFIRMA
#endif




//   GameEvents.GreatWorkCreated.Add(function(iPlayer, iUnit, iGreatWork) end)
#define MOD_EVENTS_GREAT_WORK_CREATED                 gCustomMods.isEVENTS_GREAT_WORK_CREATED()

//   GameEvents.ScienceDiscover.Add(function(iPlayer,iUnit,iX,iY,bIsGreatPerson) end) 
//   GameEvents.CultureDiscover.Add(function(iPlayer, iUnit, iX, iY, bIsGreatPerson) end)
//   GameEvents.TourismDiscover.Add(function(iPlayer, iUnit, iX, iY, bIsGreatPerson) end)
//   GameEvents.ProductionDiscover.Add(function(iPlayer, iUnit, iX, iY, bIsGreatPerson) end)
//   GameEvents.GoldDiscover.Add(function(iPlayer, iUnit, iX, iY, bIsGreatPerson) end)
//   GameEvents.GoldenAgeDiscover.Add(function(iPlayer, iUnit, iX, iY, bIsGreatPerson) end)
//   GameEvents.CultureBombDiscover.Add(function(iPlayer, iUnit, iX, iY, bIsGreatPerson) end)
//   GameEvents.FaithDiscover.Add(function(iPlayer, iUnit, iX, iY, bIsGreatPerson) end)
#define MOD_EVENTS_GREAT_PEOPLE_BOOST                 gCustomMods.isEVENTS_GREAT_PEOPLE_BOOST()

//   GameEvents.CityPuppeted.Add(function(playerID, cityID) end) 
#define MOD_EVENTS_CITY_PUPPETED                      gCustomMods.isEVENTS_CITY_PUPPETED()


//   GameEvents.DoDenounce.Add(function(PlayerID, OtherPlayerID) end) 
#define MOD_EVENTS_DO_DENOUNCE                      gCustomMods.isEVENTS_DO_DENOUNCE ()

//  GameEvents.TileSetOwnership.Add(iPlotX, iPlotY, iOldOwner,iNewOwner) end)
#define MOD_EVENTS_TILE_SET_OWNER                gCustomMods.isEVENTS_TILE_SET_OWNER()

//   GameEvents.TileImprovementPillaged.Add(iPlotX, iPlotY, iOwner,iImprovement,bPillaged) end)
#define MOD_EVENTS_IMPROVEMENTS_PILLAGED          gCustomMods.isEVENTS_IMPROVEMENTS_PILLAGED()  

// Event sent when a city is fired
//   GameEvents.CityBeginsWLTKD.Add(iPlayer, iPlotX, iPlotY, iChange) end)
//   GameEvents.CityEndsWLTKD.Add(iPlayer, iPlotX, iPlotY) end)
#define MOD_EVENTS_WLKD_DAY                 gCustomMods.isEVENTS_WLKD_DAY()

// Event sent when a city is wlkd
//   GameEvents.CityRangedStrike.Add(function(iPlayer,iCity, iX, iY) end)
#define MOD_EVENTS_CITY_RANGE_STRIKE                 gCustomMods.isEVENTS_CITY_RANGE_STRIKE()

// Event sent to ascertain if a unit can perform a ranged attack on a tile (v90)
//   GameEvents.UnitCanRangeAttackPlot.Add(function(iPlayer, iUnit, iPlotX, iPlotY, bNeedWar) return false end)
#define MOD_EVENTS_UNIT_CAN_RANGEATTACK           gCustomMods.isEVENTS_UNIT_CAN_RANGEATTACK()


// Event sent to ascertain if a unit can move into a given plot - VERY, VERY CPU INTENSIVE!!!
//   GameEvents.UnitMoveInto.Add(function(iPlayer, iUnit, iPlotX, iPlotY, bAttack, bDeclareWar) return true end)
#define MOD_EVENTS_UNIT_MOVE                    gCustomMods.isEVENTS_UNIT_MOVE()


// Event sent to ascertain if a unit can move into a given plot - VERY, VERY CPU INTENSIVE!!!
//   GameEvents.UnitDoTurn.Add(function(iPlayer, iUnit, iPlotX, iPlotY) end)
#define MOD_EVENTS_UNIT_DO_TURN                    gCustomMods.isEVENTS_UNIT_DO_TURN()


// When a military unit retreats, civilians units on the same tile also retreat
#define MOD_CIVILIANS_RETREAT_WITH_MILITARY			gCustomMods.isCIVILIANS_RETREAT_WITH_MILITARY()
#define MOD_AIR_SWEEP_FOUND_SOMETHING				gCustomMods.isAIR_SWEEP_FOUND_SOMETHING()
#define MOD_SHOW_ATTACK_INTERFACE_WITHOUT_ENEMY		gCustomMods.isSHOW_ATTACK_INTERFACE_WITHOUT_ENEMY()

// SOME BASE FOUNCTION
#define MOD_TRAIN_ALL_CORE                             gCustomMods.isTRAIN_ALL_CORE()
#define MOD_ROG_CORE                                   gCustomMods.isROG_CORE()
#define MOD_DISEASE_BREAK                                   gCustomMods.isDISEASE_BREAK()
#define MOD_IMPROVEMENT_FUNCTION                       gCustomMods.isIMPROVEMENT_FUNCTION()
#define MOD_BUILDING_IMPROVEMENT_RESOURCES              gCustomMods.isBUILDING_IMPROVEMENT_RESOURCES()
#define MOD_MORE_NATURAL_WONDER					       gCustomMods.isMORE_NATURAL_WONDER()

#define MOD_GLOBAL_UNLIMITED_ONE_TURN_GROWTH             gCustomMods.isGLOBAL_UNLIMITED_ONE_TURN_GROWTH()
#define MOD_GLOBAL_UNLIMITED_ONE_TURN_PRODUCTION             gCustomMods.isGLOBAL_UNLIMITED_ONE_TURN_PRODUCTION()
#define MOD_GLOBAL_UNLIMITED_ONE_TURN_CULTURE             gCustomMods.isGLOBAL_UNLIMITED_ONE_TURN_CULTURE()
#define MOD_GLOBAL_UNLIMITED_ONE_TURN_TECH             gCustomMods.isGLOBAL_UNLIMITED_ONE_TURN_TECH()

#define MOD_GLOBAL_UNIT_EXTRA_ATTACK_DEFENSE_EXPERENCE      gCustomMods.isGLOBAL_UNIT_EXTRA_ATTACK_DEFENSE_EXPERENCE()
#define MOD_UNIT_BOUND_IMPROVEMENT      					gCustomMods.isUNIT_BOUND_IMPROVEMENT()
#define MOD_GLOBAL_TRIGGER_NEW_GOLDEN_AGE_IN_GA             gCustomMods.isGLOBAL_TRIGGER_NEW_GOLDEN_AGE_IN_GA()
#define MOD_POLICY_NEW_EFFECT_FOR_SP            			gCustomMods.isPOLICY_NEW_EFFECT_FOR_SP()
#define MOD_GLOBAL_UNIT_MOVES_AFTER_DISEMBARK             	gCustomMods.isGLOBAL_UNIT_MOVES_AFTER_DISEMBARK()
#define MOD_GLOBAL_INCREASE_SS_PART_PURCHASE_COST           gCustomMods.isGLOBAL_INCREASE_SS_PART_PURCHASE_COST()
#define MOD_GLOBAL_RANGE_ATTACK_KILL_POPULATION_OF_HEAVY    gCustomMods.isGLOBAL_RANGE_ATTACK_KILL_POPULATION_OF_HEAVY()
#define MOD_GLOBAL_CAPTURE_UNIT_CANNOT_MAX_OUT             	gCustomMods.isGLOBAL_CAPTURE_UNIT_CANNOT_MAX_OUT()
#define MOD_GLOBAL_BUILDING_INSTANT_YIELD             		gCustomMods.isGLOBAL_BUILDING_INSTANT_YIELD()
#define MOD_BUILDING_NEW_EFFECT_FOR_SP           			gCustomMods.isBUILDING_NEW_EFFECT_FOR_SP()
#define MOD_VOTING_NEW_EFFECT_FOR_SP           				gCustomMods.isVOTING_NEW_EFFECT_FOR_SP()
#define MOD_BELIEF_NEW_EFFECT_FOR_SP             			(MOD_GLOBAL_BUILDING_INSTANT_YIELD && gCustomMods.isBELIEF_NEW_EFFECT_FOR_SP())
#define MOD_PROMOTION_NEW_EFFECT_FOR_SP           			gCustomMods.isPROMOTION_NEW_EFFECT_FOR_SP()
#define MOD_PROMOTION_AURA_PROMOTION           				gCustomMods.isPROMOTION_AURA_PROMOTION()
#define MOD_TRAIT_NEW_EFFECT_FOR_SP           				gCustomMods.isTRAIT_NEW_EFFECT_FOR_SP()
#define MOD_TRAIT_WOOD_AS_ROAD_SP           				gCustomMods.isTRAIT_WOOD_AS_ROAD_SP()
#define MOD_TROOPS_AND_CROPS_FOR_SP           				gCustomMods.isTROOPS_AND_CROPS_FOR_SP()
#define MOD_INTERNATIONAL_IMMIGRATION_FOR_SP           		gCustomMods.isINTERNATIONAL_IMMIGRATION_FOR_SP()
#define MOD_NUCLEAR_WINTER_FOR_SP           				gCustomMods.isNUCLEAR_WINTER_FOR_SP()

#define MOD_UNIT_COST_DONOT_INCTEASE_WITH_TURN           	gCustomMods.isUNIT_COST_DONOT_INCTEASE_WITH_TURN()
#define MOD_NO_FASTER_REPAIR_OUTSIDE           				gCustomMods.isNO_FASTER_REPAIR_OUTSIDE()
#define MOD_GLOBAL_MAX_PLOT_BUILD           				gCustomMods.isGLOBAL_MAX_PLOT_BUILD()
#define MOD_CITY_NO_DECAY           						gCustomMods.isCITY_NO_DECAY()
#define MOD_CHANGE_RESOURCE_LINK_AFTER_ALTER_PLOT           gCustomMods.isCHANGE_RESOURCE_LINK_AFTER_ALTER_PLOT()
#define MOD_POLICY_FREE_PROMOTION_FOR_PROMOTION             gCustomMods.isPOLICY_FREE_PROMOTION_FOR_PROMOTION()
#define MOD_PROMOTION_FEATURE_INVISIBLE             		gCustomMods.isPROMOTION_FEATURE_INVISIBLE()

#define MOD_PROMOTION_SPLASH_DAMAGE             		gCustomMods.isPROMOTION_SPLASH_DAMAGE()
#define MOD_PROMOTION_COLLATERAL_DAMAGE             		gCustomMods.isPROMOTION_COLLATERAL_DAMAGE()
#define MOD_PROMOTION_ADD_ENEMY_PROMOTIONS             		gCustomMods.isPROMOTION_ADD_ENEMY_PROMOTIONS()
#define MOD_PROMOTION_CITY_DESTROYER             		gCustomMods.isPROMOTION_CITY_DESTROYER()
#define MOD_GLOBAL_PROMOTIONS_REMOVAL 		   		                gCustomMods.isGLOBAL_PROMOTIONS_REMOVAL()

#ifdef MOD_PROMOTION_SPLASH_DAMAGE
#define MOD_NEW_BATTLE_EFFECTS (MOD_PROMOTION_SPLASH_DAMAGE || MOD_PROMOTION_COLLATERAL_DAMAGE || MOD_PROMOTION_ADD_ENEMY_PROMOTIONS || MOD_PROMOTION_CITY_DESTROYER)
#endif

#define MOD_GLOBAL_CITY_SCALES gCustomMods.isGLOBAL_CITY_SCALES()
#define MOD_EVENTS_CITY_SCALES gCustomMods.isEVENTS_CITY_SCALES()

#define MOD_PROMOTION_COLLECTIONS
#define MOD_BUILDINGCLASS_COLLECTIONS

#define MOD_SPECIALIST_RESOURCES gCustomMods.isSPECIALIST_RESOURCES()

#define MOD_POLICIY_PUBLIC_OPTION gCustomMods.isPOLICIY_PUBLIC_OPTION()

#define MOD_TRAITS_GOLDEN_AGE_YIELD_MODIFIER gCustomMods.isTRAITS_GOLDEN_AGE_YIELD_MODIFIER()

#define MOD_BUGFIX_CITY_NEGATIVE_YIELD_MODIFIED gCustomMods.isBUGFIX_CITY_NEGATIVE_YIELD_MODIFIED()

#define MOD_RESOURCE_EXTRA_BUFF gCustomMods.isRESOURCE_EXTRA_BUFF()

#define MOD_SP_SMART_AI	 gCustomMods.isSP_SMART_AI()
// Used in the AI deal
#define MOD_SP_SMART_AI_DEAL MOD_SP_SMART_AI

#define MOD_SP_FASTER_AI	 gCustomMods.isSP_FASTER_AI()

#define MOD_TRAITS_SPREAD_RELIGION_AFTER_KILLING gCustomMods.isTRAITS_SPREAD_RELIGION_AFTER_KILLING()
#define MOD_TRAITS_COMBAT_BONUS_FROM_CAPTURED_HOLY_CITY gCustomMods.isTRAITS_COMBAT_BONUS_FROM_CAPTURED_HOLY_CITY()
#define MOD_TRAITS_SIEGE_BONUS_IF_SAME_RELIGION gCustomMods.isTRAITS_SIEGE_BONUS_IF_SAME_RELIGION()
#define MOD_TRAITS_ENABLE_FAITH_PURCHASE_ALL_COMBAT_UNITS gCustomMods.isTRAITS_ENABLE_FAITH_PURCHASE_ALL_COMBAT_UNITS()

#define MOD_IMPROVEMENTS_YIELD_CHANGE_PER_UNIT gCustomMods.isIMPROVEMENTS_YIELD_CHANGE_PER_UNIT()
#define MOD_IMPROVEMENTS_UNIT_XP_PER_TURN gCustomMods.isIMPROVEMENTS_UNIT_XP_PER_TURN()

#define MOD_GLOBAL_CORRUPTION gCustomMods.isGLOBAL_CORRUPTION()
#define MOD_GLOBAL_CORRUPTION_POLICY_COST_MIN_ZERO gCustomMods.isGLOBAL_CORRUPTION_POLICY_COST_MIN_ZERO()
#define MOD_GLOBAL_UNIT_BARBARIAN_CAN_TRAIN gCustomMods.isGLOBAL_UNIT_BARBARIAN_CAN_TRAIN()
#define MOD_GLOBAL_SP_BARBARIAN_ENHANCE gCustomMods.isGLOBAL_SP_BARBARIAN_ENHANCE()
#define MOD_GLOBAL_UNIQUE_PROJECT_CAPTURE gCustomMods.isGLOBAL_UNIQUE_PROJECT_CAPTURE()
#define MOD_GLOBAL_HOLY_CITY_FOUNDER_CHANGE gCustomMods.isGLOBAL_HOLY_CITY_FOUNDER_CHANGE()
#define MOD_GLOBAL_OPTIONAL_UC gCustomMods.isGLOBAL_OPTIONAL_UC()

#define MOD_DISABLE_AI_DO_TURN_DIPLOMACY_TO_HUMAN gCustomMods.isDISABLE_AI_DO_TURN_DIPLOMACY_TO_HUMAN();
//
// NOTHING BELOW HERE SHOULD NEED CHANGING
//

// Terraforming event types
enum TerraformingEventTypes {
	NO_TERRAFORMINGEVENT = -1,
	TERRAFORMINGEVENT_LOAD,
	TERRAFORMINGEVENT_AREA,
	TERRAFORMINGEVENT_LANDMASS,
	TERRAFORMINGEVENT_CONTINENT,
	TERRAFORMINGEVENT_PLOT,
	TERRAFORMINGEVENT_TERRAIN,
	TERRAFORMINGEVENT_FEATURE,
	TERRAFORMINGEVENT_RIVER,
	TERRAFORMINGEVENT_CITY,
	NUM_TERRAFORMINGEVENT_TYPES
};


// Player diplomacy and military event loggers
#if defined(MOD_API_PLAYER_LOGS)
#define DIPLOMACYLOG(eForPlayer, sMessage, eFromPlayer, eDiploUIState, eDiploMessage)                  \
	if (MOD_API_PLAYER_LOGS) {                                                                          \
		GET_PLAYER(eForPlayer).AddDiplomacyEvent(sMessage, eFromPlayer, eDiploUIState, eDiploMessage); \
CUSTOMLOG("DiploLog: For=%i, From=%i, Dstate=%i, Dmsg=%i - %s", eForPlayer, eFromPlayer, eDiploUIState, eDiploMessage, sMessage);\
	}
#define MILITARYLOG(eForPlayer, sMessage, pPlot, eOtherPlayer)                  \
	if (MOD_API_PLAYER_LOGS) {                                                  \
		GET_PLAYER(eForPlayer).AddMilitaryEvent(sMessage, pPlot, eOtherPlayer); \
	}
#else
#define DIPLOMACYLOG(eForPlayer, sMessage, eOtherPlayer, eDiploUIState, eDiploMessage)  __noop
#define MILITARYLOG(eForPlayer, sMessage, pPlot, eOtherPlayer)                          __noop
#endif


// Battle event macros
enum BattleTypeTypes
{
	BATTLE_TYPE_MELEE,
	BATTLE_TYPE_RANGED,
	BATTLE_TYPE_AIR,
	BATTLE_TYPE_SWEEP,
	BATTLE_TYPE_PARADROP,
	BATTLE_TYPE_NUKE
};

#if defined(MOD_EVENTS_BATTLES)
#define BATTLE_STARTED(iType, pPlot)              if (MOD_EVENTS_BATTLES) { GAMEEVENTINVOKE_HOOK(GAMEEVENT_BattleStarted, iType, pPlot.getX(), pPlot.getY()); }
#define BATTLE_JOINED(pCombatant, iRole, bIsCity) if (MOD_EVENTS_BATTLES && pCombatant) { GAMEEVENTINVOKE_HOOK(GAMEEVENT_BattleJoined, (pCombatant)->getOwner(), (pCombatant)->GetID(), iRole, bIsCity); }
#define BATTLE_FINISHED(bIsCaptured)			  if (MOD_EVENTS_BATTLES) { GAMEEVENTINVOKE_HOOK(GAMEEVENT_BattleFinished, bIsCaptured); }
#else
#define BATTLE_STARTED(pPlot)            __noop
#define BATTLE_JOINED(pCombatant, iRole) __noop
#define BATTLE_FINISHED()                __noop
#endif


// Custom mod logger
#if defined(CUSTOMLOGDEBUG)
#if defined(CUSTOMLOGFILEINFO) && defined(CUSTOMLOGFUNCINFO)
#define CUSTOMLOG(sFmt, ...) {																					\
	CvString sMsg; CvString::format(sMsg, sFmt, __VA_ARGS__);													\
	CvString sLine; CvString::format(sLine, "%s[%i]: %s - %s", __FILE__, __LINE__, __FUNCTION__, sMsg.c_str());	\
	LOGFILEMGR.GetLog(CUSTOMLOGDEBUG, FILogFile::kDontTimeStamp)->Msg(sLine.c_str());							\
}
#endif
#if defined(CUSTOMLOGFILEINFO) && !defined(CUSTOMLOGFUNCINFO)
#define CUSTOMLOG(sFmt, ...) {																					\
	CvString sMsg; CvString::format(sMsg, sFmt, __VA_ARGS__);													\
	CvString sLine; CvString::format(sLine, "%s[%i] - %s", __FILE__, __LINE__, sMsg.c_str());					\
	LOGFILEMGR.GetLog(CUSTOMLOGDEBUG, FILogFile::kDontTimeStamp)->Msg(sLine.c_str());							\
}
#endif
#if !defined(CUSTOMLOGFILEINFO) && defined(CUSTOMLOGFUNCINFO)
#define CUSTOMLOG(sFmt, ...) {																					\
	CvString sMsg; CvString::format(sMsg, sFmt, __VA_ARGS__);													\
	CvString sLine; CvString::format(sLine, "%s - %s", __FUNCTION__, sMsg.c_str());								\
	LOGFILEMGR.GetLog(CUSTOMLOGDEBUG, FILogFile::kDontTimeStamp)->Msg(sLine.c_str());							\
}
#endif
#if !defined(CUSTOMLOGFILEINFO) && !defined(CUSTOMLOGFUNCINFO)
#define CUSTOMLOG(sFmt, ...) {																					\
	CvString sMsg; CvString::format(sMsg, sFmt, __VA_ARGS__);													\
	LOGFILEMGR.GetLog(CUSTOMLOGDEBUG, FILogFile::kDontTimeStamp)->Msg(sMsg.c_str());							\
}
#endif
#else
#define CUSTOMLOG(sFmt, ...) __noop
#endif

// Unified yields logger
#if defined(UNIFIEDLOGDEBUG)
#define UNIFIEDLOG(sFmt, ...) {																		\
	CvString sMsg; CvString::format(sMsg, sFmt, __VA_ARGS__);										\
	CvString sLine; CvString::format(sLine, "%s[%i] - %s", __FILE__, __LINE__, sMsg.c_str());	    \
	LOGFILEMGR.GetLog(UNIFIEDLOGDEBUG, FILogFile::kDontTimeStamp)->Msg(sLine.c_str());			    \
}
#else
#define UNIFIEDLOG(sFmt, ...) __noop
#endif


// Message wrappers
#define SHOW_PLAYER_MESSAGE(pPlayer, szMessage)       DLLUI->AddMessage(0, pPlayer->GetID(), false, GC.getEVENT_MESSAGE_TIME(), szMessage)
#define SHOW_CITY_MESSAGE(pCity, ePlayer, szMessage)  DLLUI->AddCityMessage(0, pCity->GetIDInfo(), ePlayer, false, GC.getEVENT_MESSAGE_TIME(), szMessage)
#define SHOW_UNIT_MESSAGE(pUnit, ePlayer, szMessage)  DLLUI->AddUnitMessage(0, pUnit->GetIDInfo(), ePlayer, false, GC.getEVENT_MESSAGE_TIME(), szMessage)
#define SHOW_PLOT_MESSAGE(pPlot, ePlayer, szMessage)  DLLUI->AddPlotMessage(0, pPlot->GetPlotIndex(), ePlayer, false, GC.getEVENT_MESSAGE_TIME(), szMessage)
#define SHOW_PLOT_POPUP(pPlot, ePlayer, szMessage, fDelay)  pPlot->showPopupText(ePlayer, szMessage)


// GlobalDefines wrappers
#define GD_INT_DECL(name)         int m_i##name
#define GD_INT_DEF(name)          inline int get##name() { return m_i##name; }
#define GD_INT_INIT(name, def)    m_i##name(def)
#define GD_INT_CACHE(name)        m_i##name = getDefineINT(#name); CUSTOMLOG("<Defines>: %s = %i", #name, m_i##name)
#define GD_INT_GET(name)          GC.get##name()

#define GD_FLOAT_DECL(name)       float m_f##name
#define GD_FLOAT_DEF(name)        inline float get##name() { return m_f##name; }
#define GD_FLOAT_INIT(name, def)  m_f##name(def)
#define GD_FLOAT_CACHE(name)      m_f##name = getDefineFLOAT(#name); CUSTOMLOG("<Defines>: %s = %f", #name, m_f##name)
#define GD_FLOAT_GET(name)        GC.get##name()


// LUA API wrappers
#define LUAAPIEXTN(method, type, ...) static int l##method(lua_State* L)
#define LUAAPIIMPL(object, method) int CvLua##object::l##method(lua_State* L) { return BasicLuaMethod(L, &Cv##object::##method); }
#define LUAAPIINLINE(method, hasMethod, type) inline bool method() const { return hasMethod(type); }


// Game Event wrappers
#include "Lua\CvLuaSupport.h"
#define GAMEEVENTINVOKE_HOOK    gCustomMods.eventHook
#define GAMEEVENTINVOKE_TESTANY gCustomMods.eventTestAny
#define GAMEEVENTINVOKE_TESTALL gCustomMods.eventTestAll
#define GAMEEVENTINVOKE_VALUE   gCustomMods.eventAccumulator

#define GAMEEVENTRETURN_NONE  -1
#define GAMEEVENTRETURN_FALSE  0
#define GAMEEVENTRETURN_TRUE   1
#define GAMEEVENTRETURN_HOOK   GAMEEVENTRETURN_TRUE
#define GAMEEVENTRETURN_VALUE  GAMEEVENTRETURN_TRUE

// Pairs of event names and (optional) parameter types
//    iii means three int params
//    ibi means an int, then a bool, then a final int
//    s means a string (char*) and is only allowed as the last parameter
#define GAMEEVENT_AiOverrideChooseNextTech		"AiOverrideChooseNextTech",		"ib"
#define GAMEEVENT_AreaCanHaveAnyResource		"AreaCanHaveAnyResource",		"ii"
#define GAMEEVENT_BarbariansCanFoundCamp		"BarbariansCanFoundCamp",		"ii"
#define GAMEEVENT_BarbariansCampFounded			"BarbariansCampFounded",		"ii"
#define GAMEEVENT_BarbariansCampCleared			"BarbariansCampCleared",		"iii"
#define GAMEEVENT_BarbariansCampCanSpawnUnit	"BarbariansCampCanSpawnUnit",	"ii"
#define GAMEEVENT_BarbariansCampGetSpawnUnit	"BarbariansCampGetSpawnUnit",	"iii"
#define GAMEEVENT_BarbariansSpawnedUnit			"BarbariansSpawnedUnit",		"iiiii"
#define GAMEEVENT_BattleDamageDelta				"BattleDamageDelta",			"ii"
// BattleCustomDamage(iBattleUnitType, iBattleType,
//                    iAttackPlayerID, iAttackUnitOrCityID, bAttackIsCity, iAttackDamage,
//                    iDefensePlayerID, iDefenseUnitOrCityID, bDefenseIsCity, iDefenseDamage,
//                    iInterceptorPlayerID, iInterceptorUnitOrCityID, bInterceptorIsCity, iInterceptorDamage,
//                    ) -> iDamageDelta
#define GAMEEVENT_BattleCustomDamage			"BattleCustomDamage",			"iiiibiiibiiibi"
#define GAMEEVENT_BattleFinished				"BattleFinished",				"b"
#define GAMEEVENT_BattleJoined					"BattleJoined",					"iiib"
#define GAMEEVENT_BattleStarted					"BattleStarted",				"iii"
#define GAMEEVENT_CanAirliftFrom				"CanAirliftFrom",				"iiii"
#define GAMEEVENT_CanAirliftTo					"CanAirliftTo",					"iiii"
#define GAMEEVENT_CanDoCommand					"CanDoCommand",					"iiiiiiib"
#define GAMEEVENT_CanHaveAnyUpgrade				"CanHaveAnyUpgrade",			"ii"
#define GAMEEVENT_CanHavePromotion				"CanHavePromotion",				"iii"
#define GAMEEVENT_CanHaveUpgrade				"CanHaveUpgrade",				"iiii"
#define GAMEEVENT_CanLoadAt						"CanLoadAt",					"iiii"
#define GAMEEVENT_CanMoveInto					"CanMoveInto",					"iiiibb"
#define GAMEEVENT_CannotParadropFrom			"CannotParadropFrom",			"iiii"
#define GAMEEVENT_CanParadropFrom				"CanParadropFrom",				"iiii"
#define GAMEEVENT_CanRebaseInCity				"CanRebaseInCity",				"iiii"
#define GAMEEVENT_CanRebaseTo					"CanRebaseTo",					"iiiib"
#define GAMEEVENT_CapitalChanged				"CapitalChanged",				"iii"
#define GAMEEVENT_CircumnavigatedGlobe			"CircumnavigatedGlobe",			"i"
#define GAMEEVENT_CityBoughtPlot				"CityBoughtPlot",				"iiiibb"
#define GAMEEVENT_CityCanAcquirePlot			"CityCanAcquirePlot",			"iiii"
#define GAMEEVENT_CityCanAirlift				"CityCanAirlift",				"ii"
#define GAMEEVENT_CityConnected					"CityConnected",				"iiiiib"
#define GAMEEVENT_CityConnections				"CityConnections",				"ib"
#define GAMEEVENT_CityConstructed				"CityConstructed",				"iiibb"
#define GAMEEVENT_CityCreated					"CityCreated",					"iiibb"
#define GAMEEVENT_CityPrepared					"CityPrepared",					"iiibb"
#define GAMEEVENT_CitySoldBuilding				"CitySoldBuilding",				"iii"
#define GAMEEVENT_CityTrained					"CityTrained",					"iiibb"
#define GAMEEVENT_CityProjectComplete			"CityProjectComplete",			"iii"
#define GAMEEVENT_CustomMissionCompleted		"CustomMissionCompleted",		"iiiiiii"
#define GAMEEVENT_CustomMissionCameraTime		"CustomMissionCameraTime",		"iiiiiii"
#define GAMEEVENT_CustomMissionDoStep			"CustomMissionDoStep",			"iiiiiii"
#define GAMEEVENT_CustomMissionPossible			"CustomMissionPossible",		"iiiiiiiiib"
#define GAMEEVENT_CustomMissionStart			"CustomMissionStart",			"iiiiiii"
#define GAMEEVENT_CustomMissionSetActivity		"CustomMissionSetActivity",		"iiiiiii"
#define GAMEEVENT_CustomMissionTargetPlot		"CustomMissionTargetPlot",		"iiiiiii"
#define GAMEEVENT_CustomMissionTimerInc			"CustomMissionTimerInc",		"iiiiiii"
#define GAMEEVENT_DeclareWar					"DeclareWar",					"iib"
#define GAMEEVENT_DiplomacyStfu					"DiplomacyStfu",				"iiiiii"
#define GAMEEVENT_DiplomacyStfuLeaveLeader		"DiplomacyStfuLeaveLeader",		"i"
#define GAMEEVENT_EspionageCanMoveSpyTo			"EspionageCanMoveSpyTo",		"iii"
#define GAMEEVENT_EspionageCanStageCoup			"EspionageCanStageCoup",		"iii"
#define GAMEEVENT_EspionageResult				"EspionageResult",				"iiiii"
#define GAMEEVENT_EspionageState				"EspionageState",				"iiiii"
#define GAMEEVENT_GetDiploModifier				"GetDiploModifier",				"iii"
#define GAMEEVENT_GetBombardRange				"GetBombardRange",				"ii"
#define GAMEEVENT_GetReligionToFound			"GetReligionToFound",			"iib"
#define GAMEEVENT_GoodyHutCanNotReceive			"GoodyHutCanNotReceive",		"iiib"
#define GAMEEVENT_GoodyHutCanResearch			"GoodyHutCanResearch",			"ii"
#define GAMEEVENT_GoodyHutTechResearched		"GoodyHutTechResearched",		"ii"
#define GAMEEVENT_GreatPersonExpended			"GreatPersonExpended",			"iiiii"
#define GAMEEVENT_IsAbleToDeclareWar			"IsAbleToDeclareWar",			"ii"
#define GAMEEVENT_IsAbleToMakePeace				"IsAbleToMakePeace",			"ii"
#define GAMEEVENT_MakePeace						"MakePeace",					"iib"
#define GAMEEVENT_MinorAlliesChanged			"MinorAlliesChanged",			"iibii"
#define GAMEEVENT_MinorFriendsChanged			"MinorFriendsChanged",			"iibii"
#define GAMEEVENT_MinorGift						"MinorGift",					"iiiiibbs"
#define GAMEEVENT_NaturalWonderDiscovered		"NaturalWonderDiscovered",		"iiiibii"
#define GAMEEVENT_PantheonFounded				"PantheonFounded",				"iiii"
#define GAMEEVENT_ParadropAt					"ParadropAt",					"iiiiii"
#define GAMEEVENT_PlaceResource					"PlaceResource",				"iiiii"
#define GAMEEVENT_PlayerBoughtOut				"PlayerBoughtOut",				"ii"
#define GAMEEVENT_PlayerBuilding				"PlayerBuilding",				"iiiiibb"
#define GAMEEVENT_PlayerBuilt					"PlayerBuilt",					"iiiii"
#define GAMEEVENT_PlayerBullied					"PlayerBullied",				"iiiiii"
#define GAMEEVENT_PlayerCanAdoptIdeology		"PlayerCanAdoptIdeology",		"ii"
#define GAMEEVENT_PlayerCanAdoptTenet			"PlayerCanAdoptTenet",			"ii"
#define GAMEEVENT_PlayerCanBuild				"PlayerCanBuild",				"iiiii"
#define GAMEEVENT_PlayerCanBullyGold			"PlayerCanBullyGold",			"ii"
#define GAMEEVENT_PlayerCanBullyUnit			"PlayerCanBullyUnit",			"ii"
#define GAMEEVENT_PlayerCanBuyOut				"PlayerCanBuyOut",				"ii"
#define GAMEEVENT_PlayerCanCreateTradeRoute		"PlayerCanCreateTradeRoute",	"iiiiii"
#define GAMEEVENT_PlayerCanDeclareWar			"PlayerCanDeclareWar",			"ii"
#define GAMEEVENT_PlayerCanFoundCity			"PlayerCanFoundCity",			"iii"
#define GAMEEVENT_PlayerCanFoundCityRegardless	"PlayerCanFoundCityRegardless",	"iii"
#define GAMEEVENT_PlayerCanFoundPantheon		"PlayerCanFoundPantheon",		"i"
#define GAMEEVENT_PlayerCanFoundReligion		"PlayerCanFoundReligion",		"ii"
#define GAMEEVENT_PlayerCanGiftGold				"PlayerCanGiftGold",			"ii"
#define GAMEEVENT_PlayerCanGiftImprovement		"PlayerCanGiftImprovement",		"ii"
#define GAMEEVENT_PlayerCanGiftUnit				"PlayerCanGiftUnit",			"iii"
#define GAMEEVENT_PlayerCanHaveBelief			"PlayerCanHaveBelief",			"ii"
#define GAMEEVENT_PlayerCanLiberate				"PlayerCanLiberate",			"ii"
#define GAMEEVENT_PlayerCanMakePeace			"PlayerCanMakePeace",			"ii"
#define GAMEEVENT_PlayerCanPropose				"PlayerCanPropose",				"iiib"
#define GAMEEVENT_PlayerCanProtect				"PlayerCanProtect",				"ii"
#define GAMEEVENT_PlayerCanRaze					"PlayerCanRaze",				"ii"
#define GAMEEVENT_PlayerCanRemoveHeresy			"PlayerCanRemoveHeresy",		"iiii"
#define GAMEEVENT_PlayerCanRevoke				"PlayerCanRevoke",				"ii"
#define GAMEEVENT_PlayerCanSpreadReligion		"PlayerCanSpreadReligion",		"iiii"
#define GAMEEVENT_PlayerCanTransitMinorCity		"PlayerCanTransitMinorCity",	"iiiii"
#define GAMEEVENT_PlayerDoneTurn				"PlayerDoneTurn",				"i"
#define GAMEEVENT_PlayerTurnStart				"PlayerTurnStart",				"i"
#define GAMEEVENT_PlayerGifted					"PlayerGifted",					"iiiiii"
#define GAMEEVENT_PlayerCompletedQuest			"PlayerCompletedQuest",			"iiiiii"
#define GAMEEVENT_PlayerGoldenAge				"PlayerGoldenAge",				"ibi"
#define GAMEEVENT_PlayerLiberated				"PlayerLiberated",				"iii"
#define GAMEEVENT_PlayerPlunderedTradeRoute		"PlayerPlunderedTradeRoute",	"iiiiiiiii"
#define GAMEEVENT_PlayerProtected				"PlayerProtected",				"ii"
#define GAMEEVENT_PlayerRevoked					"PlayerRevoked",				"iib"
#define GAMEEVENT_PlotCanImprove				"PlotCanImprove",				"iii"
#define GAMEEVENT_QuestContestValue				"QuestContestValue",			"iii"
#define GAMEEVENT_QuestGetData					"QuestGetData",					"iiib"
#define GAMEEVENT_QuestIsAvailable				"QuestIsAvailable",				"iiibii"
#define GAMEEVENT_QuestIsCompleted				"QuestIsCompleted",				"iiib"
#define GAMEEVENT_QuestIsExpired				"QuestIsExpired",				"iii"
#define GAMEEVENT_QuestIsRevoked				"QuestIsRevoked",				"iii"
#define GAMEEVENT_QuestSendNotification			"QuestSendNotification",		"iiiiiiibbs"
#define GAMEEVENT_QuestStart					"QuestStart",					"iiibiii"
#define GAMEEVENT_RebaseTo						"RebaseTo",						"iiii"
#define GAMEEVENT_ReligionCanHaveBelief			"ReligionCanHaveBelief",		"iii"
#define GAMEEVENT_ReligionEnhanced				"ReligionEnhanced",				"iiii"
#define GAMEEVENT_ReligionFounded				"ReligionFounded",				"iiiiiiii"
#define GAMEEVENT_ReligionReformed				"ReligionReformed",				"iiiiiii"
#define GAMEEVENT_ReligionFounderChanged		"ReligionFounderChanged",		"iiiib"
#define GAMEEVENT_ResolutionProposing			"ResolutionProposing",			"ii"
#define GAMEEVENT_ResolutionResult				"ResolutionResult",				"iibb"
#define GAMEEVENT_ResolutionVoting				"ResolutionVoting",				"ii"
#define GAMEEVENT_TeamSetEra					"TeamSetEra",					"iib"
#define GAMEEVENT_PlayerSetEra					"PlayerSetEra",					"iib"
#define GAMEEVENT_PlayerSetHasTech				"PlayerSetHasTech",				"iib"
#define GAMEEVENT_TerraformingMap				"TerraformingMap",				"ii"
#define GAMEEVENT_TerraformingPlot				"TerraformingPlot",				"iiiiiiii"
#define GAMEEVENT_UnitAttackCity				"UnitAttackCity",				"iiiiii"
#define GAMEEVENT_TileFeatureChanged			"TileFeatureChanged",			"iiiii"
#define GAMEEVENT_TileImprovementChanged		"TileImprovementChanged",		"iiiiib"
#define GAMEEVENT_TileOwnershipChanged			"TileOwnershipChanged",			"iiii"
#define GAMEEVENT_TileRevealed					"TileRevealed",					"iiiibii"
#define GAMEEVENT_TileRouteChanged				"TileRouteChanged",				"iiiiib"
#define GAMEEVENT_UiDiploEvent					"UiDiploEvent",					"iiii"
#define GAMEEVENT_UnitCanFollowupFrom			"UnitCanFollowupFrom",			"iiiiiii"
#define GAMEEVENT_UnitCanHaveAnyUpgrade			"UnitCanHaveAnyUpgrade",		"ii"
#define GAMEEVENT_UnitCanHaveGreatWork			"UnitCanHaveGreatWork",			"iii"
#define GAMEEVENT_UnitCanHaveName				"UnitCanHaveName",				"iii"
#define GAMEEVENT_UnitCanHavePromotion			"UnitCanHavePromotion",			"iii"
#define GAMEEVENT_UnitCanHaveUpgrade			"UnitCanHaveUpgrade",			"iiii"
#define GAMEEVENT_UnitCanPillage				"UnitCanPillage",				"iiii"
#define GAMEEVENT_UnitCanRangeAttackAt			"UnitCanRangeAttackAt",			"iiiib"
#define GAMEEVENT_UnitCanTransitMinorCity		"UnitCanTransitMinorCity",		"iiiiii"
#define GAMEEVENT_UnitCaptured					"UnitCaptured",					"iiiibi"
#define GAMEEVENT_UnitCaptureType				"UnitCaptureType",				"iiii"
#define GAMEEVENT_UnitCityFounded				"UnitCityFounded",				"iiiii"
#define GAMEEVENT_UnitCreated					"UnitCreated",					"iiiii"
#define GAMEEVENT_UnitPillageGold				"UnitPillageGold",				"iiii"
#define GAMEEVENT_UnitPrekill					"UnitPrekill",					"iiiiibi"
#define GAMEEVENT_UnitPromoted					"UnitPromoted",					"iii"
#define GAMEEVENT_UnitRangeAttackAt				"UnitRangeAttackAt",			"iiii"
#define GAMEEVENT_UnitUpgraded					"UnitUpgraded",					"iiib"
#define GAMEEVENT_TradeRouteMove                "TradeRouteMove",               "iiiiiiii"


#define GAMEEVENT_NuclearDetonation				"NuclearDetonation",			"iiiibb"
#define GAMEEVENT_GreatWorkCreated              "GreatWorkCreated",             "iii"
#define GAMEEVENT_ScienceDiscover			    "ScienceDiscover",		        "iiiib"
#define GAMEEVENT_CultureDiscover			    "CultureDiscover",		        "iiiib"
#define GAMEEVENT_TourismDiscover			    "TourismDiscover",		        "iiiib"
#define GAMEEVENT_ProductionDiscover			"ProductionDiscover",		    "iiiib"
#define GAMEEVENT_GoldDiscover			        "GoldDiscover",		            "iiiib"
#define GAMEEVENT_GoldenAgeDiscover			    "GoldenAgeDiscover",		    "iiiib"
#define GAMEEVENT_CultureBombDiscover			"CultureBombDiscover",		    "iiiib"
#define GAMEEVENT_FaithDiscover			        "FaithDiscover",		        "iiiib"
#define GAMEEVENT_CityPuppeted					"CityPuppeted",					"ii"
#define GAMEEVENT_DoDenounce					"DoDenounce",					"ii"
#define GAMEEVENT_CityBeginsWLTKD			    "CityBeginsWLTKD",              "iiii"
#define GAMEEVENT_CityEndsWLTKD				    "CityEndsWLTKD",                "iiii"
#define GAMEEVENT_CityRangedStrike				"CityRangedStrike",			    "iiiiii"
#define GAMEEVENT_TileImprovementPillaged		"TileImprovementPillaged",		"iiiib"
#define GAMEEVENT_TileSetOwnership			    "TileSetOwnership",			    "iiii"
#define GAMEEVENT_UnitCanRangeAttackPlot		"UnitCanRangeAttackPlot",		"iiiib"
#define GAMEEVENT_UnitMoveInto					"UnitMoveInto",					"iiiiiii"
#define GAMEEVENT_UnitDoTurn					"UnitDoTurn",					"iiii"

#define GAMEEVENT_OnImprovementUpgrade			"OnImprovementUpgrade",			"iiiiii"
#define GAMEEVENT_OnImprovementDowngrade		"OnImprovementDowngrade",		"iiiiii"
#define GAMEEVENT_GetImprovementXPPerTurn		"GetImprovementXPPerTurn",		"iiiiii"

#define GAMEEVENT_DoWarPopulationLoss			"DoWarPopulationLoss",		    "iii"

#define GAMEEVENT_OnCityScaleChange				"OnCityScaleChange",		    "iiii"

#define GAMEEVENT_OnTriggerSplashFinish			"OnTriggerSplashFinish",		"iiiib"

#define GAMEEVENT_CanAddEnemyPromotion			"CanAddEnemyPromotion",		    "iiiiiii"
#define GAMEEVENT_OnTriggerAddEnemyPromotion	"OnTriggerAddEnemyPromotion",	"iiiiiiiiiii"
#define GAMEEVENT_CanRemovePromotion			"CanRemovePromotion",			"iii"

#define GAMEEVENT_LoyaltyStateChanged       	"LoyaltyStateChanged",			"iiii"

// Serialization wrappers
#define MOD_SERIALIZE

#if defined(MOD_SERIALIZE)
#define MOD_SERIALIZE_INIT_READ(stream) uint uiDllSaveVersion; stream >> uiDllSaveVersion
#define MOD_SERIALIZE_READ(version, stream, member, def) if (uiDllSaveVersion >= version) { stream >> member; } else { member = def; }
#define MOD_SERIALIZE_READ_AUTO(version, stream, member, size, def)   \
	if (uiDllSaveVersion >= version) {                                \
		stream >> member;                                             \
	} else {                                                          \
		for (int iI = 0; iI < size; iI++) { member.setAt(iI, def); }  \
	}
#define MOD_SERIALIZE_READ_ARRAY(version, stream, member, type, size, def)	\
	if (uiDllSaveVersion >= version) {										\
		ArrayWrapper<type> wrapper(size, member); stream >> wrapper;		\
	} else {																\
		for (int iI = 0; iI < size; iI++) { (member)[iI] = def; }			\
	}
#define MOD_SERIALIZE_READ_HASH(version, stream, member, type, size, def)		\
	if (uiDllSaveVersion >= version) {											\
		CvInfosSerializationHelper::ReadHashedDataArray(stream, member, size);	\
	} else {																	\
		for (int iI = 0; iI < size; iI++) { (member)[iI] = def; }				\
	}
#define MOD_SERIALIZE_INIT_WRITE(stream) uint uiDllSaveVersion = MOD_DLL_VERSION_NUMBER; stream << uiDllSaveVersion
#define MOD_SERIALIZE_WRITE(stream, member) CvAssert(uiDllSaveVersion == MOD_DLL_VERSION_NUMBER); stream << member
#define MOD_SERIALIZE_WRITE_AUTO(stream, member) CvAssert(uiDllSaveVersion == MOD_DLL_VERSION_NUMBER); stream << member
#define MOD_SERIALIZE_WRITE_ARRAY(stream, member, type, size) CvAssert(uiDllSaveVersion == MOD_DLL_VERSION_NUMBER); stream << ArrayWrapper<type>(size, member)
#define MOD_SERIALIZE_WRITE_CONSTARRAY(stream, member, type, size) CvAssert(uiDllSaveVersion == MOD_DLL_VERSION_NUMBER); stream << ArrayWrapperConst<type>(size, member)
#define MOD_SERIALIZE_WRITE_HASH(stream, member, type, size, obj) CvAssert(uiDllSaveVersion == MOD_DLL_VERSION_NUMBER); CvInfosSerializationHelper::WriteHashedDataArray<obj, type>(stream, member, size)
#else
#define MOD_SERIALIZE_INIT_READ(stream) __noop
#define MOD_SERIALIZE_READ(version, stream, member, def) __noop
#define MOD_SERIALIZE_READ_AUTO(version, stream, member, size, def) __noop
#define MOD_SERIALIZE_READ_ARRAY(version, stream, member, type, size, def) __noop
#define MOD_SERIALIZE_READ_HASH(version, stream, member, type, size, def) __noop
#define MOD_SERIALIZE_INIT_WRITE(stream) __noop
#define MOD_SERIALIZE_WRITE(stream, member) __noop
#define MOD_SERIALIZE_WRITE_AUTO(stream, member) __noop
#define MOD_SERIALIZE_WRITE_ARRAY(stream, member, type, size) __noop
#define MOD_SERIALIZE_WRITE_ARRAYCONST(stream, member, type, size) __noop
#define MOD_SERIALIZE_WRITE_HASH(stream, member, type, size) __noop
#endif

#define SERIALIZE_READ_UNORDERED_MAP(stream, map) \
{ \
	int iLen = 0; \
	kStream >> iLen; \
	map.clear(); \
	for (int i = 0; i < iLen; i++) \
	{ \
		decltype(map)::key_type key = 0; \
		decltype(map)::mapped_type value = 0; \
		kStream >> key; \
		kStream >> value; \
		map[key] = value; \
	} \
}
#define SERIALIZE_WRITE_UNORDERED_MAP(stream, map) \
{ \
	stream << map.size(); \
	for (auto iter = map.begin(); iter != map.end(); iter++) \
	{ \
		stream << (int) iter->first; \
		stream << (int) iter->second; \
	} \
}

// Custom database table name and columns
#define MOD_DB_TABLE "CustomModOptions"
#define MOD_DB_COL_NAME "Name"
#define MOD_DB_COL_VALUE "Value"
#define MOD_DB_COL_CLASS "Class"
#define MOD_DB_COL_DBUPDATES "DbUpdates"
#define MOD_DB_UPDATES "CustomModDbUpdates"


// CustomMod option wrappers
#define MOD_OPT_DECL(name)  protected: bool m_b##name; public: inline bool is##name() { return m_b##name; }
#define MOD_OPT_CACHE(name) m_b##name = (m_options[string(#name)] == 1);


// Class used to cache the database control settings and provide utility functions
class CustomMods {
public:
	CustomMods();

	int eventHook(const char* szName, const char* p, ...);
	int eventTestAll(const char* szName, const char* p, ...);
	int eventTestAny(const char* szName, const char* p, ...);
	int eventAccumulator(int& iValue, const char* szName, const char* p, ...);

	// CvLuaArgsHandle in the next four methos MUST be passed by reference (&args)
	int eventHook(const char* szName, CvLuaArgsHandle &args);
	int eventTestAll(const char* szName, CvLuaArgsHandle &args);
	int eventTestAny(const char* szName, CvLuaArgsHandle &args);
	int eventAccumulator(int& iValue, const char* szName, CvLuaArgsHandle &args);

	void prefetchCache();
	void preloadCache();
	void reloadCache();
	int getOption(const char* szName, int defValue = 0);
	int getOption(std::string sName, int defValue = 0);
	int getCivOption(const char* szCiv, const char* szName, int defValue = 0);

	MOD_OPT_DECL(GLOBAL_INTERNAL_TRADE_ROUTE_BONUS_FROM_ORIGIN_CITY);
	MOD_OPT_DECL(GLOBAL_EARLY_COOP_WAR_LOCK);
	MOD_OPT_DECL(GLOBAL_STACKING_RULES);
	MOD_OPT_DECL(GLOBAL_BREAK_CIVILIAN_1UPT);
	MOD_OPT_DECL(GLOBAL_BREAK_CIVILIAN_RESTRICTIONS);
	MOD_OPT_DECL(GLOBAL_LOCAL_GENERALS);
	MOD_OPT_DECL(GLOBAL_SEPARATE_GREAT_ADMIRAL);
	MOD_OPT_DECL(GLOBAL_PROMOTION_CLASSES);
	MOD_OPT_DECL(GLOBAL_PASSABLE_FORTS);
	MOD_OPT_DECL(GLOBAL_PASSABLE_FORTS_ANY);
	MOD_OPT_DECL(GLOBAL_ANYTIME_GOODY_GOLD);
	MOD_OPT_DECL(GLOBAL_CITY_FOREST_BONUS);
	MOD_OPT_DECL(GLOBAL_CITY_JUNGLE_BONUS);
	MOD_OPT_DECL(GLOBAL_CITY_WORKING);
	MOD_OPT_DECL(GLOBAL_CITY_AUTOMATON_WORKERS);
	MOD_OPT_DECL(GLOBAL_RELOCATION);
	MOD_OPT_DECL(GLOBAL_ALPINE_PASSES);
	MOD_OPT_DECL(GLOBAL_CS_GIFT_SHIPS);
	MOD_OPT_DECL(GLOBAL_CS_UPGRADES);
	MOD_OPT_DECL(GLOBAL_CS_RAZE_RARELY);
	MOD_OPT_DECL(GLOBAL_CS_LIBERATE_AFTER_BUYOUT);
	MOD_OPT_DECL(GLOBAL_CS_GIFTS);
	MOD_OPT_DECL(GLOBAL_CS_GIFTS_LOCAL_XP);
	MOD_OPT_DECL(GLOBAL_CS_OVERSEAS_TERRITORY);
	MOD_OPT_DECL(GLOBAL_CS_NO_ALLIED_SKIRMISHES);
	MOD_OPT_DECL(GLOBAL_VENICE_KEEPS_RESOURCES);
	MOD_OPT_DECL(GLOBAL_CS_MARRIAGE_KEEPS_RESOURCES);
	MOD_OPT_DECL(GLOBAL_NO_FOLLOWUP);
	MOD_OPT_DECL(GLOBAL_NO_FOLLOWUP_FROM_CITIES);
	MOD_OPT_DECL(GLOBAL_CAPTURE_AFTER_ATTACKING);
	MOD_OPT_DECL(GLOBAL_NO_OCEAN_PLUNDERING);
	MOD_OPT_DECL(GLOBAL_NO_CONQUERED_SPACESHIPS);
	MOD_OPT_DECL(GLOBAL_ADJACENT_BLOCKADES);
	MOD_OPT_DECL(GLOBAL_ALLIES_BLOCK_BLOCKADES);
	MOD_OPT_DECL(GLOBAL_SHORT_EMBARKED_BLOCKADES);
	MOD_OPT_DECL(GLOBAL_GRATEFUL_SETTLERS);
	MOD_OPT_DECL(GLOBAL_RELIGIOUS_SETTLERS);
	MOD_OPT_DECL(GLOBAL_QUICK_ROUTES);
	MOD_OPT_DECL(GLOBAL_SUBS_UNDER_ICE_IMMUNITY);
	MOD_OPT_DECL(GLOBAL_PARATROOPS_MOVEMENT);
	MOD_OPT_DECL(GLOBAL_PARATROOPS_AA_DAMAGE);
	MOD_OPT_DECL(GLOBAL_NUKES_MELT_ICE); 



	MOD_OPT_DECL(GLOBAL_GREATWORK_YIELDTYPES); 
	MOD_OPT_DECL(GLOBAL_NO_LOST_GREATWORKS); 
	MOD_OPT_DECL(GLOBAL_EXCLUDE_FROM_GIFTS);
	MOD_OPT_DECL(GLOBAL_MOVE_AFTER_UPGRADE);
	MOD_OPT_DECL(GLOBAL_CANNOT_EMBARK);
	MOD_OPT_DECL(GLOBAL_SEPARATE_GP_COUNTERS);
	MOD_OPT_DECL(GLOBAL_TRULY_FREE_GP);
	
	MOD_OPT_DECL(DIPLOMACY_BY_NUMBERS);
	MOD_OPT_DECL(DIPLOMACY_TECH_BONUSES);
	MOD_OPT_DECL(DIPLOMACY_AUTO_DENOUNCE);
	MOD_OPT_DECL(DIPLOMACY_STFU);
	MOD_OPT_DECL(DIPLOMACY_NO_LEADERHEADS);

	MOD_OPT_DECL(TRAITS_GG_FROM_BARBARIANS);
	MOD_OPT_DECL(TRAITS_CROSSES_ICE);
	MOD_OPT_DECL(TRAITS_CITY_WORKING);
	MOD_OPT_DECL(TRAITS_CITY_AUTOMATON_WORKERS);
	MOD_OPT_DECL(TRAITS_OTHER_PREREQS);
	MOD_OPT_DECL(TRAITS_ANY_BELIEF);
	MOD_OPT_DECL(TRAITS_TRADE_ROUTE_BONUSES);
	MOD_OPT_DECL(TRAITS_EXTRA_SUPPLY);
	MOD_OPT_DECL(TRAITS_CAN_FOUND_MOUNTAIN_CITY);
	MOD_OPT_DECL(TRAITS_CAN_FOUND_COAST_CITY);

	MOD_OPT_DECL(POLICIES_CITY_WORKING);
	MOD_OPT_DECL(POLICIES_CITY_AUTOMATON_WORKERS);

	MOD_OPT_DECL(TECHS_CITY_WORKING);
	MOD_OPT_DECL(TECHS_CITY_AUTOMATON_WORKERS);

	MOD_OPT_DECL(PROMOTIONS_AURA_CHANGE);
	MOD_OPT_DECL(PROMOTIONS_GG_FROM_BARBARIANS);
	MOD_OPT_DECL(PROMOTIONS_VARIABLE_RECON);
	MOD_OPT_DECL(PROMOTIONS_CROSS_MOUNTAINS);
	MOD_OPT_DECL(PROMOTIONS_CROSS_OCEANS);
	MOD_OPT_DECL(PROMOTIONS_CROSS_ICE);
	MOD_OPT_DECL(PROMOTIONS_HALF_MOVE);
	MOD_OPT_DECL(PROMOTIONS_DEEP_WATER_EMBARKATION);
	MOD_OPT_DECL(PROMOTIONS_FLAGSHIP);
	MOD_OPT_DECL(PROMOTIONS_UNIT_NAMING);
	MOD_OPT_DECL(PROMOTIONS_IMPROVEMENT_BONUS);
	MOD_OPT_DECL(PROMOTIONS_ALLYCITYSTATE_BONUS);
	MOD_OPT_DECL(DEFENSE_MOVES_BONUS);
	MOD_OPT_DECL(PROMOTIONS_EXTRARES_BONUS);

	MOD_OPT_DECL(UI_CITY_PRODUCTION);
	MOD_OPT_DECL(UI_CITY_EXPANSION);

	MOD_OPT_DECL(BUILDINGS_NW_EXCLUDE_RAZING);
	MOD_OPT_DECL(BUILDINGS_PRO_RATA_PURCHASE);
	MOD_OPT_DECL(BUILDINGS_CITY_WORKING);
	MOD_OPT_DECL(BUILDINGS_CITY_AUTOMATON_WORKERS);
	MOD_OPT_DECL(BUILDINGS_YIELD_FROM_OTHER_YIELD);
	MOD_OPT_DECL(BUILDINGS_GOLDEN_AGE_EXTEND);

	MOD_OPT_DECL(TRADE_ROUTE_SCALING);
	MOD_OPT_DECL(TRADE_WONDER_RESOURCE_ROUTES);

	MOD_OPT_DECL(UNITS_NO_SUPPLY);
	MOD_OPT_DECL(UNITS_MAX_HP);
	MOD_OPT_DECL(UNITS_XP_TIMES_100);
	MOD_OPT_DECL(UNITS_LOCAL_WORKERS);
	MOD_OPT_DECL(UNITS_HOVERING_LAND_ONLY_HEAL);
	MOD_OPT_DECL(UNITS_HOVERING_COASTAL_ATTACKS);

	MOD_OPT_DECL(RELIGION_NO_PREFERRENCES);
	MOD_OPT_DECL(RELIGION_RANDOMISE);
	MOD_OPT_DECL(RELIGION_CONVERSION_MODIFIERS);
	MOD_OPT_DECL(RELIGION_KEEP_PROPHET_OVERFLOW);
	MOD_OPT_DECL(RELIGION_ALLIED_INQUISITORS);
	MOD_OPT_DECL(RELIGION_RECURRING_PURCHASE_NOTIFIY);
	MOD_OPT_DECL(RELIGION_PLOT_YIELDS);
	MOD_OPT_DECL(RELIGION_POLICY_BRANCH_FAITH_GP);
	MOD_OPT_DECL(RELIGION_LOCAL_RELIGIONS);

	MOD_OPT_DECL(PROCESS_STOCKPILE);

	MOD_OPT_DECL(AI_NO_ZERO_VALUE_TRADE_ITEMS);
	MOD_OPT_DECL(AI_SECONDARY_WORKERS);
	MOD_OPT_DECL(AI_SECONDARY_SETTLERS);
	MOD_OPT_DECL(AI_GREAT_PEOPLE_CHOICES);
	MOD_OPT_DECL(AI_MP_DIPLOMACY);
	MOD_OPT_DECL(AI_SMART_V3);

	MOD_OPT_DECL(EVENTS_TERRAFORMING);
	MOD_OPT_DECL(EVENTS_TILE_IMPROVEMENTS);
	MOD_OPT_DECL(EVENTS_TILE_REVEALED);
	MOD_OPT_DECL(EVENTS_CIRCUMNAVIGATION);
	MOD_OPT_DECL(EVENTS_NEW_ERA);
	MOD_OPT_DECL(EVENTS_PLAYER_SET_HAS_TECH);
	MOD_OPT_DECL(EVENTS_NW_DISCOVERY);
	MOD_OPT_DECL(EVENTS_DIPLO_EVENTS);
	MOD_OPT_DECL(EVENTS_DIPLO_MODIFIERS);
	MOD_OPT_DECL(EVENTS_MINORS);
	MOD_OPT_DECL(EVENTS_MINORS_GIFTS);
	MOD_OPT_DECL(EVENTS_MINORS_INTERACTION);
	MOD_OPT_DECL(EVENTS_QUESTS);
	MOD_OPT_DECL(EVENTS_BARBARIANS);
	MOD_OPT_DECL(EVENTS_GOODY_CHOICE);
	MOD_OPT_DECL(EVENTS_GOODY_TECH);
	MOD_OPT_DECL(EVENTS_AI_OVERRIDE_TECH);
	MOD_OPT_DECL(EVENTS_GREAT_PEOPLE);
	MOD_OPT_DECL(EVENTS_FOUND_RELIGION);
	MOD_OPT_DECL(EVENTS_ACQUIRE_BELIEFS);
	MOD_OPT_DECL(EVENTS_RELIGION);
	MOD_OPT_DECL(EVENTS_ESPIONAGE);
	MOD_OPT_DECL(EVENTS_PLOT);
	MOD_OPT_DECL(EVENTS_PLAYER_TURN);
	MOD_OPT_DECL(EVENTS_GOLDEN_AGE);
	MOD_OPT_DECL(EVENTS_CITY);
	MOD_OPT_DECL(EVENTS_CITY_CAPITAL);
	MOD_OPT_DECL(EVENTS_CITY_BORDERS);
	MOD_OPT_DECL(EVENTS_LIBERATION);
	MOD_OPT_DECL(EVENTS_CITY_FOUNDING);
	MOD_OPT_DECL(EVENTS_CITY_RAZING);
	MOD_OPT_DECL(EVENTS_CITY_AIRLIFT);
	MOD_OPT_DECL(EVENTS_CITY_BOMBARD);
	MOD_OPT_DECL(ROG_CORE_BOMBARD_RANGE_BUILDINGS);
	MOD_OPT_DECL(EVENTS_CITY_CONNECTIONS);
	MOD_OPT_DECL(EVENTS_AREA_RESOURCES);
	MOD_OPT_DECL(EVENTS_PARADROPS);
	MOD_OPT_DECL(EVENTS_UNIT_RANGEATTACK);
	MOD_OPT_DECL(EVENTS_UNIT_CREATED);
	MOD_OPT_DECL(EVENTS_UNIT_FOUNDED);
	MOD_OPT_DECL(EVENTS_UNIT_PREKILL);
	MOD_OPT_DECL(EVENTS_UNIT_CAPTURE);
	MOD_OPT_DECL(EVENTS_CAN_MOVE_INTO);
	MOD_OPT_DECL(EVENTS_UNIT_ACTIONS);
	MOD_OPT_DECL(EVENTS_UNIT_UPGRADES);
	MOD_OPT_DECL(EVENTS_UNIT_DATA);
	MOD_OPT_DECL(EVENTS_TRADE_ROUTES);
	MOD_OPT_DECL(EVENTS_TRADE_ROUTE_PLUNDERED);
	MOD_OPT_DECL(EVENTS_WAR_AND_PEACE);
	MOD_OPT_DECL(EVENTS_RESOLUTIONS);
	MOD_OPT_DECL(EVENTS_IDEOLOGIES);
	MOD_OPT_DECL(EVENTS_NUCLEAR_DETONATION);
	MOD_OPT_DECL(EVENTS_AIRLIFT);
	MOD_OPT_DECL(EVENTS_REBASE);
	MOD_OPT_DECL(EVENTS_COMMAND);
	MOD_OPT_DECL(EVENTS_CUSTOM_MISSIONS);
	MOD_OPT_DECL(EVENTS_BATTLES);
	MOD_OPT_DECL(EVENTS_BATTLES_DAMAGE);
	MOD_OPT_DECL(EVENTS_BATTLES_CUSTOM_DAMAGE);
	MOD_OPT_DECL(EVENTS_TRADE_ROUTE_MOVE);
	
	MOD_OPT_DECL(API_RELIGION_EXTENSIONS);
	MOD_OPT_DECL(API_PLAYER_LOGS);
	MOD_OPT_DECL(API_ESPIONAGE);
	MOD_OPT_DECL(API_TRADEROUTES);
	MOD_OPT_DECL(API_RELIGION);
	MOD_OPT_DECL(API_PLOT_BASED_DAMAGE);
	MOD_OPT_DECL(API_PLOT_YIELDS);
	MOD_OPT_DECL(API_VP_ADJACENT_YIELD_BOOST);
	MOD_OPT_DECL(API_BUILDING_ENABLE_PURCHASE_UNITS);
	MOD_OPT_DECL(API_ACHIEVEMENTS);
	MOD_OPT_DECL(API_EXTENSIONS);
	MOD_OPT_DECL(API_LUA_EXTENSIONS);
	MOD_OPT_DECL(API_PROMOTION_TO_PROMOTION_MODIFIERS);
	MOD_OPT_DECL(API_UNIT_CANNOT_BE_RANGED_ATTACKED);
	MOD_OPT_DECL(API_MP_PLOT_SIGNAL);
	MOD_OPT_DECL(API_TRADE_ROUTE_YIELD_RATE);

	MOD_OPT_DECL(CONFIG_GAME_IN_XML);
	MOD_OPT_DECL(CONFIG_AI_IN_XML);

	MOD_OPT_DECL(BUGFIX_DUMMY_POLICIES);
	MOD_OPT_DECL(BUGFIX_RADARING);
	MOD_OPT_DECL(BUGFIX_RESEARCH_OVERFLOW);
	MOD_OPT_DECL(BUGFIX_LUA_CHANGE_VISIBILITY_COUNT);
	MOD_OPT_DECL(BUGFIX_RELIGIOUS_SPY_PRESSURE);
	MOD_OPT_DECL(BUGFIX_MOVE_AFTER_PURCHASE);
	MOD_OPT_DECL(BUGFIX_UNITCLASS_NOT_UNIT);
	MOD_OPT_DECL(BUGFIX_BUILDINGCLASS_NOT_BUILDING);
	MOD_OPT_DECL(BUGFIX_FREE_FOOD_BUILDING);
	MOD_OPT_DECL(BUGFIX_NAVAL_FREE_UNITS);
	MOD_OPT_DECL(BUGFIX_NAVAL_NEAREST_WATER);
	MOD_OPT_DECL(BUGFIX_CITY_STACKING);
	MOD_OPT_DECL(BUGFIX_BARB_CAMP_TERRAINS);
	MOD_OPT_DECL(BUGFIX_BARB_CAMP_SPAWNING);
	MOD_OPT_DECL(BUGFIX_BARB_GP_XP);
	MOD_OPT_DECL(BUGFIX_REMOVE_GHOST_ROUTES);
	MOD_OPT_DECL(BUGFIX_UNITS_AWAKE_IN_DANGER);
	MOD_OPT_DECL(BUGFIX_WORKERS_VISIBLE_DANGER);
	MOD_OPT_DECL(BUGFIX_FEATURE_REMOVAL);
	MOD_OPT_DECL(BUGFIX_INTERCEPTOR_STRENGTH);
	MOD_OPT_DECL(BUGFIX_UNIT_POWER_CALC);
	MOD_OPT_DECL(BUGFIX_UNIT_POWER_BONUS_VS_DOMAIN_ONLY);
	MOD_OPT_DECL(BUGFIX_UNIT_POWER_NAVAL_CONSISTENCY);
	MOD_OPT_DECL(BUGFIX_UNIT_PREREQ_PROJECT);
	MOD_OPT_DECL(BUGFIX_NO_HOVERING_REBELS);
	MOD_OPT_DECL(BUGFIX_HOVERING_PATHFINDER);
	MOD_OPT_DECL(BUGFIX_EMBARKING_PATHFINDER);
	MOD_OPT_DECL(BUGFIX_BUILDING_FREEBUILDING);

	MOD_OPT_DECL(BALANCE_CORE);
	MOD_OPT_DECL(VOLCANO_BREAK);
	MOD_OPT_DECL(ERA_EFFECTS_EXTENSIONS);
	MOD_OPT_DECL(TRAIN_ALL_CORE);
	MOD_OPT_DECL(ROG_CORE);
	MOD_OPT_DECL(DISEASE_BREAK);
	MOD_OPT_DECL(IMPROVEMENT_FUNCTION);
	MOD_OPT_DECL(BUILDING_IMPROVEMENT_RESOURCES);
	MOD_OPT_DECL(MORE_NATURAL_WONDER);

	MOD_OPT_DECL(EVENTS_TILE_SET_OWNER);
	MOD_OPT_DECL(EVENTS_IMPROVEMENTS_PILLAGED);
	MOD_OPT_DECL(EVENTS_GREAT_WORK_CREATED);
	MOD_OPT_DECL(EVENTS_GREAT_PEOPLE_BOOST);
	MOD_OPT_DECL(EVENTS_CITY_PUPPETED);
	MOD_OPT_DECL(EVENTS_DO_DENOUNCE);
	MOD_OPT_DECL(EVENTS_WLKD_DAY);
	MOD_OPT_DECL(EVENTS_CITY_RANGE_STRIKE);
	MOD_OPT_DECL(EVENTS_UNIT_CAN_RANGEATTACK);
	MOD_OPT_DECL(EVENTS_UNIT_MOVE);
	MOD_OPT_DECL(EVENTS_UNIT_DO_TURN);
	MOD_OPT_DECL(CIVILIANS_RETREAT_WITH_MILITARY);
	MOD_OPT_DECL(AIR_SWEEP_FOUND_SOMETHING);
	MOD_OPT_DECL(SHOW_ATTACK_INTERFACE_WITHOUT_ENEMY);
	MOD_OPT_DECL(IMPROVEMENTS_UPGRADE);
	MOD_OPT_DECL(IMPROVEMENTS_CREATE_ITEMS);
	MOD_OPT_DECL(IMPROVEMENT_TRADE_ROUTE_BONUSES);

	MOD_OPT_DECL(GLOBAL_UNLIMITED_ONE_TURN_GROWTH);
	MOD_OPT_DECL(GLOBAL_UNLIMITED_ONE_TURN_PRODUCTION);
	MOD_OPT_DECL(GLOBAL_UNLIMITED_ONE_TURN_CULTURE);
	MOD_OPT_DECL(GLOBAL_UNLIMITED_ONE_TURN_TECH);

	MOD_OPT_DECL(GLOBAL_WAR_CASUALTIES);

	MOD_OPT_DECL(GLOBAL_UNIT_EXTRA_ATTACK_DEFENSE_EXPERENCE);
	MOD_OPT_DECL(UNIT_BOUND_IMPROVEMENT);
	MOD_OPT_DECL(PROMOTION_FEATURE_INVISIBLE);
	MOD_OPT_DECL(PROMOTION_NEW_EFFECT_FOR_SP);
	MOD_OPT_DECL(PROMOTION_AURA_PROMOTION);
	MOD_OPT_DECL(POLICY_FREE_PROMOTION_FOR_PROMOTION);
	MOD_OPT_DECL(GLOBAL_TRIGGER_NEW_GOLDEN_AGE_IN_GA);
	MOD_OPT_DECL(POLICY_NEW_EFFECT_FOR_SP);
	MOD_OPT_DECL(GLOBAL_UNIT_MOVES_AFTER_DISEMBARK);
	MOD_OPT_DECL(GLOBAL_INCREASE_SS_PART_PURCHASE_COST);
	MOD_OPT_DECL(GLOBAL_RANGE_ATTACK_KILL_POPULATION_OF_HEAVY);
	MOD_OPT_DECL(GLOBAL_CAPTURE_UNIT_CANNOT_MAX_OUT);
	MOD_OPT_DECL(GLOBAL_BUILDING_INSTANT_YIELD);
	MOD_OPT_DECL(BUILDING_NEW_EFFECT_FOR_SP);
	MOD_OPT_DECL(VOTING_NEW_EFFECT_FOR_SP);
	MOD_OPT_DECL(BELIEF_NEW_EFFECT_FOR_SP);
	MOD_OPT_DECL(TRAIT_NEW_EFFECT_FOR_SP);
	MOD_OPT_DECL(TRAIT_WOOD_AS_ROAD_SP);
	MOD_OPT_DECL(TROOPS_AND_CROPS_FOR_SP);
	MOD_OPT_DECL(INTERNATIONAL_IMMIGRATION_FOR_SP);
	MOD_OPT_DECL(NUCLEAR_WINTER_FOR_SP);

	MOD_OPT_DECL(UNIT_COST_DONOT_INCTEASE_WITH_TURN);
	MOD_OPT_DECL(NO_FASTER_REPAIR_OUTSIDE);
	MOD_OPT_DECL(GLOBAL_MAX_PLOT_BUILD);
	MOD_OPT_DECL(CITY_NO_DECAY);
	MOD_OPT_DECL(CHANGE_RESOURCE_LINK_AFTER_ALTER_PLOT);

	MOD_OPT_DECL(PROMOTION_SPLASH_DAMAGE);
	MOD_OPT_DECL(PROMOTION_COLLATERAL_DAMAGE);
	MOD_OPT_DECL(PROMOTION_ADD_ENEMY_PROMOTIONS);
	MOD_OPT_DECL(PROMOTION_CITY_DESTROYER);

	MOD_OPT_DECL(GLOBAL_PROMOTIONS_REMOVAL);

	MOD_OPT_DECL(TRAIT_RELIGION_FOLLOWER_EFFECTS);

	MOD_OPT_DECL(GLOBAL_CITY_SCALES);
	MOD_OPT_DECL(EVENTS_CITY_SCALES);

	MOD_OPT_DECL(SPECIALIST_RESOURCES);

	MOD_OPT_DECL(POLICIY_PUBLIC_OPTION);

	MOD_OPT_DECL(TRAITS_GOLDEN_AGE_YIELD_MODIFIER);

	MOD_OPT_DECL(BUGFIX_CITY_NEGATIVE_YIELD_MODIFIED);

	MOD_OPT_DECL(BATTLE_CAPTURE_NEW_RULE);

	MOD_OPT_DECL(BUGFIX_INVISIBLE_UNIT_MOVE_ENEMY_CITY);

	MOD_OPT_DECL(RESOURCE_EXTRA_BUFF);

	MOD_OPT_DECL(SP_SMART_AI);
	MOD_OPT_DECL(SP_FASTER_AI);

	MOD_OPT_DECL(TRAITS_SPREAD_RELIGION_AFTER_KILLING);
	MOD_OPT_DECL(TRAITS_COMBAT_BONUS_FROM_CAPTURED_HOLY_CITY);
	MOD_OPT_DECL(TRAITS_SIEGE_BONUS_IF_SAME_RELIGION);
	MOD_OPT_DECL(TRAITS_ENABLE_FAITH_PURCHASE_ALL_COMBAT_UNITS);

	MOD_OPT_DECL(IMPROVEMENTS_YIELD_CHANGE_PER_UNIT);
	MOD_OPT_DECL(IMPROVEMENTS_UNIT_XP_PER_TURN);

	MOD_OPT_DECL(GLOBAL_CORRUPTION);
	MOD_OPT_DECL(GLOBAL_CORRUPTION_POLICY_COST_MIN_ZERO);
	MOD_OPT_DECL(GLOBAL_UNIT_BARBARIAN_CAN_TRAIN);
	MOD_OPT_DECL(GLOBAL_SP_BARBARIAN_ENHANCE);
	MOD_OPT_DECL(GLOBAL_UNIQUE_PROJECT_CAPTURE);
	MOD_OPT_DECL(GLOBAL_HOLY_CITY_FOUNDER_CHANGE);
	MOD_OPT_DECL(GLOBAL_OPTIONAL_UC);

	MOD_OPT_DECL(DISABLE_AI_DO_TURN_DIPLOMACY_TO_HUMAN);

protected:
	bool m_bInit;
	std::map<std::string, int> m_options;
};

extern CustomMods gCustomMods;
#endif
