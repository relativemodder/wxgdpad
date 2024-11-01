#pragma once
#include <wx/wx.h>
#include <iostream>


class App : public wxApp {
public:
    virtual bool OnInit(); // Виртуальная функция иницилизации.
};


class Frame : wxFrame {
public:

    Frame();
    void ShowPublic(bool show = true);
};