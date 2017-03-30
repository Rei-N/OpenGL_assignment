//================================Humanoid Robot====================================
#include "OpenGLl.h";
void timer_walk(int);
void timer_kick(int);

//--------------------------------draw body functions-------------------------------
void head(){
   glPushMatrix();
   glColor3f (1.0, 0.0, 5.0);
   glRotatef(-90.0, 1.0, 0.0, 0.0);
   glRotatef(15.0, 0.0, 0.0, 1.0);
   glScalef(HEAD_HEIGHT, HEAD_HEIGHT, HEAD_RADIUS);
   gluSphere(h,1.0,10,10);
   glPopMatrix();
}

void neck(){
   glPushMatrix();
   glRotatef(-90.0, 1.0, 0.0, 0.0);
   gluCylinder(n,NECK_RADIUS, NECK_RADIUS, NECK_HEIGHT,10,10);
   glPopMatrix();
}

void torso(){
   glPushMatrix();
   glRotatef(-90.0, 1.0, 0.0, 0.0);
   gluCylinder(t,TORSO_RADIUS, TORSO_RADIUS, TORSO_HEIGHT,10,10);
   glPopMatrix();
}

void joint_point(){
   glPushMatrix();
   glScalef(JOINT_POINT_RADIUS, JOINT_POINT_HEIGHT, 
								JOINT_POINT_RADIUS);
   gluSphere(jp,1.0,10,10);
   glPopMatrix();
}

void left_upper_arm(){
   glPushMatrix();
   gluCylinder(lua,UPPER_ARM_RADIUS, UPPER_ARM_RADIUS, 
									UPPER_ARM_HEIGHT,10,10);
   glPopMatrix();
}

void left_lower_arm(){
   glPushMatrix();
   glRotatef(0.0, 1.0, 0.0, 0.0);
   gluCylinder(lla,LOWER_ARM_RADIUS, LOWER_ARM_RADIUS, 
									LOWER_ARM_HEIGHT,10,10);
   glPopMatrix();
}

void left_hand(){
   glPushMatrix();
   glRotatef(90.0, 1.0, 0.0, 0.0);
   glScalef(HAND_RADIUS, HAND_HEIGHT, HAND_RADIUS);
   gluSphere(lhnd,1.0,10,10);
   glPopMatrix();
}

void right_upper_arm(){
   glPushMatrix();
   gluCylinder(rua,UPPER_ARM_RADIUS, UPPER_ARM_RADIUS, 
									UPPER_ARM_HEIGHT,10,10);
   glPopMatrix();
}

void right_lower_arm(){
   glPushMatrix();
   gluCylinder(rla,LOWER_ARM_RADIUS, LOWER_ARM_RADIUS, 
									LOWER_ARM_HEIGHT,10,10);
   glPopMatrix();
}

void right_hand(){
   glPushMatrix();
   glRotatef(90.0, 1.0, 0.0, 0.0);
   glScalef(HAND_RADIUS, HAND_HEIGHT, HAND_RADIUS);
   gluSphere(rhnd,1.0,10,10);
   glPopMatrix();
}

void left_upper_leg(){
   glPushMatrix();
   glRotatef(-90.0, 1.0, 0.0, 0.0);
   gluCylinder(lul,UPPER_LEG_RADIUS, UPPER_LEG_RADIUS, 
									UPPER_LEG_HEIGHT,10,10);
   glPopMatrix();
}

void left_lower_leg(){
   glPushMatrix();
   glRotatef(-90.0, 1.0, 0.0, 0.0);
   gluCylinder(lll,LOWER_LEG_RADIUS, LOWER_LEG_RADIUS, 
									LOWER_LEG_HEIGHT,10,10);
   glPopMatrix();
}

void left_foot(){
   glPushMatrix();
   glRotatef(90.0, 1.0, 0.0, 0.0);
   glScalef(FOOT_RADIUS, FOOT_HEIGHT, FOOT_RADIUS);
   gluSphere(lft,1.0,10,10);
   glPopMatrix();
}

