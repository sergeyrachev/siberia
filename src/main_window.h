#pragma once

#include "wx/wx.h"

class CMainWindow : public wxFrame
{
public:
    CMainWindow() : wxFrame(NULL, wxID_ANY, "Siberia"){

        auto menu_file = new wxMenu;

        auto menu_open = menu_file->Append(wxID_ANY, wxT("&Open..."));

        auto menu_help = new wxMenu;

        auto menubar = new wxMenuBar;
        menubar->Append(menu_file, wxT("&File"));
        menubar->Append(menu_help, wxT("&Help"));

        SetMenuBar(menubar);
    }


};
