#shader vertex
#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 textCord;
layout(location = 2) in float textIndex;

out vec2 v_TexCord;
out float v_TexIndex;

uniform mat4 u_VP;

void main()
{
   gl_Position = u_VP * position;
   v_TexCord = textCord;
};

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec2 v_TexCord;
in float v_TexIndex;

void main()
{
   int index = int(v_TexIndex);
   vec4 texColor = texture(index, v_TexCord);
   color = texColor;
}; 