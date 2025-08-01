/*	-------------------------------------------------------------------------------------------------------
	© 1991-2012 Take-Two Interactive Software and its subsidiaries.  Developed by Firaxis Games.  
	Sid Meier's Civilization V, Civ, Civilization, 2K Games, Firaxis Games, Take-Two Interactive Software 
	and their respective logos are all trademarks of Take-Two interactive Software, Inc.  
	All other marks and trademarks are the property of their respective owners.  
	All rights reserved. 
	------------------------------------------------------------------------------------------------------- */

#include "CvGameCoreDLLPCH.h"
#include "CvLuaSupport.h"
#include "CvLuaArea.h"
#include "CvLuaCity.h"
#include "CvLuaPlot.h"
#include "CvLuaUnit.h"
#include "NetworkMessageUtil.h"
#include <CvGameCoreUtils.h>

//Utility macro for registering methods
#define Method(Name)			\
	lua_pushcclosure(L, l##Name, 0);	\
	lua_setfield(L, t, #Name);


using namespace CvLuaArgs;
void CvLuaCity::RegistStaticFunctions() {
	REGIST_STATIC_FUNCTION(CvLuaCity::lKill);
	REGIST_STATIC_FUNCTION(CvLuaCity::lSetMadeAttack);
	REGIST_STATIC_FUNCTION(CvLuaCity::lClearOrderQueue);
	REGIST_STATIC_FUNCTION(CvLuaCity::lClearWorkingOverride);
	REGIST_STATIC_FUNCTION(CvLuaCity::lClearGreatWorks);

	REGIST_STATIC_FUNCTION(CvLuaCity::lDoTask);

	REGIST_STATIC_FUNCTION(CvLuaCity::lPushOrder);

	REGIST_STATIC_FUNCTION(CvLuaCity::lSetResourceDemanded);
	REGIST_STATIC_FUNCTION(CvLuaCity::lSetProduction);
	REGIST_STATIC_FUNCTION(CvLuaCity::lSetPopulation);
	REGIST_STATIC_FUNCTION(CvLuaCity::lSetHighestPopulation);
	REGIST_STATIC_FUNCTION(CvLuaCity::lSetJONSCultureStored);
	REGIST_STATIC_FUNCTION(CvLuaCity::lSetJONSCultureLevel);
	REGIST_STATIC_FUNCTION(CvLuaCity::lSetFood);
	REGIST_STATIC_FUNCTION(CvLuaCity::lSetOverflowProduction);
	REGIST_STATIC_FUNCTION(CvLuaCity::lSetFeatureProduction);
	REGIST_STATIC_FUNCTION(CvLuaCity::lSetOccupied);
	REGIST_STATIC_FUNCTION(CvLuaCity::lSetPuppet);
	REGIST_STATIC_FUNCTION(CvLuaCity::lSetNeverLost);
	REGIST_STATIC_FUNCTION(CvLuaCity::lSetDrafted);
	REGIST_STATIC_FUNCTION(CvLuaCity::lSetWeLoveTheKingDayCounter);
	REGIST_STATIC_FUNCTION(CvLuaCity::lSetProductionAutomated);
	REGIST_STATIC_FUNCTION(CvLuaCity::lSetCitySizeBoost);
	REGIST_STATIC_FUNCTION(CvLuaCity::lSetRevealed);
	REGIST_STATIC_FUNCTION(CvLuaCity::lSetName);
	REGIST_STATIC_FUNCTION(CvLuaCity::lSetBuildingProduction);
	REGIST_STATIC_FUNCTION(CvLuaCity::lSetBuildingProductionTime);
	REGIST_STATIC_FUNCTION(CvLuaCity::lSetUnitProduction);
	REGIST_STATIC_FUNCTION(CvLuaCity::lSetFocusType);
	REGIST_STATIC_FUNCTION(CvLuaCity::lSetDamage);
	REGIST_STATIC_FUNCTION(CvLuaCity::lSetNumRealBuilding);
	REGIST_STATIC_FUNCTION(CvLuaCity::lSetBuildingGreatWork);
	REGIST_STATIC_FUNCTION(CvLuaCity::lSetBuildingYieldChange);
	REGIST_STATIC_FUNCTION(CvLuaCity::lChangeProduction);
	REGIST_STATIC_FUNCTION(CvLuaCity::lChangePopulation);
	REGIST_STATIC_FUNCTION(CvLuaCity::lChangeBaseGreatPeopleRate);
	REGIST_STATIC_FUNCTION(CvLuaCity::lChangeJONSCultureStored);
	REGIST_STATIC_FUNCTION(CvLuaCity::lChangeJONSCultureLevel);
	REGIST_STATIC_FUNCTION(CvLuaCity::lChangeJONSCulturePerTurnFromBuildings);
	REGIST_STATIC_FUNCTION(CvLuaCity::lChangeJONSCulturePerTurnFromPolicies);
	REGIST_STATIC_FUNCTION(CvLuaCity::lChangeJONSCulturePerTurnFromSpecialists);
	REGIST_STATIC_FUNCTION(CvLuaCity::lChangeJONSCulturePerTurnFromReligion);
	REGIST_STATIC_FUNCTION(CvLuaCity::lChangeCultureRateModifier);
	REGIST_STATIC_FUNCTION(CvLuaCity::lChangeFaithPerTurnFromReligion);
	REGIST_STATIC_FUNCTION(CvLuaCity::lChangeWonderProductionModifier);
	REGIST_STATIC_FUNCTION(CvLuaCity::lChangeHealRate);
	REGIST_STATIC_FUNCTION(CvLuaCity::lChangeFood);
	REGIST_STATIC_FUNCTION(CvLuaCity::lChangeResistanceTurns);
	REGIST_STATIC_FUNCTION(CvLuaCity::lChangeRazingTurns);
	REGIST_STATIC_FUNCTION(CvLuaCity::lChangeWeLoveTheKingDayCounter);
	REGIST_STATIC_FUNCTION(CvLuaCity::lChangeBaseYieldRateFromTerrain);
	REGIST_STATIC_FUNCTION(CvLuaCity::lChangeBaseYieldRateFromBuildings);
	REGIST_STATIC_FUNCTION(CvLuaCity::lChangeBaseYieldRateFromSpecialists);
	REGIST_STATIC_FUNCTION(CvLuaCity::lChangeBaseYieldRateFromMisc);
	REGIST_STATIC_FUNCTION(CvLuaCity::lChangeBaseYieldRateFromReligion);
	REGIST_STATIC_FUNCTION(CvLuaCity::lChangeBuildingProduction);
	REGIST_STATIC_FUNCTION(CvLuaCity::lChangeBuildingProductionTime);
	REGIST_STATIC_FUNCTION(CvLuaCity::lChangeUnitProduction);
	REGIST_STATIC_FUNCTION(CvLuaCity::lChangeSpecialistGreatPersonProgressTimes100);
	REGIST_STATIC_FUNCTION(CvLuaCity::lChangeDamage);
}
//------------------------------------------------------------------------------
void CvLuaCity::PushMethods(lua_State* L, int t)
{
	Method(GetAdditionalFood);
	Method(SetAdditionalFood);
	Method(SetMadeAttack);

#if defined(MOD_API_UNIFIED_YIELDS_MORE)

	Method(GetOrganizedCrime);
	Method(SetOrganizedCrime);
	Method(HasOrganizedCrime);

	Method(ChangeResistanceCounter);
	Method(SetResistanceCounter);
	Method(GetResistanceCounter);

	Method(ChangePlagueCounter);
	Method(SetPlagueCounter);
	Method(GetPlagueCounter);

	Method(GetPlagueTurns);
	Method(ChangePlagueTurns);
	Method(SetPlagueTurns);

	Method(GetPlagueType);
	Method(SetPlagueType);
	Method(HasPlague);

	Method(ChangeLoyaltyCounter);
	Method(SetLoyaltyCounter);
	Method(GetLoyaltyCounter);

	Method(ChangeDisloyaltyCounter);
	Method(SetDisloyaltyCounter);
	Method(GetDisloyaltyCounter);

	Method(GetLoyaltyState);
	Method(SetLoyaltyState);
	Method(HasLoyaltyState);

	Method(GetYieldModifierFromHealth);
	Method(SetYieldModifierFromHealth);

	Method(GetYieldModifierFromCrime);
	Method(SetYieldModifierFromCrime);
	Method(GetYieldFromHappiness);
	Method(SetYieldFromHappiness);
	Method(GetYieldFromHealth);
	Method(SetYieldFromHealth);

	Method(GetYieldFromCrime);
	Method(SetYieldFromCrime);
#endif

	Method(SendAndExecuteLuaFunction);
	Method(SendAndExecuteLuaFunctionPostpone);

	Method(IsNone);
	Method(Kill);

	Method(CreateGreatGeneral);
	Method(CreateGreatAdmiral);

	Method(DoTask);
	Method(ChooseProduction);
	Method(GetCityPlotIndex);
	Method(GetCityIndexPlot);
	Method(CanWork);
	Method(IsPlotBlockaded);
	Method(ClearWorkingOverride);
	Method(CountNumImprovedPlots);
	Method(CountNumWaterPlots);
	Method(CountNumRiverPlots);

	Method(FindPopulationRank);
	Method(FindBaseYieldRateRank);
	Method(FindYieldRateRank);

	Method(AllUpgradesAvailable);
	Method(IsWorldWondersMaxed);
	Method(IsTeamWondersMaxed);
	Method(IsNationalWondersMaxed);
	Method(IsBuildingsMaxed);

	Method(CanTrainTooltip);
	Method(CanTrain);
	Method(CanConstructTooltip);
	Method(CanConstruct);
	Method(CanCreate);
	Method(CanPrepare);
	Method(CanMaintain);

	Method(GetPurchaseUnitTooltip);
	Method(GetFaithPurchaseUnitTooltip);
	Method(GetPurchaseBuildingTooltip);
	Method(GetFaithPurchaseBuildingTooltip);

	Method(CanJoin);
	Method(IsBuildingLocalResourceValid);

	Method(GetResourceDemanded);
	Method(SetResourceDemanded);
	Method(DoPickResourceDemanded);

	Method(GetFoodTurnsLeft);
	Method(IsProduction);
	Method(IsProductionLimited);
	Method(IsProductionUnit);
	Method(IsProductionBuilding);
	Method(IsProductionProject);
	Method(IsProductionSpecialist);
	Method(IsProductionProcess);

	Method(CanContinueProduction);
	Method(GetProductionExperience);
	Method(AddProductionExperience);

	Method(GetProductionUnit);
	Method(GetProductionUnitAI);
	Method(GetProductionBuilding);
	Method(GetProductionProject);
	Method(GetProductionSpecialist);
	Method(GetProductionProcess);
	//Method(GetProductionName);
	Method(GetProductionNameKey);
	Method(GetGeneralProductionTurnsLeft);
	Method(IsFoodProduction);
	Method(GetFirstUnitOrder);
	Method(GetFirstProjectOrder);
	Method(GetFirstSpecialistOrder);

	Method(GetOrderFromQueue);

	Method(GetNumTrainUnitAI);
	Method(GetFirstBuildingOrder);
	Method(IsUnitFoodProduction);
	Method(GetProduction);
	Method(GetProductionTimes100);
	Method(GetProductionNeeded);
	Method(GetUnitProductionNeeded);
	Method(GetBuildingProductionNeeded);
	Method(GetProjectProductionNeeded);
	Method(GetProductionTurnsLeft);
	Method(GetUnitProductionTurnsLeft);
	Method(GetBuildingProductionTurnsLeft);
	Method(GetProjectProductionTurnsLeft);
	Method(GetSpecialistProductionTurnsLeft);
#if defined(MOD_API_LUA_EXTENSIONS) && defined(MOD_PROCESS_STOCKPILE)
	Method(GetProcessProductionTurnsLeft);
#endif



	Method(CreateApolloProgram);

	Method(IsCanPurchase);
#if defined(MOD_API_LUA_EXTENSIONS)
	Method(Purchase);
#endif
	Method(GetNumTimesAttackedThisTurn);
	Method(GetUnitPurchaseCost);
	Method(GetUnitFaithPurchaseCost);
	Method(GetBuildingPurchaseCost);
	Method(GetBuildingFaithPurchaseCost);
	Method(GetProjectPurchaseCost);

	Method(SetProduction);
	Method(ChangeProduction);

	Method(GetYieldModifierTooltip);
	Method(GetProductionModifier);

	Method(GetCurrentProductionDifference);
	Method(GetRawProductionDifference);
	Method(GetCurrentProductionDifferenceTimes100);
	Method(GetRawProductionDifferenceTimes100);
	Method(GetUnitProductionModifier);
	Method(GetBuildingProductionModifier);
	Method(GetProjectProductionModifier);
	Method(GetSpecialistProductionModifier);

	Method(GetExtraProductionDifference);

	Method(CanHurry);
	Method(Hurry);
	Method(GetConscriptUnit);
	Method(GetConscriptPopulation);
	Method(ConscriptMinCityPopulation);
	Method(CanConscript);
	Method(Conscript);
	Method(GetResourceYieldRateModifier);
	Method(GetHandicapType);
	Method(GetCivilizationType);
	Method(GetPersonalityType);
	Method(GetArtStyleType);
	Method(GetCitySizeType);

	Method(IsBarbarian);
	Method(IsHuman);
	Method(IsVisible);

	Method(IsCapital);
	Method(IsOriginalCapital);
	Method(IsOriginalMajorCapital);
	Method(IsCoastal);
#if defined(MOD_API_LUA_EXTENSIONS)
	Method(IsAddsFreshWater);
#endif

	Method(FoodConsumption);
	Method(FoodDifference);
	Method(FoodDifferenceTimes100);
	Method(GrowthThreshold);
	Method(ProductionLeft);
	Method(HurryCost);
	Method(HurryGold);
	Method(HurryPopulation);
	Method(HurryProduction);
	Method(MaxHurryPopulation);

	Method(GetNumBuilding);
	Method(IsHasBuilding);
#if defined(MOD_API_LUA_EXTENSIONS)
	Method(GetNumBuildingClass);
	Method(IsHasBuildingClass);
	Method(SetNumRealBuildingClass);
#endif
	Method(GetLocalBuildingClassYield);

	Method(GetNumActiveBuilding);
	Method(GetID);
	Method(GetX);
	Method(GetY);
#if defined(MOD_API_LUA_EXTENSIONS)
	Method(GetXY);
#endif
	Method(At);
	Method(AtPlot);
	Method(Plot);
	Method(Area);
	Method(WaterArea);
	Method(GetRallyPlot);

	Method(CanBuyPlot);
	Method(CanBuyPlotAt);
	Method(GetNextBuyablePlot);
	Method(GetBuyablePlotList);
	Method(GetBuyPlotCost);
	Method(CanBuyAnyPlot);

	Method(GetGarrisonedUnit);

	Method(GetGameTurnFounded);
	Method(GetGameTurnAcquired);
	Method(GetGameTurnLastExpanded);
	Method(GetPopulation);
	Method(SetPopulation);
	Method(ChangePopulation);
	Method(GetRealPopulation);

#if defined(MOD_API_LUA_EXTENSIONS) && defined(MOD_GLOBAL_CITY_AUTOMATON_WORKERS)
	Method(GetAutomatons);
	Method(SetAutomatons);
#endif


#if defined(MOD_ROG_CORE)
	Method(GetForcedDamageValue);
	Method(GetChangeDamageValue);
#endif

	Method(GetHighestPopulation);
	Method(SetHighestPopulation);
	//Method(GetWorkingPopulation);
	//Method(GetSpecialistPopulation);
	Method(GetNumGreatPeople);
	Method(GetBaseGreatPeopleRate);
	Method(GetGreatPeopleRate);
	Method(GetTotalGreatPeopleRateModifier);
	Method(ChangeBaseGreatPeopleRate);
	Method(GetGreatPeopleRateModifier);

	Method(GetJONSCultureStored);
	Method(SetJONSCultureStored);
	Method(ChangeJONSCultureStored);
	Method(GetJONSCultureLevel);
	Method(SetJONSCultureLevel);
	Method(ChangeJONSCultureLevel);
	Method(DoJONSCultureLevelIncrease);
	Method(GetJONSCultureThreshold);

	Method(GetJONSCulturePerTurn);

	Method(GetBaseJONSCulturePerTurn);
	Method(GetJONSCulturePerTurnFromBuildings);
	Method(ChangeJONSCulturePerTurnFromBuildings);
	Method(GetJONSCulturePerTurnFromPolicies);
	Method(ChangeJONSCulturePerTurnFromPolicies);
	Method(GetJONSCulturePerTurnFromSpecialists);
	Method(ChangeJONSCulturePerTurnFromSpecialists);
	Method(GetJONSCulturePerTurnFromGreatWorks);
	Method(GetJONSCulturePerTurnFromTraits);
	Method(GetJONSCulturePerTurnFromReligion);
#if defined(MOD_BUGFIX_LUA_API)
	Method(ChangeJONSCulturePerTurnFromReligion);
#endif
	Method(GetJONSCulturePerTurnFromLeagues);

	Method(GetCultureRateModifier);
	Method(ChangeCultureRateModifier);

#if defined(MOD_API_LUA_EXTENSIONS)
	Method(GetTourismRateModifier);
	Method(ChangeTourismRateModifier);
#endif

	Method(GetNumGreatWorks);
	Method(GetNumGreatWorkSlots);
	Method(GetBaseTourism);
	Method(GetTourismMultiplier);
	Method(GetTourismTooltip);
	Method(GetFilledSlotsTooltip);
	Method(GetTotalSlotsTooltip);
	Method(ClearGreatWorks);
	Method(GetFaithBuildingTourism);

	Method(IsThemingBonusPossible);
	Method(GetThemingBonus);
	Method(GetThemingTooltip);

	Method(GetFaithPerTurn);
	Method(GetFaithPerTurnFromBuildings);
	Method(GetFaithPerTurnFromPolicies);
	Method(GetFaithPerTurnFromTraits);
	Method(GetFaithPerTurnFromReligion);
	Method(ChangeFaithPerTurnFromReligion);

	Method(IsReligionInCity);
	Method(IsHolyCityForReligion);
	Method(IsHolyCityAnyReligion);
	Method(GetReligionFoundedHere);

	Method(GetNumFollowers);
	Method(GetReligiousMajority);
	Method(GetSecondaryReligion);
	Method(GetSecondaryReligionPantheonBelief);
	Method(GetPressurePerTurn);
	Method(ConvertPercentFollowers);
	Method(AdoptReligionFully);
	Method(GetReligionBuildingClassHappiness);
	Method(GetReligionBuildingClassYieldChange);
	Method(GetLeagueBuildingClassYieldChange);
	Method(GetNumTradeRoutesAddingPressure);

	Method(GetNumWorldWonders);
	Method(GetNumTeamWonders);
	Method(GetNumNationalWonders);
	Method(GetNumBuildings);

	Method(GetWonderProductionModifier);
	Method(ChangeWonderProductionModifier);

	Method(GetLocalResourceWonderProductionMod);

#if defined(MOD_API_LUA_EXTENSIONS) && defined(MOD_GLOBAL_CITY_WORKING)
	Method(GetBuyPlotDistance);
	Method(GetWorkPlotDistance);
#endif
#if defined(MOD_API_LUA_EXTENSIONS) && defined(MOD_BUILDINGS_CITY_WORKING)
	Method(GetCityWorkingChange);
	Method(ChangeCityWorkingChange);
#endif

#if defined(MOD_API_LUA_EXTENSIONS) && defined(MOD_BUILDINGS_CITY_AUTOMATON_WORKERS)
	Method(GetCityAutomatonWorkersChange);
	Method(ChangeCityAutomatonWorkersChange);
#endif

	Method(ChangeHealRate);

	Method(IsNoOccupiedUnhappiness);

	Method(GetFood);
	Method(GetFoodTimes100);
	Method(SetFood);
	Method(ChangeFood);
	Method(GetFoodKept);
	Method(GetMaxFoodKeptPercent);
	Method(GetOverflowProduction);
	Method(SetOverflowProduction);
#if defined(MOD_API_LUA_EXTENSIONS)
	Method(ChangeOverflowProduction);
#endif
	Method(GetFeatureProduction);
	Method(SetFeatureProduction);
	Method(GetMilitaryProductionModifier);
	Method(GetSpaceProductionModifier);
	Method(GetBuildingDefense);
	Method(GetFreeExperience);
	Method(GetNukeModifier);
	//Method(GetFreeSpecialist);

	Method(IsResistance);
	Method(GetResistanceTurns);
	Method(ChangeResistanceTurns);

	Method(IsRazing);
	Method(GetRazingTurns);
	Method(ChangeRazingTurns);

	Method(IsOccupied);

	Method(SetOccupied);

	Method(IsPuppet);

	Method(SetPuppet);

	Method(GetHappinessFromBuildings);
	Method(GetHappiness);
	Method(GetLocalHappiness);

	Method(IsNeverLost);
	Method(SetNeverLost);
	Method(IsDrafted);
	Method(SetDrafted);

	Method(IsBlockaded);

	Method(GetWeLoveTheKingDayCounter);
	Method(SetWeLoveTheKingDayCounter);
	Method(ChangeWeLoveTheKingDayCounter);

	Method(GetNumThingsProduced);

	Method(IsProductionAutomated);
	Method(SetProductionAutomated);
	Method(SetCitySizeBoost);
	Method(GetOwner);
	Method(GetTeam);
	Method(GetPreviousOwner);
	Method(GetOriginalOwner);
	Method(GetSeaPlotYield);
	Method(GetRiverPlotYield);
	Method(GetLakePlotYield);

	Method(GetBaseYieldRate);
	Method(GetYieldRateInfoTool);
	Method(GetBaseYieldRateFromProjects);
	Method(GetYieldPerEra);
	Method(GetTradeRouteFromTheCityYieldsPerEra);
#if defined(MOD_API_LUA_EXTENSIONS) && defined(MOD_GLOBAL_GREATWORK_YIELDTYPES)
	Method(GetBaseYieldRateFromGreatWorks);
#endif
	Method(GetBaseYieldRateFromPolicy);

	Method(GetBaseYieldRateFromTerrain);
	Method(ChangeBaseYieldRateFromTerrain);

	Method(GetBaseYieldRateFromBuildings);
	Method(ChangeBaseYieldRateFromBuildings);

	Method(GetBaseYieldRateFromSpecialists);
	Method(ChangeBaseYieldRateFromSpecialists);

	Method(GetBaseYieldRateFromMisc);
	Method(ChangeBaseYieldRateFromMisc);

	Method(GetBaseYieldRateFromReligion);
	Method(ChangeBaseYieldRateFromReligion);

	Method(GetYieldPerPopTimes100);

	Method(GetBaseYieldRateModifier);
	Method(GetYieldRate);
	Method(GetYieldRateTimes100);
	Method(GetYieldRateModifier);

	Method(GetExtraSpecialistYield);
	Method(GetExtraSpecialistYieldOfType);

	Method(GetDomainFreeExperience);
	Method(GetDomainFreeExperienceFromGreatWorks);
	Method(GetDomainFreeExperienceFromGreatWorksGlobal);
	Method(GetDomainProductionModifier);

	Method(IsEverOwned);

	Method(IsRevealed);
	Method(SetRevealed);
	Method(GetNameKey);
	Method(GetName);
	Method(SetName);
	Method(IsHasResourceLocal);
	Method(GetBuildingProduction);
	Method(SetBuildingProduction);
	Method(ChangeBuildingProduction);
	Method(GetBuildingProductionTime);
	Method(SetBuildingProductionTime);
	Method(ChangeBuildingProductionTime);
	Method(GetBuildingOriginalOwner);
	Method(GetBuildingOriginalTime);
	Method(GetUnitProduction);
	Method(SetUnitProduction);
	Method(ChangeUnitProduction);

	Method(IsCanAddSpecialistToBuilding);
	Method(GetSpecialistUpgradeThreshold);
	Method(GetNumSpecialistsAllowedByBuilding);
	Method(GetSpecialistCount);
	Method(GetProjectCount);
	Method(GetTotalSpecialistCount);
	Method(GetSpecialistCityModifier);
	Method(GetSpecialistGreatPersonProgress);
	Method(GetSpecialistGreatPersonProgressTimes100);
	Method(ChangeSpecialistGreatPersonProgressTimes100);
	Method(GetNumSpecialistsInBuilding);
	Method(DoReallocateCitizens);
	Method(DoVerifyWorkingPlots);
	Method(IsNoAutoAssignSpecialists);
#if defined(MOD_BELIEF_NEW_EFFECT_FOR_SP)
	Method(GetGreatPersonPointFromReligion);
#endif
#if defined(MOD_TROOPS_AND_CROPS_FOR_SP)
	Method(HasEnableCrops);
	Method(HasEnableArmee);
#endif
	Method(GetFocusType);
	Method(SetFocusType);

	Method(IsForcedAvoidGrowth);

	Method(GetUnitCombatFreeExperience);
	Method(GetFreePromotionCount);
	Method(IsFreePromotion);
	Method(GetSpecialistFreeExperience);

	Method(UpdateStrengthValue);
	Method(GetStrengthValue);

	Method(GetDamage);
	Method(SetDamage);
	Method(ChangeDamage);
	Method(GetMaxHitPoints);
#if defined(MOD_EVENTS_CITY_BOMBARD)
	Method(GetBombardRange);
#endif
	Method(CanRangeStrike);
	Method(CanRangeStrikeNow);
	Method(CanRangeStrikeAt);
	Method(HasPerformedRangedStrikeThisTurn);
	Method(RangeCombatUnitDefense);
	Method(RangeCombatDamage);
	Method(GetAirStrikeDefenseDamage);

	Method(IsWorkingPlot);
	Method(AlterWorkingPlot);
	Method(IsForcedWorkingPlot);
	Method(SetForcedWorkingPlot);
	Method(GetNumRealBuilding);

	Method(SetNumRealBuilding);


	Method(GetNumFreeBuilding);
#if defined(MOD_API_LUA_EXTENSIONS)
	Method(SetNumFreeBuilding);
#endif
	Method(IsBuildingSellable);
	Method(GetSellBuildingRefund);
	Method(GetTotalBaseBuildingMaintenance);
	Method(GetBuildingGreatWork);
	Method(SetBuildingGreatWork);
	Method(IsHoldingGreatWork);
	Method(GetNumGreatWorksInBuilding);

	Method(ClearOrderQueue);
	Method(PushOrder);
	Method(PopOrder);
	Method(GetOrderQueueLength);

	Method(GetBuildingYieldChange);
	Method(SetBuildingYieldChange);

	Method(GetBuildingEspionageModifier);
	Method(GetBuildingGlobalEspionageModifier);

#if defined(MOD_API_LUA_EXTENSIONS) && defined(MOD_API_ESPIONAGE)
	Method(HasDiplomat);
	Method(HasSpy);
	Method(HasCounterSpy);
	Method(GetCounterSpy);
#endif

#if defined(MOD_API_LUA_EXTENSIONS) && defined(MOD_RELIGION_CONVERSION_MODIFIERS)
	Method(GetBuildingConversionModifier);
	Method(GetBuildingGlobalConversionModifier);
#endif

	Method(GetNumCityPlots);
	Method(CanPlaceUnitHere);

	Method(GetSpecialistYield);
	Method(GetCultureFromSpecialist);

	Method(GetNumForcedWorkingPlots);

	Method(GetReligionCityRangeStrikeModifier);

#if defined(MOD_API_LUA_EXTENSIONS)
	Method(AddMessage);
#endif

#ifdef MOD_BUILDINGS_YIELD_FROM_OTHER_YIELD
	Method(GetBaseYieldRateFromOtherYield);
#endif

#if defined(MOD_API_LUA_EXTENSIONS)
	Method(HasBelief);
	Method(HasBuilding);
	Method(HasBuildingClass);
	Method(HasAnyWonder);
	Method(HasWonder);
	Method(IsCivilization);
	Method(HasFeature);
	Method(HasWorkedFeature);
	Method(HasAnyNaturalWonder);
	Method(HasNaturalWonder);
	Method(HasImprovement);
	Method(HasWorkedImprovement);
	Method(HasPlotType);
	Method(HasWorkedPlotType);
	Method(HasAnyReligion);
	Method(HasReligion);
	Method(HasResource);
	Method(HasWorkedResource);
	Method(IsConnectedToCapital);
	Method(IsConnectedTo);
	Method(HasSpecialistSlot);
	Method(HasSpecialist);
	Method(HasTerrain);
	Method(HasWorkedTerrain);
	Method(HasAnyDomesticTradeRoute);
	Method(HasAnyInternationalTradeRoute);
	Method(HasTradeRouteToAnyCity);
	Method(HasTradeRouteTo);
	Method(HasTradeRouteFromAnyCity);
	Method(HasTradeRouteFrom);
	Method(IsOnFeature);
	Method(IsAdjacentToFeature);
	Method(IsWithinDistanceOfFeature);
	Method(IsOnImprovement);
	Method(IsAdjacentToImprovement);
	Method(IsWithinDistanceOfImprovement);
	Method(IsOnPlotType);
	Method(IsAdjacentToPlotType);
	Method(IsWithinDistanceOfPlotType);
	Method(IsOnResource);
	Method(IsAdjacentToResource);
	Method(IsWithinDistanceOfResource);
	Method(IsOnTerrain);
	Method(IsAdjacentToTerrain);
	Method(IsWithinDistanceOfTerrain);
	Method(CountFeature);
	Method(CountWorkedFeature);
	Method(CountImprovement);
	Method(CountWorkedImprovement);
	Method(CountPlotType);
	Method(CountWorkedPlotType);
	Method(CountResource);
	Method(CountWorkedResource);
	Method(CountTerrain);
	Method(CountWorkedTerrain);
#endif

#ifdef MOD_API_RELIGION_EXTENSIONS
	Method(GetMajorReligionPantheonBelief);
	Method(IsHasMajorBelief);
	Method(IsHasSecondaryBelief);
	Method(IsSecondaryReligionActive);
#endif

#if defined(MOD_INTERNATIONAL_IMMIGRATION_FOR_SP)
	Method(IsCanDoImmigration);
	Method(SetCanDoImmigration);
	Method(CanImmigrantIn);
	Method(CanImmigrantOut);
#endif
#ifdef MOD_GLOBAL_CITY_SCALES
	Method(GetScale);
	Method(CanGrowNormally);
#endif

#ifdef MOD_GLOBAL_CORRUPTION
	Method(GetCorruptionScore);
	Method(GetCorruptionLevel);
	Method(UpdateCorruption);
	Method(CalculateTotalCorruptionScore);
	Method(CalculateCorruptionScoreFromDistance);
	Method(CalculateCorruptionScoreFromCoastalBonus);
	Method(CalculateCorruptionScoreModifierFromSpy);
	Method(CalculateCorruptionScoreModifierFromTrait);
	Method(GetCorruptionScoreChangeFromBuilding);
	Method(GetCorruptionLevelChangeFromBuilding);
	Method(CalculateCorruptionScoreFromResource);
	Method(CalculateCorruptionScoreFromTrait);
	Method(GetCorruptionScoreModifierFromPolicy);
	Method(DecideCorruptionLevelForNormalCity);
	Method(GetMaxCorruptionLevel);
	Method(IsCorruptionLevelReduceByOne);
#endif
	Method(GetHurryModifier);
	Method(GetHurryModifierLocal);
	Method(GetUnitMaxExperienceLocal);
	Method(IsSecondCapital);
	Method(GetFoodConsumptionPerPopTimes100);
	Method(GetDefendedAgainstSpreadUntilTurn);
}
//------------------------------------------------------------------------------
void CvLuaCity::HandleMissingInstance(lua_State* L)
{
	DefaultHandleMissingInstance(L);
}
//------------------------------------------------------------------------------
const char* CvLuaCity::GetTypeName()
{
	return "City";
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Lua Methods
//------------------------------------------------------------------------------
//bool isNone();
int CvLuaCity::lIsNone(lua_State* L)
{
	const bool bDoesNotExist = (GetInstance(L, false) == NULL);
	lua_pushboolean(L, bDoesNotExist);

	return 1;
}

int CvLuaCity::lGetAdditionalFood(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iAdditionalFood = pkCity->GetAdditionalFood();
	lua_pushinteger(L, iAdditionalFood);

	return 1;
}
int CvLuaCity::lSetAdditionalFood(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iFood = lua_tointeger(L, 2);
	pkCity->SetAdditionalFood(iFood);
	return 1;
}

#if defined(MOD_API_UNIFIED_YIELDS_MORE)
int CvLuaCity::lSetMadeAttack(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const bool bNewValue = lua_toboolean(L, 2);

	pkCity->setMadeAttack(bNewValue);
	return 0;
}

int CvLuaCity::lGetOrganizedCrime(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	lua_pushinteger(L, pkCity->GetOrganizedCrime());
	return 1;
}
int CvLuaCity::lSetOrganizedCrime(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iValue = lua_tointeger(L, 2);
	pkCity->SetOrganizedCrime(iValue);
	return 1;
}
int CvLuaCity::lHasOrganizedCrime(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);

	lua_pushboolean(L, pkCity->HasOrganizedCrime());

	return 1;
}

int CvLuaCity::lChangeResistanceCounter(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iValue = lua_tointeger(L, 2);
	pkCity->ChangeResistanceCounter(iValue);
	return 1;
}
int CvLuaCity::lSetResistanceCounter(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iValue = lua_tointeger(L, 2);
	pkCity->SetResistanceCounter(iValue);
	return 1;
}
int CvLuaCity::lGetResistanceCounter(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	lua_pushinteger(L, pkCity->GetResistanceCounter());
	return 1;
}
int CvLuaCity::lChangePlagueCounter(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iValue = lua_tointeger(L, 2);
	pkCity->ChangePlagueCounter(iValue);
	return 1;
}
int CvLuaCity::lSetPlagueCounter(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iValue = lua_tointeger(L, 2);
	pkCity->SetPlagueCounter(iValue);
	return 1;
}
int CvLuaCity::lGetPlagueCounter(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	lua_pushinteger(L, pkCity->GetPlagueCounter());
	return 1;
}
int CvLuaCity::lGetPlagueTurns(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	lua_pushinteger(L, pkCity->GetPlagueTurns());
	return 1;
}
int CvLuaCity::lChangePlagueTurns(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iValue = lua_tointeger(L, 2);
	pkCity->ChangePlagueTurns(iValue);
	return 1;
}
int CvLuaCity::lSetPlagueTurns(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iValue = lua_tointeger(L, 2);
	pkCity->SetPlagueTurns(iValue);
	return 1;
}

int CvLuaCity::lGetPlagueType(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	lua_pushinteger(L, pkCity->GetPlagueType());
	return 1;
}
int CvLuaCity::lSetPlagueType(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iValue = lua_tointeger(L, 2);
	pkCity->SetPlagueType(iValue);
	return 1;
}
int CvLuaCity::lHasPlague(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);

	lua_pushboolean(L, pkCity->HasPlague());

	return 1;
}

int CvLuaCity::lChangeLoyaltyCounter(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iValue = lua_tointeger(L, 2);
	pkCity->ChangeLoyaltyCounter(iValue);
	return 1;
}
int CvLuaCity::lSetLoyaltyCounter(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iValue = lua_tointeger(L, 2);
	pkCity->SetLoyaltyCounter(iValue);
	return 1;
}
int CvLuaCity::lGetLoyaltyCounter(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	lua_pushinteger(L, pkCity->GetLoyaltyCounter());
	return 1;
}
int CvLuaCity::lChangeDisloyaltyCounter(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iValue = lua_tointeger(L, 2);
	pkCity->ChangeDisloyaltyCounter(iValue);
	return 1;
}
int CvLuaCity::lSetDisloyaltyCounter(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iValue = lua_tointeger(L, 2);
	pkCity->SetDisloyaltyCounter(iValue);
	return 1;
}
int CvLuaCity::lGetDisloyaltyCounter(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	lua_pushinteger(L, pkCity->GetDisloyaltyCounter());
	return 1;
}
int CvLuaCity::lGetLoyaltyState(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int eLoyalty = pkCity->GetLoyaltyState();
	lua_pushinteger(L, (LoyaltyStateTypes)eLoyalty);
	return 1;
}
int CvLuaCity::lSetLoyaltyState(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const LoyaltyStateTypes eLoyalty = (LoyaltyStateTypes)lua_tointeger(L, 2);
	pkCity->SetLoyaltyState((int)eLoyalty);
	return 1;
}

int CvLuaCity::lHasLoyaltyState(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iValue = lua_tointeger(L, 2);
	const bool bValue = (pkCity->GetLoyaltyState() == iValue);
	lua_pushboolean(L, bValue);

	return 1;
}


int CvLuaCity::lGetYieldFromHappiness(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const YieldTypes eYield = (YieldTypes)lua_tointeger(L, 2);
	const int iValue = pkCity->GetYieldFromHappiness(eYield);
	lua_pushinteger(L, iValue);
	return 1;
}
int CvLuaCity::lSetYieldFromHappiness(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iValue = lua_tointeger(L, 3);
	const YieldTypes eYield = (YieldTypes)lua_tointeger(L, 2);
	pkCity->SetYieldFromHappiness(eYield, iValue);
	return 1;
}

int CvLuaCity::lGetYieldFromHealth(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const YieldTypes eYield = (YieldTypes)lua_tointeger(L, 2);
	const int iValue = pkCity->GetYieldFromHealth(eYield);
	lua_pushinteger(L, iValue);
	return 1;
}
int CvLuaCity::lSetYieldFromHealth(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iValue = lua_tointeger(L, 3);
	const YieldTypes eYield = (YieldTypes)lua_tointeger(L, 2);
	pkCity->SetYieldFromHealth(eYield, iValue);
	return 1;
}

int CvLuaCity::lGetYieldFromCrime(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const YieldTypes eYield = (YieldTypes)lua_tointeger(L, 2);
	const int iValue = pkCity->GetYieldFromCrime(eYield);
	lua_pushinteger(L, iValue);
	return 1;
}
int CvLuaCity::lSetYieldFromCrime(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iValue = lua_tointeger(L, 3);
	const YieldTypes eYield = (YieldTypes)lua_tointeger(L, 2);
	pkCity->SetYieldFromCrime(eYield, iValue);
	return 1;
}
//------------------------------------------------------------------------------
int CvLuaCity::lGetYieldModifierFromHealth(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const YieldTypes eYield = (YieldTypes)lua_tointeger(L, 2);
	const int iValue = pkCity->GetYieldModifierFromHealth(eYield);
	lua_pushinteger(L, iValue);
	return 1;
}
int CvLuaCity::lSetYieldModifierFromHealth(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iValue = lua_tointeger(L, 3);
	const YieldTypes eYield = (YieldTypes)lua_tointeger(L, 2);
	pkCity->SetYieldModifierFromHealth(eYield, iValue);
	return 1;
}

int CvLuaCity::lGetYieldModifierFromCrime(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const YieldTypes eYield = (YieldTypes)lua_tointeger(L, 2);
	const int iValue = pkCity->GetYieldModifierFromCrime(eYield);
	lua_pushinteger(L, iValue);
	return 1;
}
int CvLuaCity::lSetYieldModifierFromCrime(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iValue = lua_tointeger(L, 3);
	const YieldTypes eYield = (YieldTypes)lua_tointeger(L, 2);
	pkCity->SetYieldModifierFromCrime(eYield, iValue);
	return 1;
}

#endif

//------------------------------------------------------------------------------
//void kill();
int CvLuaCity::lKill(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	pkCity->kill();

	return 1;
}
//------------------------------------------------------------------------------
//void CreateGreatGeneral(UnitTypes eGreatPersonUnit);
int CvLuaCity::lCreateGreatGeneral(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::createGreatGeneral);
}
//------------------------------------------------------------------------------
//void CreateGreatAdmiral(UnitTypes eGreatPersonUnit);
int CvLuaCity::lCreateGreatAdmiral(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::createGreatAdmiral);
}
//------------------------------------------------------------------------------
//void doTask(TaskTypes eTask, int iData1, int iData2, bool bOption);
int CvLuaCity::lDoTask(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const TaskTypes eTask = (TaskTypes)lua_tointeger(L, 2);
	const int iData1 = luaL_optint(L, 3, -1);
	const int iData2 = luaL_optint(L, 4, -1);
	const bool bOption = luaL_optint(L, 5, 0);
	pkCity->doTask(eTask, iData1, iData2, bOption);

	return 1;
}
//------------------------------------------------------------------------------
//void chooseProduction(UnitTypes eTrainUnit, BuildingTypes eConstructBuilding, ProjectTypes eCreateProject, bool bFinish, bool bFront);
int CvLuaCity::lChooseProduction(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	pkCity->chooseProduction();

	return 1;
}
//------------------------------------------------------------------------------
//int getCityPlotIndex(CyPlot* pPlot);
int CvLuaCity::lGetCityPlotIndex(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	CvPlot* pkPlot = CvLuaPlot::GetInstance(L, 2);
	const int iResult = pkCity->GetCityCitizens()->GetCityIndexFromPlot(pkPlot);

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//CyPlot* getCityIndexPlot(int iIndex);
int CvLuaCity::lGetCityIndexPlot(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iIndex = lua_tointeger(L, 2);

	CvPlot* pkPlot = pkCity->GetCityCitizens()->GetCityPlotFromIndex(iIndex);
	CvLuaPlot::Push(L, pkPlot);
	return 1;
}
//------------------------------------------------------------------------------
//bool canWork(CyPlot* pPlot);
int CvLuaCity::lCanWork(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	CvPlot* pkPlot = CvLuaPlot::GetInstance(L, 2);
	const bool bResult = pkCity->GetCityCitizens()->IsCanWork(pkPlot);

	lua_pushboolean(L, bResult);
	return 1;
}
//------------------------------------------------------------------------------
//bool IsBlockaded(CyPlot* pPlot);
int CvLuaCity::lIsPlotBlockaded(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	CvPlot* pkPlot = CvLuaPlot::GetInstance(L, 2);
	const bool bResult = pkCity->GetCityCitizens()->IsPlotBlockaded(pkPlot);

	lua_pushboolean(L, bResult);
	return 1;
}
//------------------------------------------------------------------------------
//void clearWorkingOverride(int iIndex);
int CvLuaCity::lClearWorkingOverride(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::clearWorkingOverride);
}
//------------------------------------------------------------------------------
//int countNumImprovedPlots();
int CvLuaCity::lCountNumImprovedPlots(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iResult = pkCity->countNumImprovedPlots();

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int countNumWaterPlots();
int CvLuaCity::lCountNumWaterPlots(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iResult = pkCity->countNumWaterPlots();

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int countNumRiverPlots();
int CvLuaCity::lCountNumRiverPlots(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iResult = pkCity->countNumRiverPlots();

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int findPopulationRank();
int CvLuaCity::lFindPopulationRank(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iResult = pkCity->findPopulationRank();

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int findBaseYieldRateRank(YieldTypes eYield);
int CvLuaCity::lFindBaseYieldRateRank(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const YieldTypes eYield = (YieldTypes)lua_tointeger(L, 2);
	const int iResult = pkCity->findBaseYieldRateRank(eYield);

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int findYieldRateRank(YieldTypes eYield);
int CvLuaCity::lFindYieldRateRank(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const YieldTypes eYield = (YieldTypes)lua_tointeger(L, 2);
	const int iResult = pkCity->findYieldRateRank(eYield);

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//UnitTypes allUpgradesAvailable(UnitTypes eUnit, int iUpgradeCount = 0);
int CvLuaCity::lAllUpgradesAvailable(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const UnitTypes eUnit = (UnitTypes)lua_tointeger(L, 2);
	const int iUpgradeCount = luaL_optint(L, 3, 0);

	const UnitTypes eResult = pkCity->allUpgradesAvailable(eUnit, iUpgradeCount);
	lua_pushinteger(L, eResult);
	return 1;
}
//------------------------------------------------------------------------------
//bool isWorldWondersMaxed();
int CvLuaCity::lIsWorldWondersMaxed(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const bool bResult = pkCity->isWorldWondersMaxed();

	lua_pushboolean(L, bResult);
	return 1;
}
//------------------------------------------------------------------------------
//bool isTeamWondersMaxed();
int CvLuaCity::lIsTeamWondersMaxed(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const bool bResult = pkCity->isTeamWondersMaxed();

	lua_pushboolean(L, bResult);
	return 1;
}
//------------------------------------------------------------------------------
//bool isNationalWondersMaxed();
int CvLuaCity::lIsNationalWondersMaxed(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const bool bResult = pkCity->isNationalWondersMaxed();

	lua_pushboolean(L, bResult);
	return 1;
}
//------------------------------------------------------------------------------
//bool isBuildingsMaxed();
int CvLuaCity::lIsBuildingsMaxed(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const bool bResult = pkCity->isBuildingsMaxed();

	lua_pushboolean(L, bResult);
	return 1;
}
//------------------------------------------------------------------------------
int CvLuaCity::lCanTrainTooltip(lua_State* L)
{
	CvString toolTip;
	CvCity* pkCity = GetInstance(L);
	const UnitTypes eUnit = (UnitTypes) lua_tointeger(L, 2);

	// City Production Modifier
	pkCity->canTrain(eUnit, false, false, false, false, &toolTip);

	lua_pushstring(L, toolTip.c_str());
	return 1;
}
//------------------------------------------------------------------------------
//bool canTrain( int iUnit, bool bContinue, bool bTestVisible, bool bIgnoreCost, bool bWillPurchase);
int CvLuaCity::lCanTrain(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iUnit = lua_tointeger(L, 2);
	const bool bContinue = luaL_optint(L, 3, 0);
	const bool bTestVisible = luaL_optint(L, 4, 0);
	const bool bIgnoreCost = luaL_optint(L, 5, 0);
	const bool bWillPurchase = luaL_optint(L, 6, 0);
	const bool bResult = pkCity->canTrain((UnitTypes)iUnit, bContinue, bTestVisible, bIgnoreCost, bWillPurchase);

	lua_pushboolean(L, bResult);
	return 1;
}
//------------------------------------------------------------------------------
int CvLuaCity::lCanConstructTooltip(lua_State* L)
{
	CvString toolTip;
	CvCity* pkCity = GetInstance(L);
	const BuildingTypes eBuilding = (BuildingTypes) lua_tointeger(L, 2);

	// City Production Modifier
#if defined(MOD_API_EXTENSIONS)
	pkCity->canConstruct(eBuilding, false, false, false, false, &toolTip);
#else
	pkCity->canConstruct(eBuilding, false, false, false, &toolTip);
#endif

	lua_pushstring(L, toolTip.c_str());
	return 1;
}
//------------------------------------------------------------------------------
//bool canConstruct( int iBuilding, bool bContinue, bool bTestVisible, bool bIgnoreCost);
int CvLuaCity::lCanConstruct(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iBuilding = lua_tointeger(L, 2);
	const bool bContinue = luaL_optint(L, 3, 0);
	const bool bTestVisible = luaL_optint(L, 4, 0);
	const bool bIgnoreCost = luaL_optint(L, 5, 0);
#if defined(MOD_API_EXTENSIONS)
	const bool bWillPurchase = luaL_optint(L, 6, 0);
	const bool bResult = pkCity->canConstruct((BuildingTypes)iBuilding, bContinue, bTestVisible, bIgnoreCost, bWillPurchase);
#else
	const bool bResult = pkCity->canConstruct((BuildingTypes)iBuilding, bContinue, bTestVisible, bIgnoreCost);
#endif

	lua_pushboolean(L, bResult);
	return 1;
}
//------------------------------------------------------------------------------
//bool canCreate( int iProject, bool bContinue, bool bTestVisible );
int CvLuaCity::lCanCreate(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iProject = lua_tointeger(L, 2);
	const bool bContinue = luaL_optint(L, 3, 0);
	const bool bTestVisible = luaL_optint(L, 4, 0);
	const bool bResult = pkCity->canCreate((ProjectTypes)iProject, bContinue, bTestVisible);

	lua_pushboolean(L, bResult);
	return 1;
}
//------------------------------------------------------------------------------
//bool canPrepare( int iSpecialist, bool bContinue );
int CvLuaCity::lCanPrepare(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iSpecialist = lua_tointeger(L, 2);
	const bool bContinue = luaL_optint(L, 3, 0);
	const bool bResult = pkCity->canPrepare((SpecialistTypes)iSpecialist, bContinue);

	lua_pushboolean(L, bResult);
	return 1;
}
//------------------------------------------------------------------------------
//bool canMaintain( int iProcess, bool bContinue );
int CvLuaCity::lCanMaintain(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iProcess = lua_tointeger(L, 2);
	const bool bContinue = luaL_optint(L, 3, 0);
	const bool bResult = pkCity->canMaintain((ProcessTypes)iProcess, bContinue);

	lua_pushboolean(L, bResult);
	return 1;
}
//------------------------------------------------------------------------------
int CvLuaCity::lGetPurchaseUnitTooltip(lua_State* L)
{
	CvString toolTip;
	CvCity* pkCity = GetInstance(L);
	const UnitTypes eUnit = (UnitTypes) lua_tointeger(L, 2);

	// City Production Modifier
	pkCity->canTrain(eUnit, false, false, false, false, &toolTip);

	// Already a unit here
	if(!pkCity->CanPlaceUnitHere(eUnit))
	{
		Localization::String localizedText = Localization::Lookup("TXT_KEY_CANNOT_PURCHASE_UNIT_HERE");

		const char* const localized = localizedText.toUTF8();
		if(localized)
		{
			if(!toolTip.IsEmpty())
				toolTip += "[NEWLINE]";

			toolTip += localized;
		}
	}

	// Not enough cash money
	if(pkCity->GetPurchaseCost(eUnit) > GET_PLAYER(pkCity->getOwner()).GetTreasury()->GetGold())
	{
		Localization::String localizedText = Localization::Lookup("TXT_KEY_CANNOT_PURCHASE_NO_GOLD");

		const char* const localized = localizedText.toUTF8();
		if(localized)
		{
			if(!toolTip.IsEmpty())
				toolTip += "[NEWLINE]";

			toolTip += localized;
		}
	}

	lua_pushstring(L, toolTip.c_str());
	return 1;
}
//------------------------------------------------------------------------------
int CvLuaCity::lGetFaithPurchaseUnitTooltip(lua_State* L)
{
	CvString toolTip;
	CvCity* pkCity = GetInstance(L);
	const UnitTypes eUnit = (UnitTypes) lua_tointeger(L, 2);
	pkCity->canTrain(eUnit, false, false, false, false, &toolTip);
	// Already a unit here
	if(!pkCity->CanPlaceUnitHere(eUnit))
	{
		Localization::String localizedText = Localization::Lookup("TXT_KEY_CANNOT_PURCHASE_UNIT_HERE");

		const char* const localized = localizedText.toUTF8();
		if(localized)
		{
			if(!toolTip.IsEmpty())
				toolTip += "[NEWLINE]";

			toolTip += localized;
		}
	}

	// Not enough faith
	if(pkCity->GetFaithPurchaseCost(eUnit, true) > GET_PLAYER(pkCity->getOwner()).GetFaith())
	{
		Localization::String localizedText = Localization::Lookup("TXT_KEY_CANNOT_PURCHASE_NO_FAITH");

		const char* const localized = localizedText.toUTF8();
		if(localized)
		{
			if(!toolTip.IsEmpty())
				toolTip += "[NEWLINE]";

			toolTip += localized;
		}
	}

	lua_pushstring(L, toolTip.c_str());
	return 1;
}
//------------------------------------------------------------------------------
int CvLuaCity::lGetPurchaseBuildingTooltip(lua_State* L)
{
	CvString toolTip;
	CvCity* pkCity = GetInstance(L);
	const BuildingTypes eBuilding = (BuildingTypes) lua_tointeger(L, 2);

	// City Production Modifier
#if defined(MOD_API_EXTENSIONS)
	pkCity->canConstruct(eBuilding, false, false, false, false, &toolTip);
#else
	pkCity->canConstruct(eBuilding, false, false, false, &toolTip);
#endif

	// Not enough cash money
	if(pkCity->GetPurchaseCost(eBuilding) > GET_PLAYER(pkCity->getOwner()).GetTreasury()->GetGold())
	{
		Localization::String localizedText = Localization::Lookup("TXT_KEY_CANNOT_PURCHASE_NO_GOLD");

		const char* const localized = localizedText.toUTF8();
		if(localized)
		{
			if(!toolTip.IsEmpty())
				toolTip += "[NEWLINE]";

			toolTip += localized;
		}
	}

	lua_pushstring(L, toolTip.c_str());
	return 1;
}
//------------------------------------------------------------------------------
int CvLuaCity::lGetFaithPurchaseBuildingTooltip(lua_State* L)
{
	CvString toolTip;
	CvCity* pkCity = GetInstance(L);
	const BuildingTypes eBuilding = (BuildingTypes) lua_tointeger(L, 2);

	// City Production Modifier
#if defined(MOD_API_EXTENSIONS)
	pkCity->canConstruct(eBuilding, false, false, false, false, &toolTip);
#else
	pkCity->canConstruct(eBuilding, false, false, false, &toolTip);
#endif

	// Not enough faith
	if(pkCity->GetFaithPurchaseCost(eBuilding) > GET_PLAYER(pkCity->getOwner()).GetFaith())
	{
		Localization::String localizedText = Localization::Lookup("TXT_KEY_CANNOT_PURCHASE_NO_FAITH");

		const char* const localized = localizedText.toUTF8();
		if(localized)
		{
			if(!toolTip.IsEmpty())
				toolTip += "[NEWLINE]";

			toolTip += localized;
		}
	}

	lua_pushstring(L, toolTip.c_str());
	return 1;
}
//------------------------------------------------------------------------------
//bool canJoin();
int CvLuaCity::lCanJoin(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const bool bResult = pkCity->canJoin();

	lua_pushboolean(L, bResult);
	return 1;
}
//------------------------------------------------------------------------------
//bool IsBuildingLocalResourceValid(BuildingTypes eBuilding, bool bCheckForImprovement);
int CvLuaCity::lIsBuildingLocalResourceValid(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::IsBuildingLocalResourceValid);
}
//------------------------------------------------------------------------------
//bool GetResourceDemanded();
int CvLuaCity::lGetResourceDemanded(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::GetResourceDemanded);
}
//------------------------------------------------------------------------------
//bool SetResourceDemanded(ResourceTypes eResource);
int CvLuaCity::lSetResourceDemanded(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::SetResourceDemanded);
}
//------------------------------------------------------------------------------
//bool DoPickResourceDemanded();
int CvLuaCity::lDoPickResourceDemanded(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::DoPickResourceDemanded);
}

//------------------------------------------------------------------------------
//int getFoodTurnsLeft();
int CvLuaCity::lGetFoodTurnsLeft(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getFoodTurnsLeft);

}
//------------------------------------------------------------------------------
//bool isProduction();
int CvLuaCity::lIsProduction(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::isProduction);
}
//------------------------------------------------------------------------------
//bool isProductionLimited();
int CvLuaCity::lIsProductionLimited(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::isProductionLimited);
}
//------------------------------------------------------------------------------
//bool isProductionUnit();
int CvLuaCity::lIsProductionUnit(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::isProductionUnit);
}
//------------------------------------------------------------------------------
//bool isProductionBuilding();
int CvLuaCity::lIsProductionBuilding(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::isProductionBuilding);
}
//------------------------------------------------------------------------------
//bool isProductionProject();
int CvLuaCity::lIsProductionProject(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::isProductionProject);
}
//------------------------------------------------------------------------------
//bool isProductionSpecialist();
int CvLuaCity::lIsProductionSpecialist(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::isProductionSpecialist);
}
//------------------------------------------------------------------------------
//bool isProductionProcess();
int CvLuaCity::lIsProductionProcess(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::isProductionProcess);
}
//------------------------------------------------------------------------------
//bool canContinueProduction(OrderTypes eOrderType, int iData1, int iData2, bool bSave)
int CvLuaCity::lCanContinueProduction(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	OrderData order;
	order.eOrderType = (OrderTypes)lua_tointeger(L, 2);
	order.iData1 = lua_tointeger(L, 3);
	order.iData2 = lua_tointeger(L, 4);
	order.bSave = lua_toboolean(L, 5);

	const bool bResult = pkCity->canContinueProduction(order);

	lua_pushboolean(L, bResult);
	return 1;
}
//------------------------------------------------------------------------------
//int getProductionExperience(UnitTypes eUnit);
int CvLuaCity::lGetProductionExperience(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getProductionExperience);
}
//------------------------------------------------------------------------------
//void addProductionExperience(CyUnit* pUnit, bool bConscript = false);
int CvLuaCity::lAddProductionExperience(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	CvUnit* pkUnit = CvLuaUnit::GetInstance(L, 2);
	const bool bConscript = luaL_optint(L, 3, 0);
	pkCity->addProductionExperience(pkUnit, bConscript);

	return 1;
}
//------------------------------------------------------------------------------
//UnitTypes getProductionUnit()
int CvLuaCity::lGetProductionUnit(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getProductionUnit);
}
//------------------------------------------------------------------------------
//UnitAITypes getProductionUnitAI()
int CvLuaCity::lGetProductionUnitAI(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const UnitAITypes eValue = pkCity->getProductionUnitAI();

	lua_pushinteger(L, eValue);
	return 1;
}
//------------------------------------------------------------------------------
//BuildingTypes getProductionBuilding()
int CvLuaCity::lGetProductionBuilding(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const BuildingTypes eValue = pkCity->getProductionBuilding();

	lua_pushinteger(L, eValue);
	return 1;
}
//------------------------------------------------------------------------------
//ProjectTypes getProductionProject()
int CvLuaCity::lGetProductionProject(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const ProjectTypes eValue = pkCity->getProductionProject();

	lua_pushinteger(L, eValue);
	return 1;
}
//------------------------------------------------------------------------------
//SpecialistTypes getProductionSpecialist()
int CvLuaCity::lGetProductionSpecialist(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const SpecialistTypes eValue = pkCity->getProductionSpecialist();

	lua_pushinteger(L, eValue);
	return 1;
}
//------------------------------------------------------------------------------
//ProcessTypes getProductionProcess()
int CvLuaCity::lGetProductionProcess(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getProductionProcess);
}
//------------------------------------------------------------------------------
//std::string getProductionName();
//------------------------------------------------------------------------------
//string getProductionNameKey();
int CvLuaCity::lGetProductionNameKey(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	lua_pushstring(L, pkCity->getProductionNameKey());
	return 1;
}
//------------------------------------------------------------------------------
//int getGeneralProductionTurnsLeft();
int CvLuaCity::lGetGeneralProductionTurnsLeft(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getGeneralProductionTurnsLeft);
}
//------------------------------------------------------------------------------
//bool isFoodProduction();
int CvLuaCity::lIsFoodProduction(lua_State* L)
{
	//return BasicLuaMethod<bool, UnitTypes>(L, &CvCity::isFoodProduction);
	CvCity* pkCity = GetInstance(L);
	const int iResult = pkCity->isFoodProduction();

	lua_pushboolean(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int getFirstUnitOrder(UnitTypes eUnit);
int CvLuaCity::lGetFirstUnitOrder(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getFirstUnitOrder);
}
//------------------------------------------------------------------------------
//int getFirstProjectOrder(ProjectTypes eProject);
int CvLuaCity::lGetFirstProjectOrder(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getFirstProjectOrder);
}
//------------------------------------------------------------------------------
//int getFirstSpecialistOrder(SpecialistTypes eSpecialist);
int CvLuaCity::lGetFirstSpecialistOrder(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getFirstSpecialistOrder);
}
//------------------------------------------------------------------------------
//int getNumTrainUnitAI(UnitAITypes eUnitAI);
int CvLuaCity::lGetNumTrainUnitAI(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getNumTrainUnitAI);
}
//------------------------------------------------------------------------------
//int getFirstBuildingOrder(BuildingTypes eBuilding);
int CvLuaCity::lGetFirstBuildingOrder(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getFirstBuildingOrder);
}
//------------------------------------------------------------------------------
//bool isUnitFoodProduction(UnitTypes iUnit);
int CvLuaCity::lIsUnitFoodProduction(lua_State* L)
{
	return BasicLuaMethod<bool, UnitTypes>(L, &CvCity::isFoodProduction);
}
//------------------------------------------------------------------------------
//int getProduction();
int CvLuaCity::lGetProduction(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getProduction);
}
//------------------------------------------------------------------------------
//int getProductionTimes100();
int CvLuaCity::lGetProductionTimes100(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getProductionTimes100);
}
//------------------------------------------------------------------------------
//int getProductionNeeded();
int CvLuaCity::lGetProductionNeeded(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getProductionNeeded);
}
//------------------------------------------------------------------------------
//int GetUnitProductionNeeded();
int CvLuaCity::lGetUnitProductionNeeded(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const UnitTypes eUnitType = (UnitTypes) lua_tointeger(L, 2);

	const int iResult = pkCity->getProductionNeeded(eUnitType);

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int GetBuildingProductionNeeded();
int CvLuaCity::lGetBuildingProductionNeeded(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const BuildingTypes eBuildingType = (BuildingTypes) lua_tointeger(L, 2);

	const int iResult = pkCity->getProductionNeeded(eBuildingType);

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int GetProjectProductionNeeded();
int CvLuaCity::lGetProjectProductionNeeded(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const ProjectTypes eProjectType = (ProjectTypes) lua_tointeger(L, 2);

	const int iResult = pkCity->getProductionNeeded(eProjectType);

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int getProductionTurnsLeft();
int CvLuaCity::lGetProductionTurnsLeft(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iResult = pkCity->getProductionTurnsLeft();

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int getUnitProductionTurnsLeft(UnitTypes iUnit, int iNum);
int CvLuaCity::lGetUnitProductionTurnsLeft(lua_State* L)
{
	return BasicLuaMethod<int, UnitTypes>(L, &CvCity::getProductionTurnsLeft);
}
//------------------------------------------------------------------------------
//int getBuildingProductionTurnsLeft(BuildingTypes iBuilding, int iNum);
int CvLuaCity::lGetBuildingProductionTurnsLeft(lua_State* L)
{
	return BasicLuaMethod<int, BuildingTypes>(L, &CvCity::getProductionTurnsLeft);
}
//------------------------------------------------------------------------------
//int getProjectProductionTurnsLeft(ProjectTypes eProject, int iNum);
int CvLuaCity::lGetProjectProductionTurnsLeft(lua_State* L)
{
	return BasicLuaMethod<int, ProjectTypes>(L, &CvCity::getProductionTurnsLeft);
}
//------------------------------------------------------------------------------
//int getSpecialistProductionTurnsLeft(SpecialistTypes eSpecialist, int iNum);
int CvLuaCity::lGetSpecialistProductionTurnsLeft(lua_State* L)
{
	return BasicLuaMethod<int, SpecialistTypes>(L, &CvCity::getProductionTurnsLeft);
}
#if defined(MOD_API_LUA_EXTENSIONS) && defined(MOD_PROCESS_STOCKPILE)
//------------------------------------------------------------------------------
//int getProcessProductionTurnsLeft(ProcessTypes eProcess, int iNum);
int CvLuaCity::lGetProcessProductionTurnsLeft(lua_State* L)
{
	return BasicLuaMethod<int, ProcessTypes>(L, &CvCity::getProductionTurnsLeft);
}
#endif
//------------------------------------------------------------------------------
// int IsCanPurchase(UnitTypes eUnitType, BuildingTypes eBuildingType, ProjectTypes eProjectType, YieldTypes ePurchaseYield);
int CvLuaCity::lIsCanPurchase(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const bool bTestPurchaseCost = lua_toboolean(L, 2);
	const bool bTestTrainable = lua_toboolean(L, 3);
	const UnitTypes eUnitType = (UnitTypes) lua_tointeger(L, 4);
	const BuildingTypes eBuildingType = (BuildingTypes) lua_tointeger(L, 5);
	const ProjectTypes eProjectType = (ProjectTypes) lua_tointeger(L, 6);
	const YieldTypes ePurchaseYield = (YieldTypes) lua_tointeger(L, 7);

	const bool bResult = pkCity->IsCanPurchase(bTestPurchaseCost, bTestTrainable, eUnitType, eBuildingType, eProjectType, ePurchaseYield);

	lua_pushboolean(L, bResult);
	return 1;
}
#if defined(MOD_API_LUA_EXTENSIONS)
//------------------------------------------------------------------------------
// void Purchase(UnitTypes eUnitType, BuildingTypes eBuildingType, ProjectTypes eProjectType, YieldTypes ePurchaseYield);
int CvLuaCity::lPurchase(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const UnitTypes eUnitType = (UnitTypes) lua_tointeger(L, 2);
	const BuildingTypes eBuildingType = (BuildingTypes) lua_tointeger(L, 3);
	const ProjectTypes eProjectType = (ProjectTypes) lua_tointeger(L, 4);
	const YieldTypes ePurchaseYield = (YieldTypes) lua_tointeger(L, 5);

	pkCity->Purchase(eUnitType, eBuildingType, eProjectType, ePurchaseYield);

	return 0;
}
#endif

int CvLuaCity::lGetNumTimesAttackedThisTurn(lua_State* L)
{
	//GetNumTimesAttackedThisTurn(PlayerTypes ePlayer)
	return BasicLuaMethod<int, PlayerTypes>(L, &CvCity::GetNumTimesAttackedThisTurn);
}
//------------------------------------------------------------------------------
// int GetPurchaseCost(UnitTypes eUnit);
int CvLuaCity::lGetUnitPurchaseCost(lua_State* L)
{
	return BasicLuaMethod<int, UnitTypes>(L, &CvCity::GetPurchaseCost);
}
//------------------------------------------------------------------------------
// int GetFaithPurchaseCost(UnitTypes eUnit, bool bIncludeBeliefDiscounts);
int CvLuaCity::lGetUnitFaithPurchaseCost(lua_State* L)
{
	return BasicLuaMethod<int, UnitTypes>(L, &CvCity::GetFaithPurchaseCost);
}
//------------------------------------------------------------------------------
//int GetPurchaseCost(BuildingTypes eBuilding);
int CvLuaCity::lGetBuildingPurchaseCost(lua_State* L)
{
	return BasicLuaMethod<int, BuildingTypes>(L, &CvCity::GetPurchaseCost);
}
//------------------------------------------------------------------------------
//int GetFaithPurchaseCost(BuildingTypes eBuilding);
int CvLuaCity::lGetBuildingFaithPurchaseCost(lua_State* L)
{
	return BasicLuaMethod<int, BuildingTypes>(L, &CvCity::GetFaithPurchaseCost);
}
//------------------------------------------------------------------------------
//int GetPurchaseCost(ProjectTypes eProject);
int CvLuaCity::lGetProjectPurchaseCost(lua_State* L)
{
	return BasicLuaMethod<int, ProjectTypes>(L, &CvCity::GetPurchaseCost);
}
//------------------------------------------------------------------------------
//void setProduction(int iNewValue);
int CvLuaCity::lSetProduction(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::setProduction);
}
//------------------------------------------------------------------------------
//void changeProduction(int iChange);
int CvLuaCity::lChangeProduction(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::changeProduction);
}
//------------------------------------------------------------------------------
int CvLuaCity::lGetYieldModifierTooltip(lua_State* L)
{
	CvString toolTip;
	CvCity* pkCity = GetInstance(L);
	const YieldTypes eYield = (YieldTypes) lua_tointeger(L, 2);

	// City Food Modifier
	if(eYield == YIELD_FOOD)
	{	
		pkCity->foodDifferenceTimes100(true, &toolTip);
	}

	// City Production Modifier
	if(eYield == YIELD_PRODUCTION)
	{
		pkCity->getProductionModifier(&toolTip);
	}

	// City Yield Rate Modifier
	pkCity->getBaseYieldRateModifier(eYield, 0, &toolTip);

	if (eYield != YIELD_FOOD)
	{
		// Trade Yield Modifier
		pkCity->GetTradeYieldModifier(eYield, &toolTip);
	}

	lua_pushstring(L, toolTip.c_str());
	return 1;
}
//------------------------------------------------------------------------------
//int getProductionModifier();
int CvLuaCity::lGetProductionModifier(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iResult = pkCity->getProductionModifier();

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int GetCurrentProductionDifference(bool bIgnoreFood, bool bOverflow);
int CvLuaCity::lGetCurrentProductionDifference(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getCurrentProductionDifference);
}
//------------------------------------------------------------------------------
//int GetRawProductionDifference(bool bIgnoreFood, bool bOverflow);
int CvLuaCity::lGetRawProductionDifference(lua_State *L)
{
	return BasicLuaMethod(L, &CvCity::getRawProductionDifference);
}
//------------------------------------------------------------------------------
//int GetCurrentProductionDifferenceTimes100(bool bIgnoreFood, bool bOverflow);
int CvLuaCity::lGetCurrentProductionDifferenceTimes100(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getCurrentProductionDifferenceTimes100);
}
//------------------------------------------------------------------------------
//int GetRawProductionDifferenceTimes100(bool bIgnoreFood, bool bOverflow);
int CvLuaCity::lGetRawProductionDifferenceTimes100(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getRawProductionDifferenceTimes100);
}
//------------------------------------------------------------------------------
//int getUnitProductionModifier(UnitTypes iUnit);
int CvLuaCity::lGetUnitProductionModifier(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const UnitTypes iUnit = (UnitTypes)lua_tointeger(L, 2);
	const int iResult = pkCity->getProductionModifier(iUnit);

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int getBuildingProductionModifier(BuildingTypes iBuilding);
int CvLuaCity::lGetBuildingProductionModifier(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const BuildingTypes iBuilding = (BuildingTypes)lua_tointeger(L, 2);
	if(iBuilding != NO_BUILDING)
	{
		const int iResult = pkCity->getProductionModifier(iBuilding);
		lua_pushinteger(L, iResult);
	}
	else
	{
		lua_pushinteger(L, 0);
	}
	return 1;
}
//------------------------------------------------------------------------------
//int getProjectProductionModifier(ProjectTypes eProject);
int CvLuaCity::lGetProjectProductionModifier(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const ProjectTypes eProject = (ProjectTypes)lua_tointeger(L, 2);
	const int iResult = pkCity->getProductionModifier(eProject);

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int getSpecialistProductionModifier(SpecialistTypes eSpecialist);
int CvLuaCity::lGetSpecialistProductionModifier(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const SpecialistTypes eSpecialist = (SpecialistTypes)lua_tointeger(L, 2);
	const int iResult = pkCity->getProductionModifier(eSpecialist);

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int getExtraProductionDifference(int iExtra);
int CvLuaCity::lGetExtraProductionDifference(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getExtraProductionDifference);
}
//------------------------------------------------------------------------------
//bool canHurry(HurryTypes iHurry, bool bTestVisible);
int CvLuaCity::lCanHurry(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::canHurry);
}
//------------------------------------------------------------------------------
//void hurry(HurryTypes iHurry);
int CvLuaCity::lHurry(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::hurry);
}
//------------------------------------------------------------------------------
//UnitTypes getConscriptUnit()
int CvLuaCity::lGetConscriptUnit(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getConscriptUnit);
}
//------------------------------------------------------------------------------
//int getConscriptPopulation();
int CvLuaCity::lGetConscriptPopulation(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getConscriptPopulation);
}
//------------------------------------------------------------------------------
//int conscriptMinCityPopulation();
int CvLuaCity::lConscriptMinCityPopulation(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::conscriptMinCityPopulation);
}
//------------------------------------------------------------------------------
//bool canConscript();
int CvLuaCity::lCanConscript(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::canConscript);
}
//------------------------------------------------------------------------------
//void conscript();
int CvLuaCity::lConscript(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	pkCity->conscript();

	return 1;
}
//------------------------------------------------------------------------------
//int getYieldModifierFromResource(YieldTypes eIndex, ResourceTypes eResource);
int CvLuaCity::lGetResourceYieldRateModifier(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const YieldTypes eYield = (YieldTypes)lua_tointeger(L, 2);
	const ResourceTypes eResource = (ResourceTypes)lua_tointeger(L, 3);
	lua_pushinteger(L, pkCity->getYieldModifierFromResource(eResource, eYield));
	return 1;
}
//------------------------------------------------------------------------------
//HandicapTypes getHandicapType();
int CvLuaCity::lGetHandicapType(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getHandicapType);
}
//------------------------------------------------------------------------------
//CivilizationTypes getCivilizationType();
int CvLuaCity::lGetCivilizationType(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getCivilizationType);
}
//------------------------------------------------------------------------------
//LeaderHeadTypes getPersonalityType()
int CvLuaCity::lGetPersonalityType(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const LeaderHeadTypes eValue = pkCity->getPersonalityType();

	lua_pushinteger(L, eValue);
	return 1;
}
//------------------------------------------------------------------------------
//ArtStyleTypes getArtStyleType()
int CvLuaCity::lGetArtStyleType(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const ArtStyleTypes eValue = pkCity->getArtStyleType();

	lua_pushinteger(L, eValue);
	return 1;
}
//------------------------------------------------------------------------------
//CitySizeTypes getCitySizeType()
int CvLuaCity::lGetCitySizeType(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const CitySizeTypes eValue = pkCity->getCitySizeType();

	lua_pushinteger(L, eValue);
	return 1;
}
//------------------------------------------------------------------------------
//bool isBarbarian();
int CvLuaCity::lIsBarbarian(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::isBarbarian);
}
//------------------------------------------------------------------------------
//bool isHuman();
int CvLuaCity::lIsHuman(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::isHuman);
}
//------------------------------------------------------------------------------
//bool isVisible(TeamTypes eTeam, bool bDebug);
int CvLuaCity::lIsVisible(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::isVisible);
}
//------------------------------------------------------------------------------
//bool isCapital();
int CvLuaCity::lIsCapital(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::isCapital);
}
//------------------------------------------------------------------------------
//bool isOriginalCapital();
int CvLuaCity::lIsOriginalCapital(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::IsOriginalCapital);
}
//------------------------------------------------------------------------------
//bool isOriginalMajorCapital();
int CvLuaCity::lIsOriginalMajorCapital(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::IsOriginalMajorCapital);
}
//------------------------------------------------------------------------------
//bool isCoastal(int iMinWaterSize);
int CvLuaCity::lIsCoastal(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::isCoastal);
}
#if defined(MOD_API_LUA_EXTENSIONS)
//------------------------------------------------------------------------------
//bool isAddsFreshWater();
int CvLuaCity::lIsAddsFreshWater(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::isAddsFreshWater);
}
#endif
//------------------------------------------------------------------------------
//int foodConsumption(bool bNoAngry, int iExtra);
int CvLuaCity::lFoodConsumption(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::foodConsumption);
}
//------------------------------------------------------------------------------
//int foodDifference(bool bBottom);
int CvLuaCity::lFoodDifference(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::foodDifference);
}
//------------------------------------------------------------------------------
//int foodDifferenceTimes100(bool bBottom);
int CvLuaCity::lFoodDifferenceTimes100(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::foodDifferenceTimes100);
}
//------------------------------------------------------------------------------
//int growthThreshold();
int CvLuaCity::lGrowthThreshold(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::growthThreshold);
}
//------------------------------------------------------------------------------
//int productionLeft();
int CvLuaCity::lProductionLeft(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::productionLeft);
}
//------------------------------------------------------------------------------
//int hurryCost(HurryTypes iHurry, bool bExtra);
int CvLuaCity::lHurryCost(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::hurryCost);
}
//------------------------------------------------------------------------------
//int hurryGold(HurryTypes iHurry);
int CvLuaCity::lHurryGold(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::hurryGold);
}
//------------------------------------------------------------------------------
//int hurryPopulation(HurryTypes iHurry);
int CvLuaCity::lHurryPopulation(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::hurryPopulation);
}
//------------------------------------------------------------------------------
//int hurryProduction(HurryTypes iHurry);
int CvLuaCity::lHurryProduction(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::hurryProduction);
}
//------------------------------------------------------------------------------
//int maxHurryPopulation();
int CvLuaCity::lMaxHurryPopulation(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::maxHurryPopulation);
}
//------------------------------------------------------------------------------
//int getNumBuilding(BuildingTypes eBuildingType);
int CvLuaCity::lGetNumBuilding(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const BuildingTypes eBuildingType = (BuildingTypes)lua_tointeger(L, 2);
	if(eBuildingType != NO_BUILDING)
	{
		const int iResult = pkCity->GetCityBuildings()->GetNumBuilding(eBuildingType);
		lua_pushinteger(L, iResult);
	}
	else
	{
		lua_pushinteger(L, 0);
	}
	return 1;
}
//------------------------------------------------------------------------------
//bool isHasBuilding(BuildingTypes eBuildingType);
// This is a function to help modders out, since it was replaced with getNumBuildings() in the C++
int CvLuaCity::lIsHasBuilding(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const BuildingTypes eBuildingType = (BuildingTypes)lua_tointeger(L, 2);
	if(eBuildingType != NO_BUILDING)
	{
		const bool bResult = pkCity->GetCityBuildings()->GetNumBuilding(eBuildingType);
		lua_pushboolean(L, bResult);
	}
	else
	{
		lua_pushboolean(L, false);
	}
	return 1;
}
#if defined(MOD_API_LUA_EXTENSIONS)
//------------------------------------------------------------------------------
//int getNumBuildingClass(BuildingClassTypes eBuildingClassType);
int CvLuaCity::lGetNumBuildingClass(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const BuildingClassTypes eBuildingClassType = (BuildingClassTypes)lua_tointeger(L, 2);
	if (eBuildingClassType == NO_BUILDINGCLASS)
	{
		lua_pushinteger(L, 0);
		return 1;
	}
	lua_pushinteger(L, pkCity->GetNumBuildingClass(eBuildingClassType));

	return 1;
}
//------------------------------------------------------------------------------
//bool isHasBuildingClass(BuildingClassTypes eBuildingClassType);
int CvLuaCity::lIsHasBuildingClass(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const BuildingClassTypes eBuildingClassType = (BuildingClassTypes)lua_tointeger(L, 2);
	if (eBuildingClassType == NO_BUILDINGCLASS)
	{
		lua_pushboolean(L, false);
		return 1;
	}
	lua_pushboolean(L, pkCity->GetNumBuildingClass(eBuildingClassType) > 0);

	return 1;
}

