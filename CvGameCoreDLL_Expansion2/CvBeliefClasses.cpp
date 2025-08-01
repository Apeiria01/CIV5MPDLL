/*	-------------------------------------------------------------------------------------------------------
	© 1991-2012 Take-Two Interactive Software and its subsidiaries.  Developed by Firaxis Games.  
	Sid Meier's Civilization V, Civ, Civilization, 2K Games, Firaxis Games, Take-Two Interactive Software 
	and their respective logos are all trademarks of Take-Two interactive Software, Inc.  
	All other marks and trademarks are the property of their respective owners.  
	All rights reserved. 
	------------------------------------------------------------------------------------------------------- */
#include "CvGameCoreDLLPCH.h"
#include "CvGameCoreDLLUtil.h"
#include "ICvDLLUserInterface.h"
#include "CvGameCoreUtils.h"
#include "CvInfosSerializationHelper.h"
#include "CvBarbarians.h"

#include "LintFree.h"

//======================================================================================================
//					CvBeliefEntry
//======================================================================================================
/// Constructor
CvBeliefEntry::CvBeliefEntry() :
	m_iMinPopulation(0),
	m_iMinFollowers(0),
	m_iMaxDistance(0),
	m_iCityGrowthModifier(0),
	m_iFaithFromKills(0),
	m_iFaithFromDyingUnits(0),
	m_iRiverHappiness(0),
	m_iHappinessPerCity(0),
	m_iHappinessPerXPeacefulForeignFollowers(0),
	m_iPlotCultureCostModifier(0),
	m_iCityRangeStrikeModifier(0),
	m_iCombatModifierEnemyCities(0),
	m_iCombatModifierFriendlyCities(0),
	m_iFriendlyHealChange(0),
	m_iCityStateFriendshipModifier(0),
	m_iLandBarbarianConversionPercent(0),
	m_iWonderProductionModifier(0),
	m_iPlayerHappiness(0),
	m_iPlayerCultureModifier(0),
	m_fHappinessPerFollowingCity(0),
	m_iGoldPerFollowingCity(0),
	m_iGoldPerXFollowers(0),
	m_iGoldWhenCityAdopts(0),
	m_iSciencePerOtherReligionFollower(0),
	m_iSpreadDistanceModifier(0),
	m_iSpreadStrengthModifier(0),
	m_iProphetStrengthModifier(0),
	m_iProphetCostModifier(0),
	m_iMissionaryStrengthModifier(0),
	m_iMissionaryCostModifier(0),
	m_iFriendlyCityStateSpreadModifier(0),
	m_iGreatPersonExpendedFaith(0),
	m_iCityStateMinimumInfluence(0),
	m_iCityStateInfluenceModifier(0),
	m_iOtherReligionPressureErosion(0),
	m_iSpyPressure(0),
	m_iInquisitorPressureRetention(0),
	m_iFaithBuildingTourism(0),
#if defined(MOD_BELIEF_NEW_EFFECT_FOR_SP)
	m_iGoldenAgeModifier(0),
	m_iExtraSpies(0),
	m_bGreatPersonPointsCapital(false),
	m_bGreatPersonPointsPerCity(false),
	m_bGreatPersonPointsHolyCity(false),
	m_bInquisitorProhibitSpreadInAlly(false),
	m_piGreatPersonPoints(NULL),
	m_piTerrainCityFoodConsumption(NULL),
	m_iFreePromotionForProphet(NO_PROMOTION),
	m_iFounderFreePromotion(NO_PROMOTION),
	m_iFollowingCityFreePromotion(NO_PROMOTION),
	m_iLandmarksTourismPercent(0),
	m_iHolyCityUnitExperence(0),
	m_iHolyCityPressureModifier(0),
	m_iSameReligionMinorRecoveryModifier(0),
	m_iInquisitionFervorTimeModifier(0),
	m_iCuttingBonusModifier(0),
	m_iCityExtraMissionarySpreads(0),
	m_bAllowYieldPerBirth(false),
	m_piYieldPerBirth(NULL),
	m_piLakePlotYieldChange(NULL),
	m_piRiverPlotYieldChange(NULL),
#endif

	m_bPantheon(false),
	m_bFounder(false),
	m_bFollower(false),
	m_bEnhancer(false),
	m_bReformer(false),
	m_bRequiresPeace(false),
	m_bConvertsBarbarians(false),
	m_bFaithPurchaseAllGreatPeople(false),

	m_eObsoleteEra(NO_ERA),
	m_eResourceRevealed(NO_RESOURCE),
	m_eSpreadModifierDoublingTech(NO_TECH),

	m_paiCityYieldChange(NULL),
	m_paiHolyCityYieldChange(NULL),
	m_paiYieldChangePerForeignCity(NULL),
	m_paiYieldChangePerXForeignFollowers(NULL),
#if defined(MOD_API_UNIFIED_YIELDS)
	m_piYieldPerFollowingCity(NULL),
	m_piYieldPerXFollowers(NULL),
	m_piHolyCityYieldPerForeignFollowers(NULL),
	m_piHolyCityYieldPerNativeFollowers(NULL),
	m_piCityYieldPerOtherReligion(NULL),
	m_piYieldPerOtherReligionFollower(NULL),
	m_piCuttingInstantYieldModifier(NULL),
	m_piCuttingInstantYield(NULL),
#endif
	m_piResourceQuantityModifiers(NULL),
	m_ppiImprovementYieldChanges(NULL),
	m_ppiImprovementAdjacentCityYieldChanges(NULL),
	m_ppiBuildingClassYieldChanges(NULL),
	m_paiBuildingClassHappiness(NULL),
	m_paiBuildingClassTourism(NULL),
	m_ppaiFeatureYieldChange(NULL),
#if defined(MOD_API_UNIFIED_YIELDS)
	m_ppiCityYieldFromUnimprovedFeature(NULL),
	m_ppiUnimprovedFeatureYieldChanges(NULL),
#endif
	m_ppaiResourceYieldChange(NULL),
	m_ppaiTerrainYieldChange(NULL),
	m_ppaiTerrainYieldChangeAdditive(NULL),
	m_ppaiTerrainCityYieldChanges(NULL),
#if defined(MOD_API_UNIFIED_YIELDS)
	m_ppiTradeRouteYieldChange(NULL),
	m_ppiSpecialistYieldChange(NULL),
	m_ppiGreatPersonExpendedYield(NULL),
	m_piGoldenAgeGreatPersonRateModifier(NULL),
	m_piCapitalYieldChange(NULL),
	m_piCoastalCityYieldChange(NULL),
	m_piGreatWorkYieldChange(NULL),
	m_piYieldFromKills(NULL),
	m_piYieldFromBarbarianKills(NULL),
#endif
#if defined(MOD_RELIGION_PLOT_YIELDS)
	m_ppiPlotYieldChange(NULL),
#endif
	m_piExtraFlavorValue(NULL),
	m_piCivilizationFlavorValue(NULL),

	m_piResourceHappiness(NULL),
	m_piYieldChangeAnySpecialist(NULL),
	m_piYieldChangeTradeRoute(NULL),
	m_piYieldChangeNaturalWonder(NULL),
	m_piYieldChangeWorldWonder(NULL),
	m_piYieldModifierNaturalWonder(NULL),
	m_piMaxYieldModifierPerFollower(NULL),
	m_piYieldModifierPerFollowerTimes100(NULL),
	m_pbFaithPurchaseUnitEraEnabled(NULL),
	m_pbBuildingClassEnabled(NULL)
{
}

/// Destructor
CvBeliefEntry::~CvBeliefEntry()
{
	SAFE_DELETE_ARRAY(m_piExtraFlavorValue);
	SAFE_DELETE_ARRAY(m_piCivilizationFlavorValue);
	CvDatabaseUtility::SafeDelete2DArray(m_ppiImprovementYieldChanges);
	CvDatabaseUtility::SafeDelete2DArray(m_ppiImprovementAdjacentCityYieldChanges);
	CvDatabaseUtility::SafeDelete2DArray(m_ppiBuildingClassYieldChanges);
	CvDatabaseUtility::SafeDelete2DArray(m_ppaiFeatureYieldChange);
#if defined(MOD_API_UNIFIED_YIELDS)
	CvDatabaseUtility::SafeDelete2DArray(m_ppiCityYieldFromUnimprovedFeature);
	CvDatabaseUtility::SafeDelete2DArray(m_ppiUnimprovedFeatureYieldChanges);
#endif
	CvDatabaseUtility::SafeDelete2DArray(m_ppaiResourceYieldChange);
	CvDatabaseUtility::SafeDelete2DArray(m_ppaiTerrainYieldChange);
	CvDatabaseUtility::SafeDelete2DArray(m_ppaiTerrainYieldChangeAdditive);
	CvDatabaseUtility::SafeDelete2DArray(m_ppaiTerrainCityYieldChanges);
#if defined(MOD_API_UNIFIED_YIELDS)
	CvDatabaseUtility::SafeDelete2DArray(m_ppiTradeRouteYieldChange);
	CvDatabaseUtility::SafeDelete2DArray(m_ppiSpecialistYieldChange);
	CvDatabaseUtility::SafeDelete2DArray(m_ppiGreatPersonExpendedYield);
#endif
#if defined(MOD_RELIGION_PLOT_YIELDS)
	if (MOD_RELIGION_PLOT_YIELDS) {
		CvDatabaseUtility::SafeDelete2DArray(m_ppiPlotYieldChange);
	}
#endif
}

/// Accessor:: Minimum population in this city for belief to be active (0 = no such requirement)
int CvBeliefEntry::GetMinPopulation() const
{
	return m_iMinPopulation;
}

/// Accessor:: Minimum followers in this city for belief to be active (0 = no such requirement)
int CvBeliefEntry::GetMinFollowers() const
{
	return m_iMinFollowers;
}

/// Accessor:: Maximum distance from a city of this religion for belief to be active (0 = no such requirement)
int CvBeliefEntry::GetMaxDistance() const
{
	return m_iMaxDistance;
}

/// Accessor:: Modifier to city growth rate
int CvBeliefEntry::GetCityGrowthModifier() const
{
	return m_iCityGrowthModifier;
}

/// Accessor:: Percentage of enemy strength received in Faith for killing him
int CvBeliefEntry::GetFaithFromKills() const
{
	return m_iFaithFromKills;
}

/// Accessor:: Faith received when a friendly unit dies
int CvBeliefEntry::GetFaithFromDyingUnits() const
{
	return m_iFaithFromDyingUnits;
}

/// Accessor:: Happiness from each city settled on a river
int CvBeliefEntry::GetRiverHappiness() const
{
	return m_iRiverHappiness;
}

/// Accessor:: Happiness per every X population in a city
int CvBeliefEntry::GetHappinessPerCity() const
{
	return m_iHappinessPerCity;
}

/// Accessor:: Happiness per every X population in a foreign city
int CvBeliefEntry::GetHappinessPerXPeacefulForeignFollowers() const
{
	return m_iHappinessPerXPeacefulForeignFollowers;
}

/// Accessor:: Boost in speed of acquiring tiles through culture
int CvBeliefEntry::GetPlotCultureCostModifier() const
{
	return m_iPlotCultureCostModifier;
}

/// Accessor:: Boost in city strike strength
int CvBeliefEntry::GetCityRangeStrikeModifier() const
{
	return m_iCityRangeStrikeModifier;
}

/// Accessor:: Boost in combat near enemy cities of this religion
int CvBeliefEntry::GetCombatModifierEnemyCities() const
{
	return m_iCombatModifierEnemyCities;
}

/// Accessor:: Boost in combat near friendly cities of this religion
int CvBeliefEntry::GetCombatModifierFriendlyCities() const
{
	return m_iCombatModifierFriendlyCities;
}

/// Accessor:: Additional healing in friendly territory
int CvBeliefEntry::GetFriendlyHealChange() const
{
	return m_iFriendlyHealChange;
}

/// Accessor:: Boost in city state influence effectiveness
int CvBeliefEntry::GetCityStateFriendshipModifier() const
{
	return m_iCityStateFriendshipModifier;
}

/// Accessor:: Chance of converting a barbarian camp guard
int CvBeliefEntry::GetLandBarbarianConversionPercent() const
{
	return m_iLandBarbarianConversionPercent;
}

/// Accessor:: boost in production speed for wonders prior to obsolete era
int CvBeliefEntry::GetWonderProductionModifier() const
{
	return m_iWonderProductionModifier;
}

/// Accessor:: boost in production speed for wonders prior to obsolete era
int CvBeliefEntry::GetPlayerHappiness() const
{
	return m_iPlayerHappiness;
}

/// Accessor:: boost in production speed for wonders prior to obsolete era
int CvBeliefEntry::GetPlayerCultureModifier() const
{
	return m_iPlayerCultureModifier;
}

/// Accessor:: amount of extra happiness from each city following this religion
float CvBeliefEntry::GetHappinessPerFollowingCity() const
{
	return m_fHappinessPerFollowingCity;
}

/// Accessor:: amount of extra gold from each city following this religion
int CvBeliefEntry::GetGoldPerFollowingCity() const
{
	return m_iGoldPerFollowingCity;
}

/// Accessor:: amount of extra gold from each city following this religion
int CvBeliefEntry::GetGoldPerXFollowers() const
{
	return m_iGoldPerXFollowers;
}

/// Accessor:: amount of extra gold from each city following this religion
int CvBeliefEntry::GetGoldWhenCityAdopts() const
{
	return m_iGoldWhenCityAdopts;
}

/// Accessor:: amount of science for each follower of another religion in city spread to
int CvBeliefEntry::GetSciencePerOtherReligionFollower() const
{
	return m_iSciencePerOtherReligionFollower;
}

/// Accessor:: extra distance in city-to-city religion spread
int CvBeliefEntry::GetSpreadDistanceModifier() const
{
	return m_iSpreadDistanceModifier;
}

/// Accessor:: extra strength in city-to-city religion spread
int CvBeliefEntry::GetSpreadStrengthModifier() const
{
	return m_iSpreadStrengthModifier;
}

