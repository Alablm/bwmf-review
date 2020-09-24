// Author: BWMF
// Description: Russian: AK74 - Uniform camouflage coloring summer

#include "undef.hpp" // Reset defines

// Rifle
#define RIFLE "rhs_weap_ak74m_camo","rhs_weap_ak74m_2mag_camo","rhs_weap_ak74m","rhs_weap_ak74m_2mag"
#define RIFLE_MAG "30Rnd_545x39_Mag_Green_F:8","30Rnd_545x39_Mag_Tracer_Green_F:2"
#define RIFLE_ATTACHMENTS "rhs_acc_dtk","rhs_acc_perst1ik"
#define ALT_OPTICS WARSAW_OPTICS
// GL Rifle
#define GLRIFLE "rhs_weap_ak74m_gp25"
#define GLRIFLE_MAG RIFLE_MAG
#define GLRIFLE_MAG_SMOKE "1Rnd_Smoke_Grenade_shell:2","1Rnd_SmokeRed_Grenade_shell:2"
#define GLRIFLE_MAG_HE "1Rnd_HE_Grenade_shell:5"
// Carbine
#define CARBINE "rhs_weap_ak105"
#define CARBINE_MAG RIFLE_MAG
// AR
#define AR "CUP_arifle_RPK74"
#define AR_MAG "CUP_75Rnd_TE4_LRT4_Green_Tracer_545x39_RPK_M:6"
#define AR_ATTACHMENTS "CUP_optic_Kobra"
// AT
#define AT "rhs_weap_rpg26"
// MMG
#define MMG "rhs_weap_pkm"
#define MMG_MAG "rhs_100Rnd_762x54mmR_green:5"
// MAT
#define MAT "rhs_weap_rpg7"
#define MAT_MAG "rhs_rpg7_PG7VR_mag:2","rhs_rpg7_PG7VL_mag:1","rhs_rpg7_OG7V_mag:1"
#define MAT_MAG2 "rhs_rpg7_PG7VR_mag:1","rhs_rpg7_PG7VL_mag:2"
#define MAT_OPTIC "rhs_acc_pgo7v3"
// SAM
#define SAM "rhs_weap_igla"
#define SAM_MAG "rhs_mag_9k38_rocket:3"
#define SAM_MAG2 "rhs_mag_9k38_rocket:2"
// Sniper Rifle
#define SNIPER "rhs_weap_svdp_npz"
#define SNIPER_MAG "rhs_10Rnd_762x54mmR_7N1:20"
#define SNIPER_ATTACHMENTS "optic_LRPS"
// Spotter Rifle
#define SPOTTER "rhs_weap_ak74m_camo"
#define SPOTTER_MAG RIFLE_MAG
#define SPOTTER_ATTACHMENTS "rhs_acc_1p78","rhs_acc_perst1ik","rhs_acc_uuk"
// SMG
#define SMG "rhs_weap_aks74u"
#define SMG_MAG "rhs_30Rnd_545x39_AK:6"
// Pistol
#define PISTOL "rhs_weap_pya"
#define PISTOL_MAG "rhs_mag_9x19_17:3"
// Grenades
#define LEADER_GRENADES BASE_FRAG,LEADER_SMOKES,SIDE_CHEM_LIGHT
// Gear
#define TOOLS BASE_TOOLS
#define LEADER_TOOLS BASE_LEADER_TOOLS,SIDE_KEY
#define LINKED BASE_LINKED
#define LEADER_LINKED BASE_LEADER_LINKED

class Car {
  TransportWeapons[] = {AT};
  TransportMagazines[] = {RIFLE_MAG,RIFLE_MAG,CARBINE_MAG,AR_MAG,AR_MAG,GLRIFLE_MAG_HE};
  TransportItems[] = {BASE_MEDICAL,BASE_MEDICAL,BASE_MEDICAL,BASE_MEDICAL};
};
class Tank {
  TransportWeapons[] = {AT};
  TransportMagazines[] = {RIFLE_MAG,RIFLE_MAG,CARBINE_MAG,AR_MAG,AR_MAG,GLRIFLE_MAG_HE};
  TransportItems[] = {BASE_MEDICAL,BASE_MEDICAL,BASE_MEDICAL,BASE_MEDICAL};
};
class Helicopter {
  TransportMagazines[] = {RIFLE_MAG,RIFLE_MAG,CARBINE_MAG,AR_MAG,AR_MAG,GLRIFLE_MAG_HE};
  TransportItems[] = {BASE_MEDICAL,BASE_MEDICAL,BASE_MEDICAL,BASE_MEDICAL};
};
class Plane {};
class Ship_F {};