//------------------------------------------------------------------------------
int CvLuaCity::lGetLocalBuildingClassYield(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const BuildingClassTypes eBuildingClassType = (BuildingClassTypes)lua_tointeger(L, 2);
	const YieldTypes eIndex = (YieldTypes)lua_tointeger(L, 3);
	int iResult = 0;
	if (eBuildingClassType != NO_BUILDINGCLASS && eIndex != NO_YIELD)
	{
		iResult = pkCity->getLocalBuildingClassYield(eBuildingClassType, eIndex);
	}

	lua_pushinteger(L, iResult);
	return 1;
}

//bool SetNumRealBuildingClass(BuildingClassTypes eBuildingClassType, int iNum);
int CvLuaCity::lSetNumRealBuildingClass(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const BuildingClassTypes eBuildingClassType = (BuildingClassTypes)lua_tointeger(L, 2);
	const int iNum = lua_tointeger(L, 3);
	if (eBuildingClassType == NO_BUILDINGCLASS)
	{
		lua_pushboolean(L, false);
		return 1;
	}

	CvPlayerAI& pkPlayer = GET_PLAYER(pkCity->getOwner());
	BuildingTypes eBuilding = pkPlayer.GetCivBuilding(eBuildingClassType);

	if (eBuilding == NO_BUILDING)
	{
		lua_pushboolean(L, false);
	}
	else
	{
		pkCity->GetCityBuildings()->SetNumRealBuilding(eBuilding, iNum);
		lua_pushboolean(L, true);
	}

	return 1;
}
#endif
//------------------------------------------------------------------------------
//int getNumActiveBuilding(BuildingTypes eBuildingType);
int CvLuaCity::lGetNumActiveBuilding(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const BuildingTypes eBuildingType = (BuildingTypes)lua_tointeger(L, 2);
	if(eBuildingType != NO_BUILDING)
	{
		const int iResult = pkCity->GetCityBuildings()->GetNumActiveBuilding(eBuildingType);
		lua_pushinteger(L, iResult);
	}
	else
	{
		lua_pushinteger(L, 0);
	}
	return 1;
}
//------------------------------------------------------------------------------
//int getID();
int CvLuaCity::lGetID(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iResult = pkCity->GetID();

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int getX();
int CvLuaCity::lGetX(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iResult = pkCity->getX();

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int getY();
int CvLuaCity::lGetY(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iResult = pkCity->getY();

	lua_pushinteger(L, iResult);
	return 1;
}
#if defined(MOD_API_LUA_EXTENSIONS)
//------------------------------------------------------------------------------
//int, int getXY();
int CvLuaCity::lGetXY(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iX = pkCity->getX();
	const int iY = pkCity->getY();

	lua_pushinteger(L, iX);
	lua_pushinteger(L, iY);
	return 2;
}
#endif
//------------------------------------------------------------------------------
//bool at(int iX, int iY);
int CvLuaCity::lAt(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int x = lua_tointeger(L, 2);
	const int y = lua_tointeger(L, 3);
	const bool bResult = pkCity->at(x, y);

	lua_pushboolean(L, bResult);
	return 1;
}
//------------------------------------------------------------------------------
//bool atPlot(CyPlot* pPlot);
int CvLuaCity::lAtPlot(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	CvPlot* pkPlot = CvLuaPlot::GetInstance(L, 2);
	const bool bResult = pkCity->at(pkPlot);

	lua_pushboolean(L, bResult);
	return 1;
}
//------------------------------------------------------------------------------
//CyPlot* plot();
int CvLuaCity::lPlot(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	CvPlot* pkPlot = pkCity->plot();
	CvLuaPlot::Push(L, pkPlot);
	return 1;
}
//------------------------------------------------------------------------------
//CyArea* area();
int CvLuaCity::lArea(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	CvArea* pkArea = pkCity->area();
	CvLuaArea::Push(L, pkArea);
	return 1;
}
//------------------------------------------------------------------------------
//CyArea* waterArea();
int CvLuaCity::lWaterArea(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	CvArea* pkArea = pkCity->waterArea();
	CvLuaArea::Push(L, pkArea);
	return 1;
}
//------------------------------------------------------------------------------
//CyPlot* getRallyPlot();
int CvLuaCity::lGetRallyPlot(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	CvPlot* pkPlot = pkCity->getRallyPlot();
	CvLuaPlot::Push(L, pkPlot);
	return 1;
}

//------------------------------------------------------------------------------
//bool getCanBuyPlot();
int CvLuaCity::lCanBuyPlot(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	CvPlot* pPlot = pkCity->GetNextBuyablePlot();
	lua_pushboolean(L, pkCity->CanBuyPlot(pPlot->getX(), pPlot->getY()));
	return 1;
}

//------------------------------------------------------------------------------
//bool getCanBuyPlotAt();
int CvLuaCity::lCanBuyPlotAt(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iX = lua_tointeger(L, 2);
	const int iY = lua_tointeger(L, 3);
	const bool bIgnoreCost = lua_toboolean(L, 4);
	lua_pushboolean(L, pkCity->CanBuyPlot(iX, iY, bIgnoreCost));
	return 1;
}
//------------------------------------------------------------------------------
//bool CanBuyAnyPlot(void)
int CvLuaCity::lCanBuyAnyPlot(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	lua_pushboolean(L, pkCity->CanBuyAnyPlot());
	return 1;
}
//------------------------------------------------------------------------------
//CvPlot* getNextBuyablePlot();
int CvLuaCity::lGetNextBuyablePlot(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	CvPlot* pkPlot = pkCity->GetNextBuyablePlot();
	CvLuaPlot::Push(L, pkPlot);
	return 1;
}

//------------------------------------------------------------------------------
int CvLuaCity::lGetBuyablePlotList(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	std::vector<int> aiPlotList;
	aiPlotList.resize(20, -1);
	pkCity->GetBuyablePlotList(aiPlotList);

	int iReturnValues = 0;

	for(uint ui = 0; ui < aiPlotList.size(); ui++)
	{
		if(aiPlotList[ui] >= 0)
		{
			CvPlot* pkPlot = GC.getMap().plotByIndex(aiPlotList[ui]);
			CvLuaPlot::Push(L, pkPlot);
			iReturnValues++;
		}
		else
		{
			break;
		}
	}

	return iReturnValues;
}

//------------------------------------------------------------------------------
//int GetBuyPlotCost()
int CvLuaCity::lGetBuyPlotCost(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iX = lua_tointeger(L, 2);
	const int iY = lua_tointeger(L, 3);
	lua_pushinteger(L, pkCity->GetBuyPlotCost(iX, iY));
	return 1;
}

//------------------------------------------------------------------------------
// CvUnit* GetGarrisonedUnit()
int CvLuaCity::lGetGarrisonedUnit(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	CvUnit* pkUnit = pkCity->GetGarrisonedUnit();
	CvLuaUnit::Push(L, pkUnit);
	return 1;
}

//------------------------------------------------------------------------------
//int getGameTurnFounded();
int CvLuaCity::lGetGameTurnFounded(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getGameTurnFounded);
}
//------------------------------------------------------------------------------
//int getGameTurnAcquired();
int CvLuaCity::lGetGameTurnAcquired(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getGameTurnAcquired);
}
//------------------------------------------------------------------------------
//int getGameTurnLastExpanded();
int CvLuaCity::lGetGameTurnLastExpanded(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getGameTurnLastExpanded);
}
//------------------------------------------------------------------------------
//int getPopulation();
int CvLuaCity::lGetPopulation(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getPopulation);
}
//------------------------------------------------------------------------------
//void setPopulation(int iNewValue);
int CvLuaCity::lSetPopulation(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	int iValue = lua_tointeger(L, 2);
	int bReassignPop = lua_toboolean(L, 3);
	CvAssertMsg(bReassignPop != 0, "It is super dangerous to set this to false.  Ken would love to see why you are doing this.");
	pkCity->setPopulation(iValue, bReassignPop);

	return 1;
//	return BasicLuaMethod(L, &CvCity::setPopulation);
}
//------------------------------------------------------------------------------
//void changePopulation(int iChange);
int CvLuaCity::lChangePopulation(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	int iChange = lua_tointeger(L, 2);
	int bReassignPop = lua_toboolean(L, 3);
	CvAssertMsg(bReassignPop != 0, "It is super dangerous to set this to false.  Ken would love to see why you are doing this.");
	pkCity->changePopulation(iChange, bReassignPop);

	return 1;
//	return BasicLuaMethod(L, &CvCity::changePopulation);
}

