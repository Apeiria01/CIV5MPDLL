ALTER TABLE UnitPromotions ADD COLUMN SplashDamagePercent integer not null default 0;
ALTER TABLE UnitPromotions ADD COLUMN SplashDamageFixed integer not null default 0;
ALTER TABLE UnitPromotions ADD COLUMN SplashDamageRadius integer not null default 0;
ALTER TABLE UnitPromotions ADD COLUMN SplashDamagePlotUnitLimit integer not null default 0;
ALTER TABLE UnitPromotions ADD COLUMN SplashDamageImmune boolean not null default 0;
ALTER TABLE UnitPromotions ADD COLUMN SplashXP int not null default 0;
ALTER TABLE UnitPromotions ADD COLUMN TriggerSplashFinish boolean not null default 0;

ALTER TABLE UnitPromotions ADD COLUMN CollateralDamagePercent integer not null default 0;
ALTER TABLE UnitPromotions ADD COLUMN CollateralDamageFixed integer not null default 0;
ALTER TABLE UnitPromotions ADD COLUMN CollateralDamagePlotUnitLimit integer not null default 0;
ALTER TABLE UnitPromotions ADD COLUMN CollateralDamageImmune boolean not null default 0;
ALTER TABLE UnitPromotions ADD COLUMN CollateralXP int not null default 0;
ALTER TABLE UnitPromotions ADD COLUMN CollateralOnlyCity boolean not null default 0;
ALTER TABLE UnitPromotions ADD COLUMN CollateralOnlyUnit boolean not null default 1;

create table PromotionCollections_AddEnemyPromotions (
    CollectionType text references PromotionCollections(Type),
    OtherCollectionType text references PromotionCollections(Type)
);

alter table UnitPromotions add column AddEnemyPromotionImmune boolean not null default 0;

alter table UnitPromotions add column 'DestroyBuildingCollection' text default '';
alter table UnitPromotions add column 'DestroyBuildingProbability' int default 0 not null;
alter table UnitPromotions add column 'DestroyBuildingNumLimit' int default 0 not null;

alter table UnitPromotions add column 'SiegeKillCitizensPercent' integer default 0 not null;
alter table UnitPromotions add column 'SiegeKillCitizensFixed' integer default 0 not null;
alter table Buildings add column 'SiegeKillCitizensModifier' integer default 0 not null;

alter table PromotionCollections add column 'StackingFightBack' boolean not null default 0;
alter table PromotionCollections add column 'StopAttacker' boolean not null default 0;
alter table UnitPromotions add column 'RangeBackWhenDefense' boolean not null default 0;

alter table UnitPromotions add column 'HeavyChargeAddMoves' integer not null default 0;
alter table UnitPromotions add column 'HeavyChargeExtraDamage' integer not null default 0;
alter table UnitPromotions add column 'HeavyChargeCollateralFixed' integer not null default 0;
alter table UnitPromotions add column 'HeavyChargeCollateralPercent' integer not null default 0;
ALTER TABLE UnitPromotions ADD COLUMN ReligionOwnership boolean not null default 0;