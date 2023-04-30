#ifndef TASKNINE_ERROR_H
#define TASKNINE_ERROR_H


#include <iostream>

class Error {
public:
    virtual void what() {};
};

class IndexError : public Error {
protected:
    std::string msg;
public:
    IndexError() {
        msg = "Index Error\n";
    }

    virtual void what() {
        std::cout << msg;
    }
};

class SizeError : public Error {
protected:
    std::string msg;
public:
    SizeError() {
        msg = "size error\n";
    }

    void what() override {
        std::cout << msg;
    }
};

class EmptySizeError : public SizeError {
protected:
    std::string msg_;
public:
    EmptySizeError() {
        SizeError();
        msg_ = "List is empty\n";
    }

    void what() override {
        std::cout << msg << msg_;
    }
};

class IndexError1 : public IndexError {
protected:
    std::string msg_;
public:
    IndexError1() {
        IndexError();
        msg_ = "index <0\n";
    }

    void what() override {
        std::cout << msg << msg_;
    }
};

class IndexError2 : public IndexError {
protected:
    std::string msg_;
public:
    IndexError2() {
        IndexError();
        msg_ = "index>size\n";
    }

    void what() override {
        std::cout << msg << msg_;
    }
};


#endif
