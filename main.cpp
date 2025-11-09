// Main Objective of this project:
// 1. Create text file on the disk
// 2. Write data to that text file
// 3. Close the stream buffer

// New Concept
// 1. Open Function
// 2. Understanding Mode bits in Open Function

// ================ Header include ================
#include <iostream>
#include <fstream> // header for file handling read/write
#include <iomanip>
#include <string>
#include <ctime>
#include <filesystem>

// ================ Header include ================

#ifdef _WIN32
#define LOCALTIME_S(tm_ptr, timep) localtime_s((tm_ptr), (timep))
#else
#define LOCALTIME_S(tm_ptr, timep) localtime_r((timep), (tm_ptr))
#endif


int main()
{
    std::string     filename    = "stat.txt";

    // Take time
    std::time_t     now         = std::time(nullptr);
    std::tm         local       {};
    LOCALTIME_S(&local, &now);

    // Declarations
    int year    = local.tm_year + 1900;
    int month   = local.tm_mon + 1;
    int day     = local.tm_mday;
    int hour    = local.tm_hour;
    int minute  = local.tm_min;
    int second  = local.tm_sec;

    // Open Stream
    std::ofstream outfile(filename); // creating out object of name(<Param>)

    // Write to a file
    outfile << '['
             << year << '/'
             << std::setw(2) << std::setfill('0') << month << '/'
             << std::setw(2) << std::setfill('0') << day << ' '
             << std::setw(2) << std::setfill('0') << hour << ':'
             << std::setw(2) << std::setfill('0') << minute << ':'
             << std::setw(2) << std::setfill('0') << second << "] ";

    // close file
    outfile.close();

    std::cout << "Saved at \"cmake-build-debug/stat.txt\"" << std::endl;
    return 0;
}
