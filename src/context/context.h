#pragma once

template <typename Derived>
class Context {
public:
    void render(){
        static_cast<Derived*>(this)->render();
    }
    void update(){
        static_cast<Derived*>(this)->update();
    }
};