void right_upper_leg(){
   glPushMatrix();
   glRotatef(-90.0, 1.0, 0.0, 0.0);
   gluCylinder(rul,UPPER_LEG_RADIUS, UPPER_LEG_RADIUS, 
									UPPER_LEG_HEIGHT,10,10);
   glPopMatrix();
}

void right_lower_leg(){
   glPushMatrix();
   glRotatef(-90.0, 1.0, 0.0, 0.0);
   gluCylinder(rll,LOWER_LEG_RADIUS, LOWER_LEG_RADIUS, 
									LOWER_LEG_HEIGHT,10,10);
   glPopMatrix();
}

void right_foot(){
   glPushMatrix();
   glRotatef(90.0, 1.0, 0.0, 0.0);
   glScalef(FOOT_RADIUS, FOOT_HEIGHT, FOOT_RADIUS);
   gluSphere(rft,1.0,10,10);
   glPopMatrix();
}

//--------------------------------Display function--------------------------------
void myDisplay(void)
{
	glClearColor(1, 1, 0.5, 0.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(0.0, 0.0, 0.0);
	glColor3ub(0, 0, 0);

	glBindTexture(GL_TEXTURE_2D, texture2);
    glRotatef(theta[0], 0.0, 1.0, 0.0);
    torso();
	glPushMatrix();

	glBindTexture(GL_TEXTURE_2D, texture4);
	glTranslatef(0,TORSO_HEIGHT, 0.0);
	neck();

	glBindTexture(GL_TEXTURE_2D, texture1);
	glTranslatef(0.0, NECK_HEIGHT+0.5*HEAD_HEIGHT, 0.0);
	glRotatef(theta[1], 1.0, 0.0, 0.0);
    glRotatef(theta[2], 0.0, 1.0, 0.0);
    head();

	glPopMatrix();//add JOINT_POINT_
    glPushMatrix();//add JOINT_POINT_

	glBindTexture(GL_TEXTURE_2D, texture4);
	glTranslatef(-0.85*(TORSO_RADIUS+JOINT_POINT_RADIUS), 
									0.9*TORSO_HEIGHT, 0.0);
	joint_point();

	glBindTexture(GL_TEXTURE_2D, texture4);
	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(theta[3], 1.0, 0.0, 0.0);
	glRotatef(theta[11], 0.0, 0.0, 1.0);
    left_upper_arm();

	glBindTexture(GL_TEXTURE_2D, texture4);
	glTranslatef(0.0, 0.0,UPPER_ARM_HEIGHT);
	joint_point();

	glBindTexture(GL_TEXTURE_2D, texture4);
    glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT, 0.0);
    glRotatef(theta[4], 1.0, 0.0, 0.0);
    left_lower_arm();

	glBindTexture(GL_TEXTURE_2D, texture4);
	glTranslatef(0.0, 0.0, LOWER_ARM_HEIGHT);
	left_hand();

    glPopMatrix();
    glPushMatrix();

	glBindTexture(GL_TEXTURE_2D, texture4);
    glTranslatef(0.85*(TORSO_RADIUS+JOINT_POINT_RADIUS), 
									0.9*TORSO_HEIGHT, 0.0);
	joint_point();

	glBindTexture(GL_TEXTURE_2D, texture4);
    glTranslatef(0.0, 0.0, 0.0);
    glRotatef(theta[5], 1.0, 0.0, 0.0);
	glRotatef(theta[12], 0.0, 0.0, 1.0);
    right_upper_arm();

	glBindTexture(GL_TEXTURE_2D, texture4);
    glTranslatef(0.0, 0.0, UPPER_ARM_HEIGHT);
	joint_point();

	glBindTexture(GL_TEXTURE_2D, texture4);
    glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT, 0.0);
    glRotatef(theta[6], 1.0, 0.0, 0.0);
    right_lower_arm();

	glBindTexture(GL_TEXTURE_2D, texture4);
	glTranslatef(0.0, 0.0, LOWER_ARM_HEIGHT);
	right_hand();

    glPopMatrix();
    glPushMatrix();
	
	glBindTexture(GL_TEXTURE_2D, texture3);
	glTranslatef(-(TORSO_RADIUS-JOINT_POINT_RADIUS), 
							-0.15*JOINT_POINT_HEIGHT, 0.0);
	joint_point();

	glBindTexture(GL_TEXTURE_2D, texture3);
	glTranslatef(0, 0.1*JOINT_POINT_HEIGHT, 0.0);
    glRotatef(theta[7], 1.0, 0.0, 0.0);
	glRotatef(theta[13], 0.0, 0.0, 1.0);
    left_upper_leg();

	glBindTexture(GL_TEXTURE_2D, texture4);
	glTranslatef(0.0, UPPER_LEG_HEIGHT, 0.0);
	joint_point();

	glBindTexture(GL_TEXTURE_2D, texture4);
    glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT, 0.0);
    glRotatef(theta[8], 1.0, 0.0, 0.0);
    left_lower_leg();

	glBindTexture(GL_TEXTURE_2D, texture4);
    glTranslatef(0.0, LOWER_LEG_HEIGHT, -0.5*FOOT_HEIGHT);
	glRotatef(theta[15], 1.0, 0.0, 0.0);
	left_foot();

    glPopMatrix();
    glPushMatrix();

	glBindTexture(GL_TEXTURE_2D, texture3);
    glTranslatef(TORSO_RADIUS-JOINT_POINT_RADIUS, 
							-0.15*JOINT_POINT_HEIGHT, 0.0);
	joint_point();

	glBindTexture(GL_TEXTURE_2D, texture3);
	glTranslatef(0, 0.1*JOINT_POINT_HEIGHT, 0.0);
    glRotatef(theta[9], 1.0, 0.0, 0.0);
	glRotatef(theta[14], 0.0, 0.0, 1.0);
    right_upper_leg();

	glBindTexture(GL_TEXTURE_2D, texture4);
	glTranslatef(0.0, UPPER_LEG_HEIGHT, 0.0);
	joint_point();

	glBindTexture(GL_TEXTURE_2D, texture4);
    glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT, 0.0);
    glRotatef(theta[10], 1.0, 0.0, 0.0);
    right_lower_leg();
	
	glBindTexture(GL_TEXTURE_2D, texture4);
	glTranslatef(0.0, LOWER_LEG_HEIGHT, -0.5*FOOT_HEIGHT);
	glRotatef(theta[16], 1.0, 0.0, 0.0);
	right_foot();
    
	glPopMatrix();
	
    glFlush();
    glutSwapBuffers();
}

