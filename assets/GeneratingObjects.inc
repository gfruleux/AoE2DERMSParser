/* Generating Objects - this file is used by all standard, real world, and special maps to generate all objects */

/* Updated 01.01 2020 */

if INFINITE_RESOURCES
#define DEATH_MATCH
endif

/* TC generation */

if GNR_ALWAYSNOMAD
	if EMPIRE_WARS
		if GNR_EMP_W_ISLENOMAD
		else

create_object TOWN_CENTER
{
  set_place_for_every_player
  group_placement_radius     18
  min_distance_to_players    0
  max_distance_to_players    0
  actor_area 100
  actor_area_radius 2
}

		endif
	elseif BATTLE_ROYALE

#const PACKEDBUS 444

create_object PACKEDBUS
{
  set_place_for_every_player
  group_placement_radius     18
  min_distance_to_players    0
  max_distance_to_players    0
}
	else
	endif

elseif GNR_NORMALTC

	if BATTLE_ROYALE

#const PACKEDBUS 444

create_object PACKEDBUS
{
  set_place_for_every_player
  group_placement_radius     18
  min_distance_to_players    0
  max_distance_to_players    0
}

	elseif EMPIRE_WARS

create_object TOWN_CENTER
{
  set_place_for_every_player
  group_placement_radius     18
  min_distance_to_players    0
  max_distance_to_players    0
  actor_area 100
  actor_area_radius 2
}

	else

create_object TOWN_CENTER
{
  set_place_for_every_player
  group_placement_radius     18
  min_distance_to_players    0
  max_distance_to_players    0
}

	endif

endif

/* KOTH */

#const MONUMENT_RESOURCES 1639

if KING_OT_HILL
create_object MONUMENT_RESOURCES
{
	number_of_objects			1
	set_place_for_every_player
	min_distance_to_players			0
	max_distance_to_players			0
}
endif

/* KOTH - end */

/* starting villagers */

if GNR_STARTVILLS

	if EMPIRE_WARS
	else

create_object VILLAGER
{
  set_place_for_every_player
  min_distance_to_players       6
  max_distance_to_players       6
 }
	endif

elseif GNR_STARTVILLS_DOUBLE

	if EMPIRE_WARS
	else

create_object VILLAGER
{
     set_place_for_every_player
     min_distance_to_players 2
     max_distance_to_players 9
}

create_object VILLAGER
{
     number_of_objects	     3
     set_place_for_every_player
     min_distance_to_players 2
     max_distance_to_players 9
}

	endif
endif



/* Walls */

if GNR_ARENAWALL

	if LUDIKRIS_MAP
		if GNR_PALISADING
create_object PALISADE_WALL
		else
create_object STONE_WALL
		endif
{
  set_place_for_every_player
  min_distance_to_players       35
  max_distance_to_players       35
}
	else
		if GNR_PALISADING
create_object PALISADE_WALL
		else
create_object STONE_WALL
		endif
{
  set_place_for_every_player
  min_distance_to_players       20
  max_distance_to_players       20
}
	endif

elseif GNR_SMALLWALL

start_random
percent_chance 50
create_object STONE_WALL
percent_chance 50
create_object PALISADE_WALL
end_random
{
  set_place_for_every_player
  min_distance_to_players 14
  max_distance_to_players 14
 }

elseif GNR_HIDEOUTWALL

create_object PALISADE_WALL
{
  set_place_for_every_player
  min_distance_to_players 17
  max_distance_to_players 17
 }


else
endif




/* scout cavalry */

/* horse variation */

if GNR_ALWAYSNOMAD
	if GNR_GIVENOMADSCOUT

		if GNR_HORSESCOUT

	start_random
	percent_chance 20
create_object HORSE
	percent_chance 20
create_object HORSE_B
	percent_chance 20
create_object HORSE_C
	percent_chance 20
create_object HORSE_D
	percent_chance 20
create_object HORSE_E
	end_random
{
  number_of_objects             1
  set_place_for_every_player
			if EMPIRE_WARS
  min_distance_to_players       12
  max_distance_to_players       16
   avoid_forest_zone 1
			else
  min_distance_to_players       7
  max_distance_to_players       9
   avoid_forest_zone 1
			endif
 }

		endif

		if GNR_CLASSICSCOUT
			if BATTLE_ROYALE
			else

create_object SCOUT
{
  number_of_objects             1
  set_place_for_every_player
				if EMPIRE_WARS
  min_distance_to_players       12
  max_distance_to_players       16
   avoid_forest_zone 1
				else
  min_distance_to_players       7
  max_distance_to_players       9
   avoid_forest_zone 1
				endif
 }

			endif
		endif

	endif
else
	if GNR_CLASSICSCOUT
		if BATTLE_ROYALE
		else

create_object SCOUT
{
  number_of_objects             1
  set_place_for_every_player
			if EMPIRE_WARS
  min_distance_to_players       12
  max_distance_to_players       16
   avoid_forest_zone 1
			else
  min_distance_to_players       7
  max_distance_to_players       9
   avoid_forest_zone 1
			endif
 }

		endif

	elseif GNR_HORSESCOUT

	start_random
	percent_chance 20
create_object HORSE
	percent_chance 20
create_object HORSE_B
	percent_chance 20
create_object HORSE_C
	percent_chance 20
create_object HORSE_D
	percent_chance 20
create_object HORSE_E
	end_random
{
  number_of_objects             1
  set_place_for_every_player
			if EMPIRE_WARS
  min_distance_to_players       12
  max_distance_to_players       16
   avoid_forest_zone 1
			else
  min_distance_to_players       7
  max_distance_to_players       9
   avoid_forest_zone 1
			endif
 }

	endif
endif

if BATTLE_ROYALE
	if GNR_GIVETRANSPORT

create_object TRANSPORT_SHIP
{
  set_place_for_every_player
  number_of_objects    3
		if GNR_TRANSPORTSUPERFAR
  min_distance_to_players    15
  max_distance_to_players    90
		else
  min_distance_to_players    15
  max_distance_to_players    60
		endif
}


	endif
endif


/* Relics per map - could be further down the line */

if INFINITE_RESOURCES
elseif GNR_GIVERELICS

create_object RELIC
{
	if GNR_RELICSET5

		if LUDIKRIS_MAP
   number_of_objects            250
   temp_min_distance_group_placement 160
		else
   number_of_objects            5
   temp_min_distance_group_placement 20
		endif
		if GNR_RELICDONTAVOID
		else
   min_distance_to_players     25
		endif

	elseif GNR_RELICMODERN_DENSER

   number_of_objects            999

		if GNR_RELICDONTAVOID
		else
   min_distance_to_players     35
		endif

   temp_min_distance_group_placement 18

	elseif GNR_RELICMODERN_DENSE

   number_of_objects            999

		if GNR_RELICDONTAVOID
		else
   min_distance_to_players     35
		endif

   temp_min_distance_group_placement 42

	elseif GNR_RELICMODERN_MEDIUM

		if TINY_MAP
   number_of_objects            5
   temp_min_distance_group_placement 35
		elseif SMALL_MAP
   number_of_objects            5
   temp_min_distance_group_placement 38
		elseif MEDIUM_MAP
   number_of_objects            5
   temp_min_distance_group_placement 38
		elseif LARGE_MAP
   number_of_objects            7
   temp_min_distance_group_placement 48
		elseif HUGE_MAP
   number_of_objects            8
   temp_min_distance_group_placement 52
		else
   number_of_objects            999
   temp_min_distance_group_placement 52 /* originally 64; only applied to largest map sizes for now to maintain 5 consistent relics on 1v1 */
		endif

		if GNR_RELICDONTAVOID
		else
   min_distance_to_players     35
		endif

	elseif GNR_RELICMODERN_LOW

   number_of_objects            999

		if GNR_RELICDONTAVOID
		else
   min_distance_to_players     35
		endif

   temp_min_distance_group_placement 90

	elseif GNR_RELICMODERN_VERYLOW

   number_of_objects            999

		if GNR_RELICDONTAVOID
		else
   min_distance_to_players     35
		endif

   temp_min_distance_group_placement 180

	elseif GNR_RELICMODERN_FILLED

   number_of_objects            999

		if GNR_RELICDONTAVOID
		else
   min_distance_to_players     35
		endif

   temp_min_distance_group_placement 1

	elseif GNR_RELICMODERN_SEMIFILLED

   number_of_objects            999

		if GNR_RELICDONTAVOID
		else
   min_distance_to_players     35
		endif

   temp_min_distance_group_placement 4

	elseif GNR_RELICMODERN_PERPL

   number_of_objects            1
   min_distance_to_players     15
   max_distance_to_players     21
   set_place_for_every_player
   set_gaia_object_only

	elseif GNR_RELICMODERN_PER2PL

   number_of_objects            2
   min_distance_to_players     18
   max_distance_to_players     26
   set_place_for_every_player
   set_gaia_object_only
   temp_min_distance_group_placement 8

	else
	endif

   avoid_forest_zone 2
   avoid_cliff_zone 3

	if GNR_RELPLACE_LAYERA
   terrain_to_place_on LAYER_A
	elseif GNR_RELPLACE_LAYERC
   terrain_to_place_on LAYER_C
	elseif GNR_RELPLACE_LAYERD
   terrain_to_place_on LAYER_D
	else
	endif
}

endif


if INFINITE_RESOURCES
elseif GNR_RELIC_EXTRAONE

create_object RELIC
{

   number_of_objects            1
   temp_min_distance_group_placement 4

	if GNR_RELIC_EXTRA_LAYERA
   terrain_to_place_on LAYER_A
	elseif GNR_RELIC_EXTRA_LAYERC
   terrain_to_place_on LAYER_C
	elseif GNR_RELIC_EXTRA_LAYERD
   terrain_to_place_on LAYER_D
	else
	endif
	if GNR_EXTRARELICAVOID30
   min_distance_to_players     30
	elseif GNR_EXTRARELICAVOID40
   min_distance_to_players     40
	endif
}

elseif GNR_RELIC_EXTRATWO

create_object RELIC
{

   number_of_objects            2
   temp_min_distance_group_placement 4

	if GNR_RELIC_EXTRA_LAYERA
   terrain_to_place_on LAYER_A
	elseif GNR_RELIC_EXTRA_LAYERC
   terrain_to_place_on LAYER_C
	elseif GNR_RELIC_EXTRA_LAYERD
   terrain_to_place_on LAYER_D
	else
	endif
	if GNR_EXTRARELICAVOID30
   min_distance_to_players     30
	elseif GNR_EXTRARELICAVOID40
   min_distance_to_players     40
	endif
}

endif


/* Kericek */

if GNR_6KER

	if BATTLE_ROYALE
	elseif DEATH_MATCH

#define GNR_MISSINGTHEKER

	else

create_object KERICEK
{
		if GNR_KERIK7NUMBER
  number_of_objects          7
		else
  number_of_objects          6
		endif
  group_placement_radius     3
  set_tight_grouping
  set_gaia_object_only
  set_place_for_every_player
		if GNR_RESSUPERCLOSE
  min_distance_to_players    7
  max_distance_to_players    11
		else
  min_distance_to_players    9
  max_distance_to_players    13
		endif
		if EMPIRE_WARS
  actor_area 14
  actor_area_radius 2
		elseif BATTLE_ROYALE
		else
  actor_area 14
  actor_area_radius 4	/* originally 6 */
  min_distance_group_placement 2
		endif
  avoid_forest_zone 4
  avoid_cliff_zone 2
}
	endif

elseif GNR_DOUBLE6KER

	if BATTLE_ROYALE
	elseif DEATH_MATCH

#define GNR_MISSINGTHEKER

	else

create_object KERICEK
{
		if GNR_KERIK7NUMBER
  number_of_objects          7
		else
  number_of_objects          6
		endif
  group_placement_radius     3
  set_tight_grouping
  set_gaia_object_only
  set_place_for_every_player
		if GNR_RESSUPERCLOSE
  min_distance_to_players    7
  max_distance_to_players    11
		else
  min_distance_to_players    9
  max_distance_to_players    13
		endif
		if EMPIRE_WARS
  actor_area 14
  actor_area_radius 2
		elseif BATTLE_ROYALE
		else
  actor_area 14
  actor_area_radius 4 /* originally 6 */
  min_distance_group_placement 2
		endif
  avoid_forest_zone 4
  avoid_cliff_zone 2
}

create_object KERICEK
{
  number_of_objects          6
  group_placement_radius     3
  set_tight_grouping
  set_gaia_object_only
  set_place_for_every_player
		if GNR_RESSUPERCLOSE
  min_distance_to_players    7
  max_distance_to_players    11
		else
  min_distance_to_players    9
  max_distance_to_players    13
		endif
		if EMPIRE_WARS
		elseif BATTLE_ROYALE
		else
  actor_area 149
  actor_area_radius 4 /* originally 6 */
		endif
  avoid_forest_zone 4
  avoid_cliff_zone 2
  min_distance_group_placement 2
}
	endif

else

#define GNR_MISSINGTHEKER

endif

/* Empire Wars 8 Farms around TC */

if EMPIRE_WARS

	if GNR_EMP_LIMITTO5FARMS

/* limiting to  farms makes them spawn later */
/*
create_object FARM
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       3
  max_distance_to_players       6
  actor_area 21
  actor_area_radius 0
  find_closest
 }

create_object FARM
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       3
  max_distance_to_players       6
  actor_area 22
  actor_area_radius 0
  find_closest
 }

create_object FARM
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       3
  max_distance_to_players       6
  actor_area 23
  actor_area_radius 0
  find_closest
 }

create_object FARM
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       3
  max_distance_to_players       6
  actor_area 24
  actor_area_radius 0
  find_closest
 }

create_object FARM
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       3
  max_distance_to_players       6
  actor_area 25
  actor_area_radius 0
  find_closest
 }
*/

	elseif GNR_EMP_W_NOSPACE
/*
create_object FARM
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       3
  max_distance_to_players       6
  actor_area 21
  actor_area_radius 0
  find_closest
 }

create_object FARM
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       3
  max_distance_to_players       6
  actor_area 22
  actor_area_radius 0
  find_closest
 }

create_object FARM
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       3
  max_distance_to_players       6
  actor_area 23
  actor_area_radius 0
  find_closest
 }

create_object FARM
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       3
  max_distance_to_players       6
  actor_area 24
  actor_area_radius 0
  find_closest
 }

create_object FARM
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       3
  max_distance_to_players       6
  actor_area 25
  actor_area_radius 0
  find_closest
 }

create_object FARM
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       3
  max_distance_to_players       6
  actor_area 26
  actor_area_radius 0
  find_closest
 }
*/
	else