//------------------------------------------------------------------------------
//int getRealPopulation();
int CvLuaCity::lGetRealPopulation(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getRealPopulation);
}
//------------------------------------------------------------------------------
//int getHighestPopulation();
int CvLuaCity::lGetHighestPopulation(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getHighestPopulation);
}
//------------------------------------------------------------------------------
//void setHighestPopulation(int iNewValue);
int CvLuaCity::lSetHighestPopulation(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::setHighestPopulation);
}
//------------------------------------------------------------------------------
//int getWorkingPopulation();
//int CvLuaCity::lGetWorkingPopulation(lua_State* L)
//{
//	return BasicLuaMethod(L, &CvCity::getWorkingPopulation);
//}
////------------------------------------------------------------------------------
////int getSpecialistPopulation();
//int CvLuaCity::lGetSpecialistPopulation(lua_State* L)
//{
//	return BasicLuaMethod(L, &CvCity::getSpecialistPopulation);
//}
#if defined(MOD_API_LUA_EXTENSIONS) && defined(MOD_GLOBAL_CITY_AUTOMATON_WORKERS)
//------------------------------------------------------------------------------
//int getAutomatons();
int CvLuaCity::lGetAutomatons(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getAutomatons);
}
//------------------------------------------------------------------------------
//void setAutomatons(int iNewValue, bool bReassignPop);
int CvLuaCity::lSetAutomatons(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::setAutomatons);
}
#endif
//------------------------------------------------------------------------------
//int getNumGreatPeople();
int CvLuaCity::lGetNumGreatPeople(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getNumGreatPeople);
}
//------------------------------------------------------------------------------
//int getBaseGreatPeopleRate();
int CvLuaCity::lGetBaseGreatPeopleRate(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getBaseGreatPeopleRate);
}
//------------------------------------------------------------------------------
//int getGreatPeopleRate();
int CvLuaCity::lGetGreatPeopleRate(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getGreatPeopleRate);
}
//------------------------------------------------------------------------------
//int getTotalGreatPeopleRateModifier();
int CvLuaCity::lGetTotalGreatPeopleRateModifier(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getTotalGreatPeopleRateModifier);
}
//------------------------------------------------------------------------------
//void changeBaseGreatPeopleRate(int iChange);
int CvLuaCity::lChangeBaseGreatPeopleRate(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::changeBaseGreatPeopleRate);
}
//------------------------------------------------------------------------------
//int getGreatPeopleRateModifier();
int CvLuaCity::lGetGreatPeopleRateModifier(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getGreatPeopleRateModifier);
}
//------------------------------------------------------------------------------
//int GetJONSCultureStored() const;
int CvLuaCity::lGetJONSCultureStored(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::GetJONSCultureStored);
}
//------------------------------------------------------------------------------
//void SetJONSCultureStored(int iValue);
int CvLuaCity::lSetJONSCultureStored(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::SetJONSCultureStored);
}
//------------------------------------------------------------------------------
//void ChangeJONSCultureStored(int iChange);
int CvLuaCity::lChangeJONSCultureStored(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::ChangeJONSCultureStored);
}
//------------------------------------------------------------------------------
//int GetJONSCultureLevel() const;
int CvLuaCity::lGetJONSCultureLevel(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::GetJONSCultureLevel);
}
//------------------------------------------------------------------------------
//void SetJONSCultureLevel(int iValue);
int CvLuaCity::lSetJONSCultureLevel(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::SetJONSCultureLevel);
}
//------------------------------------------------------------------------------
//void ChangeJONSCultureLevel(int iChange);
int CvLuaCity::lChangeJONSCultureLevel(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::ChangeJONSCultureLevel);
}
//------------------------------------------------------------------------------
//void DoJONSCultureLevelIncrease();
int CvLuaCity::lDoJONSCultureLevelIncrease(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::DoJONSCultureLevelIncrease);
}
//------------------------------------------------------------------------------
//int GetJONSCultureThreshold() const;
int CvLuaCity::lGetJONSCultureThreshold(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::GetJONSCultureThreshold);
}

