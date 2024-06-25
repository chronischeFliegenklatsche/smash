
#include <smash.h>

namespace smash
{

    Component::Component() : _updateIndex(0), _gameObject(nullptr)
    {}

    Component::Component(int updateIndex) : _updateIndex(updateIndex), _gameObject(nullptr)
    {}

    GameObject* Component::getGameObject() const
    {
        return _gameObject;
    }

    Component::~Component()
    {}
}