create_object FARM
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       3
  max_distance_to_players       3
  actor_area 21
  actor_area_radius 0
  second_object VILLAGER
 }

create_object FARM
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       3
  max_distance_to_players       3
  actor_area 22
  actor_area_radius 0
  second_object VILLAGER
 }

create_object FARM
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       3
  max_distance_to_players       3
  actor_area 23
  actor_area_radius 0
  second_object VILLAGER
 }

create_object FARM
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       3
  max_distance_to_players       3
  actor_area 24
  actor_area_radius 0
  second_object VILLAGER
 }

create_object FARM
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       3
  max_distance_to_players       3
  actor_area 25
  actor_area_radius 0
  second_object VILLAGER
 }

create_object FARM
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       4
  max_distance_to_players       4
  actor_area 26
  actor_area_radius 0
  second_object VILLAGER
 }

create_object FARM
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       4
  max_distance_to_players       6
  actor_area 27
  actor_area_radius 0
  find_closest
  second_object VILLAGER
 }

create_object FARM
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       4
  max_distance_to_players       6
  actor_area 28
  actor_area_radius 0
  find_closest
  second_object VILLAGER
 }

	endif

	if GNR_EMP_LIMITTO5FARMS
	elseif GNR_EMP_W_NOSPACE
	else

/* original farmers generation */
/*

create_object VILLAGER
{
  set_place_for_every_player
  number_of_objects 1
  actor_area_to_place_in 21
  actor_area 151
  actor_area_radius 2
 }

create_object VILLAGER
{
  set_place_for_every_player
  number_of_objects 1
  actor_area_to_place_in 22
  actor_area 152
  actor_area_radius 2
 }

create_object VILLAGER
{
  set_place_for_every_player
  number_of_objects 1
  actor_area_to_place_in 23
  actor_area 153
  actor_area_radius 2
 }

create_object VILLAGER
{
  set_place_for_every_player
  number_of_objects 1
  actor_area_to_place_in 24
  actor_area 154
  actor_area_radius 2
 }

create_object VILLAGER
{
  set_place_for_every_player
  number_of_objects 1
  actor_area_to_place_in 25
  actor_area 155
  actor_area_radius 2
 }

create_object VILLAGER
{
  set_place_for_every_player
  number_of_objects 1
  actor_area_to_place_in 26
  actor_area 156
  actor_area_radius 2
 }

create_object VILLAGER
{
  set_place_for_every_player
  number_of_objects 1
  actor_area_to_place_in 27
  actor_area 157
  actor_area_radius 2
 }

create_object VILLAGER
{
  set_place_for_every_player
  number_of_objects 1
  actor_area_to_place_in 28
  actor_area 158
  actor_area_radius 2
 }

*/
/* original farmers generation - end */

	endif
endif

/* Empire Wars Mill */

if EMPIRE_WARS
	if EMP_W_GIVEKERSUB
		if GNR_EMP_W_NOSPACE
		elseif GNR_EMP_W_CRAMPED
		else

create_object MILL
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       7
  max_distance_to_players       10
  avoid_forest_zone 3
  actor_area 721
  actor_area_radius 5
 }

create_object FARM
{
  set_place_for_every_player
  number_of_objects 1
  actor_area_to_place_in 721
  actor_area 212
  actor_area_radius 0
  find_closest
  second_object VILLAGER
 }

create_object FARM
{
  set_place_for_every_player
  number_of_objects 1
  actor_area_to_place_in 721
  actor_area 213
  actor_area_radius 0
  find_closest
  second_object VILLAGER
 }

create_object FARM
{
  set_place_for_every_player
  number_of_objects 1
  actor_area_to_place_in 721
  actor_area 214
  actor_area_radius 0
  find_closest
  second_object VILLAGER
 }

create_object FARM
{
  set_place_for_every_player
  number_of_objects 1
  actor_area_to_place_in 721
  actor_area 215
  actor_area_radius 0
  find_closest
  second_object VILLAGER
 }

create_object FARM
{
  set_place_for_every_player
  number_of_objects 1
  actor_area_to_place_in 721
  actor_area 216
  actor_area_radius 0
  find_closest
  second_object VILLAGER
 }

/* original KERSUB farmer generation */
/*

create_object VILLAGER
{
  set_place_for_every_player
  number_of_objects 1
  actor_area_to_place_in 212
  actor_area 159
  actor_area_radius 2
 }

create_object VILLAGER
{
  set_place_for_every_player
  number_of_objects 1
  actor_area_to_place_in 213
  actor_area 160
  actor_area_radius 2
 }

create_object VILLAGER
{
  set_place_for_every_player
  number_of_objects 1
  actor_area_to_place_in 214
  actor_area 161
  actor_area_radius 2
 }

create_object VILLAGER
{
  set_place_for_every_player
  number_of_objects 1
  actor_area_to_place_in 215
  actor_area 162
  actor_area_radius 2
 }

create_object VILLAGER
{
  set_place_for_every_player
  number_of_objects 1
  actor_area_to_place_in 216
  actor_area 163
  actor_area_radius 2
 }

*/
/* original KERSUB farmer generation - end */

		endif


	else

/* mill placed at the primary berry bush, if there are two, only the first one has the actor area ID */

		if GNR_MISSINGTHEKER
		else

create_object MILL
{
  set_place_for_every_player
  number_of_objects 1
  actor_area_to_place_in 14
  find_closest
  actor_area 40

			if GNR_EMP_W_NOSPACE
  actor_area_radius 2
			elseif GNR_EMP_W_CRAMPED
  actor_area_radius 3
			elseif GNR_EMP_W_LIMITED
  actor_area_radius 5
			else
  actor_area_radius 6
			endif

 }

create_object VILLAGER
{
  set_place_for_every_player
  number_of_objects 5
  actor_area_to_place_in 14
  actor_area 94

			if GNR_EMP_W_NOSPACE
  actor_area_radius 2
			elseif GNR_EMP_W_CRAMPED
  actor_area_radius 3
			elseif GNR_EMP_W_LIMITED
  actor_area_radius 5
			else
  actor_area_radius 6
			endif
  force_placement
  find_closest
 }

		endif
	endif
endif

/* Primary Gold Mine */

/*

GNR_STARTINGGOLD
GNR_STARTINGSTONE

GNR_STARTGOLD744CL
GNR_STARTGOLD544M
GNR_STARTGOLD444M
GNR_STARTGOLD77M
GNR_STARTGOLD74M
GNR_STARTGOLD54M
GNR_STARTGOLD44M
GNR_STARTGOLD33M
GNR_STARTGOLD22M
GNR_STARTGOLD4M
GNR_STARTGOLD3M
GNR_STARTGOLD2M
GNR_STARTGOLD1M

GNR_STARTSTONE54CL
GNR_STARTSTONE65M
GNR_STARTSTONE44M
GNR_STARTSTONE43M
GNR_STARTSTONE33M
GNR_STARTSTONE32M
GNR_STARTSTONE22M
GNR_STARTSTONE5M
GNR_STARTSTONE4M
GNR_STARTSTONE3M
GNR_STARTSTONE2M
GNR_STARTSTONE1M

*/

if INFINITE_RESOURCES
	if EMPIRE_WARS
	else
#define GNR_INFRES_REMOVEMAINGOLD
	endif
endif

if GNR_STARTINGGOLD

	if BATTLE_ROYALE
	elseif GNR_INFRES_REMOVEMAINGOLD
	else

create_object GOLD
{
		if GNR_STARTGOLD744CL
  number_of_objects          7
 group_placement_radius     3
			if EMPIRE_WARS
			else
 min_distance_group_placement 2
			endif
		elseif GNR_STARTGOLD544M
  number_of_objects          5
 group_placement_radius     3
		elseif GNR_STARTGOLD554M
  number_of_objects          5
 group_placement_radius     3
		elseif GNR_STARTGOLD444M
  number_of_objects          4
 group_placement_radius     3
		elseif GNR_STARTGOLD77M
  number_of_objects          7
 group_placement_radius     3
			if EMPIRE_WARS
			else
 min_distance_group_placement 2
			endif
		elseif GNR_STARTGOLD66M
  number_of_objects          6
 group_placement_radius     3
			if EMPIRE_WARS
			else
 min_distance_group_placement 2
			endif
		elseif GNR_STARTGOLD74M
  number_of_objects          7
 group_placement_radius     3
			if EMPIRE_WARS
			else
 min_distance_group_placement 2
			endif
		elseif GNR_STARTGOLD54M
  number_of_objects          5
 group_placement_radius     3
		elseif GNR_STARTGOLD44M
  number_of_objects          4
 group_placement_radius     3
		elseif GNR_STARTGOLD43M
  number_of_objects          4
 group_placement_radius     3
		elseif GNR_STARTGOLD33M
  number_of_objects          3
 group_placement_radius     2
		elseif GNR_STARTGOLD22M
  number_of_objects          2
 group_placement_radius     2
		elseif GNR_STARTGOLD8M
  number_of_objects          8
			if EMPIRE_WARS
			else
 min_distance_group_placement 2
			endif
		elseif GNR_STARTGOLD7M
  number_of_objects          7
			if EMPIRE_WARS
			else
 min_distance_group_placement 2
			endif
 group_placement_radius     3
		elseif GNR_STARTGOLD4M
  number_of_objects          4
 group_placement_radius     3
		elseif GNR_STARTGOLD3M
  number_of_objects          3
 group_placement_radius     2
		elseif GNR_STARTGOLD2M
  number_of_objects          2
 group_placement_radius     2
		elseif GNR_STARTGOLD1M
  number_of_objects          1
 group_placement_radius     2
		else
  number_of_objects          4
 group_placement_radius     3
		endif
  set_tight_grouping
  set_gaia_object_only
  set_place_for_every_player

		if GNR_STARTG_OPENDISTANCE
  min_distance_to_players 9
  max_distance_to_players 18
		else

			if GNR_RESSUPERCLOSE
				if GNR_STARTGS_INTCRANGE
  min_distance_to_players    4
  max_distance_to_players    9
				else
  min_distance_to_players    7
  max_distance_to_players    12
				endif
			elseif GNR_RESCLOSE
  min_distance_to_players    9
  max_distance_to_players    14
			elseif GNR_ARENAGS_DISTANCE
  min_distance_to_players    9
  max_distance_to_players    14
			elseif GNR_ISLANDGS_DISTANCE
  min_distance_to_players    12
  max_distance_to_players    19 /* reduced from 28 for primary gold */
			elseif GNR_ISLANDBGS_DISTANCE
  min_distance_to_players    12
  max_distance_to_players    19 /* reduced from 28 for primary gold */
			else
  min_distance_to_players    12
  max_distance_to_players    17
			endif

		endif

		if GNR_STARTGS_0WBLOCK
		elseif GNR_STARTGS_3WBLOCK
  max_distance_to_other_zones  3
		elseif GNR_STARTGS_5WBLOCK
  max_distance_to_other_zones  5
		else
  max_distance_to_other_zones  7
		endif


		if EMPIRE_WARS
  avoid_forest_zone 3
  avoid_cliff_zone 2
		else
  avoid_forest_zone 2 /* originally 1 */
  avoid_cliff_zone 2
		endif

		if EMPIRE_WARS
  actor_area 12

			if GNR_EMP_W_NOSPACE
  actor_area_radius 2
			elseif GNR_EMP_W_CRAMPED
  actor_area_radius 2
			else
  actor_area_radius 1
			endif

			if EMP_W_GIVEKERSUB
			else
  avoid_actor_area 40
  avoid_actor_area 94
			endif
		else
  actor_area 12
  actor_area_radius 5
			if EMP_W_GIVEKERSUB
			else
  avoid_actor_area 14
			endif

/* avoid farms */

			if GNR_STARTGS_INTCRANGE

  avoid_actor_area 151
  avoid_actor_area 152
  avoid_actor_area 153
  avoid_actor_area 154
  avoid_actor_area 155
  avoid_actor_area 156
  avoid_actor_area 157
  avoid_actor_area 158
  avoid_actor_area 159
  avoid_actor_area 160
  avoid_actor_area 161
  avoid_actor_area 162
  avoid_actor_area 163

			endif

		endif

		if GNR_STARTG_PLACELAYERA
terrain_to_place_on LAYER_A
		elseif GNR_STARTG_PLACELAYERC
terrain_to_place_on LAYER_C
		elseif GNR_STARTG_PLACELAYERD
terrain_to_place_on LAYER_D
		else
		endif

}
	endif

endif





/* Mining Camp for Empire Wars */

if EMPIRE_WARS

	if GNR_STARTINGGOLD

create_object MINING_CAMP
{
  set_place_for_every_player
  number_of_objects 1
  find_closest
  actor_area_to_place_in 12
  actor_area 10
  actor_area_radius 2
  avoid_forest_zone 1
 }

create_object VILLAGER
{
  set_place_for_every_player
  number_of_objects 4
  actor_area_to_place_in 12
  actor_area 171
		if GNR_EMP_W_CRAMPED
  actor_area_radius 2
		elseif GNR_EMP_W_NOSPACE
  actor_area_radius 1
		else
  actor_area_radius 5
		endif
  find_closest
  force_placement
 }

	endif
endif






/* Regicide buildings - 7 villagers, king, castle or tower */

if REGICIDE

	if GNR_REGICIDETOWER

create_object KING
{
  set_place_for_every_player
  min_distance_to_players       6
  max_distance_to_players       8
}

create_object WATCH_TOWER
{
  number_of_objects             1
  set_place_for_every_player
if EMPIRE_WARS
  min_distance_to_players    6
  max_distance_to_players    12
else
  min_distance_to_players    4
  max_distance_to_players    8
endif
}

	elseif GNR_REGICIDE_SPECIALTOWER

create_object KING
{
  set_place_for_every_player
  min_distance_to_players       6
  max_distance_to_players       8
}

#const FANCYTOWER 1102

