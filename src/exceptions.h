//
//  meiexception.cpp
//  mei
//
//  Created by Andrew Hankinson on 11-08-09.
//  Copyright 2011 McGill University. All rights reserved.
//

#ifndef MEIEXCEPTION_H_
#define MEIEXCEPTION_H_

#include <exception>
#include <stdexcept>

namespace mei {
    
class MeiException : public std::runtime_error {
private:
    std::string message;
public:
    explicit MeiException(const std::string& message) : std::runtime_error(message) {
        this->message = message;
    }
    
    virtual const char* what() const throw()
	{
		return message.c_str();
	}
    ~MeiException() throw() {}
};

class DuplicateAttributeException : public MeiException {
public:
    explicit DuplicateAttributeException(const std::string &what) : MeiException("Attribute " + what + " is already present on this object.") {}
    ~DuplicateAttributeException() throw() {};
};

class AttributeNotFoundException : public MeiException {
public:
    explicit AttributeNotFoundException(const std::string &what) : MeiException("The attribute " + what + " was not found on this object.") {}
    ~AttributeNotFoundException() throw() {};
};

class ChildNotFoundException : public MeiException {
public:
    explicit ChildNotFoundException(const std::string &what) : MeiException("The child " + what + " was not found on this object.") {}
    ~ChildNotFoundException() throw() {};
};


class FooBarException : public MeiException {
public:
    explicit FooBarException(const std::string &what) : MeiException("blahblah") {}
    ~FooBarException() throw() {};
};
}
#endif

