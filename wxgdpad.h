#pragma once
#include <wx/wx.h>
#include <iostream>


class App : public wxApp {
public:
    virtual bool OnInit(); // Виртуальная функция иницилизации.
};

class Frame : wxFrame {
public:
    wxPanel* m_mainPanel;
    wxStaticText* m_prsValueLabel;
    wxSlider* m_pollingRateSlider;

    static Frame* GetShared();
    static void OnPRSChange(wxScrollEvent& event);

    Frame();
    void DrawTitle();
    void DrawPollingRateSlider();
    void DrawApplyButton();
    void ShowPublic(bool show = true);
};

Frame* g_frameInstance;