create_object FANCYTOWER
{
  number_of_objects             1
  set_place_for_every_player
if EMPIRE_WARS
  min_distance_to_players    6
  max_distance_to_players    12
else
  min_distance_to_players    4
  max_distance_to_players    8
endif
}

	elseif GNR_REGICIDEKING

create_object KING
{
  set_place_for_every_player
  min_distance_to_players       4
  max_distance_to_players       5
}

	elseif GNR_REGICIDECLASSIC
		if EMPIRE_WARS
		else

create_object VILLAGER
{
  number_of_objects             7
  set_place_for_every_player
  min_distance_to_players       6
  max_distance_to_players       6
  force_placement
}
		endif

create_object KING
{
  set_place_for_every_player
  min_distance_to_players       6
  max_distance_to_players       6
}

create_object CASTLE
{
  set_place_for_every_player
if EMPIRE_WARS
  min_distance_to_players    8
  max_distance_to_players    14
else
  min_distance_to_players    10
  max_distance_to_players    10
endif
}
	else
	endif
endif








/* Empire Wars Lumbercamps */
/* possibly need to place them only after the gold */

if EMPIRE_WARS

	if GNR_DONTGIVELUMBER
	else

create_object LUMBER_CAMP
{
  set_place_for_every_player
  number_of_objects 1
  max_distance_to_players       67
  place_on_forest_zone 0
  find_closest
  actor_area 8
  actor_area_radius 4
  avoid_actor_area 94
  avoid_actor_area 40
		if GNR_EMP_W_NOSPACE
		else
  avoid_actor_area 171
		endif
 }

create_object VILLAGER
{
  set_place_for_every_player
  number_of_objects 4
  actor_area_to_place_in 8
  place_on_forest_zone 0
  actor_area 71
		if GNR_EMP_CLUMPLUMBER
  actor_area_radius 1
		else
			if GNR_EMP_W_NOSPACE
  actor_area_radius 1
			elseif GNR_EMP_W_CRAMPED
  actor_area_radius 2
			elseif GNR_EMP_W_LIMITED
  actor_area_radius 3
			else
  actor_area_radius 4
			endif
		endif
  find_closest
  force_placement
 }

		if GNR_EMP_W_NOSPACE
		else

create_object LUMBER_CAMP
{
  set_place_for_every_player
  number_of_objects 1
  max_distance_to_players       67
  place_on_forest_zone 0
  find_closest
  actor_area 9
  actor_area_radius 4

  avoid_actor_area 71

  avoid_actor_area 94
  avoid_actor_area 40
			if GNR_EMP_W_NOSPACE
			else
  avoid_actor_area 171
			endif
 }

create_object VILLAGER
{
  set_place_for_every_player
  number_of_objects 3
  actor_area_to_place_in 9
  place_on_forest_zone 0
  actor_area 72
			if GNR_EMP_CLUMPLUMBER
  actor_area_radius 1
	else
				if GNR_EMP_W_NOSPACE
  actor_area_radius 1
				elseif GNR_EMP_W_CRAMPED
  actor_area_radius 2
				elseif GNR_EMP_W_LIMITED
  actor_area_radius 3
				else
  actor_area_radius 4
				endif
			endif
  find_closest
  force_placement
 }

create_object LUMBER_CAMP
{
  set_place_for_every_player
  number_of_objects 1
  max_distance_to_players       67
  place_on_forest_zone 0

  avoid_actor_area 71
  avoid_actor_area 72

  avoid_actor_area 94
  avoid_actor_area 40
  find_closest
  actor_area 99
  actor_area_radius 4
			if GNR_EMP_W_NOSPACE
			else
  avoid_actor_area 171
			endif
 }

create_object VILLAGER
{
  set_place_for_every_player
  number_of_objects 3
  actor_area_to_place_in 99
  place_on_forest_zone 0
  actor_area 73
			if GNR_EMP_CLUMPLUMBER
  actor_area_radius 1
			else
				if GNR_EMP_W_NOSPACE
  actor_area_radius 1
				elseif GNR_EMP_W_CRAMPED
  actor_area_radius 2
				elseif GNR_EMP_W_LIMITED
  actor_area_radius 3
				else
  actor_area_radius 5
				endif
			endif
  find_closest
  force_placement
 }

		endif
	endif
endif



/* Blacksmith, barracks, and houses for Empire Wars */

if EMPIRE_WARS
	if GNR_EMP_W_NOSPACE

		if GNR_STEPPEHOUSES
create_object YURT2
		else
create_object HOUSE
		endif
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       7
  max_distance_to_players       14
  avoid_actor_area 40
  avoid_actor_area 10
  avoid_actor_area 94
  avoid_actor_area 171
  find_closest
 }

		if GNR_STEPPEHOUSES
create_object YURT3
		else
create_object HOUSE
		endif
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       7
  max_distance_to_players       14
  avoid_actor_area 40
  avoid_actor_area 10
  avoid_actor_area 94
  avoid_actor_area 171
  find_closest
 }

		if GNR_STEPPEHOUSES
create_object YURT4
		else
create_object HOUSE
		endif
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       7
  max_distance_to_players       14
  avoid_actor_area 40
  avoid_actor_area 10
  avoid_actor_area 94
  avoid_actor_area 171
  find_closest
 }

	else

create_object BLACKSMITH
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       7
  max_distance_to_players       11

  avoid_actor_area 94
  avoid_actor_area 40
  avoid_actor_area 8
  avoid_actor_area 9
  avoid_actor_area 99
  avoid_actor_area 171 /* primary gold villagers, large radius */

  actor_area 80
		if GNR_RESSUPERCLOSE
		elseif GNR_RESCLOSE
  actor_area_radius 2
		else
  actor_area_radius 4
		endif
 }

		if GNR_STEPPEHOUSES
create_object YURT5
		else
create_object HOUSE
		endif
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       7
  max_distance_to_players       14
  avoid_actor_area 40
  avoid_actor_area 10
  avoid_actor_area 94
  avoid_actor_area 171
  find_closest
 }

		if GNR_STEPPEHOUSES
create_object YURT6
		else
create_object HOUSE
		endif
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       7
  max_distance_to_players       14
  avoid_actor_area 40
  avoid_actor_area 10
  avoid_actor_area 94
  avoid_actor_area 171
  find_closest
 }

		if GNR_STEPPEHOUSES
create_object YURT7
		else
create_object HOUSE
		endif
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       7
  max_distance_to_players       14
  avoid_actor_area 40
  avoid_actor_area 10
  avoid_actor_area 94
  avoid_actor_area 171
  find_closest
 }

/* ***** blacksmith houses, replaced by individual ones ****** */
/*
create_object HOUSE
{
  set_place_for_every_player
  number_of_objects 1
  actor_area_to_place_in 80
  find_closest
  avoid_actor_area 40
  avoid_actor_area 10
  actor_area 45
  actor_area_radius 5
 }

create_object HOUSE
{
  set_place_for_every_player
  number_of_objects 1
  actor_area_to_place_in 80
  find_closest
  avoid_actor_area 40
  avoid_actor_area 10
  actor_area 46
  actor_area_radius 5
 }

create_object HOUSE
{
  set_place_for_every_player
  number_of_objects 1
  actor_area_to_place_in 80
  find_closest
  avoid_actor_area 40
  avoid_actor_area 10
  actor_area 47
  actor_area_radius 5
 }
*/

	endif

	if GNR_EMP_W_NOSPACE
	else

		if GNR_STEPPEHOUSES
create_object YURT
		else
create_object HOUSE
		endif
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       7
  max_distance_to_players       14
  avoid_actor_area 40
  avoid_actor_area 10
  avoid_actor_area 94
  avoid_actor_area 171
  find_closest
 }

		if GNR_STEPPEHOUSES
create_object YURT2
		else
create_object HOUSE
		endif
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       7
  max_distance_to_players       14
  avoid_actor_area 40
  avoid_actor_area 10
  avoid_actor_area 94
  avoid_actor_area 171
  find_closest
 }

		if GNR_STEPPEHOUSES
create_object YURT3
		else
create_object HOUSE
		endif
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       7
  max_distance_to_players       14
  avoid_actor_area 40
  avoid_actor_area 10
  avoid_actor_area 94
  avoid_actor_area 171
  find_closest
 }

	endif

/* **** other houses, also replaced by newer ones **** */
/*

create_object HOUSE
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       7
  max_distance_to_players       7
  avoid_actor_area 40
  avoid_actor_area 10
  actor_area 48
  actor_area_radius 5
 }

create_object HOUSE
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       7
  max_distance_to_players       7
  avoid_actor_area 40
  avoid_actor_area 10
  actor_area 49
  actor_area_radius 5
 }

create_object HOUSE
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       7
  max_distance_to_players       7
  avoid_actor_area 40
  avoid_actor_area 10
  actor_area 50
  actor_area_radius 5
 }

*/

	if GNR_EMP_W_NOSPACE
	else
		if GNR_EMP_NOBARRACKS
		else
create_object BARRACKS
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       7
  max_distance_to_players       9
  avoid_actor_area 94
  avoid_actor_area 40
  avoid_actor_area 8
  avoid_actor_area 9
  avoid_actor_area 99
  avoid_actor_area 171 /* primary gold villagers, large radius */
  actor_area 51
			if GNR_RESSUPERCLOSE
			elseif GNR_RESCLOSE
  actor_area_radius 2
			else
  actor_area_radius 5
			endif
 }
		endif

	endif

endif

/* The rest of home gold and stone */

if BATTLE_ROYALE /* no home gold or stone when battle royale */
elseif INFINITE_RESOURCES
else

if GNR_STARTINGGOLD
	if GNR_STARTGOLD3M
	elseif GNR_STARTGOLD8M
	elseif GNR_STARTGOLD7M
	elseif GNR_STARTGOLD4M
	elseif GNR_STARTGOLD2M
	elseif GNR_STARTGOLD1M
	else

create_object GOLD
{
		if GNR_STARTGOLD744CL
  number_of_objects          4
  group_placement_radius     3
		elseif GNR_STARTGOLD544M
  number_of_objects          4
  group_placement_radius     3
		elseif GNR_STARTGOLD554M
  number_of_objects          5
  group_placement_radius     3
		elseif GNR_STARTGOLD444M
  number_of_objects          4
  group_placement_radius     3
		elseif GNR_STARTGOLD77M
  number_of_objects          7
  group_placement_radius     3

 min_distance_group_placement 2

		elseif GNR_STARTGOLD66M
  number_of_objects          6
  group_placement_radius     3

 min_distance_group_placement 2

		elseif GNR_STARTGOLD74M
  number_of_objects          4
  group_placement_radius     3
		elseif GNR_STARTGOLD54M
  number_of_objects          4
  group_placement_radius     3
		elseif GNR_STARTGOLD44M
  number_of_objects          4
  group_placement_radius     3
		elseif GNR_STARTGOLD43M
  number_of_objects          3
  group_placement_radius     2
		elseif GNR_STARTGOLD33M
  number_of_objects          3
  group_placement_radius     2
		elseif GNR_STARTGOLD22M
  number_of_objects          2
 group_placement_radius     2
		else
  number_of_objects          3
 group_placement_radius     2
		endif
  set_tight_grouping
  set_gaia_object_only
  set_place_for_every_player

		if GNR_STARTG_OPENDISTANCE
  min_distance_to_players 14
  max_distance_to_players 25
		else

			if GNR_RESSUPERCLOSE
  min_distance_to_players    7
  max_distance_to_players    12
			elseif GNR_RESCLOSE
  min_distance_to_players    12
  max_distance_to_players    17
			elseif GNR_ARENAGS_DISTANCE
  min_distance_to_players    10
  max_distance_to_players    15
			elseif GNR_ISLANDGS_DISTANCE
  min_distance_to_players    12
  max_distance_to_players    28
			elseif GNR_ISLANDBGS_DISTANCE
  min_distance_to_players    12
  max_distance_to_players    28
			else
/* MEDIUM GOLD DISTANCE */
start_random
percent_chance 50
  min_distance_to_players    17
  max_distance_to_players    22
percent_chance 50
  min_distance_to_players    20
  max_distance_to_players    25
end_random
			endif
		endif

		if GNR_STARTGS_0WBLOCK
		elseif GNR_STARTGS_3WBLOCK
  max_distance_to_other_zones  3
		elseif GNR_STARTGS_5WBLOCK
  max_distance_to_other_zones  5
		else
  max_distance_to_other_zones  7
		endif

		if GNR_RESSUPERCLOSE
  avoid_forest_zone 1
  avoid_cliff_zone 2
		elseif GNR_RESCLOSE
  avoid_forest_zone 2	/* originally only 1 */
  avoid_cliff_zone 2
		else
  avoid_forest_zone 2
  avoid_cliff_zone 2
		endif
  actor_area 61
  actor_area_radius 5

		if EMPIRE_WARS
  avoid_actor_area 171
  avoid_actor_area 40
  avoid_actor_area 94
  avoid_actor_area 8
  avoid_actor_area 9
  avoid_actor_area 99
  avoid_actor_area 80 /* blacksmith */
  avoid_actor_area 51 /* barracks */
		else
  avoid_actor_area 14 /* kericek */
  avoid_actor_area 12 /* Primary gold, only use if no ew */
		endif


		if GNR_STARTG_PLACELAYERA
terrain_to_place_on LAYER_A
		elseif GNR_STARTG_PLACELAYERC
terrain_to_place_on LAYER_C
		elseif GNR_STARTG_PLACELAYERD
terrain_to_place_on LAYER_D
		else
		endif


}
	endif

/* continuing within if starting gold */

	if GNR_STARTGOLD77M
	elseif GNR_STARTGOLD66M
	elseif GNR_STARTGOLD74M
	elseif GNR_STARTGOLD54M
	elseif GNR_STARTGOLD44M
	elseif GNR_STARTGOLD43M
	elseif GNR_STARTGOLD33M
	elseif GNR_STARTGOLD22M
	elseif GNR_STARTGOLD8M
	elseif GNR_STARTGOLD7M
	elseif GNR_STARTGOLD4M
	elseif GNR_STARTGOLD3M
	elseif GNR_STARTGOLD2M
	elseif GNR_STARTGOLD1M
	else

