create table CityScales (
    ID integer primary key autoincrement not null,
    Type text not null unique,
    MinPopulation integer not null
);

create table CityScale_FreeBuildingClass (
    CityScaleType text not null references CityScales(Type),
    BuildingClassType text not null references BuildingClasses(Type),
    NumBuildings integer not null default 1
);