//--------------------------------Keyboard control function-----------------------
void keyboard(unsigned char key, int x, int y)
{
	if(key=='q') {choise=2;}		// Head horiz
	if(key=='a') {choise=1;}		// Head vert

	if(key=='w') {choise=3;}	//left arm horiz
	if(key=='s') {choise=11;}		//left arm vert

	if(key=='e') {choise=5;}	//right arm horiz
	if(key=='d') {choise=12;}		//right arm horiz

	if(key=='r') {choise=7;}		//left leg vert
	if(key=='f') {choise=13;}	//left leg horiz

	if(key=='t') {choise=9;}		//right leg horiz
	if(key=='g') {choise=14;}	//right leg vert

	if(key=='z') {choise=0;}		//torso

	if(key=='x') {choise=4;}		//left_lower_arm

	if(key=='c') {choise=6;}		//right_lower_arm

	if(key=='v') {choise=8;}		//left_lower_leg

	if(key=='b') {choise=10;}	//right_lowerleg

	if(key==',') {choise=15;}	//left_foot

	if(key=='.') {choise=16;}	//right_foot
	
	if(key=='m') {glutTimerFunc(100,timer_walk,0);}	//animation walk

	if(key=='n') {
		old_thetaW3=theta[3];
		old_thetaX4=theta[4];
		old_thetaE5=theta[5];
		old_thetaC6=theta[6];
		old_thetaS11=theta[11];
		old_thetaD12=theta[12];

		theta[3]=0;	// 0-30
		theta[4]=0;	// 0
		theta[11]=-15;	// 0
		theta[5]=60;	// 0
		theta[6]=-120;	// 0
		theta[12]=15;	// 0
		glutTimerFunc(200,timer_kick,0);/*glutTimerFunc(100,timer_kick,0);*/
	}	//animation kick

	if(key=='9') {
		theta[choise] += 5.0;
		if( theta[choise] > 360.0 ) theta[choise] -= 360.0;
		glutPostRedisplay();
	}
	if(key=='0') {
		theta[choise] -= 5.0;
		if( theta[choise] < 360.0 ) theta[choise] += 360.0;
		glutPostRedisplay();
	}
}

