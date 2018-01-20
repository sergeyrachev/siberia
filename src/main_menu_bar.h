#pragma once

#include <wx/menu.h>

class main_menu_bar_t : public wxMenuBar{
public:
    main_menu_bar_t() : wxMenuBar(){

        auto menu_file = new wxMenu;
        Append(menu_file, "&File");

        auto menu_help = new wxMenu;
        Append(menu_help, "&Help");

        menu_file->Append(wxID_OPEN);
        menu_file->AppendSeparator();
        menu_file->Append(wxID_EXIT);

        menu_help->Append(wxID_HELP);
    }
};