/// Accessor:: prophet conversion strength modifier
int CvBeliefEntry::GetProphetStrengthModifier() const
{
	return m_iProphetStrengthModifier;
}

/// Accessor:: prophet cost discount
int CvBeliefEntry::GetProphetCostModifier() const
{
	return m_iProphetCostModifier;
}

/// Accessor:: missionary conversion strength modifier
int CvBeliefEntry::GetMissionaryStrengthModifier() const
{
	return m_iMissionaryStrengthModifier;
}

/// Accessor:: missionary cost discount
int CvBeliefEntry::GetMissionaryCostModifier() const
{
	return m_iMissionaryCostModifier;
}

/// Accessor: speed increase of spread to friendly city states
int CvBeliefEntry::GetFriendlyCityStateSpreadModifier() const
{
	return m_iFriendlyCityStateSpreadModifier;
}

/// Accessor: faith earned for each GP expended
int CvBeliefEntry::GetGreatPersonExpendedFaith() const
{
	return m_iGreatPersonExpendedFaith;
}

/// Accessor: minimum influence with city states of a shared religion
int CvBeliefEntry::GetCityStateMinimumInfluence() const
{
	return m_iCityStateMinimumInfluence;
}

/// Accessor: modifier to influence boosts with city states
int CvBeliefEntry::GetCityStateInfluenceModifier() const
{
	return m_iCityStateInfluenceModifier;
}

/// Accessor: percentage of religious pressure gain that becomes a drop in pressure of other religions
int CvBeliefEntry::GetOtherReligionPressureErosion() const
{
	return m_iOtherReligionPressureErosion;
}

/// Accessor: base religious pressure (before speed multiplier) from having a spy in a city
int CvBeliefEntry::GetSpyPressure() const
{
	return m_iSpyPressure;
}

/// Accessor: percentage of religious pressure retained if one of your cities is hit with an Inquisitor
int CvBeliefEntry::GetInquisitorPressureRetention() const
{
	return m_iInquisitorPressureRetention;
}

/// Accessor: how much tourism can I get from Buildings bought with Faith?
int CvBeliefEntry::GetFaithBuildingTourism() const
{
	return m_iFaithBuildingTourism;
}

/// Accessor: is this a belief a pantheon can adopt
bool CvBeliefEntry::IsPantheonBelief() const
{
	return m_bPantheon;
}

/// Accessor: is this a belief a religion founder can adopt
bool CvBeliefEntry::IsFounderBelief() const
{
	return m_bFounder;
}

/// Accessor: is this a belief a religion follower can adopt
bool CvBeliefEntry::IsFollowerBelief() const
{
	return m_bFollower;
}

/// Accessor: is this a belief that enhances the spread of the religion
bool CvBeliefEntry::IsEnhancerBelief() const
{
	return m_bEnhancer;
}

/// Accessor: is this a belief that is added with the Reformation social policy
bool CvBeliefEntry::IsReformationBelief() const
{
	return m_bReformer;
}

/// Accessor: is this a belief that requires you to be at peace to benefit?
bool CvBeliefEntry::RequiresPeace() const
{
	return m_bRequiresPeace;
}

/// Accessor: is this a belief that allows your missionaries to convert adjacent barbarians?
bool CvBeliefEntry::ConvertsBarbarians() const
{
	return m_bConvertsBarbarians;
}

/// Accessor: is this a belief that allows you to purchase any type of Great Person with Faith?
bool CvBeliefEntry::FaithPurchaseAllGreatPeople() const
{
	return m_bFaithPurchaseAllGreatPeople;
}

/// Accessor: era when wonder production modifier goes obsolete
EraTypes CvBeliefEntry::GetObsoleteEra() const
{
	return m_eObsoleteEra;
}

/// Accessor:: resource revealed near this city
ResourceTypes CvBeliefEntry::GetResourceRevealed() const
{
	return m_eResourceRevealed;
}

/// Accessor:: technology that doubles the effect of the SpreadStrengthModifier
TechTypes CvBeliefEntry::GetSpreadModifierDoublingTech() const
{
	return m_eSpreadModifierDoublingTech;
}

/// Accessor:: Get brief text description
const char* CvBeliefEntry::getShortDescription() const
{
	return m_strShortDescription;
}

/// Accessor:: Set brief text description
void CvBeliefEntry::setShortDescription(const char* szVal)
{
	m_strShortDescription = szVal;
}

/// Accessor:: Additional yield
int CvBeliefEntry::GetCityYieldChange(int i) const
{
	return m_paiCityYieldChange ? m_paiCityYieldChange[i] : -1;
}

/// Accessor:: Additional player-level yield for controlling holy city
int CvBeliefEntry::GetHolyCityYieldChange(int i) const
{
	return m_paiHolyCityYieldChange ? m_paiHolyCityYieldChange[i] : -1;
}

/// Accessor:: Additional player-level yield for each foreign city converted
int CvBeliefEntry::GetYieldChangePerForeignCity(int i) const
{
	return m_paiYieldChangePerForeignCity ? m_paiYieldChangePerForeignCity[i] : -1;
}

/// Accessor:: Additional player-level yield for followers in foreign cities
int CvBeliefEntry::GetYieldChangePerXForeignFollowers(int i) const
{
	return m_paiYieldChangePerXForeignFollowers ? m_paiYieldChangePerXForeignFollowers[i] : -1;
}

#if defined(MOD_API_UNIFIED_YIELDS)
int CvBeliefEntry::GetYieldPerFollowingCity(int i) const
{
	return m_piYieldPerFollowingCity ? m_piYieldPerFollowingCity[i] : 0;
}

int CvBeliefEntry::GetYieldPerXFollowers(int i) const
{
	return m_piYieldPerXFollowers ? m_piYieldPerXFollowers[i] : 0;
}

int CvBeliefEntry::GetHolyCityYieldPerForeignFollowers(int i) const
{
	return m_piHolyCityYieldPerForeignFollowers ? m_piHolyCityYieldPerForeignFollowers[i] : 0;
}
int CvBeliefEntry::GetHolyCityYieldPerNativeFollowers(int i) const
{
	CvAssertMsg(i < NUM_YIELD_TYPES, "Index out of bounds");
	CvAssertMsg(i > -1, "Index out of bounds");
	return m_piHolyCityYieldPerNativeFollowers ? m_piHolyCityYieldPerNativeFollowers[i] : 0;
}

int CvBeliefEntry::GetCityYieldPerOtherReligion(int i) const
{
	return m_piCityYieldPerOtherReligion ? m_piCityYieldPerOtherReligion[i] : 0;
}

int CvBeliefEntry::GetYieldPerOtherReligionFollower(int i) const
{
	return m_piYieldPerOtherReligionFollower ? m_piYieldPerOtherReligionFollower[i] : 0;
}

int CvBeliefEntry::GetCuttingInstantYieldModifier(int i) const
{
	return m_piCuttingInstantYieldModifier ? m_piCuttingInstantYieldModifier[i] : 0;
}

int CvBeliefEntry::GetCuttingInstantYield(int i) const
{
	return m_piCuttingInstantYield ? m_piCuttingInstantYield[i] : 0;
}
#endif

/// Accessor:: Additional quantity of a specific resource
int CvBeliefEntry::GetResourceQuantityModifier(int i) const
{
	CvAssertMsg(i < GC.getNumResourceInfos(), "Index out of bounds");
	CvAssertMsg(i > -1, "Index out of bounds");
	return m_piResourceQuantityModifiers ? m_piResourceQuantityModifiers[i] : -1;
}

/// Accessor:: Extra yield from an improvement
int CvBeliefEntry::GetImprovementYieldChange(ImprovementTypes eIndex1, YieldTypes eIndex2) const
{
	CvAssertMsg(eIndex1 < GC.getNumImprovementInfos(), "Index out of bounds");
	CvAssertMsg(eIndex1 > -1, "Index out of bounds");
	CvAssertMsg(eIndex2 < NUM_YIELD_TYPES, "Index out of bounds");
	CvAssertMsg(eIndex2 > -1, "Index out of bounds");
	return m_ppiImprovementYieldChanges ? m_ppiImprovementYieldChanges[eIndex1][eIndex2] : 0;
}

int CvBeliefEntry::GetImprovementAdjacentCityYieldChange(ImprovementTypes eIndex1, YieldTypes eIndex2) const
{
	CvAssertMsg(eIndex1 < GC.getNumImprovementInfos(), "Index out of bounds");
	CvAssertMsg(eIndex1 > -1, "Index out of bounds");
	CvAssertMsg(eIndex2 < NUM_YIELD_TYPES, "Index out of bounds");
	CvAssertMsg(eIndex2 > -1, "Index out of bounds");
	return m_ppiImprovementAdjacentCityYieldChanges ? m_ppiImprovementAdjacentCityYieldChanges[eIndex1][eIndex2] : 0;
}

/// Yield change for a specific BuildingClass by yield type
int CvBeliefEntry::GetBuildingClassYieldChange(int i, int j) const
{
	CvAssertMsg(i < GC.getNumBuildingClassInfos(), "Index out of bounds");
	CvAssertMsg(i > -1, "Index out of bounds");
	CvAssertMsg(j < NUM_YIELD_TYPES, "Index out of bounds");
	CvAssertMsg(j > -1, "Index out of bounds");
	return m_ppiBuildingClassYieldChanges[i][j];
}

/// Amount of extra Happiness per turn a BuildingClass provides
int CvBeliefEntry::GetBuildingClassHappiness(int i) const
{
	CvAssertMsg(i < GC.getNumBuildingClassInfos(), "Index out of bounds");
	CvAssertMsg(i > -1, "Index out of bounds");
	return m_paiBuildingClassHappiness ? m_paiBuildingClassHappiness[i] : -1;
}

/// Amount of extra Tourism per turn a BuildingClass provides
int CvBeliefEntry::GetBuildingClassTourism(int i) const
{
	CvAssertMsg(i < GC.getNumBuildingClassInfos(), "Index out of bounds");
	CvAssertMsg(i > -1, "Index out of bounds");
	return m_paiBuildingClassTourism ? m_paiBuildingClassTourism[i] : -1;
}

/// Change to Feature yield by type
int CvBeliefEntry::GetFeatureYieldChange(int i, int j) const
{
	CvAssertMsg(i < GC.getNumFeatureInfos(), "Index out of bounds");
	CvAssertMsg(i > -1, "Index out of bounds");
	CvAssertMsg(j < NUM_YIELD_TYPES, "Index out of bounds");
	CvAssertMsg(j > -1, "Index out of bounds");
	return m_ppaiFeatureYieldChange ? m_ppaiFeatureYieldChange[i][j] : -1;
}

#if defined(MOD_API_UNIFIED_YIELDS)
int CvBeliefEntry::GetCityYieldFromUnimprovedFeature(int i, int j) const
{
	CvAssertMsg(i < GC.getNumFeatureInfos(), "Index out of bounds");
	CvAssertMsg(i > -1, "Index out of bounds");
	CvAssertMsg(j < NUM_YIELD_TYPES, "Index out of bounds");
	CvAssertMsg(j > -1, "Index out of bounds");
	return m_ppiCityYieldFromUnimprovedFeature ? m_ppiCityYieldFromUnimprovedFeature[i][j] : 0;
}

int CvBeliefEntry::GetUnimprovedFeatureYieldChange(int i, int j) const
{
	CvAssertMsg(i < GC.getNumFeatureInfos(), "Index out of bounds");
	CvAssertMsg(i > -1, "Index out of bounds");
	CvAssertMsg(j < NUM_YIELD_TYPES, "Index out of bounds");
	CvAssertMsg(j > -1, "Index out of bounds");
	return m_ppiUnimprovedFeatureYieldChanges ? m_ppiUnimprovedFeatureYieldChanges[i][j] : 0;
}
#endif

/// Change to Resource yield by type
int CvBeliefEntry::GetResourceYieldChange(int i, int j) const
{
	CvAssertMsg(i < GC.getNumResourceInfos(), "Index out of bounds");
	CvAssertMsg(i > -1, "Index out of bounds");
	CvAssertMsg(j < NUM_YIELD_TYPES, "Index out of bounds");
	CvAssertMsg(j > -1, "Index out of bounds");
	return m_ppaiResourceYieldChange ? m_ppaiResourceYieldChange[i][j] : -1;
}

/// Change to yield by terrain
int CvBeliefEntry::GetTerrainYieldChange(int i, int j) const
{
	CvAssertMsg(i < GC.getNumTerrainInfos(), "Index out of bounds");
	CvAssertMsg(i > -1, "Index out of bounds");
	CvAssertMsg(j < NUM_YIELD_TYPES, "Index out of bounds");
	CvAssertMsg(j > -1, "Index out of bounds");
	return m_ppaiTerrainYieldChange ? m_ppaiTerrainYieldChange[i][j] : -1;
}

/// Change to yield by terrain
int CvBeliefEntry::GetTerrainYieldChangeAdditive(int i, int j) const
{
	CvAssertMsg(i < GC.getNumTerrainInfos(), "Index out of bounds");
	CvAssertMsg(i > -1, "Index out of bounds");
	CvAssertMsg(j < NUM_YIELD_TYPES, "Index out of bounds");
	CvAssertMsg(j > -1, "Index out of bounds");
	return m_ppaiTerrainYieldChangeAdditive ? m_ppaiTerrainYieldChangeAdditive[i][j] : -1;
}

/// Change to city yield by terrain
int CvBeliefEntry::GetTerrainCityYieldChanges(int i, int j) const
{
	CvAssertMsg(i < GC.getNumTerrainInfos(), "Index out of bounds");
	CvAssertMsg(i > -1, "Index out of bounds");
	CvAssertMsg(j < NUM_YIELD_TYPES, "Index out of bounds");
	CvAssertMsg(j > -1, "Index out of bounds");
	return m_ppaiTerrainCityYieldChanges ? m_ppaiTerrainCityYieldChanges[i][j] : -1;
}

