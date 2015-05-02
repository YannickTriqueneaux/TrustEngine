

WindowManager & WindowManager::getInstance(){
    static WindowManager instance;
    return instance;


}

Window & WindowManager::createNewWindow(Position const & position, Size const & size){
   // windowsList[Guid::NewGuid().ToString()]
    return std::move(Window());
}