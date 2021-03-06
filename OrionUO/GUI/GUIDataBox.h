﻿// MIT License
// Copyright (C) August 2016 Hotride

#pragma once

class CGUIDataBox : public CGUIPolygonal
{
public:
    CGUIDataBox();
    virtual ~CGUIDataBox();

    virtual void PrepareTextures();

    virtual bool EntryPointerHere();

    virtual bool Select() { return true; }
};
