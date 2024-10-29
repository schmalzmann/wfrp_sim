#pragma once

#include <string>
#include <map>
#include <unordered_map>
#include <iostream>

#include "boost/bimap/bimap.hpp"

class Die;
class ActionNode;
class Entity;

template <typename L, typename R>
boost::bimaps::bimap<L, R>
make_bimap(std::initializer_list<typename boost::bimaps::bimap<L, R>::value_type> list)
{
    return boost::bimaps::bimap<L, R>(list.begin(), list.end());
}

namespace attributes
{
    enum attribute_id {
        weapon_skill,
        ballistic_skill,
        strength,
        toughness,
        initiative,
        agility,
        dexterity,
        intelligence,
        willpower,
        fellowship,
        fate,
        fortune,
        resilience,
        resolve,
        corruption,
        movement
    };

    extern boost::bimaps::bimap<attributes::attribute_id,std::string> attID_attName;
}

namespace skills
{
    enum skill_id {
        animal_care,
        animal_training,
        art,
        athletics,
        bribery,
        channelling,
        charm,
        charm_animal,
        climb,
        consume_alcohol,
        cool,
        dodge,
        drive,
        endurance,
        entertain,
        evaluate,
        gamble,
        gossip,
        haggle,
        heal,
        intimidate,
        inutition,
        language,
        leadership,
        lore,
        melee,
        navigation,
        outdoor_survival,
        perception,
        perform,
        pick_lock,
        play,
        pray,
        ranged,
        research,
        ride,
        row,
        sail,
        secret_signs,
        set_trap,
        sleight_of_hand,
        stealth,
        swim,
        track,
        trade
    };

    extern std::map<skills::skill_id,attributes::attribute_id> skillID_attID;
    extern boost::bimaps::bimap<skills::skill_id,std::string> skillID_skillName;
}

namespace talents
{
    enum talent_id {
        accurate_shot,
        acute_sense,
        aethyric_attunement,
        alley_cat,
        ambidextrous,
        animal_affinity,
        arcane_magic,
        argumentative,
        artistic,
        attractive,
        battle_rage,
        beat_blade,
        beneath_notice,
        berserk_charge,
        blather,
        bless,
        bookish,
        break_and_enter,
        briber,
        cardsharp,
        careful_strike,
        carouser,
        catfall,
        cat_tongued,
        chaos_magic,
        combat_aware,
        combat_master,
        combat_reflexes,
        commanding_presence,
        concoct,
        contortionist,
        coolheaded,
        crack_the_whip,
        craftsman,
        criminal,
        deadeye_shot,
        dealmaker,
        detect_artifact,
        diceman,
        dirty_fighting,
        disarm,
        distract,
        doomed,
        drilled,
        dual_wielder,
        embezzle,
        enclosed_fighter,
        etiquette,
        fast_hands,
        fast_shot,
        fearless,
        feint,
        field_dressing,
        fisherman,
        flagellant,
        flee,
        fleet_footed,
        frenzy,
        frightening,
        furious_assault,
        gregarious,
        gunner,
        hardy,
        hatred,
        holy_visions,
        hunters_eye,
        impassioned_zeal,
        implacable,
        in_fighter,
        inspiring,
        instinctive_diction,
        invoke,
        iron_jaw,
        iron_will,
        jump_up,
        kingpin,
        lightning_reflexes,
        linguistics,
        lip_reading,
        luck,
        magical_sense,
        magic_resistance,
        magnum_opus,
        marksman,
        master_of_disguise,
        master_orator,
        master_tradesman,
        menacing,
        mimic,
        night_vision,
        nimble_fingered,
        noble_blood,
        nose_for_trouble,
        numismatics,
        old_salt,
        orientation,
        panhandle,
        perfect_pitch,
        petty_magic,
        pharmacist,
        pilot,
        public_speaker,
        pure_soul,
        rapid_reload,
        reaction_strike,
        read_write,
        relentless,
        resistance,
        resolute,
        reversal,
        riposte,
        river_guide,
        robust,
        roughrider,
        rover,
        savant,
        savvy,
        scale_sheer_surface,
        schemer,
        sea_legs,
        seasoned_traveller,
        second_sight,
        secret_identity,
        shadow,
        sharp,
        sharpshooter,
        shieldsman,
        sixth_sense,
        slayer,
        small,
        sniper,
        speedreader,
        sprinter,
        step_aside,
        stone_soup,
        stout_hearted,
        strider,
        strike_mighty_blow,
        strike_to_injure,
        strike_to_stun,
        strong_back,
        strong_legs,
        strong_minded,
        strong_swimmer,
        sturdy,
        suave,
        super_numerate,
        supportive,
        sure_shot,
        surgery,
        tenacious,
        tinker,
        tower_of_memories,
        trapper,
        trick_riding,
        tunnel_rat,
        unshakable,
        very_resilient,
        very_strong,
        war_leader,
        war_wizard,
        warrior_born,
        waterman,
        wealthy,
        well_prepared,
        witch
    };