create_object GOLD
{
  number_of_objects	     4
  group_placement_radius     3
  set_tight_grouping
  set_gaia_object_only
  set_place_for_every_player

		if GNR_STARTG_OPENDISTANCE
  min_distance_to_players 14
  max_distance_to_players 28
		else

			if GNR_RESSUPERCLOSE
  min_distance_to_players    10
  max_distance_to_players    15
			elseif GNR_RESCLOSE
  min_distance_to_players    15
  max_distance_to_players    20
			elseif GNR_ARENAGS_DISTANCE
  min_distance_to_players    26
  max_distance_to_players    30
			elseif GNR_ISLANDBGS_DISTANCE
  min_distance_to_players    16
  max_distance_to_players    29
			else
start_random
percent_chance 50
  min_distance_to_players    23
  max_distance_to_players    28
percent_chance 50
  min_distance_to_players    27
  max_distance_to_players    32
end_random
			endif
		endif

  min_distance_group_placement  3

		if GNR_STARTGS_0WBLOCK
		elseif GNR_STARTGS_3WBLOCK
  max_distance_to_other_zones  3
		elseif GNR_STARTGS_5WBLOCK
  max_distance_to_other_zones  5
		else
  max_distance_to_other_zones  7
		endif

		if GNR_RESSUPERCLOSE
  avoid_forest_zone 1
  avoid_cliff_zone 2
		elseif GNR_RESCLOSE
  avoid_forest_zone 2	/* originally only 1 */
  avoid_cliff_zone 2
		else
  avoid_forest_zone 2
  avoid_cliff_zone 2
		endif
  actor_area 62
  actor_area_radius 5

		if EMPIRE_WARS
  avoid_actor_area 171
  avoid_actor_area 40
  avoid_actor_area 94
  avoid_actor_area 8
  avoid_actor_area 9
  avoid_actor_area 99
  avoid_actor_area 80 /* blacksmith */
  avoid_actor_area 51 /* barracks */
		else
  avoid_actor_area 14 /* kericek */
  avoid_actor_area 12 /* Primary gold, only use if no ew */
		endif
  avoid_actor_area 61


		if GNR_STARTG_PLACELAYERA
terrain_to_place_on LAYER_A
		elseif GNR_STARTG_PLACELAYERC
terrain_to_place_on LAYER_C
		elseif GNR_STARTG_PLACELAYERD
terrain_to_place_on LAYER_D
		else
		endif

}
	endif
endif


if GNR_STARTINGSTONE

create_object STONE
{
	if GNR_STARTSTONE54CL
  number_of_objects          5
 group_placement_radius     3
	elseif GNR_STARTSTONE65M
  number_of_objects          6
 group_placement_radius     3
	elseif GNR_STARTSTONE55M
  number_of_objects          5
 group_placement_radius     3
	elseif GNR_STARTSTONE44M
  number_of_objects          4
 group_placement_radius     3
	elseif GNR_STARTSTONE444M
  number_of_objects          4
 group_placement_radius     3
	elseif GNR_STARTSTONE43M
  number_of_objects          4
 group_placement_radius     3
	elseif GNR_STARTSTONE33M
  number_of_objects          3
 group_placement_radius     2
	elseif GNR_STARTSTONE32M
  number_of_objects          3
 group_placement_radius     2
	elseif GNR_STARTSTONE22M
  number_of_objects          2
 group_placement_radius     2
	elseif GNR_STARTSTONE6M
  number_of_objects          6
 group_placement_radius     3
	elseif GNR_STARTSTONE5M
  number_of_objects          5
 group_placement_radius     3
	elseif GNR_STARTSTONE4M
  number_of_objects          4
 group_placement_radius     3
	elseif GNR_STARTSTONE3M
  number_of_objects          3
 group_placement_radius     2
	elseif GNR_STARTSTONE2M
  number_of_objects          2
 group_placement_radius     2
	elseif GNR_STARTSTONE1M
  number_of_objects          1
 group_placement_radius     2
	else
  number_of_objects          2
 group_placement_radius     2
	endif
  set_tight_grouping
  set_gaia_object_only
  set_place_for_every_player
	if GNR_RESSUPERCLOSE
		if GNR_STARTGS_INTCRANGE
  min_distance_to_players    5
  max_distance_to_players    10
		else
  min_distance_to_players    8
  max_distance_to_players    13
		endif
	elseif GNR_RESCLOSE
  min_distance_to_players    11
  max_distance_to_players    17
	elseif GNR_ARENAGS_DISTANCE
  min_distance_to_players    11
  max_distance_to_players    16
	elseif GNR_ISLANDGS_DISTANCE
  min_distance_to_players    14
  max_distance_to_players    30
	elseif GNR_ISLANDBGS_DISTANCE
  min_distance_to_players    13
  max_distance_to_players    27
	else
  min_distance_to_players    13
  max_distance_to_players    18
	endif
  min_distance_group_placement  3

	if GNR_ISLANDGS_DISTANCE
  max_distance_to_other_zones  4
	else
		if GNR_STARTGS_0WBLOCK
		elseif GNR_STARTGS_3WBLOCK
  max_distance_to_other_zones  3
		elseif GNR_STARTGS_5WBLOCK
  max_distance_to_other_zones  5
		else
  max_distance_to_other_zones  7
		endif
	endif

	if GNR_RESSUPERCLOSE
  avoid_forest_zone 1
  avoid_cliff_zone 2
	elseif GNR_RESCLOSE
  avoid_forest_zone 2	/* originally only 1 */
  avoid_cliff_zone 2
	else
  avoid_forest_zone 2
  avoid_cliff_zone 2
	endif
  actor_area 63
  actor_area_radius 5


	if EMPIRE_WARS
  avoid_actor_area 171
  avoid_actor_area 40
  avoid_actor_area 94
  avoid_actor_area 8
  avoid_actor_area 9
  avoid_actor_area 99
  avoid_actor_area 80 /* blacksmith */
  avoid_actor_area 51 /* barracks */

		if GNR_STARTGS_INTCRANGE

  avoid_actor_area 151
  avoid_actor_area 152
  avoid_actor_area 153
  avoid_actor_area 154
  avoid_actor_area 155
  avoid_actor_area 156
  avoid_actor_area 157
  avoid_actor_area 158
  avoid_actor_area 159
  avoid_actor_area 160
  avoid_actor_area 161
  avoid_actor_area 162
  avoid_actor_area 163

		endif
	else
  avoid_actor_area 14 /* kericek */
  avoid_actor_area 12 /* Primary gold, only use if no ew */
	endif
  avoid_actor_area 61
  avoid_actor_area 62
}


	if GNR_STARTSTONE5M
	elseif GNR_STARTSTONE6M
	elseif GNR_STARTSTONE4M
	elseif GNR_STARTSTONE3M
	elseif GNR_STARTSTONE2M
	elseif GNR_STARTSTONE1M
	else

create_object STONE
{
		if GNR_STARTSTONE54CL
  number_of_objects          4
 group_placement_radius     3
		elseif GNR_STARTSTONE65M
  number_of_objects          5
 group_placement_radius     3
		elseif GNR_STARTSTONE55M
  number_of_objects          5
 group_placement_radius     3
		elseif GNR_STARTSTONE44M
  number_of_objects          4
 group_placement_radius     3
		elseif GNR_STARTSTONE444M
  number_of_objects          4
 group_placement_radius     3
 number_of_groups	2
		elseif GNR_STARTSTONE43M
  number_of_objects          3
 group_placement_radius     2
		elseif GNR_STARTSTONE33M
  number_of_objects          3
 group_placement_radius     2
		elseif GNR_STARTSTONE32M
  number_of_objects          2
 group_placement_radius     2
		elseif GNR_STARTSTONE22M
  number_of_objects          2
 group_placement_radius     2
		else
  number_of_objects          3
 group_placement_radius     2
		endif
  set_tight_grouping
  set_gaia_object_only
  set_place_for_every_player
		if GNR_RESSUPERCLOSE
  min_distance_to_players    13
  max_distance_to_players    18
		elseif GNR_RESCLOSE
  min_distance_to_players    18
  max_distance_to_players    23
		elseif GNR_ARENAGS_DISTANCE
  min_distance_to_players    25
  max_distance_to_players    28
		elseif GNR_ISLANDGS_DISTANCE
  min_distance_to_players    14
  max_distance_to_players    30
		elseif GNR_ISLANDBGS_DISTANCE
  min_distance_to_players    14
  max_distance_to_players    26
		else
/* FAR STONE DISTANCE */
start_random
percent_chance 50
  min_distance_to_players    19
  max_distance_to_players    24
percent_chance 50
  min_distance_to_players    22
  max_distance_to_players    27
end_random
		endif
  min_distance_group_placement  3

		if GNR_ISLANDGS_DISTANCE
  max_distance_to_other_zones  4
		else
			if GNR_STARTGS_0WBLOCK
			elseif GNR_STARTGS_3WBLOCK
  max_distance_to_other_zones  3
			elseif GNR_STARTGS_5WBLOCK
  max_distance_to_other_zones  5
			else
  max_distance_to_other_zones  7
			endif
		endif

		if GNR_RESSUPERCLOSE
  avoid_forest_zone 1
  avoid_cliff_zone 2
		elseif GNR_RESCLOSE
  avoid_forest_zone 2	/* originally only 1 */
  avoid_cliff_zone 2
		else
  avoid_forest_zone 2
  avoid_cliff_zone 2
		endif

  actor_area 65
  actor_area_radius 5

		if EMPIRE_WARS
  avoid_actor_area 171
  avoid_actor_area 40
  avoid_actor_area 94
  avoid_actor_area 8
  avoid_actor_area 9
  avoid_actor_area 99
  avoid_actor_area 80 /* blacksmith */
  avoid_actor_area 51 /* barracks */
		else
  avoid_actor_area 14 /* kericek */
  avoid_actor_area 12 /* Primary gold, only use if no ew */
		endif
  avoid_actor_area 61
  avoid_actor_area 62
  avoid_actor_area 63
}
	endif
endif

endif /* endif of battle royale & infinite resources */




/*  limited farms come here */

if EMPIRE_WARS
	if GNR_EMP_LIMITTO5FARMS

create_object FARM
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       3
  max_distance_to_players       6
  actor_area 21
  actor_area_radius 0
  find_closest
  second_object VILLAGER
 }

create_object FARM
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       3
  max_distance_to_players       6
  actor_area 22
  actor_area_radius 0
  find_closest
  second_object VILLAGER
 }

create_object FARM
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       3
  max_distance_to_players       6
  actor_area 23
  actor_area_radius 0
  find_closest
  second_object VILLAGER
 }

create_object FARM
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       3
  max_distance_to_players       6
  actor_area 24
  actor_area_radius 0
  find_closest
  second_object VILLAGER
 }

create_object FARM
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       3
  max_distance_to_players       6
  actor_area 25
  actor_area_radius 0
  find_closest
  second_object VILLAGER
 }

/* original limited 5-farm generation for villagers */
/*

create_object VILLAGER
{
  set_place_for_every_player
  number_of_objects 1
  actor_area_to_place_in 21
  actor_area 151
  actor_area_radius 2
 }

create_object VILLAGER
{
  set_place_for_every_player
  number_of_objects 1
  actor_area_to_place_in 22
  actor_area 152
  actor_area_radius 2
 }

create_object VILLAGER
{
  set_place_for_every_player
  number_of_objects 1
  actor_area_to_place_in 23
  actor_area 153
  actor_area_radius 2
 }

create_object VILLAGER
{
  set_place_for_every_player
  number_of_objects 1
  actor_area_to_place_in 24
  actor_area 154
  actor_area_radius 2
 }

create_object VILLAGER
{
  set_place_for_every_player
  number_of_objects 1
  actor_area_to_place_in 25
  actor_area 155
  actor_area_radius 2
 }

*/
/* original limited 5-tile generation for villagers - end */

	elseif GNR_EMP_W_NOSPACE


create_object FARM
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       3
  max_distance_to_players       6
  actor_area 21
  actor_area_radius 0
  find_closest
  second_object VILLAGER
 }

create_object FARM
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       3
  max_distance_to_players       6
  actor_area 22
  actor_area_radius 0
  find_closest
  second_object VILLAGER
 }

create_object FARM
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       3
  max_distance_to_players       6
  actor_area 23
  actor_area_radius 0
  find_closest
  second_object VILLAGER
 }

create_object FARM
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       3
  max_distance_to_players       6
  actor_area 24
  actor_area_radius 0
  find_closest
  second_object VILLAGER
 }

create_object FARM
{
  set_place_for_every_player
  number_of_objects 1
  min_distance_to_players       3
  max_distance_to_players       6
  actor_area 25
  actor_area_radius 0
  find_closest
  second_object VILLAGER
 }

/* original farmers for 5-farm situation in case of no space */
/*

create_object VILLAGER
{
  set_place_for_every_player
  number_of_objects 1
  actor_area_to_place_in 21
  actor_area 151
  actor_area_radius 2
 }

create_object VILLAGER
{
  set_place_for_every_player
  number_of_objects 1
  actor_area_to_place_in 22
  actor_area 152
  actor_area_radius 2
 }

create_object VILLAGER
{
  set_place_for_every_player
  number_of_objects 1
  actor_area_to_place_in 23
  actor_area 153
  actor_area_radius 2
 }

create_object VILLAGER
{
  set_place_for_every_player
  number_of_objects 1
  actor_area_to_place_in 24
  actor_area 154
  actor_area_radius 2
 }

create_object VILLAGER
{
  set_place_for_every_player
  number_of_objects 1
  actor_area_to_place_in 25
  actor_area 155
  actor_area_radius 2
 }

*/

	endif
endif





/* Animals - sheep, boar, huntable, predators */

if GNR_GIVEHERD_A

	if DEATH_MATCH
	else

