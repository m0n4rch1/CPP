#ifndef BASE_HPP
#define BASE_HPP

// A polymorphic base with only a virtual destructor
class Base {
public:
    virtual ~Base() {}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif
