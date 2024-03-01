#ifndef Objects_h
#define Objects_h
#include "Game.h"


class Objects
{
private:
   SDL_Rect dest;
   SDL_Texture * objTexture;
  
public:
   Objects();
   virtual ~Objects();
   
   void objInit(const char * texturesheet);
   void objUpdate(float x, float y, float w, float h);
   void objDraw(SDL_Renderer & render);
   
 
};



#endif //Objects_h