create_object HERDABLE_A
{
		if EMPIRE_WARS
   number_of_objects 1
   set_tight_grouping
   set_gaia_object_only
   set_place_for_every_player
   actor_area_to_place_in 100
   find_closest
		else
			if GNR_HERD4CLASSIC_A
				if PREPARE_FOR_COWS_A
   number_of_objects 3
				else
   number_of_objects 4
				endif
			elseif GNR_HERD3_A
				if PREPARE_FOR_COWS_A
   number_of_objects 2
				else
   number_of_objects 3
				endif
			elseif GNR_HERD2_A
   number_of_objects 2
			elseif GNR_HERD1_A
   number_of_objects 1
			elseif GNR_HERD6_A
				if PREPARE_FOR_COWS_A
   number_of_objects 4
				else
   number_of_objects 6
				endif
			endif
   set_loose_grouping
   set_gaia_object_only
   set_place_for_every_player
   min_distance_to_players    7
   max_distance_to_players    8	/* originally 8-9 */
		endif
  avoid_forest_zone 2
  avoid_cliff_zone 2

  		if EMPIRE_WARS
avoid_actor_area 12
avoid_actor_area 14
  		else
  		endif

}
	endif

endif

if GNR_GIVEHERD_B

	if DEATH_MATCH
	else

create_object HERDABLE_B
{
		if GNR_HERD22CLASSIC_B
			if PREPARE_FOR_COWS_B
   number_of_objects 3
   number_of_groups 1
			else
   number_of_objects 2
   number_of_groups 2
			endif
		elseif GNR_HERD33_B
			if PREPARE_FOR_COWS_B
   number_of_objects 2
   number_of_groups 3
			else
   number_of_objects 3
   number_of_groups 3
			endif
		elseif GNR_HERD4_B
			if PREPARE_FOR_COWS_B
   number_of_objects 3
   number_of_groups 1
			else
   number_of_objects 4
   number_of_groups 1
			endif
		elseif GNR_HERD3_B
			if PREPARE_FOR_COWS_B
   number_of_objects 2
   number_of_groups 1
			else
   number_of_objects 3
   number_of_groups 1
			endif
		elseif GNR_HERD2_B
   number_of_objects 2
   number_of_groups 1
		elseif GNR_HERD1_B
   number_of_objects 1
   number_of_groups 1
		endif
   set_loose_grouping
   set_gaia_object_only
   set_place_for_every_player

		if GNR_RESSUPERCLOSE

  min_distance_to_players    10
  max_distance_to_players    14

		elseif GNR_RESCLOSE

start_random
percent_chance 50
   min_distance_to_players    14
   max_distance_to_players    17
percent_chance 50
   min_distance_to_players    18
   max_distance_to_players    21
end_random

		else
			if GNR_HERDBDIST_CL

   min_distance_to_players    14
   max_distance_to_players    17

			elseif GNR_HERDBDIST_SCL

   min_distance_to_players    10
   max_distance_to_players    14

			elseif GNR_HERDBDIST_FAR

start_random
percent_chance 50
   min_distance_to_players    24
   max_distance_to_players    27
percent_chance 50
   min_distance_to_players    27
   max_distance_to_players    30
end_random

			else

/* DISTANT SHEEP CLASSIC */
start_random
percent_chance 20
   min_distance_to_players    14
   max_distance_to_players    17
percent_chance 20
   min_distance_to_players    18
   max_distance_to_players    21
percent_chance 20
   min_distance_to_players    20
   max_distance_to_players    23
percent_chance 20
   min_distance_to_players    24
   max_distance_to_players    27
percent_chance 20
   min_distance_to_players    27
   max_distance_to_players    30
end_random
			endif
		endif
		if GNR_RESSUPERCLOSE
  avoid_forest_zone 1
		else
  avoid_forest_zone 2
		endif

  		if EMPIRE_WARS
avoid_actor_area 12
avoid_actor_area 14
  		else
  		endif

}
	endif

endif


if GNR_GIVEHUNT

	if DEATH_MATCH
	else

create_object HUNTABLE
{
		if GNR_HUNT3OR4CLASSIC
start_random
percent_chance 50
  number_of_objects          4
percent_chance 50
  number_of_objects          3
end_random
		elseif GNR_HUNT8MODERN
  number_of_objects          8
		elseif GNR_HUNT6MODERN
  number_of_objects          6
		elseif GNR_HUNT4MODERN
  number_of_objects          4
		elseif GNR_HUNT3MODERN
  number_of_objects          3
		elseif GNR_HUNT2MODERN
  number_of_objects          2
		endif
		if GNR_HUNTGROUPS_2
  number_of_groups 	     2
		else
  number_of_groups 	     1
		endif
  group_placement_radius     3
  set_loose_grouping
  set_gaia_object_only
  set_place_for_every_player

		if GNR_RESSUPERCLOSE

  min_distance_to_players    10
  max_distance_to_players    14

		elseif GNR_RESCLOSE

start_random
percent_chance 50
   min_distance_to_players    14
   max_distance_to_players    17
percent_chance 50
   min_distance_to_players    17
   max_distance_to_players    21
end_random

		else
			if GNR_HUNTDIST_CL

   min_distance_to_players    14
   max_distance_to_players    17

			elseif GNR_HUNTDIST_SCL

   min_distance_to_players    10
   max_distance_to_players    14

			elseif GNR_HUNTDIST_FAR

start_random
percent_chance 50
   min_distance_to_players    24
   max_distance_to_players    27
percent_chance 50
   min_distance_to_players    27
   max_distance_to_players    30
end_random

			else

/* DISTANT SHEEP CLASSIC */
start_random
percent_chance 20
   min_distance_to_players    14
   max_distance_to_players    17
percent_chance 20
   min_distance_to_players    18
   max_distance_to_players    21
percent_chance 20
   min_distance_to_players    21
   max_distance_to_players    24
percent_chance 20
   min_distance_to_players    24
   max_distance_to_players    27
percent_chance 20
   min_distance_to_players    27
   max_distance_to_players    30
end_random
			endif
		endif

		if GNR_RESSUPERCLOSE
  avoid_forest_zone 1
		else
  avoid_forest_zone 2
		endif


  		if EMPIRE_WARS
avoid_actor_area 12
avoid_actor_area 14
  		else
 		endif


}

	endif

endif



if EMPIRE_WARS /* disabling boars on empire wars */
elseif BATTLE_ROYALE /* disabling boars on BATTLE ROYALE too */
elseif DEATH_MATCH
elseif GNR_GIVELURES

create_object LURABLE_A
{
	if GNR_CLASSICLURES
  number_of_objects          1
	elseif GNR_CLASSICLURES_ONE
  number_of_objects          1
	elseif GNR_CLASSICLURES_THREE
  number_of_objects          1
	elseif GNR_GROUPEDLURES_TWO
  number_of_objects          2
	elseif GNR_GROUPEDLURES_THREE
  number_of_objects          3
	endif
  set_loose_grouping
  set_gaia_object_only
  set_place_for_every_player


	if GNR_LUREDIST_CL

   min_distance_to_players    12
   max_distance_to_players    15

	elseif GNR_LUREDIST_SCL

   min_distance_to_players    8
   max_distance_to_players    11

	elseif GNR_LUREDIST_FAR

   min_distance_to_players    19
   max_distance_to_players    22

	elseif GNR_LUREDIST_OPENDIST

   min_distance_to_players    4
   max_distance_to_players    18

	else

		if GNR_RESSUPERCLOSE


   min_distance_to_players    8
   max_distance_to_players    11

		elseif GNR_RESCLOSE

   min_distance_to_players    12
   max_distance_to_players    15

		else

/* DISTANT BOAR */

   min_distance_to_players    16
   max_distance_to_players    19

/* originally 16-19 and 19-22, but reduced to 16-19 only to discourage boar stealing and limit unlucky map generations */

		endif
	endif

	if GNR_RESSUPERCLOSE
  avoid_forest_zone 1
	else
  avoid_forest_zone 2
	endif

	if GNR_LURETERRAIN_LAYERA
terrain_to_place_on LAYER_A
	elseif GNR_LURETERRAIN_LAYERC
terrain_to_place_on LAYER_C
	elseif GNR_LURETERRAIN_LAYERD
terrain_to_place_on LAYER_D
	else
	endif


  if EMPIRE_WARS
avoid_actor_area 12
avoid_actor_area 14
  else
  endif


}

	if GNR_LUREDOUBLEGROUP

create_object LURABLE_B
{
		if GNR_CLASSICLURES
  number_of_objects          1
		elseif GNR_CLASSICLURES_ONE
  number_of_objects          1
		elseif GNR_CLASSICLURES_THREE
  number_of_objects          1
		elseif GNR_GROUPEDLURES_TWO
  number_of_objects          2
		elseif GNR_GROUPEDLURES_THREE
  number_of_objects          3
		endif
  set_loose_grouping
  set_gaia_object_only
  set_place_for_every_player


		if GNR_LUREDIST_CL

   min_distance_to_players    12
   max_distance_to_players    15

		elseif GNR_LUREDIST_SCL

   min_distance_to_players    8
   max_distance_to_players    11

		elseif GNR_LUREDIST_FAR

   min_distance_to_players    19
   max_distance_to_players    22

		elseif GNR_LUREDIST_OPENDIST

   min_distance_to_players    4
   max_distance_to_players    18

		else

			if GNR_RESSUPERCLOSE


   min_distance_to_players    8
   max_distance_to_players    11

			elseif GNR_RESCLOSE

   min_distance_to_players    12
   max_distance_to_players    15

			else

/* DISTANT BOAR */


   min_distance_to_players    16
   max_distance_to_players    19

/* originally 16-19 and 19-22, but reduced to 16-19 only to discourage boar stealing and limit unlucky map generations */

			endif
		endif

		if GNR_RESSUPERCLOSE
  avoid_forest_zone 1
		else
  avoid_forest_zone 2
		endif


		if GNR_LURETERRAIN_LAYERA
terrain_to_place_on LAYER_A
		elseif GNR_LURETERRAIN_LAYERC
terrain_to_place_on LAYER_C
		elseif GNR_LURETERRAIN_LAYERD
terrain_to_place_on LAYER_D
		else
		endif


  if EMPIRE_WARS
avoid_actor_area 12
avoid_actor_area 14
  else
  endif


}

	endif

	if GNR_CLASSICLURES

create_object LURABLE_B
{
  number_of_objects          1
  set_loose_grouping
  set_gaia_object_only
  set_place_for_every_player

		if GNR_LUREDIST_CL

   min_distance_to_players    12
   max_distance_to_players    15

		elseif GNR_LUREDIST_SCL

   min_distance_to_players    8
   max_distance_to_players    11

		elseif GNR_LUREDIST_FAR

   min_distance_to_players    19
   max_distance_to_players    22

		elseif GNR_LUREDIST_OPENDIST

   min_distance_to_players    4
   max_distance_to_players    18

		else

			if GNR_RESSUPERCLOSE


   min_distance_to_players    8
   max_distance_to_players    11

			elseif GNR_RESCLOSE

   min_distance_to_players    12
   max_distance_to_players    15

			else

/* DISTANT BOAR */


   min_distance_to_players    16
   max_distance_to_players    19

/* originally 16-19 and 19-22, but reduced to 16-19 only to discourage boar stealing and limit unlucky map generations */

			endif
		endif

		if GNR_RESSUPERCLOSE
  avoid_forest_zone 1
		else
  avoid_forest_zone 2
		endif


		if GNR_LURETERRAIN_LAYERA
terrain_to_place_on LAYER_A
		elseif GNR_LURETERRAIN_LAYERC
terrain_to_place_on LAYER_C
		elseif GNR_LURETERRAIN_LAYERD
terrain_to_place_on LAYER_D
		else
		endif


  if EMPIRE_WARS
avoid_actor_area 12
avoid_actor_area 14
  else
  endif


}

	elseif GNR_CLASSICLURES_THREE

create_object LURABLE_B
{
  number_of_objects          1
  number_of_groups 	     2
  set_loose_grouping
  set_gaia_object_only
  set_place_for_every_player

		if GNR_LUREDIST_CL

   min_distance_to_players    12
   max_distance_to_players    15

		elseif GNR_LUREDIST_SCL

   min_distance_to_players    8
   max_distance_to_players    11

		elseif GNR_LUREDIST_FAR

   min_distance_to_players    19
   max_distance_to_players    22

		elseif GNR_LUREDIST_OPENDIST

   min_distance_to_players    4
   max_distance_to_players    18

		else

			if GNR_RESSUPERCLOSE


   min_distance_to_players    8
   max_distance_to_players    11

			elseif GNR_RESCLOSE

   min_distance_to_players    12
   max_distance_to_players    15

			else

/* DISTANT BOAR */


   min_distance_to_players    16
   max_distance_to_players    19

/* originally 16-19 and 19-22, but reduced to 16-19 only to discourage boar stealing and limit unlucky map generations */

			endif
		endif

		if GNR_RESSUPERCLOSE
  avoid_forest_zone 1
		else
  avoid_forest_zone 2
		endif


		if GNR_LURETERRAIN_LAYERA
terrain_to_place_on LAYER_A
		elseif GNR_LURETERRAIN_LAYERC
terrain_to_place_on LAYER_C
		elseif GNR_LURETERRAIN_LAYERD
terrain_to_place_on LAYER_D
		else
		endif


  if EMPIRE_WARS
avoid_actor_area 12
avoid_actor_area 14
  else
  endif


}

	endif

endif





/* predators:
GNR_CLASSICPRED
GNR_DOUBLEPRED
*/


if BATTLE_ROYALE /* disabling predators on BR */
elseif DEATH_MATCH
else

	if GNR_CLASSICPRED

create_object PREDATOR_A
{
  number_of_objects          2
  set_gaia_object_only
  set_place_for_every_player
  min_distance_group_placement 12
/* PREDATOR */
start_random
percent_chance 33
   min_distance_to_players    30
   max_distance_to_players    33
percent_chance 33
   min_distance_to_players    34
   max_distance_to_players    37
percent_chance 34
   min_distance_to_players    37
   max_distance_to_players    40
end_random
  avoid_forest_zone 1
}

	elseif GNR_DOUBLEPRED

create_object PREDATOR_B
{
  number_of_objects          2
  set_gaia_object_only
  set_place_for_every_player
  min_distance_group_placement 12
/* PREDATOR */
start_random
percent_chance 50
   min_distance_to_players    34
   max_distance_to_players    37
percent_chance 50
   min_distance_to_players    37
   max_distance_to_players    40
end_random
  avoid_forest_zone 1
}

/*
create_object PREDATOR_B
{
  number_of_objects          1
  set_gaia_object_only
  set_place_for_every_player
start_random
percent_chance 50
   min_distance_to_players    34
   max_distance_to_players    37
percent_chance 50
   min_distance_to_players    35
   max_distance_to_players    40
end_random
  avoid_forest_zone 1
}
*/

	endif

