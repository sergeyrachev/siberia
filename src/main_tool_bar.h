#pragma once

#include <wx/wx.h>
#include <wx/aui/auibar.h>
#include <wx/artprov.h>

class main_tool_bar_t : public wxAuiToolBar{
public:
    main_tool_bar_t(wxWindow& parent)
        : wxAuiToolBar(&parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_OVERFLOW){

        SetToolBitmapSize(wxSize(16, 16));
        AddTool(wxID_ANY, "Open...", wxArtProvider::GetBitmap(wxART_FILE_OPEN));
        Realize();
    }
};