#if defined(MOD_API_UNIFIED_YIELDS)
int CvBeliefEntry::GetTradeRouteYieldChange(int i, int j) const
{
	CvAssertMsg(i < GC.getNumDomainInfos(), "Index out of bounds");
	CvAssertMsg(i > -1, "Index out of bounds");
	CvAssertMsg(j < NUM_YIELD_TYPES, "Index out of bounds");
	CvAssertMsg(j > -1, "Index out of bounds");
	return m_ppiTradeRouteYieldChange ? m_ppiTradeRouteYieldChange[i][j] : 0;
}

int CvBeliefEntry::GetSpecialistYieldChange(int i, int j) const
{
	CvAssertMsg(i < GC.getNumSpecialistInfos(), "Index out of bounds");
	CvAssertMsg(i > -1, "Index out of bounds");
	CvAssertMsg(j < NUM_YIELD_TYPES, "Index out of bounds");
	CvAssertMsg(j > -1, "Index out of bounds");
	return m_ppiSpecialistYieldChange ? m_ppiSpecialistYieldChange[i][j] : 0;
}

int CvBeliefEntry::GetGreatPersonExpendedYield(int i, int j) const
{
	CvAssertMsg(i < GC.getNumGreatPersonInfos(), "Index out of bounds");
	CvAssertMsg(i > -1, "Index out of bounds");
	CvAssertMsg(j < NUM_YIELD_TYPES, "Index out of bounds");
	CvAssertMsg(j > -1, "Index out of bounds");
	return m_ppiGreatPersonExpendedYield ? m_ppiGreatPersonExpendedYield[i][j] : 0;
}

int CvBeliefEntry::GetGoldenAgeGreatPersonRateModifier(int i) const
{
	CvAssertMsg(i < GC.getNumGreatPersonInfos(), "Index out of bounds");
	CvAssertMsg(i > -1, "Index out of bounds");
	return m_piGoldenAgeGreatPersonRateModifier ? m_piGoldenAgeGreatPersonRateModifier[i] : 0;
}

int CvBeliefEntry::GetCapitalYieldChange(int i) const
{
	return m_piCapitalYieldChange ? m_piCapitalYieldChange[i] : 0;
}

int CvBeliefEntry::GetCoastalCityYieldChange(int i) const
{
	return m_piCoastalCityYieldChange ? m_piCoastalCityYieldChange[i] : 0;
}

int CvBeliefEntry::GetGreatWorkYieldChange(int i) const
{
	return m_piGreatWorkYieldChange ? m_piGreatWorkYieldChange[i] : 0;
}

/// Do we get one of our yields from defeating an enemy?
int CvBeliefEntry::GetYieldFromKills(YieldTypes eYield) const
{
	CvAssertMsg((int)eYield < NUM_YIELD_TYPES, "Yield type out of bounds");
	CvAssertMsg((int)eYield > -1, "Index out of bounds");
	return m_piYieldFromKills[(int)eYield];
}

/// Do we get one of our yields from defeating a barbarian?
int CvBeliefEntry::GetYieldFromBarbarianKills(YieldTypes eYield) const
{
	CvAssertMsg((int)eYield < NUM_YIELD_TYPES, "Yield type out of bounds");
	CvAssertMsg((int)eYield > -1, "Index out of bounds");
	return m_piYieldFromBarbarianKills[(int)eYield];
}
#endif

#if defined(MOD_RELIGION_PLOT_YIELDS)
/// Change to yield by plot
int CvBeliefEntry::GetPlotYieldChange(int i, int j) const
{
	if (MOD_API_PLOT_YIELDS) {
		CvAssertMsg(i < GC.getNumPlotInfos(), "Index out of bounds");
		CvAssertMsg(i > -1, "Index out of bounds");
		CvAssertMsg(j < NUM_YIELD_TYPES, "Index out of bounds");
		CvAssertMsg(j > -1, "Index out of bounds");
		return m_ppiPlotYieldChange ? m_ppiPlotYieldChange[i][j] : -1;
	} else {
		return 0;
	}
}
#endif
#if defined(MOD_BELIEF_NEW_EFFECT_FOR_SP)
int CvBeliefEntry::GetGoldenAgeModifier() const
{
	return m_iGoldenAgeModifier;
}
int CvBeliefEntry::GetExtraSpies() const
{
	return m_iExtraSpies;
}
//Great Person Points
bool CvBeliefEntry::IsGreatPersonPointsCapital() const
{
	return m_bGreatPersonPointsCapital;
}
bool CvBeliefEntry::IsGreatPersonPointsPerCity() const
{
	return m_bGreatPersonPointsPerCity;
}
bool CvBeliefEntry::IsGreatPersonPointsHolyCity() const
{
	return m_bGreatPersonPointsHolyCity;
}
int CvBeliefEntry::GetGreatPersonPoints(int i, bool bCapital, bool bHolyCity) const
{
	CvAssertMsg(i < GC.getNumGreatPersonInfos(), "Index out of bounds");
	CvAssertMsg(i > -1, "Index out of bounds");
	if(!m_piGreatPersonPoints) return 0;
	int resValue = 0;
	resValue += (m_bGreatPersonPointsPerCity ? m_piGreatPersonPoints[i] : 0);
	resValue += (bCapital && m_bGreatPersonPointsCapital ? m_piGreatPersonPoints[i] : 0);
	resValue += (bHolyCity && m_bGreatPersonPointsHolyCity ? m_piGreatPersonPoints[i] : 0);

	return resValue;
}
bool CvBeliefEntry::IsInquisitorProhibitSpreadInAlly() const
{
	return m_bInquisitorProhibitSpreadInAlly;
}
int CvBeliefEntry::GetTerrainCityFoodConsumption(int i) const
{
	CvAssertMsg(i < GC.getNumTerrainInfos(), "Index out of bounds");
	CvAssertMsg(i > -1, "Index out of bounds");
	return m_piTerrainCityFoodConsumption ? m_piTerrainCityFoodConsumption[i] : -1;
}
//Extra Free Promotion For Prophet
int CvBeliefEntry::GetFreePromotionForProphet() const
{
	return m_iFreePromotionForProphet;
}
//Extra Free Promotion For Founder
int CvBeliefEntry::GetFounderFreePromotion() const
{
	return m_iFounderFreePromotion;
}
//Extra Free Promotion For Following City
int CvBeliefEntry::GetFollowingCityFreePromotion() const
{
	return m_iFollowingCityFreePromotion;
}
//Extra Landmarks Tourism Percent
int CvBeliefEntry::GetLandmarksTourismPercent() const
{
	return m_iLandmarksTourismPercent;
}
//Extra Experence for Holy City Unit
int CvBeliefEntry::GetHolyCityUnitExperence() const
{
	return m_iHolyCityUnitExperence;
}
//Extra HolyCity Religious Pressure
int CvBeliefEntry::GetHolyCityPressureModifier() const
{
	return m_iHolyCityPressureModifier;
}
//Extra MinorCiv Friendship Recovery from SameReligion
int CvBeliefEntry::GetSameReligionMinorRecoveryModifier() const
{
	return m_iSameReligionMinorRecoveryModifier;
}
int CvBeliefEntry::GetInquisitionFervorTimeModifier() const
{
	return m_iInquisitionFervorTimeModifier;
}
//Extra Production Bonus When Remove Forest/Jungle
int CvBeliefEntry::GetCuttingBonusModifier() const
{
	return m_iCuttingBonusModifier;
}
//Extra Missionary Spreads
int CvBeliefEntry::GetCityExtraMissionarySpreads() const
{
	return m_iCityExtraMissionarySpreads;
}
//Instant Yield when birth
bool CvBeliefEntry::AllowYieldPerBirth() const
{
	return m_bAllowYieldPerBirth;
}
int CvBeliefEntry::GetYieldPerBirth(int i) const
{
	CvAssertMsg(i < NUM_YIELD_TYPES, "Index out of bounds");
	CvAssertMsg(i > -1, "Index out of bounds");
	return m_piYieldPerBirth ? m_piYieldPerBirth[i] : -1;
}
//Lake Yield
int CvBeliefEntry::GetLakePlotYieldChange(int i) const
{
	CvAssertMsg(i < NUM_YIELD_TYPES, "Index out of bounds");
	CvAssertMsg(i > -1, "Index out of bounds");
	return m_piLakePlotYieldChange ? m_piLakePlotYieldChange[i] : -1;
}

//River Yield
int CvBeliefEntry::GetRiverPlotYieldChange(int i) const
{
	CvAssertMsg(i < NUM_YIELD_TYPES, "Index out of bounds");
	CvAssertMsg(i > -1, "Index out of bounds");
	return m_piRiverPlotYieldChange ? m_piRiverPlotYieldChange[i] : -1;
}
#endif

/// Happiness from a resource
int CvBeliefEntry::GetResourceHappiness(int i) const
{
	CvAssertMsg(i < GC.getNumResourceInfos(), "Index out of bounds");
	CvAssertMsg(i > -1, "Index out of bounds");
	return m_piResourceHappiness ? m_piResourceHappiness[i] : -1;
}

/// Yield boost from having a specialist of any type in city
int CvBeliefEntry::GetYieldChangeAnySpecialist(int i) const
{
	CvAssertMsg(i < NUM_YIELD_TYPES, "Index out of bounds");
	CvAssertMsg(i > -1, "Index out of bounds");
	return m_piYieldChangeAnySpecialist ? m_piYieldChangeAnySpecialist[i] : -1;
}

/// Yield boost from a trade route
int CvBeliefEntry::GetYieldChangeTradeRoute(int i) const
{
	CvAssertMsg(i < NUM_YIELD_TYPES, "Index out of bounds");
	CvAssertMsg(i > -1, "Index out of bounds");
	return m_piYieldChangeTradeRoute ? m_piYieldChangeTradeRoute[i] : -1;
}

/// Yield boost from a natural wonder
int CvBeliefEntry::GetYieldChangeNaturalWonder(int i) const
{
	CvAssertMsg(i < NUM_YIELD_TYPES, "Index out of bounds");
	CvAssertMsg(i > -1, "Index out of bounds");
	return m_piYieldChangeNaturalWonder ? m_piYieldChangeNaturalWonder[i] : -1;
}

/// Yield boost from a world wonder
int CvBeliefEntry::GetYieldChangeWorldWonder(int i) const
{
	CvAssertMsg(i < NUM_YIELD_TYPES, "Index out of bounds");
	CvAssertMsg(i > -1, "Index out of bounds");
	return m_piYieldChangeWorldWonder ? m_piYieldChangeWorldWonder[i] : -1;
}

/// Yield percentage boost from a natural wonder
int CvBeliefEntry::GetYieldModifierNaturalWonder(int i) const
{
	CvAssertMsg(i < NUM_YIELD_TYPES, "Index out of bounds");
	CvAssertMsg(i > -1, "Index out of bounds");
	return m_piYieldModifierNaturalWonder ? m_piYieldModifierNaturalWonder[i] : -1;
}

/// Do we get a yield modifier 
int CvBeliefEntry::GetMaxYieldModifierPerFollower(int i) const
{
	CvAssertMsg(i < NUM_YIELD_TYPES, "Index out of bounds");
	CvAssertMsg(i > -1, "Index out of bounds");
	return m_piMaxYieldModifierPerFollower ? m_piMaxYieldModifierPerFollower[i] : -1;
}
int CvBeliefEntry::GetYieldModifierPerFollowerTimes100(int i) const
{
	CvAssertMsg(i < NUM_YIELD_TYPES, "Index out of bounds");
	CvAssertMsg(i > -1, "Index out of bounds");
	return m_piYieldModifierPerFollowerTimes100 ? m_piYieldModifierPerFollowerTimes100[i] : -1;
}

/// Find value of extra flavors associated with this belief
int CvBeliefEntry::GetExtraFlavorValue(int i) const
{
	CvAssertMsg(i < GC.getNumFlavorTypes(), "Index out of bounds");
	CvAssertMsg(i > -1, "Index out of bounds");
	return m_piExtraFlavorValue ? m_piExtraFlavorValue[i] : 0;
}

int CvBeliefEntry::GetCivilizationFlavorValue(int i) const
{
	CvAssertMsg(i < GC.getNumCivilizationInfos(), "Index out of bounds");
	CvAssertMsg(i > -1, "Index out of bounds");
	return m_piCivilizationFlavorValue ? m_piCivilizationFlavorValue[i] : 0;
}

/// Can we buy units of this era with faith?
bool CvBeliefEntry::IsFaithUnitPurchaseEra(int i) const
{
	CvAssertMsg(i > -1, "Index out of bounds");
	CvAssertMsg(i < GC.getNumEraInfos(), "Index out of bounds");
	return m_pbFaithPurchaseUnitEraEnabled ? m_pbFaithPurchaseUnitEraEnabled[i] : false;
}

/// Can we buy units of this era with faith?
bool CvBeliefEntry::IsBuildingClassEnabled(int i) const
{
	CvAssertMsg(i > -1, "Index out of bounds");
	CvAssertMsg(i < GC.getNumBuildingClassInfos(), "Index out of bounds");
	return m_pbBuildingClassEnabled ? m_pbBuildingClassEnabled[i] : false;
}

