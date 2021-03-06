#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <GL/glew.h>

#include "glm/glm.hpp"

#include "Renderer/Shader.h"

struct OpenGLShaderProgramSource{
    std::string VertexSource;
    std::string FragmentSource;
};

class OpenGLShader : public Shader
{  
public:
    OpenGLShader(const std::string& filePath);
    virtual ~OpenGLShader() override;

    virtual void Bind() const override;
    virtual void Unbind() const override;
    //Uniforms
    void SetUniform4f(const std::string& name, float, float, float, float);
    void SetUniform1i(const std::string& name, int value);
    void SetUniformMat4f(const std::string& name, const glm::mat4& mat);
private:
    OpenGLShaderProgramSource ParseShader(const std::string& filePath);
    unsigned int CompileShader(unsigned int type, const std::string& source);
    unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
    
    unsigned int GetUniformLocation(const std::string& name) const;
private:
    std::string m_FilePath;
    unsigned int m_RendererId;
    mutable std::unordered_map<std::string, int> m_UniformLocationCache;
};