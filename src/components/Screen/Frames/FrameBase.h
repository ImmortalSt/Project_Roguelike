#ifndef FRAMEBASE_H
#define FRAMEBASE_H

#include <string>
#include <codecvt>
#include <fstream>
#include <vector>

class FrameBase {
protected:
    std::vector<std::wstring> lines;
 
    void InitFrame() {
        std::string filePath = getReletiveFilePath();
        lines.clear();

        std::wifstream in(filePath);
        in.imbue(std::locale(in.getloc(), new std::codecvt_utf16<wchar_t, 0x10ffff, std::consume_header>));

        std::wstring line;
        while (in.eof() == false) {
            getline(in, line);

//
            //if (line.length() !=  WIDTH) 
            //    throw std::length_error("the file width does not match the screen width " 
            //        + std::to_string((int)WIDTH) + " != " + std::to_string(line.length()) 
            //        + " " + "" + " " + filePath);
//
            line += L"\n";
            lines.push_back(line);
        }
        //if(lines.size() != HEIGHT)
        //    throw std::length_error("the file HEIGHT does not match the screen HEIGHT " 
        //            + std::to_string((int)HEIGHT) + " != " + std::to_string(lines.size()) 
        //            + " " + filePath);
    }

public:
    const static int WIDTH = 140;
    const static int HEIGHT = 30;

    virtual std::string getReletiveFilePath() = 0;
    std::vector<std::wstring> GetFrame() {
        return lines;
    }
    virtual std::string getName() = 0;
   // virtual std::map<std::string, Field> getFields() = 0;
};

#endif