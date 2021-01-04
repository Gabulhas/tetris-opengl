#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;
layout (location = 2) in vec3 aColor;
layout (location = 3) in float textureSel;

out vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 ourColor;
out float ts;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0f);
    ourColor = aColor;
    ts = textureSel;
    TexCoord = vec2(aTexCoord.x, aTexCoord.y);
}
