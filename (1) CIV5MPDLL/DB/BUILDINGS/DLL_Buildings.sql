alter table Buildings add column `MinorFriendshipAnchorChange` int not null default 0;
alter table Buildings add column `MinorQuestFriendshipMod` int not null default 0;
alter table Buildings add column `GoldenAgeUnitCombatModifier` int not null default 0;
alter table Buildings add column `GoldenAgeMeterMod` int not null default 0;

create table Building_YieldFromOtherYield(
	BuildingType text references Buildings(Type),
	InYieldType text references Yields(Type),
	InYieldValue integer not null,
	OutYieldType text references Yields(Type),
	OutYieldValue integer not null
);

ALTER TABLE Buildings ADD COLUMN 'AllowInstantYield' BOOLEAN DEFAULT 0;
ALTER TABLE Buildings ADD COLUMN 'AnyWater' BOOLEAN DEFAULT 0;
ALTER TABLE Buildings ADD COLUMN 'RiverOrCoastal' BOOLEAN DEFAULT 0;
alter table Buildings add column `MinNumReligions` int not null default 0;

CREATE TABLE Building_ClassesNeededGlobal(
	'BuildingType' text , 
	'BuildingClassType' text , 
	foreign key (BuildingType) references Buildings(Type), 
	foreign key (BuildingClassType) references BuildingClasses(Type)
);

ALTER TABLE Buildings ADD 'TradeRouteSeaGoldBonusGlobal' INTEGER DEFAULT 0;
ALTER TABLE Buildings ADD 'TradeRouteLandGoldBonusGlobal' INTEGER DEFAULT 0;
ALTER TABLE Buildings ADD 'LandmarksTourismPercentGlobal' INTEGER DEFAULT 0;
ALTER TABLE Buildings ADD 'GreatWorksTourismModifierGlobal' INTEGER DEFAULT 0;
ALTER TABLE Buildings ADD 'CityStateTradeRouteProductionModifierGlobal' INTEGER DEFAULT 0;

ALTER TABLE Buildings ADD 'GlobalProductionNeededUnitModifier' INTEGER DEFAULT 0;
ALTER TABLE Buildings ADD 'GlobalProductionNeededBuildingModifier' INTEGER DEFAULT 0;
ALTER TABLE Buildings ADD 'GlobalProductionNeededProjectModifier' INTEGER DEFAULT 0;

ALTER TABLE Buildings ADD 'GlobalProductionNeededUnitMax' INTEGER DEFAULT 0;
ALTER TABLE Buildings ADD 'GlobalProductionNeededBuildingMax' INTEGER DEFAULT 0;
ALTER TABLE Buildings ADD 'GlobalProductionNeededProjectMax' INTEGER DEFAULT 0;

ALTER TABLE Buildings ADD 'DummyBuilding' BOOLEAN DEFAULT 0;
ALTER TABLE Buildings ADD COLUMN 'GlobalEspionageSpeedModifier' INTEGER DEFAULT 0;
ALTER TABLE Buildings ADD 'InstantResearchFromFriendlyGreatScientist' INTEGER DEFAULT 0;

ALTER TABLE Buildings ADD 'NoPuppet' BOOLEAN DEFAULT 0;

ALTER TABLE Buildings ADD 'UnitMaxExperienceLocal' INTEGER DEFAULT 0;
ALTER TABLE Buildings ADD 'ExtraSellRefund' INTEGER DEFAULT 0;
ALTER TABLE Buildings ADD 'ExtraSellRefundModifierPerEra' INTEGER DEFAULT 0;
ALTER TABLE Buildings ADD 'CityDefenseModifierGlobal' INTEGER DEFAULT 0;

CREATE TABLE Building_TradeRouteFromTheCityYields (
	'BuildingType' text no null references Buildings(Type),
	'YieldType' text references Yields(Type),
	'YieldValue' int default 0 not null
);

ALTER TABLE Buildings ADD 'GlobalGrowthFoodNeededModifier' INTEGER DEFAULT 0;
ALTER TABLE Buildings ADD 'SecondCapitalsExtraScore' INTEGER DEFAULT 0;
ALTER TABLE Buildings ADD 'FoodKeptFromPollution' INTEGER DEFAULT 0;
ALTER TABLE Buildings ADD 'NotNeedOccupied' BOOLEAN DEFAULT 0;
ALTER TABLE Buildings ADD 'TechNoPrereqClasses' TEXT DEFAULT NULL REFERENCES Technologies(Type);

ALTER TABLE Buildings ADD 'CapitalOnly' BOOLEAN DEFAULT 0;
ALTER TABLE Buildings ADD 'OriginalCapitalOnly' BOOLEAN DEFAULT 0;
CREATE TABLE "Building_TradeRouteFromTheCityYieldsPerEra" (
	"BuildingType"	text references Buildings(Type),
	"YieldType"	text references Yields(Type),
	"YieldValue"	integer
);
CREATE TABLE "Building_YieldChangesPerEra" (
	"BuildingType"	text references Buildings(Type),
	"YieldType"	text references Yields(Type),
	"Yield"	integer
);
CREATE TABLE Building_RiverPlotYieldChangesGlobal (
	'BuildingType' text no null references Buildings(Type),
	'YieldType' text references Yields(Type),
	'Yield' int default 0 not null
);

CREATE TABLE "Building_LocalPlotAnds" (
	'BuildingType' text no null references Buildings(Type),
	'PlotType' text references Plots(Type)
);

CREATE TABLE "Building_DomainFreeExperiencesPerPop" (
	'BuildingType'	no null references Buildings(Type),
	'DomainType'	no null references Domains(Type),
	'Modifier'	integer
);

CREATE TABLE "Building_DomainFreeExperiencesPerPopGlobal" (
	'BuildingType'	no null references Buildings(Type),
	'DomainType'	no null references Domains(Type),
	'Modifier'	integer
);

CREATE TABLE "Building_DomainFreeExperiencesPerTurn" (
	'BuildingType'	no null references Buildings(Type),
	'DomainType'	no null references Domains(Type),
	'Value'	integer
);

CREATE TABLE "Building_DomainFreeExperiencesPerTurnGlobal" (
	'BuildingType'	no null references Buildings(Type),
	'DomainType'	no null references Domains(Type),
	'Value'	integer
);
CREATE TABLE "Building_YieldModifiersChangesPerEra" (
	"BuildingType"	text references Buildings(Type),
	"YieldType"	text references Yields(Type),
	"Yield"	integer
);