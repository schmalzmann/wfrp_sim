#include "critical_provider.hpp"
#include "entity.hpp"

CriticalProvider::CriticalProvider(){
   Initialize();
}

CriticalProvider::~CriticalProvider(){

}

std::function<void(Entity*)>* CriticalProvider::GetCritical(criticals::critical_id id){
    return &m_critical_map[id];
}

std::function<void(Entity*)>* CriticalProvider::GetCritical(int area, int severity){

    if(!(area >=0 && area <= 99)){
        throw("Faulty crit area! Must be in [0,99]!");
    }

    //overflow 0 to 100
    if(area == 0) area = 100;
    if(severity == 0) severity = 100;

    /*
    * Maybe there is a better way to do this but let's just use if blocks.
    */
    if(area <= 9){
        //head
        if(severity <= 10)  return &m_critical_map[criticals::critical_id::head_dramatic_injury];
        if(severity <= 20)  return &m_critical_map[criticals::critical_id::head_minor_cut];
        if(severity <= 25)  return &m_critical_map[criticals::critical_id::head_poked_eye];
        if(severity <= 30)  return &m_critical_map[criticals::critical_id::head_ear_bash];
        if(severity <= 35)  return &m_critical_map[criticals::critical_id::head_rattling_blow];
        if(severity <= 40)  return &m_critical_map[criticals::critical_id::head_black_eye];
        if(severity <= 45)  return &m_critical_map[criticals::critical_id::head_sliced_ear];
        if(severity <= 50)  return &m_critical_map[criticals::critical_id::head_struck_forehead];
        if(severity <= 55)  return &m_critical_map[criticals::critical_id::head_fractured_jaw];
        if(severity <= 60)  return &m_critical_map[criticals::critical_id::head_major_eye_wound];
        if(severity <= 65)  return &m_critical_map[criticals::critical_id::head_major_ear_wound];
        if(severity <= 70)  return &m_critical_map[criticals::critical_id::head_broken_nose];
        if(severity <= 75)  return &m_critical_map[criticals::critical_id::head_broken_jaw];
        if(severity <= 80)  return &m_critical_map[criticals::critical_id::head_concussive_blow];
        if(severity <= 85)  return &m_critical_map[criticals::critical_id::head_smashed_mouth];
        if(severity <= 90)  return &m_critical_map[criticals::critical_id::head_mangled_ear];
        if(severity <= 93)  return &m_critical_map[criticals::critical_id::head_devastated_eye];
        if(severity <= 96)  return &m_critical_map[criticals::critical_id::head_disfiguring_blow];
        if(severity <= 99)  return &m_critical_map[criticals::critical_id::head_mangled_jaw];
        if(severity <= 100) return &m_critical_map[criticals::critical_id::head_decapitated];
    } else if(area <= 24){
        //secondary arm
        if(severity <= 10)  return &m_critical_map[criticals::critical_id::arm_sec_jarred_arm];
        if(severity <= 20)  return &m_critical_map[criticals::critical_id::arm_sec_minor_cut];
        if(severity <= 25)  return &m_critical_map[criticals::critical_id::arm_sec_sprain];
        if(severity <= 30)  return &m_critical_map[criticals::critical_id::arm_sec_badly_jarred_arm];
        if(severity <= 35)  return &m_critical_map[criticals::critical_id::arm_sec_torn_muscles];
        if(severity <= 40)  return &m_critical_map[criticals::critical_id::arm_sec_bleeding_hand];
        if(severity <= 45)  return &m_critical_map[criticals::critical_id::arm_sec_wrenched_arm];
        if(severity <= 50)  return &m_critical_map[criticals::critical_id::arm_sec_gaping_wound];
        if(severity <= 55)  return &m_critical_map[criticals::critical_id::arm_sec_clean_break];
        if(severity <= 60)  return &m_critical_map[criticals::critical_id::arm_sec_ruptured_ligament];
        if(severity <= 65)  return &m_critical_map[criticals::critical_id::arm_sec_deep_cut];
        if(severity <= 70)  return &m_critical_map[criticals::critical_id::arm_sec_damaged_artery];
        if(severity <= 75)  return &m_critical_map[criticals::critical_id::arm_sec_crushed_elbow];
        if(severity <= 80)  return &m_critical_map[criticals::critical_id::arm_sec_dislocated_shoulder];
        if(severity <= 85)  return &m_critical_map[criticals::critical_id::arm_sec_severed_finger];
        if(severity <= 90)  return &m_critical_map[criticals::critical_id::arm_sec_cleft_hand];
        if(severity <= 93)  return &m_critical_map[criticals::critical_id::arm_sec_mauled_bicep];
        if(severity <= 96)  return &m_critical_map[criticals::critical_id::arm_sec_mangled_hand];
        if(severity <= 99)  return &m_critical_map[criticals::critical_id::arm_sec_sliced_tendons];
        if(severity <= 100) return &m_critical_map[criticals::critical_id::arm_sec_brutal_dismemberment];
    } else if(area <= 44){
        //main arm
        if(severity <= 10)  return &m_critical_map[criticals::critical_id::arm_main_jarred_arm];
        if(severity <= 20)  return &m_critical_map[criticals::critical_id::arm_main_minor_cut];
        if(severity <= 25)  return &m_critical_map[criticals::critical_id::arm_main_sprain];
        if(severity <= 30)  return &m_critical_map[criticals::critical_id::arm_main_badly_jarred_arm];
        if(severity <= 35)  return &m_critical_map[criticals::critical_id::arm_main_torn_muscles];
        if(severity <= 40)  return &m_critical_map[criticals::critical_id::arm_main_bleeding_hand];
        if(severity <= 45)  return &m_critical_map[criticals::critical_id::arm_main_wrenched_arm];
        if(severity <= 50)  return &m_critical_map[criticals::critical_id::arm_main_gaping_wound];
        if(severity <= 55)  return &m_critical_map[criticals::critical_id::arm_main_clean_break];
        if(severity <= 60)  return &m_critical_map[criticals::critical_id::arm_main_ruptured_ligament];
        if(severity <= 65)  return &m_critical_map[criticals::critical_id::arm_main_deep_cut];
        if(severity <= 70)  return &m_critical_map[criticals::critical_id::arm_main_damaged_artery];
        if(severity <= 75)  return &m_critical_map[criticals::critical_id::arm_main_crushed_elbow];
        if(severity <= 80)  return &m_critical_map[criticals::critical_id::arm_main_dislocated_shoulder];
        if(severity <= 85)  return &m_critical_map[criticals::critical_id::arm_main_severed_finger];
        if(severity <= 90)  return &m_critical_map[criticals::critical_id::arm_main_cleft_hand];
        if(severity <= 93)  return &m_critical_map[criticals::critical_id::arm_main_mauled_bicep];
        if(severity <= 96)  return &m_critical_map[criticals::critical_id::arm_main_mangled_hand];
        if(severity <= 99)  return &m_critical_map[criticals::critical_id::arm_main_sliced_tendons];
        if(severity <= 100) return &m_critical_map[criticals::critical_id::arm_main_brutal_dismemberment];
    } else if(area <= 79){
        //body
        if(severity <= 10)  return &m_critical_map[criticals::critical_id::body_tis_but_a_scratch];
        if(severity <= 20)  return &m_critical_map[criticals::critical_id::body_gut_blow];
        if(severity <= 25)  return &m_critical_map[criticals::critical_id::body_low_blow];
        if(severity <= 30)  return &m_critical_map[criticals::critical_id::body_twisted_back];
        if(severity <= 35)  return &m_critical_map[criticals::critical_id::body_winded];
        if(severity <= 40)  return &m_critical_map[criticals::critical_id::body_bruised_ribs];
        if(severity <= 45)  return &m_critical_map[criticals::critical_id::body_wrenched_collar_bone];
        if(severity <= 50)  return &m_critical_map[criticals::critical_id::body_ragged_wound];
        if(severity <= 55)  return &m_critical_map[criticals::critical_id::body_cracked_ribs];
        if(severity <= 60)  return &m_critical_map[criticals::critical_id::body_gaping_wound];
        if(severity <= 65)  return &m_critical_map[criticals::critical_id::body_painful_cut];
        if(severity <= 70)  return &m_critical_map[criticals::critical_id::body_arterial_damage];
        if(severity <= 75)  return &m_critical_map[criticals::critical_id::body_pulled_back];
        if(severity <= 80)  return &m_critical_map[criticals::critical_id::body_fractured_hip];
        if(severity <= 85)  return &m_critical_map[criticals::critical_id::body_major_chest_wound];
        if(severity <= 90)  return &m_critical_map[criticals::critical_id::body_gut_wound];
        if(severity <= 93)  return &m_critical_map[criticals::critical_id::body_smashed_rib_cage];
        if(severity <= 96)  return &m_critical_map[criticals::critical_id::body_broken_collar_bone];
        if(severity <= 99)  return &m_critical_map[criticals::critical_id::body_internal_bleeding];
        if(severity <= 100) return &m_critical_map[criticals::critical_id::body_torn_apart];
    } else if(area <= 89){
        //left leg
        if(severity <= 10)  return &m_critical_map[criticals::critical_id::leg_left_stubbed_toe];
        if(severity <= 20)  return &m_critical_map[criticals::critical_id::leg_left_twisted_ankle];
        if(severity <= 25)  return &m_critical_map[criticals::critical_id::leg_left_minor_cut];
        if(severity <= 30)  return &m_critical_map[criticals::critical_id::leg_left_lost_footing];
        if(severity <= 35)  return &m_critical_map[criticals::critical_id::leg_left_thigh_strike];
        if(severity <= 40)  return &m_critical_map[criticals::critical_id::leg_left_sprained_ankle];
        if(severity <= 45)  return &m_critical_map[criticals::critical_id::leg_left_twisted_knee];
        if(severity <= 50)  return &m_critical_map[criticals::critical_id::leg_left_badly_cut_toe];
        if(severity <= 55)  return &m_critical_map[criticals::critical_id::leg_left_bad_cut];
        if(severity <= 60)  return &m_critical_map[criticals::critical_id::leg_left_badly_twisted_knee];
        if(severity <= 65)  return &m_critical_map[criticals::critical_id::leg_left_hacked_leg];
        if(severity <= 70)  return &m_critical_map[criticals::critical_id::leg_left_torn_thigh];
        if(severity <= 75)  return &m_critical_map[criticals::critical_id::leg_left_ruptured_tendon];
        if(severity <= 80)  return &m_critical_map[criticals::critical_id::leg_left_carved_shin];
        if(severity <= 85)  return &m_critical_map[criticals::critical_id::leg_left_broken_knee];
        if(severity <= 90)  return &m_critical_map[criticals::critical_id::leg_left_dislocated_knee];
        if(severity <= 93)  return &m_critical_map[criticals::critical_id::leg_left_crushed_foot];
        if(severity <= 96)  return &m_critical_map[criticals::critical_id::leg_left_severed_foot];
        if(severity <= 99)  return &m_critical_map[criticals::critical_id::leg_left_cut_tendon];
        if(severity <= 100) return &m_critical_map[criticals::critical_id::leg_left_shattered_pelvis];
    } else if(area <= 100){
        //right leg
        if(severity <= 10)  return &m_critical_map[criticals::critical_id::leg_right_stubbed_toe];
        if(severity <= 20)  return &m_critical_map[criticals::critical_id::leg_right_twisted_ankle];
        if(severity <= 25)  return &m_critical_map[criticals::critical_id::leg_right_minor_cut];
        if(severity <= 30)  return &m_critical_map[criticals::critical_id::leg_right_lost_footing];
        if(severity <= 35)  return &m_critical_map[criticals::critical_id::leg_right_thigh_strike];
        if(severity <= 40)  return &m_critical_map[criticals::critical_id::leg_right_sprained_ankle];
        if(severity <= 45)  return &m_critical_map[criticals::critical_id::leg_right_twisted_knee];
        if(severity <= 50)  return &m_critical_map[criticals::critical_id::leg_right_badly_cut_toe];
        if(severity <= 55)  return &m_critical_map[criticals::critical_id::leg_right_bad_cut];
        if(severity <= 60)  return &m_critical_map[criticals::critical_id::leg_right_badly_twisted_knee];
        if(severity <= 65)  return &m_critical_map[criticals::critical_id::leg_right_hacked_leg];
        if(severity <= 70)  return &m_critical_map[criticals::critical_id::leg_right_torn_thigh];
        if(severity <= 75)  return &m_critical_map[criticals::critical_id::leg_right_ruptured_tendon];
        if(severity <= 80)  return &m_critical_map[criticals::critical_id::leg_right_carved_shin];
        if(severity <= 85)  return &m_critical_map[criticals::critical_id::leg_right_broken_knee];
        if(severity <= 90)  return &m_critical_map[criticals::critical_id::leg_right_dislocated_knee];
        if(severity <= 93)  return &m_critical_map[criticals::critical_id::leg_right_crushed_foot];
        if(severity <= 96)  return &m_critical_map[criticals::critical_id::leg_right_severed_foot];
        if(severity <= 99)  return &m_critical_map[criticals::critical_id::leg_right_cut_tendon];
        if(severity <= 100) return &m_critical_map[criticals::critical_id::leg_right_shattered_pelvis];
    } else {
        return nullptr;
    }
}

void CriticalProvider::Initialize(){

    /*
    * Dramatic Injury: The one time you might just feel good about a crit.
    * I wonder how I'll implement that bonus but I guess I'll just make another trait for it.
    */
    m_critical_map[criticals::critical_id::head_dramatic_injury] = [&](Entity* entity){
        entity->Damage(1);
        //here I would now need to apply a trait to the entity for the 1 SL that should
        //be given to any appropriate social tests where a dashing scar might come in handy
        //at this point I have several classes of which I only want a single instance
        //like the ActionProvider, the CriticalProvider and upcoming TraitProvider, ConditionProvider, etc
        //So let's make a central class that manages all of that
    };
}