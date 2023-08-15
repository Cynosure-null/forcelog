#include "ForceLog.h"

ForceLog::ForceLog(std::string_view name)
{
    m_name = name;
    nt::NetworkTableInstance inst = nt::NetworkTableInstance::GetDefault();
    m_table = inst.GetTable(std::to_string(std::rand()));
    wpi::log::DataLog& log = frc::DataLogManager::GetLog();
    string_log = wpi::log::StringLogEntry(log, name);
}

ForceLog::~ForceLog()
{
}

void ForceLog::set_config(LogConfig config)
{
    m_config = config;
}

void ForceLog::err(std::string_view string_to_log)
{
    if (m_config.cout_level >= 1)
    {
        if (m_config.colors)
        {
            std::cout << m_red << "ERROR " << "(" << m_name << "): " << string_to_log << std::endl;
        }
        else
        {
            std::cout << "ERROR: " << string_to_log << std::endl;
        }
    }
    if (m_config.nt_level >= 1)
    {
        m_table->PutString(m_name+"/ERROR/"+std::to_string(frc::GetTime().value()), string_to_log);
    }
    if (m_config.file_level >= 1)
    {
        string_log.Append("ERROR (" + m_name + "): " string_log);

    }
}

void ForceLog::warn(std::string_view string_to_log)
{
    if (m_config.cout_level >= 2)
    {
        if (m_config.colors)
        {
            std::cout << m_yellow << "WARNING" << "(" << m_name << "): " << string_to_log << std::endl;
        }
        else
        {
            std::cout << "WARNING" << string_to_log << std::endl;
        }
    }
    if (m_config.nt_level >= 2)
    {
        m_table->PutString(m_name+"/WARNING/"+std::to_string(frc::GetTime().value()), string_to_log);
    }
    if (m_config.file_level >= 2)
    {
        string_log.Append("WARNING (" + m_name + "): " string_log);

    }
}

void ForceLog::debug(std::string_view string_to_log)
{
    if (m_config.cout_level >= 3)
    {
        if (m_config.colors)
        {
            std::cout << m_green << "DEBUG" << "(" << m_name << "): " << string_to_log << std::endl;
        }
        else
        {
            std::cout << "DEBUG" << string_to_log << std::endl;
        }
    }
    if (m_config.nt_level >= 3)
    {
        m_table->PutString(m_name+"/DEBUG/"+std::to_string(frc::GetTime().value()), string_to_log);
    }
    if (m_config.file_level >= 3)
    {
        string_log.Append("DEBUG (" + m_name + "): " string_log);

    }
}

void ForceLog::info(std::string_view string_to_log)
{
    if (m_config.cout_level >= 4)
    {
        if (m_config.colors)
        {
            std::cout << m_white << "INFO" << "(" << m_name << "): " << string_to_log << std::endl;
        }
        else
        {
            std::cout << "INFO" << string_to_log << std::endl;
        }
    }
    if (m_config.nt_level >= 4)
    {
        m_table->PutString(m_name+"/INFO/"+std::to_string(frc::GetTime().value()), string_to_log);
    }
    if (m_config.file_level >= 4)
    {
        string_log.Append("INFO (" + m_name + "): " string_log);

    }
}