/// Load XML data
bool CvBeliefEntry::CacheResults(Database::Results& kResults, CvDatabaseUtility& kUtility)
{
	if(!CvBaseInfo::CacheResults(kResults, kUtility))
		return false;

	//Basic Properties
	setShortDescription(kResults.GetText("ShortDescription"));

	m_iMinPopulation                  = kResults.GetInt("MinPopulation");
	m_iMinFollowers                   = kResults.GetInt("MinFollowers");
	m_iMaxDistance					  = kResults.GetInt("MaxDistance");
	m_iCityGrowthModifier		      = kResults.GetInt("CityGrowthModifier");
	m_iFaithFromKills				  = kResults.GetInt("FaithFromKills");
	m_iFaithFromDyingUnits			  = kResults.GetInt("FaithFromDyingUnits");
	m_iRiverHappiness				  = kResults.GetInt("RiverHappiness");
	m_iHappinessPerCity				  = kResults.GetInt("HappinessPerCity");
	m_iHappinessPerXPeacefulForeignFollowers  = kResults.GetInt("HappinessPerXPeacefulForeignFollowers");
	m_iPlotCultureCostModifier	      = kResults.GetInt("PlotCultureCostModifier");
	m_iCityRangeStrikeModifier	      = kResults.GetInt("CityRangeStrikeModifier");
	m_iCombatModifierEnemyCities      = kResults.GetInt("CombatModifierEnemyCities");
	m_iCombatModifierFriendlyCities   = kResults.GetInt("CombatModifierFriendlyCities");
	m_iFriendlyHealChange	          = kResults.GetInt("FriendlyHealChange");
	m_iCityStateFriendshipModifier    = kResults.GetInt("CityStateFriendshipModifier");
	m_iLandBarbarianConversionPercent = kResults.GetInt("LandBarbarianConversionPercent");
	m_iWonderProductionModifier       = kResults.GetInt("WonderProductionModifier");
	m_iPlayerHappiness			      = kResults.GetInt("PlayerHappiness");
	m_iPlayerCultureModifier          = kResults.GetInt("PlayerCultureModifier");
	m_fHappinessPerFollowingCity      = kResults.GetFloat("HappinessPerFollowingCity");
	m_iGoldPerFollowingCity           = kResults.GetInt("GoldPerFollowingCity");
	m_iGoldPerXFollowers              = kResults.GetInt("GoldPerXFollowers");
	m_iGoldWhenCityAdopts             = kResults.GetInt("GoldPerFirstCityConversion");
	m_iSciencePerOtherReligionFollower= kResults.GetInt("SciencePerOtherReligionFollower");
	m_iSpreadDistanceModifier         = kResults.GetInt("SpreadDistanceModifier");
	m_iSpreadStrengthModifier		  = kResults.GetInt("SpreadStrengthModifier");
	m_iProphetStrengthModifier        = kResults.GetInt("ProphetStrengthModifier");
	m_iProphetCostModifier            = kResults.GetInt("ProphetCostModifier");
	m_iMissionaryStrengthModifier     = kResults.GetInt("MissionaryStrengthModifier");
	m_iMissionaryCostModifier         = kResults.GetInt("MissionaryCostModifier");
	m_iFriendlyCityStateSpreadModifier= kResults.GetInt("FriendlyCityStateSpreadModifier");
	m_iGreatPersonExpendedFaith       = kResults.GetInt("GreatPersonExpendedFaith");
	m_iCityStateMinimumInfluence      = kResults.GetInt("CityStateMinimumInfluence");
	m_iCityStateInfluenceModifier     = kResults.GetInt("CityStateInfluenceModifier");
	m_iOtherReligionPressureErosion   = kResults.GetInt("OtherReligionPressureErosion");
	m_iSpyPressure					  = kResults.GetInt("SpyPressure");
	m_iInquisitorPressureRetention    = kResults.GetInt("InquisitorPressureRetention");
	m_iFaithBuildingTourism           = kResults.GetInt("FaithBuildingTourism");
#if defined(MOD_BELIEF_NEW_EFFECT_FOR_SP)
	m_iGoldenAgeModifier	  		  = kResults.GetInt("GoldenAgeModifier");
	m_iExtraSpies	  	  			  = kResults.GetInt("ExtraSpies");
	m_iLandmarksTourismPercent	  	  = kResults.GetInt("LandmarksTourismPercent");
	m_iHolyCityUnitExperence	  	  = kResults.GetInt("HolyCityUnitExperence");
	m_iCityExtraMissionarySpreads	  = kResults.GetInt("CityExtraMissionarySpreads");
	m_iHolyCityPressureModifier	  	  = kResults.GetInt("HolyCityPressureModifier");
	m_iSameReligionMinorRecoveryModifier = kResults.GetInt("SameReligionMinorRecoveryModifier");
	m_iInquisitionFervorTimeModifier = kResults.GetInt("InquisitionFervorTimeModifier");
	m_iCuttingBonusModifier = kResults.GetInt("CuttingBonusModifier");
#endif

	m_bPantheon						  = kResults.GetBool("Pantheon");
	m_bFounder						  = kResults.GetBool("Founder");
	m_bFollower						  = kResults.GetBool("Follower");
	m_bEnhancer						  = kResults.GetBool("Enhancer");
	m_bReformer						  = kResults.GetBool("Reformation");
	m_bRequiresPeace				  = kResults.GetBool("RequiresPeace");
	m_bConvertsBarbarians			  = kResults.GetBool("ConvertsBarbarians");
	m_bFaithPurchaseAllGreatPeople	  = kResults.GetBool("FaithPurchaseAllGreatPeople");
#if defined(MOD_BELIEF_NEW_EFFECT_FOR_SP)
	m_bGreatPersonPointsCapital	  	  = kResults.GetBool("GreatPersonPointsCapital");
	m_bGreatPersonPointsPerCity	  	  = kResults.GetBool("GreatPersonPointsPerCity");
	m_bGreatPersonPointsHolyCity	  = kResults.GetBool("GreatPersonPointsHolyCity");
	m_bAllowYieldPerBirth	  		  = kResults.GetBool("AllowYieldPerBirth");
	m_bInquisitorProhibitSpreadInAlly = kResults.GetBool("InquisitorProhibitSpreadInAlly");
#endif
	//References
	const char* szTextVal;
	szTextVal						  = kResults.GetText("ObsoleteEra");
	m_eObsoleteEra					  = (EraTypes)GC.getInfoTypeForString(szTextVal, true);
	szTextVal						  = kResults.GetText("ResourceRevealed");
	m_eResourceRevealed				  = (ResourceTypes)GC.getInfoTypeForString(szTextVal, true);
	szTextVal						  = kResults.GetText("SpreadModifierDoublingTech");
	m_eSpreadModifierDoublingTech     = (TechTypes)GC.getInfoTypeForString(szTextVal, true);
#if defined(MOD_BELIEF_NEW_EFFECT_FOR_SP)
	szTextVal						  = kResults.GetText("FreePromotionForProphet");
	m_iFreePromotionForProphet 		  = GC.getInfoTypeForString(szTextVal, true);
	szTextVal						  = kResults.GetText("FounderFreePromotion");
	m_iFounderFreePromotion 		  = GC.getInfoTypeForString(szTextVal, true);
	szTextVal						  = kResults.GetText("FollowingCityFreePromotion");
	m_iFollowingCityFreePromotion	  = GC.getInfoTypeForString(szTextVal, true);
#endif

	//Arrays
	const char* szBeliefType = GetType();
#if defined(MOD_BELIEF_NEW_EFFECT_FOR_SP)
	kUtility.SetYields(m_piYieldPerBirth, "Belief_YieldPerBirth", "BeliefType", szBeliefType);
	kUtility.SetYields(m_piLakePlotYieldChange, "Belief_LakePlotYieldChanges", "BeliefType", szBeliefType);
	kUtility.SetYields(m_piRiverPlotYieldChange, "Belief_RiverPlotYieldChanges", "BeliefType", szBeliefType);
#endif
	kUtility.SetYields(m_paiCityYieldChange, "Belief_CityYieldChanges", "BeliefType", szBeliefType);
	kUtility.SetYields(m_paiHolyCityYieldChange, "Belief_HolyCityYieldChanges", "BeliefType", szBeliefType);
	kUtility.SetYields(m_piYieldChangeAnySpecialist, "Belief_YieldChangeAnySpecialist", "BeliefType", szBeliefType);
	kUtility.SetYields(m_piYieldChangeTradeRoute, "Belief_YieldChangeTradeRoute", "BeliefType", szBeliefType);
	kUtility.SetYields(m_piYieldChangeNaturalWonder, "Belief_YieldChangeNaturalWonder", "BeliefType", szBeliefType);
	kUtility.SetYields(m_piYieldChangeWorldWonder, "Belief_YieldChangeWorldWonder", "BeliefType", szBeliefType);
	kUtility.SetYields(m_piYieldModifierNaturalWonder, "Belief_YieldModifierNaturalWonder", "BeliefType", szBeliefType);
#if defined(MOD_BELIEF_NEW_EFFECT_FOR_SP)
	kUtility.PopulateArrayByValue(m_piGreatPersonPoints, "GreatPersons", "Belief_GreatPersonPoints", "GreatPersonType", "BeliefType", szBeliefType, "Value");
	kUtility.PopulateArrayByValue(m_piTerrainCityFoodConsumption, "Terrains", "Belief_TerrainCityFoodConsumption", "TerrainType", "BeliefType", szBeliefType, "Modifier");
#endif
	kUtility.PopulateArrayByValue(m_piMaxYieldModifierPerFollower, "Yields", "Belief_MaxYieldModifierPerFollower", "YieldType", "BeliefType", szBeliefType, "Max");
	kUtility.PopulateArrayByValue(m_piYieldModifierPerFollowerTimes100, "Yields", "Belief_YieldModifierPerFollowerTimes100", "YieldType", "BeliefType", szBeliefType, "Modifier");
	kUtility.PopulateArrayByValue(m_piResourceHappiness, "Resources", "Belief_ResourceHappiness", "ResourceType", "BeliefType", szBeliefType, "HappinessChange");
	kUtility.PopulateArrayByValue(m_piResourceQuantityModifiers, "Resources", "Belief_ResourceQuantityModifiers", "ResourceType", "BeliefType", szBeliefType, "ResourceQuantityModifier");
	kUtility.PopulateArrayByValue(m_paiBuildingClassHappiness, "BuildingClasses", "Belief_BuildingClassHappiness", "BuildingClassType", "BeliefType", szBeliefType, "Happiness");
	kUtility.PopulateArrayByValue(m_paiBuildingClassTourism, "BuildingClasses", "Belief_BuildingClassTourism", "BuildingClassType", "BeliefType", szBeliefType, "Tourism");
	kUtility.PopulateArrayByValue(m_paiYieldChangePerForeignCity, "Yields", "Belief_YieldChangePerForeignCity", "YieldType", "BeliefType", szBeliefType, "Yield");
	kUtility.PopulateArrayByValue(m_paiYieldChangePerXForeignFollowers, "Yields", "Belief_YieldChangePerXForeignFollowers", "YieldType", "BeliefType", szBeliefType, "ForeignFollowers");
#if defined(MOD_API_UNIFIED_YIELDS)
	kUtility.PopulateArrayByValue(m_piYieldPerFollowingCity, "Yields", "Belief_YieldPerFollowingCity", "YieldType", "BeliefType", szBeliefType, "Yield");
	kUtility.PopulateArrayByValue(m_piYieldPerXFollowers, "Yields", "Belief_YieldPerXFollowers", "YieldType", "BeliefType", szBeliefType, "PerXFollowers");
	kUtility.PopulateArrayByValue(m_piHolyCityYieldPerForeignFollowers, "Yields", "Belief_HolyCityYieldPerForeignFollowers", "YieldType", "BeliefType", szBeliefType, "PerForeignFollowers");
	kUtility.PopulateArrayByValue(m_piHolyCityYieldPerNativeFollowers, "Yields", "Belief_HolyCityYieldPerNativeFollowers", "YieldType", "BeliefType", szBeliefType, "PerNativeFollowers");
	kUtility.PopulateArrayByValue(m_piCityYieldPerOtherReligion, "Yields", "Belief_CityYieldPerOtherReligion", "YieldType", "BeliefType", szBeliefType, "Yield");
	kUtility.PopulateArrayByValue(m_piYieldPerOtherReligionFollower, "Yields", "Belief_YieldPerOtherReligionFollower", "YieldType", "BeliefType", szBeliefType, "Yield");
	kUtility.PopulateArrayByValue(m_piCuttingInstantYieldModifier, "Yields", "Belief_CuttingInstantYieldModifier", "YieldType", "BeliefType", szBeliefType, "Modifier");
	kUtility.PopulateArrayByValue(m_piCuttingInstantYield, "Yields", "Belief_CuttingInstantYield", "YieldType", "BeliefType", szBeliefType, "Yield");
#endif
	kUtility.SetFlavors(m_piExtraFlavorValue, "Belief_ExtraFlavors", "BeliefType",szBeliefType);
	kUtility.PopulateArrayByValue(m_piCivilizationFlavorValue, "Civilizations", "Belief_CivilizationFlavors", "CivilizationType", "BeliefType", szBeliefType, "Flavor");

	kUtility.PopulateArrayByExistence(m_pbFaithPurchaseUnitEraEnabled, "Eras", "Belief_EraFaithUnitPurchase", "EraType", "BeliefType", szBeliefType);
	kUtility.PopulateArrayByExistence(m_pbBuildingClassEnabled, "BuildingClasses", "Belief_BuildingClassFaithPurchase", "BuildingClassType", "BeliefType", szBeliefType);

	//ImprovementYieldChanges
	{
		kUtility.Initialize2DArray(m_ppiImprovementYieldChanges, "Improvements", "Yields");

		std::string strKey("Belief_ImprovementYieldChanges");
		Database::Results* pResults = kUtility.GetResults(strKey);
		if(pResults == NULL)
		{
			pResults = kUtility.PrepareResults(strKey, "select Improvements.ID as ImprovementID, Yields.ID as YieldID, Yield from Belief_ImprovementYieldChanges inner join Improvements on Improvements.Type = ImprovementType inner join Yields on Yields.Type = YieldType where BeliefType = ?");
		}

		pResults->Bind(1, szBeliefType);

		while(pResults->Step())
		{
			const int ImprovementID = pResults->GetInt(0);
			const int YieldID = pResults->GetInt(1);
			const int yield = pResults->GetInt(2);

			m_ppiImprovementYieldChanges[ImprovementID][YieldID] = yield;
		}
	}
	//ImprovementAdjacentCityYieldChanges;
	{
		kUtility.Initialize2DArray(m_ppiImprovementAdjacentCityYieldChanges, "Improvements", "Yields");

		std::string strKey("Belief_ImprovementAdjacentCityYieldChanges;");
		Database::Results* pResults = kUtility.GetResults(strKey);
		if(pResults == NULL)
		{
			pResults = kUtility.PrepareResults(strKey, "select Improvements.ID as ImprovementID, Yields.ID as YieldID, Yield from Belief_ImprovementAdjacentCityYieldChanges inner join Improvements on Improvements.Type = ImprovementType inner join Yields on Yields.Type = YieldType where BeliefType = ?");
		}

		pResults->Bind(1, szBeliefType);

		while(pResults->Step())
		{
			const int ImprovementID = pResults->GetInt(0);
			const int YieldID = pResults->GetInt(1);
			const int yield = pResults->GetInt(2);

			m_ppiImprovementAdjacentCityYieldChanges[ImprovementID][YieldID] = yield;
		}
	}

	//BuildingClassYieldChanges
	{
		kUtility.Initialize2DArray(m_ppiBuildingClassYieldChanges, "BuildingClasses", "Yields");

		std::string strKey("Belief_BuildingClassYieldChanges");
		Database::Results* pResults = kUtility.GetResults(strKey);
		if(pResults == NULL)
		{
			pResults = kUtility.PrepareResults(strKey, "select BuildingClasses.ID as BuildingClassID, Yields.ID as YieldID, YieldChange from Belief_BuildingClassYieldChanges inner join BuildingClasses on BuildingClasses.Type = BuildingClassType inner join Yields on Yields.Type = YieldType where BeliefType = ?");
		}

		pResults->Bind(1, szBeliefType);

		while(pResults->Step())
		{
			const int BuildingClassID = pResults->GetInt(0);
			const int iYieldID = pResults->GetInt(1);
			const int iYieldChange = pResults->GetInt(2);

			m_ppiBuildingClassYieldChanges[BuildingClassID][iYieldID] = iYieldChange;
		}
	}

	//FeatureYieldChanges
	{
		kUtility.Initialize2DArray(m_ppaiFeatureYieldChange, "Features", "Yields");

		std::string strKey("Belief_FeatureYieldChanges");
		Database::Results* pResults = kUtility.GetResults(strKey);
		if(pResults == NULL)
		{
			pResults = kUtility.PrepareResults(strKey, "select Features.ID as FeatureID, Yields.ID as YieldID, Yield from Belief_FeatureYieldChanges inner join Features on Features.Type = FeatureType inner join Yields on Yields.Type = YieldType where BeliefType = ?");
		}

		pResults->Bind(1, szBeliefType);

		while(pResults->Step())
		{
			const int FeatureID = pResults->GetInt(0);
			const int YieldID = pResults->GetInt(1);
			const int yield = pResults->GetInt(2);

			m_ppaiFeatureYieldChange[FeatureID][YieldID] = yield;
		}
	}

#if defined(MOD_API_UNIFIED_YIELDS)
	//CityYieldFromUnimprovedFeature
	if (MOD_API_UNIFIED_YIELDS) {
		kUtility.Initialize2DArray(m_ppiCityYieldFromUnimprovedFeature, "Features", "Yields");

		std::string strKey("Belief_CityYieldFromUnimprovedFeature");
		Database::Results* pResults = kUtility.GetResults(strKey);
		if(pResults == NULL)
		{
			pResults = kUtility.PrepareResults(strKey, "select Features.ID as FeatureID, Yields.ID as YieldID, Yield from Belief_CityYieldFromUnimprovedFeature inner join Features on Features.Type = FeatureType inner join Yields on Yields.Type = YieldType where BeliefType = ?");
		}

		pResults->Bind(1, szBeliefType);

		while(pResults->Step())
		{
			const int FeatureID = pResults->GetInt(0);
			const int YieldID = pResults->GetInt(1);
			const int yield = pResults->GetInt(2);

			m_ppiCityYieldFromUnimprovedFeature[FeatureID][YieldID] = yield;
		}
	}

	//UnimprovedFeatureYieldChanges
	if (MOD_API_UNIFIED_YIELDS) {
		kUtility.Initialize2DArray(m_ppiUnimprovedFeatureYieldChanges, "Features", "Yields");

		std::string strKey("Belief_UnimprovedFeatureYieldChanges");
		Database::Results* pResults = kUtility.GetResults(strKey);
		if(pResults == NULL)
		{
			pResults = kUtility.PrepareResults(strKey, "select Features.ID as FeatureID, Yields.ID as YieldID, Yield from Belief_UnimprovedFeatureYieldChanges inner join Features on Features.Type = FeatureType inner join Yields on Yields.Type = YieldType where BeliefType = ?");
		}

		pResults->Bind(1, szBeliefType);

		while(pResults->Step())
		{
			const int FeatureID = pResults->GetInt(0);
			const int YieldID = pResults->GetInt(1);
			const int yield = pResults->GetInt(2);

			m_ppiUnimprovedFeatureYieldChanges[FeatureID][YieldID] = yield;
		}
	}
#endif

	//ResourceYieldChanges
	{
		kUtility.Initialize2DArray(m_ppaiResourceYieldChange, "Resources", "Yields");

		std::string strKey("Belief_ResourceYieldChanges");
		Database::Results* pResults = kUtility.GetResults(strKey);
		if(pResults == NULL)
		{
			pResults = kUtility.PrepareResults(strKey, "select Resources.ID as ResourceID, Yields.ID as YieldID, Yield from Belief_ResourceYieldChanges inner join Resources on Resources.Type = ResourceType inner join Yields on Yields.Type = YieldType where BeliefType = ?");
		}

		pResults->Bind(1, szBeliefType);

		while(pResults->Step())
		{
			const int ResourceID = pResults->GetInt(0);
			const int YieldID = pResults->GetInt(1);
			const int yield = pResults->GetInt(2);

			m_ppaiResourceYieldChange[ResourceID][YieldID] = yield;
		}
	}

	//TerrainYieldChanges
	{
		kUtility.Initialize2DArray(m_ppaiTerrainYieldChange, "Terrains", "Yields");

		std::string strKey("Belief_TerrainYieldChanges");
		Database::Results* pResults = kUtility.GetResults(strKey);
		if(pResults == NULL)
		{
			pResults = kUtility.PrepareResults(strKey, "select Terrains.ID as TerrainID, Yields.ID as YieldID, Yield from Belief_TerrainYieldChanges inner join Terrains on Terrains.Type = TerrainType inner join Yields on Yields.Type = YieldType where BeliefType = ?");
		}

		pResults->Bind(1, szBeliefType);

		while(pResults->Step())
		{
			const int TerrainID = pResults->GetInt(0);
			const int YieldID = pResults->GetInt(1);
			const int yield = pResults->GetInt(2);

			m_ppaiTerrainYieldChange[TerrainID][YieldID] = yield;
		}
	}
	//TerrainYieldChangesAdditive
	{
		kUtility.Initialize2DArray(m_ppaiTerrainYieldChangeAdditive, "Terrains", "Yields");

		std::string strKey("TerrainYieldChangesAdditive");
		Database::Results* pResults = kUtility.GetResults(strKey);
		if(pResults == NULL)
		{
			pResults = kUtility.PrepareResults(strKey, "select Terrains.ID as TerrainID, Yields.ID as YieldID, Yield from Belief_TerrainYieldChangesAdditive inner join Terrains on Terrains.Type = TerrainType inner join Yields on Yields.Type = YieldType where BeliefType = ?");
		}

		pResults->Bind(1, szBeliefType);

		while(pResults->Step())
		{
			const int TerrainID = pResults->GetInt(0);
			const int YieldID = pResults->GetInt(1);
			const int yield = pResults->GetInt(2);

			m_ppaiTerrainYieldChangeAdditive[TerrainID][YieldID] = yield;
		}
	}

	//TerrainCityYieldChanges
	{
		kUtility.Initialize2DArray(m_ppaiTerrainCityYieldChanges, "Terrains", "Yields");

		std::string strKey("TerrainCityYieldChanges");
		Database::Results* pResults = kUtility.GetResults(strKey);
		if(pResults == NULL)
		{
			pResults = kUtility.PrepareResults(strKey, "select Terrains.ID as TerrainID, Yields.ID as YieldID, Yield from Belief_TerrainCityYieldChanges inner join Terrains on Terrains.Type = TerrainType inner join Yields on Yields.Type = YieldType where BeliefType = ?");
		}

		pResults->Bind(1, szBeliefType);

		while(pResults->Step())
		{
			const int TerrainID = pResults->GetInt(0);
			const int YieldID = pResults->GetInt(1);
			const int yield = pResults->GetInt(2);

			m_ppaiTerrainCityYieldChanges[TerrainID][YieldID] = yield;
		}
	}
	
#if defined(MOD_API_UNIFIED_YIELDS)
	//TradeRouteYieldChange
	if (MOD_API_UNIFIED_YIELDS) {
		kUtility.Initialize2DArray(m_ppiTradeRouteYieldChange, "Domains", "Yields");

		std::string strKey("Belief_TradeRouteYieldChange");
		Database::Results* pResults = kUtility.GetResults(strKey);
		if(pResults == NULL)
		{
			pResults = kUtility.PrepareResults(strKey, "select Domains.ID as DomainID, Yields.ID as YieldID, Yield from Belief_TradeRouteYieldChange inner join Domains on Domains.Type = DomainType inner join Yields on Yields.Type = YieldType where BeliefType = ?");
		}

		pResults->Bind(1, szBeliefType);

		while(pResults->Step())
		{
			const int DomainID = pResults->GetInt(0);
			const int YieldID = pResults->GetInt(1);
			const int yield = pResults->GetInt(2);

			m_ppiTradeRouteYieldChange[DomainID][YieldID] = yield;
		}
	}
	
	//SpecialistYieldChanges
	if (MOD_API_UNIFIED_YIELDS) {
		kUtility.Initialize2DArray(m_ppiSpecialistYieldChange, "Specialists", "Yields");

		std::string strKey("Belief_SpecialistYieldChanges");
		Database::Results* pResults = kUtility.GetResults(strKey);
		if(pResults == NULL)
		{
			pResults = kUtility.PrepareResults(strKey, "select Specialists.ID as SpecialistID, Yields.ID as YieldID, Yield from Belief_SpecialistYieldChanges inner join Specialists on Specialists.Type = SpecialistType inner join Yields on Yields.Type = YieldType where BeliefType = ?");
		}

		pResults->Bind(1, szBeliefType);

		while(pResults->Step())
		{
			const int SpecialistID = pResults->GetInt(0);
			const int YieldID = pResults->GetInt(1);
			const int yield = pResults->GetInt(2);

			m_ppiSpecialistYieldChange[SpecialistID][YieldID] = yield;
		}
	}
	
	//GreatPersonExpendedYield
	if (MOD_API_UNIFIED_YIELDS) {
		kUtility.Initialize2DArray(m_ppiGreatPersonExpendedYield, "GreatPersons", "Yields");

		std::string strKey("Belief_GreatPersonExpendedYield");
		Database::Results* pResults = kUtility.GetResults(strKey);
		if(pResults == NULL)
		{
			pResults = kUtility.PrepareResults(strKey, "select GreatPersons.ID as GreatPersonID, Yields.ID as YieldID, Yield from Belief_GreatPersonExpendedYield inner join GreatPersons on GreatPersons.Type = GreatPersonType inner join Yields on Yields.Type = YieldType where BeliefType = ?");
		}

		pResults->Bind(1, szBeliefType);

		while(pResults->Step())
		{
			const int GreatPersonID = pResults->GetInt(0);
			const int YieldID = pResults->GetInt(1);
			const int yield = pResults->GetInt(2);

			m_ppiGreatPersonExpendedYield[GreatPersonID][YieldID] = yield;
		}
	}
	
	kUtility.PopulateArrayByValue(m_piGoldenAgeGreatPersonRateModifier, "GreatPersons", "Belief_GoldenAgeGreatPersonRateModifier", "GreatPersonType", "BeliefType", szBeliefType, "Modifier");
	kUtility.SetYields(m_piCapitalYieldChange, "Belief_CapitalYieldChanges", "BeliefType", szBeliefType);
	kUtility.SetYields(m_piCoastalCityYieldChange, "Belief_CoastalCityYieldChanges", "BeliefType", szBeliefType);
	kUtility.SetYields(m_piGreatWorkYieldChange, "Belief_GreatWorkYieldChanges", "BeliefType", szBeliefType);
	kUtility.SetYields(m_piYieldFromKills, "Belief_YieldFromKills", "BeliefType", szBeliefType);
	kUtility.SetYields(m_piYieldFromBarbarianKills, "Belief_YieldFromBarbarianKills", "BeliefType", szBeliefType);
#endif

#if defined(MOD_RELIGION_PLOT_YIELDS)
	if (MOD_RELIGION_PLOT_YIELDS)
	//PlotYieldChanges
	{
		kUtility.Initialize2DArray(m_ppiPlotYieldChange, "Plots", "Yields");

		std::string strKey("Belief_PlotYieldChanges");
		Database::Results* pResults = kUtility.GetResults(strKey);
		if(pResults == NULL)
		{
			pResults = kUtility.PrepareResults(strKey, "select Plots.ID as PlotID, Yields.ID as YieldID, Yield from Belief_PlotYieldChanges inner join Plots on Plots.Type = PlotType inner join Yields on Yields.Type = YieldType where BeliefType = ?");
		}

		pResults->Bind(1, szBeliefType);

		while(pResults->Step())
		{
			const int PlotID = pResults->GetInt(0);
			const int YieldID = pResults->GetInt(1);
			const int yield = pResults->GetInt(2);

			m_ppiPlotYieldChange[PlotID][YieldID] = yield;
		}
	}
#endif

	return true;
}

