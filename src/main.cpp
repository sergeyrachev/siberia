#include "main.h"

#include <memory>

#include "wx/wx.h"

class CMainWindow : public wxFrame
{
public:
    CMainWindow() : wxFrame(NULL, wxID_ANY, "Siberia"){

    }
};


class CGuiApp : public wxApp
{
private:
    virtual bool OnInit(){
        if ( !wxApp::OnInit() ) {
            return false;
        }

        auto main_window = new CMainWindow;
        return main_window->Show();
    }
};

IMPLEMENT_APP(CGuiApp)
