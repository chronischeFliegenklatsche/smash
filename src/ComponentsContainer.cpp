#ifdef _COMPONENTS_CONTAINER_HPP
#include <smash.h>

namespace smash
{
    ComponentsContainer::ComponentsContainer() : _head(nullptr), _tail(nullptr) {}

    ComponentsContainer::~ComponentsContainer()
    {
        Node *current = _head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }

    void ComponentsContainer::addComponent(Component& component)
    {
        Node *newNode = new Node(&component);
        if (!_head || component._updateIndex < _head->component->_updateIndex)
        {
            newNode->next = _head;
            _head = newNode;
            if (!_tail)
                _tail = newNode;
            return;
        }

        Node *current = _head;
        while (current->next && current->next->component->_updateIndex < component._updateIndex)
        {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
        if (!newNode->next)
            _tail = newNode;
    }

    void ComponentsContainer::removeComponent(const Component& component)
    {
        if (!_head)
            return;

        if (_head->component->_updateIndex == component._updateIndex)
        {
            Node *temp = _head;
            _head = _head->next;
            delete temp;
            if (!_head)
                _tail = nullptr;
            return;
        }

        Node *current = _head;
        while (current->next && current->next->component->_updateIndex != component._updateIndex)
        {
            current = current->next;
        }

        if (current->next)
        {
            Node *temp = current->next;
            current->next = current->next->next;
            delete temp;
            if (!current->next)
                _tail = nullptr;
        }
    }

    ComponentsContainer::Iterator ComponentsContainer::begin()
    {
        return Iterator(_head);
    }

    ComponentsContainer::Iterator ComponentsContainer::end()
    {
        return Iterator(nullptr);
    }

    ComponentsContainer::ConstIterator ComponentsContainer::begin() const
    {
        return ConstIterator(_head);
    }

    ComponentsContainer::ConstIterator ComponentsContainer::end() const
    {
        return ConstIterator(nullptr);
    }

    ComponentsContainer::Node::Node(Component *component, Node *next) : component(component), next(next) {}

    ComponentsContainer::Iterator::Iterator(Node *current) : _current(current) {}

    ComponentsContainer::Iterator& ComponentsContainer::Iterator::operator++()
    {
        if (_current)
            _current = _current->next;
        return *this;
    }

    ComponentsContainer::Iterator ComponentsContainer::Iterator::operator++(int)
    {
        Iterator temp = *this;
        ++(*this);
        return temp;
    }

    Component& ComponentsContainer::Iterator::operator*()
    {
        return *(_current->component);
    }

    Component* ComponentsContainer::Iterator::operator->()
    {
        return _current->component;
    }

    bool ComponentsContainer::Iterator::operator==(const Iterator& other) const
    {
        return _current == other._current;
    }

    bool ComponentsContainer::Iterator::operator!=(const Iterator& other) const
    {
        return _current != other._current;
    }

    ComponentsContainer::ConstIterator::ConstIterator(const Node *current) : _current(current) {}

    ComponentsContainer::ConstIterator& ComponentsContainer::ConstIterator::operator++()
    {
        if (_current)
            _current = _current->next;
        return *this;
    }

    ComponentsContainer::ConstIterator ComponentsContainer::ConstIterator::operator++(int)
    {
        ConstIterator temp = *this;
        ++(*this);
        return temp;
    }

    const Component& ComponentsContainer::ConstIterator::operator*() const
    {
        return *(_current->component);
    }

    const Component* ComponentsContainer::ConstIterator::operator->() const
    {
        return _current->component;
    }

    bool ComponentsContainer::ConstIterator::operator==(const ConstIterator& other) const
    {
        return _current == other._current;
    }

    bool ComponentsContainer::ConstIterator::operator!=(const ConstIterator& other) const
    {
        return _current != other._current;
    }
}
#endif