//=====================================
// CvBeliefXMLEntries
//=====================================
/// Constructor
CvBeliefXMLEntries::CvBeliefXMLEntries(void)
{

}

/// Destructor
CvBeliefXMLEntries::~CvBeliefXMLEntries(void)
{
	DeleteArray();
}

/// Returns vector of belief entries
std::vector<CvBeliefEntry*>& CvBeliefXMLEntries::GetBeliefEntries()
{
	return m_paBeliefEntries;
}

/// Number of defined beliefs
int CvBeliefXMLEntries::GetNumBeliefs()
{
	return m_paBeliefEntries.size();
}

/// Clear belief entries
void CvBeliefXMLEntries::DeleteArray()
{
	for(std::vector<CvBeliefEntry*>::iterator it = m_paBeliefEntries.begin(); it != m_paBeliefEntries.end(); ++it)
	{
		SAFE_DELETE(*it);
	}

	m_paBeliefEntries.clear();
}

/// Get a specific entry
CvBeliefEntry* CvBeliefXMLEntries::GetEntry(int index)
{
	return m_paBeliefEntries[index];
}

//=====================================
// CvReligionBeliefs
//=====================================
/// Constructor
CvReligionBeliefs::CvReligionBeliefs():
	m_paiBuildingClassEnabled(NULL)
{
	Reset();
}

