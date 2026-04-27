#include "GameObject.h"

GameObject::GameObject(const std::string &n, const std::string &d) : name(n), description(d) {}

void GameObject::setName(const std::string &s) {
    name = s;
}

std::string GameObject::getName() const {
    return name;
}

std::string GameObject::getDescription() const { // 实现getDescription方法
    return description;
}

void GameObject::setDescription(const std::string &s) {
    description = s;
}