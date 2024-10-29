#pragma once

//this class is the base for talend, trait and mutation classes
//all of these are mechanically simialr

#include <iostream>
#include <vector>

//base feature class
//all features (attributes, skills, talents, traits, modifiers)
//have things that trigger them and things they trigger
//they generally are associated with some kind of value (attribute or skill value, talent rank, trait rating, etc.)
//and they have a name (fear, strength, bestial, ...) with often a subcategory (fear(mutant), trade(carpentry))

//the idea of input/output triggers is to set up event chains that are outside of the player's control and
//thus automate any form of engagement as much as possible

//unique to attributes:
//  basically just a number
//  have individual mod values attached which get influenced by modifiers
//unique to skills:
//  always have a base attribute
//  have individual mod values attached which get influenced by modifiers
//unique to talents:
//  active or passive
//  associated tests where SLs are added on a successful test
//  usually attribute based rank limits
//unique to traits:
//  mostly passive (tiny, tough)
//  trigger mostly automatically and cause skill checks for other entities (fear)
//  apply static modifications to an entity (e.g. big)
//unique to modifiers:
//  directly touch mod values of attributes and skills
//  do not trigger but instead apply either their effect on attributes/skills once (extreme range bow shot, fatigue)
//      or are recurring (ablaze, bleeding)

class Feature{
    public:
        //this is a virtual base class
        Feature(std::string name, std::string category, int value);
        virtual ~Feature(){};

        const std::vector<Feature*>& GetInputTrigger();
        const std::vector<Feature*>& GetOutputTrigger();

        void SetInputTrigger(Feature* feat){m_input_triggers.push_back(feat);};
        void SetOutputTrigger(Feature* feat){m_output_triggers.push_back(feat);};

        void SetValue(int value){m_value = value;};
        int GetValue(){return m_value;};
        std::string GetName(){return m_name;};
        std::string GetCategory(){return m_category;};

    protected:
        std::vector<Feature*> m_input_triggers;
        std::vector<Feature*> m_output_triggers;
        std::string m_name;
        std::string m_category;
        int m_value;
};