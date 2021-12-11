#pragma once

#include <iostream>
#include <vector>

#include "Renderer/Renderer.h"

//////////////////////////////////////////////////////////////////
//BufferLayout
//////////////////////////////////////////////////////////////////

enum class ShaderDataType
{
    None = 0, Float, Float2, Float3, Float4, Mat3, Mat4, Int, Int2, Int3, Int4, Bool

};
static unsigned int ShaderDataTypeSize(ShaderDataType type)
{
    switch (type)
    {
    case ShaderDataType::Float:     return 4;
    case ShaderDataType::Float2:    return 4 * 2;
    case ShaderDataType::Float3:    return 4 * 3;
    case ShaderDataType::Float4:    return 4 * 4;
    case ShaderDataType::Mat3:      return 4 * 3 * 3;
    case ShaderDataType::Mat4:      return 4 * 4 * 4;
    case ShaderDataType::Int:       return 4;
    case ShaderDataType::Int2:      return 4 * 2;
    case ShaderDataType::Int3:      return 4 * 3;
    case ShaderDataType::Int4:      return 4 * 4;
    case ShaderDataType::Bool:      return 1;
    default: fprintf(stderr, "Error: Unknow ShaderDataType"); return 0;
    }
}

struct BufferElement
{
    std::string Name;
    ShaderDataType Type;
    unsigned int Size;
    unsigned int Offset;
    bool Normalized;

    BufferElement() {}
    BufferElement(ShaderDataType type, const std::string& name)
        :Name(name), Type(type), Size(ShaderDataTypeSize(type)), Offset(0), Normalized(false)
    { 
    }

    unsigned int GetElementCount() const
    {
        switch (Type)
        {
        case ShaderDataType::Float:     return 1;
        case ShaderDataType::Float2:    return 2;
        case ShaderDataType::Float3:    return 3;
        case ShaderDataType::Float4:    return 4;
        case ShaderDataType::Mat3:      return 3 * 3;
        case ShaderDataType::Mat4:      return 4 * 4;
        case ShaderDataType::Int:       return 1;
        case ShaderDataType::Int2:      return 2;
        case ShaderDataType::Int3:      return 3;
        case ShaderDataType::Int4:      return 4;
        case ShaderDataType::Bool:      return 1;
        default: fprintf(stderr, "Error: Unknow ShaderDataType"); return 0;
        }
    }
};

class BufferLayout
{
public:
    BufferLayout() {}
    BufferLayout(const std::initializer_list<BufferElement> elements);

    inline const std::vector<BufferElement>& GetElements() const {return m_Elements;}
    inline unsigned int GetStride() const {return m_Stride;}
private:
    void CalculateOffsetsAndStride();
private:
    std::vector<BufferElement> m_Elements;
    unsigned int m_Stride;
};

//////////////////////////////////////////////////////////////////
//VertexBuffer
//////////////////////////////////////////////////////////////////

class VertexBuffer
{
public:
    virtual ~VertexBuffer() {}

    virtual void Bind() const = 0;
    virtual void Unbind() const = 0;

    virtual void SetLayout(const BufferLayout& layout) = 0;
    virtual const BufferLayout& GetLayout() const = 0;

    static VertexBuffer* Create(float* vertices, unsigned int size);
};

//////////////////////////////////////////////////////////////////
//IdexBuffer
//////////////////////////////////////////////////////////////////

class IndexBuffer
{
private:
    
public:
    virtual ~IndexBuffer() {}

    virtual void Bind() const = 0;
    virtual void Unbind() const = 0;

    static IndexBuffer* Create(unsigned int* indices, unsigned int count);
};
