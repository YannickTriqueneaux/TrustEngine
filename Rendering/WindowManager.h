


class WindowManager
{
    REFLECTED_CLASS
private:
    WindowManager(){}
    WindowManager(WindowManager const &){}
    WindowManager & operator=(WindowManager const &){}
public:

    //singleton
    static WindowManager & getInstance();

    //methods
    Window & createNewWindow(Position const & position, Size const & size);

    std::map<std::string, Window> windowsList;

};

