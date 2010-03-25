// Copyright (c) 2005, Rodrigo Braz Monteiro
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//   * Redistributions of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//   * Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//   * Neither the name of the Aegisub Group nor the names of its contributors
//     may be used to endorse or promote products derived from this software
//     without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// Aegisub Project http://www.aegisub.org/
//
// $Id$

/// @file options.h
/// @see options.cpp
/// @ingroup main
///


#pragma once


///////////
// Headers
#ifndef AGI_PRE
#include <map>
#endif

#include "variable_data.h"

/// DOCME
enum ModType {

	/// DOCME
	MOD_OFF = -1,

	/// DOCME
	MOD_AUTOMATIC,

	/// DOCME
	MOD_RESTART,

	/// DOCME
	MOD_EDIT_BOX,

	/// DOCME
	MOD_GRID,

	/// DOCME
	MOD_VIDEO,

	/// DOCME
	MOD_VIDEO_RELOAD,

	/// DOCME
	MOD_AUDIO,

	/// DOCME
	MOD_AUDIO_RELOAD
};



/// DOCME
/// @class OptionsManager
/// @brief DOCME
///
/// DOCME
class OptionsManager {
private:

	/// DOCME
	ModType curModType;

	/// DOCME
	bool modified;

	/// DOCME
	bool overriding;

	/// DOCME
	wxString filename;

	/// DOCME
	std::map<wxString,VariableData> opt;

	/// DOCME
	std::map<wxString,ModType> optType;

	/// DOCME
	int lastVersion;

	void SetModificationType(ModType type);

public:
	OptionsManager();
	~OptionsManager();

	void Clear();
	void SetFile(wxString file);
	wxString GetFile() const;
	void Save();
	void Load();
	void LoadDefaults(bool onlyDefaults=false,bool versionOverride=false);

	wxArrayString GetRecentList (wxString list);

	void SetInt(wxString key,int param,int ifLastVersion=-1);
	void SetFloat(wxString key,double param,int ifLastVersion=-1);
	void SetBool(wxString key,bool param,int ifLastVersion=-1);
	void SetText(wxString key,wxString param,int ifLastVersion=-1);
	void SetColour(wxString key,wxColour param,int ifLastVersion=-1);
	void ResetWith(wxString key,wxString param);

	bool IsDefined(wxString key);
	double AsFloat(wxString key);
	wxString AsText(wxString key);
	ModType GetModType(wxString key);
};


///////////////////
// Global instance
extern OptionsManager Options;