//------------------------------------------------------------------------------
//int getJONSCulturePerTurn() const;
int CvLuaCity::lGetJONSCulturePerTurn(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getJONSCulturePerTurn);
}
//------------------------------------------------------------------------------
//int GetBaseJONSCulturePerTurn() const;
int CvLuaCity::lGetBaseJONSCulturePerTurn(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::GetBaseJONSCulturePerTurn);
}
//------------------------------------------------------------------------------
//int GetJONSCulturePerTurnFromBuildings() const;
int CvLuaCity::lGetJONSCulturePerTurnFromBuildings(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::GetJONSCulturePerTurnFromBuildings);
}
//------------------------------------------------------------------------------
//void ChangeJONSCulturePerTurnFromBuildings(int iChange);
int CvLuaCity::lChangeJONSCulturePerTurnFromBuildings(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	int iChange = lua_tointeger(L, 2);
	pkCity->ChangeBaseYieldRateFromBuildings(YIELD_CULTURE, iChange);
	return 0;
}
//------------------------------------------------------------------------------
//int GetJONSCulturePerTurnFromPolicies() const;
int CvLuaCity::lGetJONSCulturePerTurnFromPolicies(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::GetJONSCulturePerTurnFromPolicies);
}
//------------------------------------------------------------------------------
//void ChangeJONSCulturePerTurnFromPolicies(int iChange);
int CvLuaCity::lChangeJONSCulturePerTurnFromPolicies(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::ChangeJONSCulturePerTurnFromPolicies);
}
//------------------------------------------------------------------------------
//int GetJONSCulturePerTurnFromSpecialists() const;
int CvLuaCity::lGetJONSCulturePerTurnFromSpecialists(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	lua_pushinteger(L, pkCity->GetJONSCulturePerTurnFromSpecialists() + pkCity->GetBaseYieldRateFromSpecialists(YIELD_CULTURE));

	return 1;
}
//------------------------------------------------------------------------------
//void ChangeJONSCulturePerTurnFromSpecialists(int iChange);
int CvLuaCity::lChangeJONSCulturePerTurnFromSpecialists(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::ChangeJONSCulturePerTurnFromSpecialists);
}
//------------------------------------------------------------------------------
//int GetJONSCulturePerTurnFromGreatWorks() const;
int CvLuaCity::lGetJONSCulturePerTurnFromGreatWorks(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::GetJONSCulturePerTurnFromGreatWorks);
}
//------------------------------------------------------------------------------
//int GetJONSCulturePerTurnFromTraits() const;
int CvLuaCity::lGetJONSCulturePerTurnFromTraits(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::GetJONSCulturePerTurnFromTraits);
}
//------------------------------------------------------------------------------
//int GetJONSCulturePerTurnFromReligion() const;
int CvLuaCity::lGetJONSCulturePerTurnFromReligion(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::GetJONSCulturePerTurnFromReligion);
}
//------------------------------------------------------------------------------
//void ChangeBaseYieldRateFromReligion(YIELD_CULTURE, iChange);
int CvLuaCity::lChangeJONSCulturePerTurnFromReligion(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	int iChange = lua_tointeger(L, 2);
	pkCity->ChangeBaseYieldRateFromReligion(YIELD_CULTURE, iChange);
	return 0;
}
//------------------------------------------------------------------------------
//int GetJONSCulturePerTurnFromLeagues() const;
int CvLuaCity::lGetJONSCulturePerTurnFromLeagues(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::GetJONSCulturePerTurnFromLeagues);
}
//------------------------------------------------------------------------------
//int getCultureRateModifier() const;
int CvLuaCity::lGetCultureRateModifier(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getCultureRateModifier);
}
//------------------------------------------------------------------------------
//void changeCultureRateModifier(int iChange);
int CvLuaCity::lChangeCultureRateModifier(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::changeCultureRateModifier);
}
#if defined(MOD_API_LUA_EXTENSIONS)
//------------------------------------------------------------------------------
//int getTourismRateModifier() const;
int CvLuaCity::lGetTourismRateModifier(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getTourismRateModifier);
}
//------------------------------------------------------------------------------
//void changeTourismRateModifier(int iChange);
int CvLuaCity::lChangeTourismRateModifier(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::changeTourismRateModifier);
}
#endif
//------------------------------------------------------------------------------
//int GetNumGreatWorks();
int CvLuaCity::lGetNumGreatWorks(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
#if defined(MOD_API_LUA_EXTENSIONS) && defined(MOD_GLOBAL_GREATWORK_YIELDTYPES)
	const bool bIgnoreYield = luaL_optbool(L, 2, true);
	lua_pushinteger(L, pkCity->GetCityCulture()->GetNumGreatWorks(bIgnoreYield));
#else
	lua_pushinteger(L, pkCity->GetCityCulture()->GetNumGreatWorks());
#endif
	return 1;
}
//------------------------------------------------------------------------------
//int GetNumGreatWorkSlots();
int CvLuaCity::lGetNumGreatWorkSlots(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	lua_pushinteger(L, pkCity->GetCityCulture()->GetNumGreatWorkSlots());
	return 1;
}
//------------------------------------------------------------------------------
//int GetBaseTourism();
int CvLuaCity::lGetBaseTourism(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	lua_pushinteger(L, pkCity->GetBaseTourism());
	return 1;
}
//------------------------------------------------------------------------------
//int GetTourismMultiplier(PlayerTypes ePlayer);
int CvLuaCity::lGetTourismMultiplier(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const PlayerTypes ePlayer = (PlayerTypes)lua_tointeger(L, 2);
	lua_pushinteger(L, pkCity->GetCityCulture()->GetTourismMultiplier(ePlayer, false, false, false, false, false));
	return 1;
}
//------------------------------------------------------------------------------
//CvString GetTourismTooltip();
int CvLuaCity::lGetTourismTooltip(lua_State* L)
{
	CvString toolTip;
	CvCity* pkCity = GetInstance(L);
	toolTip = pkCity->GetCityCulture()->GetTourismTooltip();
	lua_pushstring(L, toolTip.c_str());
	return 1;
}
//------------------------------------------------------------------------------
//CvString GetFilledSlotsTooltip();
int CvLuaCity::lGetFilledSlotsTooltip(lua_State* L)
{
	CvString toolTip;
	CvCity* pkCity = GetInstance(L);
	toolTip = pkCity->GetCityCulture()->GetFilledSlotsTooltip();
	lua_pushstring(L, toolTip.c_str());
	return 1;
}
//------------------------------------------------------------------------------
//CvString GetTotalSlotsTooltip();
int CvLuaCity::lGetTotalSlotsTooltip(lua_State* L)
{
	CvString toolTip;
	CvCity* pkCity = GetInstance(L);
	toolTip = pkCity->GetCityCulture()->GetTotalSlotsTooltip();
	lua_pushstring(L, toolTip.c_str());
	return 1;
}
//------------------------------------------------------------------------------
//void ClearGreatWorks();
int CvLuaCity::lClearGreatWorks(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	pkCity->GetCityCulture()->ClearGreatWorks();
	return 1;
}
//------------------------------------------------------------------------------
// int GetFaithBuildingTourism()
int CvLuaCity::lGetFaithBuildingTourism(lua_State* L)
{
	int iRtnValue = 0;
	CvCity* pkCity = GetInstance(L);
	ReligionTypes eMajority = pkCity->GetCityReligions()->GetReligiousMajority();
	const CvReligion* pReligion = GC.getGame().GetGameReligions()->GetReligion(eMajority, pkCity->getOwner());
	if(pReligion)
	{
		iRtnValue = pReligion->m_Beliefs.GetFaithBuildingTourism();
	}
	lua_pushinteger(L, iRtnValue);
	return 1;
}
//------------------------------------------------------------------------------
//bool IsThemingBonusPossible(BuildingClassTypes eBuildingClass);
int CvLuaCity::lIsThemingBonusPossible(lua_State* L)
{
	bool bPossible;
	CvCity* pkCity = GetInstance(L);
	const BuildingClassTypes iIndex = toValue<BuildingClassTypes>(L, 2);
	bPossible = pkCity->GetCityCulture()->IsThemingBonusPossible(iIndex);
	lua_pushboolean(L, bPossible);
	return 1;
}
//------------------------------------------------------------------------------
//int GetThemingBonus(BuildingClassTypes eBuildingClass);
int CvLuaCity::lGetThemingBonus(lua_State* L)
{
	int iBonus;
	CvCity* pkCity = GetInstance(L);
	const BuildingClassTypes iIndex = toValue<BuildingClassTypes>(L, 2);
	iBonus = pkCity->GetCityCulture()->GetThemingBonus(iIndex);
	lua_pushinteger(L, iBonus);
	return 1;
}
//------------------------------------------------------------------------------
//CvString GetThemingTooltip(BuildingClassTypes eBuildingClass);
int CvLuaCity::lGetThemingTooltip(lua_State* L)
{
	CvString toolTip;
	CvCity* pkCity = GetInstance(L);
	const BuildingClassTypes iIndex = toValue<BuildingClassTypes>(L, 2);
	toolTip = pkCity->GetCityCulture()->GetThemingTooltip(iIndex);
	lua_pushstring(L, toolTip.c_str());
	return 1;
}
//------------------------------------------------------------------------------
//int GetFaithPerTurn() const;
int CvLuaCity::lGetFaithPerTurn(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::GetFaithPerTurn);
}
//------------------------------------------------------------------------------
//int GetFaithPerTurnFromBuildings() const;
int CvLuaCity::lGetFaithPerTurnFromBuildings(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::GetFaithPerTurnFromBuildings);
}
//------------------------------------------------------------------------------
//int GetFaithPerTurnFromPolicies() const;
int CvLuaCity::lGetFaithPerTurnFromPolicies(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::GetFaithPerTurnFromPolicies);
}
//------------------------------------------------------------------------------
//int GetFaithPerTurnFromTraits() const;
int CvLuaCity::lGetFaithPerTurnFromTraits(lua_State* L)
{

	CvCity* pkCity = GetInstance(L);
#if defined(MOD_API_UNIFIED_YIELDS)
	int iBonus = pkCity->GetYieldPerTurnFromUnimprovedFeatures(YIELD_FAITH);
#else
	int iBonus = pkCity->GetFaithPerTurnFromTraits();
#endif
	iBonus += pkCity->GetYieldPerTurnFromAdjacentFeatures(YIELD_FAITH);
	lua_pushinteger(L, iBonus);
	return 1;
}
//------------------------------------------------------------------------------
//int GetFaithPerTurnFromReligion() const;
int CvLuaCity::lGetFaithPerTurnFromReligion(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::GetFaithPerTurnFromReligion);
}
//------------------------------------------------------------------------------
//void ChangeBaseYieldRateFromReligion(YIELD_FAITH, iChange);
int CvLuaCity::lChangeFaithPerTurnFromReligion(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iChange = lua_tointeger(L, 2);
	pkCity->ChangeBaseYieldRateFromReligion(YIELD_FAITH, iChange);

	return 0;
}
//------------------------------------------------------------------------------
//int IsReligionInCity() const;
int CvLuaCity::lIsReligionInCity(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const bool bResult = pkCity->GetCityReligions()->IsReligionInCity();

	lua_pushboolean(L, bResult);
	return 1;
}
//------------------------------------------------------------------------------
//int IsHolyCityForReligion(ReligionTypes eReligion) const;
int CvLuaCity::lIsHolyCityForReligion(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	ReligionTypes eReligion = (ReligionTypes)lua_tointeger(L, 2);
	const bool bResult = pkCity->GetCityReligions()->IsHolyCityForReligion(eReligion);

	lua_pushboolean(L, bResult);
	return 1;
}
//------------------------------------------------------------------------------
//int IsHolyCityAnyReligion() const;
int CvLuaCity::lIsHolyCityAnyReligion(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const bool bResult = pkCity->GetCityReligions()->IsHolyCityAnyReligion();

	lua_pushboolean(L, bResult);
	return 1;
}
//------------------------------------------------------------------------------
//ReligionTypes GetReligionFoundedHere() const;
int CvLuaCity::lGetReligionFoundedHere(lua_State* L)
{
    CvCity* pkCity = GetInstance(L);
    const int iResult = (int)pkCity->GetCityReligions()->GetReligionFoundedHere();
    lua_pushinteger(L, iResult);
    return 1;
} 
//------------------------------------------------------------------------------
//int GetNumFollowers(ReligionTypes eReligion) const;
int CvLuaCity::lGetNumFollowers(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	ReligionTypes eReligion = (ReligionTypes)lua_tointeger(L, 2);
	const int iResult = pkCity->GetCityReligions()->GetNumFollowers(eReligion);

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int GetReligiousMajority() const;
int CvLuaCity::lGetReligiousMajority(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iResult = (int)pkCity->GetCityReligions()->GetReligiousMajority();
	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int GetSecondaryReligion() const;
int CvLuaCity::lGetSecondaryReligion(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iResult = (int)pkCity->GetCityReligions()->GetSecondaryReligion();
	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int GetSecondaryReligionPantheonBelief() const;
int CvLuaCity::lGetSecondaryReligionPantheonBelief(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iResult = (int)pkCity->GetCityReligions()->GetSecondaryReligionPantheonBelief();
	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int GetPressurePerTurn() const;
int CvLuaCity::lGetPressurePerTurn(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	ReligionTypes eReligion = (ReligionTypes)lua_tointeger(L, 2);
	int iNumTradeRoutes;
	const int iResult = (int)pkCity->GetCityReligions()->GetPressurePerTurn(eReligion, iNumTradeRoutes);
	lua_pushinteger(L, iResult);
	lua_pushinteger(L, iNumTradeRoutes);
	return 2;
}
//------------------------------------------------------------------------------
//int ConvertPercentFollowers(ReligionTypes eToReligion, ReligionTypes eFromReligion, int iPercent) const;
int CvLuaCity::lConvertPercentFollowers(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	ReligionTypes eToReligion = (ReligionTypes)lua_tointeger(L, 2);
	ReligionTypes eFromReligion = (ReligionTypes)lua_tointeger(L, 3);
	int iPercent = lua_tointeger(L, 4);
	pkCity->GetCityReligions()->ConvertPercentFollowers(eToReligion, eFromReligion, iPercent);
	return 1;
}
//------------------------------------------------------------------------------
//int AdoptReligionFully() const;
int CvLuaCity::lAdoptReligionFully(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	ReligionTypes eReligion = (ReligionTypes)lua_tointeger(L, 2);
	pkCity->GetCityReligions()->AdoptReligionFully(eReligion);
	return 1;
}
//------------------------------------------------------------------------------
//int lGetReligionBuildingClassHappiness(eBuildingClass) const;
int CvLuaCity::lGetReligionBuildingClassHappiness(lua_State* L)
{
	int iHappinessFromBuilding = 0;

	CvCity* pkCity = GetInstance(L);
	BuildingClassTypes eBuildingClass = (BuildingClassTypes)lua_tointeger(L, 2);

	ReligionTypes eMajority = pkCity->GetCityReligions()->GetReligiousMajority();
	if(eMajority != NO_RELIGION)
	{
		const CvReligion* pReligion = GC.getGame().GetGameReligions()->GetReligion(eMajority, pkCity->getOwner());
		if(pReligion)
		{	
			int iFollowers = pkCity->GetCityReligions()->GetNumFollowers(eMajority);
			iHappinessFromBuilding += pReligion->m_Beliefs.GetBuildingClassHappiness(eBuildingClass, iFollowers);
		}
	}
	lua_pushinteger(L, iHappinessFromBuilding);
	return 1;
}
//------------------------------------------------------------------------------
//int GetReligionBuildingClassYieldChange(eBuildingClass, eYieldType) const;
int CvLuaCity::lGetReligionBuildingClassYieldChange(lua_State* L)
{
	int iYieldFromBuilding = 0;

	CvCity* pkCity = GetInstance(L);
	BuildingClassTypes eBuildingClass = (BuildingClassTypes)lua_tointeger(L, 2);
	YieldTypes eYieldType = (YieldTypes)lua_tointeger(L, 3);

	ReligionTypes eMajority = pkCity->GetCityReligions()->GetReligiousMajority();
	if(eMajority != NO_RELIGION)
	{
		const CvReligion* pReligion = GC.getGame().GetGameReligions()->GetReligion(eMajority, pkCity->getOwner());
		if(pReligion)
		{	
			int iFollowers = pkCity->GetCityReligions()->GetNumFollowers(eMajority);
			iYieldFromBuilding += pReligion->m_Beliefs.GetBuildingClassYieldChange(eBuildingClass, eYieldType, iFollowers);
			BeliefTypes eSecondaryPantheon = pkCity->GetCityReligions()->GetSecondaryReligionPantheonBelief();
			if (eSecondaryPantheon != NO_BELIEF)
			{
				iFollowers =  pkCity->GetCityReligions()->GetNumFollowers(pkCity->GetCityReligions()->GetSecondaryReligion());
				if (iFollowers >= GC.GetGameBeliefs()->GetEntry(eSecondaryPantheon)->GetMinFollowers())
				{
					iYieldFromBuilding += GC.GetGameBeliefs()->GetEntry(eSecondaryPantheon)->GetBuildingClassYieldChange(eBuildingClass, eYieldType);
				}
			}
		}
	}
	lua_pushinteger(L, iYieldFromBuilding);
	return 1;
}
//------------------------------------------------------------------------------
//int GetLeagueBuildingClassYieldChange(eBuildingClass, eYieldType) const;
int CvLuaCity::lGetLeagueBuildingClassYieldChange(lua_State* L)
{
	int iYieldFromBuilding = 0;

	CvCity* pkCity = GetInstance(L);
	BuildingClassTypes eBuildingClass = (BuildingClassTypes)lua_tointeger(L, 2);
	YieldTypes eYieldType = (YieldTypes)lua_tointeger(L, 3);

	CvBuildingClassInfo* pInfo = GC.getBuildingClassInfo(eBuildingClass);
	if (pInfo && pInfo->getMaxGlobalInstances() != -1)
	{
		int iYieldChange = GC.getGame().GetGameLeagues()->GetWorldWonderYieldChange(pkCity->getOwner(), eYieldType);
		if (iYieldChange != 0)
		{
			iYieldFromBuilding += iYieldChange;
		}
	}

	lua_pushinteger(L, iYieldFromBuilding);
	return 1;
}
//------------------------------------------------------------------------------
int CvLuaCity::lGetNumTradeRoutesAddingPressure(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	ReligionTypes eReligion = (ReligionTypes)lua_tointeger(L, 2);
	
	int iNumTradeRoutes = pkCity->GetCityReligions()->GetNumTradeRouteConnections(eReligion);
	lua_pushinteger(L, iNumTradeRoutes);
	return 1;

}
//------------------------------------------------------------------------------
//int getNumWorldWonders();
int CvLuaCity::lGetNumWorldWonders(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getNumWorldWonders);
}
//------------------------------------------------------------------------------
//int getNumTeamWonders();
int CvLuaCity::lGetNumTeamWonders(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getNumTeamWonders);
}
//------------------------------------------------------------------------------
//int getNumNationalWonders();
int CvLuaCity::lGetNumNationalWonders(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getNumNationalWonders);
}
//------------------------------------------------------------------------------
//int getNumBuildings();
int CvLuaCity::lGetNumBuildings(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iResult = pkCity->GetCityBuildings()->GetNumBuildings();

	lua_pushinteger(L, iResult);
	return 1;
}

//------------------------------------------------------------------------------
//int GetWonderProductionModifier();
int CvLuaCity::lGetWonderProductionModifier(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::GetWonderProductionModifier);
}
//------------------------------------------------------------------------------
//void ChangeWonderProductionModifier(int iChange);
int CvLuaCity::lChangeWonderProductionModifier(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::ChangeWonderProductionModifier);
}
//------------------------------------------------------------------------------
//int GetLocalResourceWonderProductionMod(BuildingTypes eBuilding);
int CvLuaCity::lGetLocalResourceWonderProductionMod(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::GetLocalResourceWonderProductionMod);
}

