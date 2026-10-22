class CfgPatches
{
	class OMD_Armor
	{
		units[] =
		{
			"OMD_Plate_RU_Br4_Steel",
			"OMD_Plate_RU_Br4_Ceramic",
			"OMD_Plate_RU_Br5_Ceramic",
			"OMD_Plate_RU_Br5_Composite",
			"OMD_Plate_RU_Br6_Steel",
			"OMD_Plate_US_L3_Steel",
			"OMD_Plate_US_L3P_Ceramic",
			"OMD_Plate_US_L4_Ceramic",
			"OMD_Plate_US_ESAPI",
			"OMD_Plate_US_XSAPI"
		};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Characters_Vests",
			"DZ_Scripts",
			"DZ_Weapons_Projectiles",
			"DZ_Sounds_Effects",
			"OMD_Bridge",
			"OMD_NewDamage",
			"TerjeMedicine"
		};
	};
};

class CfgMods
{
	class OMD_Armor
	{
		dir = "OMD_Armor";
		picture = "";
		action = "";
		hideName = 0;
		hidePicture = 0;
		name = "OMD Armor";
		credits = "OMD";
		author = "OMD";
		authorID = "0";
		version = "0.1.0";
		type = "mod";
		dependencies[] = { "World" };
		class defs
		{
			class imageSets
			{
				files[] = {"OMD_Armor\data\imagesets\omd_slots.imageset"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "OMD_Armor/Scripts/4_World" };
			};
		};
	};
};

class CfgSlots
{
	class Slot_OMD_PlateFront
	{
		name = "OMD_PlateFront";
		displayName = "Плита спереди";
		ghostIcon = "set:omd_slots image:plate_plain";
	};
	class Slot_OMD_PlateBack
	{
		name = "OMD_PlateBack";
		displayName = "Плита сзади";
		ghostIcon = "set:omd_slots image:plate_plain";
	};
	class Slot_OMD_PlateFront_RU
	{
		name = "OMD_PlateFront_RU";
		displayName = "Плита спереди RU";
		ghostIcon = "set:omd_slots image:plate_ru";
	};
	class Slot_OMD_PlateBack_RU
	{
		name = "OMD_PlateBack_RU";
		displayName = "Плита сзади RU";
		ghostIcon = "set:omd_slots image:plate_ru";
	};
	class Slot_OMD_PlateFront_US
	{
		name = "OMD_PlateFront_US";
		displayName = "Плита спереди US";
		ghostIcon = "set:omd_slots image:plate_us";
	};
	class Slot_OMD_PlateBack_US
	{
		name = "OMD_PlateBack_US";
		displayName = "Плита сзади US";
		ghostIcon = "set:omd_slots image:plate_us";
	};
};

