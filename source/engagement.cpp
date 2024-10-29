#include "engagement.hpp"
#include "entity.hpp"

Engagement::Engagement(Entity* p1, Entity* p2)
    :m_participants({p1,p2})
{
    Init();
}

Engagement::~Engagement(){

}

void Engagement::Init(){
    //sort out initial things like initiative order, fear triggers, etc.

    //sort the participant list by initiative
    std::sort(m_participants.begin(),m_participants.end(),[](auto p1, auto p2){
        return p1->GetAttribute("initiative")->GetValue() > p2->GetAttribute("initiative")->GetValue();
    });

    // for(size_t i = 0; i < m_participants.size(); ++i){
    //     std::cout << m_participants[i]->GetName() << " has Initiative " << m_participants[i]->GetAttribute("initiative")->GetValue() << std::endl;
    // }
}
