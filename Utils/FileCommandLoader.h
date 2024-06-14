//
// Created by 023da on 14.06.2024.
//

#ifndef UTILS_FILECOMMANDLOADER_H
#define UTILS_FILECOMMANDLOADER_H

#include <functional>
#include <vector>
#include <string>
#include <stdint.h>

class Color;
class Vec2D;

enum CommandType{
    COMMAND_ONE_LINE = 0,
    COMMAND_MULTI_LINE
};

struct ParseFuncParams{
    std::string line;    // Przechowuje linię tekstu
    size_t dilimitPos;   // Pozycja delimitera w linii
    uint32_t lineNum;    // Numer linii
};

using ParseFunc = std::function<void(const ParseFuncParams& params)>;

struct Command{ // Struktura reprezentująca polecenie
    CommandType commandType = COMMAND_ONE_LINE;
    std::string command = "";
    ParseFunc parseFunc = nullptr; // Funkcja analizująca polecenie
};

class FileCommandLoader{ // łądowanie i przetwarzanie polecenia z pliku
public:

    void AddCommand(const Command& command);
    bool LoadFile(const std::string& filePath);

    static Color ReadColor(const ParseFuncParams& params);
    static Vec2D ReadSize(const ParseFuncParams& params);
    static int ReadInt(const ParseFuncParams& params);
    static std::string ReadString(const ParseFuncParams& params);
    static char ReadChar(const ParseFuncParams& params);

private:
    std::vector<Command> mCommands;
};

#endif