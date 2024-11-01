﻿#pragma once
#include <wx/wx.h>
#include <iostream>
#include <fmt/format.h>


class App : public wxApp {
public:
    virtual bool OnInit();
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

inline Frame* g_frameInstance;