//--------------------------------Display area for mouse conrol-------------------
void area_update(area* area, int update){
    if (selection != area->id)
	return;

    area->value += update * area->step;

    if (area->value < area->min)
	area->value = area->min;
    else if (area->value > area->max) 
	area->value = area->max;

}

int area_hit(area* area, int x, int y){
    if ((x > 0 && x < WIN_WIDTH) &&
		(y > 0 && y < WIN_HEIGHT))
	return area->id;
    return 0;
}

int old_y, old_x;

void menu(int id) {
   if(id <3 ) m_choise=id;
   if(id == 3 ) exit(1);
}

void mouse(int button, int state, int x, int y)
{
    selection = 0;
	if (button==GLUT_LEFT_BUTTON && state == GLUT_DOWN 
									&& (m_choise==0||m_choise==2)) {
		selection += area_hit(&translation[0], x, y);
		if (m_choise==0) selection += area_hit(&translation[0], x, y);
		if (m_choise==2) selection += area_hit(&translation[3], x, y);
		old_x = x;
		redisplay_all();
    }
	if (button==GLUT_RIGHT_BUTTON && state == GLUT_DOWN 
					&& ((m_choise==0||m_choise==1)||m_choise==2)) {
		if (m_choise==0) selection += area_hit(&translation[1], x, y);
		if (m_choise==1) selection += area_hit(&translation[2], x, y);
		if (m_choise==2) selection += area_hit(&translation[4], x, y);
		old_y = y;
		redisplay_all();
    } 
}

void pressed_mouse(int x, int y)
{
    area_update(&translation[0], x-old_x);
    area_update(&translation[1], old_y-y);
    area_update(&translation[2], old_y-y);
	area_update(&translation[3], x-old_x);
    area_update(&translation[4], old_y-y);
	old_y = y;
	old_x = x;

	redisplay_all();
}
//--------------------------------Reshape & redisplay functions--------------------
void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-30.0, 30.0, -30.0 * (GLfloat) h / (GLfloat) w,
            30.0 * (GLfloat) h / (GLfloat) w, -200, 200);
    else
       glOrtho(-30.0 * (GLfloat) w / (GLfloat) h,
            30.0 * (GLfloat) w / (GLfloat) h, -30.0, 30.0, -200, 200);

	gluPerspective(1.0, (float)w/h, 2.0, 1.0);
    gluLookAt(translation[3].value, translation[4].value, eye[2], 
						at[0], at[1], at[2], up[0], up[1],up[2]);
	glTranslatef(translation[0].value, translation[1].value,
										translation[2].value);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void redisplay_all(void) {
    myReshape(WIN_WIDTH, WIN_HEIGHT);
    glutPostRedisplay();
}

