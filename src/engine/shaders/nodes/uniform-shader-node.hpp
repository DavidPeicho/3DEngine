#pragma once

#include <string>

#include "shader-node.hpp"

class UniformShaderNode : public ShaderNode
{
  public:
    virtual std::string toString();
    virtual const std::string getName() const;

  public:
    void setName(std::string name);

    void setType(std::string type);
    const std::string getType() const;

    void setDefaultValue(std::string value);
    const std::string getDefaultValue() const;

  private:
    std::string name_;
    std::string type_;
    std::string defaultValue_;
};
