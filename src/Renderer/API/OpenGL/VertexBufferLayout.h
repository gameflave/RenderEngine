#pragma once

#include <vector>
#include <GL/glew.h>
#include <iostream>

namespace OpenGL
{
    struct VertexBufferElement
    {
        unsigned int type;
        unsigned int count;
        unsigned char normalized;

        static unsigned int GetSizeOfType(unsigned int type)
        {
            switch (type)
            {
            case GL_FLOAT:
                return 4;
            case GL_UNSIGNED_INT:
                return 4;
            case GL_UNSIGNED_BYTE:
                return 1;
            }

            return 0;
        }
    };

    class VertexBufferLayout
    {
    public:
        VertexBufferLayout():m_Stride(0) {};

    //    template<typename T>
        void Push(unsigned int type, unsigned int count)
        {
            m_Elements.push_back({type, count, GL_FALSE});
            m_Stride += count * VertexBufferElement::GetSizeOfType(type);
        }
    /*
        template<float> void Push(unsigned int count)
        {
            m_Elements.push_back({GL_FLOAT, count, GL_FALSE});
            m_Stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
        }

        template<unsigned int> void Push(unsigned int count)
        {
            m_Elements.push_back({GL_UNSIGNED_INT, count, GL_FALSE});
            m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
        }

        template<char> void Push(unsigned int count)
        {
            m_Elements.push_back({GL_UNSIGNED_BYTE, count, GL_TRUE});
            m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
        }
    */
        inline const std::vector<VertexBufferElement> GetElements() const { return m_Elements; }
        inline unsigned int GetStride() const { return m_Stride; }
    private:
        std::vector<VertexBufferElement> m_Elements;
        unsigned int m_Stride;
    };
}
