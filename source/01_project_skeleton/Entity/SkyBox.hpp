//
//  SkyBox.hpp
//  opengl-series
//
//  Created by SATAN_Z on 2017/9/17.
//
//

#ifndef SkyBox_hpp
#define SkyBox_hpp

#include <iostream>
#include "Entity.hpp"
#include "TextureCube.hpp"

namespace ze{
    
    class SkyBox : public Entity{
    public:
        SkyBox();
        ~SkyBox();
        
        static SkyBox * create(zdogl::TextureCube & textureCube);
        
        static SkyBox * create(const std::vector<const GLchar *> &faces);
        
        bool init(zdogl::TextureCube & textureCube);
        
        virtual bool initProgram(const std::string &vs , const std::string &fs);
        
        virtual void initVao();
        
        virtual void _begin();
        
        virtual void _end();
        
        virtual void draw(float dt);
        
        bool init(const std::vector<const GLchar *> &faces);
        
    protected:
        
        zdogl::TextureCube _textureCube;
        
        
    };
    
}

#endif /* SkyBox_hpp */
