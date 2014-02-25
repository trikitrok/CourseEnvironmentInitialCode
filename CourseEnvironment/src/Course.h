#pragma once
#ifndef Course_H
#define Course_H

#include <string>

#include <boost/date_time/posix_time/posix_time_types.hpp>

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
  static const int SecondsPerMinute{60};

  std::string name;
  int duration;
  std::string college;
  boost::posix_time::ptime startTime;
};
#endif // !Course_H


