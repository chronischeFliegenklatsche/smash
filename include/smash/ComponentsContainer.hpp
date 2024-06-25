#ifndef _COMPONENTS_CONTAINER_HPP
#define _COMPONENTS_CONTAINER_HPP

#include "Component.hpp"

namespace smash
{
    class ComponentsContainer
    {
    public:
        struct Node;
        class Iterator;
        class ConstIterator;

    private:
        Node *_head;
        Node *_tail;

    public:
        ComponentsContainer();
        ~ComponentsContainer();
        void addComponent(Component& component);
        void removeComponent(const Component& component);
        Iterator begin();
        Iterator end();
        ConstIterator begin() const;
        ConstIterator end() const;
    };

    struct ComponentsContainer::Node
    {
        Component *component;
        Node *next;
        Node(Component *component, Node *next = nullptr);
    };

    class ComponentsContainer::Iterator
    {
        Node *_current;

    public:
        Iterator(Node *current);
        Iterator& operator++();
        Iterator operator++(int);
        Component& operator*();
        Component* operator->();
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
    };

    class ComponentsContainer::ConstIterator
    {
        const Node *_current;

    public:
        ConstIterator(const Node *current);
        ConstIterator& operator++();
        ConstIterator operator++(int);
        const Component& operator*() const;
        const Component* operator->() const;
        bool operator==(const ConstIterator& other) const;
        bool operator!=(const ConstIterator& other) const;
    };
}

#endif