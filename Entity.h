//
// Created by roberts on 2015-10-06.
//

#ifndef ENTITY_FRAMEWORK_ENTITY_H
#define ENTITY_FRAMEWORK_ENTITY_H


#include <memory>
#include <vector>
#include "Component.h"

using std::shared_ptr;
using std::vector;

class ComponentOperationHandler;

class Entity
{
public:
    Entity();
    ~Entity();

    int getUUID();

    void addComponent(shared_ptr<Component> component);
    void removeComponent(shared_ptr<Component> component);

private:
    friend class EntityEngine;

    void setUUID(int uuid);
    void addInternal(shared_ptr<Component> component);
    void removeInternal(shared_ptr<Component> component);

private:
    int uuid;
    vector<shared_ptr<Component>> components;
    shared_ptr<ComponentOperationHandler> componentOperationHandler;
};


#endif //ENTITY_FRAMEWORK_ENTITY_H