/// Destructor
CvReligionBeliefs::~CvReligionBeliefs(void)
{
	Uninit();
}

/// Copy Constructor with typical parameters
CvReligionBeliefs::CvReligionBeliefs(const CvReligionBeliefs& source)
{
	m_iFaithFromDyingUnits = source.m_iFaithFromDyingUnits;
	m_iRiverHappiness = source.m_iRiverHappiness;
	m_iPlotCultureCostModifier = source.m_iPlotCultureCostModifier;
	m_iCityRangeStrikeModifier = source.m_iCityRangeStrikeModifier;
	m_iCombatModifierEnemyCities = source.m_iCombatModifierEnemyCities;
	m_iCombatModifierFriendlyCities = source.m_iCombatModifierFriendlyCities;
	m_iFriendlyHealChange = source.m_iFriendlyHealChange;
	m_iCityStateFriendshipModifier = source.m_iCityStateFriendshipModifier;
	m_iLandBarbarianConversionPercent = source.m_iLandBarbarianConversionPercent;
	m_iSpreadDistanceModifier = source.m_iSpreadDistanceModifier;
	m_iSpreadStrengthModifier = source.m_iSpreadStrengthModifier;
	m_iProphetStrengthModifier = source.m_iProphetStrengthModifier;
	m_iProphetCostModifier = source.m_iProphetCostModifier;
	m_iMissionaryStrengthModifier = source.m_iMissionaryStrengthModifier;
	m_iMissionaryCostModifier = source.m_iMissionaryCostModifier;
	m_iFriendlyCityStateSpreadModifier = source.m_iFriendlyCityStateSpreadModifier;
	m_iGreatPersonExpendedFaith = source.m_iGreatPersonExpendedFaith;
	m_iCityStateMinimumInfluence = source.m_iCityStateMinimumInfluence;
	m_iCityStateInfluenceModifier = source.m_iCityStateInfluenceModifier;
	m_iOtherReligionPressureErosion = source.m_iOtherReligionPressureErosion;
	m_iSpyPressure = source.m_iSpyPressure;
	m_iInquisitorPressureRetention = source.m_iInquisitorPressureRetention;
	m_iFaithBuildingTourism = source.m_iFaithBuildingTourism;

#if defined(MOD_BELIEF_NEW_EFFECT_FOR_SP)
	m_iGoldenAgeModifier = source.m_iGoldenAgeModifier;
	m_iExtraSpies = source.m_iExtraSpies;
	m_bGreatPersonPoints = source.m_bGreatPersonPoints;
	m_vFreePromotionForProphet = source.m_vFreePromotionForProphet;
	m_iFounderFreePromotion = source.m_iFounderFreePromotion;
	m_vFollowingCityFreePromotion = source.m_vFollowingCityFreePromotion;
	m_iLandmarksTourismPercent = source.m_iLandmarksTourismPercent;
	m_iHolyCityUnitExperence = source.m_iHolyCityUnitExperence;
	m_iHolyCityPressureModifier = source.m_iHolyCityPressureModifier;
	m_iSameReligionMinorRecoveryModifier = source.m_iSameReligionMinorRecoveryModifier;
	m_iInquisitionFervorTimeModifier = source.m_iInquisitionFervorTimeModifier;
	m_iNumInquisitorProhibitSpreadInAlly = source.m_iNumInquisitorProhibitSpreadInAlly;
	m_iCuttingBonusModifier = source.m_iCuttingBonusModifier;
	m_iCityExtraMissionarySpreads = source.m_iCityExtraMissionarySpreads;
	m_bAllowYieldPerBirth = source.m_bAllowYieldPerBirth;
#endif
	m_vImprovementYieldChanges = source.m_vImprovementYieldChanges;
	m_vImprovementAdjacentCityYieldChanges = source.m_vImprovementAdjacentCityYieldChanges;

	m_eObsoleteEra = source.m_eObsoleteEra;
	m_eResourceRevealed = source.m_eResourceRevealed;
	m_eSpreadModifierDoublingTech = source.m_eSpreadModifierDoublingTech;

	m_ReligionBeliefs = source.m_ReligionBeliefs;

	m_paiBuildingClassEnabled = FNEW(int[GC.getNumBuildingClassInfos()], c_eCiv5GameplayDLL, 0);
	for(int iI = 0; iI < GC.getNumBuildingClassInfos(); iI++)
	{
		CvBuildingClassInfo* pkBuildingClassInfo = GC.getBuildingClassInfo((BuildingClassTypes)iI);
		if(!pkBuildingClassInfo)
		{
			continue;
		}

		m_paiBuildingClassEnabled[iI] = source.m_paiBuildingClassEnabled[iI];
	}
}

/// Deallocate memory created in initialize
void CvReligionBeliefs::Uninit()
{
	SAFE_DELETE_ARRAY(m_paiBuildingClassEnabled);
}

/// Reset data members
void CvReligionBeliefs::Reset()
{
	m_iFaithFromDyingUnits = 0;
	m_iRiverHappiness = 0;
	m_iPlotCultureCostModifier = 0;
	m_iCityRangeStrikeModifier = 0;
	m_iCombatModifierEnemyCities = 0;
	m_iCombatModifierFriendlyCities = 0;
	m_iFriendlyHealChange = 0;
	m_iCityStateFriendshipModifier = 0;
	m_iLandBarbarianConversionPercent = 0;
	m_iSpreadDistanceModifier = 0;
	m_iSpreadStrengthModifier = 0;
	m_iProphetStrengthModifier = 0;
	m_iProphetCostModifier = 0;
	m_iMissionaryStrengthModifier = 0;
	m_iMissionaryCostModifier = 0;
	m_iFriendlyCityStateSpreadModifier = 0;
	m_iGreatPersonExpendedFaith = 0;
	m_iCityStateMinimumInfluence = 0;
	m_iCityStateInfluenceModifier = 0;
	m_iOtherReligionPressureErosion = 0;
	m_iSpyPressure = 0;
	m_iInquisitorPressureRetention = 0;
	m_iFaithBuildingTourism = 0;

#if defined(MOD_BELIEF_NEW_EFFECT_FOR_SP)
	m_iGoldenAgeModifier = 0;
	m_iExtraSpies = 0;
	m_bGreatPersonPoints = false;
	m_vFreePromotionForProphet.clear();
	m_iFounderFreePromotion = NO_PROMOTION;
	m_vFollowingCityFreePromotion.clear();
	m_iLandmarksTourismPercent = 0;
	m_iHolyCityUnitExperence = 0;
	m_iHolyCityPressureModifier = 0;
	m_iSameReligionMinorRecoveryModifier = 0;
	m_iInquisitionFervorTimeModifier = 0;
	m_iNumInquisitorProhibitSpreadInAlly = 0;
	m_iCuttingBonusModifier = 0;
	m_iCityExtraMissionarySpreads = 0;
	m_bAllowYieldPerBirth = false;
#endif
	m_vImprovementYieldChanges.resize(GC.getNumImprovementInfos(), vector<int>(NUM_YIELD_TYPES, 0));
	m_vImprovementAdjacentCityYieldChanges.resize(GC.getNumImprovementInfos(), vector<int>(NUM_YIELD_TYPES, 0));

	m_eObsoleteEra = NO_ERA;
	m_eResourceRevealed = NO_RESOURCE;
	m_eSpreadModifierDoublingTech = NO_TECH;

	m_ReligionBeliefs.clear();

	m_paiBuildingClassEnabled = FNEW(int[GC.getNumBuildingClassInfos()], c_eCiv5GameplayDLL, 0);
	for(int iI = 0; iI < GC.getNumBuildingClassInfos(); iI++)
	{
		CvBuildingClassInfo* pkBuildingClassInfo = GC.getBuildingClassInfo((BuildingClassTypes)iI);
		if(!pkBuildingClassInfo)
		{
			continue;
		}

		m_paiBuildingClassEnabled[iI] = 0;
	}
}

/// Store off data on bonuses from beliefs
void CvReligionBeliefs::AddBelief(BeliefTypes eBelief, PlayerTypes ePlayer)
{
	CvAssert(eBelief != NO_BELIEF);
	if(eBelief == NO_BELIEF)
		return;

	CvBeliefEntry* belief = GC.GetGameBeliefs()->GetEntry(eBelief);
	CvAssert(belief != NULL);
	if(belief == NULL)
		return;

	m_iFaithFromDyingUnits += belief->GetFaithFromDyingUnits();
	m_iRiverHappiness += belief->GetRiverHappiness();
	m_iPlotCultureCostModifier += belief->GetPlotCultureCostModifier();
	m_iCityRangeStrikeModifier += belief->GetCityRangeStrikeModifier();
	m_iCombatModifierEnemyCities += belief->GetCombatModifierEnemyCities();
	m_iCombatModifierFriendlyCities += belief->GetCombatModifierFriendlyCities();
	m_iFriendlyHealChange += belief->GetFriendlyHealChange();
	m_iCityStateFriendshipModifier += belief->GetCityStateFriendshipModifier();
	m_iLandBarbarianConversionPercent += belief->GetLandBarbarianConversionPercent();
	m_iSpreadDistanceModifier += belief->GetSpreadDistanceModifier();
	m_iSpreadStrengthModifier += belief->GetSpreadStrengthModifier();
	m_iProphetStrengthModifier += belief->GetProphetStrengthModifier();
	m_iProphetCostModifier += belief->GetProphetCostModifier();
	m_iMissionaryStrengthModifier += belief->GetMissionaryStrengthModifier();
	m_iMissionaryCostModifier += belief->GetMissionaryCostModifier();
	m_iFriendlyCityStateSpreadModifier += belief->GetFriendlyCityStateSpreadModifier();
	m_iGreatPersonExpendedFaith += belief->GetGreatPersonExpendedFaith();
	m_iCityStateMinimumInfluence += belief->GetCityStateMinimumInfluence();
	m_iCityStateInfluenceModifier += belief->GetCityStateInfluenceModifier();
	m_iOtherReligionPressureErosion += belief->GetOtherReligionPressureErosion();
	m_iSpyPressure += belief->GetSpyPressure();
	m_iInquisitorPressureRetention += belief->GetInquisitorPressureRetention();
	m_iFaithBuildingTourism += belief->GetFaithBuildingTourism();

#if defined(MOD_BELIEF_NEW_EFFECT_FOR_SP)
	m_iGoldenAgeModifier += belief->GetGoldenAgeModifier();
	m_iExtraSpies += belief->GetExtraSpies();
	// The actual effect is added in the CvPlayer::processBelief
	
	m_bGreatPersonPoints = m_bGreatPersonPoints || belief->IsGreatPersonPointsCapital() || belief->IsGreatPersonPointsPerCity() || belief->IsGreatPersonPointsHolyCity();	
	if(belief->GetFreePromotionForProphet() != NO_PROMOTION)
	{
		m_vFreePromotionForProphet.push_back(belief->GetFreePromotionForProphet());
	}
	if(belief->GetFollowingCityFreePromotion() != NO_PROMOTION)
	{
		m_vFollowingCityFreePromotion.insert(belief->GetFollowingCityFreePromotion());
	}
	m_iLandmarksTourismPercent += belief->GetLandmarksTourismPercent();
	m_iHolyCityUnitExperence += belief->GetHolyCityUnitExperence();
	m_iHolyCityPressureModifier += belief->GetHolyCityPressureModifier();
	m_iSameReligionMinorRecoveryModifier += belief->GetSameReligionMinorRecoveryModifier();
	m_iInquisitionFervorTimeModifier += belief->GetInquisitionFervorTimeModifier();
	m_iNumInquisitorProhibitSpreadInAlly += belief->IsInquisitorProhibitSpreadInAlly() ? 1 : 0;
	m_iCuttingBonusModifier += belief->GetCuttingBonusModifier();
	m_iCityExtraMissionarySpreads += belief->GetCityExtraMissionarySpreads();
	m_bAllowYieldPerBirth = m_bAllowYieldPerBirth || belief->AllowYieldPerBirth();
#endif
	for (int iImprovement = 0; iImprovement < GC.getNumImprovementInfos(); iImprovement++)
	{
		for(int iYield = 0; iYield < NUM_YIELD_TYPES; iYield++)
		{
			m_vImprovementYieldChanges[iImprovement][iYield] += belief->GetImprovementYieldChange((ImprovementTypes)iImprovement, (YieldTypes)iYield);
			m_vImprovementAdjacentCityYieldChanges[iImprovement][iYield] += belief->GetImprovementAdjacentCityYieldChange((ImprovementTypes)iImprovement, (YieldTypes)iYield);
		}
	}

	m_eObsoleteEra = belief->GetObsoleteEra();
	m_eResourceRevealed = belief->GetResourceRevealed();

	for (int iI = 0; iI < GC.getNumBuildingClassInfos(); iI++)
	{
		if (belief->IsBuildingClassEnabled(iI))
		{
			m_paiBuildingClassEnabled[iI]++;
		}
	}

	if(belief->GetSpreadModifierDoublingTech() != NO_TECH)
	{
		m_eSpreadModifierDoublingTech = belief->GetSpreadModifierDoublingTech();
	}

	m_ReligionBeliefs.push_back((int)eBelief);

	//Attention !!! in CanFoundReligion(), ePlayer is NO_PLAYER(to avoid adding Repeated value)
	if(ePlayer != NO_PLAYER) GET_PLAYER(ePlayer).processBelief(eBelief, 1, true);
}

