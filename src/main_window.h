#pragma once

#include <wx/wx.h>

#include <wx/aui/aui.h>
#include <wx/treelist.h>
#include <wx/stc/stc.h>

class CMainWindow : public wxFrame {
public:
    CMainWindow() : wxFrame(NULL, wxID_ANY, "Siberia") {

        manager.SetManagedWindow(this);

        auto menu_file = new wxMenu;
        auto menu_open = menu_file->Append(wxID_ANY, wxT("&Open..."));
        auto menu_help = new wxMenu;

        auto menubar = new wxMenuBar;
        menubar->Append(menu_file, wxT("&File"));
        menubar->Append(menu_help, wxT("&Help"));
        SetMenuBar(menubar);

        auto structure = new wxTreeListCtrl(this, wxID_ANY);
        manager.AddPane(structure, wxLEFT, "Structure");

        auto definition = new wxStyledTextCtrl(this);
        manager.AddPane(definition, wxCENTER, "Definition");

        manager.Update();
    }

    ~CMainWindow() {
        manager.UnInit();
    }

private:
    wxAuiManager manager;
};
