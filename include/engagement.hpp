#pragma once

#include <vector>
#include <string>
#include <array>

#include "utility.hpp"

//an engagement is by definition between two entities. passive entities like a tree do not actively engage
//and thus to not count towards outnumbering. this will have to be implemented somehow
//the engagement is the smallest version of an environment within which interactions happen. this can
//either be a self-engagement for tests that only concern the actor itself or opposed engagements between
//two actors
//the engagement maintains an interaction buffer. if one opponent submits an interaction to the buffer,
//the interaction is added. if the interaction has a target, that target is then prompted for a reaction
//which itself can be added to the buffer, that intercation can trigger a new reaction from the initial actor
//and so on. once no more reactions happen, resolve all interactions in the buffer.

class Entity;
class Engagement{
    public:
        Engagement(Entity* p1, Entity* p2);
        ~Engagement();

        //Move assignment
        Engagement& operator=(Engagement&&) noexcept = default;

        void SubmitAction();

    private:
        void Init();
        std::array<Entity*,2> m_participants;
};