class rifleman { // rifleman
  uniform[] = {"rhs_uniform_emr_patchless"};
  vest[] = {"rhs_6b23_digi_6sh92"};
  headgear[] = {"rhs_6b47","rhs_6b47_bala"};
  backpack[] = {"rhs_assault_umbts"};
  backpackItems[] = {BASE_MEDICAL};
  weapons[] = {RIFLE};
  magazines[] = {RIFLE_MAG,BASE_GRENADES};
  items[] = {TOOLS};
  linkedItems[] = {LINKED};
  attachments[] = {RIFLE_ATTACHMENTS};
  opticChoices[] = {ALT_OPTICS};
};
class Fic_Soldier_Carbine: rifleman {// carbine-man
  weapons[] = {CARBINE};
  magazines[] = {CARBINE_MAG,BASE_GRENADES};
};
class ftl: rifleman {// FTL
  vest[] = {"rhs_6b23_digi_6sh92_vog_headset"};
  weapons[] = {GLRIFLE};
  magazines[] = {GLRIFLE_MAG,GLRIFLE_MAG_HE,GLRIFLE_MAG_SMOKE,LEADER_GRENADES};
  items[] += {LEADER_TOOLS};
  linkedItems[] += {LEADER_LINKED,BINOS};
};
class sl: ftl { // SL
  backpack[] = {"B_Kitbag_sgg"};
  handguns[] = {PISTOL};
  magazines[] += {PISTOL_MAG};
  linkedItems[] = {LINKED,LEADER_LINKED,RANGE_FINDER};
  items[] += {RADIO_MR};
};
class coy: sl { // CO and DC
  items[] += {RADIO_LR};
};
class uav: rifleman {
  backpack[] = {SIDE_UAV_BACKPACK};
  linkedItems[] += {SIDE_UAV_TERMINAL};
};
class soldier_GL_F: ftl {}; // GP Dude
class ar: rifleman {// AR
  weapons[] = {AR};
  magazines[] = {AR_MAG,PISTOL_MAG,BASE_GRENADES};
  handguns[] = {PISTOL};
  attachments[] = {AR_ATTACHMENTS};
  opticChoices[] = {};
};
class aar: rifleman {// AAR
  backpack[] = {"B_Carryall_oli"};
  backpackItems[] += {AR_MAG};
  linkedItems[] += {BINOS};
};
class lat: Fic_Soldier_Carbine {// RAT
  launchers[] = {AT};
};
class cm: Fic_Soldier_Carbine {// Medic
  magazines[] = {CARBINE_MAG,MEDIC_GRENADES};
  backpackItems[] = {MEDIC_MEDICAL};
};
class Fic_Spotter: rifleman {
  linkedItems[] += {RANGE_FINDER};
};
class mmgg: ar {// MMG
  backpack[] = {"B_Kitbag_rgr"};
  weapons[] = {MMG};
  magazines[] = {MMG_MAG,PISTOL_MAG,BASE_GRENADES};
  attachments[] = {};
};
class mmgag: Fic_Spotter {// MMG Spotter/Ammo Bearer
  backpack[] = {"B_Carryall_oli"};
  backpackItems[] += {MMG_MAG};
};
class matg: Fic_Soldier_Carbine {// MAT Gunner
  backpack[] = {"B_Carryall_oli"};
  backpackItems[] = {};
  magazines[] += {MAT_MAG};
  items[] += {BASE_MEDICAL};
  launchers[] = {MAT};
  secondaryAttachments[] = {MAT_OPTIC};
};
class matag: Fic_Spotter {// MAT Spotter/Ammo Bearer
  backpack[] = {"B_Carryall_oli"};
  backpackItems[] = {};
  magazines[] += {MAT_MAG2};
  items[] += {BASE_MEDICAL};
};
class msamg: Fic_soldier_Carbine {// SAM Gunner
  SAM_GEAR("B_Carryall_oli", SAM_MAG)
  launchers[] = {SAM};
};
class msamag: Fic_Spotter {// SAM Spotter/Ammo Bearer
  SAM_GEAR("B_Carryall_oli", SAM_MAG)
};
class mtrg: Fic_Soldier_Carbine {// Mortar Gunner
  MORTAR_GEAR("O_Mortar_01_weapon_F")
};
class mtrag: Fic_Spotter {// Assistant Mortar
  MORTAR_GEAR("O_Mortar_01_support_F")
};
class spotter: Fic_Spotter {// Spotter
  weapons[] = {SPOTTER};
  magazines[] = {SPOTTER_MAG,BASE_GRENADES};
  items[] += {RADIO_MR,"ACE_ATragMX","ACE_Kestrel4500"};
  linkedItems[] += {LEADER_LINKED};
  attachments[] = {SPOTTER_ATTACHMENTS};
};
class sniper: spotter {// Sniper
  weapons[] = {SNIPER};
  magazines[] = {SNIPER_MAG,BASE_GRENADES};
  items[] = {TOOLS,"ACE_RangeCard"};
  linkedItems[] = {LINKED};
  attachments[] = {SNIPER_ATTACHMENTS};
};
class pilot {// Pilot
  uniform[] = {"rhs_uniform_df15"};
  vest[] = {"V_TacVest_blk"};
  headgear[] = {"rhs_zsh7a_mike"};
  backpack[] = {"B_AssaultPack_rgr"};
  weapons[] = {SMG};
  magazines[] = {SMG_MAG,CREW_GRENADES};
  backpackItems[] = {RADIO_LR};
  items[] = {BASE_MEDICAL,TOOLS,LEADER_TOOLS,RADIO_MR};
  linkedItems[] = {LINKED,LEADER_LINKED};
  attachments[] = {"rhs_acc_dtk"};
};
class vicc: Fic_Soldier_Carbine {// Crew
  headgear[] = {"rhs_tsh4","rhs_tsh4_bala"};
  backpack[] = {"rhs_assault_umbts_engineer_empty"};
  magazines[] = {CARBINE_MAG,CREW_GRENADES};
  backpackItems[] += {SIDE_KEY,RADIO_LR};
  linkedItems[] += {LEADER_LINKED,BINOS};
  items[] += {BASE_MEDICAL};
};
class vicd: vicc {// Repair Specialist
  backpackItems[] = {"Toolkit",RADIO_MR,SIDE_KEY};
  linkedItems[] = {LINKED,LEADER_LINKED};
};
class Fic_eng: vicd {
  headgear[] = {"rhs_6b47","rhs_6b47_bala"};
  backpack[] = {"B_Carryall_oli"};
  items[] += {BASE_ENG};
  backpackItems[] = {};
};
class demo: Fic_eng {// Explosive Specialist
  magazines[] += {BASE_EXP};
};
class mine: Fic_eng {// Mine Specialist
  magazines[] += {BASE_MINE};
};
class engl: Fic_eng {
  magazines[] += {BASE_EXP};
  backpackItems[] = {RADIO_MR,"Toolkit"};
};
class fac: coy {// FAC
  items[] += {RADIO_LR};
  magazines[] = {GLRIFLE_MAG,SIDE_FAC_GRENADES,"Laserbatteries"};
  linkedItems[] = {LINKED,LEADER_LINKED,"CUP_LRTV"};
};
class rifleman_02: rifleman {// Rifleman 2
};
class artl: sl {// Artillery Leader
  backpackItems[] += {BASE_ARTILLERY,RADIO_LR};
};
class artg: rifleman {// Artillery Gunner
  backpackItems[] += {BASE_ARTILLERY};
};
class plm: sm {// Platoon Medic
};
class cm: sm {// Company Medic
};
class xo: coy {// XO
};
class plt: coy {// Platoon Leader
};
class sgt: plt {// Platoon Sergeant
};
class vicl: vicc {// Vehicle Commander
};
class mmgl: sl {// MMG Lead
};
class matl: sl {// MAT Lead
};
class hmgl: sl {// HMG Lead
};
class hmgg: rifleman {// HMG Gunner
};
class hmgag: rifleman {// HMG Spotter
};
class hatl: sl {// HAT Lead
};
class hatg: rifleman {// HAT Gunner
};
class hatag: rifleman {// HAT Spotter
};
class msaml: sl {// MSAM Lead
};
class mtrl: sl {// Mortar Lead
};
class helicrew: pilot {// Aircrew
  backpack[] = {"B_Carryall_oli"};
  backpackItems[] = {"Toolkit",SIDE_KEY};
  linkedItems[] = {LINKED,LEADER_LINKED};
};
class cc: helicrew {// Crew Chief
  backpackItems[] += {RADIO_MR};
};
class fallback: rifleman {}; // This means any faction member who doesn't match something will use this loadout
