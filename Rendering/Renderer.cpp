

Renderer & Renderer::Initialize(int & appArgc, char* appArgs[],int majorVersion, int minorVersion){
    
    Renderer & instance = getInstance(false);

    glutInit(&appArgc, appArgs);
    glutInitContextVersion(majorVersion, minorVersion);

    instance.initialized = true;
    return instance;
}

Renderer & Renderer::getInstance(){
    Renderer & instance = getInstance(false);
    assert(instance.initialized && "Uninitialized Renderer");
    return instance;
}

Renderer & Renderer::getInstance(bool){
    static Renderer instance;
    return instance;
}