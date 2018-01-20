#pragma once

#include "main_menu_bar.h"
#include "main_tool_bar.h"
#include "main_status_bar.h"

#include <wx/wx.h>

#include <wx/aui/aui.h>
#include <wx/treelist.h>
#include <wx/treectrl.h>
#include <wx/stc/stc.h>

#include "icon.xpm"

class CMainWindow : public wxFrame {
public:
    CMainWindow()
        : wxFrame(nullptr, wxID_ANY, "Siberia")
    {

        manager.SetManagedWindow(this);

        SetIcon(wxIcon(icon_xpm));

        SetMenuBar(new main_menu_bar_t);
        SetStatusBar(new main_status_bar_t(*this));


        manager.AddPane(new main_tool_bar_t(*this),
                        wxAuiPaneInfo().ToolbarPane().Top().Row(1));


        auto definition = new wxStyledTextCtrl(this);
        manager.AddPane(definition, wxAuiPaneInfo().Caption("Bitstream definition").CloseButton(false).MaximizeButton(true).MinimizeButton(true));

        auto ctrl = new wxAuiNotebook(this, wxID_ANY);
        ctrl->Freeze();

        auto panel  = new wxPanel(ctrl);
        auto tree = new wxTreeListCtrl(panel, wxID_ANY);
        tree->AppendColumn("Node",
                           wxCOL_WIDTH_AUTOSIZE,
                           wxALIGN_LEFT,
                           wxCOL_DEFAULT_FLAGS & ~wxCOL_SORTABLE);
        tree->AppendColumn("Name",
                           wxCOL_WIDTH_AUTOSIZE,
                           wxALIGN_RIGHT,
                        wxCOL_DEFAULT_FLAGS & ~wxCOL_SORTABLE);
        tree->AppendColumn("Type",
                           wxCOL_WIDTH_AUTOSIZE,
                           wxALIGN_RIGHT,
                           wxCOL_DEFAULT_FLAGS & ~wxCOL_SORTABLE);
        tree->AppendColumn("Size",
                           wxCOL_WIDTH_AUTOSIZE,
                           wxALIGN_RIGHT,
                           wxCOL_DEFAULT_FLAGS & ~wxCOL_SORTABLE);
        tree->AppendColumn("Value",
                           wxCOL_WIDTH_AUTOSIZE,
                           wxALIGN_RIGHT,
                           wxCOL_DEFAULT_FLAGS & ~wxCOL_SORTABLE);
        tree->AppendColumn("Offset",
                           wxCOL_WIDTH_AUTOSIZE,
                           wxALIGN_RIGHT,
                           wxCOL_DEFAULT_FLAGS & ~wxCOL_SORTABLE);

        auto root = tree->GetRootItem();
        auto item = tree->AppendItem(root, "transport_packet()");
        item = tree->AppendItem(item, "for( i = 0; i < N; ++i)");
        auto entry = tree->AppendItem(item, "[0]");
        tree->SetItemText(entry, 1, "payload");
        tree->SetItemText(entry, 2, "bslbf");
        tree->SetItemText(entry, 3, "8");
        tree->SetItemText(entry, 4, "0x64");
        tree->SetItemText(entry, 5, "0xA6");

        entry = tree->AppendItem(item, "[1]");
        tree->SetItemText(entry, 1, "payload");
        tree->SetItemText(entry, 2, "bslbf");
        tree->SetItemText(entry, 3, "8");
        tree->SetItemText(entry, 4, "0x64");
        tree->SetItemText(entry, 5, "0xA6");

        entry = tree->AppendItem(item, "[2]");
        tree->SetItemText(entry, 1, "payload");
        tree->SetItemText(entry, 2, "bslbf");
        tree->SetItemText(entry, 3, "8");
        tree->SetItemText(entry, 4, "0x44");
        tree->SetItemText(entry, 5, "0xA6");

        ctrl->AddPage(tree, "Structure");
        ctrl->AddPage(new wxTextCtrl(this, wxID_ANY), "Structure");
        ctrl->Thaw();

        manager.AddPane(ctrl, wxAuiPaneInfo().CenterPane().PaneBorder(false).CloseButton(false));

        manager.Update();
    }

    ~CMainWindow() {
        manager.UnInit();
    }

private:
    wxAuiManager manager;
};