//--------------------------------Animation timer functions-------------------------
void timer_walk(int) 
{
		if(flag1) {
			theta[3] += 5.0;
		}
		else {
			theta[3] -= 5.0;
		}
		if(theta[3] >= 110.0) flag1 = false;
		if(theta[3] <= 70.0)  flag1 = true;
		
		if(flag2) {
		theta[5] += 5.0;
		}
		else {
			theta[5] -= 5.0;
		}
		if(theta[5] >= 110.0) flag2 = false;
		if(theta[5] <= 70.0)  flag2 = true;
		
		if(flag3) {
			theta[9] += 5.0;
		}
		else {
			theta[9] -= 5.0;
		}
		if(theta[9] >= 200.0) flag3 = false;
		if(theta[9] <= 160.0)  flag3 = true;
		
		if(flag4) {
			theta[7] += 5.0;
		}
		else {
			theta[7] -= 5.0;
		}
		if(theta[7] >= 200.0) flag4 = false;
		if(theta[7] <= 160.0)  flag4 = true;
		
		if(hflag) {
			theta[2] += 5.0;
		}
		else {
			theta[2] -= 5.0;
		}
		if(theta[2] >= 30.0) hflag = false;
		if(theta[2] <= -30.0) hflag = true;
		
		glutPostRedisplay();
	    glutTimerFunc(100,timer_walk,0);
}
void timer_kick(int)
{
	if(flag1) {
		theta[3] -= 15.0;
	}
	else {
		theta[3] += 15.0;
	}
	if(theta[3] >= 60) flag1 = true;
	if(theta[3] <= 0)  flag1 = false;	// 0-45

	if(flag2) {
		theta[4] -= 30;
	}
	else {
		theta[4] += 30;
	}
	if(theta[4] >= 0) flag2 = true;
	if(theta[4] <= -120)  flag2 = false;
	theta[11]=-15;	// 0
	
	if(flag3) {
		theta[5] -= 15.0;
	}
	else {
		theta[5] += 15.0;
	}
	if(theta[5] >= 60) flag3 = true;
	if(theta[5] <= 0)  flag3 = false;	// 0-45
	
	if(flag4) {
		theta[6] -= 30;
	}
	else {
		theta[6] += 30;
	}
	if(theta[6] >= 0) flag4 = true;
	if(theta[6] <= -120)  flag4 = false;
	
	if(flag5) {
		theta[9] += 10.0;
	}
	else {
		theta[9] -= 10.0;
	}
	if(theta[9] >= 200.0) flag5 = false;
	if(theta[9] <= 160.0)  flag5 = true;
	
	if(flag6) {
		theta[7] += 10.0;
	}
	else {
		theta[7] -= 10.0;
	}
	if(theta[7] >= 200.0) flag6 = false;
	if(theta[7] <= 160.0)  flag6 = true;

	glutPostRedisplay();
	glutTimerFunc(200,timer_kick,0);
}

//--------------------------------Initialization function----------------------------
void myInit()
{
        GLfloat mat_specular[]={1.0, 1.0, 1.0, 1.0};
        GLfloat mat_diffuse[]={1.0, 1.0, 1.0, 1.0};
        GLfloat mat_ambient[]={1.0, 1.0, 1.0, 1.0};
        GLfloat mat_shininess={100.0};
        GLfloat light_ambient[]={0.0, 0.0, 0.0, 1.0};
        GLfloat light_diffuse[]={1.0, 1.0, 1.0, 1.0};
        GLfloat light_specular[]={1.0, 1.0, 1.0, 1.0};
        GLfloat light_position[]={10.0, 10.0, 10.0, 0.0};

        glLightfv(GL_LIGHT0, GL_POSITION, light_position);
        glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

        glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
        glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);

        glShadeModel(GL_SMOOTH);
        glEnable(GL_LIGHTING); 
        glEnable(GL_LIGHT0);
        glDepthFunc(GL_LEQUAL);
        glEnable(GL_DEPTH_TEST); 

		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		photo_body = auxDIBImageLoadA("body.bmp");
		photo_image = auxDIBImageLoadA("photom.bmp");
		photo_legs = auxDIBImageLoadA("shorts.bmp");
		skin = auxDIBImageLoadA("skin.bmp");
		
		glGenTextures(1, &texture2);
		glGenTextures(1, &texture1);
		glGenTextures(1, &texture3);
		glGenTextures(1, &texture3);

		glBindTexture (GL_TEXTURE_2D, texture2);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, 
					photo_body->sizeX,
					photo_body->sizeY,
					GL_RGB, GL_UNSIGNED_BYTE,
					photo_body->data);

		glBindTexture (GL_TEXTURE_2D, texture1);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, 
					photo_image->sizeX,
					photo_image->sizeY,
					GL_RGB, GL_UNSIGNED_BYTE,
					photo_image->data);

		glBindTexture (GL_TEXTURE_2D, texture3);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, 
					photo_legs->sizeX,
					photo_legs->sizeY,
					GL_RGB, GL_UNSIGNED_BYTE,
					photo_legs->data);

		glBindTexture (GL_TEXTURE_2D, texture4);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, 
					skin->sizeX,
					skin->sizeY,
					GL_RGB, GL_UNSIGNED_BYTE,
					skin->data);

