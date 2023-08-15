#pragma once
#include <frc/DataLogManager.h>
#include <frc/DriverStation.h>
#include <frc/Timer.h>
#include <iostream>
#include <networktables/DoubleTopic.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>
#include <random>
#include <string>
#include <units/time.h>

class ForceLog {
public:
  struct LogConfig {
    /// @brief Which functions should log with a cout. 0 couts nothing, 4 couts
    /// everything.
    int cout_level = 2;

    /// @brief Which functions should log via networktables. 0 logs nothing, 4
    /// logs everyhing.
    int nt_level = 4;

    /// @brief Which functions should write to a file. 0 logs nothing, 4 logs
    /// everything.
    /// Note that file level ALSO logs to STDOUT, so cout_level and file_level
    /// are redundant at times
    int file_level = 0;

    /// @brief Should couts be colorful
    bool colors = 0;
  };

    void set_config(LogConfig config);
    void info(std::string_view string_to_log);  // 4
    void debug(std::string_view string_to_log); // 3
    void warn(std::string_view string_to_log);  // 2
    void err(std::string_view string_to_log);   // 1
    ForceLog(std::string_view name);
    ~ForceLog();

  private:
    std::string_view m_name;
    std::string_view m_red = "\\x1b[;31m";
    std::string_view m_yellow = "\\x1b[;33m";
    std::string_view m_green = "\\x1b[;32m";
    std::string_view m_white = "\\x1b[;39m";
    std::shared_ptr<nt::NetworkTable> m_table;
    LogConfig m_config;
};
