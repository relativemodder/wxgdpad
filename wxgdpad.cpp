#include "wxgdpad.h"

bool App::OnInit() {
    Frame* frame = new Frame();
    frame->ShowPublic(true);
    return true;
}


void Frame::ShowPublic(bool show) {
    Show(show);
}


Frame::Frame()
    : wxFrame(nullptr, wxID_ANY, "wxGDPad")
{
    SetMinSize({ 500, 600 });
    SetMaxSize({ 500, 600 });

    wxPanel* panel = new wxPanel(this);
    auto sizer = new wxBoxSizer(wxVERTICAL);
    
    panel->SetSizer(sizer);

    auto btn1 = new wxButton(panel, panel->GetId(), "Bruh");
    auto btn2 = new wxButton(panel, panel->GetId(), "Bruh2");

    btn1->Bind(wxEVT_LEFT_UP, [&](wxMouseEvent& event) {
        wxMessageBox(wxString::Format("The frame is clicked at {x=%d, y=%d}", event.GetPosition().x, event.GetPosition().y), "FrameClick", wxOK);
    });

    sizer->Add(btn1);
    sizer->Add(btn2);
}


wxIMPLEMENT_APP(App);