endif


/* Resources by map - kericek */

if DEATH_MATCH
elseif GNR_RESBYMAP_KER

	if TINY_MAP
	elseif SMALL_MAP
	elseif MEDIUM_MAP
	else

create_object KERICEK
{
     number_of_groups           9999
     number_of_objects          4
     group_placement_radius     2
     set_tight_grouping
     set_gaia_object_only
     min_distance_to_players	   40
     temp_min_distance_group_placement  112
}

	endif

endif






/* need to replace classic entirely and globally with the modern one, just keep the same numbers */

/*

GNR_FARGMODERN_GIVE
GNR_FARSMODERN_GIVE

GNR_FARG_CLASSIC
GNR_FARG_GENEROUS
GNR_FARG_GENEROUSPLUS
GNR_FARG_MEAGRE
GNR_FARG_LITTLE
GNR_FARG_NONE

GNR_FARS_CLASSIC
GNR_FARS_GENEROUS
GNR_FARS_GENEROUSPLUS
GNR_FARS_MEAGRE
GNR_FARS_LITTLE
GNR_FARS_NONE

GNR_FARG_LAYERA
GNR_FARG_LAYERC
GNR_FARG_LAYERD

GNR_FARS_LAYERA
GNR_FARS_LAYERC
GNR_FARS_LAYERD

A list of specials:

GNR_SPECIALGS_G
GNR_SPECIALGS_S
GNR_SPECIALGS_GS

GNR_SPECIALG_LAYERA
GNR_SPECIALG_LAYERC
GNR_SPECIALG_LAYERD

GNR_SPECIALS_LAYERA
GNR_SPECIALS_LAYERC
GNR_SPECIALS_LAYERD

GNR_SPECIALGS_LAYERA
GNR_SPECIALGS_LAYERC
GNR_SPECIALGS_LAYERD

GNR_SPECIALG_LARGE
GNR_SPECIALG_MEDIUM
GNR_SPECIALG_LOW

GNR_SPECIALS_LARGE
GNR_SPECIALS_MEDIUM
GNR_SPECIALS_LOW

GNR_SPECIALGS_LARGE
GNR_SPECIALGS_MEDIUM
GNR_SPECIALGS_LOW

*/

if BATTLE_ROYALE

/* Gold settings from Generous Plus */
	if GNR_DISABLEBRGOLD
	elseif INFINITE_RESOURCES	/* inf resources on BR still no gold or stone */
	else

create_object GOLD
{
		if TINY_MAP
     number_of_groups           9999 /* originally 2 */
     number_of_objects          3
     temp_min_distance_group_placement  16
		elseif SMALL_MAP
     number_of_groups           9999 /* originally 2 */
     number_of_objects          3
     temp_min_distance_group_placement  16
		elseif MEDIUM_MAP
     number_of_groups           9999
     number_of_objects          3
     temp_min_distance_group_placement  20
		elseif LARGE_MAP
     number_of_groups           9999
     number_of_objects          3
     temp_min_distance_group_placement  20
		elseif HUGE_MAP
     number_of_groups           9999
     number_of_objects          3
     temp_min_distance_group_placement  20
		else
     number_of_groups           9999
     number_of_objects          3
     temp_min_distance_group_placement  20
		endif
     group_placement_radius     2
     set_tight_grouping
     set_gaia_object_only
     avoid_forest_zone 2
     avoid_cliff_zone 2

  actor_area 66
  actor_area_radius 5

/*
disabled for battle royale, gold should be spread around:

		if GNR_FARG_LAYERA
     terrain_to_place_on LAYER_A
		elseif GNR_FARG_LAYERC
     terrain_to_place_on LAYER_C
		elseif GNR_FARG_LAYERD
     terrain_to_place_on LAYER_D
		else
		endif
*/

}

create_object STONE
{
		if TINY_MAP
     number_of_groups           9999 /* originally 2 */
     number_of_objects          1
     temp_min_distance_group_placement  16
		elseif SMALL_MAP
     number_of_groups           9999 /* originally 2 */
     number_of_objects          1
     temp_min_distance_group_placement  16
		elseif MEDIUM_MAP
     number_of_groups           9999
     number_of_objects          1
     temp_min_distance_group_placement  20
		elseif LARGE_MAP
     number_of_groups           9999
     number_of_objects          1
     temp_min_distance_group_placement  20
		elseif HUGE_MAP
     number_of_groups           9999
     number_of_objects          1
     temp_min_distance_group_placement  20
		else
     number_of_groups           9999
     number_of_objects          1
     temp_min_distance_group_placement  20
		endif
     group_placement_radius     2
     set_tight_grouping
     set_gaia_object_only
     avoid_forest_zone 2
     avoid_cliff_zone 2

  actor_area 67
  actor_area_radius 5

}

	endif

elseif INFINITE_RESOURCES	/* no gold or stone on infinite resources at all */
elseif GNR_FARGORIG_GIVE

	if GNR_FARGORIG_TYPE1

create_object GOLD
{
		if TINY_MAP

     number_of_objects          3
     number_of_groups           2
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif SMALL_MAP

     number_of_objects          3
     number_of_groups           2
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif MEDIUM_MAP

     number_of_objects          3
     number_of_groups           3
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif LARGE_MAP

     number_of_objects          3
     number_of_groups           3
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif HUGE_MAP

     number_of_objects          4
     number_of_groups           4
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif GIGANTIC_MAP

     number_of_objects          4
     number_of_groups           5
     temp_min_distance_group_placement  30
     group_placement_radius     2

		else

     number_of_objects          4
     number_of_groups           26
     temp_min_distance_group_placement  44
     group_placement_radius     2

		endif

     set_tight_grouping
     set_gaia_object_only

		if GNR_FARG_AVOID30PL
     min_distance_to_players	   30
 		elseif GNR_FARG_AVOID20PL
     min_distance_to_players	   20
 		elseif GNR_FARG_AVOID0PL
		else
     min_distance_to_players	   40
		endif

  avoid_forest_zone 3
  avoid_cliff_zone 4

  actor_area 66
  actor_area_radius 5

		if GNR_FARG_LAYERA
     terrain_to_place_on LAYER_A
		elseif GNR_FARG_LAYERC
     terrain_to_place_on LAYER_C
		elseif GNR_FARG_LAYERD
     terrain_to_place_on LAYER_D
		else
		endif
}



	elseif GNR_FARGORIG_TYPE2 /* Acropolis */


create_object GOLD
{
		if TINY_MAP

     number_of_objects          4
     number_of_groups           4
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif SMALL_MAP

     number_of_objects          4
     number_of_groups           6
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif MEDIUM_MAP

     number_of_objects          4
     number_of_groups           8
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif LARGE_MAP

     number_of_objects          5
     number_of_groups           11
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif HUGE_MAP

     number_of_objects          6
     number_of_groups           14
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif GIGANTIC_MAP

     number_of_objects          6
     number_of_groups           999
     temp_min_distance_group_placement  30
     group_placement_radius     2

		else

     number_of_objects          6
     number_of_groups           999
     temp_min_distance_group_placement  44
     group_placement_radius     2

		endif

     set_tight_grouping
     set_gaia_object_only

		if GNR_FARG_AVOID30PL
     min_distance_to_players	   30
 		elseif GNR_FARG_AVOID20PL
     min_distance_to_players	   20
 		elseif GNR_FARG_AVOID0PL
		else
     min_distance_to_players	   40
		endif

  avoid_forest_zone 3
  avoid_cliff_zone 4

  actor_area 66
  actor_area_radius 5

		if GNR_FARG_LAYERA
     terrain_to_place_on LAYER_A
		elseif GNR_FARG_LAYERC
     terrain_to_place_on LAYER_C
		elseif GNR_FARG_LAYERD
     terrain_to_place_on LAYER_D
		else
		endif
}


	elseif GNR_FARGORIG_TYPE3 /* AoF Maps */


create_object GOLD
{
		if TINY_MAP

     number_of_objects          4
     number_of_groups           2
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif SMALL_MAP

     number_of_objects          4
     number_of_groups           2
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif MEDIUM_MAP

     number_of_objects          4
     number_of_groups           3
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif LARGE_MAP

     number_of_objects          5
     number_of_groups           4
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif HUGE_MAP

     number_of_objects          5
     number_of_groups           5
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif GIGANTIC_MAP

     number_of_objects          6
     number_of_groups           6
     temp_min_distance_group_placement  30
     group_placement_radius     2

		else

     number_of_objects          6
     number_of_groups           999
     temp_min_distance_group_placement  44
     group_placement_radius     2

		endif

     set_tight_grouping
     set_gaia_object_only

		if GNR_FARG_AVOID30PL
     min_distance_to_players	   30
 		elseif GNR_FARG_AVOID20PL
     min_distance_to_players	   20
 		elseif GNR_FARG_AVOID0PL
		else
     min_distance_to_players	   40
		endif

  avoid_forest_zone 3
  avoid_cliff_zone 4

  actor_area 66
  actor_area_radius 5

		if GNR_FARG_LAYERA
     terrain_to_place_on LAYER_A
		elseif GNR_FARG_LAYERC
     terrain_to_place_on LAYER_C
		elseif GNR_FARG_LAYERD
     terrain_to_place_on LAYER_D
		else
		endif
}


	elseif GNR_FARGORIG_TYPE4 /* Scandinavia */


create_object GOLD
{
		if TINY_MAP

     number_of_objects          5
     number_of_groups           3
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif SMALL_MAP

     number_of_objects          5
     number_of_groups           3
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif MEDIUM_MAP

     number_of_objects          5
     number_of_groups           4
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif LARGE_MAP

     number_of_objects          5
     number_of_groups           4
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif HUGE_MAP

     number_of_objects          6
     number_of_groups           5
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif GIGANTIC_MAP

     number_of_objects          6
     number_of_groups           6
     temp_min_distance_group_placement  30
     group_placement_radius     2

		else

     number_of_objects          6
     number_of_groups           999
     temp_min_distance_group_placement  44
     group_placement_radius     2

		endif

     set_tight_grouping
     set_gaia_object_only

		if GNR_FARG_AVOID30PL
     min_distance_to_players	   30
 		elseif GNR_FARG_AVOID20PL
     min_distance_to_players	   20
 		elseif GNR_FARG_AVOID0PL
		else
     min_distance_to_players	   40
		endif

  avoid_forest_zone 3
  avoid_cliff_zone 4

  actor_area 66
  actor_area_radius 5

		if GNR_FARG_LAYERA
     terrain_to_place_on LAYER_A
		elseif GNR_FARG_LAYERC
     terrain_to_place_on LAYER_C
		elseif GNR_FARG_LAYERD
     terrain_to_place_on LAYER_D
		else
		endif
}



	elseif GNR_FARGORIG_TYPE5 /* Steppe */


create_object GOLD
{
		if TINY_MAP

     number_of_objects          3	/* originally 2 piles of 4 */
     number_of_groups           3
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif SMALL_MAP

     number_of_objects          3	/* originally 3 piles of 4 */
     number_of_groups           4
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif MEDIUM_MAP

     number_of_objects          4
     number_of_groups           4
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif LARGE_MAP

     number_of_objects          5
     number_of_groups           5
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif HUGE_MAP

     number_of_objects          5
     number_of_groups           6
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif GIGANTIC_MAP

     number_of_objects          6
     number_of_groups           7
     temp_min_distance_group_placement  30
     group_placement_radius     2

		else

     number_of_objects          6
     number_of_groups           999
     temp_min_distance_group_placement  44
     group_placement_radius     2

		endif

     set_tight_grouping
     set_gaia_object_only

		if GNR_FARG_AVOID30PL
     min_distance_to_players	   30
 		elseif GNR_FARG_AVOID20PL
     min_distance_to_players	   20
 		elseif GNR_FARG_AVOID0PL
		else
     min_distance_to_players	   26
		endif

  avoid_forest_zone 3
  avoid_cliff_zone 4

  actor_area 66
  actor_area_radius 5

		if GNR_FARG_LAYERA
     terrain_to_place_on LAYER_A
		elseif GNR_FARG_LAYERC
     terrain_to_place_on LAYER_C
		elseif GNR_FARG_LAYERD
     terrain_to_place_on LAYER_D
		else
		endif
}

	else
	endif


elseif GNR_FARGMODERN_GIVE

