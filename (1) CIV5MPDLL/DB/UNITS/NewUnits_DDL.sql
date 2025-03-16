ALTER TABLE Units ADD 'ScaleFromNumGWs' INTEGER DEFAULT 0;

create table UnitPromotions_Promotions (
    FreePromotionType text references UnitPromotions(Type),
    PrePromotionType text references UnitPromotions(Type)
);

ALTER TABLE Units ADD 'CombatStrengthChangeAfterKilling' INTEGER DEFAULT 0;
ALTER TABLE Units ADD 'RangedCombatStrengthChangeAfterKilling' INTEGER DEFAULT 0;

ALTER TABLE Units ADD 'ExtraXPValueAttack' INTEGER DEFAULT 0;
ALTER TABLE Units ADD 'ExtraXPValueDefense' INTEGER DEFAULT 0;

ALTER TABLE Units ADD 'BoundLandImprovement' TEXT DEFAULT NULL ;
ALTER TABLE Units ADD 'BoundWaterImprovement' TEXT DEFAULT NULL;

ALTER TABLE Units ADD 'TrainPopulationConsume' INTEGER DEFAULT 0;

create table Unit_InstantYieldFromTrainings (
    UnitType text references Units(Type),
    YieldType integer references Yields(Type),
    Yield integer default 0
);

ALTER TABLE Units ADD COLUMN 'GivePoliciesWithSpreaded' BOOLEAN DEFAULT 0;
ALTER TABLE Units ADD COLUMN 'GoldenAgeWithSpreaded' BOOLEAN DEFAULT 0;
ALTER TABLE Units ADD COLUMN 'GoldFromTourismModifier' INTEGER DEFAULT 0;
ALTER TABLE Units ADD COLUMN 'NoSpreadTurnPopModifierAfterRemovingHeresy' INTEGER DEFAULT 0;
ALTER TABLE Units ADD COLUMN 'PolicyBranchType' TEXT DEFAULT NULL REFERENCES PolicyBranchTypes(Type);
ALTER TABLE Units ADD COLUMN 'NoAggressive' BOOLEAN DEFAULT 0;
--default Great People class is always true, for new Great People, enter a positive value to make it valid(for example: 1), for other Unit, Increase fixed value.
ALTER TABLE Units ADD COLUMN 'FaithCostIncrease' INTEGER DEFAULT 0;