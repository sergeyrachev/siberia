#pragma once

#include <wx/statusbr.h>

class main_status_bar_t : public wxStatusBar {
public:
    explicit main_status_bar_t(wxWindow& parent) : wxStatusBar(&parent){

    }

};