/* allocate quadrics with filled drawing style */
        h=gluNewQuadric();
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_TEXTURE_2D);
		gluQuadricTexture(h, GL_TRUE);
		gluQuadricDrawStyle(h, GLU_FILL);
		
		n=gluNewQuadric();
		gluQuadricTexture(n, GL_TRUE);
		gluQuadricDrawStyle(n, GLU_FILL);

		t=gluNewQuadric();
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_TEXTURE_2D);
		gluQuadricTexture(t, GL_TRUE);
        gluQuadricDrawStyle(t, GLU_FILL);

		jp=gluNewQuadric();
		gluQuadricTexture(jp, GL_TRUE);
		gluQuadricDrawStyle(jp, GLU_FILL);

        lua=gluNewQuadric();
		gluQuadricTexture(lua, GL_TRUE);
    	gluQuadricDrawStyle(lua, GLU_FILL);

        lla=gluNewQuadric();
		gluQuadricTexture(lla, GL_TRUE);
        gluQuadricDrawStyle(lla, GLU_FILL);

        lhnd=gluNewQuadric();
		gluQuadricTexture(lhnd, GL_TRUE);
		gluQuadricDrawStyle(lhnd, GLU_FILL);

		rhnd=gluNewQuadric();
		gluQuadricTexture(rhnd, GL_TRUE);
		gluQuadricDrawStyle(rhnd, GLU_FILL);

		rft=gluNewQuadric();
		gluQuadricTexture(rft, GL_TRUE);
		gluQuadricDrawStyle(rft, GLU_FILL);

		lft=gluNewQuadric();
		gluQuadricTexture(lft, GL_TRUE);
		gluQuadricDrawStyle(lft, GLU_FILL);

		rua=gluNewQuadric();
		gluQuadricTexture(rua, GL_TRUE);
        gluQuadricDrawStyle(rua, GLU_FILL);

        rla=gluNewQuadric();
		gluQuadricTexture(rla, GL_TRUE);
        gluQuadricDrawStyle(rla, GLU_FILL);

        lul=gluNewQuadric();
		gluQuadricTexture(lul, GL_TRUE);
        gluQuadricDrawStyle(lul, GLU_FILL);

        lll=gluNewQuadric();
		gluQuadricTexture(lll, GL_TRUE);
        gluQuadricDrawStyle(lll, GLU_FILL);

        rul=gluNewQuadric();
		gluQuadricTexture(rul, GL_TRUE);
        gluQuadricDrawStyle(rul, GLU_FILL);

        rll=gluNewQuadric();
		gluQuadricTexture(rll, GL_TRUE);
        gluQuadricDrawStyle(rll, GLU_FILL);
}

void main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WIN_WIDTH,WIN_HEIGHT);
	glutInitWindowPosition(50, 50);
    glutCreateWindow("Humanoid");
    myInit();
	glutReshapeFunc(myReshape);
    glutDisplayFunc(myDisplay);
	glutMotionFunc(pressed_mouse);
	glutMouseFunc(mouse);
	glutCreateMenu(menu);
	glutAddMenuEntry("view_hor/vert", 0);
    glutAddMenuEntry("view_zoom_in/out", 1);
	glutAddMenuEntry("view_lft-rgt/up-dow", 2);
	glutAddMenuEntry("quit", 3);
    glutAttachMenu(GLUT_MIDDLE_BUTTON);
	glutKeyboardFunc(keyboard);
	redisplay_all();
    glutMainLoop();
}
