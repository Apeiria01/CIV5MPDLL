CREATE TABLE Belief_YieldPerBirth (
    BeliefType TEXT REFERENCES Beliefs(Type),
    YieldType TEXT REFERENCES Yields(Type),
    Yield INTEGER DEFAULT 0
);

ALTER TABLE Beliefs ADD COLUMN 'AllowYieldPerBirth' BOOLEAN DEFAULT 0;
ALTER TABLE Beliefs ADD COLUMN 'CityExtraMissionarySpreads' INTEGER DEFAULT 0;
ALTER TABLE Beliefs ADD COLUMN 'HolyCityPressureModifier' INTEGER DEFAULT 0;
ALTER TABLE Beliefs ADD COLUMN 'HolyCityUnitExperence' INTEGER DEFAULT 0;
ALTER TABLE Beliefs ADD COLUMN 'LandmarksTourismPercent' INTEGER DEFAULT 0;
ALTER TABLE Beliefs ADD COLUMN 'FreePromotionForProphet' TEXT DEFAULT NULL;

CREATE TABLE Belief_GreatPersonPoints (
    BeliefType TEXT REFERENCES Beliefs(Type),
    GreatPersonType TEXT REFERENCES GreatPersons(Type),
    Value INTEGER DEFAULT 0
);
ALTER TABLE Beliefs ADD COLUMN 'GreatPersonPointsPerCity' BOOLEAN DEFAULT 0;
ALTER TABLE Beliefs ADD COLUMN 'GreatPersonPointsCapital' BOOLEAN DEFAULT 0;
ALTER TABLE Beliefs ADD COLUMN 'GreatPersonPointsHolyCity' BOOLEAN DEFAULT 0;
ALTER TABLE Beliefs ADD COLUMN 'InquisitorProhibitSpreadInAlly' BOOLEAN DEFAULT 0;

ALTER TABLE Beliefs ADD COLUMN 'SameReligionMinorRecoveryModifier' INTEGER DEFAULT 0;
ALTER TABLE Beliefs ADD COLUMN 'InquisitionFervorTimeModifier' INTEGER DEFAULT 0;
ALTER TABLE Beliefs ADD COLUMN 'GoldenAgeModifier' INTEGER DEFAULT 0;
ALTER TABLE Beliefs ADD COLUMN 'ExtraSpies' INTEGER DEFAULT 0;

CREATE TABLE Belief_TerrainYieldChangesAdditive (
    BeliefType TEXT REFERENCES Beliefs(Type),
    TerrainType TEXT REFERENCES Terrains(Type),
    YieldType TEXT REFERENCES Yields(Type),
    Yield INTEGER DEFAULT 0
);

CREATE TABLE Belief_TerrainCityYieldChanges (
    BeliefType TEXT REFERENCES Beliefs(Type),
    TerrainType TEXT REFERENCES Terrains(Type),
    YieldType TEXT REFERENCES Yields(Type),
    Yield INTEGER DEFAULT 0
);

CREATE TABLE Belief_TerrainCityFoodConsumption (
    BeliefType TEXT REFERENCES Beliefs(Type),
    TerrainType TEXT REFERENCES Terrains(Type),
    Modifier INTEGER DEFAULT 0
);

CREATE TABLE Belief_LakePlotYieldChanges (
    BeliefType TEXT REFERENCES Beliefs(Type),
    YieldType TEXT REFERENCES Yields(Type),
    Yield INTEGER DEFAULT 0
);

CREATE TABLE Belief_RiverPlotYieldChanges (
    BeliefType TEXT REFERENCES Beliefs(Type),
    YieldType TEXT REFERENCES Yields(Type),
    Yield INTEGER DEFAULT 0
);

ALTER TABLE Beliefs ADD COLUMN 'CuttingBonusModifier' INTEGER DEFAULT 0;
ALTER TABLE Beliefs ADD COLUMN 'FounderFreePromotion' TEXT DEFAULT NULL REFERENCES UnitPromotions(Type);
ALTER TABLE Beliefs ADD COLUMN 'FollowingCityFreePromotion' TEXT DEFAULT NULL REFERENCES UnitPromotions(Type);

--Per 25 will add about 1 AI-judge score if leader's this flavor is 6
--common  AI-popular beliefs` score about 100-200,common no-AI-choose beliefs` score about 20-40
CREATE TABLE Belief_ExtraFlavors (
    BeliefType TEXT REFERENCES Beliefs(Type),
    FlavorType TEXT REFERENCES Flavors(Type),
    Flavor INTEGER DEFAULT 0 NOT NULL
);
CREATE TABLE Belief_CivilizationFlavors (
    BeliefType TEXT REFERENCES Beliefs(Type),
    CivilizationType TEXT REFERENCES Civilizations(Type),
    Flavor INTEGER DEFAULT 0 NOT NULL
);
--Yield = Modifier * cutting-production
CREATE TABLE Belief_CuttingInstantYieldModifier (
    BeliefType TEXT REFERENCES Beliefs(Type),
    YieldType TEXT REFERENCES Yields(Type),
    Modifier INTEGER DEFAULT 0
);
CREATE TABLE Belief_CuttingInstantYield (
    BeliefType TEXT REFERENCES Beliefs(Type),
    YieldType TEXT REFERENCES Yields(Type),
    Yield INTEGER DEFAULT 0
);
--Need define Belief_MaxYieldModifierPerFollower before use this, Actual value = 100 + Modifier
CREATE TABLE Belief_YieldModifierPerFollowerTimes100 (
    BeliefType TEXT REFERENCES Beliefs(Type),
    YieldType TEXT REFERENCES Yields(Type),
    Modifier INTEGER DEFAULT 0
);