    extern boost::bimaps::bimap<talents::talent_id,std::string> talentID_talentName;

}

namespace traits
{
    enum trait_id {
        afraid,
        amphibious,
        arboreal,
        animosity,
        armour,
        belligerent,
        bestial,
        big,
        bite,
        blessed,
        bounce,
        breath,
        brute,
        champion,
        chill_grasp,
        clever,
        cold_blooded,
        constrictor,
        construct,
        corrosive_blood,
        corrupted,
        cunning,
        dark_vision,
        daemonic,
        die_hard,
        disease,
        distracting,
        elite,
        ethereal,
        fast,
        fear,
        flight,
        frenzy,
        fury,
        ghostly_howl,
        hardy,
        hatred,
        horns,
        hungry,
        immunity,
        immunity_to_psychology,
        infected,
        infestation,
        leader,
        magical,
        magic_resistance,
        mental_corruption,
        miracles,
        mutation,
        night_vision,
        painless,
        petrifying_gaze,
        prejudice,
        ranged,
        rear,
        regenerate,
        size,
        skittish,
        spellcaster,
        stealthy,
        stride,
        stupid,
        swamp_strider,
        swarm,
        tail_attack,
        tentacles,
        territorial,
        terror,
        trained,
        tongue_attack,
        tough,
        tracker,
        undead,
        unstable,
        vampiric,
        venom,
        vomit,
        ward,
        wallcrawler,
        weapon,
        web
    };

    extern boost::bimaps::bimap<traits::trait_id,std::string> traitID_traitName;
}

namespace actions {

    struct action_node_data {
        //add containers as needed
        Entity* entity;
        Entity* target;
        std::string test_name;
        std::unique_ptr<Die> d;
        int success_level;
        ActionNode* previous_node;
        std::vector<std::string> tags;
    };

    enum action_id {
        simple_test,
        critical,
        oppose,
        do_damage
    };
}

namespace states {
    /*anything that modifies wounds, attributes, skills, rolls or success levels and does not "evolve"
    * is managed here. E.g. the talent "warrior born" provides a state of the same name which modifies
    * weapon skill by +5 permanently. Similarly, "dead" is a state as well.
    */

    enum state_id {
        dead,
        warrior_born,
        marksman,
        amputation_secondary_arm,
        amputation_primary_arm
    };
}

namespace conditions {
    /*
    * Things like "prone" or "ablaze" are considered conditions because they "evolve" in the sense that they
    * can have stacks that can change, apply their effect every time unit and can have an age after which
    * they go away or change into a state
    */

    struct condition_data {
        unsigned int stacks;
        int age_limit;
        int age_current;
    };

    enum condition_id {
        prone,
        ablaze,
        bleeding,
        afraid
    };
}

