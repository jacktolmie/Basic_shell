#ifndef ALIAS_HPP
#define ALIAS_HPP

#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

class Alias{
public:
    using arguments = std::deque<std::string>;
    using _register = std::function<int(std::deque<std::string>&)>;
    using deqstr    = std::deque<std::pair<int, std::string>>;
};

#endif // ALIAS_HPP