/// Does this religion possess a specific belief?
bool CvReligionBeliefs::HasBelief(BeliefTypes eBelief) const
{
	return (find(m_ReligionBeliefs.begin(), m_ReligionBeliefs.end(), (int)eBelief) != m_ReligionBeliefs.end());
}

/// Does this religion possess a specific belief?
BeliefTypes CvReligionBeliefs::GetBelief(int iIndex) const
{
	return (BeliefTypes)m_ReligionBeliefs[iIndex];
}

/// Does this religion possess a specific belief?
int CvReligionBeliefs::GetNumBeliefs() const
{
	return m_ReligionBeliefs.size();
}

/// Faith from kills
int CvReligionBeliefs::GetFaithFromKills(int iDistance) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;
	int iRequiredDistance;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		CvBeliefEntry* pBeliefEntry = pBeliefs->GetEntry(*i);
		iRequiredDistance = pBeliefEntry->GetMaxDistance();
		if(iRequiredDistance == 0 || iDistance <= iRequiredDistance)
		{
			rtnValue += pBeliefEntry->GetFaithFromKills();
		}
	}

	return rtnValue;
}

/// Happiness per city
int CvReligionBeliefs::GetHappinessPerCity(int iPopulation) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		CvBeliefEntry* pBeliefEntry = pBeliefs->GetEntry(*i);
		if(iPopulation >= pBeliefEntry->GetMinPopulation())
		{
			rtnValue += pBeliefEntry->GetHappinessPerCity();
		}
	}

	return rtnValue;
}

/// Happiness per X followers in foreign cities of powers you are not at war with
int CvReligionBeliefs::GetHappinessPerXPeacefulForeignFollowers() const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		CvBeliefEntry* pBeliefEntry = pBeliefs->GetEntry(*i);
		if(pBeliefEntry->GetHappinessPerXPeacefulForeignFollowers() > 0)
		{
			return pBeliefEntry->GetHappinessPerXPeacefulForeignFollowers();
		}
	}

	return 0;
}

/// Wonder production boost
int CvReligionBeliefs:: GetWonderProductionModifier(EraTypes eWonderEra) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		CvBeliefEntry* pBeliefEntry = pBeliefs->GetEntry(*i);
		int iObsoleteEra = pBeliefEntry->GetObsoleteEra();
		if((iObsoleteEra != NO_ERA && (int)eWonderEra < iObsoleteEra) || iObsoleteEra == NO_ERA)
		{
			rtnValue += pBeliefEntry->GetWonderProductionModifier();
		}
	}

	return rtnValue;
}

/// Player happiness boost
int CvReligionBeliefs:: GetPlayerHappiness(bool bAtPeace) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		CvBeliefEntry* pBeliefEntry = pBeliefs->GetEntry(*i);
		if(bAtPeace || !pBeliefEntry->RequiresPeace())
		{
			rtnValue += pBeliefEntry->GetPlayerHappiness();
		}
	}

	return rtnValue;
}

/// Player culture modifier
int CvReligionBeliefs:: GetPlayerCultureModifier(bool bAtPeace) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		CvBeliefEntry* pBeliefEntry = pBeliefs->GetEntry(*i);
		if(bAtPeace || !pBeliefEntry->RequiresPeace())
		{
			rtnValue += pBeliefEntry->GetPlayerCultureModifier();
		}
	}

	return rtnValue;
}

/// Happiness per following city
float CvReligionBeliefs:: GetHappinessPerFollowingCity() const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	float rtnValue = 0.0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetHappinessPerFollowingCity();
	}

	return rtnValue;
}

/// Gold per following city
int CvReligionBeliefs:: GetGoldPerFollowingCity() const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetGoldPerFollowingCity();
	}

	return rtnValue;
}

/// Gold per following city
int CvReligionBeliefs:: GetGoldPerXFollowers() const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetGoldPerXFollowers();
	}

	return rtnValue;
}

/// Gold per following city
int CvReligionBeliefs:: GetGoldWhenCityAdopts() const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetGoldWhenCityAdopts();
	}

	return rtnValue;
}

/// Science per other religion follower
int CvReligionBeliefs:: GetSciencePerOtherReligionFollower() const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetSciencePerOtherReligionFollower();
	}

	return rtnValue;
}

/// City growth modifier
int CvReligionBeliefs::GetCityGrowthModifier(bool bAtPeace) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		CvBeliefEntry* pBeliefEntry = pBeliefs->GetEntry(*i);
		if(bAtPeace || !pBeliefEntry->RequiresPeace())
		{
			rtnValue += pBeliefEntry->GetCityGrowthModifier();
		}
	}

	return rtnValue;
}

/// Extra yield
int CvReligionBeliefs::GetCityYieldChange(int iPopulation, YieldTypes eYield) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		CvBeliefEntry* pBeliefEntry = pBeliefs->GetEntry(*i);
		if(iPopulation >= pBeliefEntry->GetMinPopulation())
		{
			rtnValue += pBeliefEntry->GetCityYieldChange(eYield);
		}
	}

	return rtnValue;
}

/// Extra holy city yield
int CvReligionBeliefs::GetHolyCityYieldChange (YieldTypes eYield) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetHolyCityYieldChange(eYield);
	}

	return rtnValue;
}

/// Extra yield for foreign cities following religion
int CvReligionBeliefs::GetYieldChangePerForeignCity(YieldTypes eYield) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetYieldChangePerForeignCity(eYield);
	}

	return rtnValue;
}

/// Extra yield for foreign followers
int CvReligionBeliefs::GetYieldChangePerXForeignFollowers(YieldTypes eYield) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetYieldChangePerXForeignFollowers(eYield);
	}

	return rtnValue;
}

#if defined(MOD_API_UNIFIED_YIELDS)
int CvReligionBeliefs::GetYieldPerFollowingCity(YieldTypes eYield) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetYieldPerFollowingCity(eYield);
	}

	return rtnValue;
}

int CvReligionBeliefs::GetYieldPerXFollowers(YieldTypes eYield) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetYieldPerXFollowers(eYield);
	}

	return rtnValue;
}

int CvReligionBeliefs::GetHolyCityYieldPerForeignFollowers(YieldTypes eYield) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetHolyCityYieldPerForeignFollowers(eYield);
	}

	return rtnValue;
}

int CvReligionBeliefs::GetHolyCityYieldPerNativeFollowers(YieldTypes eYield) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetHolyCityYieldPerNativeFollowers(eYield);
	}

	return rtnValue;
}

int CvReligionBeliefs::GetCityYieldPerOtherReligion(YieldTypes eYield) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetCityYieldPerOtherReligion(eYield);
	}

	return rtnValue;
}

int CvReligionBeliefs::GetYieldPerOtherReligionFollower(YieldTypes eYield) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetYieldPerOtherReligionFollower(eYield);
	}

	return rtnValue;
}

int CvReligionBeliefs::GetCuttingInstantYieldModifier(YieldTypes eYield) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetCuttingInstantYieldModifier(eYield);
	}

	return rtnValue;
}

int CvReligionBeliefs::GetCuttingInstantYield(YieldTypes eYield) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetCuttingInstantYield(eYield);
	}

	return rtnValue;
}
#endif

/// Extra yield from this improvement
int CvReligionBeliefs::GetResourceQuantityModifier(ResourceTypes eResource) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetResourceQuantityModifier(eResource);
	}

	return rtnValue;
}

/// Extra yield from this improvement
int CvReligionBeliefs::GetImprovementYieldChange(ImprovementTypes eImprovement, YieldTypes eYield) const
{
	return m_vImprovementYieldChanges[eImprovement][eYield];
}

int CvReligionBeliefs::GetImprovementAdjacentCityYieldChange(ImprovementTypes eImprovement, YieldTypes eYield) const
{
	return m_vImprovementAdjacentCityYieldChanges[eImprovement][eYield];
}

/// Get yield change from beliefs for a specific building class
int CvReligionBeliefs::GetBuildingClassYieldChange(BuildingClassTypes eBuildingClass, YieldTypes eYieldType, int iFollowers) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		CvBeliefEntry* pBeliefEntry = pBeliefs->GetEntry(*i);
		if(iFollowers >= pBeliefEntry->GetMinFollowers())
		{
			rtnValue += pBeliefEntry->GetBuildingClassYieldChange(eBuildingClass, eYieldType);
		}
	}

	return rtnValue;
}

/// Get Happiness from beliefs for a specific building class
int CvReligionBeliefs::GetBuildingClassHappiness(BuildingClassTypes eBuildingClass, int iFollowers) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		CvBeliefEntry* pBeliefEntry = pBeliefs->GetEntry(*i);
		if(iFollowers >= pBeliefEntry->GetMinFollowers())
		{
			rtnValue += pBeliefEntry->GetBuildingClassHappiness(eBuildingClass);
		}
	}

	return rtnValue;
}

/// Get Tourism from beliefs for a specific building class
int CvReligionBeliefs::GetBuildingClassTourism(BuildingClassTypes eBuildingClass) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetBuildingClassTourism(eBuildingClass);
	}

	return rtnValue;
}

/// Get yield change from beliefs for a specific feature
int CvReligionBeliefs::GetFeatureYieldChange(FeatureTypes eFeature, YieldTypes eYieldType) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetFeatureYieldChange(eFeature, eYieldType);
	}

	return rtnValue;
}

#if defined(MOD_API_UNIFIED_YIELDS)
int CvReligionBeliefs::GetCityYieldFromUnimprovedFeature(FeatureTypes eFeature, YieldTypes eYieldType) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetCityYieldFromUnimprovedFeature(eFeature, eYieldType);
	}

	return rtnValue;
}

int CvReligionBeliefs::GetUnimprovedFeatureYieldChange(FeatureTypes eFeature, YieldTypes eYieldType) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetUnimprovedFeatureYieldChange(eFeature, eYieldType);
	}

	return rtnValue;
}
#endif

/// Get yield change from beliefs for a specific resource
int CvReligionBeliefs::GetResourceYieldChange(ResourceTypes eResource, YieldTypes eYieldType) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetResourceYieldChange(eResource, eYieldType);
	}

	return rtnValue;
}

/// Get yield change from beliefs for a specific terrain
int CvReligionBeliefs::GetTerrainYieldChange(TerrainTypes eTerrain, YieldTypes eYieldType) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetTerrainYieldChange(eTerrain, eYieldType);
	}

	return rtnValue;
}

/// Get yield change from beliefs for a specific terrain(include forest and natural wonders)
int CvReligionBeliefs::GetTerrainYieldChangeAdditive(TerrainTypes eTerrain, YieldTypes eYieldType) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetTerrainYieldChangeAdditive(eTerrain, eYieldType);
	}

	return rtnValue;
}

/// Get yield change from beliefs for a specific terrain(include forest and natural wonders)
int CvReligionBeliefs::GetTerrainCityYieldChanges(TerrainTypes eTerrain, YieldTypes eYieldType) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetTerrainCityYieldChanges(eTerrain, eYieldType);
	}

	return rtnValue;
}

#if defined(MOD_API_UNIFIED_YIELDS)
int CvReligionBeliefs::GetTradeRouteYieldChange(DomainTypes eDomain, YieldTypes eYieldType) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetTradeRouteYieldChange(eDomain, eYieldType);
	}

	return rtnValue;
}

int CvReligionBeliefs::GetSpecialistYieldChange(SpecialistTypes eSpecialist, YieldTypes eYieldType) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetSpecialistYieldChange(eSpecialist, eYieldType);
	}

	return rtnValue;
}

int CvReligionBeliefs::GetGreatPersonExpendedYield(GreatPersonTypes eGreatPerson, YieldTypes eYieldType) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetGreatPersonExpendedYield(eGreatPerson, eYieldType);
	}

	return rtnValue;
}

int CvReligionBeliefs::GetGoldenAgeGreatPersonRateModifier(GreatPersonTypes eGreatPerson) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetGoldenAgeGreatPersonRateModifier(eGreatPerson);
	}

	return rtnValue;
}

int CvReligionBeliefs::GetCapitalYieldChange(int iPopulation, YieldTypes eYield) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		CvBeliefEntry* pBeliefEntry = pBeliefs->GetEntry(*i);
		if(iPopulation >= pBeliefEntry->GetMinPopulation())
		{
			rtnValue += pBeliefEntry->GetCapitalYieldChange(eYield);
		}
	}

	return rtnValue;
}

int CvReligionBeliefs::GetCoastalCityYieldChange(int iPopulation, YieldTypes eYield) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		CvBeliefEntry* pBeliefEntry = pBeliefs->GetEntry(*i);
		if(iPopulation >= pBeliefEntry->GetMinPopulation())
		{
			rtnValue += pBeliefEntry->GetCoastalCityYieldChange(eYield);
		}
	}

	return rtnValue;
}

int CvReligionBeliefs::GetGreatWorkYieldChange(int iPopulation, YieldTypes eYield) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		CvBeliefEntry* pBeliefEntry = pBeliefs->GetEntry(*i);
		if(iPopulation >= pBeliefEntry->GetMinPopulation())
		{
			rtnValue += pBeliefEntry->GetGreatWorkYieldChange(eYield);
		}
	}

	return rtnValue;
}

/// Do we get one of our yields from defeating an enemy?
int CvReligionBeliefs::GetYieldFromKills(YieldTypes eYieldType) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetYieldFromKills(eYieldType);
	}

	return rtnValue;
}

/// Do we get one of our yields from defeating a barbarian?
int CvReligionBeliefs::GetYieldFromBarbarianKills(YieldTypes eYieldType) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetYieldFromBarbarianKills(eYieldType);
	}

	return rtnValue;
}
#endif

