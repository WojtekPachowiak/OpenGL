#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <iostream>
#include <map>



//GLuint textureBaseAdrres = GL_TEXTURE0;

class Textures
{
    std::map<unsigned int, int> texDict;
    int texIndex = 0;

public:
    Textures() {
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        stbi_set_flip_vertically_on_load(true);
    }

    unsigned int AddTexture(const char* texPath, GLint wrap_S = GL_REPEAT, GLint wrap_T = GL_REPEAT, GLint minFilter = GL_LINEAR, GLint maxFilter = GL_LINEAR) {
        unsigned int texture;
        // texture 1
        // ---------
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        // set the texture wrapping parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        // set texture filtering parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        // load image, create texture and generate mipmaps
        int width, height, nrChannels;
        unsigned char* data = stbi_load(texPath, &width, &height, &nrChannels, 0);
        if (data)
        {
            GLenum format;
            if (nrChannels == 1)
                format = GL_RED;
            else if (nrChannels == 3)
                format = GL_RGB;
            else if (nrChannels == 4)
                format = GL_RGBA;

            glBindTexture(GL_TEXTURE_2D, texture);
            glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            std::cout << "Failed to load texture" << std::endl;
        }
        stbi_image_free(data);

        texDict[texture] = texIndex;
        texIndex++;
        return texture;
    }

    void BindTexture(unsigned int texture) {
        glActiveTexture(GL_TEXTURE0 + texDict[texture]);
        glBindTexture(GL_TEXTURE_2D, texture);
    }

private:

};



#endif // !TEXTURES_H
