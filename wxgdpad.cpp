#include "wxgdpad.h"
#include <fmt/format.h>

bool App::OnInit() {
    Frame* frame = new Frame();
    frame->ShowPublic(true);
    return true;
}


void Frame::ShowPublic(bool show) {
    Show(show);
}


Frame* Frame::GetShared() {
    return g_frameInstance;
}


void Frame::OnPRSChange(wxScrollEvent& event) {
    auto value = event.GetInt();
    int roundedValue = round((double)value / 1000) * 1000;

    Frame::GetShared()->m_prsValueLabel->SetLabelText(std::to_string(roundedValue));
    Frame::GetShared()->m_pollingRateSlider->SetValue(roundedValue);
}


void Frame::DrawPollingRateSlider() {
    m_prsValueLabel = new wxStaticText(
        m_mainPanel,
        m_mainPanel->GetId(),
        "8000"
    );

    m_prsValueLabel->SetFont(m_mainPanel->GetFont().Scale(1.3));
    m_prsValueLabel->SetPosition({ 420, 120 });

    auto prsLabel = new wxStaticText(
        m_mainPanel,
        m_mainPanel->GetId(),
        "Polling Rate"
    );

    prsLabel->SetFont(m_mainPanel->GetFont().Scale(1.3));
    prsLabel->SetSize({ 200, 28 });
    prsLabel->SetPosition({ 30, 80 });

    m_pollingRateSlider = new wxSlider(
        m_mainPanel,
        m_mainPanel->GetId(),
        8000, 1000, 8000
    );

    m_pollingRateSlider->Bind(wxEVT_SCROLL_THUMBRELEASE, Frame::OnPRSChange);

    m_pollingRateSlider->SetSize({ 380, 30 });
    m_pollingRateSlider->SetPosition({ 20, 120 });


}


void Frame::DrawTitle() {
    auto titleLabel = new wxStaticText(
        m_mainPanel,
        m_mainPanel->GetId(),
        "GDPad Settings"
    );
    titleLabel->SetFont(m_mainPanel->GetFont().Scale(2).MakeBold());
    titleLabel->SetSize({ 300, 40 });
    titleLabel->SetPosition({ 160, 10 }); // bruh alignment please help
}


void Frame::DrawApplyButton() {
    auto applyButton = new wxButton(
        m_mainPanel, m_mainPanel->GetId(),
        "Apply"
    );
    applyButton->SetPosition({ 15, 520 });
    applyButton->SetSize({ 454, 30 });
}


Frame::Frame()
    : wxFrame(nullptr, wxID_ANY, "wxGDPad")
{
    g_frameInstance = this;

    SetMinSize({ 500, 600 });
    SetMaxSize({ 500, 600 });

    m_mainPanel = new wxPanel(this);
    m_mainPanelSizer = new wxBoxSizer(wxVERTICAL);
    
    m_mainPanel->SetSizer(m_mainPanelSizer);

    DrawTitle();
    DrawPollingRateSlider();
    DrawApplyButton();
}


wxIMPLEMENT_APP(App);
