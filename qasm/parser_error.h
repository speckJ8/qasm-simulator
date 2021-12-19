#ifndef __QASM_LANG__PARSER_ERROR_H__
#define __QASM_LANG__PARSER_ERROR_H__

#include <string>
#include <exception>
#include <iostream>

namespace qasm {
namespace parser {

class ParserError : public std::exception {
private:
    std::string _what;

public:
    unsigned int line, column;
    std::string msg;
    std::string filename;

    ParserError (std::string msg, unsigned int line, unsigned int column):
        line(line), column(column), msg(msg), filename("file-name") {
        _what = "[" + filename + ":" + std::to_string(line) + ":" +
            std::to_string(column) + "] " + msg;
    }

    ParserError (std::string msg, unsigned int line, unsigned int column,
                 std::string filename):
        line(line), column(column), msg(msg), filename(filename) {
        _what = "[" + filename + ":" + std::to_string(line) + ":" +
            std::to_string(column) + "] " + msg;
    }

    const char* what () const throw () {
        return _what.c_str();
    }

    inline std::string to_string () const {
        return _what;
    }
};

};
};


#endif // __QASM_LANG__PARSER_ERROR_H__
