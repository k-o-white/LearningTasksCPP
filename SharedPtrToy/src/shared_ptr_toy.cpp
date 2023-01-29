//
// Created by teena on 25.01.2023.
//

#include "shared_ptr_toy.h"

shared_ptr_toy::shared_ptr_toy() : obj(new Toy("SomeName")), linkCount(new int(1)) {};

shared_ptr_toy::shared_ptr_toy(std::string name) : obj(new Toy(std::move(name))), linkCount(new int(1)) {};

shared_ptr_toy::shared_ptr_toy(const shared_ptr_toy& oth) : obj(oth.obj), linkCount(oth.linkCount)
{
    ++(*this->linkCount);
}

shared_ptr_toy& shared_ptr_toy::operator=(const shared_ptr_toy& oth)
{
    if (this == &oth)
        return *this;
    if (this->obj != nullptr)
    {
        delete this->obj;
        delete this->linkCount;
    }
    this->obj = oth.obj;
    this->linkCount = oth.linkCount;
    ++(*this->linkCount);
    return *this;
}

shared_ptr_toy::~shared_ptr_toy()
{
    if (this->obj != nullptr)
    {
        if (--(*linkCount) == 0)
        {
            delete this->obj;
            delete this->linkCount;
        }
    }
    this->obj = nullptr;
    this->linkCount = nullptr;
}

std::string shared_ptr_toy::getToyName()
{
    return obj->getName();
}

shared_ptr_toy make_shared_toy()
{
    shared_ptr_toy ptrToy;
    return ptrToy;
}

shared_ptr_toy make_shared_toy(const std::string &name)
{
    shared_ptr_toy ptrToy(name);
    return ptrToy;
}

shared_ptr_toy make_shared_toy(const shared_ptr_toy& oth)
{
    shared_ptr_toy ptrToy(oth);
    return ptrToy;
}