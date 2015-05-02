

class Renderer
{
    Renderer(){}
    Renderer(Renderer const &){}
    Renderer & operator=(Renderer const &){}
public:
    
    static Renderer & Initialize(int & appArgc, char* appArgs[], int majorVersion = 3, int minorVersion = 0);
    static Renderer & getInstance();
private:
    static Renderer & getInstance(bool);

    bool initialized = false;
};

