#pragma once
#ifndef Course_H
#define Course_H

#include <string>

#include <ctime>

class Course
{
public:
  Course(const std::string & name);
  virtual ~Course();

  void start();
  void end();

  bool isShort() const;
  bool isLong() const;

  std::string getName() const;
  std::string getCollege() const;
  int getDurationInSeconds() const;

private:
  std::string name;
  int duration;
  std::string college;
  clock_t startTime;
};
#endif // !Course_H


