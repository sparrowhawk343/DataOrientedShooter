#pragma once
#include <bitset>

using Entity = size_t;
const Entity MAX_ENTITIES = 5000;

using ComponentType = size_t;
const ComponentType MAX_COMPONENTS = 32;

using Signature = std::bitset<MAX_COMPONENTS>;