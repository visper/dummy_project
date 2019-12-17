#include "movie.h"

Movie::Movie(const std::string& type,
            const std::string& name) :
            type_(type),
            name_(name) {
}


std::string Movie::getType() const
{
return type_;
}


std::string Movie::getName() const
{
return name_;
}
