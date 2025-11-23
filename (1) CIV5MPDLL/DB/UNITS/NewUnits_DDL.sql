alter table Units add ScaleFromNumGWs integer default 0;
alter table Units add GivePoliciesWithSpreaded boolean default 0;
alter table Units add GoldenAgeWithSpreaded boolean default 0;
alter table Units add GoldFromTourismModifier integer default 0;

alter table Units add CombatStrengthChangeAfterKilling integer default 0;
alter table Units add RangedCombatStrengthChangeAfterKilling integer default 0;

alter table Units add ExtraXPValueAttack integer default 0;
alter table Units add ExtraXPValueDefense integer default 0;

alter table Units add BoundLandImprovement text references Improvements(Type);
alter table Units add BoundWaterImprovement text references Improvements(Type);

alter table Units add PolicyBranchType text references PolicyBranchTypes(Type);
alter table Units add TrainPopulationConsume integer default 0;
alter table Units add PuppetPurchaseOverride boolean default 0;
alter table Units add ProductionCostAddedPerEra integer default 0;
--default Great People class is always true, for new Great People, enter a positive value to make it valid(for example: 1), for other Unit, Increase fixed value.
alter table Units add FaithCostIncrease integer default 0;

alter table Units add NoSpreadTurnPopModifierAfterRemovingHeresy integer default 0;
alter table Units add NoAggressive boolean default 0;
alter table Units add ForbidRebase boolean default 0;
alter table Units add UnitTechUpgrade boolean default 0;

alter table Units add NoFallout boolean default 0;
alter table Units add ExtraNukeBlastRadius integer default 0;

alter table Units add BarbarianCanTrait boolean default 0;
alter table Units add BarbarianTraitTechObsolete boolean default 0;

create table Unit_ScalingFromOwnedImprovements (
	UnitType text references Units(Type),
	ImprovementType text references Improvements(Type),
	Amount integer default 0
);
create table Unit_InstantYieldFromTrainings (
    UnitType text references Units(Type),
    YieldType integer references Yields(Type),
    Yield integer default 0
);