#if defined(MOD_API_LUA_EXTENSIONS) && defined(MOD_GLOBAL_CITY_WORKING)
//------------------------------------------------------------------------------
//int GetBuyPlotDistance();
int CvLuaCity::lGetBuyPlotDistance(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getBuyPlotDistance);
}

//------------------------------------------------------------------------------
//void GetWorkPlotDistance();
int CvLuaCity::lGetWorkPlotDistance(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getWorkPlotDistance);
}
#endif

#if defined(MOD_API_LUA_EXTENSIONS) && defined(MOD_BUILDINGS_CITY_WORKING)
//------------------------------------------------------------------------------
//int getCityWorkingChange();
int CvLuaCity::lGetCityWorkingChange(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::GetCityWorkingChange);
}

//------------------------------------------------------------------------------
//void changeCityWorkingChange(int iChange);
int CvLuaCity::lChangeCityWorkingChange(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::changeCityWorkingChange);
}
#endif

#if defined(MOD_API_LUA_EXTENSIONS) && defined(MOD_BUILDINGS_CITY_AUTOMATON_WORKERS)
//------------------------------------------------------------------------------
//int getCityAutomatonWorkersChange();
int CvLuaCity::lGetCityAutomatonWorkersChange(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::GetCityAutomatonWorkersChange);
}

