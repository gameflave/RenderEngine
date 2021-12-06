#include "Shader.h"

namespace OpenGL
{
    Shader::Shader(const std::string& filePath)
        :m_FilePath(filePath), m_RendererId(0)
    {
        ShaderProgramSource source = ParseShader(filePath);
        m_RendererId = CreateShader(source.VertexSource, source.FragmentSource);
    }

    Shader::~Shader()
    {
        glDeleteProgram(m_RendererId);
    }

    ShaderProgramSource Shader::ParseShader(const std::string& filePath)
    {
        std::ifstream stream(filePath);

        enum class ShaderType
        {
            NONE = -1, VERTEX = 0, FRAGMENT = 1
        };

        std::string line;
        std::stringstream ss[2];
        ShaderType type = ShaderType::NONE;
        while(getline(stream, line))
        {
            if(line.find("#shader") != std::string::npos)
            {
                if (line.find("vertex") != std::string::npos)
                    type = ShaderType::VERTEX;
                else if (line.find("fragment") != std::string::npos)
                    type = ShaderType::FRAGMENT;
            }
            else
                ss[(int)type] << line << '\n';
        }

        return {ss[0].str(), ss[1].str()};
    }

    unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
    {
        unsigned int id = glCreateShader(type);
        const char* src = source.c_str();
        glShaderSource(id, 1, &src, nullptr);
        glCompileShader(id);

        int result;
        glGetShaderiv(id, GL_COMPILE_STATUS, &result);
        if(result == GL_FALSE)
        {
            int length;
            glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
            char* message = (char*)alloca(length * sizeof(float));
            glGetShaderInfoLog(id, length, &length, message);
            std::cout << "Failled to compile " << (type==GL_VERTEX_SHADER?"vertex":"fragment") << std::endl;
            std::cout << message << std::endl;
            glDeleteShader(id);
            return 0;
        }

        return id;
    }

    unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
    {
        unsigned int program = glCreateProgram();
        unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
        unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

        glAttachShader(program, vs);
        glAttachShader(program, fs);
        glLinkProgram(program);
        glValidateProgram(program);

        glDeleteShader(vs);
        glDeleteShader(fs);

        return program;
    }

    void Shader::Bind() const
    {
        glUseProgram(m_RendererId);
    }
    void Shader::Unbind() const
    {
        glUseProgram(0);
    }

    void Shader::SetUniform4f(const std::string& name, float x, float y, float z, float w)
    {
        glUniform4f(GetUniformLocation(name), x, y, z, w);
    }
    void Shader::SetUniform1i(const std::string& name, int value)
    {
        glUniform1f(GetUniformLocation(name), value);
    }
    void Shader::SetUniformMat4f(const std::string& name, const glm::mat4& mat)
    {
        glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &mat[0][0]);
    }

    unsigned int Shader::GetUniformLocation(const std::string& name) const
    {
        if(m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
            return m_UniformLocationCache[name];

        int location = glGetUniformLocation(m_RendererId, name.c_str());
        if(location == -1)
            std::cout << "Warning: uniform " << name << " doesn't exist" << std::endl;

        m_UniformLocationCache[name] = location;
        return location;
    }
}