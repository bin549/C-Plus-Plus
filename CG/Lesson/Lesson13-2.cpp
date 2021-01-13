void init()
{
    GLfloat fogColor[]={1,1,1,1};
glFogfv(GL_FOG_COLOR, fogColor);   //fog’s color
  glFogf(GL_FOG_START, 200.0f);  // how far to start
  glFogf(GL_FOG_END, 260.0f); //how far to end
  glFogi(GL_FOG_MODE,GL_LINEAR);  //which mode
glFogf(GL_FOG_DENSITY, 0.5f);
glEnable(GL_FOG); 
} 
  