//------------------------------------------------------------------------------
//void changeCityAutomatonWorkersChange(int iChange);
int CvLuaCity::lChangeCityAutomatonWorkersChange(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::changeCityAutomatonWorkersChange);
}
#endif

//------------------------------------------------------------------------------
//void changeHealRate(int iChange);
int CvLuaCity::lChangeHealRate(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::changeHealRate);
}

//------------------------------------------------------------------------------
//bool IsNoOccupiedUnhappiness();
int CvLuaCity::lIsNoOccupiedUnhappiness(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::IsNoOccupiedUnhappiness);
}
//------------------------------------------------------------------------------
//int getFood();
int CvLuaCity::lGetFood(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getFood);
}
//------------------------------------------------------------------------------
//int getFoodTimes100();
int CvLuaCity::lGetFoodTimes100(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getFoodTimes100);
}
//------------------------------------------------------------------------------
//void setFood(int iNewValue);
int CvLuaCity::lSetFood(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::setFood);
}

//------------------------------------------------------------------------------
//void changeFood(int iChange);
int CvLuaCity::lChangeFood(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::changeFood);
}
//------------------------------------------------------------------------------
//int getFoodKept();
int CvLuaCity::lGetFoodKept(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getFoodKept);
}
//------------------------------------------------------------------------------
//int getMaxFoodKeptPercent();
int CvLuaCity::lGetMaxFoodKeptPercent(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getMaxFoodKeptPercent);
}
//------------------------------------------------------------------------------
//int getOverflowProduction();
int CvLuaCity::lGetOverflowProduction(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getOverflowProduction);
}
//------------------------------------------------------------------------------
//void setOverflowProduction(int iNewValue);
int CvLuaCity::lSetOverflowProduction(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::setOverflowProduction);
}
#if defined(MOD_API_LUA_EXTENSIONS)
//------------------------------------------------------------------------------
//void changeOverflowProduction(int iChange);
int CvLuaCity::lChangeOverflowProduction(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::changeOverflowProduction);
}
#endif
//------------------------------------------------------------------------------
//int getFeatureProduction();
int CvLuaCity::lGetFeatureProduction(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getFeatureProduction);
}
//------------------------------------------------------------------------------
//void setFeatureProduction(int iNewValue);
int CvLuaCity::lSetFeatureProduction(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::setFeatureProduction);
}
//------------------------------------------------------------------------------
//int getMilitaryProductionModifier();
int CvLuaCity::lGetMilitaryProductionModifier(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iResult = pkCity->getMilitaryProductionModifier();

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int getSpaceProductionModifier();
int CvLuaCity::lGetSpaceProductionModifier(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iResult = pkCity->getSpaceProductionModifier();

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//void CreateApolloProgram();
int CvLuaCity::lCreateApolloProgram(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	if(pkCity != NULL)
	{
		ProjectTypes eApolloProgram = (ProjectTypes)GC.getSPACE_RACE_TRIGGER_PROJECT();
		pkCity->CreateProject(eApolloProgram);
	}

	return 0;
}
//------------------------------------------------------------------------------
//int getBuildingDefense();
int CvLuaCity::lGetBuildingDefense(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iResult = pkCity->GetCityBuildings()->GetBuildingDefense();

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int getFreeExperience();
int CvLuaCity::lGetFreeExperience(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iResult = pkCity->getFreeExperience();

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int getNukeModifier();
int CvLuaCity::lGetNukeModifier(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iResult = pkCity->getNukeModifier();

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int getFreeSpecialist();
//int CvLuaCity::lGetFreeSpecialist(lua_State* L)
//{
//	CvCity* pkCity = GetInstance(L);
//	const int iResult = pkCity->getFreeSpecialist();
//
//	lua_pushinteger(L, iResult);
//	return 1;
//}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

//int IsResistance();
int CvLuaCity::lIsResistance(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::IsResistance);
}
//int GetResistanceTurns();
int CvLuaCity::lGetResistanceTurns(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::GetResistanceTurns);
}
//int ChangeResistanceTurns();
int CvLuaCity::lChangeResistanceTurns(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::ChangeResistanceTurns);
}

//int IsRazing();
int CvLuaCity::lIsRazing(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::IsRazing);
}
//int GetRazingTurns();
int CvLuaCity::lGetRazingTurns(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::GetRazingTurns);
}
//int ChangeRazingTurns();
int CvLuaCity::lChangeRazingTurns(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::ChangeRazingTurns);
}
//int HasEnableCrops();
int CvLuaCity::lHasEnableCrops(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::HasEnableCrops);
}
//------------------------------------------------------------------------------
//int HasEnableCrops();
int CvLuaCity::lHasEnableArmee(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::HasEnableArmee);
}
//------------------------------------------------------------------------------
//int IsOccupied();
int CvLuaCity::lIsOccupied(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::IsOccupied);
}
//------------------------------------------------------------------------------
//void SetOccupied(bool bValue);
int CvLuaCity::lSetOccupied(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::SetOccupied);
}
//------------------------------------------------------------------------------
//int IsPuppet();
int CvLuaCity::lIsPuppet(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::IsPuppet);
}
//------------------------------------------------------------------------------
//void SetPuppet(bool bValue);
int CvLuaCity::lSetPuppet(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::SetPuppet);
}

//------------------------------------------------------------------------------
int CvLuaCity::lGetHappinessFromBuildings(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::GetHappinessFromBuildings);
}
//------------------------------------------------------------------------------
int CvLuaCity::lGetLocalHappiness(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::GetLocalHappiness);
}


//------------------------------------------------------------------------------
int CvLuaCity::lGetHappiness(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);

	CvPlayerAI& kPlayer = GET_PLAYER(pkCity->getOwner());

	const int numPolicyInfos = GC.getNumPolicyInfos();
	const int numBuildingInfos = GC.getNumBuildingInfos();

	CvPlayerPolicies* pkPlayerPolicies = kPlayer.GetPlayerPolicies();
	CvCityBuildings* pkCityBuildings = pkCity->GetCityBuildings();

	int iHappiness = pkCity->GetHappinessFromBuildings();

	lua_pushinteger(L, iHappiness);
	return 1;
}
//------------------------------------------------------------------------------
//bool isNeverLost();
int CvLuaCity::lIsNeverLost(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::isNeverLost);
}
//------------------------------------------------------------------------------
//void setNeverLost(int iNewValue);
int CvLuaCity::lSetNeverLost(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::setNeverLost);
}
//------------------------------------------------------------------------------
//bool isDrafted();
int CvLuaCity::lIsDrafted(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::isDrafted);
}
//------------------------------------------------------------------------------
//void setDrafted(int iNewValue);
int CvLuaCity::lSetDrafted(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::setDrafted);
}

//------------------------------------------------------------------------------
int CvLuaCity::lIsBlockaded(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::IsBlockaded);
}

//------------------------------------------------------------------------------
//int GetWeLoveTheKingDayCounter();
int CvLuaCity::lGetWeLoveTheKingDayCounter(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::GetWeLoveTheKingDayCounter);
}
//------------------------------------------------------------------------------
//void SetWeLoveTheKingDayCounter(int iValue);
int CvLuaCity::lSetWeLoveTheKingDayCounter(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::SetWeLoveTheKingDayCounter);
}
//------------------------------------------------------------------------------
//void ChangeWeLoveTheKingDayCounter(int iChange);
int CvLuaCity::lChangeWeLoveTheKingDayCounter(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::ChangeWeLoveTheKingDayCounter);
}
//------------------------------------------------------------------------------
//void GetNumThingsProduced() const;
int CvLuaCity::lGetNumThingsProduced(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::GetNumThingsProduced);
}

//------------------------------------------------------------------------------
//bool isCitizensAutomated();
//int CvLuaCity::lIsCitizensAutomated(lua_State* L)
//{
//	return BasicLuaMethod(L, &CvCity::isCitizensAutomated);
//}
////------------------------------------------------------------------------------
////void setCitizensAutomated(bool bNewValue);
//int CvLuaCity::lSetCitizensAutomated(lua_State* L)
//{
//	return BasicLuaMethod(L, &CvCity::setCitizensAutomated);
//}
//------------------------------------------------------------------------------
//bool isProductionAutomated();
int CvLuaCity::lIsProductionAutomated(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::isProductionAutomated);
}
//------------------------------------------------------------------------------
//void setProductionAutomated(bool bNewValue);
int CvLuaCity::lSetProductionAutomated(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::setProductionAutomated);
}
//------------------------------------------------------------------------------
//void setCitySizeBoost(int iBoost);
int CvLuaCity::lSetCitySizeBoost(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::setCitySizeBoost);
}
//------------------------------------------------------------------------------
//PlayerTypes getOwner();
int CvLuaCity::lGetOwner(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getOwner);
}
//------------------------------------------------------------------------------
//TeamTypes getTeam();
int CvLuaCity::lGetTeam(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getTeam);
}
//------------------------------------------------------------------------------
//PlayerTypes getPreviousOwner();
int CvLuaCity::lGetPreviousOwner(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getPreviousOwner);
}
//------------------------------------------------------------------------------
//PlayerTypes getOriginalOwner();
int CvLuaCity::lGetOriginalOwner(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getOriginalOwner);
}
//------------------------------------------------------------------------------
//int getSeaPlotYield(YieldTypes eIndex);
int CvLuaCity::lGetSeaPlotYield(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const YieldTypes eIndex = (YieldTypes)lua_tointeger(L, 2);
	const int iResult = pkCity->getSeaPlotYield(eIndex);

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int getRiverPlotYield(YieldTypes eIndex);
int CvLuaCity::lGetRiverPlotYield(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const YieldTypes eIndex = (YieldTypes)lua_tointeger(L, 2);
	const int iResult = pkCity->getRiverPlotYield(eIndex);

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int getLakePlotYield(YieldTypes eIndex);
int CvLuaCity::lGetLakePlotYield(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const YieldTypes eIndex = (YieldTypes)lua_tointeger(L, 2);
	const int iResult = pkCity->getLakePlotYield(eIndex);

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int getBaseYieldRate(YieldTypes eIndex);
int CvLuaCity::lGetBaseYieldRate(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const YieldTypes eIndex = (YieldTypes)lua_tointeger(L, 2);
	const int iResult = pkCity->getBaseYieldRate(eIndex, false);

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//CvString getBaseYieldRate(YieldTypes eIndex);
int CvLuaCity::lGetYieldRateInfoTool(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const YieldTypes eIndex = (YieldTypes)lua_tointeger(L, 2);
	CvString toolTip = pkCity->getYieldRateInfoTool(eIndex);
	lua_pushstring(L, toolTip.c_str());
	return 1;
}

int CvLuaCity::lGetBaseYieldRateFromProjects(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::GetBaseYieldRateFromProjects);
}


//------------------------------------------------------------------------------
int CvLuaCity::lGetYieldPerEra(lua_State* L) {
    CvCity* pkCity = GetInstance(L);
	const YieldTypes eIndex = (YieldTypes)lua_tointeger(L, 2);
    CvPlayerAI& kPlayer = GET_PLAYER(pkCity->getOwner());
    int totalYield = (pkCity->GetYieldPerEra(eIndex)) *  (kPlayer.GetCurrentEra() + 1) * 100;
    lua_pushinteger(L, totalYield);
    return 1;
}

// int GetTradeRouteFromTheCityYieldsPerEra(YieldTypes eYield);
int CvLuaCity::lGetTradeRouteFromTheCityYieldsPerEra(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const YieldTypes eIndex = (YieldTypes) lua_tointeger(L, 2);
	const int iResult = pkCity->GetTradeRouteFromTheCityYieldsPerEra(eIndex);
	lua_pushinteger(L, iResult);
	return 1;
}

#if defined(MOD_API_LUA_EXTENSIONS) && defined(MOD_GLOBAL_GREATWORK_YIELDTYPES)
//------------------------------------------------------------------------------
int CvLuaCity::lGetBaseYieldRateFromGreatWorks(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::GetBaseYieldRateFromGreatWorks);
}
#endif
//------------------------------------------------------------------------------
int CvLuaCity::lGetBaseYieldRateFromPolicy(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::GetBaseYieldRateFromPolicy);
}
//------------------------------------------------------------------------------
int CvLuaCity::lGetBaseYieldRateFromTerrain(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::GetBaseYieldRateFromTerrain);
}
//------------------------------------------------------------------------------
int CvLuaCity::lChangeBaseYieldRateFromTerrain(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::ChangeBaseYieldRateFromTerrain);
}
//------------------------------------------------------------------------------
int CvLuaCity::lGetBaseYieldRateFromBuildings(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const YieldTypes eIndex = (YieldTypes)lua_tointeger(L, 2);
	const bool bIgnorePolicyBonus = luaL_optbool(L, 3, false);

	int iResult = pkCity->GetBaseYieldRateFromBuildings(eIndex);
	if(!bIgnorePolicyBonus && eIndex != YIELD_FAITH)
		iResult += pkCity->GetBaseYieldRateFromBuildingsPolicies(eIndex);

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
int CvLuaCity::lChangeBaseYieldRateFromBuildings(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::ChangeBaseYieldRateFromBuildings);
}
//------------------------------------------------------------------------------
int CvLuaCity::lGetBaseYieldRateFromSpecialists(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::GetBaseYieldRateFromSpecialists);
}
//------------------------------------------------------------------------------
int CvLuaCity::lChangeBaseYieldRateFromSpecialists(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::ChangeBaseYieldRateFromSpecialists);
}
//------------------------------------------------------------------------------
int CvLuaCity::lGetBaseYieldRateFromMisc(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::GetBaseYieldRateFromMisc);
}
//------------------------------------------------------------------------------
int CvLuaCity::lChangeBaseYieldRateFromMisc(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::ChangeBaseYieldRateFromMisc);
}

//------------------------------------------------------------------------------
int CvLuaCity::lGetBaseYieldRateFromReligion(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::GetBaseYieldRateFromReligion);
}
//------------------------------------------------------------------------------
int CvLuaCity::lChangeBaseYieldRateFromReligion(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::ChangeBaseYieldRateFromReligion);
}
//------------------------------------------------------------------------------
int CvLuaCity::lGetYieldPerPopTimes100(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::GetYieldPerPopTimes100);
}

//------------------------------------------------------------------------------
//int getBaseYieldRateModifier(YieldTypes eIndex, int iExtra = 0);
int CvLuaCity::lGetBaseYieldRateModifier(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const YieldTypes eIndex = (YieldTypes)lua_tointeger(L, 2);
	const int iExtra = luaL_optint(L, 3, 0);
	const int iResult = pkCity->getBaseYieldRateModifier(eIndex, iExtra);

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int getYieldRate(YieldTypes eIndex);
int CvLuaCity::lGetYieldRate(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const YieldTypes eIndex = (YieldTypes)lua_tointeger(L, 2);
	const bool bIgnoreTrade = luaL_optbool(L, 3, false);
	const int iResult = pkCity->getYieldRate(eIndex, bIgnoreTrade);

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int getYieldRateTimes100(YieldTypes eIndex);
int CvLuaCity::lGetYieldRateTimes100(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const YieldTypes eIndex = (YieldTypes)lua_tointeger(L, 2);
	const bool bIgnoreTrade = luaL_optbool(L, 3, false);
	const int iResult = pkCity->getYieldRateTimes100(eIndex, bIgnoreTrade);

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int getYieldRateModifier(YieldTypes eIndex);
int CvLuaCity::lGetYieldRateModifier(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const YieldTypes eIndex = (YieldTypes)lua_tointeger(L, 2);
	const int iResult = pkCity->getYieldRateModifier(eIndex);

	lua_pushinteger(L, iResult);
	return 1;
}

//------------------------------------------------------------------------------
//int getExtraSpecialistYield(YieldTypes eIndex);
int CvLuaCity::lGetExtraSpecialistYield(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const YieldTypes eIndex = (YieldTypes)lua_tointeger(L, 2);
	const int iResult = pkCity->getExtraSpecialistYield(eIndex);

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int getExtraSpecialistYieldOfType(YieldTypes eIndex, SpecialistTypes eSpecialist);
int CvLuaCity::lGetExtraSpecialistYieldOfType(lua_State* L)
{
	return BasicLuaMethod<int, YieldTypes, SpecialistTypes>(L, &CvCity::getExtraSpecialistYield);
}

//------------------------------------------------------------------------------
//int getDomainFreeExperience(DomainTypes eIndex);
int CvLuaCity::lGetDomainFreeExperience(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getDomainFreeExperience);
}

//------------------------------------------------------------------------------
//int getDomainFreeExperience(DomainTypes eIndex);
int CvLuaCity::lGetDomainFreeExperienceFromGreatWorks(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getDomainFreeExperienceFromGreatWorks);
}

//------------------------------------------------------------------------------
//int getDomainFreeExperience(DomainTypes eIndex);
int CvLuaCity::lGetDomainFreeExperienceFromGreatWorksGlobal(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getDomainFreeExperienceFromGreatWorksGlobal);
}

//------------------------------------------------------------------------------
//int getDomainProductionModifier(DomainTypes eIndex);
int CvLuaCity::lGetDomainProductionModifier(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getDomainProductionModifier);
}
//------------------------------------------------------------------------------
//bool isEverOwned(PlayerTypes eIndex);
int CvLuaCity::lIsEverOwned(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::isEverOwned);
}
//------------------------------------------------------------------------------
//bool isRevealed(TeamTypes eIndex, bool bDebug);
int CvLuaCity::lIsRevealed(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::isRevealed);
}
//------------------------------------------------------------------------------
//void setRevealed(TeamTypes eIndex, bool bNewValue);
int CvLuaCity::lSetRevealed(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::setRevealed);
}
//------------------------------------------------------------------------------
//std::string getName();
int CvLuaCity::lGetName(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	lua_pushstring(L, pkCity->getName());
	return 1;
}

