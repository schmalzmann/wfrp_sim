#pragma once

#include <toml.hpp>

#include <algorithm>
#include <memory>

#include "utility.hpp"
#include "attribute.hpp"
#include "skill.hpp"
#include "state.hpp"
#include "condition.hpp"

//the entity class is supposed to be a base class for any kind of object or being in the world, such as
//player character, a dragon, a tree or a wall.
//there are a few very basic things any entity would have such as some form of toughness to indiate how it deals with
//incoming damage or maybe a size (tiny, small, normal, large, enormous, monstrous), a description, location, etc

class Engagement;
class Entity{
    public:
        Entity(const Entity& d);
        Entity(const toml::table& info);
        ~Entity();

        void ClearModifiers();
        void ApplySelfModifiers();

        //entities store their own attributes and skills
        std::shared_ptr<Attribute> GetAttribute(std::string name);
        std::shared_ptr<Skill> GetSkill(std::string name);

        void AddEngagement(Engagement* engagement);
        void DelEngagement(Engagement* engagement);

        std::string GetName(){return m_name;};
        std::string GetType(){return m_type;};

        int GetMaxWounds();
        void ModifyWounds(int n);

        void Heal(unsigned int n);
        void Damage(unsigned int n);

    protected:
        void ParseInfo();

        toml::table m_info;
        std::string m_name;
        std::string m_type;
        std::map<std::string,std::shared_ptr<Attribute>> m_attributes;
        std::map<std::string,std::shared_ptr<Skill>> m_skills;
        std::map<std::string,talents::talent_id> m_talents;
        std::map<std::string,traits::trait_id> m_traits;
        std::map<std::string,std::shared_ptr<State>> m_states;
        std::map<std::string,std::shared_ptr<Condition>> m_conditions;

        //engagements with other entities
        std::vector<Engagement*> m_engagements;

        //wounds of the entity (e.g. health points)
        int m_wounds;


};