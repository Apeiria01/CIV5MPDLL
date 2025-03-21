alter table Policies add column `MinorBullyInfluenceLossModifier` int not null default 0;

create table Policy_MinorsTradeRouteYieldRate (
    PolicyType text default '',
    YieldType text default '',
    Rate integer not null
);

create table Policy_InternalTradeRouteDestYieldRate (
    PolicyType text default '',
    YieldType text default '',
    Rate integer not null
);

alter table Policies add column IdeologyPressureModifier integer not null default 0;
alter table Policies add column IdeologyUnhappinessModifier integer not null default 0;

CREATE TABLE Policy_CityWithWorldWonderYieldModifier (
	'PolicyType' text default '',
	'YieldType' text default '',
	'Yield' integer  not null ,
	foreign key (PolicyType) references Policies(Type),
	foreign key (YieldType) references Yields(Type)
);

CREATE TABLE Policy_TradeRouteCityYieldModifier (
	'PolicyType' text default '',
	'YieldType' text default '',
	'Yield' integer not null ,
	foreign key (PolicyType) references Policies(Type),
	foreign key (YieldType) references Yields(Type)
);

alter table Policies add column GlobalHappinessFromFaithPercent integer not null default 0;

alter table Policies add column HappinessInWLTKDCities integer not null default 0;

CREATE TABLE Policy_CityNumberCityYieldModifier (
	'PolicyType' text default '',
	'YieldType' text default '',
	'Yield' integer not null ,
	foreign key (PolicyType) references Policies(Type),
	foreign key (YieldType) references Yields(Type)
);

create table Policy_HappinessYieldModifier (
    PolicyType text references Policies(Type),
    YieldType text references Yields(Type),
    YieldFormula text references LuaFormula(Type)
);

alter table Policies add column InstantFoodThresholdPercent integer not null default 0;
alter table Policies add column CaptureCityResistanceTurnsChangeFormula text references LuaFormula(Type);

ALTER TABLE Policies ADD 'WaterBuildSpeedModifier' INTEGER DEFAULT 0;
ALTER TABLE Policies ADD 'SettlerProductionEraModifier' INTEGER DEFAULT 0;
ALTER TABLE Policies ADD 'SettlerProductionStartEra' TEXT DEFAULT NULL REFERENCES Eras(Type);
ALTER TABLE Policies ADD 'NumTradeRouteBonus' INTEGER DEFAULT 0;
ALTER TABLE Policies ADD 'HappinessPerReligionInCity' INTEGER DEFAULT 0;
ALTER TABLE Policies ADD 'HappinessPerPolicy' INTEGER DEFAULT 0;
ALTER TABLE Policies ADD 'DifferentIdeologyTourismModifier' INTEGER DEFAULT 0;
ALTER TABLE Policies ADD 'ReligionProductionModifier' INTEGER DEFAULT 0;

ALTER TABLE Policies ADD 'NullifyInfluenceModifier' BOOLEAN DEFAULT 0;
ALTER TABLE Policies ADD 'SettlerPopConsume' BOOLEAN DEFAULT 0;
ALTER TABLE Policies ADD 'TourismModifierPerGPCreation' BOOLEAN DEFAULT 0;
ALTER TABLE Policies ADD 'ScienceModifierFromRANum' INTEGER DEFAULT 0;
ALTER TABLE Policies ADD 'DiplomatPropagandaModifier' INTEGER DEFAULT 0;
ALTER TABLE Policies ADD 'CityExtraProductionCount' INTEGER DEFAULT 0;
ALTER TABLE Policies ADD 'NationalWonderCityCostModifier' INTEGER DEFAULT 0;

ALTER TABLE Policies ADD 'DeepWaterNavalStrengthCultureModifier' INTEGER DEFAULT 0;
ALTER TABLE Policies ADD 'FreeBuildingClass' text default null references BuildingClasses(Type);

ALTER TABLE Policies ADD 'MinorLocalBullyScoreModifier' INTEGER DEFAULT 0;
ALTER TABLE Policies ADD 'MinorAllyBullyScoreModifier' INTEGER DEFAULT 0;

alter table Policies add column FreePromotionRemoved integer default -1;
alter table Policies add column RemoveCurrentPromotion boolean default 0;
alter table Policies add column RemoveOceanImpassableCombatUnit boolean default 0;

CREATE TABLE Policy_YieldModifierPerArtifacts (
	'PolicyType' text default '',
	'YieldType' text default '',
	'Yield' integer  not null ,
	foreign key (PolicyType) references Policies(Type),
	foreign key (YieldType) references Yields(Type)
);

CREATE TABLE Policy_GreatPersonOutputModifierPerGWs (
	'PolicyType' text default '',
	'GreatPersonType' text default '',
	'Modifier' integer  not null ,
	foreign key (PolicyType) references Policies(Type),
	foreign key (GreatPersonType) references GreatPersons(Type)
);

alter table Policies add column CapitalTradeRouteGoldChange integer default 0;
alter table Policies add column CapitalTradeRouteRangeChange integer default 0;
alter table Policies add column RiggingElectionInfluenceModifier integer default 0;
alter table Policies add column SpyLevelUpWhenRigging boolean default 0;
ALTER TABLE Policies ADD COLUMN GlobalUnlimitedOneTurnTGCP BOOLEAN DEFAULT 0;