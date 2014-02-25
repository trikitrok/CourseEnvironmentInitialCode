#pragma once

#ifndef Environment_h
#define Environment_h

#include <unordered_map>
#include <string>
#include <vector>

class Environment
{
public:
  Environment();
  virtual ~Environment();

  std::string getVariable(const std::string & key);

private:
  std::unordered_map<std::string, std::string> environmentVariables;

  std::vector<std::string> split(const std::string & line,
    const std::string & delimiter) const;
};
#endif // !Environment_h