create_object GOLD
{
	if TINY_MAP

		if GNR_FARG_CLASSIC
     number_of_objects          3
     temp_min_distance_group_placement  52 /* previously 62 */
     number_of_groups           2	/* previously at 9999 */
		elseif GNR_FARG_GENEROUS
     number_of_objects          4
     temp_min_distance_group_placement  42
     number_of_groups           9999
		elseif GNR_FARG_GENEROUSPLUS
     number_of_objects          4
     temp_min_distance_group_placement  24
     number_of_groups           9999
		elseif GNR_FARG_MEAGRE
     number_of_objects          2
     temp_min_distance_group_placement  72
     number_of_groups           9999
		elseif GNR_FARG_LITTLE
     number_of_objects          2
     temp_min_distance_group_placement  100
     number_of_groups           9999
		endif

	elseif SMALL_MAP
		if GNR_FARG_CLASSIC
     number_of_objects          3
     temp_min_distance_group_placement  72 /* previously 82 */
     number_of_groups           2	/* previously at 9999 */
		elseif GNR_FARG_GENEROUS
     number_of_objects          4
     temp_min_distance_group_placement  52
     number_of_groups           9999
		elseif GNR_FARG_GENEROUSPLUS
     number_of_objects          4
     temp_min_distance_group_placement  29
     number_of_groups           9999
		elseif GNR_FARG_MEAGRE
     number_of_objects          2
     temp_min_distance_group_placement  102
     number_of_groups           9999
		elseif GNR_FARG_LITTLE
     number_of_objects          2
     temp_min_distance_group_placement  140
     number_of_groups           9999
		endif
	elseif MEDIUM_MAP
     number_of_groups           9999
		if GNR_FARG_CLASSIC
     number_of_objects          4
     temp_min_distance_group_placement  108
		elseif GNR_FARG_GENEROUS
     number_of_objects          4
     temp_min_distance_group_placement  72
		elseif GNR_FARG_GENEROUSPLUS
     number_of_objects          4
     temp_min_distance_group_placement  35
		elseif GNR_FARG_MEAGRE
     number_of_objects          3
     temp_min_distance_group_placement  126
		elseif GNR_FARG_LITTLE
     number_of_objects          2
     temp_min_distance_group_placement  140
		endif
	elseif LARGE_MAP
     number_of_groups           9999
		if GNR_FARG_CLASSIC
     number_of_objects          4
     temp_min_distance_group_placement  108
		elseif GNR_FARG_GENEROUS
     number_of_objects          4
     temp_min_distance_group_placement  72
		elseif GNR_FARG_GENEROUSPLUS
     number_of_objects          4
     temp_min_distance_group_placement  35
		elseif GNR_FARG_MEAGRE
     number_of_objects          3
     temp_min_distance_group_placement  126
		elseif GNR_FARG_LITTLE
     number_of_objects          2
     temp_min_distance_group_placement  140
		endif
	elseif HUGE_MAP
     number_of_groups           9999
		if GNR_FARG_CLASSIC
     number_of_objects          4
     temp_min_distance_group_placement  97
		elseif GNR_FARG_GENEROUS
     number_of_objects          4
     temp_min_distance_group_placement  72
		elseif GNR_FARG_GENEROUSPLUS
     number_of_objects          4
     temp_min_distance_group_placement  35
		elseif GNR_FARG_MEAGRE
     number_of_objects          3
     temp_min_distance_group_placement  118
		elseif GNR_FARG_LITTLE
     number_of_objects          2
     temp_min_distance_group_placement  151
		endif
	else
     number_of_groups           9999
		if GNR_FARG_CLASSIC
     number_of_objects          4	/* originally 5 */
     temp_min_distance_group_placement  88
		elseif GNR_FARG_GENEROUS
     number_of_objects          4
     temp_min_distance_group_placement  62
		elseif GNR_FARG_GENEROUSPLUS
     number_of_objects          4
     temp_min_distance_group_placement  32
		elseif GNR_FARG_MEAGRE
     number_of_objects          3
     temp_min_distance_group_placement  104
		elseif GNR_FARG_LITTLE
     number_of_objects          2
     temp_min_distance_group_placement  161
		endif
	endif
     group_placement_radius     2
     set_tight_grouping
     set_gaia_object_only

	if GNR_FARG_AVOID30PL
     min_distance_to_players	   30
 	elseif GNR_FARG_AVOID20PL
     min_distance_to_players	   20
 	elseif GNR_FARG_AVOID0PL
	else
     min_distance_to_players	   40
	endif

     avoid_forest_zone 3
     avoid_cliff_zone 4

  actor_area 66
  actor_area_radius 5

	if GNR_FARG_LAYERA
     terrain_to_place_on LAYER_A
	elseif GNR_FARG_LAYERC
     terrain_to_place_on LAYER_C
	elseif GNR_FARG_LAYERD
     terrain_to_place_on LAYER_D
	else
	endif
}

endif

if BATTLE_ROYALE /* No stone here for map for battle royale */
elseif INFINITE_RESOURCES	/* no stone or gold at all for infinite resources */
elseif GNR_FARSORIG_GIVE

	if GNR_FARSORIG_TYPE1


create_object STONE
{
		if TINY_MAP	/* changed from 1 group of 4 */

     number_of_objects          2
     number_of_groups           2
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif SMALL_MAP	/* changed from 1 group of 4 */

     number_of_objects          2
     number_of_groups           2
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif MEDIUM_MAP

     number_of_objects          3	/* changed from 2 groups of 4 */
     number_of_groups           3
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif LARGE_MAP

     number_of_objects          4
     number_of_groups           3
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif HUGE_MAP

     number_of_objects          4
     number_of_groups           4
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif GIGANTIC_MAP

     number_of_objects          4
     number_of_groups           999
     temp_min_distance_group_placement  30
     group_placement_radius     2

		else

     number_of_objects          4
     number_of_groups           999
     temp_min_distance_group_placement  44
     group_placement_radius     2

		endif

     set_tight_grouping
     set_gaia_object_only

		if GNR_FARS_AVOID30PL
     min_distance_to_players	   30
 		elseif GNR_FARS_AVOID20PL
     min_distance_to_players	   20
 		elseif GNR_FARS_AVOID0PL
		else
     min_distance_to_players	   40
		endif

     avoid_forest_zone 3
     avoid_cliff_zone 4

  actor_area 67
  actor_area_radius 5

		if GNR_FARS_LAYERA
     terrain_to_place_on LAYER_A
		elseif GNR_FARS_LAYERC
     terrain_to_place_on LAYER_C
		elseif GNR_FARS_LAYERD
     terrain_to_place_on LAYER_D
		else
		endif
}

	elseif GNR_FARSORIG_TYPE2

create_object STONE
{
		if TINY_MAP

     number_of_objects          3
     number_of_groups           2
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif SMALL_MAP

     number_of_objects          3
     number_of_groups           4
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif MEDIUM_MAP

     number_of_objects          4
     number_of_groups           6
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif LARGE_MAP

     number_of_objects          4
     number_of_groups           10
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif HUGE_MAP

     number_of_objects          5
     number_of_groups           12
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif GIGANTIC_MAP

     number_of_objects          5
     number_of_groups           999
     temp_min_distance_group_placement  30
     group_placement_radius     2

		else

     number_of_objects          5
     number_of_groups           999
     temp_min_distance_group_placement  44
     group_placement_radius     2

		endif

     set_tight_grouping
     set_gaia_object_only

		if GNR_FARS_AVOID30PL
     min_distance_to_players	   30
 		elseif GNR_FARS_AVOID20PL
     min_distance_to_players	   20
 		elseif GNR_FARS_AVOID0PL
		else
     min_distance_to_players	   40
		endif

     avoid_forest_zone 3
     avoid_cliff_zone 4

  actor_area 67
  actor_area_radius 5

		if GNR_FARS_LAYERA
     terrain_to_place_on LAYER_A
		elseif GNR_FARS_LAYERC
     terrain_to_place_on LAYER_C
		elseif GNR_FARS_LAYERD
     terrain_to_place_on LAYER_D
		else
		endif
}

	elseif GNR_FARSORIG_TYPE3

create_object STONE
{
		if TINY_MAP

     number_of_objects          3
     number_of_groups           2
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif SMALL_MAP

     number_of_objects          3
     number_of_groups           2
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif MEDIUM_MAP

     number_of_objects          4
     number_of_groups           3
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif LARGE_MAP

     number_of_objects          4
     number_of_groups           4
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif HUGE_MAP

     number_of_objects          4
     number_of_groups           5
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif GIGANTIC_MAP

     number_of_objects          4
     number_of_groups           6
     temp_min_distance_group_placement  30
     group_placement_radius     2

		else

     number_of_objects          5
     number_of_groups           999
     temp_min_distance_group_placement  44
     group_placement_radius     2

		endif

     set_tight_grouping
     set_gaia_object_only

		if GNR_FARS_AVOID30PL
     min_distance_to_players	   30
 		elseif GNR_FARS_AVOID20PL
     min_distance_to_players	   20
 		elseif GNR_FARS_AVOID0PL
		else
     min_distance_to_players	   40
		endif

     avoid_forest_zone 3
     avoid_cliff_zone 4

  actor_area 67
  actor_area_radius 5

		if GNR_FARS_LAYERA
     terrain_to_place_on LAYER_A
		elseif GNR_FARS_LAYERC
     terrain_to_place_on LAYER_C
		elseif GNR_FARS_LAYERD
     terrain_to_place_on LAYER_D
		else
		endif
}

	elseif GNR_FARSORIG_TYPE5 /* steppe stone */

create_object STONE
{
		if TINY_MAP

     number_of_objects          3
     number_of_groups           2
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif SMALL_MAP

     number_of_objects          3
     number_of_groups           3
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif MEDIUM_MAP

     number_of_objects          4
     number_of_groups           4
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif LARGE_MAP

     number_of_objects          4
     number_of_groups           5
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif HUGE_MAP

     number_of_objects          4
     number_of_groups           6
     temp_min_distance_group_placement  30
     group_placement_radius     2

		elseif GIGANTIC_MAP

     number_of_objects          4
     number_of_groups           7
     temp_min_distance_group_placement  30
     group_placement_radius     2

		else

     number_of_objects          5
     number_of_groups           999
     temp_min_distance_group_placement  44
     group_placement_radius     2

		endif

     set_tight_grouping
     set_gaia_object_only

		if GNR_FARS_AVOID30PL
     min_distance_to_players	   30
 		elseif GNR_FARS_AVOID20PL
     min_distance_to_players	   20
 		elseif GNR_FARS_AVOID0PL
		else
     min_distance_to_players	   26
		endif

     avoid_forest_zone 3
     avoid_cliff_zone 4

  actor_area 67
  actor_area_radius 5

		if GNR_FARS_LAYERA
     terrain_to_place_on LAYER_A
		elseif GNR_FARS_LAYERC
     terrain_to_place_on LAYER_C
		elseif GNR_FARS_LAYERD
     terrain_to_place_on LAYER_D
		else
		endif
}

	else
	endif


elseif GNR_FARSMODERN_GIVE

create_object STONE
{

	if TINY_MAP

		if GNR_FARS_CLASSIC
     number_of_objects          2
     number_of_groups           1
     temp_min_distance_group_placement  5
		elseif GNR_FARS_GENEROUS
     number_of_objects          3
     number_of_groups           9999
     temp_min_distance_group_placement  52
		elseif GNR_FARS_GENEROUSPLUS
     number_of_objects          4
     number_of_groups           9999
     temp_min_distance_group_placement  28
		elseif GNR_FARS_MEAGRE
     number_of_objects          1
     number_of_groups           2
     temp_min_distance_group_placement  54
		elseif GNR_FARS_LITTLE
     number_of_objects          1
     number_of_groups           1
     temp_min_distance_group_placement  5
		endif

	elseif SMALL_MAP


		if GNR_FARS_CLASSIC
     number_of_objects          3
     number_of_groups           1
     temp_min_distance_group_placement  5
		elseif GNR_FARS_GENEROUS
     number_of_objects          3
     number_of_groups           9999
     temp_min_distance_group_placement  67
		elseif GNR_FARS_GENEROUSPLUS
     number_of_objects          4
     number_of_groups           9999
     temp_min_distance_group_placement  34
		elseif GNR_FARS_MEAGRE
     number_of_objects          2
     number_of_groups           1
     temp_min_distance_group_placement  5
		elseif GNR_FARS_LITTLE
     number_of_objects          1
     number_of_groups           2
     temp_min_distance_group_placement  5
		endif

	elseif MEDIUM_MAP

		if GNR_FARS_CLASSIC
     number_of_objects          3
     number_of_groups           9999 /* target 2 */
     temp_min_distance_group_placement  108
		elseif GNR_FARS_GENEROUS
     number_of_objects          3
     number_of_groups           9999
     temp_min_distance_group_placement  71
		elseif GNR_FARS_GENEROUSPLUS
     number_of_objects          4
     number_of_groups           9999
     temp_min_distance_group_placement  34
		elseif GNR_FARS_MEAGRE
     number_of_objects          3
     number_of_groups           2
     temp_min_distance_group_placement  54
		elseif GNR_FARS_LITTLE
     number_of_objects          2
     number_of_groups           1
     temp_min_distance_group_placement  5
		endif

	elseif LARGE_MAP

		if GNR_FARS_CLASSIC
     number_of_objects          4
     number_of_groups           9999 /* target 3 */
     temp_min_distance_group_placement  108
		elseif GNR_FARS_GENEROUS
     number_of_objects          4
     number_of_groups           9999
     temp_min_distance_group_placement  67
		elseif GNR_FARS_GENEROUSPLUS
     number_of_objects          4
     number_of_groups           9999
     temp_min_distance_group_placement  28
		elseif GNR_FARS_MEAGRE
     number_of_objects          2
     number_of_groups           9999
     temp_min_distance_group_placement  127
		elseif GNR_FARS_LITTLE
     number_of_objects          2
     number_of_groups           1
     temp_min_distance_group_placement  5
		endif

	elseif HUGE_MAP

		if GNR_FARS_CLASSIC
     number_of_objects          4
     number_of_groups           9999 /* target 4 */
     temp_min_distance_group_placement  97
		elseif GNR_FARS_GENEROUS
     number_of_objects          4
     number_of_groups           9999
     temp_min_distance_group_placement  52
		elseif GNR_FARS_GENEROUSPLUS
     number_of_objects          4
     number_of_groups           9999
     temp_min_distance_group_placement  28
		elseif GNR_FARS_MEAGRE
     number_of_objects          3
     number_of_groups           9999
     temp_min_distance_group_placement  127
		elseif GNR_FARS_LITTLE
     number_of_objects          3
     number_of_groups           1
     temp_min_distance_group_placement  5
		endif

	else

		if GNR_FARS_CLASSIC
     number_of_groups           9999
     number_of_objects          4
     temp_min_distance_group_placement  88
		elseif GNR_FARS_GENEROUS
     number_of_objects          4
     number_of_groups           9999
     temp_min_distance_group_placement  52
		elseif GNR_FARS_GENEROUSPLUS
     number_of_objects          4
     number_of_groups           9999
     temp_min_distance_group_placement  28
		elseif GNR_FARS_MEAGRE
     number_of_objects          3
     number_of_groups           9999
     temp_min_distance_group_placement  167
		elseif GNR_FARS_LITTLE
     number_of_objects          3
     number_of_groups           2
     temp_min_distance_group_placement  167
		endif


	endif


     group_placement_radius     2
     set_tight_grouping
     set_gaia_object_only

	if GNR_FARS_AVOID30PL
     min_distance_to_players	   30
 	elseif GNR_FARS_AVOID20PL
     min_distance_to_players	   20
 	elseif GNR_FARS_AVOID0PL
	else
     min_distance_to_players	   40
	endif

     avoid_forest_zone 3
     avoid_cliff_zone 4

  actor_area 67
  actor_area_radius 5

	if GNR_FARS_LAYERA
     terrain_to_place_on LAYER_A
	elseif GNR_FARS_LAYERC
     terrain_to_place_on LAYER_C
	elseif GNR_FARS_LAYERD
     terrain_to_place_on LAYER_D
	else
	endif
}