class CfgVehicles
{
	class Inventory_Base;
	class OMD_ArmorPlate_Base: Inventory_Base
	{
		scope = 0;
		displayName = "Бронеплита";
		descriptionShort = "Вставляется в плитоноску спереди или сзади.";
		model = "OMD_Armor\data\plates\armorplate.p3d";
		hiddenSelections[] = {"zbytek"};
		itemSize[] = {3, 3};
		weight = 3700;
		rotationFlags = 1;
		absorbency = 0;
		soundImpactType = "metal";
		inventorySlot[] = {"OMD_PlateFront", "OMD_PlateBack"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 400;
					healthLevels[] =
					{
						{1.0, {"OMD_Armor\data\plates\armorplate.rvmat"}},
						{0.7, {"OMD_Armor\data\plates\armorplate.rvmat"}},
						{0.5, {"OMD_Armor\data\plates\armorplate_damage.rvmat"}},
						{0.3, {"OMD_Armor\data\plates\armorplate_damage.rvmat"}},
						{0.0, {"OMD_Armor\data\plates\armorplate_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class OMD_Plate_RU_Br4_Steel: OMD_ArmorPlate_Base
	{
		scope = 2;
		displayName = "Стальная плита Бр4, Россия";
		descriptionShort = "Россия, сталь, класс 4. Слот RU или общий слот плитоноски.";
		hiddenSelectionsTextures[] = {"OMD_Armor\data\plates\armorplate_4_co.paa"};
		weight = 3500;
		inventorySlot[] = {"OMD_PlateFront_RU", "OMD_PlateBack_RU", "OMD_PlateFront", "OMD_PlateBack"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 400;
					healthLevels[] =
					{
						{1.0, {"OMD_Armor\data\plates\armorplate.rvmat"}},
						{0.7, {"OMD_Armor\data\plates\armorplate.rvmat"}},
						{0.5, {"OMD_Armor\data\plates\armorplate_damage.rvmat"}},
						{0.3, {"OMD_Armor\data\plates\armorplate_damage.rvmat"}},
						{0.0, {"OMD_Armor\data\plates\armorplate_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class OMD_Plate_RU_Br4_Ceramic: OMD_ArmorPlate_Base
	{
		scope = 2;
		displayName = "Керамическая плита Бр4, Россия";
		descriptionShort = "Россия, керамика, класс 4. Слот RU или общий слот плитоноски.";
		hiddenSelectionsTextures[] = {"OMD_Armor\data\plates\armorplate_4_co.paa"};
		weight = 2400;
		soundImpactType = "glass";
		inventorySlot[] = {"OMD_PlateFront_RU", "OMD_PlateBack_RU", "OMD_PlateFront", "OMD_PlateBack"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 220;
					healthLevels[] =
					{
						{1.0, {"OMD_Armor\data\plates\armorplate.rvmat"}},
						{0.7, {"OMD_Armor\data\plates\armorplate.rvmat"}},
						{0.5, {"OMD_Armor\data\plates\armorplate_damage.rvmat"}},
						{0.3, {"OMD_Armor\data\plates\armorplate_damage.rvmat"}},
						{0.0, {"OMD_Armor\data\plates\armorplate_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class OMD_Plate_RU_Br5_Ceramic: OMD_ArmorPlate_Base
	{
		scope = 2;
		displayName = "Керамическая плита Бр5, Россия";
		descriptionShort = "Россия, керамика, класс 5. Слот RU или общий слот плитоноски.";
		hiddenSelectionsTextures[] = {"OMD_Armor\data\plates\armorplate_5_co.paa"};
		weight = 3000;
		soundImpactType = "glass";
		inventorySlot[] = {"OMD_PlateFront_RU", "OMD_PlateBack_RU", "OMD_PlateFront", "OMD_PlateBack"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 260;
					healthLevels[] =
					{
						{1.0, {"OMD_Armor\data\plates\armorplate.rvmat"}},
						{0.7, {"OMD_Armor\data\plates\armorplate.rvmat"}},
						{0.5, {"OMD_Armor\data\plates\armorplate_damage.rvmat"}},
						{0.3, {"OMD_Armor\data\plates\armorplate_damage.rvmat"}},
						{0.0, {"OMD_Armor\data\plates\armorplate_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class OMD_Plate_RU_Br5_Composite: OMD_ArmorPlate_Base
	{
		scope = 2;
		displayName = "Композитная плита Бр5, Россия";
		descriptionShort = "Россия, композит, класс 5. Слот RU или общий слот плитоноски.";
		hiddenSelectionsTextures[] = {"OMD_Armor\data\plates\armorplate_5_co.paa"};
		weight = 2600;
		inventorySlot[] = {"OMD_PlateFront_RU", "OMD_PlateBack_RU", "OMD_PlateFront", "OMD_PlateBack"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 320;
					healthLevels[] =
					{
						{1.0, {"OMD_Armor\data\plates\armorplate.rvmat"}},
						{0.7, {"OMD_Armor\data\plates\armorplate.rvmat"}},
						{0.5, {"OMD_Armor\data\plates\armorplate_damage.rvmat"}},
						{0.3, {"OMD_Armor\data\plates\armorplate_damage.rvmat"}},
						{0.0, {"OMD_Armor\data\plates\armorplate_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class OMD_Plate_RU_Br6_Steel: OMD_ArmorPlate_Base
	{
		scope = 2;
		displayName = "Стальная плита Бр6, Россия";
		descriptionShort = "Россия, сталь, класс 6. Слот RU или общий слот плитоноски.";
		hiddenSelectionsTextures[] = {"OMD_Armor\data\plates\armorplate_6_co.paa"};
		weight = 6000;
		inventorySlot[] = {"OMD_PlateFront_RU", "OMD_PlateBack_RU", "OMD_PlateFront", "OMD_PlateBack"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
					healthLevels[] =
					{
						{1.0, {"OMD_Armor\data\plates\armorplate.rvmat"}},
						{0.7, {"OMD_Armor\data\plates\armorplate.rvmat"}},
						{0.5, {"OMD_Armor\data\plates\armorplate_damage.rvmat"}},
						{0.3, {"OMD_Armor\data\plates\armorplate_damage.rvmat"}},
						{0.0, {"OMD_Armor\data\plates\armorplate_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class OMD_Plate_US_L3_Steel: OMD_ArmorPlate_Base
	{
		scope = 2;
		displayName = "Стальная плита Level III, США";
		descriptionShort = "США, сталь, класс 4. Слот US или общий слот плитоноски.";
		hiddenSelectionsTextures[] = {"OMD_Armor\data\plates\armorplate_4_co.paa"};
		weight = 3800;
		inventorySlot[] = {"OMD_PlateFront_US", "OMD_PlateBack_US", "OMD_PlateFront", "OMD_PlateBack"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 330;
					healthLevels[] =
					{
						{1.0, {"OMD_Armor\data\plates\armorplate.rvmat"}},
						{0.7, {"OMD_Armor\data\plates\armorplate.rvmat"}},
						{0.5, {"OMD_Armor\data\plates\armorplate_damage.rvmat"}},
						{0.3, {"OMD_Armor\data\plates\armorplate_damage.rvmat"}},
						{0.0, {"OMD_Armor\data\plates\armorplate_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class OMD_Plate_US_L3P_Ceramic: OMD_ArmorPlate_Base
	{
		scope = 2;
		displayName = "Керамическая плита Level III+, США";
		descriptionShort = "США, керамика, класс 4. Слот US или общий слот плитоноски.";
		hiddenSelectionsTextures[] = {"OMD_Armor\data\plates\armorplate_4_co.paa"};
		weight = 2300;
		soundImpactType = "glass";
		inventorySlot[] = {"OMD_PlateFront_US", "OMD_PlateBack_US", "OMD_PlateFront", "OMD_PlateBack"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 240;
					healthLevels[] =
					{
						{1.0, {"OMD_Armor\data\plates\armorplate.rvmat"}},
						{0.7, {"OMD_Armor\data\plates\armorplate.rvmat"}},
						{0.5, {"OMD_Armor\data\plates\armorplate_damage.rvmat"}},
						{0.3, {"OMD_Armor\data\plates\armorplate_damage.rvmat"}},
						{0.0, {"OMD_Armor\data\plates\armorplate_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class OMD_Plate_US_L4_Ceramic: OMD_ArmorPlate_Base
	{
		scope = 2;
		displayName = "Керамическая плита Level IV, США";
		descriptionShort = "США, керамика, класс 5. Слот US или общий слот плитоноски.";
		hiddenSelectionsTextures[] = {"OMD_Armor\data\plates\armorplate_5_co.paa"};
		weight = 3000;
		soundImpactType = "glass";
		inventorySlot[] = {"OMD_PlateFront_US", "OMD_PlateBack_US", "OMD_PlateFront", "OMD_PlateBack"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 280;
					healthLevels[] =
					{
						{1.0, {"OMD_Armor\data\plates\armorplate.rvmat"}},
						{0.7, {"OMD_Armor\data\plates\armorplate.rvmat"}},
						{0.5, {"OMD_Armor\data\plates\armorplate_damage.rvmat"}},
						{0.3, {"OMD_Armor\data\plates\armorplate_damage.rvmat"}},
						{0.0, {"OMD_Armor\data\plates\armorplate_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class OMD_Plate_US_ESAPI: OMD_ArmorPlate_Base
	{
		scope = 2;
		displayName = "Плита ESAPI, США";
		descriptionShort = "США, композит, класс 5. Слот US или общий слот плитоноски.";
		hiddenSelectionsTextures[] = {"OMD_Armor\data\plates\armorplate_5_co.paa"};
		weight = 2700;
		inventorySlot[] = {"OMD_PlateFront_US", "OMD_PlateBack_US", "OMD_PlateFront", "OMD_PlateBack"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 360;
					healthLevels[] =
					{
						{1.0, {"OMD_Armor\data\plates\armorplate.rvmat"}},
						{0.7, {"OMD_Armor\data\plates\armorplate.rvmat"}},
						{0.5, {"OMD_Armor\data\plates\armorplate_damage.rvmat"}},
						{0.3, {"OMD_Armor\data\plates\armorplate_damage.rvmat"}},
						{0.0, {"OMD_Armor\data\plates\armorplate_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class OMD_Plate_US_XSAPI: OMD_ArmorPlate_Base
	{
		scope = 2;
		displayName = "Плита XSAPI, США";
		descriptionShort = "США, композит, класс 6. Слот US или общий слот плитоноски.";
		hiddenSelectionsTextures[] = {"OMD_Armor\data\plates\armorplate_6_co.paa"};
		weight = 3200;
		inventorySlot[] = {"OMD_PlateFront_US", "OMD_PlateBack_US", "OMD_PlateFront", "OMD_PlateBack"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 380;
					healthLevels[] =
					{
						{1.0, {"OMD_Armor\data\plates\armorplate.rvmat"}},
						{0.7, {"OMD_Armor\data\plates\armorplate.rvmat"}},
						{0.5, {"OMD_Armor\data\plates\armorplate_damage.rvmat"}},
						{0.3, {"OMD_Armor\data\plates\armorplate_damage.rvmat"}},
						{0.0, {"OMD_Armor\data\plates\armorplate_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class Clothing;
	class PlateCarrierVest: Clothing
	{
		attachments[] += {"OMD_PlateFront", "OMD_PlateBack"};
		class DamageSystem
		{
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 1.0;
					};
					class Blood
					{
						damage = 1.0;
					};
					class Shock
					{
						damage = 1.0;
					};
				};
			};
		};
	};
	class PressVest_ColorBase: Clothing
	{
		class DamageSystem
		{
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 1.0;
					};
					class Blood
					{
						damage = 1.0;
					};
					class Shock
					{
						damage = 1.0;
					};
				};
			};
		};
	};
	class PoliceVest: Clothing
	{
		class DamageSystem
		{
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 1.0;
					};
					class Blood
					{
						damage = 1.0;
					};
					class Shock
					{
						damage = 1.0;
					};
				};
			};
		};
	};
};

class CfgAmmo
{
	class Bullet_Base;
	class OMD_Ammo_Blunt: Bullet_Base
	{
		class DamageApplied
		{
			type = "Projectile";
			class Health
			{
				damage = 0;
			};
			class Blood
			{
				damage = 0;
			};
			class Shock
			{
				damage = 100;
			};
		};
	};
};

class CfgSoundShaders
{
	class OMD_Armor_PlateHit_SoundShader
	{
		samples[] =
		{
			{ "dz\sounds\weapons\hits\bullet\metal_plate_1", 1 },
			{ "dz\sounds\weapons\hits\bullet\metal_plate_2", 1 },
			{ "dz\sounds\weapons\hits\bullet\metal_plate_3", 1 },
			{ "dz\sounds\weapons\hits\bullet\metal_plate_4", 1 },
			{ "dz\sounds\weapons\hits\bullet\metal_plate_5", 1 },
			{ "dz\sounds\weapons\hits\bullet\metal_plate_6", 1 },
			{ "dz\sounds\weapons\hits\bullet\metal_plate_7", 1 },
			{ "dz\sounds\weapons\hits\bullet\metal_plate_8", 1 }
		};
		volume = 0.60000002;
		range = 80;
	};
};

class CfgSoundSets
{
	class OMD_Armor_PlateHit_SoundSet
	{
		soundShaders[] =
		{
			"OMD_Armor_PlateHit_SoundShader"
		};
		volumeFactor = 1;
		volumeCurve = "InverseSquare1Curve";
		spatial = 1;
		doppler = 0;
		loop = 0;
	};
};