//------------------------------------------------------------------------------
//std::string getNameForm(int iForm);
//------------------------------------------------------------------------------
//string GetNameKey();
int CvLuaCity::lGetNameKey(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	lua_pushstring(L, pkCity->getNameKey());
	return 1;
}
//------------------------------------------------------------------------------
//void SetName(string szNewValue, bool bFound);
int CvLuaCity::lSetName(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);

	const char* cityName = lua_tostring(L, 2);
	const bool bFound = luaL_optbool(L, 3, false);

	pkCity->setName(cityName, bFound);
	return 0;
}
//------------------------------------------------------------------------------
//bool IsHasResourceLocal(ResourceTypes iResource);
int CvLuaCity::lIsHasResourceLocal(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iResource = lua_tointeger(L, 2);
	const bool bTestVisible = lua_toboolean(L, 3);
	const bool bResult = pkCity->IsHasResourceLocal((ResourceTypes)iResource, bTestVisible);

	lua_pushboolean(L, bResult);
	return 1;
}
//------------------------------------------------------------------------------
//int getBuildingProduction(BuildingTypes iIndex);
int CvLuaCity::lGetBuildingProduction(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iIndex = lua_tointeger(L, 2);
	if(iIndex != NO_BUILDING)
	{
		const int iResult = pkCity->GetCityBuildings()->GetBuildingProduction((BuildingTypes)iIndex);
		lua_pushinteger(L, iResult);
	}
	else
	{
		lua_pushinteger(L, 0);
	}
	return 1;
}
//------------------------------------------------------------------------------
//void setBuildingProduction(BuildingTypes iIndex, int iNewValue);
int CvLuaCity::lSetBuildingProduction(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iIndex = lua_tointeger(L, 2);
	const int iNewValue = lua_tointeger(L, 3);
	if(iIndex != NO_BUILDING)
	{
		pkCity->GetCityBuildings()->SetBuildingProduction((BuildingTypes)iIndex, iNewValue);
	}

	return 1;
}
//------------------------------------------------------------------------------
//void changeBuildingProduction(BuildingTypes iIndex, int iChange);
int CvLuaCity::lChangeBuildingProduction(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iIndex = lua_tointeger(L, 2);
	const int iChange = lua_tointeger(L, 3);
	if(iIndex != NO_BUILDING)
	{
		pkCity->GetCityBuildings()->ChangeBuildingProduction((BuildingTypes)iIndex, iChange);
	}

	return 1;
}
//------------------------------------------------------------------------------
//int getBuildingProductionTime(BuildingTypes eIndex);
int CvLuaCity::lGetBuildingProductionTime(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iIndex = lua_tointeger(L, 2);
	if(iIndex != NO_BUILDING)
	{
		const int iResult = pkCity->GetCityBuildings()->GetBuildingProductionTime((BuildingTypes)iIndex);
		lua_pushinteger(L, iResult);
	}
	else
	{
		lua_pushinteger(L, 0);
	}
	return 1;
}
//------------------------------------------------------------------------------
//void setBuildingProductionTime(BuildingTypes eIndex, int iNewValue);
int CvLuaCity::lSetBuildingProductionTime(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iIndex = lua_tointeger(L, 2);
	const int iNewValue = lua_tointeger(L, 3);
	if(iIndex != NO_BUILDING)
	{
		pkCity->GetCityBuildings()->SetBuildingProductionTime((BuildingTypes)iIndex, iNewValue);
	}

	return 1;
}
//------------------------------------------------------------------------------
//void changeBuildingProductionTime(BuildingTypes eIndex, int iChange);
int CvLuaCity::lChangeBuildingProductionTime(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iIndex = toValue<BuildingTypes>(L, 2);
	if(iIndex != NO_BUILDING)
	{
		pkCity->GetCityBuildings()->ChangeBuildingProductionTime((BuildingTypes)iIndex, toValue<int>(L, 3));
	}

	return 1;
}
//------------------------------------------------------------------------------
//int getBuildingOriginalOwner(BuildingTypes iIndex);
int CvLuaCity::lGetBuildingOriginalOwner(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iIndex = toValue<BuildingTypes>(L, 2);
	if(iIndex != NO_BUILDING)
	{
		const int iResult = pkCity->GetCityBuildings()->GetBuildingOriginalOwner((BuildingTypes)iIndex);
		lua_pushinteger(L, iResult);
	}
	else
	{
		lua_pushinteger(L, -1);
	}
	return 1;
}
//------------------------------------------------------------------------------
//int getBuildingOriginalTime(BuildingTypes iIndex);
int CvLuaCity::lGetBuildingOriginalTime(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iIndex = toValue<BuildingTypes>(L, 2);
	if(iIndex != NO_BUILDING)
	{
		const int iResult = pkCity->GetCityBuildings()->GetBuildingOriginalTime((BuildingTypes)iIndex);
		lua_pushinteger(L, iResult);
	}
	else
	{
		lua_pushinteger(L, 0);
	}
	return 1;
}
//------------------------------------------------------------------------------
//int getUnitProduction(int iIndex);
int CvLuaCity::lGetUnitProduction(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iResult = pkCity->getUnitProduction(toValue<UnitTypes>(L, 2));

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//void setUnitProduction(int iIndex, int iNewValue);
int CvLuaCity::lSetUnitProduction(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	pkCity->setUnitProduction(toValue<UnitTypes>(L, 2), toValue<int>(L, 3));

	return 1;
}
//------------------------------------------------------------------------------
//void changeUnitProduction(UnitTypes iIndex, int iChange);
int CvLuaCity::lChangeUnitProduction(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	pkCity->changeUnitProduction(toValue<UnitTypes>(L, 2), toValue<int>(L, 3));

	return 1;
}
//------------------------------------------------------------------------------
//int IsCanAddSpecialistToBuilding(BuildingTypes eBuilding);
int CvLuaCity::lIsCanAddSpecialistToBuilding(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	BuildingTypes bt = toValue<BuildingTypes>(L, 2);
	if(bt != NO_BUILDING)
	{
		const bool bResult = pkCity->GetCityCitizens()->IsCanAddSpecialistToBuilding(bt);
		lua_pushboolean(L, bResult);
	}
	else
	{
		lua_pushboolean(L, false);
	}
	return 1;
}
//------------------------------------------------------------------------------
//int GetSpecialistUpgradeThreshold();
int CvLuaCity::lGetSpecialistUpgradeThreshold(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const UnitClassTypes eUnitClassType = toValue<UnitClassTypes>(L, 2);
	const int iResult = pkCity->GetCityCitizens()->GetSpecialistUpgradeThreshold(eUnitClassType);

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int GetNumSpecialistsAllowedByBuilding(BuildingTypes eBuilding);
int CvLuaCity::lGetNumSpecialistsAllowedByBuilding(lua_State* L)
{
	int iResult = 0;
	CvCity* pkCity = GetInstance(L);
	BuildingTypes bt = toValue<BuildingTypes>(L, 2);
	if(bt != NO_BUILDING)
	{
		CvBuildingEntry* pkBuildingInfo = GC.getBuildingInfo(bt);
		if(pkBuildingInfo)
		{
			iResult = pkCity->GetCityCitizens()->GetNumSpecialistsAllowedByBuilding(*pkBuildingInfo);
		}
	}

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int getSpecialistCount(SpecialistTypes eIndex);
int CvLuaCity::lGetSpecialistCount(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iIndex = lua_tointeger(L, 2);
	const int iResult = pkCity->GetCityCitizens()->GetSpecialistCount(toValue<SpecialistTypes>(L, 2));

	lua_pushinteger(L, iResult);
	return 1;
}


//int getProjectCount(ProjectTypes eProject);
int CvLuaCity::lGetProjectCount(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iIndex = lua_tointeger(L, 2);
	const int iResult = pkCity->getProjectCount(toValue<ProjectTypes>(L, 2));

	lua_pushinteger(L, iResult);
	return 1;
}

#if defined(MOD_ROG_CORE)
//------------------------------------------------------------------------------
//int GetTotalSpecialistCount();
int CvLuaCity::lGetTotalSpecialistCount(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iResult = pkCity->GetCityCitizens()->GetTotalSpecialistCount();

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int lGetSpecialistCityModifier(SpecialistTypes eIndex);
int CvLuaCity::lGetSpecialistCityModifier(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iIndex = lua_tointeger(L, 2);
	int iResult = pkCity->GetSpecialistRateModifier(toValue<SpecialistTypes>(L, 2));

	GreatPersonTypes eGreatPerson = GetGreatPersonFromSpecialist((SpecialistTypes)toValue<SpecialistTypes>(L, 2));

	if (eGreatPerson != NO_GREATPERSON)
	{

		if (GET_PLAYER(pkCity->getOwner()).getGoldenAgeTurns() > 0)
		{
			ReligionTypes eMajority = pkCity->GetCityReligions()->GetReligiousMajority();
			BeliefTypes eSecondaryPantheon = NO_BELIEF;
			if (eMajority != NO_RELIGION)
			{
				const CvReligion* pReligion = GC.getGame().GetGameReligions()->GetReligion(eMajority, pkCity->getOwner());
				if (pReligion)
				{
					iResult += pReligion->m_Beliefs.GetGoldenAgeGreatPersonRateModifier(eGreatPerson);
					eSecondaryPantheon = pkCity->GetCityReligions()->GetSecondaryReligionPantheonBelief();
					if (eSecondaryPantheon != NO_BELIEF)
					{
						iResult += GC.GetGameBeliefs()->GetEntry(eSecondaryPantheon)->GetGoldenAgeGreatPersonRateModifier(eGreatPerson);
					}
				}
			}
		}
	}

	lua_pushinteger(L, iResult);
	return 1;
}
#endif
//------------------------------------------------------------------------------
//int GetSpecialistGreatPersonProgress(SpecialistTypes eIndex);
int CvLuaCity::lGetSpecialistGreatPersonProgress(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iIndex = lua_tointeger(L, 2);
	const int iResult = pkCity->GetCityCitizens()->GetSpecialistGreatPersonProgress(toValue<SpecialistTypes>(L, 2));

	lua_pushinteger(L, iResult);
	return 1;
}

//------------------------------------------------------------------------------
//int GetSpecialistGreatPersonProgressTimes100(SpecialistTypes eIndex);
int CvLuaCity::lGetSpecialistGreatPersonProgressTimes100(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iIndex = lua_tointeger(L, 2);
	const int iResult = pkCity->GetCityCitizens()->GetSpecialistGreatPersonProgressTimes100(toValue<SpecialistTypes>(L, 2));

	lua_pushinteger(L, iResult);
	return 1;
}

//------------------------------------------------------------------------------
//int ChangeSpecialistGreatPersonProgressTimes100(SpecialistTypes eIndex, int iChange);
int CvLuaCity::lChangeSpecialistGreatPersonProgressTimes100(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iIndex = lua_tointeger(L, 2);
	const int iChange = lua_tointeger(L, 3);
	pkCity->GetCityCitizens()->ChangeSpecialistGreatPersonProgressTimes100(toValue<SpecialistTypes>(L, 2), iChange);

	return 1;
}

//------------------------------------------------------------------------------
//int GetNumSpecialistsInBuilding(BuildingTypes eIndex);
int CvLuaCity::lGetNumSpecialistsInBuilding(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iIndex = lua_tointeger(L, 2);
	const int iResult = pkCity->GetCityCitizens()->GetNumSpecialistsInBuilding(toValue<BuildingTypes>(L, 2));

	lua_pushinteger(L, iResult);
	return 1;
}

//------------------------------------------------------------------------------
//int DoReallocateCitizens();
int CvLuaCity::lDoReallocateCitizens(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	pkCity->GetCityCitizens()->DoReallocateCitizens();

	return 1;
}

//------------------------------------------------------------------------------
//int DoVerifyWorkingPlots();
int CvLuaCity::lDoVerifyWorkingPlots(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	pkCity->GetCityCitizens()->DoVerifyWorkingPlots();

	return 1;
}

//------------------------------------------------------------------------------
//int IsNoAutoAssignSpecialists();
int CvLuaCity::lIsNoAutoAssignSpecialists(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const bool bResult = pkCity->GetCityCitizens()->IsNoAutoAssignSpecialists();

	lua_pushboolean(L, bResult);

	return 1;
}

//------------------------------------------------------------------------------
#if defined(MOD_BELIEF_NEW_EFFECT_FOR_SP)
int CvLuaCity::lGetGreatPersonPointFromReligion(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const SpecialistTypes eSpecialist = (SpecialistTypes)lua_tointeger(L, 2);
	if(eSpecialist != NO_SPECIALIST)
	{
		lua_pushinteger(L, pkCity->GetGreatPersonPointsFromReligion(GetGreatPersonFromSpecialist(eSpecialist)));
		return 1;
	}

	lua_pushinteger(L, 0);
	return 1;
}
#endif
//------------------------------------------------------------------------------
//int GetFocusType();
int CvLuaCity::lGetFocusType(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iResult = pkCity->GetCityCitizens()->GetFocusType();

	lua_pushinteger(L, iResult);

	return 1;
}

//------------------------------------------------------------------------------
//int DoVerifyWorkingPlots();
int CvLuaCity::lSetFocusType(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iFocus = lua_tointeger(L, 2);

	pkCity->GetCityCitizens()->SetFocusType((CityAIFocusTypes) iFocus);

	return 1;
}

//------------------------------------------------------------------------------
//int GetForcedAvoidGrowth();
int CvLuaCity::lIsForcedAvoidGrowth(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iResult = pkCity->GetCityCitizens()->IsForcedAvoidGrowth();

	lua_pushboolean(L, iResult);

	return 1;
}



//------------------------------------------------------------------------------
//int getUnitCombatFreeExperience(UnitCombatTypes eIndex);
int CvLuaCity::lGetUnitCombatFreeExperience(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getUnitCombatFreeExperience);
}
//------------------------------------------------------------------------------
//int getFreePromotionCount(PromotionTypes eIndex);
int CvLuaCity::lGetFreePromotionCount(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getFreePromotionCount);
}
//------------------------------------------------------------------------------
//bool isFreePromotion(PromotionTypes eIndex);
int CvLuaCity::lIsFreePromotion(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::isFreePromotion);
}
//------------------------------------------------------------------------------
//int getSpecialistFreeExperience();
int CvLuaCity::lGetSpecialistFreeExperience(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iResult = pkCity->getSpecialistFreeExperience();

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//void updateStrengthValue();
int CvLuaCity::lUpdateStrengthValue(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	pkCity->updateStrengthValue();

	return 1;
}
//------------------------------------------------------------------------------
//int getStrengthValue();
int CvLuaCity::lGetStrengthValue(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	bool bForRangeStrike = luaL_optbool(L, 2, false);
	const int iResult = pkCity->getStrengthValue(bForRangeStrike);

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int getDamage();
int CvLuaCity::lGetDamage(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iResult = pkCity->getDamage();

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//void setDamage(int iValue);
int CvLuaCity::lSetDamage(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::setDamage);
}

//------------------------------------------------------------------------------
//void changeDamage(int iChange);
int CvLuaCity::lChangeDamage(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::changeDamage);
}
//------------------------------------------------------------------------------
//int GetMaxHitPoints();
int CvLuaCity::lGetMaxHitPoints(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iResult = pkCity->GetMaxHitPoints();

	lua_pushinteger(L, iResult);
	return 1;
}
#if defined(MOD_EVENTS_CITY_BOMBARD)
//int, bool GetBombardRange();
int CvLuaCity::lGetBombardRange(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	bool bIndirectFireAllowed;
	const int iResult = pkCity->getBombardRange(bIndirectFireAllowed);

	lua_pushinteger(L, iResult);
	lua_pushinteger(L, bIndirectFireAllowed);
	return 2;
}
#endif
//------------------------------------------------------------------------------
//bool CanRangeStrike()
int CvLuaCity::lCanRangeStrike(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::canRangeStrike);
}
//------------------------------------------------------------------------------
int CvLuaCity::lCanRangeStrikeNow(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::CanRangeStrikeNow);
}
//------------------------------------------------------------------------------
//bool CanRangeStrikeAt(int x, int y)
int CvLuaCity::lCanRangeStrikeAt(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::canRangeStrikeAt);
}
//------------------------------------------------------------------------------
int CvLuaCity::lHasPerformedRangedStrikeThisTurn(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::isMadeAttack);
}
//------------------------------------------------------------------------------
int CvLuaCity::lRangeCombatUnitDefense(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	CvUnit* pkDefender = CvLuaUnit::GetInstance(L, 2);

	const int iDefenseStr = pkCity->rangeCombatUnitDefense(pkDefender);
	lua_pushinteger(L, iDefenseStr);
	return 1;
}
//------------------------------------------------------------------------------
int CvLuaCity::lRangeCombatDamage(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	CvUnit* pkDefendingUnit = CvLuaUnit::GetInstance(L, 2, false);
	CvCity* pkDefendingCity = GetInstance(L, 3, false);
	bool bIncludeRand = luaL_optbool(L, 4, false);

	const int iRangedDamage = pkCity->rangeCombatDamage(pkDefendingUnit, pkDefendingCity, bIncludeRand);
	lua_pushinteger(L, iRangedDamage);
	return 1;
}
//------------------------------------------------------------------------------
int CvLuaCity::lGetAirStrikeDefenseDamage(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	CvUnit* pkAttackingUnit = CvLuaUnit::GetInstance(L, 2, false);
	bool bIncludeRand = luaL_optbool(L, 3, false);

	const int iRangedDamage = pkCity->GetAirStrikeDefenseDamage(pkAttackingUnit, bIncludeRand);
	lua_pushinteger(L, iRangedDamage);
	return 1;
}
//------------------------------------------------------------------------------
//bool isWorkingPlot(CyPlot* pPlot);
int CvLuaCity::lIsWorkingPlot(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	CvPlot* pkPlot = CvLuaPlot::GetInstance(L, 2);
	const bool bResult = pkCity->GetCityCitizens()->IsWorkingPlot(pkPlot);

	lua_pushboolean(L, bResult);
	return 1;
}
//------------------------------------------------------------------------------
//void alterWorkingPlot(int iIndex);
int CvLuaCity::lAlterWorkingPlot(lua_State* L)
{
//	return BasicLuaMethod(L, &CvCity::GetCityCitizens()->DoAlterWorkingPlot);
	CvCity* pkCity = GetInstance(L);
	const int iIndex = lua_tointeger(L, 2);
	pkCity->GetCityCitizens()->DoAlterWorkingPlot(iIndex);

	return 1;
}
//------------------------------------------------------------------------------
//bool IsForcedWorkingPlot(CyPlot* pPlot);
int CvLuaCity::lIsForcedWorkingPlot(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	CvPlot* pkPlot = CvLuaPlot::GetInstance(L, 2);
	const bool bResult = pkCity->GetCityCitizens()->IsForcedWorkingPlot(pkPlot);

	lua_pushboolean(L, bResult);
	return 1;
}
//------------------------------------------------------------------------------
//void SetForcedWorkingPlot(CyPlot* pPlot);
int CvLuaCity::lSetForcedWorkingPlot(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	CvPlot* pkPlot = CvLuaPlot::GetInstance(L, 2);
	bool bNewValue = luaL_optbool(L, 3, false);
	pkCity->GetCityCitizens()->SetForcedWorkingPlot(pkPlot, bNewValue);

	return 1;
}
//------------------------------------------------------------------------------
//bool GetNumForcedWorkingPlots(CyPlot* pPlot);
int CvLuaCity::lGetNumForcedWorkingPlots(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iResult = pkCity->GetCityCitizens()->GetNumForcedWorkingPlots();

	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int getNumRealBuilding(BuildingTypes iIndex);
int CvLuaCity::lGetNumRealBuilding(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const BuildingTypes iIndex = toValue<BuildingTypes>(L, 2);
	if(iIndex != NO_BUILDING)
	{
		const int iResult = pkCity->GetCityBuildings()->GetNumRealBuilding(iIndex);
		lua_pushinteger(L, iResult);
	}
	else
	{
		lua_pushinteger(L, 0);
	}
	return 1;
}
//------------------------------------------------------------------------------
//void setNumRealBuilding(BuildingTypes iIndex, int iNewValue);
int CvLuaCity::lSetNumRealBuilding(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const BuildingTypes iIndex = toValue<BuildingTypes>(L, 2);
	if(iIndex != NO_BUILDING)
	{
		const int iNewValue = lua_tointeger(L, 3);
		pkCity->GetCityBuildings()->SetNumRealBuilding(iIndex, iNewValue);
	}

	return 1;
}
//------------------------------------------------------------------------------
//int getNumFreeBuilding(BuildingTypes iIndex);
int CvLuaCity::lGetNumFreeBuilding(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const BuildingTypes iIndex = toValue<BuildingTypes>(L, 2);
	if(iIndex != NO_BUILDING)
	{
		const int iResult = pkCity->GetCityBuildings()->GetNumFreeBuilding(iIndex);
		lua_pushinteger(L, iResult);
	}
	else
	{
		lua_pushinteger(L, 0);
	}
	return 1;
}
#if defined(MOD_API_LUA_EXTENSIONS)
//------------------------------------------------------------------------------
//void SetNumFreeBuilding(BuildingTypes iIndex, int iNewValue);
int CvLuaCity::lSetNumFreeBuilding(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const BuildingTypes iIndex = toValue<BuildingTypes>(L, 2);
	if(iIndex != NO_BUILDING)
	{
		const int iNewValue = lua_tointeger(L, 3);
		pkCity->GetCityBuildings()->SetNumFreeBuilding(iIndex, iNewValue);
	}

	return 0;
}
#endif
//------------------------------------------------------------------------------
//bool IsBuildingSellable(BuildingTypes iIndex);
int CvLuaCity::lIsBuildingSellable(lua_State* L)
{
	bool bResult = false;
	CvCity* pkCity = GetInstance(L);
	const BuildingTypes iIndex = toValue<BuildingTypes>(L, 2);
	if(iIndex != NO_BUILDING)
	{
		CvBuildingEntry* pkBuildingInfo = GC.getBuildingInfo(iIndex);
		if(pkBuildingInfo)
		{
			bResult = pkCity->GetCityBuildings()->IsBuildingSellable(*pkBuildingInfo);
		}
	}

	lua_pushboolean(L, bResult);
	return 1;
}

//------------------------------------------------------------------------------
//int GetSellBuildingRefund(BuildingTypes iIndex);
int CvLuaCity::lGetSellBuildingRefund(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const BuildingTypes iIndex = toValue<BuildingTypes>(L, 2);
	if(iIndex != NO_BUILDING)
	{
		const int iResult = pkCity->GetCityBuildings()->GetSellBuildingRefund(iIndex);
		lua_pushinteger(L, iResult);
	}
	else
	{
		lua_pushinteger(L, 0);
	}
	return 1;
}

//------------------------------------------------------------------------------
//int GetTotalBaseBuildingMaintenance(BuildingTypes iIndex);
int CvLuaCity::lGetTotalBaseBuildingMaintenance(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iResult = pkCity->GetCityBuildings()->GetTotalBaseBuildingMaintenance();
	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int GetBuildingGreatWork(BuildingClassTypes eBuildingClass, int iSlot) const;
int CvLuaCity::lGetBuildingGreatWork(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const BuildingClassTypes iIndex = toValue<BuildingClassTypes>(L, 2);
	const int iSlot = lua_tointeger(L, 3);
	const int iResult = pkCity->GetCityBuildings()->GetBuildingGreatWork(iIndex, iSlot);
	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//int SetBuildingGreatWork(BuildingClassTypes eBuildingClass, int iSlot, int iGreatWorkIndex);
int CvLuaCity::lSetBuildingGreatWork(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const BuildingClassTypes iIndex = toValue<BuildingClassTypes>(L, 2);
	const int iSlot = lua_tointeger(L, 3);
	const int iGreatWorkIndex = lua_tointeger(L, 4);
	if(iIndex != NO_BUILDING)
	{
		pkCity->GetCityBuildings()->SetBuildingGreatWork(iIndex, iSlot, iGreatWorkIndex);
	}
	return 1;
}
//------------------------------------------------------------------------------
//int IsHoldingGreatWork(BuildingClassTypes eBuildingClass) const;
int CvLuaCity::lIsHoldingGreatWork(lua_State* L)
{
	bool bResult = false;
	CvCity* pkCity = GetInstance(L);
	const BuildingClassTypes iIndex = toValue<BuildingClassTypes>(L, 2);
	if(iIndex != NO_BUILDINGCLASS)
	{
		CvBuildingClassInfo* pkBuildingClassInfo = GC.getBuildingClassInfo(iIndex);
		if(pkBuildingClassInfo)
		{
			bResult = pkCity->GetCityBuildings()->IsHoldingGreatWork(iIndex);
		}
	}
	lua_pushboolean(L, bResult);
	return 1;
}
//------------------------------------------------------------------------------
//int GetNumGreatWorksInBuilding(BuildingClassTypes eBuildingClass) const;
int CvLuaCity::lGetNumGreatWorksInBuilding(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const BuildingClassTypes iIndex = toValue<BuildingClassTypes>(L, 2);
	const int iResult = pkCity->GetCityBuildings()->GetNumGreatWorksInBuilding(iIndex);
	lua_pushinteger(L, iResult);
	return 1;
}
//------------------------------------------------------------------------------
//void clearOrderQueue();
int CvLuaCity::lClearOrderQueue(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::clearOrderQueue);
}
//------------------------------------------------------------------------------
//void pushOrder(OrderTypes eOrder, int iData1, int iData2, bool bSave, bool bPop, bool bAppend, bool bForce);
int CvLuaCity::lPushOrder(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const OrderTypes eOrder	= (OrderTypes)lua_tointeger(L, 2);
	const int iData1		= lua_tointeger(L, 3);
	const int iData2		= lua_tointeger(L, 4);
	const bool bSave		= lua_tointeger(L, 5); // While this looks like a bug (should be lua_toboolean), fixing it will break a large number of game core .lua files!
	const bool bPop			= lua_toboolean(L, 6);
	const bool bAppend		= lua_toboolean(L, 7);
	const bool bForce		= luaL_optint(L, 8, 0);
	pkCity->pushOrder(eOrder, iData1, iData2, bSave, bPop, bAppend, bForce);

	return 1;
}
//------------------------------------------------------------------------------
//void popOrder(int iNum, bool bFinish, bool bChoose);
int CvLuaCity::lPopOrder(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int iNum = lua_tointeger(L, 2);
	const bool bFinish = luaL_optint(L, 3, 0);
	const bool bChoose = luaL_optint(L, 4, 0);
	pkCity->popOrder(iNum, bFinish, bChoose);

	return 1;
}
//------------------------------------------------------------------------------
//int getOrderQueueLength();
int CvLuaCity::lGetOrderQueueLength(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::getOrderQueueLength);
}
//------------------------------------------------------------------------------
//OrderData* getOrderFromQueue(int iIndex);
//------------------------------------------------------------------------------
int CvLuaCity::lGetOrderFromQueue(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	if(pkCity)
	{
		const int iNum = lua_tointeger(L, 2);
		OrderData* pkOrder = pkCity->getOrderFromQueue(iNum);
		if(pkOrder)
		{
			lua_pushinteger(L, pkOrder->eOrderType);
			lua_pushinteger(L, pkOrder->iData1);
#if defined(MOD_BUGFIX_LUA_API)
			lua_pushinteger(L, pkOrder->iData2);
#else
			lua_pushinteger(L, pkOrder->iData1);
#endif
			lua_pushboolean(L, pkOrder->bSave);
			lua_pushboolean(L, pkOrder->bRush);
			return 5;
		}
	}
	lua_pushinteger(L, -1);
	lua_pushinteger(L, 0);
	lua_pushinteger(L, 0);
	lua_pushboolean(L, false);
	lua_pushboolean(L, false);
	return 5;
}

//int getBuildingYieldChange(BuildingClassTypes eBuildingClass, YieldTypes eYield);
int CvLuaCity::lGetBuildingYieldChange(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int eBuildingClass = lua_tointeger(L, 2);
	const int eYield = lua_tointeger(L, 3);
	const int iResult = pkCity->GetCityBuildings()->GetBuildingYieldChange((BuildingClassTypes)eBuildingClass, (YieldTypes)eYield);

	lua_pushinteger(L, iResult);
	return 1;
}

//int GetBuildingEspionageModifier(BuildingClassTypes eBuildingClass)
int CvLuaCity::lGetBuildingEspionageModifier(lua_State* L)
{
	//CvCity* pkCity = GetInstance(L);
	const BuildingTypes eBuilding = (BuildingTypes) lua_tointeger(L, 2);
	CvBuildingEntry* pBuildingInfo = GC.getBuildingInfo(eBuilding);
	CvAssertMsg(pBuildingInfo, "pBuildingInfo is null!");
	if (pBuildingInfo)
	{
		lua_pushinteger(L, pBuildingInfo->GetEspionageModifier());
	}
	else
	{
		lua_pushinteger(L, 0);
	}
	return 1;
}

// int GetBuildingGlobalEspionageModifier(BuildingClassTypes eBuildingClass)
int CvLuaCity::lGetBuildingGlobalEspionageModifier(lua_State* L)
{
	const BuildingTypes eBuilding = (BuildingTypes)lua_tointeger(L, 2);
	CvBuildingEntry* pBuildingInfo = GC.getBuildingInfo(eBuilding);
	CvAssertMsg(pBuildingInfo, "pBuildingInfo is null!");
	if (pBuildingInfo)
	{
		lua_pushinteger(L, pBuildingInfo->GetGlobalEspionageModifier());
	}
	else
	{
		lua_pushinteger(L, 0);
	}
	return 1;
}

#if defined(MOD_API_LUA_EXTENSIONS) && defined(MOD_API_ESPIONAGE)
//------------------------------------------------------------------------------
int CvLuaCity::lHasDiplomat(lua_State* L)
{
	bool bResult = false;
	CvCity* pkCity = GetInstance(L);
	const PlayerTypes iPlayer = toValue<PlayerTypes>(L, 2);
	if(iPlayer != NO_PLAYER && pkCity->isCapital())
	{
		int iSpyIndex = pkCity->GetCityEspionage()->m_aiSpyAssignment[iPlayer];
		bResult = (iSpyIndex != -1 && GET_PLAYER(iPlayer).GetEspionage()->IsDiplomat(iSpyIndex));
	}
	lua_pushboolean(L, bResult);
	return 1;
}
//------------------------------------------------------------------------------
int CvLuaCity::lHasSpy(lua_State* L)
{
	bool bResult = false;
	CvCity* pkCity = GetInstance(L);
	const PlayerTypes iPlayer = toValue<PlayerTypes>(L, 2);
	if(iPlayer != NO_PLAYER)
	{
		int iSpyIndex = pkCity->GetCityEspionage()->m_aiSpyAssignment[iPlayer];
		bResult = (iSpyIndex != -1 && !GET_PLAYER(iPlayer).GetEspionage()->IsDiplomat(iSpyIndex));
	}
	lua_pushboolean(L, bResult);
	return 1;
}
//------------------------------------------------------------------------------
int CvLuaCity::lHasCounterSpy(lua_State* L)
{
	bool bResult = false;
	CvCity* pkCity = GetInstance(L);
	bResult = (pkCity->GetCityEspionage()->m_aiSpyAssignment[pkCity->getOwner()] != -1);
	lua_pushboolean(L, bResult);
	return 1;
}
//------------------------------------------------------------------------------
int CvLuaCity::lGetCounterSpy(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	lua_pushinteger(L, pkCity->GetCityEspionage()->m_aiSpyAssignment[pkCity->getOwner()]);
	return 1;
}
#endif

#if defined(MOD_API_LUA_EXTENSIONS) && defined(MOD_RELIGION_CONVERSION_MODIFIERS)
//int GetBuildingConversionModifier(BuildingTypes eBuilding)
int CvLuaCity::lGetBuildingConversionModifier(lua_State* L)
{
	//CvCity* pkCity = GetInstance(L);
	const BuildingTypes eBuilding = (BuildingTypes) lua_tointeger(L, 2);
	CvBuildingEntry* pBuildingInfo = GC.getBuildingInfo(eBuilding);
	CvAssertMsg(pBuildingInfo, "pBuildingInfo is null!");
	if (pBuildingInfo)
	{
		lua_pushinteger(L, pBuildingInfo->GetConversionModifier());
	}
	else
	{
		lua_pushinteger(L, 0);
	}
	return 1;
}

// int GetBuildingGlobalConversionModifier(BuildingTypes eBuilding)
int CvLuaCity::lGetBuildingGlobalConversionModifier(lua_State* L)
{
	const BuildingTypes eBuilding = (BuildingTypes)lua_tointeger(L, 2);
	CvBuildingEntry* pBuildingInfo = GC.getBuildingInfo(eBuilding);
	CvAssertMsg(pBuildingInfo, "pBuildingInfo is null!");
	if (pBuildingInfo)
	{
		lua_pushinteger(L, pBuildingInfo->GetGlobalConversionModifier());
	}
	else
	{
		lua_pushinteger(L, 0);
	}
	return 1;
}
#endif

//------------------------------------------------------------------------------
//void setBuildingYieldChange(BuildingClassTypes eBuildingClass, YieldTypes eYield, int iChange);
int CvLuaCity::lSetBuildingYieldChange(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const int eBuildingClass = lua_tointeger(L, 2);
	const int eYield = lua_tointeger(L, 3);
	const int iChange = lua_tointeger(L, 4);

	pkCity->GetCityBuildings()->SetBuildingYieldChange((BuildingClassTypes)eBuildingClass, (YieldTypes)eYield, iChange);

	return 1;
}

//------------------------------------------------------------------------------
int CvLuaCity::lGetNumCityPlots(lua_State* L)
{
#if defined(MOD_API_LUA_EXTENSIONS) && defined(MOD_GLOBAL_CITY_WORKING)
	CvCity* pkCity = GetInstance(L);
	lua_pushinteger(L, pkCity->GetNumWorkablePlots());
#else
	lua_pushinteger(L, NUM_CITY_PLOTS);
#endif
	return 1;
}

//------------------------------------------------------------------------------
int CvLuaCity::lCanPlaceUnitHere(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	int iUnitType = lua_tointeger(L, 2);
	lua_pushboolean(L, pkCity->CanPlaceUnitHere((UnitTypes)iUnitType));

	return 1;
}
//------------------------------------------------------------------------------
int CvLuaCity::lGetSpecialistYield(lua_State* L)
{
	CvCity* pkCity = GetInstance(L);
	const SpecialistTypes eSpecialist = (SpecialistTypes) lua_tointeger(L, 2);
	const YieldTypes eYield = (YieldTypes) lua_tointeger(L, 3);

	const int iValue = pkCity->getSpecialistYield(eYield, eSpecialist);
	lua_pushinteger(L, iValue);

	return 1;
}
//------------------------------------------------------------------------------
int CvLuaCity::lGetCultureFromSpecialist(lua_State* L)
{
	return BasicLuaMethod(L, &CvCity::GetCultureFromSpecialist);
}
//------------------------------------------------------------------------------
int CvLuaCity::lGetReligionCityRangeStrikeModifier(lua_State* L)
{
	int iReligionRangeStrikeMod = 0;

	CvCity* pkCity = GetInstance(L);
	ReligionTypes eMajority = pkCity->GetCityReligions()->GetReligiousMajority();
	if(eMajority != NO_RELIGION)
	{
		const CvReligion* pReligion = GC.getGame().GetGameReligions()->GetReligion(eMajority, pkCity->getOwner());
		if(pReligion)
		{
			iReligionRangeStrikeMod = pReligion->m_Beliefs.GetCityRangeStrikeModifier();
			BeliefTypes eSecondaryPantheon = pkCity->GetCityReligions()->GetSecondaryReligionPantheonBelief();
			if (eSecondaryPantheon != NO_BELIEF)
			{
				iReligionRangeStrikeMod += GC.GetGameBeliefs()->GetEntry(eSecondaryPantheon)->GetCityRangeStrikeModifier();
			}
		}
	}

	lua_pushinteger(L, iReligionRangeStrikeMod);

	return 1;
}




#ifdef MOD_BUILDINGS_YIELD_FROM_OTHER_YIELD
int CvLuaCity::lGetBaseYieldRateFromOtherYield(lua_State* L) {
	return BasicLuaMethod(L, &CvCity::GetBaseYieldRateFromOtherYield);
}
#endif



#if defined(MOD_ROG_CORE)
//int getForcedDamageValue();
int CvLuaCity::lGetForcedDamageValue(lua_State* L)
{
	CvCity* pCity = GetInstance(L);

	const int iResult = pCity->getResetDamageValue();
	lua_pushinteger(L, iResult);
	return 1;
}

int CvLuaCity::lGetChangeDamageValue(lua_State* L)
{
	CvCity* pCity = GetInstance(L);

	const int iResult = pCity->getReduceDamageValue();
	lua_pushinteger(L, iResult);
	return 1;
}
#endif



#if defined(MOD_API_LUA_EXTENSIONS)
//------------------------------------------------------------------------------
int CvLuaCity::lAddMessage(lua_State* L)
{
	CvCity* pCity = GetInstance(L);
	const char* szMessage = lua_tostring(L, 2);
	const PlayerTypes ePlayer = (PlayerTypes) luaL_optinteger(L, 3, pCity->getOwner());

	SHOW_CITY_MESSAGE(pCity, ePlayer, szMessage);
	return 0;
}
#endif

#if defined(MOD_API_LUA_EXTENSIONS)
LUAAPIIMPL(City, HasBelief)
LUAAPIIMPL(City, HasBuilding)
LUAAPIIMPL(City, HasBuildingClass)
LUAAPIIMPL(City, HasAnyWonder)
LUAAPIIMPL(City, HasWonder)
LUAAPIIMPL(City, IsCivilization)
LUAAPIIMPL(City, HasFeature)
LUAAPIIMPL(City, HasWorkedFeature)
LUAAPIIMPL(City, HasAnyNaturalWonder)
LUAAPIIMPL(City, HasNaturalWonder)
LUAAPIIMPL(City, HasImprovement)
LUAAPIIMPL(City, HasWorkedImprovement)
LUAAPIIMPL(City, HasPlotType)
LUAAPIIMPL(City, HasWorkedPlotType)
LUAAPIIMPL(City, HasAnyReligion)
LUAAPIIMPL(City, HasReligion)
LUAAPIIMPL(City, HasResource)
LUAAPIIMPL(City, HasWorkedResource)
LUAAPIIMPL(City, IsConnectedToCapital)
LUAAPIIMPL(City, IsConnectedTo)
LUAAPIIMPL(City, HasSpecialistSlot)
LUAAPIIMPL(City, HasSpecialist)
LUAAPIIMPL(City, HasTerrain)
LUAAPIIMPL(City, HasWorkedTerrain)
LUAAPIIMPL(City, HasAnyDomesticTradeRoute)
LUAAPIIMPL(City, HasAnyInternationalTradeRoute)
LUAAPIIMPL(City, HasTradeRouteToAnyCity)
LUAAPIIMPL(City, HasTradeRouteTo)
LUAAPIIMPL(City, HasTradeRouteFromAnyCity)
LUAAPIIMPL(City, HasTradeRouteFrom)
LUAAPIIMPL(City, IsOnFeature)
LUAAPIIMPL(City, IsAdjacentToFeature)
LUAAPIIMPL(City, IsWithinDistanceOfFeature)
LUAAPIIMPL(City, IsOnImprovement)
LUAAPIIMPL(City, IsAdjacentToImprovement)
LUAAPIIMPL(City, IsWithinDistanceOfImprovement)
LUAAPIIMPL(City, IsOnPlotType)
LUAAPIIMPL(City, IsAdjacentToPlotType)
LUAAPIIMPL(City, IsWithinDistanceOfPlotType)
LUAAPIIMPL(City, IsOnResource)
LUAAPIIMPL(City, IsAdjacentToResource)
LUAAPIIMPL(City, IsWithinDistanceOfResource)
LUAAPIIMPL(City, IsOnTerrain)
LUAAPIIMPL(City, IsAdjacentToTerrain)
LUAAPIIMPL(City, IsWithinDistanceOfTerrain)
LUAAPIIMPL(City, CountFeature)
LUAAPIIMPL(City, CountWorkedFeature)
LUAAPIIMPL(City, CountImprovement)
LUAAPIIMPL(City, CountWorkedImprovement)
LUAAPIIMPL(City, CountPlotType)
LUAAPIIMPL(City, CountWorkedPlotType)
LUAAPIIMPL(City, CountResource)
LUAAPIIMPL(City, CountWorkedResource)
LUAAPIIMPL(City, CountTerrain)
LUAAPIIMPL(City, CountWorkedTerrain)
#endif

#ifdef MOD_API_RELIGION_EXTENSIONS
int CvLuaCity::lGetMajorReligionPantheonBelief(lua_State* L)
{
	CvCity* pCity = GetInstance(L);
	lua_pushinteger(L, pCity->GetCityReligions()->GetMajorReligionPantheonBelief());

	return 1;
}

int CvLuaCity::lIsHasMajorBelief(lua_State* L)
{
	const BeliefTypes eBelief = static_cast<BeliefTypes>(lua_tointeger(L, 2));

	CvCity* pCity = GetInstance(L);
	lua_pushboolean(L, pCity->GetCityReligions()->IsHasMajorBelief(eBelief));
	return 1;
}

int CvLuaCity::lIsHasSecondaryBelief(lua_State* L)
{
	const BeliefTypes eBelief = static_cast<BeliefTypes>(lua_tointeger(L, 2));

	CvCity* pCity = GetInstance(L);
	lua_pushboolean(L, pCity->GetCityReligions()->IsHasSecondaryBelief(eBelief));
	return 1;
}

int CvLuaCity::lIsSecondaryReligionActive(lua_State* L)
{
	CvCity* pCity = GetInstance(L);
	lua_pushboolean(L, pCity->GetCityReligions()->IsSecondaryReligionActive());
	return 1;
}
#endif

#if defined(MOD_INTERNATIONAL_IMMIGRATION_FOR_SP)
LUAAPIIMPL(City, IsCanDoImmigration)
LUAAPIIMPL(City, SetCanDoImmigration)
LUAAPIIMPL(City, CanImmigrantIn)
LUAAPIIMPL(City, CanImmigrantOut)
#endif

#ifdef MOD_GLOBAL_CITY_SCALES
LUAAPIIMPL(City, GetScale)
LUAAPIIMPL(City, CanGrowNormally)
#endif

#ifdef MOD_GLOBAL_CORRUPTION
LUAAPIIMPL(City, GetCorruptionScore);
LUAAPIIMPL(City, GetCorruptionLevel);
LUAAPIIMPL(City, UpdateCorruption);
LUAAPIIMPL(City, CalculateTotalCorruptionScore);
LUAAPIIMPL(City, CalculateCorruptionScoreFromDistance);
LUAAPIIMPL(City, CalculateCorruptionScoreFromCoastalBonus);
LUAAPIIMPL(City, CalculateCorruptionScoreModifierFromSpy);
LUAAPIIMPL(City, CalculateCorruptionScoreModifierFromTrait);
LUAAPIIMPL(City, GetCorruptionScoreChangeFromBuilding);
LUAAPIIMPL(City, GetCorruptionLevelChangeFromBuilding);
LUAAPIIMPL(City, CalculateCorruptionScoreFromResource);
LUAAPIIMPL(City, CalculateCorruptionScoreFromTrait);
LUAAPIIMPL(City, GetCorruptionScoreModifierFromPolicy);
LUAAPIIMPL(City, GetMaxCorruptionLevel);
LUAAPIIMPL(City, IsCorruptionLevelReduceByOne);

int CvLuaCity::lDecideCorruptionLevelForNormalCity(lua_State* L)
{
	CvCity* pCity = GetInstance(L);
	int iScore = lua_tointeger(L, 2);
	auto* pResult = pCity->DecideCorruptionLevelForNormalCity(iScore);
	int iResult = pResult == nullptr ? INVALID_CORRUPTION : pResult->GetID();
	lua_pushinteger(L, iResult);
	return 1;
}

LUAAPIIMPL(City, GetHurryModifier);
LUAAPIIMPL(City, GetHurryModifierLocal);
LUAAPIIMPL(City, GetUnitMaxExperienceLocal);
#endif

LUAAPIIMPL(City, IsSecondCapital);

int CvLuaCity::lGetFoodConsumptionPerPopTimes100(lua_State* L)
{
	CvCity* pCity = GetInstance(L);

	int iResult = GC.getFOOD_CONSUMPTION_PER_POPULATION() * 100;
	
	TerrainTypes eTerrain = pCity->plot()->getTerrainType();
	if(eTerrain == NO_TERRAIN)
	{
		lua_pushinteger(L, iResult);
		return 1;
	}
	
	int iConsumptionModifier = 100;
	ReligionTypes eMajority = pCity->GetCityReligions()->GetReligiousMajority();
	if(eMajority != NO_RELIGION)
	{
		iConsumptionModifier += GC.getGame().GetGameReligions()->GetReligion(eMajority, pCity->getOwner())->m_Beliefs.GetTerrainCityFoodConsumption(eTerrain);
	}	
	BeliefTypes eSecondaryPantheon = pCity->GetCityReligions()->GetSecondaryReligionPantheonBelief();
	if(eSecondaryPantheon != NO_BELIEF)
	{
		iConsumptionModifier += GC.GetGameBeliefs()->GetEntry(eSecondaryPantheon)->GetTerrainCityFoodConsumption(eTerrain);
	}
	iResult = iResult * iConsumptionModifier;
	iResult /= 100;
	lua_pushinteger(L, iResult);
	return 1;
}

LUAAPIIMPL(City, GetDefendedAgainstSpreadUntilTurn);