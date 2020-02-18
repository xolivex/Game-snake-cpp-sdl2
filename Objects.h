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
   ~Objects();
   
   void objInit(const char * texturesheet);
   void objUpdate(float x, float y, float w, float h);
   void objDraw();
   
 
};



#endif //Objects_h