#if defined(MOD_RELIGION_PLOT_YIELDS)
/// Get yield change from beliefs for a specific plot
int CvReligionBeliefs::GetPlotYieldChange(PlotTypes ePlot, YieldTypes eYieldType) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	if (MOD_RELIGION_PLOT_YIELDS) {
		for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
		{
			rtnValue += pBeliefs->GetEntry(*i)->GetPlotYieldChange(ePlot, eYieldType);
		}
	}

	return rtnValue;
}
#endif

#if defined(MOD_BELIEF_NEW_EFFECT_FOR_SP)
/// Get Great Person Points from beliefs
int CvReligionBeliefs::GetGreatPersonPoints(GreatPersonTypes eGreatPersonTypes, bool bCapital, bool bHolyCity) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		CvBeliefEntry* pBeliefEntry = pBeliefs->GetEntry(*i);
		int iValue = pBeliefEntry->GetGreatPersonPoints(eGreatPersonTypes, bCapital, bHolyCity);
		if (iValue != 0)
		{
			rtnValue += iValue;
		}
	}

	return rtnValue;
}

/// Get City Food Consume Modifier with Terrain from beliefs
int CvReligionBeliefs::GetTerrainCityFoodConsumption(TerrainTypes eTerrain) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetTerrainCityFoodConsumption(eTerrain);
	}

	return rtnValue;
}

/// Get yield from beliefs with birth
int CvReligionBeliefs::GetYieldPerBirth(YieldTypes eYieldType) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetYieldPerBirth(eYieldType);
	}

	return rtnValue;
}
/// Get lake yield from beliefs
int CvReligionBeliefs::GetLakePlotYieldChange(YieldTypes eYieldType) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetLakePlotYieldChange(eYieldType);
	}

	return rtnValue;
}
/// Get river yield from beliefs
int CvReligionBeliefs::GetRiverPlotYieldChange(YieldTypes eYieldType) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetRiverPlotYieldChange(eYieldType);
	}

	return rtnValue;
}

#endif

// Get happiness boost from a resource
int CvReligionBeliefs::GetResourceHappiness(ResourceTypes eResource) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetResourceHappiness(eResource);
	}

	return rtnValue;
}

/// Get yield change from beliefs for a specialist being present in city
int CvReligionBeliefs::GetYieldChangeAnySpecialist(YieldTypes eYieldType) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetYieldChangeAnySpecialist(eYieldType);
	}

	return rtnValue;
}

/// Get yield change from beliefs for a trade route
int CvReligionBeliefs::GetYieldChangeTradeRoute(YieldTypes eYieldType) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetYieldChangeTradeRoute(eYieldType);
	}

	return rtnValue;
}

/// Get yield change from beliefs for a natural wonder
int CvReligionBeliefs::GetYieldChangeNaturalWonder(YieldTypes eYieldType) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetYieldChangeNaturalWonder(eYieldType);
	}

	return rtnValue;
}

/// Get yield change from beliefs for a world wonder
int CvReligionBeliefs::GetYieldChangeWorldWonder(YieldTypes eYieldType) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetYieldChangeWorldWonder(eYieldType);
	}

	return rtnValue;
}

/// Get yield modifier from beliefs for a natural wonder
int CvReligionBeliefs::GetYieldModifierNaturalWonder(YieldTypes eYieldType) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetYieldModifierNaturalWonder(eYieldType);
	}

	return rtnValue;
}

/// Get yield modifier from beliefs for a natural wonder
int CvReligionBeliefs::GetMaxYieldModifierPerFollower(YieldTypes eYieldType) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetMaxYieldModifierPerFollower(eYieldType);
	}

	return rtnValue;
}
int CvReligionBeliefs::GetYieldModifierPerFollowerTimes100(YieldTypes eYieldType) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();
	int rtnValue = 0;

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		rtnValue += pBeliefs->GetEntry(*i)->GetYieldModifierPerFollowerTimes100(eYieldType);
	}

	return rtnValue;
}

/// Does this belief allow a building to be constructed?
bool CvReligionBeliefs::IsBuildingClassEnabled(BuildingClassTypes eType) const
{
	return m_paiBuildingClassEnabled[(int)eType];
}

/// Is there a belief that allows faith buying of units
bool CvReligionBeliefs::IsFaithBuyingEnabled(EraTypes eEra) const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		if (pBeliefs->GetEntry(*i)->IsFaithUnitPurchaseEra((int)eEra))
		{
			return true;
		}
	}

	return false;
}

/// Is there a belief that allows us to convert adjacent barbarians?
bool CvReligionBeliefs::IsConvertsBarbarians() const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		if (pBeliefs->GetEntry(*i)->ConvertsBarbarians())
		{
			return true;
		}
	}

	return false;
}

/// Is there a belief that allows faith buying of all great people
bool CvReligionBeliefs::IsFaithPurchaseAllGreatPeople() const
{
	CvBeliefXMLEntries* pBeliefs = GC.GetGameBeliefs();

	for (BeliefList::const_iterator i = m_ReligionBeliefs.begin(); i != m_ReligionBeliefs.end(); i++)
	{
		if (pBeliefs->GetEntry(*i)->FaithPurchaseAllGreatPeople())
		{
			return true;
		}
	}

	return false;
}

/// Serialization read
void CvReligionBeliefs::Read(FDataStream& kStream)
{
	// Version number to maintain backwards compatibility
	uint uiVersion;
	kStream >> uiVersion;
	MOD_SERIALIZE_INIT_READ(kStream);

	kStream >> m_iFaithFromDyingUnits;
	kStream >> m_iRiverHappiness;
	kStream >> m_iPlotCultureCostModifier;
	kStream >> m_iCityRangeStrikeModifier;
	kStream >> m_iCombatModifierEnemyCities;
	kStream >> m_iCombatModifierFriendlyCities;
	kStream >> m_iFriendlyHealChange;
	kStream >> m_iCityStateFriendshipModifier;
	kStream >> m_iLandBarbarianConversionPercent;
	kStream >> m_iSpreadStrengthModifier;
	kStream >> m_iSpreadDistanceModifier;
	kStream >> m_iProphetStrengthModifier;
	kStream >> m_iProphetCostModifier;
	kStream >> m_iMissionaryStrengthModifier;
	kStream >> m_iMissionaryCostModifier;
	kStream >> m_iFriendlyCityStateSpreadModifier;
	kStream >> m_iGreatPersonExpendedFaith;
	kStream >> m_iCityStateMinimumInfluence;
	kStream >> m_iCityStateInfluenceModifier;
	kStream >> m_iOtherReligionPressureErosion;
	kStream >> m_iSpyPressure;
	kStream >> m_iInquisitorPressureRetention;
	if (uiVersion >= 2)
	{
		kStream >> m_iFaithBuildingTourism;
	}
	else
	{
		m_iFaithBuildingTourism = 0;
	}

#if defined(MOD_BELIEF_NEW_EFFECT_FOR_SP)
	kStream >> m_iGoldenAgeModifier;
	kStream >> m_iExtraSpies;
	kStream >> m_bGreatPersonPoints;
	kStream >> m_vFreePromotionForProphet;
	kStream >> m_iFounderFreePromotion;
	kStream >> m_vFollowingCityFreePromotion;
	kStream >> m_iLandmarksTourismPercent;
	kStream >> m_iHolyCityUnitExperence;
	kStream >> m_iHolyCityPressureModifier;
	kStream >> m_iSameReligionMinorRecoveryModifier;
	kStream >> m_iInquisitionFervorTimeModifier;
	kStream >> m_iNumInquisitorProhibitSpreadInAlly;
	kStream >> m_iCuttingBonusModifier;
	kStream >> m_iCityExtraMissionarySpreads;
	kStream >> m_bAllowYieldPerBirth;
#endif
	kStream >> m_vImprovementYieldChanges;
	kStream >> m_vImprovementAdjacentCityYieldChanges;

	kStream >> m_eObsoleteEra;
	kStream >> m_eResourceRevealed;
	kStream >> m_eSpreadModifierDoublingTech;

	m_ReligionBeliefs.clear();
	uint uiBeliefCount;
	kStream >> uiBeliefCount;
	while(uiBeliefCount--)
	{
		int iBeliefIndex = CvInfosSerializationHelper::ReadHashed(kStream);
		m_ReligionBeliefs.push_back(iBeliefIndex);
	}

	BuildingClassArrayHelpers::Read(kStream, m_paiBuildingClassEnabled);
}

/// Serialization write
void CvReligionBeliefs::Write(FDataStream& kStream) const
{
	// Current version number
	uint uiVersion = 2;
	kStream << uiVersion;
	MOD_SERIALIZE_INIT_WRITE(kStream);

	kStream << m_iFaithFromDyingUnits;
	kStream << m_iRiverHappiness;
	kStream << m_iPlotCultureCostModifier;
	kStream << m_iCityRangeStrikeModifier;
	kStream << m_iCombatModifierEnemyCities;
	kStream << m_iCombatModifierFriendlyCities;
	kStream << m_iFriendlyHealChange;
	kStream << m_iCityStateFriendshipModifier;
	kStream << m_iLandBarbarianConversionPercent;
	kStream << m_iSpreadStrengthModifier;
	kStream << m_iSpreadDistanceModifier;
	kStream << m_iProphetStrengthModifier;
	kStream << m_iProphetCostModifier;
	kStream << m_iMissionaryStrengthModifier;
	kStream << m_iMissionaryCostModifier;
	kStream << m_iFriendlyCityStateSpreadModifier;
	kStream << m_iGreatPersonExpendedFaith;
	kStream << m_iCityStateMinimumInfluence;
	kStream << m_iCityStateInfluenceModifier;
	kStream << m_iOtherReligionPressureErosion;
	kStream << m_iSpyPressure;
	kStream << m_iInquisitorPressureRetention;
	kStream << m_iFaithBuildingTourism;

#if defined(MOD_BELIEF_NEW_EFFECT_FOR_SP)
	kStream << m_iGoldenAgeModifier;
	kStream << m_iExtraSpies;
	kStream << m_bGreatPersonPoints;
	kStream << m_vFreePromotionForProphet;
	kStream << m_iFounderFreePromotion;
	kStream << m_vFollowingCityFreePromotion;
	kStream << m_iLandmarksTourismPercent;
	kStream << m_iHolyCityUnitExperence;
	kStream << m_iHolyCityPressureModifier;
	kStream << m_iSameReligionMinorRecoveryModifier;
	kStream << m_iInquisitionFervorTimeModifier;
	kStream << m_iNumInquisitorProhibitSpreadInAlly;
	kStream << m_iCuttingBonusModifier;
	kStream << m_iCityExtraMissionarySpreads;
	kStream << m_bAllowYieldPerBirth;
#endif
	kStream << m_vImprovementYieldChanges;
	kStream << m_vImprovementAdjacentCityYieldChanges;

	kStream << m_eObsoleteEra;
	kStream << m_eResourceRevealed;
	kStream << m_eSpreadModifierDoublingTech;

	// m_ReligionBeliefs contains the BeliefTypes, which are indices into the religion info table (GC.getBeliefInfo).  Write out the info hashes
	kStream << m_ReligionBeliefs.size();
	for (uint i = 0; i < m_ReligionBeliefs.size(); ++i)
	{
		CvInfosSerializationHelper::WriteHashed(kStream, (BeliefTypes)m_ReligionBeliefs[i]);
	}

	BuildingClassArrayHelpers::Write(kStream, m_paiBuildingClassEnabled, GC.getNumBuildingClassInfos());
}

/// BELIEF HELPER CLASSES

/// Is there an adjacent barbarian naval unit that could be converted?
#if defined(MOD_EVENTS_UNIT_CAPTURE)
bool CvBeliefHelpers::ConvertBarbarianUnit(const CvUnit *pByUnit, UnitHandle pUnit)
#else
bool CvBeliefHelpers::ConvertBarbarianUnit(CvPlayer *pPlayer, UnitHandle pUnit)
#endif
{
	UnitHandle pNewUnit;
	CvPlot *pPlot = pUnit->plot();

#if defined(MOD_EVENTS_UNIT_CAPTURE)
	CvPlayer* pPlayer = &GET_PLAYER(pByUnit->getOwner());

	if (MOD_EVENTS_UNIT_CAPTURE) {
		GAMEEVENTINVOKE_HOOK(GAMEEVENT_UnitCaptured, pPlayer->GetID(), pByUnit->GetID(), pUnit->getOwner(), pUnit->GetID(), false, 4);
	}
#endif

	// Convert the barbarian into our unit
	pNewUnit = pPlayer->initUnit(pUnit->getUnitType(), pUnit->getX(), pUnit->getY(), pUnit->AI_getUnitAIType(), NO_DIRECTION, true /*bNoMove*/, false);
	CvAssertMsg(pNewUnit, "pNewUnit is not assigned a valid value");
	pNewUnit->convert(pUnit.pointer(), false);
	pNewUnit->setupGraphical();
	pNewUnit->finishMoves(); // No move first turn

	if(GC.getLogging() && GC.getAILogging())
	{
		CvString logMsg;
		logMsg.Format("Converted barbarian (with belief), X: %d, Y: %d", pUnit->getX(), pUnit->getY());
		pPlayer->GetHomelandAI()->LogHomelandMessage(logMsg);
	}

	CvString strBuffer = GetLocalizedText("TXT_KEY_NOTIFICATION_HEATHEN_CONVERTS");
	CvString strSummary = GetLocalizedText("TXT_KEY_NOTIFICATION_SUMMARY_HEATHEN_CONVERTS");
	pPlayer->GetNotifications()->Add(NOTIFICATION_GENERIC, strBuffer, strSummary, pUnit->getX(), pUnit->getY(), -1);

	if (pPlot->getImprovementType() == GC.getBARBARIAN_CAMP_IMPROVEMENT())
	{
		pPlot->setImprovementType(NO_IMPROVEMENT);

		CvBarbarians::DoBarbCampCleared(pPlot, pPlayer->GetID());
		pPlot->SetPlayerThatClearedBarbCampHere(pPlayer->GetID());

		// Don't give gold for Camps cleared by heathen conversion
	}

	return true;
}
