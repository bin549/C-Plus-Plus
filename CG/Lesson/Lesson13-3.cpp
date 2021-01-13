void drawsphere(int flag)
{ 
	float tr; 	
	tr=(outer+3*inner); 	
	glRotatef(theta,0,1,0);
  
	glPushMatrix();
		glPushMatrix();
		   if (flag==1)
		  	glColor3f(1.0,0,0.0);
		   else
             glColor3f(0.5,0.5,0.5);
	      glutSolidTorus(inner,outer,50,80); 
		glPopMatrix();
	 
		glPushMatrix();		 
			glTranslatef(outer,0,0);
			glRotatef(theta,0,1,0);
			glTranslatef(-outer,0,0);
	
			glPushMatrix();		      
				glTranslatef(tr,0,0);
				glRotatef(-45,1,0,0);
				if (flag==1) 
					glColor3f(0.0,1.0,0);
				else
					glColor3f(0.5,0.5,0.5);
				glutSolidSphere(inner,40,40);		
			glPopMatrix();
		glPopMatrix();
      glPopMatrix();
// Draw shadows first
        glDisable(GL_DEPTH_TEST);
        glDisable(GL_LIGHTING);
        glPushMatrix();               
            glMultMatrixf(mShadowMatrix);     
            drawsphere(0);
        glPopMatrix();		
        glEnable(GL_LIGHTING);
        glEnable(GL_DEPTH_TEST);        

		
}
