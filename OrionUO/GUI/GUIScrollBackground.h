﻿// MIT License
// Copyright (C) August 2016 Hotride

#pragma once

class CGUIScrollBackground : public CBaseGUI
{
public:
    //!Высота
    int Height = 0;

    //!Смещение по оси X
    int OffsetX = 0;

    //!Смещение нижней части по оси X
    int BottomOffsetX = 0;

    //!Ширина
    int Width = 0;

    //!Рабочая область
    Wisp::CRect WorkSpace = Wisp::CRect();

    CGUIScrollBackground(int serial, uint16_t graphic, int x, int y, int height);
    virtual ~CGUIScrollBackground();

    //!Обновить высоту
    void UpdateHeight(int height);

    virtual Wisp::CSize GetSize() { return Wisp::CSize(Width, Height); }

    virtual void PrepareTextures();

    virtual void Draw(bool checktrans = false);
    virtual bool Select();
};
