#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <GL/glew.h>
#include <unordered_map>

#include "glm/glm.hpp"

namespace OpenGL
{
    struct ShaderProgramSource{
        std::string VertexSource;
        std::string FragmentSource;
    };

    class Shader
    {  
    private:
        std::string m_FilePath;
        unsigned int m_RendererId;
        mutable std::unordered_map<std::string, int> m_UniformLocationCache;
    public:
        Shader(const std::string& filePath);
        ~Shader();

        void Bind() const;
        void Unbind() const;

        //Uniforms
        void SetUniform4f(const std::string& name, float, float, float, float);
        void SetUniform1i(const std::string& name, int value);
        void SetUniformMat4f(const std::string& name, const glm::mat4& mat);
    private:
        ShaderProgramSource ParseShader(const std::string& filePath);
        unsigned int CompileShader(unsigned int type, const std::string& source);
        unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
        
        unsigned int GetUniformLocation(const std::string& name) const;
    };
}