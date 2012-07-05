#pragma once

#include <atldlgs.h>
#include <atlddx.h>
//#include "ddxext.h"

class CPropPageAudio :
	public CPropertyPageImpl<CPropPageAudio>
	//,	public CWinDataExchangeEx<CPropPageAudio>
{
public:

	enum { IDD = IDD_TOOLS_OPTIONS_AUDIO };

	// Construction
	CPropPageAudio(void);

	BEGIN_MSG_MAP(CPropPageAudio)
        MESSAGE_HANDLER(WM_SHOWWINDOW, OnInitDialog)
		MESSAGE_HANDLER(WM_HSCROLL, OnTrackBar)
		COMMAND_HANDLER(IDDEFAULT, BN_CLICKED, OnDefaultClick)
        CHAIN_MSG_MAP(CPropertyPageImpl<CPropPageAudio>)
    END_MSG_MAP()

    BEGIN_DDX_MAP(CPropPageAudio)
		//DDX_COMBO_INDEX(IDC_CBO9, vAudioDriver)
	END_DDX_MAP()

    // Message handlers
	LRESULT OnTrackBar(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled);
	LRESULT OnSelComboAudQual(WORD wNotifyCode, WORD wID, HWND hwndCtl, BOOL& bHandled);
	LRESULT OnDefaultClick(WORD wNotifyCode, WORD wID, HWND hwndCtl, BOOL& bHandled);
	//OnKillActivate()?

    // Property page notification handlers
    int OnApply();
	//CComboBox cbAudioDriver;
	CUpDownCtrl sbLatency;
	CEdit ebLatency;
	CComboBox cbSamplingRate;
	//
	CButton btnDefault;

	// Override to get custom error handling
	//virtual void OnDataExchangeError(UINT nCtrlID, BOOL what) {};
    // DDX variables
	int vAudioDriver, vLatency, vSamplingRate, vFilterOrder;
};
