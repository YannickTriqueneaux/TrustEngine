
#include "..\Rendering\public.h"


namespace MyNameSpace2{

    class ParentClass{
        REFLECTED_CLASS
    public:
        int intvalue;
    };
    class SuperClass{
        REFLECTED_CLASS
    public:
        SuperClass(){}
        SuperClass(int val) : intvalue(val){}
        int intvalue = 5;
        float floatvalue = 56.0f;
        int * valuePtr = nullptr;
        std::string stringvalue;
        std::vector<int> vectorint;
        std::vector<ParentClass> vectorObject;
        std::vector<std::vector<ParentClass>> vector2Object;
        std::vector<std::vector<std::string>> vectorstring;
        std::map<std::string, std::map<int, ParentClass>> supermapfield;
        std::pair<int, int> superpair;
    };
    //
    class ChildClass : public ParentClass {
        REFLECTED_SUPER_CLASS(ParentClass)
    public:
        int secondValue;
        std::string superstring;
    };
    //
    template<typename T>
    class TempClass : public ChildClass {
        REFLECTED_SUPER_TEMPLATE_CLASS(ChildClass)
    public:
        TempClass(){}
        T value;
        TEMPLATE_CLASS_BEGIN(MyNameSpace2::TempClass, T)
            DEFINE_FIELD(value);
        DEFINE_CLASS_END
    };

    class TemplChild : public TempClass < int > {
        REFLECTED_SUPER_CLASS(TempClass<int>)
    public:
        TemplChild(){}
        std::string souris;
    };

};

DEFINE_CLASS_BEGIN(MyNameSpace2::SuperClass)
DEFINE_FIELD(intvalue);
DEFINE_FIELD(floatvalue);
DEFINE_FIELD(stringvalue);
DEFINE_FIELD(vectorint);
DEFINE_FIELD(vectorObject);
DEFINE_FIELD(vector2Object);
DEFINE_FIELD(vectorstring);
DEFINE_FIELD(supermapfield);
DEFINE_FIELD(superpair);
DEFINE_CLASS_END

DEFINE_CLASS_BEGIN(MyNameSpace2::ParentClass)
DEFINE_FIELD(intvalue);
DEFINE_CLASS_END
//
DEFINE_CLASS_BEGIN(MyNameSpace2::ChildClass)
DEFINE_FIELD(secondValue);
DEFINE_FIELD(superstring);
DEFINE_CLASS_END

DEFINE_CLASS_BEGIN(MyNameSpace2::TemplChild)
DEFINE_FIELD(souris);
DEFINE_CLASS_END

#include <GL\freeglut.h>





void update();
/*
Pre Condition:
-None
Post Condition:
-Does per frame logic
Side Effects:
-None
*/

void render();
/*
Pre Condition:
-A valid OpenGL context
-Active modelview matrix
Post Condition:
-Renders the scene
Side Effects:
-Clears the color buffer
-Swaps the front/back buffer
*/

void runMainLoop(int val);
/*
Pre Condition:
-Initialized freeGLUT
Post Condition:
-Calls the main loop functions and sets itself to be called back in 1000 / SCREEN_FPS milliseconds
Side Effects:
-Sets glutTimerFunc
*/

void handleKeys(unsigned char key, int x, int y);



void main(int argc, char* args[]){

    glutInit(&argc, args);


    glutInitContextVersion(3, 0);

    //Create Double Buffered Window
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(500  , 500);
    glutCreateWindow("OpenGL");


    //Init
    glViewport(0, 0, GLsizei(500), GLsizei(500));

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 500, 500, 0.0, 1.0, -1.0);


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    glPushMatrix();

    //Initialize clear color
    glClearColor(0.f, 0.f, 0.f, 1.f);

    //Check for error
    GLenum error = glGetError();
    if (error != GL_NO_ERROR)
    {
        printf("Error initializing OpenGL! %s\n", gluErrorString(error));
        return;
    }
    //Int


    //Set keyboard handler
    glutKeyboardFunc(handleKeys);

    //Set rendering function
    glutDisplayFunc(render);

    //Set main loop
    glutTimerFunc(1000 / 60, runMainLoop, 0);

    //Start GLUT main loop
    glutMainLoop();

    /*
    using namespace MyNameSpace2;
    getDescriptorOf<ParentClass>();
    getDescriptorOf<SuperClass>();
    getDescriptorOf<ChildClass>();
    getDescriptorOf<TempClass<SuperClass>>();
    getDescriptorOf<TemplChild>();
    DescriptorRegistry::printDescriptorList();
    */
}

GLfloat gCameraX = 0.f, gCameraY = 0.f;

void update()
{

}

void render()
{
    //Clear color buffer
    glClear(GL_COLOR_BUFFER_BIT);

    //Pop default matrix onto current matrix
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();

    //Move camera to position
    glTranslatef(-gCameraX, -gCameraY, 0.f);

    //Save default matrix again
    glPushMatrix();

    //Move to center of the screen
    GLfloat SCREEN_WIDTH = 500.0f, SCREEN_HEIGHT = 500.0f;
    glTranslatef(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f, 0.f);

    //Red quad
    glBegin(GL_QUADS);
    glColor3f(1.f, 0.f, 0.f);
    glVertex2f(-SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f);
    glVertex2f(SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f);
    glVertex2f(SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f);
    glVertex2f(-SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f);
    glEnd();

    //Move to the right of the screen
    glTranslatef(SCREEN_WIDTH, 0.f, 0.f);

    //Green quad
    glBegin(GL_QUADS);
    glColor3f(0.f, 1.f, 0.f);
    glVertex2f(-SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f);
    glVertex2f(SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f);
    glVertex2f(SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f);
    glVertex2f(-SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f);
    glEnd();

    //Move to the lower right of the screen
    glTranslatef(0.f, SCREEN_HEIGHT, 0.f);

    //Blue quad
    glBegin(GL_QUADS);
    glColor3f(0.f, 0.f, 1.f);
    glVertex2f(-SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f);
    glVertex2f(SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f);
    glVertex2f(SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f);
    glVertex2f(-SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f);
    glEnd();

    //Move below the screen
    glTranslatef(-SCREEN_WIDTH, 0.f, 0.f);

    //Yellow quad
    glBegin(GL_QUADS);
    glColor3f(1.f, 1.f, 0.f);
    glVertex2f(-SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f);
    glVertex2f(SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f);
    glVertex2f(SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f);
    glVertex2f(-SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f);
    glEnd();

    //Update screen
    glutSwapBuffers();
}

void runMainLoop(int val)
{
    //Frame logic
    update();
    render();

    //Run frame one more time
    glutTimerFunc(1000 / 60, runMainLoop, val);
}

void handleKeys(unsigned char key, int x, int y)
{
    //If the user pressed w/a/s/d, change camera position
    if (key == 'w')
    {
        gCameraY -= 16.f;
    }
    else if (key == 's')
    {
        gCameraY += 16.f;
    }
    else if (key == 'a')
    {
        gCameraX -= 16.f;
    }
    else if (key == 'd')
    {
        gCameraX += 16.f;
    }
}