#include <stack.hpp>
#include <catch.hpp>


SCENARIO("count", "[init]") {
    stack<int> _stack;
    REQUIRE(_stack.count() == 0);
}

SCENARIO("pushing", "[init]") {
    stack<int> _stack;
    _stack.push(1);
    _stack.push(2);
    _stack.push(3);
    REQUIRE(_stack.count() == 3);
}

SCENARIO("pop", "[init]") {
    stack<int> _stack;
    _stack.push(1);
    _stack.push(2);
    _stack.push(3);
    _stack.pop();
    _stack.pop();
    _stack.pop();
    REQUIRE(_stack.count() == 0);
}

