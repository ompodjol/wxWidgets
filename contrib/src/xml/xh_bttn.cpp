/////////////////////////////////////////////////////////////////////////////
// Name:        xh_bttn.cpp
// Purpose:     XML resource for buttons
// Author:      Vaclav Slavik
// Created:     2000/03/05
// RCS-ID:      $Id$
// Copyright:   (c) 2000 Vaclav Slavik
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////
 
#ifdef __GNUG__
#pragma implementation "xh_bttn.h"
#endif

// For compilers that support precompilation, includes "wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#include "wx/xml/xh_bttn.h"
#include "wx/button.h"


wxObject *wxButtonXmlHandler::DoCreateResource()
{ 
    wxButton *button = new wxButton(m_ParentAsWindow,
                                    GetID(),
                                    GetText(_T("label")),
                                    GetPosition(), GetSize(),
                                    GetStyle());
    button->SetName(GetName());
    if (GetBool(_T("default"), 0) == 1) button->SetDefault();
    SetupWindow(button);
    
    return button;
}



bool wxButtonXmlHandler::CanHandle(wxXmlNode *node)
{
    return node->GetName() == _T("button");
}


