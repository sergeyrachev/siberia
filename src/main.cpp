#include "main.h"

#include "main_window.h"

#include "wx/wx.h"



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