endif


/* far herding */

if GNR_GIVEFARHERD

	if DEATH_MATCH
	else

create_object HERDABLE_B
{

		if GNR_FARHERD_INFINITE
  number_of_groups 9999
		elseif GNR_FARHERD_20LIMIT
  number_of_groups 20
		elseif GNR_FARHERD_10LIMIT
  number_of_groups 10
		elseif GNR_FARHERD_5LIMIT
  number_of_groups 5
		else
  number_of_groups 5
		endif

		if GNR_FARHERD1GR
  number_of_objects 1
		elseif GNR_FARHERD2GR
  number_of_objects 2
		elseif GNR_FARHERD3GR
  number_of_objects 3
		else
  number_of_objects 1
		endif


  group_placement_radius 2
  set_gaia_object_only

		if GNR_FARHERD_DONTAVOID
		else
  min_distance_to_players 30
		endif

		if GNR_FARHERD4PLACE
  temp_min_distance_group_placement 4
		elseif GNR_FARHERD10PLACE
  temp_min_distance_group_placement 10
		elseif GNR_FARHERD22PLACE
  temp_min_distance_group_placement 22
		elseif GNR_FARHERD40PLACE
  temp_min_distance_group_placement 40
		elseif GNR_FARHERD60PLACE
  temp_min_distance_group_placement 60
		elseif GNR_FARHERD80PLACE
  temp_min_distance_group_placement 80
		else
  temp_min_distance_group_placement 22
		endif

  max_distance_to_other_zones 0

		if GNR_FARHERD_LAYERA
terrain_to_place_on LAYER_A
		elseif GNR_FARHERD_LAYERC
terrain_to_place_on LAYER_C
		elseif GNR_FARHERD_LAYERD
terrain_to_place_on LAYER_D
		endif

}

	endif

endif







/* Home Stragglers */

if GNR_HOMESTRAGGLE

	if EMPIRE_WARS
	elseif DEATH_MATCH
	else

create_object STRAGGLER
{
  number_of_objects             2
  set_gaia_object_only
  set_place_for_every_player
  min_distance_to_players       4
  max_distance_to_players       5
  min_distance_group_placement  2
  avoid_actor_area 14
}
create_object STRAGGLER
{
  number_of_objects             3
  set_gaia_object_only
  set_place_for_every_player
  min_distance_to_players       6
  max_distance_to_players       8
  min_distance_group_placement  2
  avoid_actor_area 14
}

	endif

elseif GNR_HOMEUNIQUESTRAGGLE

	if EMPIRE_WARS
	elseif DEATH_MATCH
	else

create_object UNIQSTRAGGLER
{
  number_of_objects             2
  set_gaia_object_only
  set_place_for_every_player
  min_distance_to_players       4
  max_distance_to_players       5
  min_distance_group_placement  2
  avoid_actor_area 14
}
create_object UNIQSTRAGGLER
{
  number_of_objects             3
  set_gaia_object_only
  set_place_for_every_player
  min_distance_to_players       6
  max_distance_to_players       8
  min_distance_group_placement  2
  avoid_actor_area 14
}

	endif
endif

/* Standard birds */

if GNR_NORMALBIRDS

create_object BIRDS_A
{
   number_of_objects         2
   set_scaling_to_map_size
}

create_object BIRDS_B
{
   number_of_objects         2
   set_scaling_to_map_size
}

elseif GNR_ABIRDS_ONLY

create_object BIRDS_A
{
   number_of_objects         4
   set_scaling_to_map_size
}


endif

/* Captain Fin */

if INFINITE_RESOURCES
elseif GNR_STANDARDFISH

	if DEATH_MATCH
	else

create_object MELKARYBA
{
  number_of_objects                   9999
  set_gaia_object_only
		if GNR_SFISH_SPARSE
 temp_min_distance_group_placement  14
		else
 temp_min_distance_group_placement  6
		endif
}

	endif

	if GNR_BIGFISH_DENSE

create_object FISH_A
{
  number_of_objects             1
number_of_groups 99999
  set_gaia_object_only
  temp_min_distance_group_placement  6
}

create_object FISH_B
{
  number_of_objects             1
number_of_groups 99999
  set_gaia_object_only
  temp_min_distance_group_placement  6
}

	elseif GNR_BIGFISH_SUPERDENSE

create_object FISH_A
{
  number_of_objects             1
number_of_groups 99999
  set_gaia_object_only
  temp_min_distance_group_placement  4
}

create_object FISH_B
{
  number_of_objects             1
number_of_groups 99999
  set_gaia_object_only
  temp_min_distance_group_placement  4
}

	else

create_object FISH_A
{
  number_of_objects                   6
  set_scaling_to_map_size
  set_gaia_object_only
  max_distance_to_other_zones         4
  min_distance_group_placement  4
}
create_object FISH_B
{
  number_of_objects                   170
  set_scaling_to_map_size
  set_gaia_object_only
  max_distance_to_other_zones         4
  min_distance_group_placement  8
}

	endif

elseif GNR_SMALLFISHONLY

/* arabia fish here */
/*
create_object SHORE_FISH
{
  number_of_objects                    4
  min_distance_group_placement         5
  set_gaia_object_only
  set_scaling_to_map_size
}
*/

	if DEATH_MATCH
	else

create_object MELKARYBA
{
  number_of_objects                   9999
  /* set_scaling_to_map_size */
  set_gaia_object_only
		if GNR_SFISH_SPARSE
 temp_min_distance_group_placement  14
		else
 temp_min_distance_group_placement  6
		endif
}
	endif

elseif GNR_BIGFISHONLY

	if GNR_BIGFISH_DENSE

create_object FISH_A
{
  number_of_objects             1
number_of_groups 99999
  set_gaia_object_only
  temp_min_distance_group_placement  6


	if GNR_BIGFISH0ZONEDIST
	elseif GNR_BIGFISH2ZONEDIST
  max_distance_to_other_zones         2
	elseif GNR_BIGFISH3ZONEDIST
  max_distance_to_other_zones         3
	else
  max_distance_to_other_zones         4
	endif

}

create_object FISH_B
{
  number_of_objects             1
number_of_groups 99999
  set_gaia_object_only
  temp_min_distance_group_placement  6


	if GNR_BIGFISH0ZONEDIST
	elseif GNR_BIGFISH2ZONEDIST
  max_distance_to_other_zones         2
	elseif GNR_BIGFISH3ZONEDIST
  max_distance_to_other_zones         3
	else
  max_distance_to_other_zones         4
	endif

}

	elseif GNR_BIGFISH_SUPERDENSE

create_object FISH_A
{
  number_of_objects             1
number_of_groups 99999
  set_gaia_object_only
  temp_min_distance_group_placement  4


	if GNR_BIGFISH0ZONEDIST
	elseif GNR_BIGFISH2ZONEDIST
  max_distance_to_other_zones         2
	elseif GNR_BIGFISH3ZONEDIST
  max_distance_to_other_zones         3
	else
  max_distance_to_other_zones         4
	endif

}

create_object FISH_B
{
  number_of_objects             1
number_of_groups 99999
  set_gaia_object_only
  temp_min_distance_group_placement  4


	if GNR_BIGFISH0ZONEDIST
	elseif GNR_BIGFISH2ZONEDIST
  max_distance_to_other_zones         2
	elseif GNR_BIGFISH3ZONEDIST
  max_distance_to_other_zones         3
	else
  max_distance_to_other_zones         4
	endif

}

	else

create_object FISH_A
{
  number_of_objects                   6
  set_scaling_to_map_size
  set_gaia_object_only

	if GNR_BIGFISH0ZONEDIST
	elseif GNR_BIGFISH2ZONEDIST
  max_distance_to_other_zones         2
	elseif GNR_BIGFISH3ZONEDIST
  max_distance_to_other_zones         3
	else
  max_distance_to_other_zones         4
	endif

  min_distance_group_placement  4
}
create_object FISH_B
{
  number_of_objects                   170
  set_scaling_to_map_size
  set_gaia_object_only

	if GNR_BIGFISH0ZONEDIST
	elseif GNR_BIGFISH2ZONEDIST
  max_distance_to_other_zones         2
	elseif GNR_BIGFISH3ZONEDIST
  max_distance_to_other_zones         3
	else
  max_distance_to_other_zones         4
	endif

  min_distance_group_placement  8
}

	endif

endif

if DEATH_MATCH
else
	if GNR_EXTRAMAPBOARS

   create_object LURABLE_B
{
		if GNR_EXTRAMAP_12BOARS
start_random
percent_chance 50
   number_of_objects 1
percent_chance 50
   number_of_objects 2
end_random
		else
   number_of_objects 3
		endif
   number_of_groups 1
   set_loose_grouping
   set_gaia_object_only
   set_place_for_every_player
   min_distance_to_players    35
   max_distance_to_players    60
   temp_min_distance_group_placement  5
}

	endif

	if GNR_FARLURABLES_20PLACED

create_object LURABLE_A
{
   number_of_objects 1
  number_of_groups 999
  set_loose_grouping
  set_gaia_object_only
		if GNR_FARLUREOVER_90PLACED
  temp_min_distance_group_placement 90
		elseif GNR_FARLUREOVER_40PLACED
  temp_min_distance_group_placement 40
		else
  temp_min_distance_group_placement 20
		endif

		if GNR_FARLURE_LAYERA
terrain_to_place_on LAYER_A
		elseif GNR_FARLURE_LAYERC
terrain_to_place_on LAYER_C
		elseif GNR_FARLURE_LAYERD
terrain_to_place_on LAYER_D
		endif

  min_distance_to_players 20
}

	endif

endif

/* Additional Map Predators */

if GNR_ADDITIONALPRED
	if BATTLE_ROYALE
	elseif DEATH_MATCH
	else

create_object PREDATOR_A
{
  number_of_groups          3
  set_loose_grouping
  start_random
  percent_chance 75
	number_of_objects 1
  percent_chance 25
	number_of_objects 2
  end_random
  set_scaling_to_map_size
  set_gaia_object_only
  temp_min_distance_group_placement 12
  min_distance_to_players    40
  max_distance_to_players    120
}
	endif
endif

/* Modern Map Predators */

if GNR_MODERNMAPPRED
	if BATTLE_ROYALE
	elseif DEATH_MATCH
	else

create_object PREDATOR_A
{
		if GNR_MODERNMP_INFINITE
     number_of_groups 9999
		elseif GNR_MODERNMP_30LIMIT
     number_of_groups 30
		else
     number_of_groups 30
		endif

     set_loose_grouping

		if GNR_MODERNMP_2GROUP
        number_of_objects 2
		elseif  GNR_MODERNMP_1GROUP
        number_of_objects 1
		else
        number_of_objects 1
		endif

     set_gaia_object_only

		if GNR_MODERNMP_60TEMP
     temp_min_distance_group_placement 60
		elseif GNR_MODERNMP_30TEMP
     temp_min_distance_group_placement 30
		elseif GNR_MODERNMP_10TEMP
     temp_min_distance_group_placement 10
		elseif GNR_MODERNMP_5TEMP
     temp_min_distance_group_placement 5
		else
     temp_min_distance_group_placement 60
		endif

		if GNR_MODERNMP_40PLAVOID
     min_distance_to_players 40
		elseif GNR_MODERNMP_20PLAVOID
     min_distance_to_players 20
		elseif GNR_MODERNMP_0PLAVOID
		else
     min_distance_to_players 32
		endif

		if GNR_MODERNMP_LAYERA
terrain_to_place_on LAYER_A
		elseif GNR_MODERNMP_LAYERC
terrain_to_place_on LAYER_C
		elseif GNR_MODERNMP_LAYERD
terrain_to_place_on LAYER_D
		else
		endif

}

	endif

endif


/* Map Stragglers */

if DEATH_MATCH
elseif GNR_MAPSTRAGGLE

create_object STRAGGLER
{
	if GNR_MAP100STRAGGLE
		if EMPIRE_WARS
  number_of_objects          50
		else
  number_of_objects          80
		endif
	elseif GNR_MAP15STRAGGLE
  number_of_objects          15
	else
		if EMPIRE_WARS
  number_of_objects          15
		else
  number_of_objects          30
		endif
	endif
  set_gaia_object_only
  set_scaling_to_map_size

	if EMPIRE_WARS
  min_distance_to_players    35
	else

		if GNR_MAPSTRAGGLE25DIST
  min_distance_to_players    25
		else
  min_distance_to_players    8
		endif

	endif

	if GNR_MAP100STRAGGLE
  min_distance_group_placement  2
	else
	endif

  avoid_actor_area 12
  avoid_actor_area 14
  avoid_actor_area 149
  avoid_actor_area 61
  avoid_actor_area 62
  avoid_actor_area 63
  avoid_actor_area 65
  avoid_actor_area 66
  avoid_actor_area 67

}

elseif GNR_MAPUNIQUESTRAGGLE

create_object UNIQSTRAGGLER
{
	if GNR_MAP100STRAGGLE
		if EMPIRE_WARS
  number_of_objects          50
		else
  number_of_objects          80
		endif
	elseif GNR_MAP15STRAGGLE
  number_of_objects          15
	else
		if EMPIRE_WARS
  number_of_objects          15
		else
  number_of_objects          30
		endif
	endif

  set_gaia_object_only
  set_scaling_to_map_size

	if EMPIRE_WARS
  min_distance_to_players    35
	else

		if GNR_MAPSTRAGGLE25DIST
  min_distance_to_players    25
		else
  min_distance_to_players    8
		endif

	endif

	if GNR_MAP100STRAGGLE
  min_distance_group_placement  2
	else
	endif

  avoid_actor_area 12
  avoid_actor_area 14
  avoid_actor_area 149
  avoid_actor_area 61
  avoid_actor_area 62
  avoid_actor_area 63
  avoid_actor_area 65
  avoid_actor_area 66
  avoid_actor_area 67

}

endif

/* Other */

if GNR_MAP_ROCKBEACH

create_object DLC_ROCKBEACH
{
  number_of_objects 999
     set_scaling_to_map_size
     temp_min_distance_group_placement 50
     set_gaia_object_only
     min_distance_to_players 25
}

endif