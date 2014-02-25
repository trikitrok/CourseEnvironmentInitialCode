#include "Environment.h"

#include <fstream>
#include<algorithm>

Environment::Environment() {

  std::ifstream environmentFile;

  environmentFile.open("src\\data\\environment.txt");

  if (environmentFile.is_open()) {
    std::string line;
    while (std::getline(environmentFile, line)) {
      std::vector<std::string> tokens = split(line, ":");
      environmentVariables[tokens[0]] = tokens[1];
    }
    environmentFile.close();
  } else {
    throw 1;
  }
}

Environment::~Environment() {}

std::string Environment::getVariable(const std::string & key) {
  return environmentVariables.find(key)->second;
}

std::vector<std::string> Environment::split(const std::string & line, const std::string & delimiter) const {

  std::vector<std::string> elements;

  if (delimiter.empty()) {
    elements.push_back(line);
    return elements;
  }

  std::string::const_iterator substart = line.begin();
  std::string::const_iterator subend;

  while (true) {
    subend = std::search(substart, line.end(), delimiter.begin(), delimiter.end());

    std::string token(substart, subend);

    if (!token.empty())
      elements.push_back(token);

    if (subend == line.end())
      break;

    substart = subend + delimiter.size();
  }

  return elements;
}
