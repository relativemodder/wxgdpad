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

    auto titleLabel = new wxStaticText(
        panel, 
        panel->GetId(), 
        "\n                       GDPad Settings" // bruh alignment please help
    );
    titleLabel->SetFont(panel->GetFont().Scale(2));

    sizer->Add(titleLabel);

}


wxIMPLEMENT_APP(App);