namespace criticals {
    enum critical_id {
        head_dramatic_injury,
        head_minor_cut,
        head_poked_eye,
        head_ear_bash,
        head_rattling_blow,
        head_black_eye,
        head_sliced_ear,
        head_struck_forehead,
        head_fractured_jaw,
        head_major_eye_wound,
        head_major_ear_wound,
        head_broken_nose,
        head_broken_jaw,
        head_concussive_blow,
        head_smashed_mouth,
        head_mangled_ear,
        head_devastated_eye,
        head_disfiguring_blow,
        head_mangled_jaw,
        head_decapitated,
        arm_sec_jarred_arm,
        arm_sec_minor_cut,
        arm_sec_sprain,
        arm_sec_badly_jarred_arm,
        arm_sec_torn_muscles,
        arm_sec_bleeding_hand,
        arm_sec_wrenched_arm,
        arm_sec_gaping_wound,
        arm_sec_clean_break,
        arm_sec_ruptured_ligament,
        arm_sec_deep_cut,
        arm_sec_damaged_artery,
        arm_sec_crushed_elbow,
        arm_sec_dislocated_shoulder,
        arm_sec_severed_finger,
        arm_sec_cleft_hand,
        arm_sec_mauled_bicep,
        arm_sec_mangled_hand,
        arm_sec_sliced_tendons,
        arm_sec_brutal_dismemberment,
        arm_main_jarred_arm,
        arm_main_minor_cut,
        arm_main_sprain,
        arm_main_badly_jarred_arm,
        arm_main_torn_muscles,
        arm_main_bleeding_hand,
        arm_main_wrenched_arm,
        arm_main_gaping_wound,
        arm_main_clean_break,
        arm_main_ruptured_ligament,
        arm_main_deep_cut,
        arm_main_damaged_artery,
        arm_main_crushed_elbow,
        arm_main_dislocated_shoulder,
        arm_main_severed_finger,
        arm_main_cleft_hand,
        arm_main_mauled_bicep,
        arm_main_mangled_hand,
        arm_main_sliced_tendons,
        arm_main_brutal_dismemberment,
        leg_left_stubbed_toe,
        leg_left_twisted_ankle,
        leg_left_minor_cut,
        leg_left_lost_footing,
        leg_left_thigh_strike,
        leg_left_sprained_ankle,
        leg_left_twisted_knee,
        leg_left_badly_cut_toe,
        leg_left_bad_cut,
        leg_left_badly_twisted_knee,
        leg_left_hacked_leg,
        leg_left_torn_thigh,
        leg_left_ruptured_tendon,
        leg_left_carved_shin,
        leg_left_broken_knee,
        leg_left_dislocated_knee,
        leg_left_crushed_foot,
        leg_left_severed_foot,
        leg_left_cut_tendon,
        leg_left_shattered_pelvis,
        leg_right_stubbed_toe,
        leg_right_twisted_ankle,
        leg_right_minor_cut,
        leg_right_lost_footing,
        leg_right_thigh_strike,
        leg_right_sprained_ankle,
        leg_right_twisted_knee,
        leg_right_badly_cut_toe,
        leg_right_bad_cut,
        leg_right_badly_twisted_knee,
        leg_right_hacked_leg,
        leg_right_torn_thigh,
        leg_right_ruptured_tendon,
        leg_right_carved_shin,
        leg_right_broken_knee,
        leg_right_dislocated_knee,
        leg_right_crushed_foot,
        leg_right_severed_foot,
        leg_right_cut_tendon,
        leg_right_shattered_pelvis,
        body_tis_but_a_scratch,
        body_gut_blow,
        body_low_blow,
        body_twisted_back,
        body_winded,
        body_bruised_ribs,
        body_wrenched_collar_bone,
        body_ragged_wound,
        body_cracked_ribs,
        body_gaping_wound,
        body_painful_cut,
        body_arterial_damage,
        body_pulled_back,
        body_fractured_hip,
        body_major_chest_wound,
        body_gut_wound,
        body_smashed_rib_cage,
        body_broken_collar_bone,
        body_internal_bleeding,
        body_torn_apart
    };
}

namespace utility
{
    std::string baseAttrName_from_skillName(std::string name);
    bool isAttribute(std::string attName);
}
