#pragma once
#include "Ninja.hpp"
using namespace std;

namespace ariel{
    class OldNinja: public Ninja{
        public:
            OldNinja(const string name, const Point location);
    };
};